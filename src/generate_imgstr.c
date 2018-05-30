/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjauzion <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/26 16:19:02 by jjauzion          #+#    #+#             */
/*   Updated: 2018/05/30 12:28:15 by jjauzion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static t_buffer		*init_buffer(int nb, t_mlx *tmlx, t_fractal *fractal)
{
	t_buffer	*buff;
	int			buff_size;
	int			i;

	if (!(buff = (t_buffer*)malloc(sizeof(t_buffer) * nb)))
		return NULL;
	buff_size = tmlx->win_height * tmlx->win_width / nb;
	i = -1;
	while (++i < nb)
	{
		buff[i].buff_id = i;
		buff[i].buff = tmlx->str_image + i * buff_size * 4;
		if (i == nb - 1)
			buff_size = buff_size + (tmlx->win_height * tmlx->win_width) % NB_BUFF;
		buff[i].size = buff_size * 4;
		buff[i].win_width = tmlx->win_width;
		buff[i].win_height = tmlx->win_height;
		buff[i].start_pixel = i * buff_size;
		buff[i].fractal = fractal;
	}
	return (buff);
}

int					generate_imgstr(t_mlx *tmlx, t_fractal *fractal)
{
	int			i;
	t_buffer	*buffer;
/*	clock_t		begin;
	clock_t		end;
	double		duration;

	begin = clock();*/
	buffer = init_buffer(NB_BUFF, tmlx, fractal);
/*end = clock();
duration = (double)(end - begin) / CLOCKS_PER_SEC;
printf("duration init = %f\n", duration);*/
	if (NB_BUFF == 1)
	{
		mandelbrot((void*)buffer);
/*end = clock();
duration = (double)(end - begin) / CLOCKS_PER_SEC;
printf("duration fin = %f\n", duration);*/
		free(buffer);
		return (0);
		//return (mandelbrot((void*)buffer) == NULL);
	}
	i = -1;
	while (++i < NB_BUFF)
	{
		if (pthread_create(&buffer[i].thread, NULL, mandelbrot, (void*)&buffer[i]))
		{
			perror("pthread_create");
			return (EXIT_FAILURE);
		}
	}
	i = -1;
	while (++i < NB_BUFF)
	{
		if (pthread_join(buffer[i].thread, NULL))
		{
			perror("pthread_join");
			return (EXIT_FAILURE);
		}
		if (i == 0)
			fractal->min_iter = buffer[i].min_iter;
		else if (buffer[i].min_iter < fractal->min_iter)
			fractal->min_iter = buffer[i].min_iter;
	}
ft_printf("iter min = %d\n", fractal->min_iter);
/*end = clock();
duration = (double)(end - begin) / CLOCKS_PER_SEC;
printf("duration fin = %f\n", duration);*/
	free(buffer);
	return (EXIT_SUCCESS);
}

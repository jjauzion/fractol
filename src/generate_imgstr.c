/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjauzion <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/26 16:19:02 by jjauzion          #+#    #+#             */
/*   Updated: 2018/05/27 18:29:33 by jjauzion         ###   ########.fr       */
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
		if (i == nb - 1)
			buff_size = buff_size + (tmlx->win_height * tmlx->win_width) % NB_BUFF;
		if (!(buff[i].buff = (char*)malloc(sizeof(char) * buff_size)))
			return NULL;
		buff[i].size = buff_size;
		buff[i].win_width = tmlx->win_width;
		buff[i].win_height = tmlx->win_height;
		buff[i].start_index = i * buff_size;
		buff[i].fractal = fractal;
	}
	return (buff);
}

static void			join_buffer(char *dest, t_buffer *buffer)
{
	int			i;
	void		*ptr;

	ptr = (void*)dest;
	i = -1;
	while (++i < NB_BUFF)
	{
		ft_memcpy(ptr, (const void*)buffer[i].buff, (size_t)buffer[i].size);
		if (i != NB_BUFF - 1)
			ptr = ptr + buffer[i].size;
	}
}

int					generate_imgstr(t_mlx *tmlx, t_fractal *fractal)
{
	int			i;
	t_buffer	*buffer;

	buffer = init_buffer(NB_BUFF, tmlx, fractal);
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
	}
	join_buffer(tmlx->str_image, buffer);
//	(void)join_buffer;
//	tmlx->str_image = buffer->buff;
	return (EXIT_SUCCESS);
}

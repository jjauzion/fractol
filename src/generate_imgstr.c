/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjauzion <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/26 16:19:02 by jjauzion          #+#    #+#             */
/*   Updated: 2018/05/26 20:00:05 by jjauzion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static *t_buffer	alloc_buffer(int nb, int total_size)
{
	t_buffer	*buff;
	int			buff_size;
	int			i;

	if (!(buff = (t_buffer*)malloc(sizeof(t_buffer) * nb)))
		return NULL;
	buff_size = total_size / nb;
	i = -1;
	while (++i < nb)
	{
		if (i == nb - 1)
			buff_size = buff_size + total_size % NB_BUFF;
		if (!(buff[i]->str = (char*)malloc(sizeof(char) * buff_size)))
			return NULL;
		buff[i]->size = buff_size;
		buff[i]->start = i * buff_size;
	}
	return (buff);
}

char				*generate_imgstr(t_mlx *tmlx, t_ipoint start, int zoom)
{
	int		i;


	tmlx->buff = alloc_buffer(NB_BUFF, tmlx->height * tmlx->width);
	tmlx->buff_id = -1;
	i = -1;
	while (++i < NB_BUFF)
	{
		if (pthread_create(tmlx->buff[i].thread, NULL, mandelbrot, (void*)tmlx))
		{
			perror("pthread_create");
			return (EXIT_FAILURE);
		}
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjauzion <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/20 17:21:49 by jjauzion          #+#    #+#             */
/*   Updated: 2018/05/30 12:36:25 by jjauzion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdlib.h>


void	*mandelbrot(void *buffer)
{
	t_ipoint	z;
	t_ipoint	c;
	t_point2d	p;
	int			j;
	int			max_iter;
	double		tmp;
	int			color;
	int			index;
	t_buffer	*buff;
	int			min_iter;

	buff = (t_buffer*)buffer;
	max_iter = buff->fractal->max_iter;
//	buff->fractal->color_scale = scale(0x2567A8, max_iter);
	index = buff->start_pixel - 1;
	while (++index < buff->start_pixel + (buff->size / 4))
	{
		p.x = index % buff->win_width;
		p.y = index / buff->win_width;
		z.real = 0;
		z.imag = 0;
		c.real = (double)p.x / buff->fractal->zoom + buff->fractal->start.real;
		c.imag = (double)p.y / buff->fractal->zoom + buff->fractal->start.imag;
		j = -1;
		while ((++j < max_iter) && (z.real * z.real + z.imag * z.imag < 4.0))
		{
			tmp = z.real * z.real - z.imag * z.imag + c.real;
			z.imag = 2. * z.real * z.imag + c.imag;
			z.real = tmp;
		}
		if (index == buff->start_pixel)
			min_iter = j;
		else if (j < min_iter)
			min_iter = j;
		color = get_color(j, buff->fractal->color_scale);
		fill_string(buff, &p, color);
	}
	buff->min_iter = min_iter;
	if (NB_BUFF != 1)
		pthread_exit(NULL);
	else
		return (NULL);
}

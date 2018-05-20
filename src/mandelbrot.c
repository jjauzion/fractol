/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjauzion <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/20 17:21:49 by jjauzion          #+#    #+#             */
/*   Updated: 2018/05/20 19:24:19 by jjauzion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdlib.h>

void	mandelbrot(t_mlx *tmlx, t_ipoint start, t_ipoint end, int zoom)
{
	t_ipoint	z;
	t_ipoint	c;
	t_point2d	p;
	int			j;
	int			max_iter;
	double		tmp;
	(void) end;

	max_iter = 50;
	p.x = -1;
	while (++p.x < tmlx->win_width)
	{
		p.y = -1;
		while (++p.y < tmlx->win_height)
		{
			z.real = 0;
			z.imag = 0;
			c.real = (double)p.x / (double)zoom + start.real;
			c.imag = (double)p.y / (double)zoom + start.imag;
			j = -1;
			while ((++j < max_iter) && (z.real * z.real + z.imag * z.imag < 4.0))
			{
				tmp = z.real * z.real - z.imag * z.imag + c.real;
				z.imag = 2. * z.real * z.imag + c.imag;
				z.real = tmp;
			}
			if (j >= max_iter)
				pixel_put(tmlx, &p, 0, 0);
		}
	}
}

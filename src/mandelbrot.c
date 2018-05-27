/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjauzion <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/20 17:21:49 by jjauzion          #+#    #+#             */
/*   Updated: 2018/05/27 18:17:06 by jjauzion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdlib.h>

void	mandelbrot(t_mlx *tmlx, t_ipoint start, int zoom)
{
	t_ipoint	z;
	t_ipoint	c;
	t_point2d	p;
	int			j;
	int			max_iter;
	double		tmp;
	int			color;

	max_iter = 50;
	tmlx->color_scale = scale(0x2567A8, max_iter);
	p.y = -1;
	while (++p.y < tmlx->win_height)
	{
		p.x = -1;
		while (++p.x < tmlx->win_width)
		{
			z.real = 0;
			z.imag = 0;
			c.real = (double)p.x / (double)zoom + start.real;
			c.imag = (double)p.y / (double)zoom + start.imag;
//printf("px = %d ; py = %d\n", p.x, p.y);
//printf("c.real = %f ; c.imag = %f\n", c.real, c.imag);
			j = -1;
			while ((++j < max_iter) && (z.real * z.real + z.imag * z.imag < 4.0))
			{
				tmp = z.real * z.real - z.imag * z.imag + c.real;
				z.imag = 2. * z.real * z.imag + c.imag;
				z.real = tmp;
			}
			if (j >= max_iter)
				fill_image(tmlx, &p, 0);
			else if (j >= 5)
			{
//printf("FRACTAL\n");
				color = get_color(j, tmlx->color_scale);
				fill_image(tmlx, &p, color);
			}
		}
	}
}

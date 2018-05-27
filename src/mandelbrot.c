/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjauzion <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/20 17:21:49 by jjauzion          #+#    #+#             */
/*   Updated: 2018/05/27 18:07:09 by jjauzion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdlib.h>

pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;

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

	buff = (t_buffer*)buffer;
/*pthread_mutex_lock(&lock);
ft_printf("in thread %d\n", buff->buff_id);
fflush(stdout);
pthread_mutex_unlock(&lock);*/
	max_iter = 50;
	buff->fractal->color_scale = scale(0x2567A8, max_iter);
	index = buff->start_index - 1;
	while (++index < buff->win_width * buff->win_height)
	{
		p.x = index % buff->win_width;
		p.y = index / buff->win_width;
pthread_mutex_lock(&lock);
ft_printf("px = %d ; py = %d\n", p.x, p.y);
fflush(stdout);
pthread_mutex_unlock(&lock);
		z.real = 0;
		z.imag = 0;
		c.real = (double)p.x / (double)buff->fractal->zoom + buff->fractal->start.real;
		c.imag = (double)p.y / (double)buff->fractal->zoom + buff->fractal->start.imag;
pthread_mutex_lock(&lock);
printf("c.real = %f ; c.imag = %f\n", c.real, c.imag);
fflush(stdout);
pthread_mutex_unlock(&lock);
		j = -1;
		while ((++j < max_iter) && (z.real * z.real + z.imag * z.imag < 4.0))
		{
			tmp = z.real * z.real - z.imag * z.imag + c.real;
			z.imag = 2. * z.real * z.imag + c.imag;
			z.real = tmp;
		}
		if (j >= max_iter)
			fill_string(buff, index - buff->start_index, 0);
		else if (j >= 5)
		{
pthread_mutex_lock(&lock);
printf("FRACTAL\n");
fflush(stdout);
pthread_mutex_unlock(&lock);
			color = get_color(j, buff->fractal->color_scale);
			fill_string(buff, index - buff->start_index, color);
		}
	}
	pthread_exit(NULL);
}

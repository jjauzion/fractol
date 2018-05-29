/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjauzion <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/20 17:21:49 by jjauzion          #+#    #+#             */
/*   Updated: 2018/05/29 11:04:52 by jjauzion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdlib.h>

//pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;

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
/*	clock_t		begin;
	clock_t		end;
	double		duration;
	int			cpt = 0;

	begin = clock();
*/	buff = (t_buffer*)buffer;
	max_iter = buff->fractal->max_iter;
	buff->fractal->color_scale = scale(0x2567A8, max_iter);
	index = buff->start_pixel - 1;
	while (++index < buff->start_pixel + (buff->size / 4))
	{
		p.x = index % buff->win_width;
		p.y = index / buff->win_width;
		z.real = 0;
		z.imag = 0;
		c.real = (double)p.x / (double)buff->fractal->zoom + buff->fractal->start.real;
		c.imag = (double)p.y / (double)buff->fractal->zoom + buff->fractal->start.imag;
		j = -1;
		while ((++j < max_iter) && (z.real * z.real + z.imag * z.imag < 4.0))
		{
			tmp = z.real * z.real - z.imag * z.imag + c.real;
			z.imag = 2. * z.real * z.imag + c.imag;
			z.real = tmp;
//			cpt++;
		}
		color = get_color(j, buff->fractal->color_scale);
		fill_string(buff, &p, color);
	}
/*end = clock();
duration = (double)(end - begin) / CLOCKS_PER_SEC;
if (NB_BUFF != 1)
	pthread_mutex_lock(&lock);
printf("thread %d duration : %f | ", buff->buff_id, duration);
printf("nb iter : %d | nb of pixel computed : %d\n", index + cpt, buff->size);
if (NB_BUFF != 1) {
fflush(stdout);
pthread_mutex_unlock(&lock);}*/
	if (NB_BUFF != 1)
		pthread_exit(NULL);
	else
		return (NULL);
}

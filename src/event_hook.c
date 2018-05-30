/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_hook.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjauzion <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/21 18:57:04 by jjauzion          #+#    #+#             */
/*   Updated: 2018/05/30 13:13:27 by jjauzion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		key_hook(int keycode, void *param)
{
	t_mlx		*tmlx;
	t_fractal	*fract;

	tmlx = (t_mlx*)param;
	fract = (t_fractal*)tmlx->fractal;
	if (keycode == 53)
		exit(EXIT_SUCCESS);
	else if (keycode == 49)
	{
		fract->zoom = 500;
		fract->max_iter = 50;
		fract->start.real = -2.1;
		fract->start.imag = -1.2;
	}
	else if (keycode == 69)
		fract->max_iter += 1;
	else if (keycode == 78)
		fract->max_iter -= 1;
	else if (keycode == 126)
		fract->start.imag -= 10 / fract->zoom; 
	else if (keycode == 125)
		fract->start.imag += 10 / fract->zoom; 
	else if (keycode == 124)
		fract->start.real += 10 / fract->zoom; 
	else if (keycode == 123)
		fract->start.real -= 10 / fract->zoom; 
	printf("max_iter = %d\n", fract->max_iter);
	display(tmlx, fract);
	return (0);
}

int		mouse_hook(int button, int x, int y, void *param)
{
	t_mlx		*tmlx;
	t_fractal	*fract;
	t_ipoint	mouse;

	if (button != 1 || x < 0 || y < 0)
		return (0);
	tmlx = (t_mlx*)param;
	fract = (t_fractal*)tmlx->fractal;
	mouse.real = (double)x / (double)fract->zoom + fract->start.real;
	mouse.imag = (double)y / (double)fract->zoom + fract->start.imag;
	fract->zoom = fract->zoom * ZOOM_FACTOR;
	fract->start.real = mouse.real - (double)x / (double)fract->zoom;
	fract->start.imag = mouse.imag - (double)y / (double)fract->zoom;
	fract->max_iter = fract->min_iter + 50;
	printf("zoom = %f ; max_iter = %d\n", fract->zoom, fract->max_iter);
	display(tmlx, fract);
	return (0);
}

int		loop_hook(void *param)
{
	t_mlx	*tmlx;

	tmlx = (t_mlx*)param;
	if (tmlx->zoomin == 1)
	{
			
	}
	return (0);
}

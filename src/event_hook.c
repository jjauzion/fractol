/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_hook.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjauzion <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/21 18:57:04 by jjauzion          #+#    #+#             */
/*   Updated: 2018/05/29 12:31:32 by jjauzion         ###   ########.fr       */
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
		fract->start.real = -2.1;
		fract->start.imag = -1.2;
		display(tmlx, fract);
	}
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
	fract->zoom = (int)((double)fract->zoom * ZOOM_FACTOR);
	fract->start.real = mouse.real - (double)x / (double)fract->zoom;
	fract->start.imag = mouse.imag - (double)y / (double)fract->zoom;
	fract->max_iter += 1;
	printf("zoom = %ju ; start.real = %f ; start.imag = %f\n", fract->zoom, fract->start.real, fract->start.imag);
	display(tmlx, fract);
	return (0);
}

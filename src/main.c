/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjauzion <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/20 15:15:57 by jjauzion          #+#    #+#             */
/*   Updated: 2018/05/20 19:24:24 by jjauzion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		main(int argc, char **argv)
{
	t_mlx		tmlx;
	t_ipoint	start;
	t_ipoint	end;
	int			zoom;
	(void)**argv;

	if (argc <= 1)
	{
		ft_putstr("Usage :\n");
		return (1);
	}
	start.real = -2.1;
	start.imag = -1.2;
	end.real = 0.6;
	end.imag = 1.2;
	zoom = 500;
	tmlx.win_height = ABS((int)(end.imag * (double)zoom) - (int)(start.imag * (double)zoom));
	tmlx.win_width = ABS((int)(end.real * (double)zoom) - (int)(start.real * (double)zoom));
	tmlx.mlx = mlx_init();
	tmlx.win = mlx_new_window(tmlx.mlx, tmlx.win_width, tmlx.win_height, "fractol");
	mandelbrot(&tmlx, start, end, zoom);
	mlx_loop(tmlx.mlx);
}

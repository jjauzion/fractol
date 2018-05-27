/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjauzion <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/20 15:15:57 by jjauzion          #+#    #+#             */
/*   Updated: 2018/05/27 17:40:39 by jjauzion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		main(int argc, char **argv)
{
	t_mlx		tmlx;
	t_fractal	fractal;
	t_ipoint	start;
	t_ipoint	end;
	int			bpp;
	int			s_l;
	int			endian;

	(void) **argv;
	if (argc <= 1)
	{
		ft_putstr("Usage :\n");
		return (1);
	}
	start.real = -2.1;
	start.imag = -1.2;
	end.real = 0.6;
	end.imag = 1.2;
	fractal.zoom = 50;
	tmlx.win_height = ABS((int)(end.imag * (double)fractal.zoom)
			- (int)(start.imag * (double)fractal.zoom));
	tmlx.win_width = ABS((int)(end.real * (double)fractal.zoom)
			- (int)(start.real * (double)fractal.zoom));
	ft_printf("h = %d ; w = %d\n", tmlx.win_height, tmlx.win_width);
	getchar();
	tmlx.mlx = mlx_init();
	tmlx.win = mlx_new_window(tmlx.mlx, tmlx.win_width, tmlx.win_height, "fractol");
	tmlx.ptr_image = mlx_new_image(tmlx.mlx, tmlx.win_width, tmlx.win_height);
	tmlx.str_image = mlx_get_data_addr(tmlx.ptr_image, &(bpp), &(s_l), &(endian));
	fractal.start = start;
	generate_imgstr(&tmlx, &fractal);
	mlx_put_image_to_window(tmlx.mlx, tmlx.win, tmlx.ptr_image, 0, 0);
	mlx_key_hook(tmlx.win, key_hook, (void*)&tmlx);
	mlx_loop(tmlx.mlx);
	free(fractal.color_scale);
}

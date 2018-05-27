/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel_put.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjauzion <jjauzion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/22 11:51:33 by jjauzion          #+#    #+#             */
/*   Updated: 2018/05/27 15:14:27 by jjauzion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		pixel_put(t_mlx *tmlx, t_point2d *p, int height, char option)
{
	int	color;

	color = (option == 'c') ? get_color(height, tmlx->fractal->color_scale) : 0xFFFFFF;
	mlx_pixel_put(tmlx->mlx, tmlx->win, p->x, p->y, color);
}

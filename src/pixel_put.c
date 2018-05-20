/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel_put.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjauzion <jjauzion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/22 11:51:33 by jjauzion          #+#    #+#             */
/*   Updated: 2018/05/20 17:13:49 by jjauzion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		pixel_put(t_mlx *tmlx, t_point2d *p, int height, char option)
{
	int	color;
	(void) height;
	(void) option;

	color = 0xFFFFFF;
	mlx_pixel_put(tmlx->mlx, tmlx->win, p->x, p->y, color);
}

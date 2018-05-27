/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_image.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjauzion <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/21 14:28:37 by jjauzion          #+#    #+#             */
/*   Updated: 2018/05/27 18:34:35 by jjauzion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		fill_image(t_mlx *tmlx, t_point2d *p, int color)
{
	int		index;
	int		tmp;

	index = p->y * tmlx->win_width * 4 + p->x * 4;
	tmp = (color & 0xFF);	
	tmlx->str_image[index] = (char)tmp;
	tmp = (color & 0xFF00) >> 8;	
	tmlx->str_image[index + 1] = (char)tmp;
	tmp = (color & 0xFF0000) >> 16;	
	tmlx->str_image[index + 2] = (char)tmp;
	tmlx->str_image[index + 3] = 0;
}

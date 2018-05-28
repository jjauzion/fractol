/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_image.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjauzion <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/21 14:28:37 by jjauzion          #+#    #+#             */
/*   Updated: 2018/05/28 11:00:03 by jjauzion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		fill_string(t_buffer *buff, t_point2d *p, int color)
{
	int		tmp;
	int		index;

	index = p->y * buff->win_width * 4 + p->x * 4 - buff->start_pixel * 4;
	tmp = (color & 0xFF);	
	buff->buff[index] = (char)tmp;
	tmp = (color & 0xFF00) >> 8;	
	buff->buff[index + 1] = (char)tmp;
	tmp = (color & 0xFF0000) >> 16;	
	buff->buff[index + 2] = (char)tmp;
	buff->buff[index + 3] = 0;
}

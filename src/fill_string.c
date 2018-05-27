/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_image.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjauzion <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/21 14:28:37 by jjauzion          #+#    #+#             */
/*   Updated: 2018/05/27 19:56:49 by jjauzion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		fill_string(t_buffer *buff, t_point2d *p, int color)
{
	int		tmp;
	int		index;

	index = p->y * buff->win_width * 4 + p->x * 4 - buff->start_pixel * 4;
/*ft_printf("w = %d ; h = %d\n", buff->win_width, buff->win_height);
ft_printf("px = %d ; py = %d\n", p->x, p->y);
ft_printf("index = %d\n", index);
ft_printf("buff start = %d ; size = %d\n", buff->start_pixel, buff->size);*/
	tmp = (color & 0xFF);	
	buff->buff[index] = (char)tmp;
	tmp = (color & 0xFF00) >> 8;	
	buff->buff[index + 1] = (char)tmp;
	tmp = (color & 0xFF0000) >> 16;	
	buff->buff[index + 2] = (char)tmp;
	buff->buff[index + 3] = 0;
}

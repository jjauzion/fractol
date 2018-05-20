/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   twd_left_lines.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjauzion <jjauzion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/18 20:35:44 by jjauzion          #+#    #+#             */
/*   Updated: 2018/05/20 17:12:25 by jjauzion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	octant_4(t_mlx *tmlx, t_line line, char option)
{
	int	err;

	(void)option;
	err = line.dx;
	line.dx = line.dx * 2;
	line.dy = line.dy * 2;
	while (line.p1->x > line.p2->x)
	{
		pixel_put(tmlx, line.p1, ft_max(line.p1->height, line.p2->height),
				option);
		line.p1->x -= 1;
		if ((err = err + line.dy) >= 0)
		{
			line.p1->y += 1;
			err = err + line.dx;
		}
	}
}

void	octant_3(t_mlx *tmlx, t_line line, char option)
{
	int	err;

	(void)option;
	err = line.dy;
	line.dx = line.dx * 2;
	line.dy = line.dy * 2;
	while (line.p1->y < line.p2->y)
	{
		pixel_put(tmlx, line.p1, ft_max(line.p1->height, line.p2->height),
				option);
		line.p1->y += 1;
		if ((err = err + line.dx) <= 0)
		{
			line.p1->x -= 1;
			err = err + line.dy;
		}
	}
}

void	octant_5(t_mlx *tmlx, t_line line, char option)
{
	int	err;

	(void)option;
	err = line.dx;
	line.dx = line.dx * 2;
	line.dy = line.dy * 2;
	while (line.p1->x > line.p2->x)
	{
		pixel_put(tmlx, line.p1, ft_max(line.p1->height, line.p2->height),
				option);
		line.p1->x -= 1;
		if ((err = err - line.dy) >= 0)
		{
			line.p1->y -= 1;
			err = err + line.dx;
		}
	}
}

void	octant_6(t_mlx *tmlx, t_line line, char option)
{
	int	err;

	(void)option;
	err = line.dy;
	line.dx = line.dx * 2;
	line.dy = line.dy * 2;
	while (line.p1->y > line.p2->y)
	{
		pixel_put(tmlx, line.p1, ft_max(line.p1->height, line.p2->height),
				option);
		line.p1->y -= 1;
		if ((err = err - line.dx) >= 0)
		{
			line.p1->x -= 1;
			err = err + line.dy;
		}
	}
}

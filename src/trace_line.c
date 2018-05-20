/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trace_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjauzion <jjauzion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/18 17:41:20 by jjauzion          #+#    #+#             */
/*   Updated: 2018/05/20 17:10:19 by jjauzion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	twd_right_line(t_mlx *tmlx, t_line line, char option)
{
	if (line.dy > 0)
	{
		if (line.dx >= line.dy)
			octant_1(tmlx, line, option);
		else
			octant_2(tmlx, line, option);
	}
	else if (line.dy < 0)
	{
		if (line.dx >= -line.dy)
			octant_8(tmlx, line, option);
		else
			octant_7(tmlx, line, option);
	}
	else
		horizontal_rh_line(tmlx, line, option);
}

void	twd_left_line(t_mlx *tmlx, t_line line, char option)
{
	if (line.dy > 0)
	{
		if (-line.dx >= line.dy)
			octant_4(tmlx, line, option);
		else
			octant_3(tmlx, line, option);
	}
	else if (line.dy < 0)
	{
		if (line.dx <= line.dy)
			octant_5(tmlx, line, option);
		else
			octant_6(tmlx, line, option);
	}
	else
		horizontal_lh_line(tmlx, line, option);
}

void	trace_line(t_mlx *tmlx, t_point2d p1, t_point2d p2, char option)
{
	t_line	line;

	(void)option;
	line.dx = p2.x - p1.x;
	line.dy = p2.y - p1.y;
	line.p1 = &p1;
	line.p2 = &p2;
	if (line.dx > 0)
		twd_right_line(tmlx, line, option);
	else if (line.dx < 0)
		twd_left_line(tmlx, line, option);
	else if (line.dy > 0)
		vertical_up_line(tmlx, line, option);
	else if (line.dy < 0)
		vertical_dw_line(tmlx, line, option);
}

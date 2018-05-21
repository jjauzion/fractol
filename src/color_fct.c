/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_fct.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjauzion <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/20 15:45:33 by jjauzion          #+#    #+#             */
/*   Updated: 2018/05/21 15:26:10 by jjauzion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	interpolate(int **color_scale, int value)
{
	int		tsv[2][3];
	int		i;
	int		j;
	double	a;
	int		b;

	i = 1;
	while (++i < color_scale[0][0] && value > color_scale[0][i])
	{
	}
	ft_rgb2tsv(color_scale[1][i - 1], &tsv[0][0], &tsv[0][1], &tsv[0][2]);
	ft_rgb2tsv(color_scale[1][i], &tsv[1][0], &tsv[1][1], &tsv[1][2]);
	j = -1;
	while (++j < 3)
	{
		if (color_scale[0][i - 1] != color_scale[0][i])
			a = (double)(tsv[0][j] - tsv[1][j]) /
				(double)(color_scale[0][i - 1] - color_scale[0][i]);
		else
			a = 0;
		b = tsv[0][j] - (int)(a * (double)color_scale[0][i - 1]);
		tsv[0][j] = (int)((double)value * a) + b;
	}
	return (ft_tsv2rgb(tsv[0][0], tsv[0][1], tsv[0][2]));
}

/*
**	Color scale format:
**	scale[0][0] : contains number of threshold in the scale
**	scale[0][i] : contains the value of the threshold i
**	scale[1][i] : contains the color of the threshold i (e.g. 0xFFFFFF)
*/

int	get_color(int value, int **color_scale)
{
	if (color_scale[0][0] < 1)
		return (0xFFFFFF);
	if (value < color_scale[0][1])
		return (color_scale[1][1]);
	else if (value >= color_scale[0][color_scale[0][0]])
		return (color_scale[1][color_scale[0][0]]);
	else
		return (interpolate(color_scale, value));
}

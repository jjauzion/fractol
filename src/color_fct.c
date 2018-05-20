/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_fct.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjauzion <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/20 15:45:33 by jjauzion          #+#    #+#             */
/*   Updated: 2018/05/20 15:45:41 by jjauzion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	interpolate(t_mlx *tmlx, int height)
{
	int		tsv[2][3];
	int		i;
	int		j;
	double	a;
	int		b;

	i = 1;
	while (++i < tmlx->color[0][0] && height > tmlx->color[0][i])
	{
	}
	ft_rgb2tsv(tmlx->color[1][i - 1], &tsv[0][0], &tsv[0][1], &tsv[0][2]);
	ft_rgb2tsv(tmlx->color[1][i], &tsv[1][0], &tsv[1][1], &tsv[1][2]);
	j = -1;
	while (++j < 3)
	{
		if (tmlx->color[0][i - 1] != tmlx->color[0][i])
			a = (double)(tsv[0][j] - tsv[1][j]) /
				(double)(tmlx->color[0][i - 1] - tmlx->color[0][i]);
		else
			a = 0;
		b = tsv[0][j] - (int)(a * (double)tmlx->color[0][i - 1]);
		tsv[0][j] = (int)((double)height * a) + b;
	}
	return (ft_tsv2rgb(tsv[0][0], tsv[0][1], tsv[0][2]));
}

static int	get_color(t_mlx *tmlx, int height)
{
	if (tmlx->color[0][0] < 1)
		return (0xFFFFFF);
	if (height < tmlx->color[0][1])
		return (tmlx->color[1][1]);
	else if (height >= tmlx->color[0][tmlx->color[0][0]])
		return (tmlx->color[1][tmlx->color[0][0]]);
	else
		return (interpolate(tmlx, height));
}

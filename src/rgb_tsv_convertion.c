/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rgb_tsv_convertion.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjauzion <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/21 12:49:06 by jjauzion          #+#    #+#             */
/*   Updated: 2018/05/21 13:06:31 by jjauzion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	rgb_mask(double r, double g, double b, double m)
{
	int	rgb;
	int	ri;
	int	gi;
	int	bi;

	ri = (int)((r + m) * 255.);
	gi = (int)((g + m) * 255.);
	bi = (int)((b + m) * 255.);
	rgb = 0;
	rgb = (ri << 16);
	rgb = (gi << 8) | rgb;
	rgb = bi | rgb;
	return (rgb);
}

static int	check_tsv(int t, int s, int v)
{
	t = t % 360;
	if (s < 0 || s > 100)
		return (-1);
	if (v < 0 || v > 100)
		return (-1);
	return (t);
}

int			ft_tsv2rgb(int t, int s, int v)
{
	int		rgb;
	double	c;
	double	x;
	double	m;

	if ((t = check_tsv(t, s, v)) < 0)
		return (-1);
	c = (double)v / 100. * (double)s / 100.;
	x = c * (1 - fabs(fmod((double)t / 60., 2.) - 1));
	m = (double)v / 100. - c;
	rgb = -1;
	if (t < 60)
		rgb = rgb_mask(c, x, 0, m);
	else if (t < 120)
		rgb = rgb_mask(x, c, 0, m);
	else if (t < 180)
		rgb = rgb_mask(0, c, x, m);
	else if (t < 240)
		rgb = rgb_mask(0, x, c, m);
	else if (t < 300)
		rgb = rgb_mask(x, 0, c, m);
	else if (t < 360)
		rgb = rgb_mask(c, 0, x, m);
	return (rgb);
}

static int	check_rgb(int rgb, int *t, int *s, int *v)
{
	if (!t || !s || !v)
		return (1);
	if (rgb < 0 || rgb > 0xFFFFFF)
		return (1);
	return (0);
}

int			ft_rgb2tsv(int rgb, int *t, int *s, int *v)
{
	int	*color;
	int	min;
	int	max;

	if (check_rgb(rgb, t, s, v))
		return (1);
	if (!(color = (int *)malloc(sizeof(int) * 3)))
		return (1);
	color[0] = (rgb & 0xFF0000) >> 16;
	color[1] = (rgb & 0xFF00) >> 8;
	color[2] = rgb & 0xFF;
	max = ft_tab_max(color, 3);
	min = ft_tab_min(color, 3);
	if (max == min)
		*t = 0;
	else if (max == color[0])
		*t = (60 * (color[1] - color[2]) / (max - min) + 360) % 360;
	else if (max == color[1])
		*t = 60 * (color[2] - color[0]) / (max - min) + 120;
	else
		*t = 60 * (color[0] - color[1]) / (max - min) + 240;
	*s = (max == 0) ? 0 : 100 - (int)(100. * (double)min / (double)max);
	*v = (int)(100. * ((double)max / 255.));
	free(color);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjauzion <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 10:04:39 by jjauzion          #+#    #+#             */
/*   Updated: 2018/05/29 10:32:00 by jjauzion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		display(t_mlx *tmlx, t_fractal *fractal)
{
	generate_imgstr(tmlx, fractal);
	mlx_clear_window(tmlx->mlx, tmlx->win);
	mlx_put_image_to_window(tmlx->mlx, tmlx->win, tmlx->ptr_image, 0, 0);
}

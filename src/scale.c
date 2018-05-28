/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scale.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjauzion <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/21 12:24:24 by jjauzion          #+#    #+#             */
/*   Updated: 2018/05/28 15:07:59 by jjauzion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		**scale(int color, int val)
{
	int	**scale;

	if (!(scale = (int**)malloc((sizeof(int*) * 2))))
		return (NULL);
	if (!(scale[0] = (int*)malloc((sizeof(int) * 3))))
		return (NULL);
	if (!(scale[1] = (int*)malloc((sizeof(int) * 3))))
		return (NULL);
	scale[0][0] = 3;
	scale[0][1] = 12;
	scale[1][1] = 0xFFFFFF;
	scale[0][2] = val - 1;
	scale[1][2] = color;
	scale[0][3] = val;
	scale[1][3] = 0xFFFFFF;
	return (scale);
}

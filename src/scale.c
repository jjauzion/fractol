/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scale.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjauzion <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/21 12:24:24 by jjauzion          #+#    #+#             */
/*   Updated: 2018/05/21 15:22:55 by jjauzion         ###   ########.fr       */
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
	scale[0][0] = 2;
	scale[0][1] = 5;
	scale[1][1] = 0x0;
	scale[0][2] = val;
	scale[1][2] = color;
	return (scale);
}

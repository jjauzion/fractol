/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scale.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjauzion <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/21 12:24:24 by jjauzion          #+#    #+#             */
/*   Updated: 2018/05/31 11:08:11 by jjauzion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		**scale1(void)
{
	int	**scale;

	if (!(scale = (int**)malloc((sizeof(int*) * 2))))
		return (NULL);
	if (!(scale[0] = (int*)malloc((sizeof(int) * 6))))
		return (NULL);
	if (!(scale[1] = (int*)malloc((sizeof(int) * 6))))
		return (NULL);
	scale[0][0] = 5;
	scale[0][1] = 10;
	scale[1][1] = 0;
	scale[0][2] = 25;
	scale[1][2] = 0x0094B9;
	scale[0][3] = 50;
	scale[1][3] = 0xCCCC00;
	scale[0][4] = 75;
	scale[1][4] = 0xCC6600;
	scale[0][5] = 100;
	scale[1][5] = 0;
	return (scale);
}

int		**scale2(void)
{
	int	**scale;

	if (!(scale = (int**)malloc((sizeof(int*) * 2))))
		return (NULL);
	if (!(scale[0] = (int*)malloc((sizeof(int) * 6))))
		return (NULL);
	if (!(scale[1] = (int*)malloc((sizeof(int) * 6))))
		return (NULL);
	scale[0][0] = 5;
	scale[0][1] = 10;
	scale[1][1] = 0;
	scale[0][2] = 25;
	scale[1][2] = 0x4DFF4D;
	scale[0][3] = 50;
	scale[1][3] = 0x330066;
	scale[0][4] = 75;
	scale[1][4] = 0xFFFFFF;
	scale[0][5] = 100;
	scale[1][5] = 0x004C99;
	return (scale);
}

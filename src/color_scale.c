/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_scale.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjauzion <jjauzion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/23 16:26:11 by jjauzion          #+#    #+#             */
/*   Updated: 2018/05/21 11:42:11 by jjauzion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

/*
** Color scale[0][0] contains the number of threshold
*/

static void	mountains(int **scale)
{
	scale[0][0] = 5;
	scale[0][1] = 0;
	scale[1][1] = 0x1962E1;
	scale[0][2] = 0;
	scale[1][2] = 0x009A00;
	scale[0][3] = 20;
	scale[1][3] = 0x9A5700;
	scale[0][4] = 80;
	scale[1][4] = 0x402400;
	scale[0][5] = 80;
	scale[1][5] = 0xFFFFFF;
}

static void	desert(int **scale)
{
	scale[0][0] = 3;
	scale[0][1] = 0;
	scale[1][1] = 0xFFB266;
	scale[0][2] = 0;
	scale[1][2] = 0xC16100;
	scale[0][3] = 8;
	scale[1][3] = 0x693502;
}

static void	ocean(int **scale)
{
	scale[0][0] = 2;
	scale[0][1] = -5;
	scale[1][1] = 0x003366;
	scale[0][2] = 5;
	scale[1][2] = 0x99CCFF;
}

int			**color_scale(void)
{
	int			**scale;
	int			i;
	static int	index = 0;

	if (!(scale = (int**)malloc(sizeof(int*) * 2)))
		return (NULL);
	i = -1;
	while (++i < 2)
		if (!(scale[i] = (int*)malloc(sizeof(int) * 6)))
			return (NULL);
	if (index == 0)
		mountains(scale);
	else if (index == 1)
		desert(scale);
	else if (index == 2)
		ocean(scale);
	else
		scale[0][0] = 0;
	index = (index >= 2) ? 0 : index + 1;
	return (scale);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkwall.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhadari <yhadari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 19:34:41 by yhadari           #+#    #+#             */
/*   Updated: 2020/11/25 20:05:07 by yhadari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	ft_checkwall2(int *i, int *j, int n)
{
	float ang;

	ang = 90;
	if (g_player.walkder == 1 && n == 0)
	{
		*i = (g_player.x + g_player.mx * g_player.movespeed) / g_tile;
		*j = (g_player.y + g_player.my * g_player.movespeed) / g_tile;
	}
	if (g_player.walkder == -1 && n == 0)
	{
		*i = (g_player.x - g_player.mx * g_player.movespeed) / g_tile;
		*j = (g_player.y - g_player.my * g_player.movespeed) / g_tile;
	}
	if (g_player.horizder != 0 && n == 0)
	{
		g_p.index1 = 0;
		if (g_player.horizder == -1)
			ang *= -1;
		*i = g_player.x + g_tile * cos((g_p.angle + ang) * RADIAN);
		*j = g_player.y + g_tile * sin((g_p.angle + ang) * RADIAN);
		ft_dda(g_player.x, g_player.y, *i, *j);
		*i = (g_player.x + g_player.mx * g_player.movespeed) / g_tile;
		*j = (g_player.y + g_player.my * g_player.movespeed) / g_tile;
	}
}

int		ft_checkwall(float x, float y, int n)
{
	int i;
	int j;

	i = 0;
	j = 0;
	ft_checkwall2(&i, &j, n);
	if (n == 1)
	{
		i = floor((int)x / g_tile);
		j = floor((int)y / g_tile);
	}
	if (i < 0 || i >= g_gt.colum || j < 0 || j >= g_gt.hori)
		return (1);
	if (g_gt.map[j][i] == '1')
		return (0);
	if (g_gt.map[j][i] == '2')
		return (2);
	return (1);
}

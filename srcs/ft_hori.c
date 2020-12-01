/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hori.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhadari <yhadari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 19:16:18 by yhadari           #+#    #+#             */
/*   Updated: 2020/11/25 20:06:37 by yhadari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	ft_hori1(int i)
{
	while (g_w.xtocheck >= 0 && g_w.xtocheck < g_gt.colum * g_tile &&
		g_w.ytocheck >= 0 && g_w.ytocheck < g_gt.hori * g_tile)
	{
		if (ft_checkwall(g_w.xtocheck, g_w.ytocheck, 1) == 2)
			ft_tmpsprite(g_w.xtocheck, g_w.ytocheck, i);
		if (!ft_checkwall(g_w.xtocheck, g_w.ytocheck, 1))
		{
			g_w.horizx = g_w.xtocheck;
			g_w.horizy = g_w.ytocheck;
			break ;
		}
		else
		{
			g_w.xtocheck += g_w.xstep;
			g_w.ytocheck += g_w.ystep;
		}
	}
	g_w.horizx = g_w.xtocheck;
	g_w.horizy = g_w.ytocheck;
	if (g_ray[i].facup)
		g_w.horizy += 1;
	g_w.disthori = ft_distance(g_player.x, g_player.y, g_w.horizx, g_w.horizy);
}

void	ft_hori(float angle, int i)
{
	g_w.horiangle = angle;
	g_w.yinter = floor(g_player.y / g_tile) * g_tile;
	if (g_ray[i].facdown)
	{
		g_w.yinter += g_tile;
		g_w.horiangle = g_w.horiangle >= 90 ? g_w.horiangle - 90 :
		90 - g_w.horiangle;
	}
	if (g_ray[i].facup)
		g_w.horiangle = g_w.horiangle >= 270 ? g_w.horiangle - 270 :
			270 - g_w.horiangle;
	g_w.distance = g_w.yinter >= g_player.y ? g_w.yinter - g_player.y :
		g_player.y - g_w.yinter;
	g_w.xinter = g_ray[i].facright ?
		g_player.x + tan(g_w.horiangle * RADIAN) * g_w.distance :
		g_player.x - tan(g_w.horiangle * RADIAN) * g_w.distance;
	g_w.ystep = g_ray[i].facdown ? g_tile : -g_tile;
	g_w.xstep = g_ray[i].facright ? tan(g_w.horiangle * RADIAN) * g_tile :
		-tan(g_w.horiangle * RADIAN) * g_tile;
	g_w.xtocheck = g_w.xinter;
	g_w.ytocheck = g_w.yinter;
	g_w.ytocheck -= g_ray[i].facup ? 1 : 0;
	ft_hori1(i);
}

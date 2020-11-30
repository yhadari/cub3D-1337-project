/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vert.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhadari <yhadari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 19:21:44 by yhadari           #+#    #+#             */
/*   Updated: 2020/11/25 20:27:00 by yhadari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	ft_vert1(int i)
{
	while (g_w.xtocheck >= 0 && g_w.xtocheck < g_gt.colum * g_tile &&
		g_w.ytocheck >= 0 && g_w.ytocheck < g_gt.hori * g_tile)
	{
		if (ft_checkwall(g_w.xtocheck, g_w.ytocheck, 1) == 2)
			ft_tmpsprite(g_w.xtocheck, g_w.ytocheck, i);
		if (!ft_checkwall(g_w.xtocheck, g_w.ytocheck, 1))
		{
			g_w.vertx = g_w.xtocheck;
			g_w.verty = g_w.ytocheck;
			break ;
		}
		else
		{
			g_w.xtocheck += g_w.xstep;
			g_w.ytocheck += g_w.ystep;
		}
	}
	g_w.vertx = g_w.xtocheck;
	g_w.verty = g_w.ytocheck;
	if (g_ray[i].facleft)
		g_w.vertx += 1;
	g_w.distvert = ft_distance(g_player.x, g_player.y, g_w.vertx, g_w.verty);
}

void	ft_vert(float angle, int i)
{
	g_w.vertangle = angle;
	g_w.xinter = floor(g_player.x / g_tile) * g_tile;
	if (g_ray[i].facright)
		g_w.xinter += g_tile;
	g_w.distance = g_w.xinter >= g_player.x ? g_w.xinter - g_player.x :
		g_player.x - g_w.xinter;
	if (g_ray[i].facup && g_ray[i].facright)
		g_w.vertangle = 360 - g_w.vertangle;
	if (g_ray[i].facleft)
		g_w.vertangle = g_w.vertangle >= 180 ?
			g_w.vertangle - 180 : 180 - g_w.vertangle;
	g_w.yinter = g_ray[i].facdown ?
		g_player.y + tan(g_w.vertangle * RADIAN) * g_w.distance :
		g_player.y - tan(g_w.vertangle * RADIAN) * g_w.distance;
	g_w.xstep = g_ray[i].facright ? g_tile : -g_tile;
	g_w.ystep = g_ray[i].facdown ? tan(g_w.vertangle * RADIAN) * g_tile :
		-tan(g_w.vertangle * RADIAN) * g_tile;
	g_w.xtocheck = g_w.xinter;
	g_w.xtocheck -= g_ray[i].facleft ? 1 : 0;
	g_w.ytocheck = g_w.yinter;
	ft_vert1(i);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhadari <yhadari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 20:51:39 by yhadari           #+#    #+#             */
/*   Updated: 2020/11/29 18:38:44 by yhadari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	ft_key1(void)
{
	if (g_player.walkder == -1 && g_player.horizder == 0)
	{
		if (ft_checkwall(g_player.x, g_player.y, 0))
		{
			g_player.x -= g_player.mx * g_player.movespeed;
			g_player.y -= g_player.my * g_player.movespeed;
		}
	}
	if (g_player.turnder == 1 && g_ray[g_num_rays - 1].dis > 6)
	{
		g_p.index = 1;
		g_p.angle = fmod((g_p.angle + g_player.turnspeed), 360);
	}
}

void	ft_key2(void)
{
	if (g_player.horizder == 1 && g_player.walkder == 0)
	{
		if (ft_checkwall(g_player.x, g_player.y, 0) &&
		g_ray[g_num_rays - 1].dis > 10)
		{
			g_player.x += g_player.mx * g_player.movespeed;
			g_player.y += g_player.my * g_player.movespeed;
		}
	}
	if (g_player.horizder == -1 && g_player.walkder == 0)
	{
		if (ft_checkwall(g_player.x, g_player.y, 0) && g_ray[0].dis > 10)
		{
			g_player.x += g_player.mx * g_player.movespeed;
			g_player.y += g_player.my * g_player.movespeed;
		}
	}
}

int		ft_key(void)
{
	if (g_player.walkder == 1 && g_player.horizder == 0)
	{
		if (ft_checkwall(g_player.x, g_player.y, 0) &&
		g_ray[g_num_rays / 2].dis > 16)
		{
			g_player.x += g_player.mx * g_player.movespeed;
			g_player.y += g_player.my * g_player.movespeed;
		}
	}
	if (g_player.turnder == -1 && g_ray[0].dis > 6)
	{
		g_p.index = 1;
		g_p.angle -= g_player.turnspeed;
		if (g_p.angle < 0)
			g_p.angle = 360;
	}
	ft_key1();
	ft_key2();
	return (0);
}

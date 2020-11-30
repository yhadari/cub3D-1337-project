/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_derec.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhadari <yhadari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 20:15:46 by yhadari           #+#    #+#             */
/*   Updated: 2020/11/30 11:39:32 by yhadari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	ft_derec(void)
{
	g_p.index1 = 1;
	g_player.turnspeed = 1.8;
	g_player.movespeed = 4.7;
	if (g_gt.der == 1 && g_p.index != 1)
		g_p.angle = 270;
	if (g_gt.der == 2 && g_p.index != 1)
		g_p.angle = 90;
	if (g_gt.der == 3 && g_p.index != 1)
		g_p.angle = 180;
	if (g_gt.der == 4 && g_p.index != 1)
		g_p.angle = 0;
	g_player.x1 = g_player.x + g_tile * cos(g_p.angle * RADIAN);
	g_player.y1 = g_player.y + g_tile * sin(g_p.angle * RADIAN);
	ft_dda(g_player.x, g_player.y, g_player.x1, g_player.y1);
}

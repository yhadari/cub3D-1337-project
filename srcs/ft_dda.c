/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dda.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhadari <yhadari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 17:01:48 by yhadari           #+#    #+#             */
/*   Updated: 2020/11/26 10:33:58 by yhadari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	ft_dda(int x1, int y1, int x2, int y2)
{
	float i1;
	float j1;

	i1 = x1;
	j1 = y1;
	g_dda.dx = x2 - x1;
	g_dda.dy = y2 - y1;
	g_dda.steps = (abs((int)(g_dda.dx)) > abs((int)(g_dda.dy)) ?
			abs((int)(g_dda.dx)) : abs((int)(g_dda.dy)));
	g_dda.incx = g_dda.dx / g_dda.steps;
	g_dda.incy = g_dda.dy / g_dda.steps;
	g_player.mx = g_dda.incx;
	g_player.my = g_dda.incy;
	while (g_dda.steps > 0 && g_p.index1 != 0)
	{
		if (ft_checkwall(x1, y1, 1))
			ft_put_pixel(x1, y1, 0xffffff);
		i1 += g_dda.incx;
		j1 += g_dda.incy;
		x1 = i1;
		y1 = j1;
		g_dda.steps--;
	}
}

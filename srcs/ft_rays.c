/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rays.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhadari <yhadari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 18:53:45 by yhadari           #+#    #+#             */
/*   Updated: 2020/11/30 11:05:58 by yhadari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int		ft_is_sprite_in_ray(t_sp s)
{
	int	i;

	i = 0;
	while (i < g_nbsprite)
	{
		if (s.indx == g_sp[i].indx && s.indy == g_sp[i].indy)
			return (1);
		i++;
	}
	return (0);
}

int		ft_tmpsprite(float xto, float yto, int i)
{
	int indx;
	int indy;

	indx = xto / g_tile;
	indy = yto / g_tile;
	g_tmpsp[g_gt.nsp].ray = i;
	g_tmpsp[g_gt.nsp].dist = ft_distance(g_player.x, g_player.y, xto, yto);
	g_tmpsp[g_gt.nsp].mdist = ft_distance(g_player.x, g_player.y,
	(indx * g_tile + g_tile / 2), (indy * g_tile + g_tile / 2));
	g_tmpsp[g_gt.nsp].indx = indx;
	g_tmpsp[g_gt.nsp].indy = indy;
	g_tmpsp[g_gt.nsp].x = xto;
	g_tmpsp[g_gt.nsp++].y = yto;
	return (1);
}

float	ft_distance(float x1, float y1, float x2, float y2)
{
	float x;
	float y;

	x = x2 >= x1 ? x2 - x1 : x1 - x2;
	y = y2 >= y1 ? y2 - y1 : y1 - y2;
	return (sqrt((x * x) + (y * y)));
}

void	ft_castrays(float angle, int i)
{
	g_ray[i].facdown = angle > 0 && angle < 180;
	g_ray[i].facup = !g_ray[i].facdown;
	g_ray[i].facright = angle < 90 || angle > 270;
	g_ray[i].facleft = !g_ray[i].facright;
	ft_hori(angle, i);
	ft_vert(angle, i);
	g_ray[i].dis = g_w.disthori > g_w.distvert ? g_w.distvert : g_w.disthori;
	g_ray[i].wallx = g_w.distvert > g_w.disthori ? g_w.horizx : g_w.vertx;
	g_ray[i].wally = g_w.distvert > g_w.disthori ? g_w.horizy : g_w.verty;
	g_ray[i].horizwall = g_w.disthori > g_w.distvert ? 0 : 1;
	g_ray[i].vertwall = g_w.disthori > g_w.distvert ? 1 : 0;
	g_ray[i].angle = angle;
	ft_sprite(g_ray[i].dis);
}

void	ft_rays(void)
{
	int		i;
	float	ang;

	i = 0;
	g_gt.nsp = 0;
	g_nbsprite = 0;
	g_num_rays = 0;
	ang = g_p.angle - FOVANGLE / 2;
	if (g_p.angle < FOVANGLE / 2)
		ang = (360 - (FOVANGLE / 2 - g_p.angle));
	g_num_rays = g_gt.win_wid;
	g_ray = malloc(g_num_rays * sizeof(t_rays));
	g_sp = malloc(g_gt.sprite_number * sizeof(t_sp));
	while (i < g_num_rays)
	{
		g_tmpsp = malloc(g_gt.sprite_number * sizeof(t_sp));
		ft_castrays(ang, i);
		ang = fmod((ang + (float)(FOVANGLE / (float)g_num_rays)), 360);
		free(g_tmpsp);
		g_gt.nsp = 0;
		i++;
	}
	ft_sortsprite();
	ft_map3d();
	ft_drawsprite();
}

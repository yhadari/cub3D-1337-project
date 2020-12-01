/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_drawsprite.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhadari <yhadari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/15 20:55:13 by yhadari           #+#    #+#             */
/*   Updated: 2020/12/01 10:53:22 by yhadari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	ft_fixtexture(int distfromstart, float dist)
{
	g_tx1.ofy = distfromstart * ((float)g_tx1.h / dist);
	g_tx2.ofy = distfromstart * ((float)g_tx2.h / dist);
	g_tx3.ofy = distfromstart * ((float)g_tx3.h / dist);
	g_tx4.ofy = distfromstart * ((float)g_tx4.h / dist);
}

void	ft_calculvector(int i)
{
	g_sp[i].vector1.x = g_ray[0].wallx - g_player.x;
	g_sp[i].vector1.y = g_ray[0].wally - g_player.y;
	g_sp[i].vector2.x = g_sp[i].indx * g_tile + g_tile / 2 - g_player.x;
	g_sp[i].vector2.y = g_sp[i].indy * g_tile + g_tile / 2 - g_player.y;
	g_sp[i].alpha = atan2(g_sp[i].vector2.y, g_sp[i].vector2.x) -
		atan2(g_sp[i].vector1.y, g_sp[i].vector1.x);
	if (g_sp[i].alpha > M_PI)
		g_sp[i].alpha -= M_PI * 2;
	else if (g_sp[i].alpha < -M_PI)
		g_sp[i].alpha += M_PI * 2;
	g_sp[i].mray = g_num_rays * g_sp[i].alpha * (180 / M_PI) / FOVANGLE;
}

void	ft_drawsprite1(int i, float tilex, float tiley, float dist)
{
	int x;
	int y;
	int color;

	x = g_sp[i].mray - dist / 2;
	while (x++ < tilex && dist <= g_gt.win_hi * 5 &&
			abs((int)(FOVANGLE / 2 - g_sp[i].alpha * 180 / M_PI)) < 48)
	{
		y = g_gt.win_hi / 2 - dist / 2;
		tiley = y + dist;
		g_sprite.ofy = 0;
		if (x > 0 && x < (g_num_rays + 1) && g_ray[x - 1].dis > g_sp[i].mdist)
		{
			while (y++ < tiley)
			{
				g_sprite.ofy += g_sprite.h / dist;
				if (g_sprite.ofy < g_sprite.h && g_sprite.ofx < g_sprite.w)
					color = g_sprite.ptr[(int)g_sprite.ofx +
					(int)g_sprite.ofy * g_sprite.h];
				if (color != 0x980088)
					ft_put_pixel(x - 1, y - 1, color);
			}
		}
		g_sprite.ofx += g_sprite.w / dist;
	}
}

void	ft_drawsprite(void)
{
	int		i;
	float	dist;
	float	tilex;
	float	tiley;

	i = 0;
	dist = 0;
	tiley = 0.0;
	g_sprite.image = mlx_xpm_file_to_image(g_mlx_ptr, g_ptr_s,
			&g_sprite.w, &g_sprite.h);
	if (g_sprite.image == NULL)
		ft_error("File xpm sprite error");
	g_sprite.ptr = (int*)mlx_get_data_addr(g_sprite.image, &g_sprite.i,
			&g_sprite.j, &g_sprite.k);
	while (i < g_nbsprite)
	{
		ft_calculvector(i);
		g_sp[i].mdist = g_sp[i].mdist * cos(FOVANGLE / 2 *
				RADIAN - g_sp[i].alpha);
		dist = g_tile * ((g_gt.win_wid + g_gt.win_hi) / 2) / g_sp[i].mdist;
		tilex = g_sp[i].mray - dist / 2 + dist;
		g_sprite.ofx = 0;
		ft_drawsprite1(i++, tilex, tiley, dist);
	}
	mlx_destroy_image(g_mlx_ptr, g_sprite.image);
}

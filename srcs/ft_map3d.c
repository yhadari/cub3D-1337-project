/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map3d.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhadari <yhadari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 20:33:38 by yhadari           #+#    #+#             */
/*   Updated: 2020/12/01 10:53:22 by yhadari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	ft_fc(void)
{
	int i;
	int j;

	i = 0;
	while (i < g_gt.win_hi / 2)
	{
		j = 0;
		while (j < g_gt.win_wid)
		{
			ft_put_pixel(j, i, ft_color(2));
			j++;
		}
		j = 0;
		while (j < g_gt.win_wid)
		{
			ft_put_pixel(j, i + (g_gt.win_hi / 2), ft_color(1));
			j++;
		}
		i++;
	}
}

void	ft_1map3d3(int i, float ystart, float dist, int color)
{
	int	distfromstart;

	distfromstart = ystart + dist / 2 - g_gt.win_hi / 2;
	ft_fixtexture(distfromstart, dist);
	if (g_ray[i].vertwall)
	{
		if (g_ray[i].facright)
			color = g_tx3.ptr[(int)g_tx1.ofx *
			(g_tx3.w / g_tile) + (int)g_tx3.ofy * g_tx3.h];
		else
			color = g_tx4.ptr[(int)g_tx1.ofx *
			(g_tx4.w / g_tile) + (int)g_tx4.ofy * g_tx4.h];
	}
	if (g_ray[i].horizwall)
	{
		if (g_ray[i].facup)
			color = g_tx2.ptr[(int)g_tx1.ofx *
			(g_tx2.w / g_tile) + (int)g_tx2.ofy * g_tx2.h];
		else
			color = g_tx1.ptr[(int)g_tx1.ofx *
			(g_tx1.w / g_tile) + (int)g_tx1.ofy * g_tx1.h];
	}
	if (g_player.x > 0 && g_player.x < g_gt.colum * g_tile &&
	g_player.y > 0 && g_player.y < g_gt.hori * g_tile)
		ft_put_pixel(i, ystart, color);
}

void	ft_map3d3(int i)
{
	int		color;
	float	dist;
	float	ystart;
	float	yend;

	color = 0;
	while (i < g_num_rays)
	{
		g_ray[i].dis = g_ray[i].dis *
		cos(g_ray[i].angle * RADIAN - g_p.angle * RADIAN);
		dist = g_tile * ((g_gt.win_wid + g_gt.win_hi) / 2) / g_ray[i].dis;
		ystart = round(g_gt.win_hi / 2 - dist / 2);
		ystart = ystart < 0 ? 0 : ystart;
		yend = round(g_gt.win_hi / 2 + dist / 2);
		yend = yend > g_gt.win_hi ? g_gt.win_hi : yend;
		if (g_ray[i].vertwall)
			g_tx1.ofx = (int)g_ray[i].wally % g_tile;
		else
			g_tx1.ofx = (int)g_ray[i].wallx % g_tile;
		while (ystart < yend)
			ft_1map3d3(i, ystart++, dist, color);
		i++;
	}
}

void	ft_map3d2(void)
{
	g_tx1.ptr = (int*)mlx_get_data_addr(g_tx1.image, &g_tx1.i,
	&g_tx1.j, &g_tx1.k);
	g_tx2.ptr = (int*)mlx_get_data_addr(g_tx2.image, &g_tx2.i,
	&g_tx2.j, &g_tx2.k);
	g_tx3.ptr = (int*)mlx_get_data_addr(g_tx3.image, &g_tx3.i,
	&g_tx3.j, &g_tx3.k);
	g_tx4.ptr = (int*)mlx_get_data_addr(g_tx4.image, &g_tx4.i,
	&g_tx4.j, &g_tx4.k);
}

void	ft_map3d(void)
{
	int		i;

	ft_fc();
	i = 0;
	g_tx1.image = mlx_xpm_file_to_image(g_mlx_ptr, g_ptr_no,
	&g_tx1.w, &g_tx1.h);
	g_tx2.image = mlx_xpm_file_to_image(g_mlx_ptr, g_ptr_so,
	&g_tx2.w, &g_tx2.h);
	g_tx3.image = mlx_xpm_file_to_image(g_mlx_ptr, g_ptr_we,
	&g_tx3.w, &g_tx3.h);
	g_tx4.image = mlx_xpm_file_to_image(g_mlx_ptr, g_ptr_ea,
	&g_tx4.w, &g_tx4.h);
	if (g_tx1.image == NULL || g_tx2.image == NULL
	|| g_tx3.image == NULL || g_tx4.image == NULL)
		ft_error("File xpm texture error");
	ft_map3d2();
	ft_map3d3(i);
	mlx_destroy_image(g_mlx_ptr, g_tx1.image);
	mlx_destroy_image(g_mlx_ptr, g_tx2.image);
	mlx_destroy_image(g_mlx_ptr, g_tx3.image);
	mlx_destroy_image(g_mlx_ptr, g_tx4.image);
}

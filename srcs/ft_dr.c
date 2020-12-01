/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dr.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhadari <yhadari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 20:28:17 by yhadari           #+#    #+#             */
/*   Updated: 2020/12/01 10:53:22 by yhadari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	ft_put_pixel(int x, int y, int color)
{
	int *ptr;
	int i;
	int j;
	int k;

	if (x >= 0 && y >= 0 && x < g_gt.win_wid && y < g_gt.win_hi)
	{
		ptr = (int*)mlx_get_data_addr(g_image_ptr, &i, &j, &k);
		ptr[x + y * g_gt.win_wid] = color;
	}
}

int		ft_update(void)
{
	int i;

	i = 0;
	g_image_ptr = mlx_new_image(g_mlx_ptr, g_gt.win_wid, g_gt.win_hi);
	ft_derec(g_player.x, g_player.y);
	ft_rays();
	ft_key();
	free(g_ray);
	free(g_sp);
	if (g_save == 1)
		ft_screenshot();
	mlx_put_image_to_window(g_mlx_ptr, g_win_ptr, g_image_ptr, 0, 0);
	mlx_destroy_image(g_mlx_ptr, g_image_ptr);
	return (0);
}

int		ft_ex(int key, void *param)
{
	param = &key;
	free(g_ptr_no);
	free(g_ptr_so);
	free(g_ptr_we);
	free(g_ptr_ea);
	free(g_ptr_s);
	exit(0);
	return (0);
}

int		main(int argc, char **argv)
{
	ft_checkargs(argc, argv);
	g_mlx_ptr = mlx_init();
	ft_readfile();
	g_win_ptr = mlx_new_window(g_mlx_ptr, g_gt.win_wid, g_gt.win_hi, "cub3D");
	mlx_hook(g_win_ptr, 2, 1L << 0, ft_keypress, NULL);
	mlx_hook(g_win_ptr, 3, 1L << 1, ft_keyrelease, NULL);
	mlx_hook(g_win_ptr, 17, 1L << 17, ft_ex, NULL);
	mlx_loop_hook(g_mlx_ptr, ft_update, NULL);
	mlx_loop(g_mlx_ptr);
	return (0);
}

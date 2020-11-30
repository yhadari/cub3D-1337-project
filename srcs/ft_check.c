/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhadari <yhadari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/01 20:20:13 by yhadari           #+#    #+#             */
/*   Updated: 2020/11/30 10:59:06 by yhadari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	ft_check_r(char *save)
{
	g_isr = 1;
	g_gt.win_wid = ft_atoi((save + 1), 1);
	save++;
	while (*save == ' ')
		save++;
	while (*save != ' ')
		save++;
	g_gt.win_len = ft_atoi(save, 0);
	while (*save == ' ')
		save++;
	while (*save != ' ' && *save != '\0')
		save++;
	while (*save != '\0')
	{
		if (*save != ' ')
			ft_error("Resolution error");
		save++;
	}
	if (g_gt.win_wid <= 0 || g_gt.win_len <= 0)
		ft_error("Resolution error");
	if (g_gt.win_len > 1440 || g_gt.win_wid > 2560)
	{
		g_gt.win_len = 1440;
		g_gt.win_wid = 2560;
	}
}

void	ft_check_f(char *save)
{
	int x;
	int y;
	int indx;

	g_isf = 1;
	x = 0;
	y = 0;
	indx = 2;
	g_gt.f = malloc(3 * sizeof(int));
	save++;
	while (*save == ' ')
		save++;
	while (*save != '\0')
	{
		g_gt.f[x++] = ft_atoi(save, indx);
		if (g_gt.f[x - 1] > 255 || g_gt.f[x - 1] < 0)
			ft_error("Floor color_error");
		while (*save != ',' && *save != '\n' && *save != '\0')
			save++;
		if (*save == ',' && save++)
			y++;
		indx = 0;
	}
	if (y != 2)
		ft_error("Floor color_error");
}

void	ft_check_c(char *save)
{
	int x;
	int y;
	int indx;

	g_isc = 1;
	x = 0;
	y = 0;
	indx = 2;
	g_gt.c = malloc(3 * sizeof(int));
	save++;
	while (*save == ' ')
		save++;
	while (*save != '\0')
	{
		g_gt.c[x++] = ft_atoi(save, indx);
		if (g_gt.c[x - 1] > 255 || g_gt.c[x - 1] < 0)
			ft_error("Ceilling color_error");
		while (*save != ',' && *save != '\n' && *save != '\0')
			save++;
		if (*save == ',' && save++)
			y++;
		indx = 0;
	}
	if (y != 2)
		ft_error("Ceilling color_error");
}

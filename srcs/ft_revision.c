/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_revision.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhadari <yhadari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 15:45:30 by yhadari           #+#    #+#             */
/*   Updated: 2020/11/30 11:26:46 by yhadari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static	void	ft_revision1(int *i, int *j)
{
	g_tile = 64;
	if (g_gt.map[*i][*j] == 'N' || g_gt.map[*i][*j] == 'W' ||
			g_gt.map[*i][*j] == 'E' || g_gt.map[*i][*j] == 'S')
	{
		g_player.x = *j * g_tile + g_tile / 2;
		g_player.y = *i * g_tile + g_tile / 2;
	}
	if (g_gt.map[*i + 1][*j] == ' ' || g_gt.map[*i + 1][*j] == '\n' ||
			g_gt.map[*i + 1][*j] == '\0')
		ft_error("Map not closed");
	if (g_gt.map[*i - 1][*j] == ' ' || g_gt.map[*i - 1][*j] == '\n' ||
			g_gt.map[*i - 1][*j] == '\0')
		ft_error("Map not closed");
	if (g_gt.map[*i][*j + 1] == ' ' || g_gt.map[*i][*j + 1] == '\n' ||
			g_gt.map[*i][*j + 1] == '\0')
		ft_error("Map not closed");
	if (g_gt.map[*i][*j - 1] == ' ' || g_gt.map[*i][*j - 1] == '\n' ||
			g_gt.map[*i][*j - 1] == '\0')
		ft_error("Map not closed");
}

void			ft_revision2(int *save, int *i, int *j)
{
	if (g_gt.map[*i][*j] == 'N')
		g_gt.der = 1;
	if (g_gt.map[*i][*j] == 'S')
		g_gt.der = 2;
	if (g_gt.map[*i][*j] == 'W')
		g_gt.der = 3;
	if (g_gt.map[*i][*j] == 'E')
		g_gt.der = 4;
	(*save)++;
}

void			ft_revision(void)
{
	int i;
	int j;
	int save;

	i = 0;
	save = 0;
	while (i < g_gt.hori)
	{
		j = 0;
		while (g_gt.map[i][j] != '\0')
		{
			if (g_gt.map[i][j] == 'N' || g_gt.map[i][j] == 'S' ||
					g_gt.map[i][j] == 'W' || g_gt.map[i][j] == 'E')
				ft_revision2(&save, &i, &j);
			if ((g_gt.map[i][j] == '0' || g_gt.map[i][j] == 'N' ||
						g_gt.map[i][j] == 'W' || g_gt.map[i][j] == 'E' ||
						g_gt.map[i][j] == 'S' || g_gt.map[i][j] == '2')
					&& i > 0 && i < (g_gt.hori - 1))
				ft_revision1(&i, &j);
			j++;
		}
		i++;
	}
	if (save != 1)
		ft_error("You can add one player");
}

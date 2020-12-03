/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_keypress.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhadari <yhadari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 19:13:38 by yhadari           #+#    #+#             */
/*   Updated: 2020/12/01 17:31:15 by yhadari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	ft_0(void)
{
	g_player.walkder = 0;
	g_player.walkder = 0;
	g_player.turnder = 0;
	g_player.turnder = 0;
	g_player.horizder = 0;
	g_player.horizder = 0;
}

int		ft_keypress(int key, void *param)
{
	if (key == 53)
		ft_ex(key, param);
	if (key == 13)
		g_player.walkder = 1;
	if (key == 1)
		g_player.walkder = -1;
	if (key == 124)
		g_player.turnder = 1;
	if (key == 123)
		g_player.turnder = -1;
	if (key == 2)
		g_player.horizder = 1;
	if (key == 0)
		g_player.horizder = -1;
	return (0);
}

int		ft_keyrelease(int key, void *param)
{
	param = &key;
	if (key == 259)
		ft_0();
	if (key == 13)
		g_player.walkder = 0;
	if (key == 1)
		g_player.walkder = 0;
	if (key == 124)
		g_player.turnder = 0;
	if (key == 123)
		g_player.turnder = 0;
	if (key == 2)
		g_player.horizder = 0;
	if (key == 0)
		g_player.horizder = 0;
	return (0);
}

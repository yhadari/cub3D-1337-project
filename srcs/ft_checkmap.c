/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkmap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhadari <yhadari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/01 20:20:00 by yhadari           #+#    #+#             */
/*   Updated: 2020/11/23 10:32:48 by yhadari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	ft_checkmap2(char *save, int len)
{
	int y;

	y = 0;
	while (*save != '\0')
	{
		while (*save == ' ')
		{
			save++;
			len++;
		}
		if (*save == '\n')
		{
			if (len > g_gt.colum)
				g_gt.colum = len;
			len = 0;
			y++;
			if (*(save + 1) == '\n' || *(save + 1) == '\0')
				break ;
		}
		if (*save == '2')
			g_gt.sprite_number++;
		save++;
		len++;
	}
	g_gt.hori = y;
}

void	ft_checkmap(char *save)
{
	int len;

	len = 1;
	g_gt.sprite_number = 0;
	if (save == 0)
		ft_error("you forget THE MAP");
	ft_checkmap2(save, len);
}

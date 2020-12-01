/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sprite.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhadari <yhadari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/08 18:17:10 by yhadari           #+#    #+#             */
/*   Updated: 2020/11/25 20:26:26 by yhadari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	ft_sprite(float dist)
{
	int i;

	i = 0;
	while (i < g_gt.nsp)
	{
		if (dist > g_tmpsp[i].dist && !ft_is_sprite_in_ray(g_tmpsp[i]))
			g_sp[g_nbsprite++] = g_tmpsp[i];
		i++;
	}
}

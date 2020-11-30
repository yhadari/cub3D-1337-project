/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sortsprite.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhadari <yhadari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 20:30:18 by yhadari           #+#    #+#             */
/*   Updated: 2020/11/20 13:05:03 by yhadari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	ft_sortsprite(void)
{
	int		i;
	int		j;
	t_sp	temp;

	i = 0;
	while (i < g_nbsprite)
	{
		j = 0;
		while (j < g_nbsprite - i - 1)
		{
			if (g_sp[j].mdist < g_sp[j + 1].mdist)
			{
				temp = g_sp[j];
				g_sp[j] = g_sp[j + 1];
				g_sp[j + 1] = temp;
			}
			j++;
		}
		i++;
	}
}

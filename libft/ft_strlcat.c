/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhadari <yhadari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 14:25:59 by yhadari           #+#    #+#             */
/*   Updated: 2020/11/04 10:28:45 by yhadari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

size_t		ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	ldst;
	size_t	lsrc;

	i = 0;
	ldst = ft_strlen(dst);
	lsrc = ft_strlen(src);
	if (size <= ldst)
		return (size + lsrc);
	while (src[i] != '\0' && i < (size - ldst) - 1)
	{
		dst[ldst + i] = src[i];
		i++;
	}
	dst[ldst + i] = '\0';
	return (ldst + lsrc);
}

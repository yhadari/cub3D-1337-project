/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhadari <yhadari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 22:52:14 by yhadari           #+#    #+#             */
/*   Updated: 2020/11/22 18:09:15 by yhadari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ptr;
	int		size;

	if (!s1 || !s2)
		return (NULL);
	size = (ft_strlen(s1) + ft_strlen(s2));
	ptr = malloc(size + 1);
	if (!ptr)
		return (NULL);
	ft_memcpy(ptr, s1, ft_strlen(s1));
	ptr[ft_strlen(s1)] = '\0';
	ft_strlcat(ptr, s2, size + 1);
	free((void*)s1);
	return (ptr);
}

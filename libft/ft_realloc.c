/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhadari <yhadari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 10:16:04 by yhadari           #+#    #+#             */
/*   Updated: 2020/11/26 21:00:23 by yhadari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	*ft_realloc(char *ptr, size_t size)
{
	char	*new;
	int		i;

	i = -1;
	new = malloc(size);
	if (!new)
		return (NULL);
	while (ptr[++i])
		new[i] = ptr[i];
	while (size - i - 1)
		new[i++] = '1';
	new[i] = '\0';
	free(ptr);
	return (new);
}

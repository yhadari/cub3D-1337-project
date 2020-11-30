/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhadari <yhadari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 18:26:45 by yhadari           #+#    #+#             */
/*   Updated: 2020/11/25 20:27:45 by yhadari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char		*ft_strjoin1(char const *s1, char const *s2, int x)
{
	char	*ptr;
	int		i;
	int		j;

	if (s1 == NULL)
		s1 = ft_strdup("");
	ptr = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!ptr)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i])
		ptr[i++] = s1[j++];
	j = 0;
	while (s2[j])
		ptr[i++] = s2[j++];
	ptr[i] = '\0';
	free((char*)s1);
	if (x == 1)
		free((char *)s2);
	return (ptr);
}

char		*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ptr;

	if (!s)
		return (NULL);
	ptr = malloc(len + 1);
	if (!ptr)
		return (NULL);
	if (start > ft_strlen(s))
		return (ft_strdup(""));
	if ((start + len) > ft_strlen(s))
		return (ft_strdup((char*)s + start));
	ft_strlcpy(ptr, s + start, len + 1);
	return (ptr);
}

size_t		ft_strlen(const char *s)
{
	size_t i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

size_t		ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t i;

	i = 0;
	if (size > 0)
	{
		while (i < (size - 1) && src[i] != '\0')
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (ft_strlen(src));
}

char		*ft_strdup(const char *s1)
{
	int		i;
	char	*ptr;

	if (!s1)
		return (NULL);
	i = 0;
	ptr = malloc(ft_strlen(s1) + 1);
	if (!ptr)
		return (NULL);
	while (s1[i] != '\0')
	{
		ptr[i] = s1[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}

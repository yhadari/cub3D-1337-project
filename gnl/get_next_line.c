/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhadari <yhadari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 18:26:12 by yhadari           #+#    #+#             */
/*   Updated: 2020/11/25 20:27:27 by yhadari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static	void		*ft_memchr(const void *s, int c, size_t n)
{
	size_t i;

	i = 0;
	while (i < n)
	{
		if ((unsigned char)c != *((unsigned char*)s + i))
			i++;
		else
			return ((unsigned char*)s + i);
	}
	return (NULL);
}

static	size_t		ft_strbn(char *s)
{
	size_t i;

	i = 0;
	while (i < BUFFER_SIZE && s[i] != '\n' && s[i] != '\0')
		i++;
	return (i);
}

static	int			ft_check(char **p, char **line)
{
	char *l;

	if (*p)
	{
		l = *p;
		if (ft_memchr(*p, '\n', ft_strlen(*p)))
		{
			*line = ft_substr(*p, 0, ft_strbn(*p));
			*p = ft_strdup(ft_memchr(*p, '\n', ft_strlen(*p)) + 1);
			free(l);
			return (1);
		}
		*line = ft_strdup(*p);
		free(l);
	}
	return (0);
}

int					get_next_line(int fd, char **line)
{
	static	char	*p;
	char			*buf;
	int				k;

	*line = NULL;
	if ((ft_check(&p, &*line)) == 1)
		return (1);
	buf = malloc((BUFFER_SIZE + 1) * (sizeof(char)));
	p = NULL;
	while ((k = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[k] = '\0';
		if ((p = ft_memchr(buf, '\n', ft_strlen(buf))))
		{
			p = ft_strdup(p + 1);
			*line = ft_strjoin1(*line, ft_substr(buf, 0, ft_strbn(buf)), 1);
			free(buf);
			return (1);
		}
		*line = ft_strjoin1(*line, buf, 0);
	}
	free(buf);
	if (*line == NULL)
		*line = ft_strdup("");
	return (k > 0 ? 1 : k);
}

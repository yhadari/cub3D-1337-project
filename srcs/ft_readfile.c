/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_readfile.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhadari <yhadari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 17:33:15 by yhadari           #+#    #+#             */
/*   Updated: 2020/12/01 14:58:57 by yhadari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void			ft_error(char *str)
{
	write(1, str, ft_strlen(str));
	write(1, "\n", 1);
	exit(0);
}

int				is_map(void)
{
	if (g_isr == 1 && g_isf == 1 && g_isc == 1 && g_isno == 1 &&
	g_isso == 1 && g_iswe == 1 && g_isea == 1 && g_iss == 1)
		return (1);
	return (0);
}

void			ft_vu(char buf)
{
	if (buf != '0' && buf != '1' && buf != '2' && buf != 'N' && buf != 'S' &&
		buf != 'E' && buf != 'W' && buf != ' ' && buf != '\n')
		ft_error("Map error wrong char");
}

static	void	ft_get2(int i, char *buf)
{
	int j;
	int line;

	i = 0;
	g_gt.map = (char**)malloc((g_gt.hori + 1) * sizeof(char*));
	while (*buf != '\0' && (line = g_gt.colum - 1))
	{
		if ((*buf == '\n' && *(buf + 1) == '\n') ||
			(*buf == '\n' && *(buf + 1) == '\0'))
			break ;
		g_gt.map[i] = (char*)malloc(g_gt.colum);
		j = 0;
		ft_checkline(buf, i);
		while (line-- != 0)
		{
			ft_vu(*buf);
			if (*buf != '\n')
				g_gt.map[i][j++] = *(buf++);
			else
				g_gt.map[i][j++] = ' ';
		}
		g_gt.map[i++][j] = '\0';
		buf++;
	}
	g_gt.map[i] = NULL;
}

void			ft_readfile(void)
{
	int		i;
	int		fd;
	char	*line;
	char	*save;
	char	*map;

	i = 0;
	line = NULL;
	save = NULL;
	if (!ft_iscub(g_cub))
		ft_error(".cub error");
	fd = open(g_cub, O_RDWR);
	if (fd == -1)
		ft_error(".cub error");
	ft_readfile2(fd, line, save, &map);
	ft_checkmap(map);
	ft_get2(i, map);
	ft_revision();
	free(map);
	free(g_cub);
	close(fd);
}

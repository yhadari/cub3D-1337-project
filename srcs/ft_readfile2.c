/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_readfile2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhadari <yhadari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 10:26:34 by yhadari           #+#    #+#             */
/*   Updated: 2020/12/01 10:37:36 by yhadari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	ft_checkmapform(int fd, char *line)
{
	int text;
	int i;

	text = 1000;
	while (text--)
	{
		i = get_next_line(fd, &line);
		if (*line != '\0')
			ft_error("Map error");
		free(line);
	}
}

void	ft_1(char **save, char *line)
{
	while (**save == ' ' && (g_isr != 1 || g_isf != 1 || g_isc != 1 ||
				g_isno != 1 || g_isso != 1 || g_iswe != 1 || g_isea != 1 ||
				g_iss != 1) && line++)
		(*save)++;
	if (**save != 'R' && **save != 'F' && **save != 'C' && **save != 'N' &&
		**save != 'S' && **save != 'W' && **save != 'E' && !is_map())
		ft_error("File error");
	if (**save == 'R')
	{
		if (g_isr == 1 || *(*save + 1) != ' ')
			ft_error("Resolution error");
		ft_check_r(line);
	}
	if (**save == 'F')
	{
		if (g_isf == 1 || *(*save + 1) != ' ')
			ft_error("Floor color error");
		ft_check_f(line);
	}
	if (**save == 'C')
	{
		if (g_isc == 1 || *(*save + 1) != ' ')
			ft_error("Ceilling color error");
		ft_check_c(line);
	}
}

void	ft_2(char *save)
{
	if ((*save == 'N' && *(save + 1) == 'O' && *(save + 2) == ' ') ||
			(*save == 'S' && *(save + 1) == 'O' && *(save + 2) == ' ') ||
			(*save == 'W' && *(save + 1) == 'E' && *(save + 2) == ' ') ||
			(*save == 'E' && *(save + 1) == 'A' && *(save + 2) == ' ') ||
			(*save == 'S' && *(save + 1) == ' '))
	{
		if ((*save == 'N' && g_isno == 1) ||
			(*save == 'S' && *(save + 1) == 'O' && g_isso == 1) ||
			(*save == 'W' && g_iswe == 1) || (*save == 'E' && g_isea == 1) ||
			(*save == 'S' && *(save + 1) == ' ' && g_iss == 1))
			ft_error("File error");
		ft_checkdirection(save);
	}
}

void	ft_3(int fd, int tile, char *line, char **map)
{
	int i;
	int indx;

	i = 0;
	indx = 0;
	if (g_isr != 1 || g_isf != 1 || g_isc != 1 || g_isno != 1 ||
			g_isso != 1 || g_iswe != 1 || g_isea != 1 || g_iss != 1)
		ft_error("File error");
	*map = line;
	while (*line != '\0')
	{
		tile += ft_strlen(line) + 1;
		*map = ft_realloc(*map, tile);
		if (indx != 0)
			free(line);
		i = get_next_line(fd, &line);
		*map = ft_strjoin(*map, "\n");
		*map = ft_strjoin(*map, line);
		indx++;
	}
	if (indx)
		free(line);
	ft_checkmapform(fd, line);
}

void	ft_readfile2(int fd, char *line, char *save, char **map)
{
	int i;
	int tile;

	i = 1;
	tile = 0;
	while (i)
	{
		i = get_next_line(fd, &line);
		save = line;
		if (*save != '\0')
			ft_1(&save, line);
		ft_2(save);
		if (*save != 'R' && *save != 'F' && *save != 'C' && *save != 'N' &&
				*save != 'S' && *save != 'W' && *save != 'E' && *save != ' ' &&
				*save != '1' && *save != '\0')
			ft_error("File error");
		if (*save == '1' || *save == ' ')
		{
			ft_3(fd, tile, save, map);
			break ;
		}
		free(line);
	}
}

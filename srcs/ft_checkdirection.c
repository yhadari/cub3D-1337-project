/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkdirection.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhadari <yhadari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 17:26:50 by yhadari           #+#    #+#             */
/*   Updated: 2020/11/25 20:04:09 by yhadari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

char	*ft_teststr(char *str)
{
	int		i;
	int		nb;
	char	*p;

	nb = 0;
	i = ft_strlen(str) + 1;
	p = malloc(i);
	i--;
	while (str[i - 1] == ' ')
	{
		nb++;
		i--;
	}
	nb = ft_strlen(str) - nb;
	i = 0;
	while (nb > 0)
	{
		p[i] = str[i];
		nb--;
		i++;
	}
	p[i] = '\0';
	free(str);
	return (p);
}

void	ft_check1(char *p, char *save, int nb)
{
	int i;

	i = 0;
	if (*p == 'N')
	{
		g_isno = 1;
		g_ptr_no = malloc(nb * sizeof(char));
		while (--nb > 0)
			g_ptr_no[i++] = *(save++);
		g_ptr_no[i] = '\0';
		g_ptr_no = ft_teststr(g_ptr_no);
	}
	if (*p == 'S' && *(p + 1) == 'O')
	{
		g_isso = 1;
		g_ptr_so = malloc(nb * sizeof(char));
		while (--nb > 0)
			g_ptr_so[i++] = *(save++);
		g_ptr_so[i] = '\0';
		g_ptr_so = ft_teststr(g_ptr_so);
	}
}

void	ft_check2(char *p, char *save, int nb)
{
	int i;

	i = 0;
	if (*p == 'W')
	{
		g_iswe = 1;
		g_ptr_we = malloc(nb * sizeof(char));
		while (--nb > 0)
			g_ptr_we[i++] = *(save++);
		g_ptr_we[i] = '\0';
		g_ptr_we = ft_teststr(g_ptr_we);
	}
	if (*p == 'E')
	{
		g_isea = 1;
		g_ptr_ea = malloc(nb * sizeof(char));
		while (--nb > 0)
			g_ptr_ea[i++] = *(save++);
		g_ptr_ea[i] = '\0';
		g_ptr_ea = ft_teststr(g_ptr_ea);
	}
}

void	ft_check3(char *p, char *save, int nb)
{
	int	i;

	i = 0;
	if (*p == 'S' && *(p + 1) != 'O')
	{
		g_iss = 1;
		g_ptr_s = malloc(nb * sizeof(char));
		while (--nb > 0)
		{
			g_ptr_s[i] = *(save++);
			i++;
		}
		g_ptr_s[i] = '\0';
		g_ptr_s = ft_teststr(g_ptr_s);
	}
}

void	ft_checkdirection(char *save)
{
	int	i;
	int	nb;
	char*p;

	i = 0;
	nb = 0;
	p = save;
	if (*save == 'S' && *(save + 1) == ' ')
		save = save + 1;
	else
		save = save + 2;
	while (*save == ' ')
		save++;
	while (*save != '\n' && *save != '\0')
	{
		nb++;
		save++;
	}
	save = save - nb;
	ft_check1(p, save, nb + 1);
	ft_check2(p, save, nb + 1);
	ft_check3(p, save, nb + 1);
}

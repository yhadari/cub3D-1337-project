/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhadari <yhadari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 10:13:57 by yhadari           #+#    #+#             */
/*   Updated: 2020/11/25 20:40:09 by yhadari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	ft_checkcolor1(char *str)
{
	int i;
	int indx;

	indx = 0;
	i = ft_strlen(str) - 1;
	if ((*str < 48 || *str > 57) && *str != 32)
		ft_error("Color error");
	i = 0;
	while (str[i] != 44 && str[i] != '\0')
		i++;
	i++;
	while (str[i] != 44 && str[i] != '\0')
	{
		if (str[i] >= 48 && str[i] <= 57)
			indx = 1;
		i++;
	}
	if (indx == 0)
		ft_error("Color error");
	i = ft_strlen(str) - 1;
	while (str[i] == ' ')
		i--;
	if (str[i] < 48 || str[i] > 57)
		ft_error("Color error");
}

void	ft_checkstr2(char *str, int i, int n)
{
	int comma;

	comma = 0;
	if (n == 2)
		ft_checkcolor1(str);
	while (str[i] != '\0' && n == 2)
	{
		if ((str[i] < 48 || str[i] > 57) && str[i] != 44 && str[i] != 32)
			ft_error("Color error");
		if (str[i] == 44)
			comma++;
		i++;
		while (comma == 2 && str[i] != '\0')
		{
			while (str[i] == 32)
				i++;
			while (str[i] != 32 && str[i] != '\0')
				i++;
			while (str[i] != '\0')
			{
				if (str[i++] != 32)
					ft_error("Color error");
			}
		}
	}
}

void	ft_checkstr(char *str, int n)
{
	int i;

	i = 0;
	if (n != 0)
	{
		while (str[i] != '\0' && n == 1)
		{
			if ((str[i] < 48 || str[i] > 57) && str[i] != 32)
				ft_error("Resolution error");
			i++;
		}
		ft_checkstr2(str, i, n);
	}
}

int		ft_atoi(char *str, int n)
{
	int result;
	int	i;
	int	j;

	i = 0;
	j = 1;
	result = 0;
	ft_checkstr(str, n);
	while (str[i] == ' ' || str[i] == '0' || (str[i] >= 9 && str[i] <= 13) ||
			str[i] == '-')
		i++;
	if ((str[i - 1] == '-' && (i - 1) >= 0) || str[i] == '+' || str[i] == '.')
	{
		if (str[i - 1] != '-')
			i++;
		else
			j = -1;
	}
	while (str[i] != '\0' && (str[i] >= '0' && str[i] <= '9'))
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return (result * j);
}

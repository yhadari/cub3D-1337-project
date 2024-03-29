/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkargs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhadari <yhadari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 13:01:54 by yhadari           #+#    #+#             */
/*   Updated: 2020/12/01 14:58:24 by yhadari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int		ft_iscub(char *str)
{
	int i;

	i = ft_strlen(str) - 4;
	str = str + i;
	if (ft_strncmp(str, ".cub", 4) != 0)
		return (0);
	return (1);
}

void	ft_checkargs(int argc, char **argv)
{
	char	*save;
	int		arg2;

	save = ft_strdup("--save");
	if (argc == 1 && write(1, "you need file .cub\n", 19))
		exit(0);
	if (argc == 2 || argc == 3)
	{
		g_cub = ft_strdup(argv[1]);
		if (argc == 3 && (g_save = 1))
		{
			arg2 = ft_strncmp(argv[2], save, ft_strlen(save));
			if ((arg2 != 0 || ft_strlen(save) != ft_strlen(argv[2])) &&
			write(1, "EROOR\n", 6))
				exit(0);
		}
	}
	else
	{
		write(1, "ERROR\n", 6);
		exit(0);
	}
	free(save);
}

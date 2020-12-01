/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screenshot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhadari <yhadari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 19:42:40 by razaha            #+#    #+#             */
/*   Updated: 2020/12/01 10:53:22 by yhadari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

unsigned char g_header[54] = { 0 };

void	ft_bitmap_create(unsigned char *buf, uint32_t imagesize)
{
	int				fd;

	fd = open("screenshot.bmp", O_CREAT | O_RDWR, S_IWUSR | S_IRUSR);
	if (fd == -1)
		return ;
	write(fd, g_header, 54);
	write(fd, buf, imagesize);
	close(fd);
	free(buf);
}

void	ft_bitmap_calc(uint32_t imagesize, int32_t width, int32_t height,
int width_in_bytes)
{
	char			*add;
	unsigned char	*buf;
	int				row;
	int				i;
	int				sl;

	add = mlx_get_data_addr(g_image_ptr, &row, &sl, &i);
	row = height - 1;
	buf = malloc(imagesize);
	while (row >= 0)
	{
		g_sc.col = 0;
		while (g_sc.col < width)
		{
			i = g_sc.col * 4 + sl * (height - 1 - row);
			buf[row * width_in_bytes + g_sc.col * 3 + 0] = add[i];
			buf[row * width_in_bytes + g_sc.col * 3 + 1] = add[i + 1];
			buf[row * width_in_bytes + g_sc.col * 3 + 2] = add[i + 2];
			g_sc.col++;
		}
		row--;
	}
	ft_bitmap_create(buf, imagesize);
}

void	ft_screenshot(void)
{
	g_sc.w = g_gt.win_wid;
	g_sc.h = g_gt.win_hi;
	g_sc.hdsize = 40;
	g_sc.bfoffbits = 54;
	g_sc.biplanes = 1;
	g_sc.bitcount = 24;
	g_sc.width_in_bytes = ((g_sc.w * g_sc.bitcount + 31) / 32) * 4;
	g_sc.imagesize = g_sc.width_in_bytes * g_sc.h;
	g_sc.filesize = 54 + g_sc.imagesize;
	ft_memcpy(g_header, "BM", 2);
	ft_memcpy(g_header + 2, &g_sc.filesize, 4);
	ft_memcpy(g_header + 10, &g_sc.bfoffbits, 4);
	ft_memcpy(g_header + 14, &g_sc.hdsize, 4);
	ft_memcpy(g_header + 18, &g_sc.w, 4);
	ft_memcpy(g_header + 22, &g_sc.h, 4);
	ft_memcpy(g_header + 26, &g_sc.biplanes, 2);
	ft_memcpy(g_header + 28, &g_sc.bitcount, 2);
	ft_memcpy(g_header + 34, &g_sc.imagesize, 4);
	ft_bitmap_calc(g_sc.imagesize, g_sc.w, g_sc.h, g_sc.width_in_bytes);
	exit(EXIT_SUCCESS);
}

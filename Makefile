# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yhadari <yhadari@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/11 20:29:51 by yhadari           #+#    #+#              #
#    Updated: 2020/12/03 14:05:50 by yhadari          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D

FLAG = gcc -Wall -Wextra -Werror

SRC = srcs/ft_dr.c srcs/ft_check.c srcs/ft_checkline.c srcs/ft_revision.c srcs/ft_checkmap.c \
	srcs/ft_key.c srcs/ft_derec.c srcs/ft_dda.c srcs/ft_checkwall.c srcs/ft_keypress.c libft/ft_strncmp.c \
    srcs/ft_rays.c srcs/ft_map3d.c srcs/ft_hori.c srcs/ft_vert.c srcs/ft_color.c libft/ft_atoi.c \
	srcs/ft_checkdirection.c srcs/ft_readfile.c libft/ft_strjoin.c libft/ft_memcpy.c srcs/screenshot.c \
	libft/ft_strlcat.c gnl/get_next_line.c gnl/get_next_line_utils.c srcs/ft_sprite.c \
	srcs/ft_drawsprite.c srcs/ft_sortsprite.c libft/ft_realloc.c srcs/ft_readfile2.c srcs/ft_checkargs.c \

all : $(NAME)

$(NAME) : 
	@$(FLAG) $(SRC) -L /usr/local/lib -lmlx -framework OpenGL -framework AppKit -Iinclude -o $(NAME)

clean :
	@rm -rf $(NAME)
	
fclean : clean
	@rm -rf *.bmp

re : fclean all

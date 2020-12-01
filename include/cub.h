/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhadari <yhadari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 17:09:23 by yhadari           #+#    #+#             */
/*   Updated: 2020/12/01 10:56:51 by yhadari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_H
# define CUB_H
# define RADIAN M_PI/180
# define FOVANGLE 60
# include "mlx.h"
# include <math.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <fcntl.h>
# include <string.h>
# include "get_next_line.h"

typedef	struct		s_get
{
	int				win_hi;
	int				win_wid;
	int				colum;
	int				hori;
	int				der;
	int				*f;
	int				*c;
	char			**map;
	int				sprite_number;
	int				nsp;
}					t_get;

typedef	struct		s_player
{
	float			x;
	float			y;
	float			x1;
	float			y1;
	float			mx;
	float			my;
	float			movespeed;
	float			turnspeed;
	int				walkder;
	int				turnder;
	int				horizder;
}					t_player;

typedef	struct		s_rays
{
	float			wallx;
	float			wally;
	float			dis;
	float			angle;
	int				facup;
	int				facdown;
	int				facright;
	int				facleft;
	int				vertwall;
	int				horizwall;
}					t_rays;

typedef	struct		s_vector
{
	float			x;
	float			y;
}					t_vector;

typedef	struct		s_sp
{
	float			x;
	float			y;
	float			dist;
	float			mdist;
	int				indx;
	int				indy;
	int				ray;
	float			alpha;
	int				mray;
	t_vector		vector1;
	t_vector		vector2;
	t_vector		vector3;
}					t_sp;

typedef	struct		s_wall
{
	float			distance;
	float			xinter;
	float			yinter;
	float			xstep;
	float			ystep;
	float			xtocheck;
	float			ytocheck;
	float			disthori;
	float			distvert;
	float			horizx;
	float			horizy;
	float			vertx;
	float			verty;
	float			vertangle;
	float			horiangle;
}					t_wall;

typedef	struct		s_p
{
	int				index;
	int				index1;
	float			angle;
}					t_p;

typedef	struct		s_dda
{
	float			dx;
	float			dy;
	float			sx;
	float			sy;
	float			incx;
	float			incy;
	float			steps;
}					t_dda;

typedef	struct		s_texture
{
	int				*ptr;
	void			*image;
	float			ofx;
	float			ofy;
	int				w;
	int				h;
	int				i;
	int				j;
	int				k;
}					t_texture;

typedef struct		s_sc
{
	int32_t			w;
	int32_t			h;
	uint16_t		bitcount;
	int				width_in_bytes;
	uint32_t		imagesize;
	uint32_t		hdsize;
	uint32_t		bfoffbits;
	uint32_t		filesize;
	uint16_t		biplanes;
	int				col;
}					t_sc;

void				*g_mlx_ptr;
void				*g_win_ptr;
void				*g_image_ptr;
t_get				g_gt;
t_player			g_player;
t_p					g_p;
t_dda				g_dda;
t_wall				g_w;
t_rays				*g_ray;
t_sp				*g_sp;
t_sp				*g_tmpsp;
t_texture			g_tx1;
t_texture			g_tx2;
t_texture			g_tx3;
t_texture			g_tx4;
t_texture			g_sprite;
t_sc				g_sc;
char				*g_ptr_no;
char				*g_ptr_so;
char				*g_ptr_we;
char				*g_ptr_ea;
char				*g_ptr_s;
int					g_isno;
int					g_isso;
int					g_iswe;
int					g_isea;
int					g_iss;
int					g_isr;
int					g_isf;
int					g_isc;
int					g_nbsprite;
int					g_spritetile;
int					g_num_rays;
int					g_tile;
int					g_save;
char				*g_cub;

void				ft_error(char *str);
void				ft_check_r(char *save);
void				ft_check_f(char *save);
void				ft_check_c(char *save);
void				ft_checkmap(char *save);
void				ft_checkline(char *buf, int line);
void				ft_revision();
int					ft_key();
void				ft_put_pixel(int x, int y, int color);
void				ft_derec();
void				ft_dda(int x1, int y1, int x2, int y2);
int					ft_checkwall(float x, float y, int n);
int					ft_keypress(int key, void *param);
int					ft_keyrelease(int key, void *param);
int					ft_update();
void				ft_rays();
float				ft_distance(float x1, float x2, float y1, float y2);
void				ft_map3d();
void				ft_castrays(float angle, int i);
void				ft_hori(float angle, int i);
void				ft_vert(float angle, int i);
int					ft_color(int n);
void				ft_checkdirection(char *save);
size_t				ft_strlcat(char *dst, const char *src, size_t size);
void				*ft_memcpy(void *dst, const void *src, size_t n);
int					ft_strncmp(char *s1, char *s2, size_t n);
char				*ft_strjoin(char const *s1, char const *s2);
void				ft_readfile();
int					ft_tmpsprite(float xto, float yto, int i);
void				ft_sprite(float	dist);
int					ft_is_sprite_in_ray(t_sp s);
void				ft_drawsprite();
void				ft_sortsprite();
void				*ft_realloc(char *ptr, size_t size);
int					ft_atoi(char *str, int n);
int					ft_ex(int key, void *param);
void				ft_readfile2(int fd, char *line, char *save, char **map);
int					is_map(void);
void				ft_fixtexture(int distfromstart, float dist);
void				ft_checkargs(int argc, char **argv);
void				ft_screenshot();

#endif

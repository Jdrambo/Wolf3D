/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-rus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/21 21:56:51 by jde-rus           #+#    #+#             */
/*   Updated: 2015/05/29 08:19:15 by jde-rus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF_H
# define WOLF_H

# include "libft.h"
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include <sys/uio.h>
# include <sys/types.h>
# include <math.h>
# include <mlx.h>
# define MAP "map/test.w3d"
# define WIN_W 800
# define WIN_H 600
# define WALL_H 64
# define ESCAPE 53
# define SPACE 49
# define UP 126
# define DOWN 125
# define RIGHT 124
# define LEFT 123

typedef struct	s_pos
{
	float x;
	float y;
}				t_pos;

typedef struct	s_player
{
	t_pos	*start;
	t_pos	*pos;
	t_pos	*dir;
	float	vit;
}				t_player;

typedef struct	s_ray
{
	float			cam;
	t_pos			pos;
	t_pos			dir;
	t_pos			start;
	t_pos			dist;
	t_pos			delta;
	t_pos			step;
	t_pos			plane;
	float			walldist;
	int				hit;
	int				side;
	int				lineh;
	int				draw_start;
	int				draw_end;
	unsigned int	color;
}				t_ray;

typedef struct	s_map
{
	int		width;
	int		height;
	char	**data;
}				t_map;

typedef struct	s_img
{
	void	*a_img;
	char	*data;
	int		bpp;
	int		sizeline;
	int		endian;
}				t_img;

typedef struct s_key
{
	int escape;
	int space;
	int left;
	int up;
	int down;
	int right;
}				t_key;

typedef struct	s_env
{
	void 		*mlx;
	void		*win;
	int			win_w;
	int			win_h;
	int			bpp;
	t_img		*img;
	char		*file;
	t_map		*map;
	t_player	*player;
	float		time;
	float		oldtime;
	t_key		*key;
}				t_env;

void			ft_exit(char *s);
void			init_env(t_env *env);
void			init_image(t_env *env);
void			height_map(t_env *env);
void			width_map(t_env *env);
void			get_map(t_env *env);
void			read_map(t_env *env);
void			destroy_env(t_env *env);
void			main_loop(t_env *env);
void			set_player_start(t_env *env);
int				expose_hook(t_env *env);
void			render(t_env *env);
void			put_pxl_to_img(t_env *env, int x, int y, unsigned long color);
int				is_wall(char c);
void			draw_line(t_env *env, int x, int draw_start, int draw_end,\
		unsigned int color);
void			move(t_env *env);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-rus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/25 23:22:34 by jde-rus           #+#    #+#             */
/*   Updated: 2015/05/29 08:40:19 by jde-rus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

static void	get_dimensions(t_env *env)
{
	int		x;
	int		y;
	int		fd;
	char	*line;

	fd = open(env->file, O_RDONLY);
	if (fd < 0)
		ft_exit("get_dimensions(): ouverture du fichier impossible");
	y = 0;
	while ((get_next_line(fd, &line)) > 0)
	{
		x = 0;
		while (line[x] != '\0')
			x++;
		y++;
		ft_strdel(&line);
	}
	if (line != NULL)
		ft_strdel(&line);
	close(fd);
	env->map->height = y;
	env->map->width = x;
}

static void init_player(t_env *env)
{
	env->player = (t_player*)malloc(sizeof(*(env)->player));
	if (env->player == NULL)
		ft_exit("(init_env.c) Erreur avec le malloc de env->player");
	env->player->pos = (t_pos*)malloc(sizeof(*(env)->player->pos));
	env->player->start = (t_pos*)malloc(sizeof(*(env)->player->start));
	env->player->dir = (t_pos*)malloc(sizeof(*(env)->player->dir));
}

static void	init_map(t_env *env)
{
	int	i;
	env->map = (t_map*)malloc(sizeof(*(env)->map));
	get_dimensions(env);
	env->map->data = (char**)malloc(sizeof(char**) * env->map->height + 1);
	i = 0;
	while (i < env->map->height)
	{
		env->map->data[i] = (char*)malloc(sizeof(char*) * env->map->width + 1);
		i++;
	}
	env->map->data[i] = NULL;
}

static void init_key(t_env *env)
{
	env->key = (t_key*)malloc(sizeof(*(env)->key));
	if (env->key == NULL)
		ft_exit("(init_env.c) Erreur avec le malloc de env->key");
	env->key->escape = 0;
	env->key->space = 0;
	env->key->left = 0;
	env->key->up = 0;
	env->key->down = 0;
	env->key->right = 0;
}

void		init_env(t_env *env)
{
	env->file = ft_strdup(MAP);
	env->win_w = WIN_W;
	env->win_h = WIN_H;
	init_player(env);
	init_map(env);
	init_key(env);
	env->mlx = mlx_init();
	env->win = mlx_new_window(env->mlx, env->win_w, env->win_h, "Wolf 3D");
	init_image(env);
}

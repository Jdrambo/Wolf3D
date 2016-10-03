/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_start.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-rus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/27 15:48:35 by jde-rus           #+#    #+#             */
/*   Updated: 2015/05/29 07:51:30 by jde-rus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

static void	set_dir(t_env *env, float x, float y)
{
	env->player->dir->x = x;
	env->player->dir->y = y;
}

void		set_dir_start(t_env *env)
{
	int x;
	int y;

	x = env->player->start->x;
	y = env->player->start->y;
	if (x > 0 && x < env->map->width && y > 0 && y < env->map->height)
	{
		if (x < (env->map->width / 2) && x < (env->map->height / 2))
			set_dir(env, 1, 0);
		else if (x > (env->map->width / 2) && x < (env->map->height / 2))
			set_dir(env, 0, -1);
		else if (x < (env->map->width / 2) && x > (env->map->height / 2))
			set_dir(env, 0, 1);
		else if (x > (env->map->width / 2) && x > (env->map->height / 2))
			set_dir(env, -1, 0);
		else
			set_dir(env, 1, 0);
	}
	else
		ft_exit("L'emplacement de depart ne semble pas correct");
	env->player->vit = 0.3;
}

void	set_player_start(t_env *env)
{
	int x;
	int y;
	int find;

	find = 0;
	y = 0;
	while (env->map->data[y] != NULL)
	{
		x = 0;
		while (env->map->data[y] && x < env->map->width)
		{
			if (env->map->data[y][x] == 'A')
			{
				find = 1;
				env->player->start->x = x;
				env->player->start->y = y;
				env->player->pos->x = x;
				env->player->pos->y = y;
			}
			x++;
		}
		y++;
	}
	if (find != 1)
		ft_exit("(player_start.c) : Erreur emplacement de depart introuvable");
	set_dir_start(env);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-rus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/29 08:17:37 by jde-rus           #+#    #+#             */
/*   Updated: 2015/05/29 08:30:05 by jde-rus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	move(t_env *env)
{
	if (env->key->escape == 1)
		exit(0);
	if (env->key->up == 1)
	{
		env->player->pos->x += env->player->pos->x * env->player->dir->x;
		env->player->pos->y += env->player->pos->y * env->player->dir->y;
	}
	if (env->key->down == 1)
	{	
		env->player->pos->x -= env->player->pos->x * env->player->dir->x;
		env->player->pos->y -= env->player->pos->y * env->player->dir->y;
	}
}

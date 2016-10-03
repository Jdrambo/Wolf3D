/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-rus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/27 14:41:09 by jde-rus           #+#    #+#             */
/*   Updated: 2015/05/29 08:49:51 by jde-rus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

static	int	key_down(int keycode, t_env *env)
{
	if (keycode == ESCAPE)
		env->key->escape = 1;
	if (keycode == SPACE)
		env->key->space = 1;
	if (keycode == LEFT)
		env->key->left = 1;
	if (keycode == UP)
		env->key->up = 1;
	if (keycode == RIGHT)
		env->key->right = 1;
	if (keycode == DOWN)
		env->key->down = 1;
	move(env);
	return (0);
}

static int	key_up(int keycode, t_env *env)
{
	if (keycode == ESCAPE)
		env->key->escape = 0;
	if (keycode == SPACE)
		env->key->space = 0;
	if (keycode == LEFT)
		env->key->left = 0;
	if (keycode == UP)
		env->key->up = 0;
	if (keycode == RIGHT)
		env->key->right = 0;
	if (keycode == DOWN)
		env->key->down = 0;
	return (0);
}

void	main_loop(t_env *env)
{
	mlx_expose_hook(env->win, expose_hook, env);
	mlx_hook(env->win, 2, 1, key_down, env);
	mlx_hook(env->win, 3, 2, key_up, env);
	mlx_loop_hook(env->mlx, expose_hook, env);

	mlx_loop(env->mlx);
}

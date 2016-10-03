/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-rus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/28 00:14:50 by jde-rus           #+#    #+#             */
/*   Updated: 2015/05/29 07:06:56 by jde-rus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

static void	init_ray(t_env *env, t_ray *ray, float x)
{
	ray->cam = (2 * x / env->win_w) - 1;
	ray->start.x = env->player->pos->x;
	ray->start.y = env->player->pos->y;
	ray->dir.x = env->player->dir->x + ray->plane.x * ray->cam;
	ray->dir.y = env->player->dir->y + ray->plane.y * ray->cam;
	ray->delta.x = sqrt(1 + (ray->dir.y * ray->dir.y)\
			/ (ray->dir.x * ray->dir.x));
	ray->delta.y = sqrt(1 + (ray->dir.x * ray->dir.x)\
			/ (ray->dir.y * ray->dir.y));
	ray->hit = 0;
	ray->pos.x = (int)ray->start.x;
	ray->pos.y = (int)ray->start.y;
}

static void pre_raycast(t_ray *ray)
{
	if (ray->dir.x < 0)
	{
		ray->step.x = -1;
		ray->dist.x = (ray->pos.x - ray->pos.x) * ray->dist.x;
	}
	else
	{
		ray->step.x = 1;
		ray->dist.x = (ray->pos.x + 1 - ray->pos.x) * ray->delta.x;
	}
	if (ray->dir.y < 0)
	{
		ray->step.y = -1;
		ray->dist.y = (ray->pos.y - ray->pos.y) * ray->dist.y;
	}
	else
	{
		ray->plane.y = 1;
		ray->dist.y = (ray->pos.y + 1 - ray->pos.y) * ray->delta.y;
	}
}

static void raycast(t_env *env, t_ray *ray)
{
	while (ray->hit == 0)
	{
		if (ray->dist.x < ray->dist.y)
		{
			ray->dist.x += ray->delta.x;
			ray->pos.x += ray->step.x;
			ray->side = 0;
		}
		else
		{
			ray->dist.y += ray->delta.y;
			ray->pos.y += ray->step.y;
			ray->side = 1;
		}
		if (is_wall(env->map->data[(int)ray->pos.x][(int)ray->pos.y]) == 1)
			ray->hit = 1;
	}
	if (ray->side == 0)
		ray->walldist = ft_abs((ray->pos.x - ray->start.x +\
					(1 - ray->step.x)) / ray->dir.x);
	else
		ray->walldist = ft_abs((ray->pos.y - ray->start.y +\
					(1 - ray->step.y)) / ray->dir.y);
}

static void line_height(t_env *env, t_ray *ray, int x)
{
	ray->lineh = ft_abs((int)(WIN_H / ray->walldist));
	ray->draw_start = -(ray->lineh) / 2 + env->win_h / 2;
	if (ray->draw_start < 0)
		ray->draw_start = 0;
	ray->draw_end = ray->lineh / 2 + env->win_h / 2;
	if (ray->draw_end >= env->win_h)
		ray->draw_end = env->win_h - 1;
	ray->color = 0x0000ff;
	if (ray->side == 1)
		ray->color /= 2;
	draw_line(env, x, ray->draw_start, ray->draw_end, ray->color);
}

void		render(t_env *env)
{
	int		x;
	t_ray	ray;

	x = 0;
	while (x <= env->win_w)
	{
		init_ray(env, &ray, x);
		pre_raycast(&ray);
		raycast(env, &ray);
		line_height(env, &ray, x);
		x++;
	}
	mlx_put_image_to_window(env->mlx, env->win, env->img->a_img, 0, 0);
}

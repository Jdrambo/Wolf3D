/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_image.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-rus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/27 21:18:59 by jde-rus           #+#    #+#             */
/*   Updated: 2015/05/29 06:51:51 by jde-rus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	init_image(t_env *env)
{
	env->img = (t_img*)malloc(sizeof(*(env)->img));
	if (env->img ==NULL)
		ft_exit("(init_image.c) Erreur durant le malloc de env->img");
	env->img->a_img = mlx_new_image(env->mlx, env->win_w, env->win_h);
	env->img->data = mlx_get_data_addr(env->img->a_img, &(env->img->bpp),\
			&(env->img->sizeline), &(env->img->endian));
}

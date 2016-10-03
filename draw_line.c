/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-rus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/29 01:21:35 by jde-rus           #+#    #+#             */
/*   Updated: 2015/05/29 07:20:00 by jde-rus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	draw_line(t_env *env, int x, int draw_start, int draw_end,\
		unsigned int color)
{
	int i;

	i = 0;
	while (i <= env->win_h)
	{
		if (i >= draw_start && i <= draw_end)
			put_pxl_to_img(env, x, i, color);
		else
			put_pxl_to_img(env, x, i, 0x949494);
		i++;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_in_image.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-rus <jde-rus@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/14 21:16:42 by jde-rus           #+#    #+#             */
/*   Updated: 2015/05/28 00:11:41 by jde-rus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void			put_pxl_to_img(t_env *env, int x, int y, unsigned long color)
{
	int				i;
	unsigned int	col[(env->img->bpp / 8) - 1];

	i = 0;
	if (x < WIN_W && y < WIN_H && x >= 0 && y >= 0)
	{
		if (env->img->endian == 0)
		{
			while (i < (env->img->bpp / 8) - 1)
			{
				col[i] = color >> (i * 8);
				i++;
			}
			while (i >= 0)
			{
				env->img->data\
					[y * env->img->sizeline + x *\
					(env->img->bpp) / 8 + i] = col[i];
				i--;
			}
		}
	}
}

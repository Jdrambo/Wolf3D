/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-rus <jde-rus@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/08 04:01:11 by jde-rus           #+#    #+#             */
/*   Updated: 2015/05/26 02:04:39 by jde-rus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

static void	stock(t_env *env, char *line, int y)
{
	int x;

	x = 0;
	while (line[x] != '\0')
	{
		env->map->data[y][x] = line[x];
		x++;
	}
}

void		get_map(t_env *env)
{
	char	*line;
	int		fd;
	int		y;

	y = 0;
	fd = open(env->file, O_RDONLY);
	if (fd < 0)
		ft_exit("get_map(): ouverture du fichier impossible");
	while (get_next_line(fd, &line) > 0)
	{
		stock(env, line, y);
		y++;
		ft_strdel(&line);
	}
	if (line != NULL)
		ft_strdel(&line);
}

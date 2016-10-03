/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-rus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/21 17:26:33 by jde-rus           #+#    #+#             */
/*   Updated: 2015/05/27 20:05:17 by jde-rus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

int main(void)
{
	t_env *env;

	env = (t_env*)malloc(sizeof(*env));
	if (env == NULL)
		ft_exit("Erreur lors du malloc de env");
	init_env(env);
	get_map(env);
	set_player_start(env);
	read_map(env);
	main_loop(env);
	destroy_env(env);
	return (0);
}

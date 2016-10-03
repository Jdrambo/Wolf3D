#include "wolf.h"

static void	free_player(t_env *env)
{
	free(env->player->pos);
	env->player->pos = NULL;
	free(env->player->dir);
	env->player->dir = NULL;
	free(env->player->start);
	env->player->start = NULL;
	free(env->player);
	env->player = NULL;
}

void	destroy_env(t_env *env)
{
	int	y;

	y = 0;
	free(env->file);
	while (env->map->data[y] != NULL)
	{
		free(env->map->data[y]);
		env->map->data[y] = NULL;
		y++;
	}
	free(env->map->data);
	env->map->data = NULL;
	free(env->map);
	env->map = NULL;
	free_player(env);
	free(env->key);
	env->key = NULL;
	free(env);
	env = NULL;
}

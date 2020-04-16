#include "env.h"

int			update_sector_entities_light_event(t_event *event, void *penv)
{
	t_env	*env;
	int		i;

	env = (t_env*)penv;
	i = 0;
	while (i < env->nb_enemies)
	{
		if (env->enemies[i].sector == event->update_param.sector)
			update_enemy_light(env, i);
		i++;
	}
	i = 0;
	while (i < env->nb_objects)
	{
		if (env->objects[i].sector == event->update_param.sector)
			update_object_light(env, i);
		i++;
	}
	return (0);
}

int			update_object_sector_event(t_event *event, void *penv)
{
	t_env	*env;

	env = (t_env*)penv;
	update_object_light(env, event->update_param.object);
	return (0);
}

int			update_enemy_sector_event(t_event *event, void *penv)
{
	t_env	*env;

	env = (t_env*)penv;
	update_enemy(env, event->update_param.enemy);
	return (0);
}

int			update_vertex_event(t_event *event, void *penv)
{
	t_env	*env;
	int		i;
	int		j;

	env = (t_env*)penv;
	i = -1;
	while (++i < env->nb_sectors)
	{
		j = -1;
		while (++j < env->sectors[i].nb_vertices)
		{
			if (env->sectors[i].vertices[j] != event->update_param.vertex)
			  	continue ;
			update_sector_slope(env, &env->sectors[i]);
			if (env->player.sector == i)
			{
				update_player_pos(env);
				env->player.pos.z = get_floor_at_pos(&env->
				sectors[env->player.sector], env->player.pos, env);
				update_player_pos(env);
			}
			break ;
		}
	}
	return (0);
}

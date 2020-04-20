#include "env.h"

int			update_floor_texture_event(t_event *event, void *penv)
{
	t_env	*env;

	env = (t_env*)penv;
	if (env->sectors[event->update_param.sector].floor_texture < 0)
		env->contains_skybox = 1;
	if (set_sector_floor_map_array(&env->sectors[event->update_param.sector],
		&env->wall_textures[env->sectors[event->update_param.sector].
		floor_texture], env))
		return (-1);
	return (0);
}

int			update_ceiling_texture_event(t_event *event, void *penv)
{
	t_env	*env;

	env = (t_env*)penv;
	if (env->sectors[event->update_param.sector].ceiling_texture < 0)
		env->contains_skybox = 1;
	if (set_sector_ceiling_map_array(&env->sectors[event->update_param.sector],
		&env->wall_textures[env->sectors[event->update_param.sector].
		ceiling_texture], env))
		return (-1);
	return (0);
}

int			update_wall_texture_event(t_event *event, void *penv)
{
	t_env	*env;

	env = (t_env*)penv;
	if (env->sectors[event->update_param.sector].
		textures[event->update_param.wall] < 0)
		env->contains_skybox = 1;
	if (set_sector_wall_map_array(&env->sectors[event->update_param.sector],
		&env->wall_textures[env->sectors[event->update_param.sector].
		textures[event->update_param.wall]], event->update_param.wall, env))
		return (-1);
	if (set_camera_map_array(&env->player.camera, event->update_param.sector,
		event->update_param.wall, env))
		return (-1);
	return (0);
}

int			update_sector_event(t_event *event, void *penv)
{
	t_env	*env;
	int		i;

	env = (t_env*)penv;
	update_sector_slope(env, &env->sectors[event->update_param.sector]);
	if (env->player.sector == event->update_param.sector)
		update_player_z(env);
	i = 0;
	while (i < env->nb_enemies)
	{
		if (env->enemies[i].sector == event->update_param.sector)
			update_enemy_z(env, i);
		i++;
	}
	return (0);
}

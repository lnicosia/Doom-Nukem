/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_updaters.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipatry <sipatry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 12:05:50 by lnicosia          #+#    #+#             */
/*   Updated: 2020/01/20 11:55:30 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "collision.h"

t_event_param	new_event_param(int num, double equ_value, double diff_value)
{
	t_event_param	new;

	ft_bzero(&new, sizeof(new));
	new.num = num;
	new.equ_value = equ_value;
	new.diff_value = diff_value;
	return (new);
}

t_event_param	empty_event_param(void)
{
	t_event_param	new;

	ft_bzero(&new, sizeof(new));
	return (new);
}

int			update_sector_event(t_event *event, void *penv)
{
	t_env	*env;

	env = (t_env*)penv;
	update_sector_slope(env, &env->sectors[event->update_param.sector]);
	if (env->player.sector == event->update_param.sector)
		update_player_pos(env);
	return (0);
}

int			update_player_pos_event(t_event *event, void *penv)
{
	(void)event;
	update_player_pos((t_env*)penv);
	return (0);
}

int			update_player_z_event(t_event *event, void *penv)
{
	t_env	*env;

	(void)event;
	env = ((t_env*)penv);
	update_player_pos(env);
	env->player.pos.z = get_floor_at_pos(env->sectors[env->player.sector],
	env->player.pos, env);
	update_player_pos(env);
	return (0);
}

int			update_player_event(t_event *event, void *penv)
{
	(void)event;
	update_player_pos((t_env*)penv);
	return (0);
}

int			update_floor_texture_event(t_event *event, void *penv)
{
	t_env	*env;

	env = (t_env*)penv;
	if (env->sectors[event->update_param.sector].floor_texture < 0)
		env->contains_skybox = 1;
	if (set_sector_floor_map_array(&env->sectors[event->update_param.sector],
		env->wall_textures[env->sectors[event->update_param.sector].
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
		env->wall_textures[env->sectors[event->update_param.sector].
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
		env->wall_textures[env->sectors[event->update_param.sector].
		textures[event->update_param.wall]], event->update_param.wall, env))
		return (-1);
	if (set_camera_map_array(&env->player.camera, event->update_param.sector,
		event->update_param.wall, env))
		return (-1);
	return (0);
}

int			delete_itself_event(t_event *event, void *penv)
{
	ft_delindex(event->update_param.target,
			sizeof(*event->update_param.target) * event->update_param.size,
			sizeof(*event->update_param.target),
			sizeof(*event->update_param.target) * event->update_param.num);
	(void)penv;
	return (0);
}

int			update_sector_entities_event(t_event *event, void *penv)
{
	t_env	*env;
	int		i;

	env = (t_env*)penv;
	i = 0;
	while (i < env->nb_enemies)
	{
		if (env->enemies[i].sector == event->update_param.sector)
		{
			env->enemies[i].brightness =
			env->sectors[event->update_param.sector].brightness;
			env->enemies[i].light_color =
			env->sectors[event->update_param.sector].light_color;
			env->enemies[i].intensity =
			env->sectors[event->update_param.sector].intensity;
		}
		i++;
	}
	i = 0;
	while (i < env->nb_objects)
	{
		if (env->objects[i].sector == event->update_param.sector)
		{
			env->objects[i].brightness =
			env->sectors[event->update_param.sector].brightness;
			env->objects[i].light_color =
			env->sectors[event->update_param.sector].light_color;
			env->objects[i].intensity =
			env->sectors[event->update_param.sector].intensity;
		}
		i++;
	}
	return (0);
}

int			update_object_sector_event(t_event *event, void *penv)
{
	t_env	*env;

	env = (t_env*)penv;
	env->objects[event->update_param.object].sector = get_sector(env,
	env->objects[event->update_param.object].pos, 
	env->objects[event->update_param.object].sector);
	env->objects[event->update_param.object].brightness =
	env->sectors[env->objects[event->update_param.object].sector].brightness;
	env->objects[event->update_param.object].light_color =
	env->sectors[env->objects[event->update_param.object].sector].light_color;
	env->objects[event->update_param.object].intensity =
	env->sectors[env->objects[event->update_param.object].sector].intensity;
	return (0);
}

int			update_enemy_sector_event(t_event *event, void *penv)
{
	t_env	*env;

	env = (t_env*)penv;
	env->enemies[event->update_param.enemy].sector = get_sector(env,
	env->enemies[event->update_param.enemy].pos, 
	env->enemies[event->update_param.enemy].sector);
	env->enemies[event->update_param.enemy].brightness =
	env->sectors[env->enemies[event->update_param.enemy].sector].brightness;
	env->enemies[event->update_param.enemy].light_color =
	env->sectors[env->enemies[event->update_param.enemy].sector].light_color;
	env->enemies[event->update_param.enemy].intensity =
	env->sectors[env->enemies[event->update_param.enemy].sector].intensity;
	return (0);
}

/*int				launch_prec_event_ended(t_event *event, void *penv)
{
	t_event	*target;

	(void)penv;
	//ft_printf("Current time = %d\n", (int)SDL_GetTicks());
	//ft_printf("Prec event ended at %d\n",
	//(int)(*(Uint32*)event->launch_param.target));
	target = (t_event*)event->launch_param.target;
	if (SDL_GetTicks() >= target->end_time + event->delay && target->happened)
	{
		target->happened = 0;
		return (1);
	}
	return (0);
}

int				launch_prec_event_ended_starter(t_event *event, void *penv)
{
	t_event	*target;

	(void)penv;
	//ft_printf("Current time = %d\n", (int)SDL_GetTicks());
	//ft_printf("Prec event ended at %d\n",
	//(int)(*(Uint32*)event->launch_param.target));
	target = (t_event*)event->launch_param.target;
	if ((SDL_GetTicks() >= target->end_time + event->delay && target->happened) || !event->uses)
	{
		target->happened = 0;
		return (1);
	}
	return (0);
}*/

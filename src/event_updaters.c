/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_updaters.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipatry <sipatry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 12:05:50 by lnicosia          #+#    #+#             */
/*   Updated: 2020/02/25 14:28:20 by lnicosia         ###   ########.fr       */
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
	env->player.pos.z = get_floor_at_pos(&env->sectors[env->player.sector],
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
	i = 0;
	while (i < env->nb_sectors)
	{
		j = 0;
		while (j < env->sectors[i].nb_vertices)
		{
			if (env->sectors[i].vertices[j] == event->update_param.vertex)
			{
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
			j++;
		}
		i++;
	}
	return (0);
}

int			update_object_sprite_event(t_event *event, void *penv)
{
	t_env	*env;

	env = (t_env *)penv;
	env->objects[event->update_param.object].sprite =
	env->objects_main_sprites[env->objects[event->update_param.object].sprite];
	return (0);
}

int			update_enemy_sprite_event(t_event *event, void *penv)
{
	t_env	*env;

	env = (t_env *)penv;
	env->enemies[event->update_param.enemy].sprite =
	env->enemies_main_sprites[env->objects[event->update_param.enemy].sprite];
	return (0);
}

int			update_wall_sprite_event(t_event *event, void *penv)
{
	t_env	*env;

	env = (t_env *)penv;
	env->sectors[event->update_param.sector].wall_sprites[event->
	update_param.wall].sprite[event->update_param.sprite] =
	env->objects_main_sprites[env->sectors[event->update_param.sector]
	.wall_sprites[event->update_param.wall].sprite[event->update_param.sprite]];
	return (0);
}

int			update_floor_sprite_event(t_event *event, void *penv)
{
	t_env	*env;

	env = (t_env *)penv;
	env->sectors[event->update_param.sector].floor_sprites.sprite[event->
	update_param.sprite] =
	env->objects_main_sprites[env->sectors[event->update_param.sector]
	.floor_sprites.sprite[event->update_param.sprite]];
	return (0);
}

int			update_ceiling_sprite_event(t_event *event, void *penv)
{
	t_env	*env;

	env = (t_env *)penv;
	env->sectors[event->update_param.sector].ceiling_sprites.sprite[event->
	update_param.sprite] =
	env->objects_main_sprites[env->sectors[event->update_param.sector]
	.ceiling_sprites.sprite[event->update_param.sprite]];
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

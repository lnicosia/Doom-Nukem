/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_box_updaters.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipatry <sipatry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 12:05:50 by lnicosia          #+#    #+#             */
/*   Updated: 2020/01/31 14:48:01 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "collision.h"

int			update_sector_input_box(void *penv)
{
	t_env	*env;

	env = (t_env*)penv;
	if (env->selected_floor != -1)
	{
		update_sector_slope(env, &env->sectors[env->selected_floor]);
		if (env->player.sector == env->selected_ceiling)
			update_player_pos(env);
	}
	else if (env->selected_ceiling != -1)
	{
		update_sector_slope(env, &env->sectors[env->selected_ceiling]);
		if (env->player.sector == env->selected_ceiling)
			update_player_pos(env);
	}
	else if (env->editor.selected_sector != -1)
	{
		update_sector_slope(env, &env->sectors[env->editor.selected_sector]);
		if (env->player.sector == env->editor.selected_sector)
			update_player_pos(env);
	}
	return (0);
}

int			update_floor_sprite_scale_input_box(void *penv)
{
	t_env	*env;

	env = (t_env*)penv;
	precompute_floor_sprite_scales(env->selected_floor,
	env->selected_floor_sprite, env);
	return (0);
}

int			update_ceiling_sprite_scale_input_box(void *penv)
{
	t_env	*env;

	env = (t_env*)penv;
	precompute_ceiling_sprite_scales(env->selected_ceiling,
	env->selected_ceiling_sprite, env);
	return (0);
}

/*int			update_floor_texture_input_box(t_event *event, void *penv)
{
	t_env	*env;

	env = (t_env*)penv;
	if (env->sectors[input_box->update_param.sector].floor_texture < 0)
		env->contains_skybox = 1;
	if (set_sector_floor_map_array(&env->sectors[input_box->update_param.sector],
		env->wall_textures[env->sectors[input_box->update_param.sector].
		floor_texture], env))
		return (-1);
	return (0);
}

int			update_ceiling_texture_input_box(t_event *event, void *penv)
{
	t_env	*env;

	env = (t_env*)penv;
	if (env->sectors[input_box->update_param.sector].ceiling_texture < 0)
		env->contains_skybox = 1;
	if (set_sector_ceiling_map_array(&env->sectors[input_box->update_param.sector],
		env->wall_textures[env->sectors[input_box->update_param.sector].
		ceiling_texture], env))
		return (-1);
	return (0);
}

int			update_wall_texture_input_box(t_event *event, void *penv)
{
	t_env	*env;

	env = (t_env*)penv;
	if (env->sectors[input_box->update_param.sector].
		textures[input_box->update_param.wall] < 0)
		env->contains_skybox = 1;
	if (set_sector_wall_map_array(&env->sectors[input_box->update_param.sector],
		env->wall_textures[env->sectors[input_box->update_param.sector].
		textures[input_box->update_param.wall]], event->update_param.wall, env))
		return (-1);
	if (set_camera_map_array(&env->player.camera, input_box->update_param.sector,
		input_box->update_param.wall, env))
		return (-1);
	return (0);
}

int			delete_itself_input_box(t_event *event, void *penv)
{
	ft_delindex(input_box->update_param.target,
			sizeof(*input_box->update_param.target) * event->update_param.size,
			sizeof(*input_box->update_param.target),
			sizeof(*input_box->update_param.target) * event->update_param.num);
	(void)penv;
	return (0);
}

int			update_sector_entities_input_box(t_event *event, void *penv)
{
	t_env	*env;
	int		i;

	env = (t_env*)penv;
	i = 0;
	while (i < env->nb_enemies)
	{
		if (env->enemies[i].sector == input_box->update_param.sector)
		{
			env->enemies[i].brightness =
			env->sectors[input_box->update_param.sector].brightness;
			env->enemies[i].light_color =
			env->sectors[input_box->update_param.sector].light_color;
			env->enemies[i].intensity =
			env->sectors[input_box->update_param.sector].intensity;
		}
		i++;
	}
	i = 0;
	while (i < env->nb_objects)
	{
		if (env->objects[i].sector == input_box->update_param.sector)
		{
			env->objects[i].brightness =
			env->sectors[input_box->update_param.sector].brightness;
			env->objects[i].light_color =
			env->sectors[input_box->update_param.sector].light_color;
			env->objects[i].intensity =
			env->sectors[input_box->update_param.sector].intensity;
		}
		i++;
	}
	return (0);
}

int			update_object_sector_input_box(t_event *event, void *penv)
{
	t_env	*env;

	env = (t_env*)penv;
	env->objects[input_box->update_param.object].sector = get_sector(env,
	env->objects[input_box->update_param.object].pos, 
	env->objects[input_box->update_param.object].sector);
	env->objects[input_box->update_param.object].brightness =
	env->sectors[env->objects[input_box->update_param.object].sector].brightness;
	env->objects[input_box->update_param.object].light_color =
	env->sectors[env->objects[input_box->update_param.object].sector].light_color;
	env->objects[input_box->update_param.object].intensity =
	env->sectors[env->objects[input_box->update_param.object].sector].intensity;
	return (0);
}

int			update_enemy_sector_input_box(t_event *event, void *penv)
{
	t_env	*env;

	env = (t_env*)penv;
	env->enemies[input_box->update_param.enemy].sector = get_sector(env,
	env->enemies[input_box->update_param.enemy].pos, 
	env->enemies[input_box->update_param.enemy].sector);
	env->enemies[input_box->update_param.enemy].brightness =
	env->sectors[env->enemies[input_box->update_param.enemy].sector].brightness;
	env->enemies[input_box->update_param.enemy].light_color =
	env->sectors[env->enemies[input_box->update_param.enemy].sector].light_color;
	env->enemies[input_box->update_param.enemy].intensity =
	env->sectors[env->enemies[input_box->update_param.enemy].sector].intensity;
	return (0);
}

int			update_vertex_input_box(t_event *event, void *penv)
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
			if (env->sectors[i].vertices[j] == input_box->update_param.vertex)
			{
				update_sector_slope(env, &env->sectors[i]);
				if (env->player.sector == i)
				{
					update_player_pos(env);
					env->player.pos.z = get_floor_at_pos(env->
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

int			update_object_sprite_input_box(t_event *event, void *penv)
{
	t_env	*env;

	env = (t_env *)penv;
	env->objects[input_box->update_param.object].sprite =
	env->objects_main_sprites[env->objects[input_box->update_param.object].sprite];
	return (0);
}

int			update_enemy_sprite_input_box(t_event *event, void *penv)
{
	t_env	*env;

	env = (t_env *)penv;
	env->enemies[input_box->update_param.enemy].sprite =
	env->enemies_main_sprites[env->objects[input_box->update_param.enemy].sprite];
	return (0);
}

int			update_wall_sprite_input_box(t_event *event, void *penv)
{
	t_env	*env;

	env = (t_env *)penv;
	env->sectors[input_box->update_param.sector].wall_sprites[event->
	update_param.wall].sprite[input_box->update_param.sprite] =
	env->objects_main_sprites[env->sectors[input_box->update_param.sector]
	.wall_sprites[input_box->update_param.wall].sprite[event->update_param.sprite]];
	return (0);
}

int			update_floor_sprite_input_box(t_event *event, void *penv)
{
	t_env	*env;

	env = (t_env *)penv;
	env->sectors[input_box->update_param.sector].floor_sprites.sprite[event->
	update_param.sprite] =
	env->objects_main_sprites[env->sectors[input_box->update_param.sector]
	.floor_sprites.sprite[input_box->update_param.sprite]];
	return (0);
}

int			update_ceiling_sprite_input_box(t_event *event, void *penv)
{
	t_env	*env;

	env = (t_env *)penv;
	env->sectors[input_box->update_param.sector].ceiling_sprites.sprite[event->
	update_param.sprite] =
	env->objects_main_sprites[env->sectors[input_box->update_param.sector]
	.ceiling_sprites.sprite[input_box->update_param.sprite]];
	return (0);
}*/

/*int				launch_prec_input_box_ended(t_event *event, void *penv)
{
	t_input_box	*target;

	(void)penv;
	//ft_printf("Current time = %d\n", (int)SDL_GetTicks());
	//ft_printf("Prec input_box ended at %d\n",
	//(int)(*(Uint32*)input_box->launch_param.target));
	target = (t_input_box*)event->launch_param.target;
	if (SDL_GetTicks() >= target->end_time + input_box->delay && target->happened)
	{
		target->happened = 0;
		return (1);
	}
	return (0);
}

int				launch_prec_input_box_ended_starter(t_event *event, void *penv)
{
	t_input_box	*target;

	(void)penv;
	//ft_printf("Current time = %d\n", (int)SDL_GetTicks());
	//ft_printf("Prec input_box ended at %d\n",
	//(int)(*(Uint32*)input_box->launch_param.target));
	target = (t_input_box*)event->launch_param.target;
	if ((SDL_GetTicks() >= target->end_time + input_box->delay && target->happened) || !event->uses)
	{
		target->happened = 0;
		return (1);
	}
	return (0);
}*/

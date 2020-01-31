/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_box_updaters.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipatry <sipatry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 12:05:50 by lnicosia          #+#    #+#             */
/*   Updated: 2020/01/31 17:19:23 by lnicosia         ###   ########.fr       */
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

int			update_sector_entities_input_box(void *penv)
{
	t_env	*env;
	int		sector;
	int		i;

	env = (t_env*)penv;
	if (env->editor.selected_sector != -1)
		sector = env->editor.selected_sector;
	else if (env->selected_ceiling != -1)
		sector = env->selected_ceiling;
	else if (env->selected_floor != -1)
		sector = env->selected_floor;
	else
		return (0);
	i = 0;
	while (i < env->nb_enemies)
	{
		if (env->enemies[i].sector == sector)
		{
			env->enemies[i].brightness =
			env->sectors[sector].brightness;
			env->enemies[i].light_color =
			env->sectors[sector].light_color;
			env->enemies[i].intensity =
			env->sectors[sector].intensity;
		}
		i++;
	}
	i = 0;
	while (i < env->nb_objects)
	{
		if (env->objects[i].sector == sector)
		{
			env->objects[i].brightness =
			env->sectors[sector].brightness;
			env->objects[i].light_color =
			env->sectors[sector].light_color;
			env->objects[i].intensity =
			env->sectors[sector].intensity;
		}
		i++;
	}
	return (0);
}

int			update_object_sector_input_box(void *penv)
{
	t_env	*env;

	env = (t_env*)penv;
	env->objects[env->selected_object].sector = get_sector(env,
	env->objects[env->selected_object].pos, 
	env->objects[env->selected_object].sector);
	env->objects[env->selected_object].brightness =
	env->sectors[env->objects[env->selected_object].sector].brightness;
	env->objects[env->selected_object].light_color =
	env->sectors[env->objects[env->selected_object].sector].light_color;
	env->objects[env->selected_object].intensity =
	env->sectors[env->objects[env->selected_object].sector].intensity;
	return (0);
}

int			update_enemy_sector_input_box(void *penv)
{
	t_env	*env;

	env = (t_env*)penv;
	env->enemies[env->selected_enemy].sector = get_sector(env,
	env->enemies[env->selected_enemy].pos, 
	env->enemies[env->selected_enemy].sector);
	env->enemies[env->selected_enemy].brightness =
	env->sectors[env->enemies[env->selected_enemy].sector].brightness;
	env->enemies[env->selected_enemy].light_color =
	env->sectors[env->enemies[env->selected_enemy].sector].light_color;
	env->enemies[env->selected_enemy].intensity =
	env->sectors[env->enemies[env->selected_enemy].sector].intensity;
	return (0);
}

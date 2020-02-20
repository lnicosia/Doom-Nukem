/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_box_updaters.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipatry <sipatry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 12:05:50 by lnicosia          #+#    #+#             */
/*   Updated: 2020/02/20 10:38:03 by lnicosia         ###   ########.fr       */
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
		update_sector_entities_z(env, env->selected_floor);
	}
	else if (env->editor.selected_sector != -1)
	{
		update_sector_slope(env, &env->sectors[env->editor.selected_sector]);
		update_sector_entities_z(env, env->editor.selected_sector);
	}
	else if (env->selected_ceiling != -1)
		update_sector_slope(env, &env->sectors[env->selected_ceiling]);
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

int			update_sector_entities_light_input_box(void *penv)
{
	t_env	*env;

	env = (t_env*)penv;
	if (env->editor.selected_sector != -1)
		update_sector_entities_light(env, env->editor.selected_sector);
	else if (env->selected_ceiling != -1)
		update_sector_entities_light(env, env->selected_ceiling);
	else if (env->selected_floor != -1)
		update_sector_entities_light(env, env->selected_floor);
	else
		return (0);
	return (0);
}

int			update_object_input_box(void *penv)
{
	t_env	*env;

	env = (t_env*)penv;
	update_object_light(env, env->selected_object);
	return (0);
}

int			update_enemy_input_box(void *penv)
{
	t_env	*env;

	env = (t_env*)penv;
	update_enemy(env, env->selected_enemy);
	return (0);
}

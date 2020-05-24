/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   three_d_edit_slopes.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipatry <sipatry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 17:41:53 by sipatry           #+#    #+#             */
/*   Updated: 2020/02/20 18:33:20 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

int		increase_slope(t_env *env)
{
	if (env->selected_ceiling != -1)
	{
		env->sectors[env->selected_ceiling].ceiling_slope +=
		(0.5 * (env->editor.key_delay / 500));
		update_sector_slope(env, &env->sectors[env->selected_ceiling]);
		check_height_protections(env, &env->sectors[env->selected_ceiling]);
		update_sector_slope(env, &env->sectors[env->selected_ceiling]);
	}
	if (env->selected_floor != -1)
	{
		env->sectors[env->selected_floor].floor_slope +=
		(0.5 * (env->editor.key_delay / 500));
		update_sector_slope(env, &env->sectors[env->selected_floor]);
		check_height_protections(env, &env->sectors[env->selected_floor]);
		update_sector_slope(env, &env->sectors[env->selected_floor]);
		update_sector_entities_z(env, env->selected_floor);
	}
	return (0);
}

int		decrease_slope(t_env *env)
{
	if (env->selected_ceiling != -1)
	{
		env->sectors[env->selected_ceiling].ceiling_slope -=
		(0.5 * (env->editor.key_delay / 500));
		update_sector_slope(env, &env->sectors[env->selected_ceiling]);
		check_height_protections(env, &env->sectors[env->selected_ceiling]);
		update_sector_slope(env, &env->sectors[env->selected_ceiling]);
	}
	if (env->selected_floor != -1)
	{
		env->sectors[env->selected_floor].floor_slope -=
		(0.5 * (env->editor.key_delay / 500));
		update_sector_slope(env, &env->sectors[env->selected_floor]);
		check_height_protections(env, &env->sectors[env->selected_floor]);
		update_sector_slope(env, &env->sectors[env->selected_floor]);
		update_sector_entities_z(env, env->selected_floor);
	}
	return (0);
}

int		increase_slope_keyup(t_env *env)
{
	if (env->selected_ceiling != -1)
	{
		env->sectors[env->selected_ceiling].ceiling_slope += 1;
		update_sector_slope(env, &env->sectors[env->selected_ceiling]);
		check_height_protections(env, &env->sectors[env->selected_ceiling]);
		update_sector_slope(env, &env->sectors[env->selected_ceiling]);
	}
	if (env->selected_floor != -1)
	{
		env->sectors[env->selected_floor].floor_slope += 1;
		update_sector_slope(env, &env->sectors[env->selected_floor]);
		check_height_protections(env, &env->sectors[env->selected_floor]);
		update_sector_slope(env, &env->sectors[env->selected_floor]);
		update_sector_entities_z(env, env->selected_floor);
	}
	return (0);
}

int		decrease_slope_keyup(t_env *env)
{
	if (env->selected_ceiling != -1)
	{
		env->sectors[env->selected_ceiling].ceiling_slope -= 1;
		update_sector_slope(env, &env->sectors[env->selected_ceiling]);
		check_height_protections(env, &env->sectors[env->selected_ceiling]);
		update_sector_slope(env, &env->sectors[env->selected_ceiling]);
	}
	if (env->selected_floor != -1)
	{
		env->sectors[env->selected_floor].floor_slope -= 1;
		update_sector_slope(env, &env->sectors[env->selected_floor]);
		check_height_protections(env, &env->sectors[env->selected_floor]);
		update_sector_slope(env, &env->sectors[env->selected_floor]);
		update_sector_entities_z(env, env->selected_floor);
	}
	return (0);
}

int		change_slopes_keyup(t_env *env)
{
	if (env->editor.key_delay > INPUT_DELAY
	|| env->editor.keyup_allowed)
	{
		if (env->inputs.plus
		|| env->sdl.event.key.keysym.sym == SDLK_KP_PLUS)
		{
			if (increase_slope_keyup(env))
				return (-1);
		}
		else if (env->inputs.minus
		|| env->sdl.event.key.keysym.sym == SDLK_KP_MINUS)
		{
			if (decrease_slope_keyup(env))
				return (-1);
		}
	}
	return (0);
}

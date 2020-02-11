/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3d_edit_function.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipatry <sipatry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 17:25:50 by sipatry           #+#    #+#             */
/*   Updated: 2020/02/11 18:44:04 by sipatry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

int		increse_wall_texture_scale(t_env *env)
{
	if (env->selected_floor)
		increase_floor_texture_scale(env);
	if (env->selected_ceiling)
		increase_ceiling_texture_scale(env);
	if (env->editor.selected_wall)
		increase_floor_texture_scale(env);
}

int		reduce_wall_texture_scale(t_env *env)
{
	if (env->selected_floor)
		reduce_floor_texture_scale(env);
	if (env->selected_ceiling)
		reduce_ceiling_texture_scale(env);
	if (env->editor.selected_wall)
		reduce_floor_texture_scale(env);
}

int		change_ceiling_floor_height(t_env *env)
{
	if (env->selected_ceiling != -1)
	{
		if (env->inputs.plus
		&& env->sectors[env->selected_ceiling].ceiling
		> env->sectors[env->selected_ceiling].floor + 1)
			env->sectors[env->selected_ceiling].ceiling += 0.1;
		if (env->inputs.minus
		&& env->sectors[env->selected_ceiling].ceiling)
			env->sectors[env->selected_ceiling].ceiling -= 0.1;
		update_sector_slope(env, &env->sectors[env->selected_ceiling]);
	}
	else if (env->selected_floor != 1)
	{
		if (env->inputs.plus
		&& env->sectors[env->selected_floor].floor
		< env->sectors[env->selected_floor].ceiling - 1)
			env->sectors[env->selected_floor].floor += 0.1;
		else if (env->inputs.minus)
			env->sectors[env->selected_floor].floor -= 0.1;
		update_sector_slope(env, &env->sectors[env->selected_floor]);
		update_sector_entities_z(env, env->selected_floor);
	}
}
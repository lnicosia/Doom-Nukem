/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3d_edit_function.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipatry <sipatry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 17:25:50 by sipatry           #+#    #+#             */
/*   Updated: 2020/02/12 18:35:24 by sipatry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

int		increase_walls_texture_scale(t_env *env)
{
	if (env->selected_floor != -1)
	{
		if (increase_floor_texture_scale(env))
			return (-1);
	}
	if (env->selected_ceiling != -1)
	{
		if (increase_ceiling_texture_scale(env))
			return (-1);
	}
	if (env->editor.selected_wall != -1)
	{
		if (increase_wall_texture_scale(env))
			return (-1);
	}
	return (0);
}

int		reduce_walls_texture_scale(t_env *env)
{
	if (env->selected_floor != -1)
	{
		if (reduce_floor_texture_scale(env))
			return (-1);
	}
	if (env->selected_ceiling != -1)
	{
		if (reduce_ceiling_texture_scale(env))
			return (-1);
	}
	if (env->editor.selected_wall != -1)
	{
		if (reduce_wall_texture_scale(env))
			return (-1);
	}
	return (0);
}



void	change_ceiling_floor_height(t_env *env)
{
	if (env->selected_ceiling != -1)
	{
		if ((env->inputs.plus && !env->inputs.ctrl) && height_check(env))
			env->sectors[env->selected_ceiling].ceiling += 0.1;
		if ((env->inputs.minus && !env->inputs.ctrl)
		&& env->sectors[env->selected_ceiling].ceiling
		> env->sectors[env->selected_ceiling].floor + 1
		&& (check_entities_height(env)))
			env->sectors[env->selected_ceiling].ceiling -= 0.1;
		update_sector_slope(env, &env->sectors[env->selected_ceiling]);
	}
	else if (env->selected_floor != -1)
	{
		if ((env->inputs.plus && !env->inputs.ctrl)
		&& env->sectors[env->selected_floor].floor
		< env->sectors[env->selected_floor].ceiling - 1
		&& (check_entities_height(env)))
			env->sectors[env->selected_floor].floor += 0.1;
		else if ((env->inputs.minus && !env->inputs.ctrl) && height_check(env))
			env->sectors[env->selected_floor].floor -= 0.1;
		update_sector_slope(env, &env->sectors[env->selected_floor]);
		update_sector_entities_z(env, env->selected_floor);
	}
}
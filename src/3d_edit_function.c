/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3d_edit_function.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipatry <sipatry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 17:25:50 by sipatry           #+#    #+#             */
/*   Updated: 2020/02/18 12:32:26 by sipatry          ###   ########.fr       */
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

void	update_height(t_env *env, t_sector *sector)
{
	if (env->editor.keyup_allowed && env->selected_ceiling != -1)
		sector->ceiling -= 0.1;
	else if (env->editor.key_delay > INPUT_DELAY && env->selected_ceiling != -1)
		sector->ceiling -= (0.1 * (env->editor.key_delay / 500));
	if (env->editor.keyup_allowed && env->selected_floor != -1)
		sector->floor -= 0.1;
	else if (env->editor.key_delay > INPUT_DELAY && env->selected_floor != -1)
		sector->floor -= (0.1 * (env->editor.key_delay / 500));
}

void	update_height_for_entities(t_env *env, t_sector *sector)
{
	if (env->selected_ceiling != -1 && !env->inputs.ctrl
	&& env->editor.key_delay > INPUT_DELAY)
		sector->ceiling += (0.1 * (env->editor.key_delay / 500));
	else if (env->selected_ceiling != -1 && !env->inputs.ctrl
	&& env->editor.keyup_allowed)
		sector->ceiling += 0.1;
	if (env->selected_floor != -1 && !env->inputs.ctrl
	&& env->editor.key_delay > INPUT_DELAY)
		sector->floor -= (0.1 * (env->editor.key_delay / 500));
	else if (env->selected_floor != -1 && !env->inputs.ctrl
	&& env->editor.keyup_allowed && env->editor.key_delay < INPUT_DELAY)
		sector->floor -= 0.1;
	if (env->selected_ceiling != -1 && env->inputs.ctrl
	&& env->editor.keyup_allowed && env->editor.key_delay < INPUT_DELAY)
		sector->ceiling_slope += 0.01;
	else if (env->selected_ceiling != -1 && env->inputs.ctrl
	&& env->editor.key_delay > INPUT_DELAY)
		sector->ceiling_slope += (0.01 * (env->editor.key_delay / 500));
	if (env->selected_floor != -1 && env->inputs.ctrl
	&& env->editor.key_delay > INPUT_DELAY)
		sector->floor_slope -= (0.01 * (env->editor.key_delay / 500));
	else if (env->selected_floor != -1 && env->inputs.ctrl
	&& env->editor.keyup_allowed && env->editor.key_delay < INPUT_DELAY)
		sector->floor_slope -= 0.01;
}

void	check_height_protections(t_env * env, t_sector *sector)
{
	if (env->editor.key_delay > INPUT_DELAY
	|| env->editor.keyup_allowed)
	{
		if (height_check(env))
			update_height(env, sector);
		if (check_entities_height(env))
			update_height_for_entities(env, sector);
	}
}

void	change_ceiling_floor_height(t_env *env)
{
	t_sector	*sector;

	sector = NULL;
	if (env->editor.key_delay > INPUT_DELAY)
	{
		if (env->selected_ceiling != -1)
		{
			sector = &env->sectors[env->selected_ceiling];
			if (env->inputs.plus && !env->inputs.ctrl)
				env->sectors[env->selected_ceiling].ceiling += (0.1 * (env->editor.key_delay / 500));
			if (env->inputs.minus && !env->inputs.ctrl)
				env->sectors[env->selected_ceiling].ceiling -= (0.1 * (env->editor.key_delay / 500));
			check_height_protections(env, sector);
			update_sector_slope(env, sector);	
		}
		else if (env->selected_floor != -1)
		{
			sector = &env->sectors[env->selected_floor];
			if (env->inputs.plus && !env->inputs.ctrl)
				env->sectors[env->selected_floor].floor += 0.1 * (env->editor.key_delay / 500);
			else if (env->inputs.minus && !env->inputs.ctrl)
				env->sectors[env->selected_floor].floor -= 0.1 * (env->editor.key_delay / 500);
			check_height_protections(env, sector);
			update_sector_slope(env, sector);	
		}
	}
}
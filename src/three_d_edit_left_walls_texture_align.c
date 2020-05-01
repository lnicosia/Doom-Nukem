/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   three_d_edit_left_walls_texture_align.c            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/01 11:30:53 by lnicosia          #+#    #+#             */
/*   Updated: 2020/05/01 11:32:27 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

int		left_ceiling_texture_alignement(t_env *env)
{
	if (env->inputs.shift && !env->inputs.ctrl
		&& env->sectors[env->selected_ceiling].ceiling_map_align.y > -1000
		&& env->sectors[env->selected_ceiling].ceiling_map_align.x > -1000)
	{
		env->sectors[env->selected_ceiling].ceiling_map_align.y -= 1;
		env->sectors[env->selected_ceiling].ceiling_map_align.x -= 1;
	}
	else if (env->inputs.ctrl
		&& env->sectors[env->selected_ceiling].ceiling_map_align.y > -1000)
		env->sectors[env->selected_ceiling].ceiling_map_align.y -= 1;
	else if (env->sectors[env->selected_ceiling].ceiling_map_align.x > -1000)
		env->sectors[env->selected_ceiling].ceiling_map_align.x -= 1;
	if (set_sector_ceiling_map_array(&env->sectors[env->selected_ceiling],
	&env->wall_textures[env->sectors[env->selected_ceiling].ceiling_texture],
	env))
		return (-1);
	return (0);
}

int		left_floor_texture_alignement(t_env *env)
{
	if (env->inputs.shift && !env->inputs.ctrl
		&& env->sectors[env->selected_floor].floor_map_align.y > -1000
		&& env->sectors[env->selected_floor].floor_map_align.x > -1000)
	{
		env->sectors[env->selected_floor].floor_map_align.y -= 1;
		env->sectors[env->selected_floor].floor_map_align.x -= 1;
	}
	else if (env->inputs.ctrl
	&& env->sectors[env->selected_floor].floor_map_align.y > -1000)
		env->sectors[env->selected_floor].floor_map_align.y -= 1;
	else if (env->sectors[env->selected_floor].floor_map_align.x > -1000)
		env->sectors[env->selected_floor].floor_map_align.x -= 1;
	if (set_sector_floor_map_array(&env->sectors[env->selected_floor],
	&env->wall_textures[env->sectors[env->selected_floor].floor_texture],
	env))
		return (-1);
	return (0);
}

void	left_wall_texture_alignement(t_env *env)
{
	if (env->inputs.shift && !env->inputs.ctrl
	&& env->sectors[env->editor.selected_sector].
	align[env->editor.selected_wall].y > -1000
	&& env->sectors[env->editor.selected_sector].
	align[env->editor.selected_wall].x > -1000)
	{
		env->sectors[env->editor.selected_sector].
		align[env->editor.selected_wall].y -= 1;
		env->sectors[env->editor.selected_sector].
		align[env->editor.selected_wall].x -= 1;
	}
	else if (env->inputs.ctrl
		&& env->sectors[env->editor.selected_sector].
		align[env->editor.selected_wall].y > -1000)
		env->sectors[env->editor.selected_sector].
		align[env->editor.selected_wall].y -= 1;
	else if (env->sectors[env->editor.selected_sector].
		align[env->editor.selected_wall].x > -1000)
		env->sectors[env->editor.selected_sector].
		align[env->editor.selected_wall].x -= 1;
}

int		left_walls_texture_align(t_env *env)
{
	if (env->selected_ceiling != -1)
	{
		if (left_ceiling_texture_alignement(env))
			return (-1);
	}
	if (env->selected_floor != -1)
	{
		if (left_floor_texture_alignement(env))
			return (-1);
	}
	if (env->editor.selected_wall != -1)
		left_wall_texture_alignement(env);
	return (0);
}

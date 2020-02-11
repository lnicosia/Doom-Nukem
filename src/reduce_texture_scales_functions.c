/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reduce_texture_scales_functions.c                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipatry <sipatry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 18:30:35 by sipatry           #+#    #+#             */
/*   Updated: 2020/02/11 18:30:49 by sipatry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

int		reduce_ceiling_texture_scale(t_env *env)
{
	t_sector *sector;

	sector = &env->sectors[env->selected_ceiling];
	if (env->inputs.shift && !env->inputs.ctrl
	&& sector->scale[env->selected_ceiling].y > 1
	&& sector->scale[env->selected_ceiling].x > 1)
	{
		sector->scale[env->selected_ceiling].y /= 1.1;
		sector->scale[env->selected_ceiling].x /= 1.1;
	}
	else if (env->inputs.ctrl
	&& sector->scale[env->selected_ceiling].y >1)
		sector->scale[env->selected_ceiling].y /= 1.1;
	else if (sector->scale[env->selected_ceiling].x > 1)
		sector->scale[env->selected_ceiling].x /= 1.1;
	if (set_sector_ceiling_map_array(&env->sectors[env->selected_ceiling],
	env->wall_textures[sector->textures[env->selected_ceiling]],
	env->selected_ceiling, env))
		return (-1);
	return (0);
}

int		reduce_floor_texture_scale(t_env *env)
{
	t_sector *sector;

	sector = &env->sectors[env->selected_floor];
	if (env->inputs.shift && !env->inputs.ctrl
	&& sector->scale[env->selected_floor].y > 1
	&& sector->scale[env->selected_floor].x > 1)
	{
		sector->scale[env->selected_floor].y /= 1.1;
		sector->scale[env->selected_floor].x /= 1.1;
	}
	else if (env->inputs.ctrl
	&& sector->scale[env->selected_floor].y >1)
		sector->scale[env->selected_floor].y /= 1.1;
	else if (sector->scale[env->selected_floor].x > 1)
		sector->scale[env->selected_floor].x /= 1.1;
	if (set_sector_floor_map_array(&env->sectors[env->selected_floor],
	env->wall_textures[sector->textures[env->selected_floor]],
	env->selected_floor, env))
		return (-1);
	return (0);
}

int		reduce_wall_texture_scale(t_env *env)
{
	t_sector *sector;

	sector = &env->sectors[env->editor.selected_sector];
	if (env->inputs.shift && !env->inputs.ctrl
	&& sector->scale[env->editor.selected_wall].y > 1
	&& sector->scale[env->editor.selected_wall].x > 1)
	{
		sector->scale[env->editor.selected_wall].y /= 1.1;
		sector->scale[env->editor.selected_wall].x /= 1.1;
	}
	else if (env->inputs.ctrl
	&& sector->scale[env->editor.selected_wall].y >1)
		sector->scale[env->editor.selected_wall].y /= 1.1;
	else if (sector->scale[env->editor.selected_wall].x > 1)
		sector->scale[env->editor.selected_wall].x /= 1.1;
	if (set_sector_wall_map_array(&env->sectors[env->editor.selected_sector],
	env->wall_textures[sector->textures[env->editor.selected_wall]],
	env->editor.selected_wall, env))
		return (-1);
	if (set_camera_map_array(&env->player.camera,
	env->editor.selected_sector, env->editor.selected_wall, env))
		return (-1);
	return (0);
}
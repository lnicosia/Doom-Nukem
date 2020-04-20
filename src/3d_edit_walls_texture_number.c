/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3d_edit_walls_texture_number.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipatry <sipatry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 15:36:18 by sipatry           #+#    #+#             */
/*   Updated: 2020/02/17 17:02:26 by sipatry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

int		texture_protections2(t_env *env, t_sector *sector)
{
	if (env->selected_floor != -1)
	{
		if (set_sector_floor_map_array(&env->sectors[env->selected_floor],
		&env->wall_textures[env->sectors[env->selected_floor].
		floor_texture], env))
			return (-1);
		if (sector->floor_texture < 0)
			env->contains_skybox = 1;
	}
	return (0);
}

int		texture_protections(t_env *env, t_sector *sector)
{
	if (env->editor.selected_wall != -1)
	{
		if (set_sector_wall_map_array(sector,
		&env->wall_textures[sector->textures[env->editor.selected_wall]],
		env->editor.selected_wall, env))
			return (-1);
		if (set_camera_map_array(&env->player.camera,
		env->editor.selected_sector, env->editor.selected_wall, env))
			return (-1);
		if (sector->textures[env->editor.selected_wall] < 0)
			env->contains_skybox = 1;
	}
	if (env->selected_ceiling != -1)
	{
		if (set_sector_ceiling_map_array(&env->sectors[env->selected_ceiling],
		&env->wall_textures[env->sectors[env->selected_ceiling].
		ceiling_texture], env))
			return (-1);
		if (env->sectors[env->selected_ceiling].ceiling_texture < 0)
			env->contains_skybox = 1;
	}
	return (texture_protections2(env, sector));
}

int		increase_wall_texture_number(t_env *env, t_sector *sector)
{
	if (env->editor.selected_wall != -1)
	{
		if (env->inputs.shift && sector->textures[env->editor.selected_wall]
		< MAX_WALL_TEXTURE - 10)
			sector->textures[env->editor.selected_wall] += 10;
		else if (sector->textures[env->editor.selected_wall]
		< MAX_WALL_TEXTURE - 1)
			sector->textures[env->editor.selected_wall]++;
	}
	if (env->selected_ceiling != -1)
	{
		if (env->inputs.shift && sector->ceiling_texture > 9 - MAX_SKYBOX)
			sector->ceiling_texture += 10;
		else if (sector->ceiling_texture > -MAX_SKYBOX)
			sector->ceiling_texture++;
	}
	if (env->selected_floor != -1)
	{
		if (env->inputs.shift && sector->floor_texture < MAX_WALL_TEXTURE - 10)
			sector->floor_texture += 10;
		else if (sector->floor_texture < MAX_WALL_TEXTURE - 1)
			sector->floor_texture++;
	}
	return (texture_protections(env, sector));
}

int		decrease_wall_texture_number2(t_env *env, t_sector *sector)
{
	if (env->selected_floor != -1)
	{
		if (env->inputs.shift
		&& env->sectors[env->selected_floor].floor_texture > 9 - MAX_SKYBOX)
			env->sectors[env->selected_floor].floor_texture -= 10;
		else if (env->sectors[env->selected_floor].floor_texture > -MAX_SKYBOX)
			env->sectors[env->selected_floor].floor_texture--;
	}
	return (texture_protections(env, sector));
}

int		decrease_wall_texture_number(t_env *env, t_sector *sector)
{
	if (env->editor.selected_wall != -1)
	{
		if (env->inputs.shift && sector->textures[env->editor.
			selected_wall] > 8)
			sector->textures[env->editor.selected_wall] -= 10;
		else if (sector->textures[env->editor.selected_wall] > -MAX_SKYBOX)
			sector->textures[env->editor.selected_wall] -= 1;
	}
	if (env->selected_ceiling != -1)
	{
		if (env->inputs.shift
			&& env->sectors[env->selected_ceiling].
			ceiling_texture < MAX_WALL_TEXTURE - 10)
			env->sectors[env->selected_ceiling].ceiling_texture -= 10;
		else if (env->sectors[env->selected_ceiling].
		  	ceiling_texture < MAX_WALL_TEXTURE - 1)
			env->sectors[env->selected_ceiling].ceiling_texture--;
	}
	return (decrease_wall_texture_number2(env, sector));
}

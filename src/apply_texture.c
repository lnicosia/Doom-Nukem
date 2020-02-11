/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_texture.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 09:29:46 by lnicosia          #+#    #+#             */
/*   Updated: 2019/11/26 14:32:31 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

int		apply_texture(t_sector *sector, t_env *env, int i)
{
	if (env->editor.selected_wall != -1)
	{
		sector->textures[i] = env->editor.current_texture;
		if (set_sector_wall_map_array(sector,
		env->wall_textures[sector->textures[i]], i, env)
		|| (env->editor.in_game && set_camera_map_array(&env->player.camera,
		sector->num, i, env)))
			return (-1);
	}
	else if (env->selected_floor != -1)
	{
		sector->floor_texture = env->editor.current_texture;
		if (set_sector_floor_map_array(sector,
		env->wall_textures[sector->floor_texture], env))
			return (-1);
	}
	else if (env->selected_ceiling != -1)
	{
		sector->ceiling_texture = env->editor.current_texture;
		if (set_sector_ceiling_map_array(sector,
		env->wall_textures[sector->ceiling_texture], env))
			return (-1);
	}
	return (0);
}

int		change_target_texture(t_env *env)
{
	int	i;
	i = 0;
	if (env->editor.selected_wall != -1)
		{
			i = env->editor.selected_wall;
			if (apply_texture(
			&env->sectors[env->editor.selected_sector], env, i))
				return (-1);
		}
		if (env->selected_ceiling != -1)
		{
			i = env->selected_ceiling;
			if (apply_texture(&env->sectors[env->selected_ceiling], env, i))
				return (-1);
		}
		if (env->selected_floor != -1)
		{
			i = env->selected_floor;
			if (apply_texture(&env->sectors[env->selected_floor], env, i))
				return (-1);
		}
	return (0);
}
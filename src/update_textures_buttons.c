/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_textures_buttons.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipatry <sipatry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 10:53:12 by sipatry           #+#    #+#             */
/*   Updated: 2020/02/03 11:08:48 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

int		update_wall_texture_button(void *penv)
{
	t_env	*env;
	env = (t_env*)penv;
	if (env->sectors[env->editor.selected_sector].
		textures[env->editor.selected_wall] < 0)
		env->contains_skybox = 1;
	if (set_sector_wall_map_array(&env->sectors[env->editor.selected_sector],
		env->wall_textures[env->sectors[env->editor.selected_sector].
		textures[env->editor.selected_wall]], env->editor.selected_wall, env))
		return (-1);
	if (set_camera_map_array(&env->player.camera, env->editor.selected_sector,
		env->editor.selected_wall, env))
		return (-1);
	return (0);
} 

int			update_ceiling_texture_button(void *penv)
{
	t_env	*env;
	env = (t_env*)penv;
	ft_printf("updating ceiling %d texture\n", env->selected_ceiling);
	if (env->sectors[env->selected_ceiling].ceiling_texture < 0)
		env->contains_skybox = 1;
	if (set_sector_ceiling_map_array(&env->sectors[env->selected_ceiling],
		env->wall_textures[env->sectors[env->selected_ceiling].
		ceiling_texture], env))
		return (-1);
	return (0);
}

int			update_floor_texture_button(void *penv)
{
	t_env	*env;
	env = (t_env*)penv;
	if (env->sectors[env->selected_floor].floor_texture < 0)
		env->contains_skybox = 1;
	if (set_sector_floor_map_array(&env->sectors[env->selected_floor],
		env->wall_textures[env->sectors[env->selected_floor].
		floor_texture], env))
		return (-1);
	return (0);
}

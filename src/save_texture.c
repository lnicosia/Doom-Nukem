/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/01 10:43:48 by lnicosia          #+#    #+#             */
/*   Updated: 2020/05/01 10:43:49 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

int		save_texture3(int i, t_env *env)
{
	if (env->editor.in_game)
	{
		if (env->selected_floor != -1)
		{
			env->sectors[env->selected_floor].floor_texture = i;
			if (update_floor_texture_button(env))
				return (-1);
		}
		else if (env->selected_ceiling != -1)
		{
			env->sectors[env->selected_ceiling].ceiling_texture = i;
			if (update_ceiling_texture_button(env))
				return (-1);
		}
		else if (env->editor.selected_wall != -1)
		{
			env->sectors[env->editor.selected_sector].
			textures[env->editor.selected_wall] = i;
			if (update_wall_texture_button(env))
				return (-1);
		}
	}
	return (0);
}

void	save_texture2(int i, t_env *env)
{
	if (i < 0)
	{
		env->contains_skybox = 1;
		env->editor.current_texture = i;
		env->editor.current_texture_selection.img_down =
		env->mini_skyboxes[MAX_SKYBOX + (-i - 1)].surface;
		env->editor.current_texture_selection.img_pressed =
		env->mini_skyboxes[MAX_SKYBOX + (-i - 1)].surface;
		env->editor.current_texture_selection.img_hover =
		env->mini_skyboxes[MAX_SKYBOX + (-i - 1)].surface;
		env->editor.current_texture_selection.img_up =
		env->mini_skyboxes[MAX_SKYBOX + (-i - 1)].surface;
	}
}

int		save_texture(void *param)
{
	t_env	*env;
	int		i;

	env = ((t_button_param*)param)->env;
	i = ((t_button_param*)param)->i;
	env->editor.current_texture = i;
	if (i >= 0)
	{
		env->editor.current_texture_selection.img_down =
		env->wall_textures[i].maps[7];
		env->editor.current_texture_selection.img_pressed =
		env->wall_textures[i].maps[7];
		env->editor.current_texture_selection.img_hover =
		env->wall_textures[i].maps[7];
		env->editor.current_texture_selection.img_up =
		env->wall_textures[i].maps[7];
	}
	save_texture2(i, env);
	if (save_texture3(i, env))
		return (-1);
	env->editor.current_texture_selection.state = UP;
	env->editor.current_texture_selection.anim_state = REST;
	env->editor.draw_texture_tab = 0;
	env->editor.click_locked = 1;
	return (0);
}

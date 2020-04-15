/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   editor_3d_keys.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipatry <sipatry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/01 12:18:01 by lnicosia          #+#    #+#             */
/*   Updated: 2020/03/11 19:13:08 by sipatry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

int		change_textures_scales(t_env *env)
{
	if (env->editor.key_delay > INPUT_DELAY
	&& env->editor.selected_wall_sprite == -1
	&& env->selected_floor_sprite == -1
	&& env->selected_ceiling_sprite == -1)
	{
		if ((env->inputs.minus1)
		&& (env->editor.selected_wall != -1 || env->selected_floor != -1
		|| env->selected_ceiling != -1))
		{
			if (reduce_walls_texture_scale(env))
				return (-1);
		}
		if ((env->inputs.equals)
		&& (env->editor.selected_wall != -1 || env->selected_floor != -1
		|| env->selected_ceiling != -1))
		{
			if (increase_walls_texture_scale(env))
				return (-1);
		}
	}
	return (0);
}

int		save_map_3d_keys(t_env *env)
{
  	int	ret;

	if ((ret = valid_map(env)))
	  	return (ret);
	if (env->editor.creating_event)
	{
		if (update_confirmation_box(&env->confirmation_box,
			"Please save your event before saving the map", ERROR, env))
		return (-1);
	}
	else
	{
		SDL_SetRelativeMouseMode(0);
		SDL_GetRelativeMouseState(&env->sdl.mouse_x, &env->sdl.mouse_y);
		if (new_input_box(&env->input_box, new_point(env->h_w, env->h_h),
				STRING, &env->save_file))
			return (-1);
		env->input_box.text_size = 50;
		env->input_box.update = &save_map;
		env->inputs.s = 0;
		env->inputs.ctrl = 0;
	}
	return (1);
}

int		editor_3d_keys3(t_env *env)
{
	if (env->inputs.minus && !env->inputs.shift
	&& env->options.minimap_scale / 1.2 > 1)
		env->options.minimap_scale /= 1.2;
	if (env->inputs.h)
	{
		env->editor.options_from_h = 1;
		env->editor.tab = 1;
		env->options.editor_options = 1;
	}
	return (0);
}

int		editor_3d_keys2(t_env *env)
{
	int		ret;

	if (env->inputs.s && env->inputs.ctrl)
	{
	  	if ((ret = save_map_3d_keys(env)) != 1)
		  	return (ret);
	}
	if ((env->editor.selecting_weapon || env->editor.selecting_condition_weapon)
		&& !env->confirmation_box.state)
	{
		if (weapon_picker_keys(env))
			return (-1);
	}
	if (env->confirmation_box.state)
	{
		if (confirmation_box_keys(&env->confirmation_box, env))
			return (-1);
	}
	if (env->inputs.plus && !env->inputs.shift
	&& env->options.minimap_scale * 1.2 < 100)
		env->options.minimap_scale *= 1.2;
	return (editor_3d_keys3(env));
}

int		editor_3d_keys(t_env *env)
{
	if (env->editor.tab)
	{
		if (!env->options.editor_options)
		{
			if (editor_3d_tab_keys(env))
				return (-1);
		}
		else
			if (editor_options_keys(env))
				return (-1);
	}
	if (wall_edit_keys(env))
		return (-1);
	if (check_move_player_conditions(env))
	{
		if (move_player(env))
			return (-1);
	}
	if (env->editor.in_game && env->inputs.right_click)
	{
		reset_selection(env);
		tabs_gestion(env);
	}
	return (editor_3d_keys2(env));
}

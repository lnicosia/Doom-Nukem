/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   editor_3d_keys.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipatry <sipatry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/01 12:18:01 by lnicosia          #+#    #+#             */
/*   Updated: 2020/02/25 15:39:47 by lnicosia         ###   ########.fr       */
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

int		check_move_player_conditions(t_env *env)
{
	if ((((env->inputs.forward || env->inputs.backward || env->inputs.left
		|| env->inputs.right || env->inputs.space || env->jump.on_going == 1
		|| env->crouch.on_going || env->inputs.lgui)
		&& env->player.health > 0 && !env->inputs.ctrl
		&&  (((env->selected_enemy == -1 && env->editor.tab)
		|| (env->selected_enemy != -1 && !env->editor.tab))
		|| (env->selected_enemy == -1 && !env->editor.tab)))
		|| (env->player.state.climb || env->player.state.drop))
		&& !env->editor.tab)
		return (1);
	return (0);
}

int		editor_3d_keys(t_env *env)
{
	int		ret;

	if (env->editor.tab)
	{
		if (editor_3d_tab_keys(env))
			return (-1);
	}
	if (wall_edit_keys(env))
		return (-1);
	if (check_move_player_conditions(env))
		move_player(env);
	if (env->editor.in_game && env->inputs.right_click)
	{
		reset_selection(env);
		tabs_gestion(env);
	}
	if (env->inputs.s && env->inputs.ctrl)
	{
		ret = valid_map(env);
		if (ret == -1)
			return (-1);
		else if (ret)
			return (0);
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
			new_input_box(&env->input_box, new_point(env->h_w, env->h_h),
					STRING, &env->save_file);
			env->input_box.update = &save_map;
			env->inputs.s = 0;
			env->inputs.ctrl = 0;
		}
	}
	if (env->confirmation_box.state)
	{
		if (confirmation_box_keys(&env->confirmation_box, env))
			return (-1);
	}
/*	if (env->inputs.forward || env->inputs.backward || env->inputs.left
			|| env->inputs.right)
		play_sound(env, &env->sound.footstep_chan, env->sound.footstep,
			env->sound.ambient_vol);*/
	if (env->inputs.plus && !env->inputs.shift
	&& env->options.minimap_scale * 1.2 < 100)
		env->options.minimap_scale *= 1.2;
	if (env->inputs.minus && !env->inputs.shift
	&& env->options.minimap_scale / 1.2 > 1)
		env->options.minimap_scale /= 1.2;
	return (0);
}

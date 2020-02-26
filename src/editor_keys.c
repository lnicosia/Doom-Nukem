/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   editor_keys.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipatry <sipatry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/29 15:07:41 by lnicosia          #+#    #+#             */
/*   Updated: 2020/02/25 15:37:52 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

int			editor_keys(t_env *env)
{
	double	time;
	int		i;
	int		ret;

	i = 0;
	time = SDL_GetTicks();
	if (env->inputs.backspace && !env->confirmation_box.state)
	{
		if (del_last_vertex(env))
			return (-1);
		env->inputs.backspace = 0;
	}
	player_selection(env);
	starting_player_selection(env);
	enemy_selection(env);
	objects_selection(env);
	vertices_selection(env);
	if (env->confirmation_box.state)
	{
		if (confirmation_box_keys(&env->confirmation_box, env))
			return (-1);
	}
	if (env->inputs.right_click)
	{
		env->editor.center.x += env->sdl.mouse_x;
		env->editor.center.y += env->sdl.mouse_y;
	}

	/*
	**	Moving the map with arrows
	*/
	
	if (env->inputs.left && !env->editor.tab && !env->inputs.ctrl)
		env->editor.center.x -= 3;
	if (env->inputs.right && !env->editor.tab && !env->inputs.ctrl)
		env->editor.center.x += 3;
	if (env->inputs.forward && !env->editor.tab && !env->inputs.ctrl)
		env->editor.center.y -= 3;
	if (env->inputs.backward && !env->editor.tab && !env->inputs.ctrl)
		env->editor.center.y += 3;
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
			new_input_box(&env->input_box, new_point(env->h_w, env->h_h),
			STRING, &env->save_file);
			env->input_box.update = &save_map;
			env->inputs.s = 0;
			env->inputs.ctrl = 0;
		}
	}

	/*
	**	control of the selection the stats in 2D mode editor iwh include:
	**	floor | ceiling | brightness control on arrows or keybord usual binding (w-a-s-d)
	**	control of the sector status with +/-
	*/

	if (button_keys(&env->editor.add_enemy, env))
		return (-1);
	if (button_keys(&env->editor.add_object, env))
		return (-1);
	if (button_keys(&env->editor.save, env))
		return (-1);
	if (button_keys(&env->editor.general_tab, env))
		return (-1);
	if (button_keys(&env->editor.sprite_tab, env))
		return (-1);
	if (button_keys(&env->editor.sector_tab, env))
		return (-1);
	if (button_keys(&env->editor.change_mode, env))
		return (-1);
	if (button_keys(&env->editor.launch_game, env))
		return (-1);
	if (button_keys(&env->editor.current_enemy_selection, env))
		return (-1);
	if (button_keys(&env->editor.current_object_selection, env))
		return (-1);
	if (button_keys(&env->editor.texture_background, env))
		return (-1);
	if (button_keys(&env->editor.enemy_background, env))
		return (-1);
	if (env->editor.selected_sector != -1 && sector_buttons(env))
		return (-1);
	if (env->editor.selected_player != -1 && player_buttons(env))
		return (-1);
	if (env->selected_enemy != -1 && enemy_buttons(env))
		return (-1);
	if (env->selected_object != -1 && object_buttons(env))
		return (-1);
	if (button_keys(&env->editor.events_tab, env))
		return (-1);
	if (env->editor.events_tab.state == DOWN)
	{
		if (!env->editor.selecting_target && !env->editor.selecting_event
			&& !env->editor.selecting_condition_target
			&& button_keys(&env->editor.new_event, env))
			return (-1);
		if (is_modify_event_button_visible(env))
		{
			if (button_keys(&env->editor.modify_event, env))
				return (-1);
			if (button_keys(&env->editor.delete_event, env))
				return (-1);
		}
		if (are_event_selection_buttons_visible(env))
		{
			if (button_keys(&env->editor.next_event, env))
				return (-1);
			if (button_keys(&env->editor.previous_event, env))
				return (-1);
		}
		if (are_events_selection_buttons_visible(env))
		{
			if (button_keys(&env->editor.next_events, env)
				|| button_keys(&env->editor.previous_events, env))
				return (-1);
		}
	}
	if (env->editor.draw_texture_tab)
	{
		while (i < MAX_WALL_TEXTURE)
		{
			if (button_keys(&env->editor.textures[i], env))
				return (-1);
			i++;
		}
		i = 0;
		while (i < MAX_SKYBOX)
		{
			button_keys(&env->editor.skyboxes[i], env);
			i++;
		}
	}
	if (env->editor.draw_enemy_tab)
	{
		while (i < MAX_ENEMIES)
		{
			if (button_keys(&env->editor.enemy_tab[i], env))
				return (-1);
			i++;
		}
	}
	if (env->editor.draw_object_tab)
	{
		while (i < MAX_OBJECTS)
		{
			if (button_keys(&env->editor.object_tab[i], env))
				return (-1);
			i++;
		}
	}
	if (env->editor.creating_event && !env->confirmation_box.state)
	{
		if (event_panel_keys(env))
			return (-1);
	}
	if ((env->inputs.plus || env->inputs.minus) && !env->editor.in_game && env->editor.selected_sector != -1)
	{
		if (!env->time.tick4)
			env->time.tick4 = SDL_GetTicks();
		time = SDL_GetTicks();
	}
	return (0);
}

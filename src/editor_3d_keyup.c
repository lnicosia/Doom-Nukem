/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   editor_3d_keyup.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipatry <sipatry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 15:34:09 by lnicosia          #+#    #+#             */
/*   Updated: 2020/03/11 19:13:06 by sipatry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

int		editor_3d_keyup5(t_env *env)
{
	if (env->editor.selecting_condition_target && !env->confirmation_box.state
			&& env->sdl.event.key.keysym.sym == SDLK_BACKSPACE)
	{
		env->editor.selecting_condition_target = 0;
		env->editor.creating_event = 1;
		env->editor.creating_condition = 1;
	}
	if (env->editor.selecting_event && !env->confirmation_box.state
			&& env->sdl.event.key.keysym.sym == SDLK_BACKSPACE)
	{
		env->editor.selecting_event = 0;
		env->editor.creating_event = 1;
		env->editor.creating_condition = 1;
	}
	return (0);
}

int		editor_3d_keyup4(t_env *env)
{
	if (env->confirmation_box.state)
	{
		if (confirmation_box_keyup(&env->confirmation_box, env))
			return (-1);
	}
	if (env->editor.tab)
	{
		if (env->sdl.event.button.button == SDL_BUTTON_LEFT)
		{
			if (editor_left_click_up(env))
				return (-1);
		}
		if (editor_3d_tabs_keyup(env))
			return (-1);		
		if (selection_tabs_keyup(env))
			return (-1);
	}
	if (env->editor.selecting_target && !env->confirmation_box.state
			&& env->sdl.event.key.keysym.sym == SDLK_BACKSPACE)
	{
		env->editor.selecting_target = 0;
		env->editor.creating_event = 1;
	}
	return (editor_3d_keyup5(env));
}

int		editor_3d_keyup3(t_env *env)
{
	if (env->editor.in_game && env->sdl.event.button.button == SDL_BUTTON_LEFT
			&& (env->sdl.mx > 400 || !env->editor.tab)
			&& !env->confirmation_box.state
			&& !is_mouse_on_any_selection_tab(env)
			&& ((!env->editor.creating_event && !env->editor.creating_condition)
				|| !is_mouse_on_event_panel(env)))
	{
		if (env->inputs.ctrl)
			env->editor.select_portal = 1;
		else	
			env->editor.select = 1;
	}
	if (env->editor.creating_event && !env->confirmation_box.state
			&& env->editor.tab)
	{
		if (event_panel_keyup(env))
			return (-1);
	}
	if ((env->editor.selecting_weapon || env->editor.selecting_condition_weapon)
		&& !env->confirmation_box.state)
	{
		if (weapon_picker_keyup(env))
			return (-1);
	}
	return (editor_3d_keyup4(env));
}

int		editor_3d_keyup2(t_env *env)
{
	if (env->sdl.event.key.keysym.sym == SDLK_f)
	{
		if (env->player.state.fly == 0)
			env->player.state.fly = 1;
		else if (env->sectors[env->player.sector].gravity)
			env->player.state.fly = 0;
		env->player.pos.z += 0.01;
	}
	if (env->sdl.event.key.keysym.sym == env->keys.enter
			&& env->editor.enter_locked)
		env->editor.enter_locked = 0;
	if (env->sdl.event.key.keysym.sym == SDLK_g && env->inputs.ctrl)
	{
		if (launch_game(env))
			return (-1);
	}
	if (env->sdl.event.key.keysym.sym == SDLK_TAB)
		editor_show_tab(env);
	return (editor_3d_keyup3(env));
}

int		editor_3d_keyup(t_env *env)
{
	if (wall_edit_keyup(env))
		return (-1);
	if (env->sdl.event.key.keysym.sym == env->keys.enter
			&& !env->confirmation_box.state && !env->input_box.state
			&& !env->editor.enter_locked)
	{
		going_in_2D_mode(env);
		return (0);
	}
	if (env->sdl.event.key.keysym.sym == SDLK_DELETE
		&& (env->selected_enemy != -1 || env->selected_object != -1
		|| env->selected_wall_sprite_wall != -1))
		if (delete_action(env))
			return (-1);
	editor_options_tab_keyup(env);
	if (env->sdl.event.button.button == SDL_BUTTON_LEFT
			&& env->editor.event_panel_dragged)
		env->editor.event_panel_dragged = -1;
	return (editor_3d_keyup2(env));
}

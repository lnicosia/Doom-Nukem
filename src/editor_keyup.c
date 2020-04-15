/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   editor_keyup.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipatry <sipatry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 17:29:35 by lnicosia          #+#    #+#             */
/*   Updated: 2020/03/09 10:30:19 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

int	editor_keyup5(t_env *env)
{
	if ((env->editor.selecting_weapon || env->editor.selecting_condition_weapon)
		&& !env->confirmation_box.state)
	{
		if (weapon_picker_keyup(env))
			return (-1);
	}
	if (env->confirmation_box.state)
	{
		if (confirmation_box_keyup(&env->confirmation_box, env))
			return (-1);
	}
	if (env->sdl.event.button.button == SDL_BUTTON_RIGHT)
	{
		reset_selection(env);
		tabs_gestion(env);
	}
	if (button_keyup(&env->editor.add_enemy, env))
		return (-1);
	if (button_keyup(&env->editor.add_object, env))
		return (-1);
	if (button_keyup(&env->editor.save, env))
		return (-1);
	if (button_keyup(&env->editor.change_mode, env))
		return (-1);
	return (editor_keyup6(env));
}

int	editor_keyup4(t_env *env)
{
	if (env->inputs.ctrl && env->sdl.event.button.button == SDL_BUTTON_LEFT)
	{
		if ((is_mouse_on_a_wall(env)))
		{
			if (add_vertex_in_sector(env))
			{
				env->editor.add.v1 = -1;
				env->editor.add.v2 = -1;
				return (0);
			}
		}
	}
	if (select_sector(env))
		return (-1);
	if (env->editor.creating_event && !env->confirmation_box.state)
	{
		if (event_panel_keyup(env))
			return (-1);
	}
	if (env->sdl.event.button.button == SDL_BUTTON_LEFT)
	{
		if (editor_left_click_up(env))
			return (-1);
	}
	return (editor_keyup5(env));
}

int	editor_keyup3(t_env *env)
{
	int	ret;

	if (env->editor.create_enemy && !env->confirmation_box.state
		&& env->sdl.event.key.keysym.sym == SDLK_BACKSPACE)
		env->editor.create_enemy = 0;
	if ((ret = space_pressed(env)) != 1)
	  	return (ret);
	if (env->sdl.event.key.keysym.sym == env->keys.enter
		&& !env->confirmation_box.state && !env->input_box.state
		&& !env->editor.enter_locked)
	{
		ret = valid_map(env);
		if (ret == -1)
			return (-1);
		else if (!ret)
			going_in_3D_mode(env);
	}
	if (env->sdl.event.key.keysym.sym == env->keys.enter
		&& env->editor.enter_locked)
		env->editor.enter_locked = 0;
	return (editor_keyup4(env));
}

int	editor_keyup2(t_env *env)
{
	if (env->editor.selecting_target && !env->confirmation_box.state
		&& env->sdl.event.key.keysym.sym == SDLK_BACKSPACE)
	{
		env->editor.selecting_target = 0;
		env->editor.creating_event = 1;
	}
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
	if (env->editor.create_object && !env->confirmation_box.state
		&& env->sdl.event.key.keysym.sym == SDLK_BACKSPACE)
		env->editor.create_object = 0;
	return (editor_keyup3(env));
}

int	editor_keyup(t_env *env)
{
	if (env->sdl.event.key.keysym.sym == SDLK_g && env->inputs.ctrl)
	{
		if (launch_game(env))
			return (-1);
	}
	if (env->sdl.event.key.keysym.sym == SDLK_m)
	{
		env->options.show_minimap = env->options.show_minimap ? 0 : 1;
		env->options.mipmapping = env->options.mipmapping ? 0 : 1;
	}
	if (env->sdl.event.key.keysym.sym == SDLK_DELETE)
		if (delete_action(env))
			return (-1);
	if (env->sdl.event.key.keysym.sym == SDLK_o)
		env->options.o = env->options.o ? 0 : 1;
	if (env->sdl.event.key.keysym.sym == SDLK_TAB)
		env->editor.tab = env->editor.tab ? 0 : 1;
	if (env->sdl.event.button.button == SDL_BUTTON_LEFT
		&& env->editor.event_panel_dragged)
		env->editor.event_panel_dragged = -1;
	return (editor_keyup2(env));
}

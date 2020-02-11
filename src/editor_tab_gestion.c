/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   editor_tab_gestion.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipatry <sipatry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 15:03:01 by sipatry           #+#    #+#             */
/*   Updated: 2020/02/11 16:54:48 by sipatry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

int		sprite_tab_keyup(t_env *env)
{
	if ((env->selected_floor_sprite != -1 || env->selected_ceiling_sprite != -1
	|| env->selected_wall_sprite_sprite != -1) && env->editor.sprite_tab.state == DOWN)
	{
		if (button_keyup(&env->editor.next_sprite, env))
			return (-1);
		if (button_keyup(&env->editor.previous_sprite, env))
			return (-1);
		if (button_keyup(&env->editor.current_sprite_selection, env))
			return (-1);
	}
	return (0);
}

int		events_tab_keyup(t_env *env)
{
	if (are_event_selection_buttons_visible(env))
	{
		if (button_keyup(&env->editor.next_event, env))
			return (-1);
		if (button_keyup(&env->editor.previous_event, env))
			return (-1);
	}
	if (are_launch_condition_selection_buttons_visible(env))
	{
		if (button_keyup(&env->editor.next_launch_condition, env))
			return (-1);
		if (button_keyup(&env->editor.previous_launch_condition, env))
			return (-1);
	}
	if (are_exec_condition_selection_buttons_visible(env))
	{
		if (button_keyup(&env->editor.next_exec_condition, env))
			return (-1);
		if (button_keyup(&env->editor.previous_exec_condition, env))
			return (-1);
	}
	return (0);
}

int		general_keyup(t_env *env)
{
	if (button_keyup(&env->editor.save, env))
		return (-1);
	if (button_keyup(&env->editor.sprite_tab, env))
		return (-1);
	else if (button_keyup(&env->editor.general_tab, env))
		return (-1);
	else if (button_keyup(&env->editor.sector_tab, env))
		return (-1);
	if (button_keyup(&env->editor.change_mode, env))	
		return (-1);
	if (button_keyup(&env->editor.launch_game, env))
		return (-1);
	if (button_keyup(&env->editor.texture_background, env))
		return (-1);
	if (button_keyup(&env->editor.events_tab, env))
		return (-1);   
	if (env->selected_ceiling != -1 && ceiling_buttons_up(env))
		return (-1);
	if (env->editor.selected_wall != -1 && wall_buttons_up(env))
		return (-1);
	if (env->selected_floor != -1 && floor_buttons_up(env))
		return (-1);
	if (env->selected_enemy != -1 && enemy_buttons_up(env))
		return (-1);
	if (env->selected_object != -1 && object_buttons_up(env))
		return (-1);
	if (env->selected_floor_sprite != -1 && floor_sprite_buttons_up(env))
		return (-1);
	if (env->selected_ceiling_sprite != -1 && ceiling_sprite_buttons_up(env))
		return (-1);
	if (env->selected_wall_sprite_sprite != -1 && wall_sprite_buttons_up(env))
		return (-1);
	return (0);
}

void		editor_options_tab_keyup(t_env *env)
{
	if (env->sdl.event.key.keysym.sym == SDLK_l)
		env->options.lighting = env->options.lighting ? 0 : 1;
	if (env->sdl.event.key.keysym.sym == SDLK_z)
		env->options.zbuffer = env->options.zbuffer ? 0 : 1;
	if (env->sdl.event.key.keysym.sym == SDLK_m)
		env->options.show_minimap = env->options.show_minimap ? 0 : 1;
}

int		editor_3d_tabs_keyup(t_env *env)
{
	general_keyup(env);
	if (env->editor.events_tab.state == DOWN)
	{
		if (events_tab_keyup(env))
			return (-1);
		if (button_keyup(&env->editor.next_events, env))
			return (-1);
		if (button_keyup(&env->editor.previous_events, env))
			return (-1);
	}
	if (env->editor.sprite_tab.state == DOWN)
	{
		if (sprite_tab_keyup(env))
			return (-1);
	}
	return (0);
}

void	editor_show_tab(t_env *env)
{
	if (env->editor.tab)
		SDL_SetRelativeMouseMode(1);
	else
		SDL_SetRelativeMouseMode(0);
	env->editor.tab = env->editor.tab ? 0 : 1;
	SDL_GetRelativeMouseState(&env->sdl.mouse_x,
	&env->sdl.mouse_y);
	SDL_GetRelativeMouseState(&env->sdl.mouse_x,
	&env->sdl.mouse_y);
	if (!env->editor.tab)
	{
		env->editor.sprite_tab.state = UP;
		env->editor.general_tab.state = UP;
		env->editor.sector_tab.state = UP;
		env->editor.sprite_tab.anim_state = REST;
		env->editor.general_tab.anim_state = REST;
		env->editor.sector_tab.anim_state = REST;
	}
}
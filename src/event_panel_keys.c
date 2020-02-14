/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_panel_keys.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 19:19:40 by lnicosia          #+#    #+#             */
/*   Updated: 2020/02/14 18:30:27 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

int		is_mouse_on_event_panel(t_env *env)
{
	if (env->editor.event_panel_dragged == 1)
		return (1);
	if (env->sdl.mx >= env->editor.event_panel.pos.x
		&& env->sdl.mx <= env->editor.event_panel.pos.x +
		env->editor.event_panel.size.x 
		&& env->sdl.my >= env->editor.event_panel.pos.y
		&& env->sdl.my <= env->editor.event_panel.pos.y +
		env->editor.event_panel.size.y)
		return (1);
	return (0);
}

static int	set_dragging(t_env *env)
{
	if (env->editor.event_panel_dragged == -1 && env->inputs.left_click
		&& env->sdl.mx >= env->editor.event_panel.pos.x
		&& env->sdl.mx <= env->editor.event_panel.pos.x +
		env->editor.event_panel.size.x
		&& env->sdl.my >= env->editor.event_panel.pos.y
		&& env->sdl.my <= env->editor.event_panel.pos.y +
		env->editor.event_panel.size.y / 5)
		env->editor.event_panel_dragged = 1;
	return (0);
}

static int	drag_panel(t_env *env)
{
	if (env->editor.event_panel_dragged == 1)
	{
		env->editor.event_panel.pos.x += env->sdl.mouse_x;
		env->editor.event_panel.pos.y += env->sdl.mouse_y;
		env->editor.event_panel.pos.x =
		ft_clamp(env->editor.event_panel.pos.x, 0, env->w - 1);
		env->editor.event_panel.pos.y =
		ft_clamp(env->editor.event_panel.pos.y, 0, env->h - 1);
		update_event_panel_button_pos(env);
		update_target_panel_button_pos(env);
		update_action_panel_button_pos(env);
		update_launch_conditions_panel_button_pos(env);
	}
	return (0);
}

int		event_panel_keys(t_env *env)
{
	if (button_keys(&env->editor.event_panel.target_tab, env))
		return (-1);
	if (button_keys(&env->editor.event_panel.action_tab, env))
		return (-1);
	if (button_keys(&env->editor.event_panel.launch_conditions_tab, env))
		return (-1);
	if (button_keys(&env->editor.event_panel.exec_conditions_tab, env))
		return (-1);
	if (button_keys(&env->editor.event_panel.ok, env))
		return (-1);
	if (button_keys(&env->editor.event_panel.cancel, env))
		return (-1);
	set_dragging(env);
	drag_panel(env);
	if (env->editor.event_panel.target_tab.state == DOWN)
	{
		if (target_panel_keys(env))
			return (-1);
	}
	if (env->editor.event_panel.action_tab.state == DOWN)
	{
		if (action_panel_keys(env))
			return (-1);
	}
	if (env->editor.event_panel.launch_conditions_tab.state == DOWN)
	{
		if (launch_conditions_panel_keys(env))
			return (-1);
	}
	/*if (env->editor.event_panel.exec_conditions_tab.state == DOWN)
	{
		if (exec_conditions_panel_keys(env))
			return (-1);
	}*/
	return (0);
}

int		event_panel_keyup(t_env *env)
{
	if (button_keyup(&env->editor.event_panel.target_tab, env))
		return (-1);
	if (button_keyup(&env->editor.event_panel.action_tab, env))
		return (-1);
	if (button_keyup(&env->editor.event_panel.launch_conditions_tab, env))
		return (-1);
	if (button_keyup(&env->editor.event_panel.exec_conditions_tab, env))
		return (-1);
	if (button_keyup(&env->editor.event_panel.ok, env))
		return (-1);
	if (button_keyup(&env->editor.event_panel.cancel, env))
		return (-1);
	if (env->editor.event_panel.target_tab.state == DOWN)
	{
		if (target_panel_keyup(env))
			return (-1);
	}
	if (env->editor.event_panel.action_tab.state == DOWN)
	{
		if (action_panel_keyup(env))
			return (-1);
	}
	if (env->editor.event_panel.launch_conditions_tab.state == DOWN)
	{
		if (launch_conditions_panel_keyup(env))
			return (-1);
	}
	/*if (env->editor.event_panel.exec_conditions_tab.state == DOWN)
	{
		if (exec_conditions_panel_keyup(env))
			return (-1);
	}*/
	return (0);
}

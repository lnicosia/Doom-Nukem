/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_panel_keys.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 19:19:40 by lnicosia          #+#    #+#             */
/*   Updated: 2020/02/06 21:50:07 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

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
	if (env->editor.event_panel_dragged == -1 && env->inputs.left_click
		&& env->sdl.mx >= env->editor.event_panel.pos.x
		&& env->sdl.mx <= env->editor.event_panel.pos.x +
		env->editor.event_panel.size.x
		&& env->sdl.mx >= env->editor.event_panel.pos.y
		&& env->sdl.mx <= env->editor.event_panel.pos.y +
		env->editor.event_panel.size.y)
		env->editor.event_panel_dragged = 1;
	if (env->editor.event_panel_dragged == 1)
	{
		env->editor.event_panel.pos.x += env->sdl.mouse_x;
		env->editor.event_panel.pos.y += env->sdl.mouse_y;
		env->editor.event_panel.target_tab.pos.x += env->sdl.mouse_x;
		env->editor.event_panel.target_tab.pos.y += env->sdl.mouse_y;
		env->editor.event_panel.action_tab.pos.x += env->sdl.mouse_x;
		env->editor.event_panel.action_tab.pos.y += env->sdl.mouse_y;
		env->editor.event_panel.launch_conditions_tab.pos.x += env->sdl.mouse_x;
		env->editor.event_panel.launch_conditions_tab.pos.y += env->sdl.mouse_y;
		env->editor.event_panel.exec_conditions_tab.pos.x += env->sdl.mouse_x;
		env->editor.event_panel.exec_conditions_tab.pos.y += env->sdl.mouse_y;
	}
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
	return (0);
}

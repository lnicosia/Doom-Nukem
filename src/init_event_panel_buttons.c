/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_event_panel_buttons.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 18:03:51 by lnicosia          #+#    #+#             */
/*   Updated: 2020/02/07 19:33:59 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

int		target_tab_func(void *param)
{
	t_env	*env;

	env = (t_env*)param;
	env->editor.event_panel.action_tab.state = UP;
	env->editor.event_panel.action_tab.anim_state = REST;
	env->editor.event_panel.launch_conditions_tab.state = UP;
	env->editor.event_panel.launch_conditions_tab.anim_state = REST;
	env->editor.event_panel.exec_conditions_tab.state = UP;
	env->editor.event_panel.exec_conditions_tab.anim_state = REST;
	return (0);
}

int		action_tab_func(void *param)
{
	t_env	*env;

	env = (t_env*)param;
	env->editor.event_panel.target_tab.state = UP;
	env->editor.event_panel.target_tab.anim_state = REST;
	env->editor.event_panel.launch_conditions_tab.state = UP;
	env->editor.event_panel.launch_conditions_tab.anim_state = REST;
	env->editor.event_panel.exec_conditions_tab.state = UP;
	env->editor.event_panel.exec_conditions_tab.anim_state = REST;
	return (0);
}

int		launch_conditions_tab_func(void *param)
{
	t_env	*env;

	env = (t_env*)param;
	env->editor.event_panel.target_tab.state = UP;
	env->editor.event_panel.target_tab.anim_state = REST;
	env->editor.event_panel.action_tab.state = UP;
	env->editor.event_panel.action_tab.anim_state = REST;
	env->editor.event_panel.exec_conditions_tab.state = UP;
	env->editor.event_panel.exec_conditions_tab.anim_state = REST;
	return (0);
}

int		exec_conditions_tab_func(void *param)
{
	t_env	*env;

	env = (t_env*)param;
	env->editor.event_panel.target_tab.state = UP;
	env->editor.event_panel.target_tab.anim_state = REST;
	env->editor.event_panel.action_tab.state = UP;
	env->editor.event_panel.action_tab.anim_state = REST;
	env->editor.event_panel.launch_conditions_tab.state = UP;
	env->editor.event_panel.launch_conditions_tab.anim_state = REST;
	return (0);
}

void	init_event_panel_buttons(t_env *env)
{
	env->editor.event_panel.top_size = 75;
	env->editor.event_panel.size =
	new_point(600, 400 + env->editor.event_panel.top_size);
	env->editor.event_panel.content_panel_size =
	new_point(env->editor.event_panel.size.x - 100,
	env->editor.event_panel.size.y - env->editor.event_panel.top_size);
	env->editor.event_panel.pos =
	new_point(env->h_w - env->editor.event_panel.size.x / 2,
	env->h_h - env->editor.event_panel.size.y / 2);
	env->editor.event_panel.target_tab = new_rectangle_button(WHEN_DOWN,
	&target_tab_func, env, env);
	env->editor.event_panel.target_tab.pos =
	new_point(env->editor.event_panel.pos.x,
	env->editor.event_panel.pos.y + env->editor.event_panel.top_size);
	env->editor.event_panel.action_tab = new_rectangle_button(WHEN_DOWN,
	&action_tab_func, env, env);
	env->editor.event_panel.action_tab.pos =
	new_point(env->editor.event_panel.pos.x,
	env->editor.event_panel.pos.y + env->editor.event_panel.top_size + 100);
	env->editor.event_panel.launch_conditions_tab = new_rectangle_button(
	WHEN_DOWN, &launch_conditions_tab_func, env, env);
	env->editor.event_panel.launch_conditions_tab.pos =
	new_point(env->editor.event_panel.pos.x,
	env->editor.event_panel.pos.y + env->editor.event_panel.top_size + 200);
	env->editor.event_panel.exec_conditions_tab = new_rectangle_button(
	WHEN_DOWN, &exec_conditions_tab_func, env, env);
	env->editor.event_panel.exec_conditions_tab.pos =
	new_point(env->editor.event_panel.pos.x,
	env->editor.event_panel.pos.y + env->editor.event_panel.top_size + 300);
	init_target_panel_buttons(env);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_panel_tab_functions.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 15:24:37 by lnicosia          #+#    #+#             */
/*   Updated: 2020/02/12 15:24:58 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

int             target_tab_func(void *param)
{
	t_env   *env;

	env = (t_env*)param;
	env->editor.event_panel.action_tab.state = UP;
	env->editor.event_panel.action_tab.anim_state = REST;
	env->editor.event_panel.launch_conditions_tab.state = UP;
	env->editor.event_panel.launch_conditions_tab.anim_state = REST;
	env->editor.event_panel.exec_conditions_tab.state = UP;
	env->editor.event_panel.exec_conditions_tab.anim_state = REST;
	return (0);
}

int             action_tab_func(void *param)
{
	t_env   *env;

	env = (t_env*)param;
	env->editor.event_panel.target_tab.state = UP;
	env->editor.event_panel.target_tab.anim_state = REST;
	env->editor.event_panel.launch_conditions_tab.state = UP;
	env->editor.event_panel.launch_conditions_tab.anim_state = REST;
	env->editor.event_panel.exec_conditions_tab.state = UP;
	env->editor.event_panel.exec_conditions_tab.anim_state = REST;
	return (0);
}

int             launch_conditions_tab_func(void *param)
{
	t_env   *env;

	env = (t_env*)param;
	env->editor.event_panel.target_tab.state = UP;
	env->editor.event_panel.target_tab.anim_state = REST;
	env->editor.event_panel.action_tab.state = UP;
	env->editor.event_panel.action_tab.anim_state = REST;
	env->editor.event_panel.exec_conditions_tab.state = UP;
	env->editor.event_panel.exec_conditions_tab.anim_state = REST;
	return (0);
}

int             exec_conditions_tab_func(void *param)
{
	t_env   *env;

	env = (t_env*)param;
	env->editor.event_panel.target_tab.state = UP;
	env->editor.event_panel.target_tab.anim_state = REST;
	env->editor.event_panel.action_tab.state = UP;
	env->editor.event_panel.action_tab.anim_state = REST;
	env->editor.event_panel.launch_conditions_tab.state = UP;
	env->editor.event_panel.launch_conditions_tab.anim_state = REST;
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_conditions_tabs_buttons.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 18:01:26 by lnicosia          #+#    #+#             */
/*   Updated: 2020/02/18 17:40:27 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

int			next_condition1(void *param)
{
	t_env	*env;
	t_event	event;

	env = (t_env*)param;
	event = env->editor.event_panel.event;
	if (env->editor.event_panel.launch_conditions_tab.state == DOWN)
	{
		if (env->editor.selected_launch_condition
			>= env->editor.event_panel.event.nb_launch_conditions - 1)
			env->editor.selected_launch_condition = 0;
		else
			env->editor.selected_launch_condition++;
	}
	else if (env->editor.event_panel.exec_conditions_tab.state == DOWN)
	{
		if (env->editor.selected_exec_condition
			>= env->editor.event_panel.event.nb_exec_conditions - 1)
			env->editor.selected_exec_condition = 0;
		else
			env->editor.selected_exec_condition++;
	}
	return (0);
}

int			previous_condition1(void *param)
{
	t_env	*env;
	t_event	event;

	env = (t_env*)param;
	event = env->editor.event_panel.event;
	if (env->editor.event_panel.launch_conditions_tab.state == DOWN)
	{
		if (env->editor.selected_launch_condition == 0)
			env->editor.selected_launch_condition =
			env->editor.event_panel.event.nb_launch_conditions - 1;
		else
			env->editor.selected_launch_condition--;
	}
	else if (env->editor.event_panel.exec_conditions_tab.state == DOWN)
	{
		if (env->editor.selected_exec_condition == 0)
			env->editor.selected_exec_condition =
			env->editor.event_panel.event.nb_exec_conditions - 1;
		else
			env->editor.selected_exec_condition--;
	}
	return (0);
}

void		update_conditions_panel_buttons_pos(t_env *env)
{
	t_event_panel	*panel;

	panel = &env->editor.event_panel;
	panel->previous_condition.pos =
	new_point(panel->pos.x + 100 + panel->content_panel_size.x / 2
	- panel->previous_condition.size_up.x / 2 - 180,
	panel->pos.y + panel->top_size + 5);
	panel->next_condition.pos =
	new_point(panel->pos.x + 100 + panel->content_panel_size.x / 2
	- panel->previous_condition.size_up.x / 2 + 180,
	panel->pos.y + panel->top_size + 5);
	panel->new_condition.pos = new_point(panel->pos.x + 100 +
	panel->content_panel_size.x / 2 - panel->new_condition.size_up.x / 2,
	panel->action_panel.value.pos.y);
	panel->modify_condition.pos = panel->action_panel.delay.pos;
	panel->delete_condition.pos = panel->action_panel.max_uses.pos;
}

int			new_condition(void *param)
{
	t_env	*env;

	env = (t_env*)param;
	env->editor.creating_condition = 1;
	if (env->editor.event_panel.launch_conditions_tab.state == DOWN)
		env->editor.creating_launch_condition = 1;
	else if (env->editor.event_panel.exec_conditions_tab.state == DOWN)
		env->editor.creating_exec_condition = 1;
	env->editor.event_panel.ok.release_action = &save_condition;
	env->editor.event_panel.target_tab.state = DOWN;
	return (0);
}

void		init_conditions_tabs_buttons(t_env *env)
{
	env->editor.event_panel.previous_condition =
	new_previous_arrow(ON_RELEASE, &previous_condition1, env, env);
	env->editor.event_panel.next_condition =
	new_next_arrow(ON_RELEASE, &next_condition1, env, env);
	env->editor.event_panel.new_condition =
	new_dark_panel_button(ON_RELEASE, &new_condition, env, env);
	env->editor.event_panel.modify_condition =
	new_dark_panel_button(ON_RELEASE, NULL, NULL, env);
	env->editor.event_panel.delete_condition =
	new_dark_panel_button(ON_RELEASE, &delete_condition, env, env);
	update_conditions_panel_buttons_pos(env);
}

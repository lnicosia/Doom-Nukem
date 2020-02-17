/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_launch_conditions_panel_buttons.c             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 18:01:26 by lnicosia          #+#    #+#             */
/*   Updated: 2020/02/17 11:56:44 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

int			next_launch_condition1(void *param)
{
	t_env	*env;
	t_event	event;

	env = (t_env*)param;
	event = env->editor.event_panel.event;
	if (env->editor.selected_launch_condition
		>= env->editor.event_panel.event.nb_launch_conditions - 1)
		env->editor.selected_launch_condition = 0;
	else
		env->editor.selected_launch_condition++;
	return (0);
}

int			previous_launch_condition1(void *param)
{
	t_env	*env;
	t_event	event;

	env = (t_env*)param;
	event = env->editor.event_panel.event;
	if (env->editor.selected_launch_condition == 0)
		env->editor.selected_launch_condition =
		env->editor.event_panel.event.nb_launch_conditions - 1;
	else
		env->editor.selected_launch_condition--;
	return (0);
}

void		update_launch_conditions_panel_buttons_pos(t_env *env)
{
	t_event_panel	*panel;

	panel = &env->editor.event_panel;
	panel->previous_launch_condition.pos =
	new_point(panel->pos.x + 100 + panel->content_panel_size.x / 2
	- panel->previous_launch_condition.size_up.x / 2 - 180,
	panel->pos.y + panel->top_size + 5);
	panel->next_launch_condition.pos =
	new_point(panel->pos.x + 100 + panel->content_panel_size.x / 2
	- panel->previous_launch_condition.size_up.x / 2 + 180,
	panel->pos.y + panel->top_size + 5);
	panel->new_launch_condition.pos = new_point(panel->pos.x + 100 +
	panel->content_panel_size.x / 2 - panel->new_launch_condition.size_up.x / 2,
	panel->action_panel.value.pos.y);
	panel->modify_launch_condition.pos = panel->action_panel.delay.pos;
	panel->delete_launch_condition.pos = panel->action_panel.max_uses.pos;
}

int			new_launch_condition(void *param)
{
	t_env	*env;

	env = (t_env*)param;
	env->editor.creating_condition = 1;
	env->editor.event_panel.ok.release_action = &save_condition;
	return (0);
}

void		init_launch_conditions_panel_buttons(t_env *env)
{
	env->editor.event_panel.previous_launch_condition =
	new_previous_arrow(ON_RELEASE, &previous_launch_condition1, env, env);
	env->editor.event_panel.next_launch_condition =
	new_next_arrow(ON_RELEASE, &next_launch_condition1, env, env);
	env->editor.event_panel.new_launch_condition =
	new_dark_panel_button(ON_RELEASE, &new_launch_condition, env, env);
	env->editor.event_panel.modify_launch_condition =
	new_dark_panel_button(ON_RELEASE, NULL, NULL, env);
	env->editor.event_panel.delete_launch_condition =
	new_dark_panel_button(ON_RELEASE, &delete_launch_condition, env, env);
	update_launch_conditions_panel_buttons_pos(env);
}

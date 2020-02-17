/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_condition_panel_buttons.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 11:44:24 by lnicosia          #+#    #+#             */
/*   Updated: 2020/02/17 12:25:14 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

void		set_condition_panel_button_pos(t_button *button, double side,
double tier, t_env *env)
{
	button->pos =
	new_point(env->editor.event_panel.pos.x + 100 +
	env->editor.event_panel.content_panel_size.x / 2 + 40 -
	(button->size_up.x + 4) * (side),
	env->editor.event_panel.pos.y + env->editor.event_panel.top_size + 50 +
	(button->size_up.y + 4) * tier);
}

void	update_condition_panel_buttons_pos(t_env *env)
{
	t_condition_panel	*panel;

	panel = &env->editor.condition_panel;
	set_condition_panel_button_pos(&panel->equals, -0.5, 0, env);
	set_condition_panel_button_pos(&panel->different, 0.5, 0, env);
	set_condition_panel_button_pos(&panel->less, 1.5, 0, env);
	set_condition_panel_button_pos(&panel->greater, 2.5, 0, env);
	set_condition_panel_button_pos(&panel->less_or_equals, -1, 1, env);
	set_condition_panel_button_pos(&panel->greater_or_equals, 0, 1, env);
	set_condition_panel_button_pos(&panel->event_ended, 1, 1, env);
	set_condition_panel_button_pos(&panel->event_ended_start, 2, 1, env);
	set_condition_panel_button_pos(&panel->function, 3, 1, env);
}

void	init_condition_panel_buttons(t_env *env)
{
	env->editor.condition_panel.equals = new_condition_panel_button(
	ON_RELEASE, NULL, NULL, env);
	env->editor.condition_panel.different = new_condition_panel_button(
	ON_RELEASE, NULL, NULL, env);
	env->editor.condition_panel.less = new_condition_panel_button(
	ON_RELEASE, NULL, NULL, env);
	env->editor.condition_panel.greater = new_condition_panel_button(
	ON_RELEASE, NULL, NULL, env);
	env->editor.condition_panel.less_or_equals =
	new_condition_panel_button(ON_RELEASE, NULL, NULL, env);
	env->editor.condition_panel.greater_or_equals =
	new_condition_panel_button(ON_RELEASE, NULL, NULL, env);
	env->editor.condition_panel.event_ended =
	new_condition_panel_button(ON_RELEASE, NULL, NULL, env);
	env->editor.condition_panel.event_ended_start =
	new_condition_panel_button(ON_RELEASE, NULL, NULL, env);
	env->editor.condition_panel.function =
	new_condition_panel_button(ON_RELEASE, NULL, NULL, env);
	update_condition_panel_buttons_pos(env);
}

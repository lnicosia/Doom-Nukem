/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_condition_panel_buttons.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 11:44:24 by lnicosia          #+#    #+#             */
/*   Updated: 2020/02/17 15:13:04 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

void	set_condition_panel_buttons_pos(t_button *button, double side,
double tier, t_env *env)
{
	button->pos =
	new_point(env->editor.event_panel.pos.x + 100 +
	env->editor.event_panel.content_panel_size.x / 2 + 40 -
	(button->size_up.x + 4) * (side),
	env->editor.event_panel.pos.y + env->editor.event_panel.top_size + 70 +
	(button->size_up.y + 4) * tier);
}

void	update_condition_panel_buttons_pos(t_env *env)
{
	t_condition_panel	*panel;

	panel = &env->editor.condition_panel;
	set_condition_panel_buttons_pos(&panel->equals, -0.5, 0, env);
	set_condition_panel_buttons_pos(&panel->different, 0.5, 0, env);
	set_condition_panel_buttons_pos(&panel->less, 1.5, 0, env);
	set_condition_panel_buttons_pos(&panel->greater, 2.5, 0, env);
	set_condition_panel_buttons_pos(&panel->less_or_equals, -1, 1, env);
	set_condition_panel_buttons_pos(&panel->greater_or_equals, 0, 1, env);
	set_condition_panel_buttons_pos(&panel->event_ended, 1, 1, env);
	set_condition_panel_buttons_pos(&panel->event_ended_start, 2, 1, env);
	set_condition_panel_buttons_pos(&panel->function, 3, 1, env);
}

void	init_condition_panel_buttons(t_env *env)
{
	t_condition_panel	*panel;

	panel = &env->editor.condition_panel;
	panel->equals = new_condition_panel_button(
	WHEN_DOWN, &set_equals, env, env);
	panel->different = new_condition_panel_button(
	WHEN_DOWN, &set_different, env, env);
	panel->less = new_condition_panel_button(
	WHEN_DOWN, &set_less, env, env);
	panel->greater = new_condition_panel_button(
	WHEN_DOWN, &set_greater, env, env);
	panel->less_or_equals = new_condition_panel_button(
	WHEN_DOWN, &set_less_or_equals, env, env);
	panel->greater_or_equals = new_condition_panel_button(
	WHEN_DOWN, &set_greater_or_equals, env, env);
	panel->event_ended = new_condition_panel_button(
	WHEN_DOWN, &set_event_ended, env, env);
	panel->event_ended_start = new_condition_panel_button(
	WHEN_DOWN, &set_event_ended_start, env, env);
	panel->function = new_condition_panel_button(
	WHEN_DOWN, &set_function, env, env);
	update_condition_panel_buttons_pos(env);
	init_condition_target_buttons(env);
}

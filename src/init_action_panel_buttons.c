/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_action_panel_buttons.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 18:01:12 by lnicosia          #+#    #+#             */
/*   Updated: 2020/02/20 14:03:13 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

int		set_event_go_to(void *param)
{
	t_env	*env;

	env = (t_env*)param;
	env->editor.event_panel.action_panel.add.state = UP;
	env->editor.event_panel.action_panel.add.anim_state = REST;
	if (env->editor.event_panel.event.mod_type == INCR)
		env->editor.event_panel.event.goal =
		env->editor.event_panel.event.start_incr;
	env->editor.event_panel.event.mod_type = FIXED;
	return (0);
}

int		set_event_add(void *param)
{
	t_env	*env;

	env = (t_env*)param;
	env->editor.event_panel.action_panel.go_to.state = UP;
	env->editor.event_panel.action_panel.go_to.anim_state = REST;
	if (env->editor.event_panel.event.mod_type == FIXED)
		env->editor.event_panel.event.start_incr =
		env->editor.event_panel.event.goal;
	env->editor.event_panel.event.mod_type = INCR;
	return (0);
}

void	update_action_panel_buttons_pos(t_env *env)
{
	t_event_panel	*panel;

	panel = &env->editor.event_panel;
	panel->action_panel.add.pos = new_point(panel->pos.x + 100 +
	panel->content_panel_size.x / 2 + 10,
	panel->pos.y + panel->top_size + panel->content_panel_size.y / 2
	- panel->action_panel.add.size_up.y * 2);
	panel->action_panel.go_to.pos = new_point(panel->action_panel.add.pos.x
	- panel->action_panel.go_to.size_up.x - 20, panel->action_panel.add.pos.y);
	panel->action_panel.delay.pos = new_point(panel->pos.x + 100 +
	panel->content_panel_size.x / 4 - panel->action_panel.delay.size_up.x / 2,
	panel->pos.y + panel->top_size + panel->content_panel_size.y / 2
	+ panel->action_panel.delay.size_up.y);
	panel->action_panel.max_uses.pos = new_point(panel->pos.x + 100 +
	panel->content_panel_size.x * 0.75
	- panel->action_panel.delay.size_up.x / 2, panel->action_panel.delay.pos.y);
	panel->action_panel.value.pos = new_point(panel->pos.x + 90
	+ panel->content_panel_size.x / 2 - panel->action_panel.value.size_up.x,
	panel->pos.y + panel->top_size + panel->content_panel_size.y / 2
	- panel->action_panel.value.size_up.y / 2);
	panel->action_panel.speed.pos = new_point(panel->pos.x + 100
	+ panel->content_panel_size.x / 2 + 10,
	panel->action_panel.value.pos.y);
}

void	init_action_panel_buttons(t_env *env)
{
	env->editor.event_panel.action_panel.go_to = new_small_panel_button(
	WHEN_DOWN, &set_event_go_to, env, env);
	env->editor.event_panel.action_panel.go_to.state = DOWN;
	env->editor.event_panel.action_panel.add = new_small_panel_button(
	WHEN_DOWN, &set_event_add, env, env);
	env->editor.event_panel.action_panel.value = new_green_panel_button(
	ON_RELEASE, &set_event_value, env, env);
	env->editor.event_panel.action_panel.speed = new_green_panel_button(
	ON_RELEASE, &set_event_speed, env, env);
	env->editor.event_panel.action_panel.delay = new_blue_panel_button(
	ON_RELEASE, &set_event_delay, env, env);
	env->editor.event_panel.action_panel.max_uses = new_blue_panel_button(
	ON_RELEASE, &set_event_max_uses, env, env);
	update_action_panel_buttons_pos(env);
}

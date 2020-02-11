/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_action_panel_buttons.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 18:01:12 by lnicosia          #+#    #+#             */
/*   Updated: 2020/02/11 18:53:58 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

void	update_action_panel_button_pos(t_env *env)
{
	t_event_panel	*panel;

	panel = &env->editor.event_panel;
	panel->action_panel.go_to.pos = new_point(panel->pos.x + 100 +
	panel->content_panel_size.x / 2 - panel->content_panel_size.x / 4
	+ panel->action_panel.go_to.size_up.x,
	panel->pos.y + panel->top_size + panel->content_panel_size.y / 2);
	panel->action_panel.add.pos = new_point(panel->pos.x + 100 +
	panel->content_panel_size.x / 2 - panel->content_panel_size.x / 4
	+ panel->action_panel.add.size_up.x,
	panel->pos.y + panel->top_size + panel->content_panel_size.y / 2);
	panel->action_panel.func.pos = new_point(panel->pos.x + 100 +
	panel->content_panel_size.x / 2 - panel->content_panel_size.x / 4
	+ panel->action_panel.func.size_up.x,
	panel->pos.y + panel->top_size + panel->content_panel_size.y / 2);
	panel->action_panel.delay.pos = new_point(panel->pos.x + 100 +
	panel->content_panel_size.x / 2 - panel->content_panel_size.x / 4
	+ panel->action_panel.delay.size_up.x,
	panel->pos.y + panel->top_size + panel->content_panel_size.y / 2);
	panel->action_panel.max_uses.pos = new_point(panel->pos.x + 100 +
	panel->content_panel_size.x / 2 - panel->content_panel_size.x / 4
	+ panel->action_panel.max_uses.size_up.x,
	panel->pos.y + panel->top_size + panel->content_panel_size.y / 2);

}

void	init_action_panel_buttons(t_env *env)
{
	env->editor.event_panel.action_panel.go_to = new_yellow_panel_button(
	WHEN_DOWN, NULL, NULL, env);
	env->editor.event_panel.action_panel.add = new_yellow_panel_button(
	WHEN_DOWN, NULL, NULL, env);
	env->editor.event_panel.action_panel.func = new_yellow_panel_button(
	WHEN_DOWN, NULL, NULL, env);
	env->editor.event_panel.action_panel.delay = new_yellow_panel_button(
	WHEN_DOWN, NULL, NULL, env);
	env->editor.event_panel.action_panel.max_uses = new_yellow_panel_button(
	WHEN_DOWN, NULL, NULL, env);
}

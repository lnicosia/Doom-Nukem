/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_event_panel_buttons.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 18:03:51 by lnicosia          #+#    #+#             */
/*   Updated: 2020/04/30 11:51:26 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

int		close_event_panel(void *param)
{
	t_env	*env;

	env = (t_env*)param;
	env->editor.event_panel.target_tab.state = UP;
	env->editor.event_panel.action_tab.state = UP;
	env->editor.event_panel.launch_conditions_tab.state = UP;
	env->editor.event_panel.exec_conditions_tab.state = UP;
	if (env->editor.creating_condition)
	{
		if (env->editor.creating_launch_condition)
			env->editor.event_panel.launch_conditions_tab.state = DOWN;
		else
			env->editor.event_panel.exec_conditions_tab.state = DOWN;
		env->editor.creating_condition = 0;
		env->editor.creating_launch_condition = 0;
		env->editor.creating_exec_condition = 0;
		env->editor.selecting_condition_target = 0;
		env->editor.selecting_event = 0;
	}
	else
	{
		env->editor.creating_event = 0;
		env->editor.selecting_target = 0;
		env->editor.event_panel.selected_event = -1;
	}
	return (0);
}

void	init_ok_button(t_env *env)
{
	env->editor.event_panel.ok = new_rectangle_button(
	ON_RELEASE, &create_event, env, env);
	env->editor.event_panel.ok.size_up.y = env->editor.event_panel.top_size - 2;
	env->editor.event_panel.ok.size_up.x = 98;
	env->editor.event_panel.ok.size_down =
	env->editor.event_panel.ok.size_up;
	env->editor.event_panel.ok.size_pressed =
	env->editor.event_panel.ok.size_up;
	env->editor.event_panel.ok.size_hover =
	env->editor.event_panel.ok.size_up;
	env->editor.event_panel.ok.font = env->sdl.fonts.lato_bold30;
	env->editor.event_panel.ok.up_text_color = 0x88c057FF;
	env->editor.event_panel.ok.down_text_color = 0x88c057FF;
	env->editor.event_panel.ok.pressed_text_color = 0x88c057FF;
	env->editor.event_panel.ok.hover_text_color = 0x88c057FF;
}

void	init_cancel_button(t_env *env)
{
	env->editor.event_panel.cancel = new_rectangle_button(
	ON_RELEASE, &close_event_panel, env, env);
	env->editor.event_panel.cancel.size_up.y =
	env->editor.event_panel.top_size - 2;
	env->editor.event_panel.cancel.size_up.x = 98;
	env->editor.event_panel.cancel.size_down =
	env->editor.event_panel.cancel.size_up;
	env->editor.event_panel.cancel.size_pressed =
	env->editor.event_panel.cancel.size_up;
	env->editor.event_panel.cancel.size_hover =
	env->editor.event_panel.cancel.size_up;
	env->editor.event_panel.cancel.font = env->sdl.fonts.lato_black40;
	env->editor.event_panel.cancel.up_text_color = 0xed7161FF;
	env->editor.event_panel.cancel.down_text_color = 0xed7161FF;
	env->editor.event_panel.cancel.pressed_text_color = 0xed7161FF;
	env->editor.event_panel.cancel.hover_text_color = 0xed7161FF;
}

void	update_event_panel_buttons_pos(t_env *env)
{
	t_event_panel	*panel;

	panel = &env->editor.event_panel;
	panel->target_tab.pos = new_point(panel->pos.x,
	panel->pos.y + panel->top_size);
	panel->action_tab.pos = new_point(panel->pos.x,
	panel->pos.y + panel->top_size + 100);
	panel->launch_conditions_tab.pos = new_point(panel->pos.x,
	panel->pos.y + panel->top_size + 200);
	panel->exec_conditions_tab.pos = new_point(panel->pos.x,
	panel->pos.y + panel->top_size + 300);
	panel->ok.pos = new_point(panel->pos.x + panel->size.x - 198,
	panel->pos.y);
	panel->cancel.pos = new_point(panel->pos.x + panel->size.x - 98,
	panel->pos.y);
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
	env->editor.event_panel.action_tab = new_rectangle_button(WHEN_DOWN,
	&action_tab_func, env, env);
	env->editor.event_panel.launch_conditions_tab = new_rectangle_button(
	WHEN_DOWN, &launch_conditions_tab_func, env, env);
	env->editor.event_panel.exec_conditions_tab = new_rectangle_button(
	WHEN_DOWN, &exec_conditions_tab_func, env, env);
	init_ok_button(env);
	init_cancel_button(env);
	update_event_panel_buttons_pos(env);
	init_target_panel_buttons(env);
	init_action_panel_buttons(env);
	init_conditions_tabs_buttons(env);
	init_condition_panel_buttons(env);
	init_weapon_picker(env);
}

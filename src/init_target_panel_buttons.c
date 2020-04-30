/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_target_panel_buttons.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 17:57:33 by lnicosia          #+#    #+#             */
/*   Updated: 2020/04/30 12:09:27 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

void	set_target_panel_button_pos(t_button *button, double side,
double nb, t_env *env)
{
	button->pos =
	new_point(env->editor.event_panel.pos.x + 100 +
	env->editor.event_panel.content_panel_size.x / 2 -
	button->size_up.x / 2 +
	(button->size_up.x / 2 + 3) * (side),
	env->editor.event_panel.pos.y + env->editor.event_panel.top_size + 20 +
	env->editor.event_panel.content_panel_size.y / 6 +
	(button->size_up.y + 5) * nb);
}

void	update_target_panel_buttons_pos2(t_event_panel *panel, t_env *env)
{
	set_target_panel_button_pos(&panel->target_panel.targets[0], -1, 0, env);
	set_target_panel_button_pos(&panel->target_panel.targets[1], -1, 1, env);
	set_target_panel_button_pos(&panel->target_panel.targets[2], -1, 2, env);
	set_target_panel_button_pos(&panel->target_panel.targets[3], -1, 3, env);
	set_target_panel_button_pos(&panel->target_panel.targets[4], 1, 0, env);
	set_target_panel_button_pos(&panel->target_panel.targets[5], 1, 1, env);
	set_target_panel_button_pos(&panel->target_panel.targets[6], 1, 2, env);
	set_target_panel_button_pos(&panel->target_panel.targets[7], 1, 3, env);
}

void	update_target_panel_buttons_pos(t_env *env)
{
	t_event_panel	*panel;

	panel = &env->editor.event_panel;
	set_target_panel_button_pos(&panel->target_panel.sector, -2, 0, env);
	set_target_panel_button_pos(&panel->target_panel.wall, -2, 1, env);
	set_target_panel_button_pos(&panel->target_panel.wall_sprite, 0, 2, env);
	set_target_panel_button_pos(&panel->target_panel.weapon, -2, 2, env);
	set_target_panel_button_pos(&panel->target_panel.enemy, 2, 0, env);
	set_target_panel_button_pos(&panel->target_panel.object, 2, 1, env);
	set_target_panel_button_pos(&panel->target_panel.other, 2, 2, env);
	set_target_panel_button_pos(&panel->target_panel.player, 0, 0, env);
	set_target_panel_button_pos(&panel->target_panel.vertex, 0, 1, env);
	set_target_panel_button_pos(&panel->target_panel.floor, 0, 0, env);
	set_target_panel_button_pos(&panel->target_panel.ceiling, 0, 1, env);
	set_target_panel_button_pos(&panel->target_panel.sector_other, 0, 2, env);
	panel->target_panel.previous.pos =
	new_point((panel->pos.x + 100 +
	panel->target_panel.sector.pos.x) / 2 -
	panel->target_panel.previous.size_up.x / 2,
	panel->pos.y + panel->top_size + panel->content_panel_size.y / 2 -
	panel->target_panel.previous.size_up.y / 2);
	update_target_panel_buttons_pos2(panel, env);
}

void	init_target_panel_buttons2(t_env *env)
{
	int		i;

	env->editor.event_panel.target_panel.other = new_yellow_panel_button(
	ON_RELEASE, &select_other, env, env);
	i = 0;
	while (i < 9)
	{
		env->editor.event_panel.target_panel.targets[i] =
		new_yellow_panel_button(WHEN_DOWN, &choose_target, env, env);
		i++;
	}
	env->editor.event_panel.target_panel.next = new_next_arrow(
	ON_RELEASE, &previous_target_selection_phase, env, env);
	env->editor.event_panel.target_panel.previous = new_previous_arrow(
	ON_RELEASE, &previous_target_selection_phase, env, env);
	update_target_panel_buttons_pos(env);
}

void	init_target_panel_buttons(t_env *env)
{
	env->editor.event_panel.target_panel.sector = new_red_panel_button(
	ON_RELEASE, &set_int_button,
	&env->editor.event_panel.target_panel.sector_type, env);
	env->editor.event_panel.target_panel.wall = new_blue_panel_button(
	ON_RELEASE, &select_wall, env, env);
	env->editor.event_panel.target_panel.wall_sprite = new_green_panel_button(
	ON_RELEASE, &select_wall_sprite, env, env);
	env->editor.event_panel.target_panel.weapon = new_dark_panel_button(
	ON_RELEASE, &select_weapon, env, env);
	env->editor.event_panel.target_panel.enemy = new_yellow_panel_button(
	ON_RELEASE, &select_enemy, env, env);
	env->editor.event_panel.target_panel.object = new_purple_panel_button(
	ON_RELEASE, &select_object, env, env);
	env->editor.event_panel.target_panel.player = new_orange_panel_button(
	ON_RELEASE, &select_player, env, env);
	env->editor.event_panel.target_panel.vertex = new_turquoise_panel_button(
	ON_RELEASE, &select_vertex, env, env);
	env->editor.event_panel.target_panel.floor = new_red_panel_button(
	ON_RELEASE, &select_floor, env, env);
	env->editor.event_panel.target_panel.ceiling = new_green_panel_button(
	ON_RELEASE, &select_ceiling, env, env);
	env->editor.event_panel.target_panel.sector_other = new_yellow_panel_button(
	ON_RELEASE, &select_sector_other, env, env);
	init_target_panel_buttons2(env);
}

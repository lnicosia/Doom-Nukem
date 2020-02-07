/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_target_panel_buttons.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 17:57:33 by lnicosia          #+#    #+#             */
/*   Updated: 2020/02/07 21:49:10 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

void		set_target_panel_button_pos(t_button *button, int side, int nb,
t_env *env)
{
	button->pos =
	new_point(env->editor.event_panel.pos.x + 100 +
	env->editor.event_panel.content_panel_size.x / 2 -
	button->size_up.x / 2 +
	(button->size_up.x / 2 + 2) * (side),
	env->editor.event_panel.pos.y + env->editor.event_panel.top_size + 20 + 
	env->editor.event_panel.content_panel_size.y / 6 +
	(button->size_up.y + 4) * nb);
}

void		update_target_panel_button_pos(t_env *env)
{
	set_target_panel_button_pos(&env->editor.event_panel.target_panel.sector,
	-1, 0, env);
	set_target_panel_button_pos(&env->editor.event_panel.target_panel.wall,
	-1, 1, env);
	set_target_panel_button_pos(&env->editor.event_panel.target_panel.
	wall_sprite, -1, 2, env);
	set_target_panel_button_pos(&env->editor.event_panel.target_panel.weapon,
	-1, 3, env);
	set_target_panel_button_pos(&env->editor.event_panel.target_panel.enemy,
	1, 0, env);
	set_target_panel_button_pos(&env->editor.event_panel.target_panel.object,
	1, 1, env);
	set_target_panel_button_pos(&env->editor.event_panel.target_panel.player,
	1, 2, env);
	set_target_panel_button_pos(&env->editor.event_panel.target_panel.other,
	1, 3, env);
}

void		init_target_panel_buttons(t_env *env)
{
	env->editor.event_panel.target_panel.sector = new_red_panel_button(
	ON_RELEASE, NULL, NULL, env);
	env->editor.event_panel.target_panel.wall = new_blue_panel_button(
	ON_RELEASE, NULL, NULL, env);
	env->editor.event_panel.target_panel.wall_sprite = new_green_panel_button(
	ON_RELEASE, NULL, NULL, env);
	env->editor.event_panel.target_panel.weapon = new_dark_panel_button(
	ON_RELEASE, NULL, NULL, env);
	env->editor.event_panel.target_panel.enemy = new_yellow_panel_button(
	ON_RELEASE, NULL, NULL, env);
	env->editor.event_panel.target_panel.object = new_purple_panel_button(
	ON_RELEASE, NULL, NULL, env);
	env->editor.event_panel.target_panel.player = new_orange_panel_button(
	ON_RELEASE, NULL, NULL, env);
	env->editor.event_panel.target_panel.other = new_turquoise_panel_button(
	ON_RELEASE, NULL, NULL, env);
	update_target_panel_button_pos(env);
}

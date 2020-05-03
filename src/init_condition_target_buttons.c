/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_condition_target_buttons.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 17:57:33 by lnicosia          #+#    #+#             */
/*   Updated: 2020/02/18 11:35:15 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

void		update_condition_target_buttons_pos2(t_target_panel *panel,
t_env *env)
{
	set_condition_panel_buttons_pos(&panel->targets[3], -0.5, 0, env);
	if (panel->player_type)
	{
		set_condition_panel_buttons_pos(&panel->targets[4], 3, 1, env);
		set_condition_panel_buttons_pos(&panel->targets[5], 2, 1, env);
		set_condition_panel_buttons_pos(&panel->targets[6], 1, 1, env);
		set_condition_panel_buttons_pos(&panel->targets[7], 0, 1, env);
		set_condition_panel_buttons_pos(&panel->targets[8], -1, 1, env);
	}
	else
	{
		set_condition_panel_buttons_pos(&panel->targets[4], 2.5, 1, env);
		set_condition_panel_buttons_pos(&panel->targets[5], 1.5, 1, env);
		set_condition_panel_buttons_pos(&panel->targets[6], 0.5, 1, env);
		set_condition_panel_buttons_pos(&panel->targets[7], -0.5, 1, env);
		set_condition_panel_buttons_pos(&panel->targets[8], -1.5, 1, env);
	}
}

void		update_condition_target_buttons_pos(t_env *env)
{
	t_target_panel	*panel;

	panel = &env->editor.condition_panel.target_panel;
	set_condition_panel_buttons_pos(&panel->sector, -0.5, 0, env);
	set_condition_panel_buttons_pos(&panel->wall, 0.5, 0, env);
	set_condition_panel_buttons_pos(&panel->wall_sprite, 1.5, 0,
	env);
	set_condition_panel_buttons_pos(&panel->weapon, 2.5, 0, env);
	set_condition_panel_buttons_pos(&panel->enemy, -0.5, 1, env);
	set_condition_panel_buttons_pos(&panel->object, 0.5, 1, env);
	set_condition_panel_buttons_pos(&panel->player, 1.5, 1, env);
	set_condition_panel_buttons_pos(&panel->vertex, 2.5, 1, env);
	set_condition_panel_buttons_pos(&panel->floor, 0, 0, env);
	set_condition_panel_buttons_pos(&panel->ceiling, 1, 0, env);
	set_condition_panel_buttons_pos(&panel->sector_other, 2, 0, env);
	panel->previous.pos =
	new_point(env->editor.event_panel.pos.x + 110,
	env->editor.event_panel.pos.y + env->editor.event_panel.top_size + 80);
	set_condition_panel_buttons_pos(&panel->targets[0], 2.5, 0, env);
	set_condition_panel_buttons_pos(&panel->targets[1], 1.5, 0, env);
	set_condition_panel_buttons_pos(&panel->targets[2], 0.5, 0, env);
	update_condition_target_buttons_pos2(panel, env);
}

void		init_condition_target_buttons2(t_condition_panel *panel, t_env *env)
{
	int	i;

	panel->target_panel.ceiling = new_condition_panel_button(
	ON_RELEASE, select_ceiling, env, env);
	panel->target_panel.sector_other = new_condition_panel_button(
	ON_RELEASE, select_sector_other, env, env);
	i = 0;
	while (i < 9)
	{
		panel->target_panel.targets[i] =
		new_condition_panel_button(WHEN_DOWN, &choose_target, env, env);
		i++;
	}
	panel->target_panel.next = new_next_arrow(
	ON_RELEASE, &previous_target_selection_phase, env, env);
	panel->target_panel.previous = new_previous_arrow(
	ON_RELEASE, &previous_target_selection_phase, env, env);
	update_condition_target_buttons_pos(env);
}

void		init_condition_target_buttons(t_env *env)
{
	t_condition_panel	*panel;

	panel = &env->editor.condition_panel;
	panel->target_panel.sector = new_condition_panel_button(
	ON_RELEASE, set_int_button, &panel->target_panel.sector_type, env);
	panel->target_panel.wall = new_condition_panel_button(
	ON_RELEASE, select_wall, env, env);
	panel->target_panel.wall_sprite = new_condition_panel_button(
	ON_RELEASE, select_wall_sprite, env, env);
	panel->target_panel.weapon = new_condition_panel_button(
	ON_RELEASE, select_weapon, env, env);
	panel->target_panel.enemy = new_condition_panel_button(
	ON_RELEASE, select_enemy, env, env);
	panel->target_panel.object = new_condition_panel_button(
	ON_RELEASE, select_object, env, env);
	panel->target_panel.player = new_condition_panel_button(
	ON_RELEASE, select_player, env, env);
	panel->target_panel.vertex = new_condition_panel_button(
	ON_RELEASE, select_vertex, env, env);
	panel->target_panel.floor = new_condition_panel_button(
	ON_RELEASE, select_floor, env, env);
	init_condition_target_buttons2(panel, env);
}

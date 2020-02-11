/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_target_panel_buttons.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 17:57:33 by lnicosia          #+#    #+#             */
/*   Updated: 2020/02/11 17:00:06 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

int			get_target_selection_phase(t_env *env)
{
	t_target_panel	panel;

	panel = env->editor.event_panel.target_panel;
	if (panel.sector_type && !panel.floor_type && !panel.ceiling_type
		&& !panel.sector_other_type)
		return (1);
	else if (panel.wall_type || panel.wall_sprite_type
		|| panel.weapon_type || panel.enemy_type || panel.object_type
		|| panel.player_type || panel.vertex_type || panel.floor_type
		|| panel.ceiling_type || panel.sector_other_type)
		return (2);
	return (0);
}

int			set_int_button(void *param)
{
	*((int*)param) = 1;
	return (0);
}

int			previous_target_selection_phase(void *param)
{
	t_env	*env;

	env = (t_env*)param;
	if (get_target_selection_phase(env) == 1)
	{
		env->editor.event_panel.target_panel.sector_type = 0;
	}
	if (get_target_selection_phase(env) == 2)
	{
		env->editor.event_panel.target_panel.wall_type = 0;
		env->editor.event_panel.target_panel.wall_sprite_type = 0;
		env->editor.event_panel.target_panel.object_type = 0;
		env->editor.event_panel.target_panel.weapon_type = 0;
		env->editor.event_panel.target_panel.enemy_type = 0;
		env->editor.event_panel.target_panel.player_type = 0;
		env->editor.event_panel.target_panel.vertex_type = 0;
		env->editor.event_panel.target_panel.floor_type = 0;
		env->editor.event_panel.target_panel.ceiling_type = 0;
		env->editor.event_panel.target_panel.sector_other_type = 0;
	}
	return (0);
}

void		set_target_panel_button_pos(t_button *button, double side,
double nb, t_env *env)
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
	t_event_panel	*panel;

	panel = &env->editor.event_panel;
	set_target_panel_button_pos(&panel->target_panel.sector, -1, 0, env);
	set_target_panel_button_pos(&panel->target_panel.wall, -1, 1, env);
	set_target_panel_button_pos(&panel->target_panel.wall_sprite, -1, 2, env);
	set_target_panel_button_pos(&panel->target_panel.weapon, -1, 3, env);
	set_target_panel_button_pos(&panel->target_panel.enemy, 1, 0, env);
	set_target_panel_button_pos(&panel->target_panel.object, 1, 1, env);
	set_target_panel_button_pos(&panel->target_panel.player, 1, 2, env);
	set_target_panel_button_pos(&panel->target_panel.vertex, 1, 3, env);
	set_target_panel_button_pos(&panel->target_panel.floor, 0, 0, env);
	set_target_panel_button_pos(&panel->target_panel.ceiling, 0, 1, env);
	set_target_panel_button_pos(&panel->target_panel.sector_other, 0, 2, env);
	panel->target_panel.previous.pos = new_point((panel->pos.x + 100 +
	panel->target_panel.sector.pos.x) / 2 -
	panel->target_panel.previous.size_up.x / 2, panel->pos.y + panel->top_size +
	panel->content_panel_size.y / 2 -
	panel->target_panel.previous.size_up.y / 2);
	set_target_panel_button_pos(&panel->target_panel.targets[0], -1, 0, env);
	set_target_panel_button_pos(&panel->target_panel.targets[1], -1, 1, env);
	set_target_panel_button_pos(&panel->target_panel.targets[2], -1, 2, env);
	set_target_panel_button_pos(&panel->target_panel.targets[3], -1, 3, env);
	set_target_panel_button_pos(&panel->target_panel.targets[4], 1, 0, env);
	set_target_panel_button_pos(&panel->target_panel.targets[5], 1, 1, env);
	set_target_panel_button_pos(&panel->target_panel.targets[6], 1, 2, env);
	set_target_panel_button_pos(&panel->target_panel.targets[7], 1, 3, env);
}

int			choose_target(void *param)
{
	t_env	*env;
	int		i;
	int		select;

	env = (t_env*)param;
	env->editor.creating_event = 0;
	env->editor.selecting_target = 1;
	select = 0;
	reset_selection(env);
	new_tabs_position(env);
	i = 0;
	while (i < 8)
	{
		if (env->editor.event_panel.target_panel.targets[i].state == DOWN
			&& env->editor.event_panel.target_panel.selected_button != i
			&& select == 0)
		{
			env->editor.event_panel.target_panel.selected_button = i;
			select = 1;
		}
		env->editor.event_panel.target_panel.targets[i].state = UP;
		env->editor.event_panel.target_panel.targets[i].anim_state = REST;
		i++;
	}
	if (env->editor.event_panel.target_panel.player_type)
		return (0);
	if (update_confirmation_box(&env->confirmation_box, "Please now select"
		" your target", CONFIRM, env))
		return (-1);
	return (0);
}

void		init_target_panel_buttons(t_env *env)
{
	int		i;

	env->editor.event_panel.target_panel.sector = new_red_panel_button(
	ON_RELEASE, set_int_button,
	&env->editor.event_panel.target_panel.sector_type, env);
	env->editor.event_panel.target_panel.wall = new_blue_panel_button(
	ON_RELEASE, select_wall, env, env);
	env->editor.event_panel.target_panel.wall_sprite = new_green_panel_button(
	ON_RELEASE, select_wall_sprite, env, env);
	env->editor.event_panel.target_panel.weapon = new_dark_panel_button(
	ON_RELEASE, select_weapon, env, env);
	env->editor.event_panel.target_panel.enemy = new_yellow_panel_button(
	ON_RELEASE, select_enemy, env, env);
	env->editor.event_panel.target_panel.object = new_purple_panel_button(
	ON_RELEASE, select_object, env, env);
	env->editor.event_panel.target_panel.player = new_orange_panel_button(
	ON_RELEASE, select_player, env, env);
	env->editor.event_panel.target_panel.vertex = new_turquoise_panel_button(
	ON_RELEASE, select_vertex, env, env);
	update_target_panel_button_pos(env);
	env->editor.event_panel.target_panel.floor = new_red_panel_button(
	ON_RELEASE, select_floor, env, env);
	env->editor.event_panel.target_panel.ceiling = new_green_panel_button(
	ON_RELEASE, select_ceiling, env, env);
	env->editor.event_panel.target_panel.sector_other = new_yellow_panel_button(
	ON_RELEASE, select_sector_other, env, env);
	i = 0;
	while (i < 8)
	{
		env->editor.event_panel.target_panel.targets[i] =
		new_yellow_panel_button(WHEN_DOWN, &choose_target, env, env);
		i++;
	}
	env->editor.event_panel.target_panel.next = new_next_arrow(
	ON_RELEASE, &previous_target_selection_phase, env, env);
	env->editor.event_panel.target_panel.previous = new_previous_arrow(
	ON_RELEASE, &previous_target_selection_phase, env, env);
}

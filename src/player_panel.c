/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_panel.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 13:09:54 by lnicosia          #+#    #+#             */
/*   Updated: 2020/02/18 11:37:18 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "events_parser.h"

int		set_player_panel_buttons_state(t_target_panel *panel, int index)
{
	if (index == PLAYER_X)
		panel->targets[0].state = DOWN;
	else if (index == PLAYER_Y)
		panel->targets[1].state = DOWN;
	else if (index == PLAYER_Z)
		panel->targets[2].state = DOWN;
	else if (index == PLAYER_HP)
		panel->targets[3].state = DOWN;
	else if (index == PLAYER_ARMOR)
		panel->targets[4].state = DOWN;
	else if (index == PLAYER_SPEED)
		panel->targets[5].state = DOWN;
	else if (index == PLAYER_INVINCIBLE)
		panel->targets[6].state = DOWN;
	else if (index == PLAYER_INFINITE_AMMO)
		panel->targets[7].state = DOWN;
	else if (index == PLAYER_SECTOR)
		panel->targets[8].state = DOWN;
	return (0);
}

int		select_player(void *param)
{
	t_env			*env;
	t_target_panel	*panel;
	int				i;

	env = (t_env*)param;
	if (env->editor.creating_condition)
		panel = &env->editor.condition_panel.target_panel;
	else
		panel = &env->editor.event_panel.target_panel;
	panel->player_type = 1;
	i = 0;
	while (i < 8)
	{
		panel->targets[i].state = UP;
		panel->targets[i].anim_state = REST;
		i++;
	}
	if (env->editor.creating_condition)
	{
		if (env->editor.condition_panel.condition.target)
			set_player_panel_buttons_state(panel,
			env->editor.condition_panel.condition.target_index);
	}
	else
	{
		if (env->editor.event_panel.event.target)
			set_player_panel_buttons_state(panel,
			env->editor.event_panel.event.target_index);
	}
	update_condition_target_buttons_pos(env);
	update_target_panel_buttons_pos(env);
	return (0);
}

int		draw_player_panel(t_env *env, t_target_panel *panel)
{
	draw_button(env, panel->targets[0], "X");
	draw_button(env, panel->targets[1], "Y");
	draw_button(env, panel->targets[2], "Z");
	draw_button(env, panel->targets[3], "Health");
	draw_button(env, panel->targets[4], "Armor");
	draw_button(env, panel->targets[5], "Speed");
	draw_button(env, panel->targets[6], "Invincible");
	draw_button(env, panel->targets[7], "Infinite ammo");
	if (env->editor.creating_condition)
		draw_button(env, panel->targets[8], "Sector");
	return (0);
}

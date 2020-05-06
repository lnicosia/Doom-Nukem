/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_panel.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 13:09:54 by lnicosia          #+#    #+#             */
/*   Updated: 2020/04/30 18:21:42 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "events_parser.h"
#include "draw.h"

void	select_player_panel_button(t_target_panel *panel, int down)
{
	panel->targets[down].state = DOWN;
	panel->selected_button = down;
}

int		set_player_panel_buttons_state(t_target_panel *panel, int index)
{
	int		down;

	down = -1;
	if (index == PLAYER_X)
		down = 0;
	else if (index == PLAYER_Y)
		down = 1;
	else if (index == PLAYER_Z)
		down = 2;
	else if (index == PLAYER_HP)
		down = 3;
	else if (index == PLAYER_ARMOR)
		down = 4;
	else if (index == PLAYER_SPEED)
		down = 5;
	else if (index == PLAYER_INVINCIBLE)
		down = 6;
	else if (index == PLAYER_INFINITE_AMMO)
		down = 7;
	else if (index == PLAYER_SECTOR)
		down = 8;
	if (down != -1)
		select_player_panel_button(panel, down);
	return (0);
}

int		select_player2(t_target_panel *panel, t_env *env)
{
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
	while (i < 9)
	{
		panel->targets[i].state = UP;
		panel->targets[i].anim_state = REST;
		i++;
	}
	return (select_player2(panel, env));
}

int		draw_player_panel(t_env *env, t_target_panel *panel)
{
	if (draw_button(env, panel->targets[0], "X"))
		return (-1);
	if (draw_button(env, panel->targets[1], "Y"))
		return (-1);
	if (draw_button(env, panel->targets[2], "Z"))
		return (-1);
	if (draw_button(env, panel->targets[3], "Health"))
		return (-1);
	if (draw_button(env, panel->targets[4], "Armor"))
		return (-1);
	if (draw_button(env, panel->targets[5], "Speed"))
		return (-1);
	if (draw_button(env, panel->targets[6], "Invincible"))
		return (-1);
	if (draw_button(env, panel->targets[7], "Infinite ammo"))
		return (-1);
	if (env->editor.creating_condition)
	{
		if (draw_button(env, panel->targets[8], "Sector"))
		return (-1);
	}
	return (0);
}

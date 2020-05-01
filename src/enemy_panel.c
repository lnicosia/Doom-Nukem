/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_panel.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 13:09:54 by lnicosia          #+#    #+#             */
/*   Updated: 2020/04/29 18:50:08 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "events_parser.h"
#include "enemies.h"
#include "draw.h"

int		set_enemy_panel_buttons_state(t_target_panel *panel, int index)
{
	int		down;

	down = -1;
	if (index == ENEMY_SPRITE)
		down = 0;
	else if (index == ENEMY_X)
		down = 1;
	else if (index == ENEMY_Y)
		down = 2;
	else if (index == ENEMY_Z)
		down = 3;
	else if (index == ENEMY_SCALE)
		down = 4;
	else if (index == ENEMY_SPEED)
		down = 5;
	else if (index == ENEMY_DAMAGE)
		down = 6;
	else if (index == ENEMY_HP)
		down = 7;
	if (down != -1)
	{
		panel->targets[down].state = DOWN;
		panel->selected_button = down;
	}
	return (0);
}

void	select_enemy2(t_target_panel *panel, t_env *env)
{
	if (env->editor.creating_condition)
	{
		if (env->editor.condition_panel.condition.target)
			set_enemy_panel_buttons_state(panel,
			env->editor.condition_panel.condition.target_index);
	}
	else
	{
		if (env->editor.event_panel.event.target)
			set_enemy_panel_buttons_state(panel,
			env->editor.event_panel.event.target_index);
	}
}

int		select_enemy(void *param)
{
	t_env			*env;
	t_target_panel	*panel;
	int				i;

	env = (t_env*)param;
	if (env->editor.creating_condition)
		panel = &env->editor.condition_panel.target_panel;
	else
		panel = &env->editor.event_panel.target_panel;
	panel->enemy_type = 1;
	i = 0;
	while (i < 8)
	{
		panel->targets[i].state = UP;
		panel->targets[i].anim_state = REST;
		i++;
	}
	select_enemy2(panel, env);
	return (0);
}

int		draw_enemy_panel(t_env *env, t_target_panel *panel)
{
	draw_button(env, panel->targets[0], "Sprite");
	draw_button(env, panel->targets[1], "X");
	draw_button(env, panel->targets[2], "Y");
	draw_button(env, panel->targets[3], "Z");
	draw_button(env, panel->targets[4], "Scale");
	draw_button(env, panel->targets[5], "Speed");
	draw_button(env, panel->targets[6], "Damage");
	draw_button(env, panel->targets[7], "Health");
	return (0);
}

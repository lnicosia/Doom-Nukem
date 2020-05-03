/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floor_panel.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 13:09:54 by lnicosia          #+#    #+#             */
/*   Updated: 2020/03/11 13:27:56 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "events_parser.h"

int		set_floor_panel_buttons_state(t_target_panel *panel, int index)
{
	int		down;

	down = -1;
	if (index == SECTOR_FLOOR_HEIGHT)
		down = 0;
	else if (index == SECTOR_FLOOR_TEXTURE)
		down = 1;
	else if (index == SECTOR_FLOOR_SLOPE)
		down = 2;
	else if (index == SECTOR_FLOOR_ALIGN_X)
		down = 3;
	else if (index == SECTOR_FLOOR_ALIGN_Y)
		down = 4;
	else if (index == SECTOR_FLOOR_SCALE_X)
		down = 5;
	else if (index == SECTOR_FLOOR_SCALE_Y)
		down = 6;
	if (down != -1)
	{
		panel->targets[down].state = DOWN;
		panel->selected_button = down;
	}
	return (0);
}

int		select_floor2(t_target_panel *panel, t_env *env)
{
	if (env->editor.creating_condition)
	{
		if (env->editor.condition_panel.condition.target)
			set_floor_panel_buttons_state(panel,
			env->editor.condition_panel.condition.target_index);
	}
	else
	{
		if (env->editor.event_panel.event.target)
			set_floor_panel_buttons_state(panel,
			env->editor.event_panel.event.target_index);
	}
	return (0);
}

int		select_floor(void *param)
{
	t_env			*env;
	t_target_panel	*panel;
	int				i;

	env = (t_env*)param;
	if (env->editor.creating_condition)
		panel = &env->editor.condition_panel.target_panel;
	else
		panel = &env->editor.event_panel.target_panel;
	panel->floor_type = 1;
	i = 0;
	while (i < 8)
	{
		panel->targets[i].state = UP;
		panel->targets[i].anim_state = REST;
		i++;
	}
	return (select_floor2(panel, env));
}

int		draw_floor_panel(t_env *env, t_target_panel *panel)
{
	draw_button(env, panel->targets[0], "Height");
	draw_button(env, panel->targets[1], "Texture");
	draw_button(env, panel->targets[2], "Slope");
	draw_button(env, panel->targets[3], "Align X");
	draw_button(env, panel->targets[4], "Align Y");
	draw_button(env, panel->targets[5], "Scale X");
	draw_button(env, panel->targets[6], "Scale Y");
	return (0);
}

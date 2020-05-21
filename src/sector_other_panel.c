/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sector_other_panel.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 13:09:54 by lnicosia          #+#    #+#             */
/*   Updated: 2020/03/11 13:27:02 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "events_parser.h"
#include "draw.h"
#include "events.h"
#include "parser.h"

int		set_sector_other_panel_buttons_state(t_target_panel *panel, int index)
{
	int		down;

	down = -1;
	if (index == SECTOR_BRIGHTNESS)
		down = 0;
	else if (index == SECTOR_LIGHT_COLOR)
		down = 1;
	else if (index == SECTOR_INTENSITY)
		down = 2;
	else if (index == SECTOR_GRAVITY)
		down = 3;
	if (down != -1)
	{
		panel->targets[down].state = DOWN;
		panel->selected_button = down;
	}
	return (0);
}

int		select_sector_other2(t_target_panel *panel, t_env *env)
{
	if (env->editor.creating_condition)
	{
		if (env->editor.condition_panel.condition.target)
			set_sector_other_panel_buttons_state(panel,
			env->editor.condition_panel.condition.target_index);
	}
	else
	{
		if (env->editor.event_panel.event.target)
			set_sector_other_panel_buttons_state(panel,
			env->editor.event_panel.event.target_index);
	}
	return (0);
}

int		select_sector_other(void *param)
{
	t_env			*env;
	t_target_panel	*panel;
	int				i;

	env = (t_env*)param;
	if (env->editor.creating_condition)
		panel = &env->editor.condition_panel.target_panel;
	else
		panel = &env->editor.event_panel.target_panel;
	panel->sector_other_type = 1;
	i = 0;
	while (i < 8)
	{
		panel->targets[i].state = UP;
		panel->targets[i].anim_state = REST;
		i++;
	}
	return (select_sector_other2(panel, env));
}

int		draw_sector_other_panel(t_env *env, t_target_panel *panel)
{
	if (draw_button(env, panel->targets[0], "Light brightness"))
		return (-1);
	if (draw_button(env, panel->targets[1], "Light color"))
		return (-1);
	if (draw_button(env, panel->targets[2], "Color intensity"))
		return (-1);
	if (draw_button(env, panel->targets[3], "Gravity"))
		return (-1);
	return (0);
}

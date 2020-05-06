/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ceiling_panel.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 13:09:54 by lnicosia          #+#    #+#             */
/*   Updated: 2020/03/11 13:28:09 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "events_parser.h"
#include "draw.h"

int		set_ceiling_panel_buttons_state(t_target_panel *panel, int index)
{
	int		down;

	down = -1;
	if (index == SECTOR_CEILING_HEIGHT)
		down = 0;
	else if (index == SECTOR_CEILING_TEXTURE)
		down = 1;
	else if (index == SECTOR_CEILING_SLOPE)
		down = 2;
	else if (index == SECTOR_CEILING_ALIGN_X)
		down = 3;
	else if (index == SECTOR_CEILING_ALIGN_Y)
		down = 4;
	else if (index == SECTOR_CEILING_SCALE_X)
		down = 5;
	else if (index == SECTOR_CEILING_SCALE_Y)
		down = 6;
	if (down != -1)
	{
		panel->targets[down].state = DOWN;
		panel->selected_button = down;
	}
	return (0);
}

int		select_ceiling2(t_target_panel *panel, t_env *env)
{
	if (env->editor.creating_condition)
	{
		if (env->editor.condition_panel.condition.target)
			set_ceiling_panel_buttons_state(panel,
			env->editor.condition_panel.condition.target_index);
	}
	else
	{
		if (env->editor.event_panel.event.target)
			set_ceiling_panel_buttons_state(panel,
			env->editor.event_panel.event.target_index);
	}
	return (0);
}

int		select_ceiling(void *param)
{
	t_env			*env;
	t_target_panel	*panel;
	int				i;

	env = (t_env*)param;
	if (env->editor.creating_condition)
		panel = &env->editor.condition_panel.target_panel;
	else
		panel = &env->editor.event_panel.target_panel;
	panel->ceiling_type = 1;
	i = 0;
	while (i < 8)
	{
		panel->targets[i].state = UP;
		panel->targets[i].anim_state = REST;
		i++;
	}
	select_ceiling2(panel, env);
	return (0);
}

int		draw_ceiling_panel(t_env *env, t_target_panel *panel)
{
	if (draw_button(env, panel->targets[0], "Height"))
		return (-1);
	if (draw_button(env, panel->targets[1], "Texture"))
		return (-1);
	if (draw_button(env, panel->targets[2], "Slope"))
		return (-1);
	if (draw_button(env, panel->targets[3], "Align X"))
		return (-1);
	if (draw_button(env, panel->targets[4], "Align Y"))
		return (-1);
	if (draw_button(env, panel->targets[5], "Scale X"))
		return (-1);
	if (draw_button(env, panel->targets[6], "Scale Y"))
		return (-1);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_panel.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 13:09:54 by lnicosia          #+#    #+#             */
/*   Updated: 2020/03/11 13:26:26 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "events_parser.h"
#include "draw.h"

int		set_wall_panel_buttons_state(t_target_panel *panel, int index)
{
	int		down;

	down = -1;
	if (index == SECTOR_WALL_TEXTURE)
		down = 0;
	else if (index == SECTOR_WALL_PORTAL)
		down = 1;
	else if (index == SECTOR_WALL_ALIGN_X)
		down = 2;
	else if (index == SECTOR_WALL_ALIGN_Y)
		down = 3;
	else if (index == SECTOR_WALL_SCALE_X)
		down = 4;
	else if (index == SECTOR_WALL_SCALE_Y)
		down = 5;
	if (down != -1)
	{
		panel->targets[down].state = DOWN;
		panel->selected_button = down;
	}
	return (0);
}

int		select_wall2(t_target_panel *panel, t_env *env)
{
	if (env->editor.creating_condition)
	{
		if (env->editor.condition_panel.condition.target)
			set_wall_panel_buttons_state(panel,
			env->editor.condition_panel.condition.target_index);
	}
	else
	{
		if (env->editor.event_panel.event.target)
			set_wall_panel_buttons_state(panel,
			env->editor.event_panel.event.target_index);
	}
	return (0);
}

int		select_wall(void *param)
{
	t_env			*env;
	t_target_panel	*panel;
	int				i;

	env = (t_env*)param;
	if (env->editor.creating_condition)
		panel = &env->editor.condition_panel.target_panel;
	else
		panel = &env->editor.event_panel.target_panel;
	panel->wall_type = 1;
	i = 0;
	while (i < 9)
	{
		panel->targets[i].state = UP;
		panel->targets[i].anim_state = REST;
		i++;
	}
	return (select_wall2(panel, env));
}

int		draw_wall_panel(t_env *env, t_target_panel *panel)
{
	if (draw_button(env, panel->targets[0], "Texture"))
		return (-1);
	if (draw_button(env, panel->targets[1], "Portal"))
		return (-1);
	if (draw_button(env, panel->targets[2], "Align X"))
		return (-1);
	if (draw_button(env, panel->targets[3], "Align Y"))
		return (-1);
	if (draw_button(env, panel->targets[4], "Scale X"))
		return (-1);
	if (draw_button(env, panel->targets[5], "Scale Y"))
		return (-1);
	return (0);
}

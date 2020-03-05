/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_panel.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 13:09:54 by lnicosia          #+#    #+#             */
/*   Updated: 2020/03/03 13:52:42 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "events_parser.h"

int		set_wall_panel_buttons_state(t_target_panel *panel, int index)
{
	int		down;

	down = 0;
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
	panel->targets[down].state = DOWN;
	panel->selected_button = down;
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

int		draw_wall_panel(t_env *env, t_target_panel *panel)
{
	draw_button(env, panel->targets[0], "Texture");
	draw_button(env, panel->targets[1], "Portal");
	draw_button(env, panel->targets[2], "Align X");
	draw_button(env, panel->targets[3], "Align Y");
	draw_button(env, panel->targets[4], "Scale X");
	draw_button(env, panel->targets[5], "Scale Y");
	return (0);
}

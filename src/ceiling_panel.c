/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ceiling_panel.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 13:09:54 by lnicosia          #+#    #+#             */
/*   Updated: 2020/02/17 16:21:46 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "events_parser.h"

int		set_ceiling_panel_buttons_state(t_target_panel *panel, int index)
{
	if (index == SECTOR_CEILING_HEIGHT)
		panel->targets[0].state = DOWN;
	else if (index == SECTOR_CEILING_TEXTURE)
		panel->targets[1].state = DOWN;
	else if (index == SECTOR_CEILING_SLOPE)
		panel->targets[2].state = DOWN;
	else if (index == SECTOR_CEILING_ALIGN_X)
		panel->targets[3].state = DOWN;
	else if (index == SECTOR_CEILING_ALIGN_Y)
		panel->targets[4].state = DOWN;
	else if (index == SECTOR_CEILING_SCALE_X)
		panel->targets[5].state = DOWN;
	else if (index == SECTOR_CEILING_SCALE_Y)
		panel->targets[6].state = DOWN;
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

int		draw_ceiling_panel(t_env *env, t_target_panel *panel)
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

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_sprite_panel.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 13:09:54 by lnicosia          #+#    #+#             */
/*   Updated: 2020/02/17 16:23:56 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "events_parser.h"

int		set_wall_sprite_panel_buttons_state2(t_target_panel *panel, int index)
{
	if (index == SECTOR_WALL_SPRITES_SCALE_X
		|| index == SECTOR_FLOOR_SPRITES_SCALE_X
		|| index == SECTOR_CEILING_SPRITES_SCALE_X)
		panel->targets[3].state = DOWN;
	else if (index == SECTOR_WALL_SPRITES_SCALE_Y
		|| index == SECTOR_FLOOR_SPRITES_SCALE_Y
		|| index == SECTOR_CEILING_SPRITES_SCALE_Y)
		panel->targets[4].state = DOWN;
	return (0);
}

int		set_wall_sprite_panel_buttons_state(t_target_panel *panel, int index)
{
	if (index == SECTOR_WALL_SPRITES_SPRITE
		|| index == SECTOR_FLOOR_SPRITES_SPRITE
		|| index == SECTOR_CEILING_SPRITES_SPRITE)
		panel->targets[0].state = DOWN;
	else if (index == SECTOR_WALL_SPRITES_POS_X
		|| index == SECTOR_FLOOR_SPRITES_POS_X
		|| index == SECTOR_CEILING_SPRITES_POS_X)
		panel->targets[1].state = DOWN;
	else if (index == SECTOR_WALL_SPRITES_POS_Y
		|| index == SECTOR_FLOOR_SPRITES_POS_Y
		|| index == SECTOR_CEILING_SPRITES_POS_Y)
		panel->targets[2].state = DOWN;
	return (set_wall_sprite_panel_buttons_state2(panel, index));
}

int		select_wall_sprite(void *param)
{
	t_env			*env;
	t_target_panel	*panel;
	int				i;

	env = (t_env*)param;
	if (env->editor.creating_condition)
		panel = &env->editor.condition_panel.target_panel;
	else
		panel = &env->editor.event_panel.target_panel;
	panel->wall_sprite_type = 1;
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
			set_wall_sprite_panel_buttons_state(panel,
			env->editor.condition_panel.condition.target_index);
	}
	else
	{
		if (env->editor.event_panel.event.target)
			set_wall_sprite_panel_buttons_state(panel,
			env->editor.event_panel.event.target_index);
	}
	return (0);
}

int		draw_wall_sprite_panel(t_env *env, t_target_panel *panel)
{
	draw_button(env, panel->targets[0], "Sprite");
	draw_button(env, panel->targets[1], "Pos X");
	draw_button(env, panel->targets[2], "Pos Y");
	draw_button(env, panel->targets[3], "Scale X");
	draw_button(env, panel->targets[4], "Scale Y");
	return (0);
}

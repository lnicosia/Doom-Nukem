/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_new_event_target3.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 13:31:28 by lnicosia          #+#    #+#             */
/*   Updated: 2020/02/11 13:52:12 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "events_parser.h"

int			set_wall_sprite2(t_env *env, t_event_panel *panel,
t_target_panel *target_panel, int wall)
{
	int	sector;
	int	sprite;

	sector = env->editor.selected_sector;
	sprite = env->selected_wall_sprite_sprite;
	if (target_panel->targets[3].state == DOWN)
	{
		panel->event.target =
		&env->sectors[sector].wall_sprites[wall].scale[sprite].x;
		panel->event.target_index = SECTOR_WALL_SPRITES_SCALE_X;
	}
	else if (target_panel->targets[4].state == DOWN)
	{
		panel->event.target =
		&env->sectors[sector].wall_sprites[wall].scale[sprite].y;
		panel->event.target_index = SECTOR_WALL_SPRITES_SCALE_Y;
	}
	return (0);
}

int			set_wall_sprite(t_env *env, t_event_panel *panel,
t_target_panel *target_panel, int wall)
{
	int	sector;
	int	sprite;

	sector = env->editor.selected_sector;
	sprite = env->selected_wall_sprite_sprite;
	if (target_panel->targets[0].state == DOWN)
	{
		panel->event.target =
		&env->sectors[sector].wall_sprites[wall].sprite[sprite];
		panel->event.target_index = SECTOR_WALL_SPRITES_SPRITE;
		panel->event.type = INT;
	}
	else if (target_panel->targets[1].state == DOWN)
	{
		panel->event.target =
		&env->sectors[sector].wall_sprites[wall].pos[sprite].x;
		panel->event.target_index = SECTOR_WALL_SPRITES_POS_X;
	}
	else if (target_panel->targets[2].state == DOWN)
	{
		panel->event.target =
		&env->sectors[sector].wall_sprites[wall].pos[sprite].y;
		panel->event.target_index = SECTOR_WALL_SPRITES_POS_Y;
	}
	return (set_wall_sprite2(env, panel, target_panel, wall));
}

int			select_wall_sprite_target(t_env *env, t_event_panel *panel,
t_target_panel *target_panel)
{
	if (env->selected_wall_sprite_wall != -1)
		return (set_wall_sprite(env, panel, target_panel,
		env->selected_wall_sprite_wall));
	else if (env->selected_floor != -1)
		return (set_floor_sprite(env, panel, target_panel,
		env->selected_floor));
	else if (env->selected_ceiling != -1)
		return (set_ceiling_sprite(env, panel, target_panel,
		env->selected_ceiling));
		return (0);
}

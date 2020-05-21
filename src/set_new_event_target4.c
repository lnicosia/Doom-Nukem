/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_new_event_target4.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 13:44:55 by lnicosia          #+#    #+#             */
/*   Updated: 2020/02/12 13:53:32 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "events_parser.h"
#include "events.h"
#include "parser.h"

int		set_floor_sprite2(t_env *env, t_event_panel *panel,
t_target_panel *target_panel, int sector)
{
	int		sprite;

	sprite = env->selected_floor_sprite;
	if (target_panel->selected_button == 3)
	{
		panel->event.target =
		&env->sectors[sector].floor_sprites.scale[sprite].x;
		panel->event.target_index = SECTOR_FLOOR_SPRITES_SCALE_X;
	}
	else if (target_panel->selected_button == 4)
	{
		panel->event.target =
		&env->sectors[sector].floor_sprites.scale[sprite].y;
		panel->event.target_index = SECTOR_FLOOR_SPRITES_SCALE_Y;
	}
	panel->event.update_param.sector = sector;
	panel->event.check_param.sector = sector;
	panel->event.update_param.sprite = sprite;
	panel->event.check_param.sprite = sprite;
	return (0);
}

int		set_floor_sprite(t_env *env, t_event_panel *panel,
t_target_panel *target_panel, int sector)
{
	int		sprite;

	sprite = env->selected_floor_sprite;
	if (target_panel->selected_button == 0)
	{
		panel->event.target =
		&env->sectors[sector].floor_sprites.sprite[sprite];
		panel->event.target_index = SECTOR_FLOOR_SPRITES_SPRITE;
		panel->event.type = INT;
	}
	else if (target_panel->selected_button == 1)
	{
		panel->event.target =
		&env->sectors[sector].floor_sprites.pos[sprite].x;
		panel->event.target_index = SECTOR_FLOOR_SPRITES_POS_X;
	}
	else if (target_panel->selected_button == 2)
	{
		panel->event.target =
		&env->sectors[sector].floor_sprites.pos[sprite].x;
		panel->event.target_index = SECTOR_FLOOR_SPRITES_POS_Y;
	}
	return (set_floor_sprite2(env, panel, target_panel, sector));
}

int		set_ceiling_sprite2(t_env *env, t_event_panel *panel,
t_target_panel *target_panel, int sector)
{
	int		sprite;

	sprite = env->selected_ceiling_sprite;
	if (target_panel->selected_button == 3)
	{
		panel->event.target =
		&env->sectors[sector].ceiling_sprites.scale[sprite].x;
		panel->event.target_index = SECTOR_CEILING_SPRITES_SCALE_X;
	}
	else if (target_panel->selected_button == 4)
	{
		panel->event.target =
		&env->sectors[sector].ceiling_sprites.scale[sprite].y;
		panel->event.target_index = SECTOR_CEILING_SPRITES_SCALE_Y;
	}
	panel->event.update_param.sector = sector;
	panel->event.check_param.sector = sector;
	panel->event.update_param.sprite = sprite;
	panel->event.check_param.sprite = sprite;
	return (0);
}

int		set_ceiling_sprite(t_env *env, t_event_panel *panel,
t_target_panel *target_panel, int sector)
{
	int		sprite;

	sprite = env->selected_ceiling_sprite;
	if (target_panel->selected_button == 0)
	{
		panel->event.target =
		&env->sectors[sector].ceiling_sprites.sprite[sprite];
		panel->event.target_index = SECTOR_CEILING_SPRITES_SPRITE;
		panel->event.type = INT;
	}
	else if (target_panel->selected_button == 1)
	{
		panel->event.target =
		&env->sectors[sector].ceiling_sprites.pos[sprite].x;
		panel->event.target_index = SECTOR_CEILING_SPRITES_POS_X;
	}
	else if (target_panel->selected_button == 2)
	{
		panel->event.target =
		&env->sectors[sector].ceiling_sprites.pos[sprite].x;
		panel->event.target_index = SECTOR_CEILING_SPRITES_POS_Y;
	}
	return (set_ceiling_sprite2(env, panel, target_panel, sector));
}

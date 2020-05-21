/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_new_condition_target4.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 13:44:55 by lnicosia          #+#    #+#             */
/*   Updated: 2020/02/18 15:03:42 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "events_parser.h"
#include "parser.h"
#include "events.h"

int		set_condition_floor_sprite2(t_env *env, t_condition_panel *panel,
t_target_panel *target_panel, int sector)
{
	int		sprite;

	sprite = env->selected_floor_sprite;
	if (target_panel->selected_button == 3)
	{
		panel->condition.target =
		&env->sectors[sector].floor_sprites.scale[sprite].x;
		panel->condition.target_index = SECTOR_FLOOR_SPRITES_SCALE_X;
	}
	else if (target_panel->selected_button == 4)
	{
		panel->condition.target =
		&env->sectors[sector].floor_sprites.scale[sprite].y;
		panel->condition.target_index = SECTOR_FLOOR_SPRITES_SCALE_Y;
	}
	panel->condition.sector = sector;
	panel->condition.sprite = sprite;
	return (0);
}

int		set_condition_floor_sprite(t_env *env, t_condition_panel *panel,
t_target_panel *target_panel, int sector)
{
	int		sprite;

	sprite = env->selected_floor_sprite;
	if (target_panel->selected_button == 0)
	{
		panel->condition.target =
		&env->sectors[sector].floor_sprites.sprite[sprite];
		panel->condition.target_index = SECTOR_FLOOR_SPRITES_SPRITE;
		panel->condition.target_type = INT;
	}
	else if (target_panel->selected_button == 1)
	{
		panel->condition.target =
		&env->sectors[sector].floor_sprites.pos[sprite].x;
		panel->condition.target_index = SECTOR_FLOOR_SPRITES_POS_X;
	}
	else if (target_panel->selected_button == 2)
	{
		panel->condition.target =
		&env->sectors[sector].floor_sprites.pos[sprite].x;
		panel->condition.target_index = SECTOR_FLOOR_SPRITES_POS_Y;
	}
	return (set_condition_floor_sprite2(env, panel, target_panel, sector));
}

int		set_condition_ceiling_sprite2(t_env *env, t_condition_panel *panel,
t_target_panel *target_panel, int sector)
{
	int		sprite;

	sprite = env->selected_ceiling_sprite;
	if (target_panel->selected_button == 3)
	{
		panel->condition.target =
		&env->sectors[sector].ceiling_sprites.scale[sprite].x;
		panel->condition.target_index = SECTOR_CEILING_SPRITES_SCALE_X;
	}
	else if (target_panel->selected_button == 4)
	{
		panel->condition.target =
		&env->sectors[sector].ceiling_sprites.scale[sprite].y;
		panel->condition.target_index = SECTOR_CEILING_SPRITES_SCALE_Y;
	}
	panel->condition.sector = sector;
	panel->condition.sprite = sprite;
	return (0);
}

int		set_condition_ceiling_sprite(t_env *env, t_condition_panel *panel,
t_target_panel *target_panel, int sector)
{
	int		sprite;

	sprite = env->selected_ceiling_sprite;
	if (target_panel->selected_button == 0)
	{
		panel->condition.target =
		&env->sectors[sector].ceiling_sprites.sprite[sprite];
		panel->condition.target_index = SECTOR_CEILING_SPRITES_SPRITE;
		panel->condition.target_type = INT;
	}
	else if (target_panel->selected_button == 1)
	{
		panel->condition.target =
		&env->sectors[sector].ceiling_sprites.pos[sprite].x;
		panel->condition.target_index = SECTOR_CEILING_SPRITES_POS_X;
	}
	else if (target_panel->selected_button == 2)
	{
		panel->condition.target =
		&env->sectors[sector].ceiling_sprites.pos[sprite].x;
		panel->condition.target_index = SECTOR_CEILING_SPRITES_POS_Y;
	}
	return (set_condition_ceiling_sprite2(env, panel, target_panel, sector));
}

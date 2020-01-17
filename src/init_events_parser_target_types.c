/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_events_parser_target_types.c                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 08:49:32 by lnicosia          #+#    #+#             */
/*   Updated: 2020/01/17 17:57:32 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "events_parser.h"

void	init_events_parser_target_types3(t_events_parser *eparser)
{
	eparser->target_types[PLAYER_SPEED] = DOUBLE;
	eparser->target_types[PLAYER_INVINCIBLE] = INT;
	eparser->target_types[PLAYER_INFINITE_AMMO] = INT;
	eparser->target_types[PLAYER_SECTOR] = INT;
	eparser->target_types[WEAPON_DAMAGE] = INT;
	eparser->target_types[WEAPON_RANGE] = INT;
	eparser->target_types[ENEMY_SPRITE] = INT;
	eparser->target_types[ENEMY_SCALE] = DOUBLE;
	eparser->target_types[ENEMY_DAMAGE] = INT;
	eparser->target_types[ENEMY_HP] = INT;
	eparser->target_types[ENEMY_SPEED] = DOUBLE;
	eparser->target_types[ENEMY_X] = DOUBLE;
	eparser->target_types[ENEMY_Y] = DOUBLE;
	eparser->target_types[ENEMY_Z] = DOUBLE;
	eparser->target_types[OBJECT_SPRITE] = INT;
	eparser->target_types[OBJECT_SCALE] = DOUBLE;
	eparser->target_types[OBJECT_DAMAGE] = INT;
	eparser->target_types[OBJECT_HP] = INT;
	eparser->target_types[OBJECT_SPEED] = DOUBLE;
	eparser->target_types[OBJECT_X] = DOUBLE;
	eparser->target_types[OBJECT_Y] = DOUBLE;
	eparser->target_types[OBJECT_Z] = DOUBLE;
}

void	init_events_parser_target_types2(t_events_parser *eparser)
{
	eparser->target_types[SECTOR_FLOOR_SPRITES_SPRITE] = INT;
	eparser->target_types[SECTOR_FLOOR_SPRITES_POS_X] = DOUBLE;
	eparser->target_types[SECTOR_FLOOR_SPRITES_POS_Y] = DOUBLE;
	eparser->target_types[SECTOR_FLOOR_SPRITES_SCALE_X] = DOUBLE;
	eparser->target_types[SECTOR_FLOOR_SPRITES_SCALE_Y] = DOUBLE;
	eparser->target_types[SECTOR_CEILING_SPRITES_SPRITE] = DOUBLE;
	eparser->target_types[SECTOR_CEILING_SPRITES_POS_X] = DOUBLE;
	eparser->target_types[SECTOR_CEILING_SPRITES_POS_Y] = DOUBLE;
	eparser->target_types[SECTOR_CEILING_SPRITES_SCALE_X] = DOUBLE;
	eparser->target_types[SECTOR_CEILING_SPRITES_SCALE_Y] = DOUBLE;
	eparser->target_types[SECTOR_BRIGHTNESS] = INT;
	eparser->target_types[SECTOR_LIGHT_COLOR] = UINT32;
	eparser->target_types[SECTOR_INTENSITY] = INT;
	eparser->target_types[SECTOR_GRAVITY] = DOUBLE;
	eparser->target_types[VERTEX_X] = DOUBLE;
	eparser->target_types[VERTEX_Y] = DOUBLE;
	eparser->target_types[PLAYER_X] = DOUBLE;
	eparser->target_types[PLAYER_Y] = DOUBLE;
	eparser->target_types[PLAYER_Z] = DOUBLE;
	eparser->target_types[PLAYER_HP] = INT;
	eparser->target_types[PLAYER_ARMOR] = INT;
	init_events_parser_target_types3(eparser);
}

void	init_events_parser_target_types(t_events_parser *eparser)
{
	eparser->target_types[SECTOR_FLOOR_HEIGHT] = DOUBLE;
	eparser->target_types[SECTOR_FLOOR_SLOPE] = DOUBLE;
	eparser->target_types[SECTOR_FLOOR_TEXTURE] = INT;
	eparser->target_types[SECTOR_FLOOR_ALIGN_X] = DOUBLE;
	eparser->target_types[SECTOR_FLOOR_ALIGN_Y] = DOUBLE;
	eparser->target_types[SECTOR_FLOOR_SCALE_X] = DOUBLE;
	eparser->target_types[SECTOR_FLOOR_SCALE_Y] = DOUBLE;
	eparser->target_types[SECTOR_CEILING_HEIGHT] = DOUBLE;
	eparser->target_types[SECTOR_CEILING_SLOPE] = DOUBLE;
	eparser->target_types[SECTOR_CEILING_TEXTURE] = INT;
	eparser->target_types[SECTOR_CEILING_ALIGN_X] = DOUBLE;
	eparser->target_types[SECTOR_CEILING_ALIGN_Y] = DOUBLE;
	eparser->target_types[SECTOR_CEILING_SCALE_X] = DOUBLE;
	eparser->target_types[SECTOR_CEILING_SCALE_Y] = DOUBLE;
	eparser->target_types[SECTOR_WALL_TEXTURE] = INT;
	eparser->target_types[SECTOR_WALL_ALIGN_X] = DOUBLE;
	eparser->target_types[SECTOR_WALL_ALIGN_Y] = DOUBLE;
	eparser->target_types[SECTOR_WALL_SCALE_X] = DOUBLE;
	eparser->target_types[SECTOR_WALL_SCALE_Y] = DOUBLE;
	eparser->target_types[SECTOR_WALL_SPRITES_SPRITE] = INT;
	eparser->target_types[SECTOR_WALL_SPRITES_POS_X] = DOUBLE;
	eparser->target_types[SECTOR_WALL_SPRITES_POS_Y] = DOUBLE;
	eparser->target_types[SECTOR_WALL_SPRITES_SCALE_X] = DOUBLE;
	eparser->target_types[SECTOR_WALL_SPRITES_SCALE_Y] = DOUBLE;
	init_events_parser_target_types2(eparser);
}

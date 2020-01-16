/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_events_parser_target_types.c                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 08:49:32 by lnicosia          #+#    #+#             */
/*   Updated: 2020/01/16 16:06:26 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "events_parser.h"

void	init_events_parser_target_types3(t_events_parser *eparser)
{
	eparser->target_types[PLAYER_SPEED] = INT;
	eparser->target_types[PLAYER_INVINCIBLE] = INT;
	eparser->target_types[PLAYER_INFINITE_AMMO] = INT;
	eparser->target_types[PLAYER_SECTOR] = INT;
	eparser->target_types[WEAPON_DAMAGE] = INT;
	eparser->target_types[WEAPON_RANGE] = INT;
	eparser->target_types[ENEMY_SPRITE] = INT;
	eparser->target_types[ENEMY_SCALE] = INT;
	eparser->target_types[ENEMY_DAMAGE] = INT;
	eparser->target_types[ENEMY_HP] = INT;
	eparser->target_types[ENEMY_SPEED] = INT;
	eparser->target_types[ENEMY_X] = INT;
	eparser->target_types[ENEMY_Y] = INT;
	eparser->target_types[ENEMY_Z] = INT;
	eparser->target_types[OBJECT_SPRITE] = INT;
	eparser->target_types[OBJECT_SCALE] = INT;
	eparser->target_types[OBJECT_DAMAGE] = INT;
	eparser->target_types[OBJECT_HP] = INT;
	eparser->target_types[OBJECT_SPEED] = INT;
	eparser->target_types[OBJECT_X] = INT;
	eparser->target_types[OBJECT_Y] = INT;
	eparser->target_types[OBJECT_Z] = INT;
}

void	init_events_parser_target_types2(t_events_parser *eparser)
{
	eparser->target_types[SECTOR_FLOOR_SPRITES_SPRITE] = INT;
	eparser->target_types[SECTOR_FLOOR_SPRITES_POS_X] = INT;
	eparser->target_types[SECTOR_FLOOR_SPRITES_POS_Y] = INT;
	eparser->target_types[SECTOR_FLOOR_SPRITES_SCALE_X] = INT;
	eparser->target_types[SECTOR_FLOOR_SPRITES_SCALE_Y] = INT;
	eparser->target_types[SECTOR_CEILING_SPRITES_SPRITE] = INT;
	eparser->target_types[SECTOR_CEILING_SPRITES_POS_X] = INT;
	eparser->target_types[SECTOR_CEILING_SPRITES_POS_Y] = INT;
	eparser->target_types[SECTOR_CEILING_SPRITES_SCALE_X] = INT;
	eparser->target_types[SECTOR_CEILING_SPRITES_SCALE_Y] = INT;
	eparser->target_types[SECTOR_BRIGHTNESS] = INT;
	eparser->target_types[SECTOR_LIGHT_COLOR] = INT;
	eparser->target_types[SECTOR_INTENSITY] = INT;
	eparser->target_types[SECTOR_GRAVITY] = INT;
	eparser->target_types[VERTEX_X] = INT;
	eparser->target_types[VERTEX_Y] = INT;
	eparser->target_types[PLAYER_X] = INT;
	eparser->target_types[PLAYER_Y] = INT;
	eparser->target_types[PLAYER_Z] = INT;
	eparser->target_types[PLAYER_HP] = INT;
	eparser->target_types[PLAYER_ARMOR] = INT;
	init_events_parser_target_types3(eparser);
}

void	init_events_parser_target_types(t_events_parser *eparser)
{
	eparser->target_types[SECTOR_FLOOR_HEIGHT] = INT;
	eparser->target_types[SECTOR_FLOOR_SLOPE] = INT;
	eparser->target_types[SECTOR_FLOOR_TEXTURE] = INT;
	eparser->target_types[SECTOR_FLOOR_ALIGN_X] = INT;
	eparser->target_types[SECTOR_FLOOR_ALIGN_Y] = INT;
	eparser->target_types[SECTOR_FLOOR_SCALE_X] = INT;
	eparser->target_types[SECTOR_FLOOR_SCALE_Y] = INT;
	eparser->target_types[SECTOR_CEILING_HEIGHT] = INT;
	eparser->target_types[SECTOR_CEILING_SLOPE] = INT;
	eparser->target_types[SECTOR_CEILING_TEXTURE] = INT;
	eparser->target_types[SECTOR_CEILING_ALIGN_X] = INT;
	eparser->target_types[SECTOR_CEILING_ALIGN_Y] = INT;
	eparser->target_types[SECTOR_CEILING_SCALE_X] = INT;
	eparser->target_types[SECTOR_CEILING_SCALE_Y] = INT;
	eparser->target_types[SECTOR_WALL_TEXTURE] = INT;
	eparser->target_types[SECTOR_WALL_ALIGN_X] = INT;
	eparser->target_types[SECTOR_WALL_ALIGN_Y] = INT;
	eparser->target_types[SECTOR_WALL_SCALE_X] = INT;
	eparser->target_types[SECTOR_WALL_SCALE_Y] = INT;
	eparser->target_types[SECTOR_WALL_SPRITES_SPRITE] = INT;
	eparser->target_types[SECTOR_WALL_SPRITES_POS_X] = INT;
	eparser->target_types[SECTOR_WALL_SPRITES_POS_Y] = INT;
	eparser->target_types[SECTOR_WALL_SPRITES_SCALE_X] = INT;
	eparser->target_types[SECTOR_WALL_SPRITES_SCALE_Y] = INT;
	init_events_parser_target_types2(eparser);
}

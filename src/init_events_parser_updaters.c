/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_events_parser_updaters.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 08:49:32 by lnicosia          #+#    #+#             */
/*   Updated: 2020/01/16 17:56:28 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "events_parser.h"

void	init_events_parser_updaters3(t_events_parser *eparser)
{
	eparser->updaters[PLAYER_SPEED] = 0;
	eparser->updaters[PLAYER_INVINCIBLE] = 0;
	eparser->updaters[PLAYER_INFINITE_AMMO] = 0;
	eparser->updaters[PLAYER_SECTOR] = 0;
	eparser->updaters[WEAPON_DAMAGE] = 0;
	eparser->updaters[WEAPON_RANGE] = 0;
	eparser->updaters[ENEMY_SPRITE] = 0;
	eparser->updaters[ENEMY_SCALE] = 0;
	eparser->updaters[ENEMY_DAMAGE] = 0;
	eparser->updaters[ENEMY_HP] = 0;
	eparser->updaters[ENEMY_SPEED] = 0;
	eparser->updaters[ENEMY_X] = 0;
	eparser->updaters[ENEMY_Y] = 0;
	eparser->updaters[ENEMY_Z] = 0;
	eparser->updaters[OBJECT_SPRITE] = 0;
	eparser->updaters[OBJECT_SCALE] = 0;
	eparser->updaters[OBJECT_DAMAGE] = 0;
	eparser->updaters[OBJECT_HP] = 0;
	eparser->updaters[OBJECT_SPEED] = 0;
	eparser->updaters[OBJECT_X] = 0;
	eparser->updaters[OBJECT_Y] = 0;
	eparser->updaters[OBJECT_Z] = 0;
}

void	init_events_parser_updaters2(t_events_parser *eparser)
{
	eparser->updaters[SECTOR_FLOOR_SPRITES_SPRITE] = 0;
	eparser->updaters[SECTOR_FLOOR_SPRITES_POS_X] = 0;
	eparser->updaters[SECTOR_FLOOR_SPRITES_POS_Y] = 0;
	eparser->updaters[SECTOR_FLOOR_SPRITES_SCALE_X] = 0;
	eparser->updaters[SECTOR_FLOOR_SPRITES_SCALE_Y] = 0;
	eparser->updaters[SECTOR_CEILING_SPRITES_SPRITE] = 0;
	eparser->updaters[SECTOR_CEILING_SPRITES_POS_X] = 0;
	eparser->updaters[SECTOR_CEILING_SPRITES_POS_Y] = 0;
	eparser->updaters[SECTOR_CEILING_SPRITES_SCALE_X] = 0;
	eparser->updaters[SECTOR_CEILING_SPRITES_SCALE_Y] = 0;
	eparser->updaters[SECTOR_BRIGHTNESS] = 0;
	eparser->updaters[SECTOR_LIGHT_COLOR] = 0;
	eparser->updaters[SECTOR_INTENSITY] = 0;
	eparser->updaters[SECTOR_GRAVITY] = 0;
	eparser->updaters[VERTEX_X] = 0;
	eparser->updaters[VERTEX_Y] = 0;
	eparser->updaters[PLAYER_X] = 0;
	eparser->updaters[PLAYER_Y] = 0;
	eparser->updaters[PLAYER_Z] = 0;
	eparser->updaters[PLAYER_HP] = 0;
	eparser->updaters[PLAYER_ARMOR] = 0;
	init_events_parser_updaters3(eparser);
}

void	init_events_parser_updaters(t_events_parser *eparser)
{
	eparser->updaters[SECTOR_FLOOR_HEIGHT] = 0;
	eparser->updaters[SECTOR_FLOOR_SLOPE] = 0;
	eparser->updaters[SECTOR_FLOOR_TEXTURE] = 0;
	eparser->updaters[SECTOR_FLOOR_ALIGN_X] = 0;
	eparser->updaters[SECTOR_FLOOR_ALIGN_Y] = 0;
	eparser->updaters[SECTOR_FLOOR_SCALE_X] = 0;
	eparser->updaters[SECTOR_FLOOR_SCALE_Y] = 0;
	eparser->updaters[SECTOR_CEILING_HEIGHT] = 0;
	eparser->updaters[SECTOR_CEILING_SLOPE] = 0;
	eparser->updaters[SECTOR_CEILING_TEXTURE] = 0;
	eparser->updaters[SECTOR_CEILING_ALIGN_X] = 0;
	eparser->updaters[SECTOR_CEILING_ALIGN_Y] = 0;
	eparser->updaters[SECTOR_CEILING_SCALE_X] = 0;
	eparser->updaters[SECTOR_CEILING_SCALE_Y] = 0;
	eparser->updaters[SECTOR_WALL_TEXTURE] = 0;
	eparser->updaters[SECTOR_WALL_ALIGN_X] = 0;
	eparser->updaters[SECTOR_WALL_ALIGN_Y] = 0;
	eparser->updaters[SECTOR_WALL_SCALE_X] = 0;
	eparser->updaters[SECTOR_WALL_SCALE_Y] = 0;
	eparser->updaters[SECTOR_WALL_SPRITES_SPRITE] = 0;
	eparser->updaters[SECTOR_WALL_SPRITES_POS_X] = 0;
	eparser->updaters[SECTOR_WALL_SPRITES_POS_Y] = 0;
	eparser->updaters[SECTOR_WALL_SPRITES_SCALE_X] = 0;
	eparser->updaters[SECTOR_WALL_SPRITES_SCALE_Y] = 0;
	init_events_parser_updaters2(eparser);
}
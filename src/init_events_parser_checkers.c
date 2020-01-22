/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_events_parser_checkers.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 08:49:32 by lnicosia          #+#    #+#             */
/*   Updated: 2020/01/16 17:56:07 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "events_parser.h"

void	init_events_parser_checkers3(t_events_parser *eparser)
{
	eparser->checkers[PLAYER_SPEED] = 0;
	eparser->checkers[PLAYER_INVINCIBLE] = 0;
	eparser->checkers[PLAYER_INFINITE_AMMO] = 0;
	eparser->checkers[PLAYER_SECTOR] = 0;
	eparser->checkers[WEAPON_DAMAGE] = 0;
	eparser->checkers[WEAPON_RANGE] = 0;
	eparser->checkers[ENEMY_SPRITE] = 0;
	eparser->checkers[ENEMY_SCALE] = 0;
	eparser->checkers[ENEMY_DAMAGE] = 0;
	eparser->checkers[ENEMY_HP] = 0;
	eparser->checkers[ENEMY_SPEED] = 0;
	eparser->checkers[ENEMY_X] = 0;
	eparser->checkers[ENEMY_Y] = 0;
	eparser->checkers[ENEMY_Z] = 0;
	eparser->checkers[OBJECT_SPRITE] = 0;
	eparser->checkers[OBJECT_SCALE] = 0;
	eparser->checkers[OBJECT_DAMAGE] = 0;
	eparser->checkers[OBJECT_HP] = 0;
	eparser->checkers[OBJECT_SPEED] = 0;
	eparser->checkers[OBJECT_X] = 0;
	eparser->checkers[OBJECT_Y] = 0;
	eparser->checkers[OBJECT_Z] = 0;
}

void	init_events_parser_checkers2(t_events_parser *eparser)
{
	eparser->checkers[SECTOR_FLOOR_SPRITES_SPRITE] = 0;
	eparser->checkers[SECTOR_FLOOR_SPRITES_POS_X] = 0;
	eparser->checkers[SECTOR_FLOOR_SPRITES_POS_Y] = 0;
	eparser->checkers[SECTOR_FLOOR_SPRITES_SCALE_X] = 0;
	eparser->checkers[SECTOR_FLOOR_SPRITES_SCALE_Y] = 0;
	eparser->checkers[SECTOR_CEILING_SPRITES_SPRITE] = 0;
	eparser->checkers[SECTOR_CEILING_SPRITES_POS_X] = 0;
	eparser->checkers[SECTOR_CEILING_SPRITES_POS_Y] = 0;
	eparser->checkers[SECTOR_CEILING_SPRITES_SCALE_X] = 0;
	eparser->checkers[SECTOR_CEILING_SPRITES_SCALE_Y] = 0;
	eparser->checkers[SECTOR_BRIGHTNESS] = 0;
	eparser->checkers[SECTOR_LIGHT_COLOR] = 0;
	eparser->checkers[SECTOR_INTENSITY] = 0;
	eparser->checkers[SECTOR_GRAVITY] = 0;
	eparser->checkers[VERTEX_X] = 0;
	eparser->checkers[VERTEX_Y] = 0;
	eparser->checkers[PLAYER_X] = 0;
	eparser->checkers[PLAYER_Y] = 0;
	eparser->checkers[PLAYER_Z] = 0;
	eparser->checkers[PLAYER_HP] = 0;
	eparser->checkers[PLAYER_ARMOR] = 0;
	init_events_parser_checkers3(eparser);
}

void	init_events_parser_checkers(t_events_parser *eparser)
{
	eparser->checkers[SECTOR_FLOOR_HEIGHT] = 0;
	eparser->checkers[SECTOR_FLOOR_SLOPE] = 0;
	eparser->checkers[SECTOR_FLOOR_TEXTURE] = 0;
	eparser->checkers[SECTOR_FLOOR_ALIGN_X] = 0;
	eparser->checkers[SECTOR_FLOOR_ALIGN_Y] = 0;
	eparser->checkers[SECTOR_FLOOR_SCALE_X] = 0;
	eparser->checkers[SECTOR_FLOOR_SCALE_Y] = 0;
	eparser->checkers[SECTOR_CEILING_HEIGHT] = 0;
	eparser->checkers[SECTOR_CEILING_SLOPE] = 0;
	eparser->checkers[SECTOR_CEILING_TEXTURE] = 0;
	eparser->checkers[SECTOR_CEILING_ALIGN_X] = 0;
	eparser->checkers[SECTOR_CEILING_ALIGN_Y] = 0;
	eparser->checkers[SECTOR_CEILING_SCALE_X] = 0;
	eparser->checkers[SECTOR_CEILING_SCALE_Y] = 0;
	eparser->checkers[SECTOR_WALL_TEXTURE] = 0;
	eparser->checkers[SECTOR_WALL_ALIGN_X] = 0;
	eparser->checkers[SECTOR_WALL_ALIGN_Y] = 0;
	eparser->checkers[SECTOR_WALL_SCALE_X] = 0;
	eparser->checkers[SECTOR_WALL_SCALE_Y] = 0;
	eparser->checkers[SECTOR_WALL_SPRITES_SPRITE] = 0;
	eparser->checkers[SECTOR_WALL_SPRITES_POS_X] = 0;
	eparser->checkers[SECTOR_WALL_SPRITES_POS_Y] = 0;
	eparser->checkers[SECTOR_WALL_SPRITES_SCALE_X] = 0;
	eparser->checkers[SECTOR_WALL_SPRITES_SCALE_Y] = 0;
	init_events_parser_checkers2(eparser);
}

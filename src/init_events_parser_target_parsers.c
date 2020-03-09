/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_events_parser_target_parsers.c                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 08:49:32 by lnicosia          #+#    #+#             */
/*   Updated: 2020/03/09 14:34:42 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "events_parser.h"

void	init_events_parser_target_parsers3(t_events_parser *eparser)
{
	eparser->target_parsers[PLAYER_SPEED] = &no_parser;
	eparser->target_parsers[PLAYER_INVINCIBLE] = &no_parser;
	eparser->target_parsers[PLAYER_INFINITE_AMMO] = &no_parser;
	eparser->target_parsers[PLAYER_SECTOR] = &no_parser;
	eparser->target_parsers[WEAPON_DAMAGE] = &weapon_parser;
	eparser->target_parsers[WEAPON_RANGE] = &weapon_parser;
	eparser->target_parsers[ENEMY_SPRITE] = &enemy_parser;
	eparser->target_parsers[ENEMY_SCALE] = &enemy_parser;
	eparser->target_parsers[ENEMY_DAMAGE] = &enemy_parser;
	eparser->target_parsers[ENEMY_HP] = &enemy_parser;
	eparser->target_parsers[ENEMY_SPEED] = &enemy_parser;
	eparser->target_parsers[ENEMY_X] = &enemy_parser;
	eparser->target_parsers[ENEMY_Y] = &enemy_parser;
	eparser->target_parsers[ENEMY_Z] = &enemy_parser;
	eparser->target_parsers[OBJECT_SPRITE] = &object_parser;
	eparser->target_parsers[OBJECT_SCALE] = &object_parser;
	eparser->target_parsers[OBJECT_DAMAGE] = &object_parser;
	eparser->target_parsers[OBJECT_HP] = &object_parser;
	eparser->target_parsers[OBJECT_X] = &object_parser;
	eparser->target_parsers[OBJECT_Y] = &object_parser;
	eparser->target_parsers[OBJECT_Z] = &object_parser;
	eparser->target_parsers[WIN] = &no_parser;
	eparser->target_parsers[DIALOG] = &dialog_parser;
}

void	init_events_parser_target_parsers2(t_events_parser *eparser)
{
	eparser->target_parsers[SECTOR_FLOOR_SPRITES_SPRITE] = &floor_sprite_parser;
	eparser->target_parsers[SECTOR_FLOOR_SPRITES_POS_X] = &floor_sprite_parser;
	eparser->target_parsers[SECTOR_FLOOR_SPRITES_POS_Y] = &floor_sprite_parser;
	eparser->target_parsers[SECTOR_FLOOR_SPRITES_SCALE_X] =
	&floor_sprite_parser;
	eparser->target_parsers[SECTOR_FLOOR_SPRITES_SCALE_Y] =
	&floor_sprite_parser;
	eparser->target_parsers[SECTOR_CEILING_SPRITES_SPRITE] =
	&ceiling_sprite_parser;
	eparser->target_parsers[SECTOR_CEILING_SPRITES_POS_X] =
	&ceiling_sprite_parser;
	eparser->target_parsers[SECTOR_CEILING_SPRITES_POS_Y] =
	&ceiling_sprite_parser;
	eparser->target_parsers[SECTOR_CEILING_SPRITES_SCALE_X] =
	&ceiling_sprite_parser;
	eparser->target_parsers[SECTOR_CEILING_SPRITES_SCALE_Y] =
	&ceiling_sprite_parser;
	eparser->target_parsers[SECTOR_BRIGHTNESS] = &sector_parser;
	eparser->target_parsers[SECTOR_LIGHT_COLOR] = &sector_parser;
	eparser->target_parsers[SECTOR_INTENSITY] = &sector_parser;
	eparser->target_parsers[SECTOR_GRAVITY] = &sector_parser;
	eparser->target_parsers[VERTEX_X] = &vertex_parser;
	eparser->target_parsers[VERTEX_Y] = &vertex_parser;
	eparser->target_parsers[PLAYER_X] = &no_parser;
	eparser->target_parsers[PLAYER_Y] = &no_parser;
	eparser->target_parsers[PLAYER_Z] = &no_parser;
	eparser->target_parsers[PLAYER_HP] = &no_parser;
	eparser->target_parsers[PLAYER_ARMOR] = &no_parser;
	init_events_parser_target_parsers3(eparser);
}

void	init_events_parser_target_parsers(t_events_parser *eparser)
{
	eparser->target_parsers[SECTOR_FLOOR_HEIGHT] = &sector_parser;
	eparser->target_parsers[SECTOR_FLOOR_SLOPE] = &sector_parser;
	eparser->target_parsers[SECTOR_FLOOR_TEXTURE] = &sector_parser;
	eparser->target_parsers[SECTOR_FLOOR_ALIGN_X] = &sector_parser;
	eparser->target_parsers[SECTOR_FLOOR_ALIGN_Y] = &sector_parser;
	eparser->target_parsers[SECTOR_FLOOR_SCALE_X] = &sector_parser;
	eparser->target_parsers[SECTOR_FLOOR_SCALE_Y] = &sector_parser;
	eparser->target_parsers[SECTOR_CEILING_HEIGHT] = &sector_parser;
	eparser->target_parsers[SECTOR_CEILING_SLOPE] = &sector_parser;
	eparser->target_parsers[SECTOR_CEILING_TEXTURE] = &sector_parser;
	eparser->target_parsers[SECTOR_CEILING_ALIGN_X] = &sector_parser;
	eparser->target_parsers[SECTOR_CEILING_ALIGN_Y] = &sector_parser;
	eparser->target_parsers[SECTOR_CEILING_SCALE_X] = &sector_parser;
	eparser->target_parsers[SECTOR_CEILING_SCALE_Y] = &sector_parser;
	eparser->target_parsers[SECTOR_WALL_TEXTURE] = &wall_parser;
	eparser->target_parsers[SECTOR_WALL_ALIGN_X] = &wall_parser;
	eparser->target_parsers[SECTOR_WALL_ALIGN_Y] = &wall_parser;
	eparser->target_parsers[SECTOR_WALL_SCALE_X] = &wall_parser;
	eparser->target_parsers[SECTOR_WALL_SCALE_Y] = &wall_parser;
	eparser->target_parsers[SECTOR_WALL_PORTAL] = &wall_parser;
	eparser->target_parsers[SECTOR_WALL_SPRITES_SPRITE] = &wall_sprite_parser;
	eparser->target_parsers[SECTOR_WALL_SPRITES_POS_X] = &wall_sprite_parser;
	eparser->target_parsers[SECTOR_WALL_SPRITES_POS_Y] = &wall_sprite_parser;
	eparser->target_parsers[SECTOR_WALL_SPRITES_SCALE_X] = &wall_sprite_parser;
	eparser->target_parsers[SECTOR_WALL_SPRITES_SCALE_Y] = &wall_sprite_parser;
	init_events_parser_target_parsers2(eparser);
}

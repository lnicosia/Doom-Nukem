/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_events_parser_updaters.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 08:49:32 by lnicosia          #+#    #+#             */
/*   Updated: 2020/01/28 11:05:42 by lnicosia         ###   ########.fr       */
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
	eparser->updaters[ENEMY_X] = &update_enemy_sector_event;
	eparser->updaters[ENEMY_Y] = &update_enemy_sector_event;
	eparser->updaters[ENEMY_Z] = &update_enemy_sector_event;
	eparser->updaters[OBJECT_SPRITE] = 0;
	eparser->updaters[OBJECT_SCALE] = 0;
	eparser->updaters[OBJECT_DAMAGE] = 0;
	eparser->updaters[OBJECT_HP] = 0;
	eparser->updaters[OBJECT_X] = &update_object_sector_event;
	eparser->updaters[OBJECT_Y] = &update_object_sector_event;
	eparser->updaters[OBJECT_Z] = &update_object_sector_event;
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
	eparser->updaters[SECTOR_BRIGHTNESS] = &update_sector_entities_event;
	eparser->updaters[SECTOR_LIGHT_COLOR] = &update_sector_entities_event;
	eparser->updaters[SECTOR_INTENSITY] = &update_sector_entities_event;
	eparser->updaters[SECTOR_GRAVITY] = 0;
	eparser->updaters[VERTEX_X] = &update_vertex_event;
	eparser->updaters[VERTEX_Y] = &update_vertex_event;
	eparser->updaters[PLAYER_X] = &update_player_z_event;
	eparser->updaters[PLAYER_Y] = &update_player_z_event;
	eparser->updaters[PLAYER_Z] = &update_player_z_event;
	eparser->updaters[PLAYER_HP] = 0;
	eparser->updaters[PLAYER_ARMOR] = 0;
	init_events_parser_updaters3(eparser);
}

void	init_events_parser_updaters(t_events_parser *eparser)
{
	eparser->updaters[SECTOR_FLOOR_HEIGHT] = &update_sector_event;
	eparser->updaters[SECTOR_FLOOR_SLOPE] = &update_sector_event;
	eparser->updaters[SECTOR_FLOOR_TEXTURE] = &update_floor_texture_event;
	eparser->updaters[SECTOR_FLOOR_ALIGN_X] = &update_floor_texture_event;
	eparser->updaters[SECTOR_FLOOR_ALIGN_Y] = &update_floor_texture_event;
	eparser->updaters[SECTOR_FLOOR_SCALE_X] = &update_floor_texture_event;
	eparser->updaters[SECTOR_FLOOR_SCALE_Y] = &update_floor_texture_event;
	eparser->updaters[SECTOR_CEILING_HEIGHT] = &update_ceiling_texture_event;
	eparser->updaters[SECTOR_CEILING_SLOPE] = &update_ceiling_texture_event;
	eparser->updaters[SECTOR_CEILING_TEXTURE] = &update_ceiling_texture_event;
	eparser->updaters[SECTOR_CEILING_ALIGN_X] = &update_ceiling_texture_event;
	eparser->updaters[SECTOR_CEILING_ALIGN_Y] = &update_ceiling_texture_event;
	eparser->updaters[SECTOR_CEILING_SCALE_X] = &update_ceiling_texture_event;
	eparser->updaters[SECTOR_CEILING_SCALE_Y] = &update_ceiling_texture_event;
	eparser->updaters[SECTOR_WALL_TEXTURE] = &update_wall_texture_event;
	eparser->updaters[SECTOR_WALL_ALIGN_X] = &update_wall_texture_event;
	eparser->updaters[SECTOR_WALL_ALIGN_Y] = &update_wall_texture_event;
	eparser->updaters[SECTOR_WALL_SCALE_X] = &update_wall_texture_event;
	eparser->updaters[SECTOR_WALL_SCALE_Y] = &update_wall_texture_event;
	eparser->updaters[SECTOR_WALL_SPRITES_SPRITE] = 0;
	eparser->updaters[SECTOR_WALL_SPRITES_POS_X] = 0;
	eparser->updaters[SECTOR_WALL_SPRITES_POS_Y] = 0;
	eparser->updaters[SECTOR_WALL_SPRITES_SCALE_X] = 0;
	eparser->updaters[SECTOR_WALL_SPRITES_SCALE_Y] = 0;
	init_events_parser_updaters2(eparser);
}

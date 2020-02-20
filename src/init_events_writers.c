/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_events_writers.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 08:49:32 by lnicosia          #+#    #+#             */
/*   Updated: 2020/02/20 14:47:51 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "events_parser.h"

void	init_events_writers3(void (*writers[])(int, t_event))
{
	writers[PLAYER_SPEED] = &no_writer;
	writers[PLAYER_INVINCIBLE] = &no_writer;
	writers[PLAYER_INFINITE_AMMO] = &no_writer;
	writers[PLAYER_SECTOR] = &no_writer;
	writers[WEAPON_DAMAGE] = &weapon_writer;
	writers[WEAPON_RANGE] = &weapon_writer;
	writers[ENEMY_SPRITE] = &enemy_writer;
	writers[ENEMY_SCALE] = &enemy_writer;
	writers[ENEMY_DAMAGE] = &enemy_writer;
	writers[ENEMY_HP] = &enemy_writer;
	writers[ENEMY_SPEED] = &enemy_writer;
	writers[ENEMY_X] = &enemy_writer;
	writers[ENEMY_Y] = &enemy_writer;
	writers[ENEMY_Z] = &enemy_writer;
	writers[OBJECT_SPRITE] = &object_writer;
	writers[OBJECT_SCALE] = &object_writer;
	writers[OBJECT_DAMAGE] = &object_writer;
	writers[OBJECT_HP] = &object_writer;
	writers[OBJECT_X] = &object_writer;
	writers[OBJECT_Y] = &object_writer;
	writers[OBJECT_Z] = &object_writer;
	writers[WIN] = &no_writer;
}

void	init_events_writers2(void (*writers[])(int, t_event))
{
	writers[SECTOR_FLOOR_SPRITES_SPRITE] = &floor_sprite_writer;
	writers[SECTOR_FLOOR_SPRITES_POS_X] = &floor_sprite_writer;
	writers[SECTOR_FLOOR_SPRITES_POS_Y] = &floor_sprite_writer;
	writers[SECTOR_FLOOR_SPRITES_SCALE_X] = &floor_sprite_writer;
	writers[SECTOR_FLOOR_SPRITES_SCALE_Y] = &floor_sprite_writer;
	writers[SECTOR_CEILING_SPRITES_SPRITE] = &ceiling_sprite_writer;
	writers[SECTOR_CEILING_SPRITES_POS_X] = &ceiling_sprite_writer;
	writers[SECTOR_CEILING_SPRITES_POS_Y] = &ceiling_sprite_writer;
	writers[SECTOR_CEILING_SPRITES_SCALE_X] = &ceiling_sprite_writer;
	writers[SECTOR_CEILING_SPRITES_SCALE_Y] = &ceiling_sprite_writer;
	writers[SECTOR_BRIGHTNESS] = &sector_writer;
	writers[SECTOR_LIGHT_COLOR] = &sector_writer;
	writers[SECTOR_INTENSITY] = &sector_writer;
	writers[SECTOR_GRAVITY] = &sector_writer;
	writers[VERTEX_X] = &vertex_writer;
	writers[VERTEX_Y] = &vertex_writer;
	writers[PLAYER_X] = &no_writer;
	writers[PLAYER_Y] = &no_writer;
	writers[PLAYER_Z] = &no_writer;
	writers[PLAYER_HP] = &no_writer;
	writers[PLAYER_ARMOR] = &no_writer;
	init_events_writers3(writers);
}

void	init_events_writers(void (*writers[])(int, t_event))
{
	writers[SECTOR_FLOOR_HEIGHT] = &sector_writer;
	writers[SECTOR_FLOOR_SLOPE] = &sector_writer;
	writers[SECTOR_FLOOR_TEXTURE] = &sector_writer;
	writers[SECTOR_FLOOR_ALIGN_X] = &sector_writer;
	writers[SECTOR_FLOOR_ALIGN_Y] = &sector_writer;
	writers[SECTOR_FLOOR_SCALE_X] = &sector_writer;
	writers[SECTOR_FLOOR_SCALE_Y] = &sector_writer;
	writers[SECTOR_CEILING_HEIGHT] = &sector_writer;
	writers[SECTOR_CEILING_SLOPE] = &sector_writer;
	writers[SECTOR_CEILING_TEXTURE] = &sector_writer;
	writers[SECTOR_CEILING_ALIGN_X] = &sector_writer;
	writers[SECTOR_CEILING_ALIGN_Y] = &sector_writer;
	writers[SECTOR_CEILING_SCALE_X] = &sector_writer;
	writers[SECTOR_CEILING_SCALE_Y] = &sector_writer;
	writers[SECTOR_WALL_TEXTURE] = &wall_writer;
	writers[SECTOR_WALL_ALIGN_X] = &wall_writer;
	writers[SECTOR_WALL_ALIGN_Y] = &wall_writer;
	writers[SECTOR_WALL_SCALE_X] = &wall_writer;
	writers[SECTOR_WALL_SCALE_Y] = &wall_writer;
	writers[SECTOR_WALL_PORTAL] = &wall_writer;
	writers[SECTOR_WALL_SPRITES_SPRITE] = &wall_sprite_writer;
	writers[SECTOR_WALL_SPRITES_POS_X] = &wall_sprite_writer;
	writers[SECTOR_WALL_SPRITES_POS_Y] = &wall_sprite_writer;
	writers[SECTOR_WALL_SPRITES_SCALE_X] = &wall_sprite_writer;
	writers[SECTOR_WALL_SPRITES_SCALE_Y] = &wall_sprite_writer;
	init_events_writers2(writers);
}

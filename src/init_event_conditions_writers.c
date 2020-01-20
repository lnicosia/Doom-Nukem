/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_event_conditions_writers.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 08:49:32 by lnicosia          #+#    #+#             */
/*   Updated: 2020/01/20 18:54:17 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "events_parser.h"

void	init_event_conditions_writers3(void (*writers[])(int, t_condition))
{
	writers[PLAYER_SPEED] = &condition_no_writer;
	writers[PLAYER_INVINCIBLE] = &condition_no_writer;
	writers[PLAYER_INFINITE_AMMO] = &condition_no_writer;
	writers[PLAYER_SECTOR] = &condition_no_writer;
	writers[WEAPON_DAMAGE] = &condition_weapon_writer;
	writers[WEAPON_RANGE] = &condition_weapon_writer;
	writers[ENEMY_SPRITE] = &condition_enemy_writer;
	writers[ENEMY_SCALE] = &condition_enemy_writer;
	writers[ENEMY_DAMAGE] = &condition_enemy_writer;
	writers[ENEMY_HP] = &condition_enemy_writer;
	writers[ENEMY_SPEED] = &condition_enemy_writer;
	writers[ENEMY_X] = &condition_enemy_writer;
	writers[ENEMY_Y] = &condition_enemy_writer;
	writers[ENEMY_Z] = &condition_enemy_writer;
	writers[OBJECT_SPRITE] = &condition_object_writer;
	writers[OBJECT_SCALE] = &condition_object_writer;
	writers[OBJECT_DAMAGE] = &condition_object_writer;
	writers[OBJECT_HP] = &condition_object_writer;
	writers[OBJECT_X] = &condition_object_writer;
	writers[OBJECT_Y] = &condition_object_writer;
	writers[OBJECT_Z] = &condition_object_writer;
}

void	init_event_conditions_writers2(void (*writers[])(int, t_condition))
{
	writers[SECTOR_FLOOR_SPRITES_SPRITE] = &condition_floor_sprite_writer;
	writers[SECTOR_FLOOR_SPRITES_POS_X] = &condition_floor_sprite_writer;
	writers[SECTOR_FLOOR_SPRITES_POS_Y] = &condition_floor_sprite_writer;
	writers[SECTOR_FLOOR_SPRITES_SCALE_X] = &condition_floor_sprite_writer;
	writers[SECTOR_FLOOR_SPRITES_SCALE_Y] = &condition_floor_sprite_writer;
	writers[SECTOR_CEILING_SPRITES_SPRITE] = &condition_ceiling_sprite_writer;
	writers[SECTOR_CEILING_SPRITES_POS_X] = &condition_ceiling_sprite_writer;
	writers[SECTOR_CEILING_SPRITES_POS_Y] = &condition_ceiling_sprite_writer;
	writers[SECTOR_CEILING_SPRITES_SCALE_X] = &condition_ceiling_sprite_writer;
	writers[SECTOR_CEILING_SPRITES_SCALE_Y] = &condition_ceiling_sprite_writer;
	writers[SECTOR_BRIGHTNESS] = &condition_sector_writer;
	writers[SECTOR_LIGHT_COLOR] = &condition_sector_writer;
	writers[SECTOR_INTENSITY] = &condition_sector_writer;
	writers[SECTOR_GRAVITY] = &condition_sector_writer;
	writers[VERTEX_X] = &condition_vertex_writer;
	writers[VERTEX_Y] = &condition_vertex_writer;
	writers[PLAYER_X] = &condition_no_writer;
	writers[PLAYER_Y] = &condition_no_writer;
	writers[PLAYER_Z] = &condition_no_writer;
	writers[PLAYER_HP] = &condition_no_writer;
	writers[PLAYER_ARMOR] = &condition_no_writer;
	init_event_conditions_writers3(writers);
}

void	init_event_conditions_writers(void (*writers[])(int, t_condition))
{
	writers[SECTOR_FLOOR_HEIGHT] = &condition_sector_writer;
	writers[SECTOR_FLOOR_SLOPE] = &condition_sector_writer;
	writers[SECTOR_FLOOR_TEXTURE] = &condition_sector_writer;
	writers[SECTOR_FLOOR_ALIGN_X] = &condition_sector_writer;
	writers[SECTOR_FLOOR_ALIGN_Y] = &condition_sector_writer;
	writers[SECTOR_FLOOR_SCALE_X] = &condition_sector_writer;
	writers[SECTOR_FLOOR_SCALE_Y] = &condition_sector_writer;
	writers[SECTOR_CEILING_HEIGHT] = &condition_sector_writer;
	writers[SECTOR_CEILING_SLOPE] = &condition_sector_writer;
	writers[SECTOR_CEILING_TEXTURE] = &condition_sector_writer;
	writers[SECTOR_CEILING_ALIGN_X] = &condition_sector_writer;
	writers[SECTOR_CEILING_ALIGN_Y] = &condition_sector_writer;
	writers[SECTOR_CEILING_SCALE_X] = &condition_sector_writer;
	writers[SECTOR_CEILING_SCALE_Y] = &condition_sector_writer;
	writers[SECTOR_WALL_TEXTURE] = &condition_wall_writer;
	writers[SECTOR_WALL_ALIGN_X] = &condition_wall_writer;
	writers[SECTOR_WALL_ALIGN_Y] = &condition_wall_writer;
	writers[SECTOR_WALL_SCALE_X] = &condition_wall_writer;
	writers[SECTOR_WALL_SCALE_Y] = &condition_wall_writer;
	writers[SECTOR_WALL_SPRITES_SPRITE] = &condition_wall_sprite_writer;
	writers[SECTOR_WALL_SPRITES_POS_X] = &condition_wall_sprite_writer;
	writers[SECTOR_WALL_SPRITES_POS_Y] = &condition_wall_sprite_writer;
	writers[SECTOR_WALL_SPRITES_SCALE_X] = &condition_wall_sprite_writer;
	writers[SECTOR_WALL_SPRITES_SCALE_Y] = &condition_wall_sprite_writer;
	init_event_conditions_writers2(writers);
}

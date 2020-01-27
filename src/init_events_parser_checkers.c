/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_events_parser_checkers.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 08:49:32 by lnicosia          #+#    #+#             */
/*   Updated: 2020/01/24 15:44:43 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "events_parser.h"

void	init_events_parser_checkers3(t_events_parser *eparser)
{
	eparser->checkers[PLAYER_SPEED] =  &check_double_overflow_event;

	eparser->checkers[PLAYER_INVINCIBLE] = &check_true_false_event;
	eparser->checkers[PLAYER_INFINITE_AMMO] = &check_true_false_event;
	eparser->checkers[PLAYER_SECTOR] = &check_double_overflow_event;
	eparser->checkers[WEAPON_DAMAGE] = &check_int_overflow_event;
	eparser->checkers[WEAPON_RANGE] = &check_double_overflow_event;
	eparser->checkers[ENEMY_SPRITE] = &check_sprite_event;
	eparser->checkers[ENEMY_SCALE] = &check_scale_event;
	eparser->checkers[ENEMY_DAMAGE] = &check_int_overflow_event;
	eparser->checkers[ENEMY_HP] = &check_int_overflow_event;
	eparser->checkers[ENEMY_SPEED] = &check_double_overflow_event;
	eparser->checkers[ENEMY_X] = &check_double_overflow_event;
	eparser->checkers[ENEMY_Y] = &check_double_overflow_event;
	eparser->checkers[ENEMY_Z] = &check_double_overflow_event;
	eparser->checkers[OBJECT_SPRITE] = &check_sprite_event;
	eparser->checkers[OBJECT_SCALE] = &check_scale_event;
	eparser->checkers[OBJECT_DAMAGE] = &check_int_overflow_event;
	eparser->checkers[OBJECT_HP] = &check_int_overflow_event;
	eparser->checkers[OBJECT_X] = &check_double_overflow_event;
	eparser->checkers[OBJECT_Y] = &check_double_overflow_event;
	eparser->checkers[OBJECT_Z] = &check_double_overflow_event;
}

void	init_events_parser_checkers2(t_events_parser *eparser)
{
	eparser->checkers[SECTOR_FLOOR_SPRITES_SPRITE] = &check_sprite_event;
	eparser->checkers[SECTOR_FLOOR_SPRITES_POS_X] = &check_align_event;
	eparser->checkers[SECTOR_FLOOR_SPRITES_POS_Y] = &check_align_event;
	eparser->checkers[SECTOR_FLOOR_SPRITES_SCALE_X] = &check_scale_event;
	eparser->checkers[SECTOR_FLOOR_SPRITES_SCALE_Y] = &check_scale_event;
	eparser->checkers[SECTOR_CEILING_SPRITES_SPRITE] = &check_sprite_event;
	eparser->checkers[SECTOR_CEILING_SPRITES_POS_X] = &check_align_event;
	eparser->checkers[SECTOR_CEILING_SPRITES_POS_Y] = &check_align_event;
	eparser->checkers[SECTOR_CEILING_SPRITES_SCALE_X] = &check_scale_event;
	eparser->checkers[SECTOR_CEILING_SPRITES_SCALE_Y] = &check_scale_event;
	eparser->checkers[SECTOR_BRIGHTNESS] = &check_brightness_event;
	eparser->checkers[SECTOR_LIGHT_COLOR] = &check_color_event;
	eparser->checkers[SECTOR_INTENSITY] = &check_brightness_event;
	eparser->checkers[SECTOR_GRAVITY] = &check_gravity_event;
	eparser->checkers[VERTEX_X] = &check_vertex_x_event;
	eparser->checkers[VERTEX_Y] = &check_vertex_y_event;
	eparser->checkers[PLAYER_X] = &check_x_collision_event;
	eparser->checkers[PLAYER_Y] = &check_y_collision_event;
	eparser->checkers[PLAYER_Z] = &check_z_collision_event;
	eparser->checkers[PLAYER_HP] = &check_int_overflow_event;
	eparser->checkers[PLAYER_ARMOR] = &check_int_overflow_event;
	init_events_parser_checkers3(eparser);
}

void	init_events_parser_checkers(t_events_parser *eparser)
{
	eparser->checkers[SECTOR_FLOOR_HEIGHT] = &check_floor_event;
	eparser->checkers[SECTOR_FLOOR_SLOPE] = &check_floor_slope_event;
	eparser->checkers[SECTOR_FLOOR_TEXTURE] = &check_texture_event;
	eparser->checkers[SECTOR_FLOOR_ALIGN_X] = &check_align_event;
	eparser->checkers[SECTOR_FLOOR_ALIGN_Y] = &check_align_event;
	eparser->checkers[SECTOR_FLOOR_SCALE_X] = &check_scale_event;
	eparser->checkers[SECTOR_FLOOR_SCALE_Y] = &check_scale_event;
	eparser->checkers[SECTOR_CEILING_HEIGHT] = &check_ceiling_event;
	eparser->checkers[SECTOR_CEILING_SLOPE] = &check_ceiling_slope_event;
	eparser->checkers[SECTOR_CEILING_TEXTURE] = &check_texture_event;
	eparser->checkers[SECTOR_CEILING_ALIGN_X] = &check_align_event;
	eparser->checkers[SECTOR_CEILING_ALIGN_Y] = &check_align_event;
	eparser->checkers[SECTOR_CEILING_SCALE_X] = &check_scale_event;
	eparser->checkers[SECTOR_CEILING_SCALE_Y] = &check_scale_event;
	eparser->checkers[SECTOR_WALL_TEXTURE] = &check_texture_event;
	eparser->checkers[SECTOR_WALL_ALIGN_X] = &check_align_event;
	eparser->checkers[SECTOR_WALL_ALIGN_Y] = &check_align_event;
	eparser->checkers[SECTOR_WALL_SCALE_X] = &check_scale_event;
	eparser->checkers[SECTOR_WALL_SCALE_Y] = &check_scale_event;
	eparser->checkers[SECTOR_WALL_PORTAL] = &check_portal_event;
	eparser->checkers[SECTOR_WALL_SPRITES_SPRITE] = &check_sprite_event;
	eparser->checkers[SECTOR_WALL_SPRITES_POS_X] = &check_align_event;
	eparser->checkers[SECTOR_WALL_SPRITES_POS_Y] = &check_align_event;
	eparser->checkers[SECTOR_WALL_SPRITES_SCALE_X] = &check_scale_event;
	eparser->checkers[SECTOR_WALL_SPRITES_SCALE_Y] = &check_scale_event;
	init_events_parser_checkers2(eparser);
}

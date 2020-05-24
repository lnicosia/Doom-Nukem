/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_print_condition_target_data.c                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 08:49:32 by lnicosia          #+#    #+#             */
/*   Updated: 2020/02/18 19:20:58 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "events_parser.h"
#include "init.h"

void	init_print_condition_target_data5(t_env *env)
{
	env->print_condition_target_data[PLAYER_SPEED] =
	&print_nothing_condition_target;
	env->print_condition_target_data[PLAYER_INVINCIBLE] =
	&print_nothing_condition_target;
	env->print_condition_target_data[PLAYER_INFINITE_AMMO] =
	&print_nothing_condition_target;
	env->print_condition_target_data[PLAYER_SECTOR] =
	&print_nothing_condition_target;
	env->print_condition_target_data[WEAPON_DAMAGE] =
	&print_weapon_condition_target;
	env->print_condition_target_data[WEAPON_RANGE] =
	&print_weapon_condition_target;
	env->print_condition_target_data[ENEMY_SPRITE] =
	&print_enemy_condition_target;
	env->print_condition_target_data[ENEMY_SCALE] =
	&print_enemy_condition_target;
	env->print_condition_target_data[ENEMY_DAMAGE] =
	&print_enemy_condition_target;
	env->print_condition_target_data[ENEMY_HP] =
	&print_enemy_condition_target;
	env->print_condition_target_data[ENEMY_SPEED] =
	&print_enemy_condition_target;
	init_print_condition_target_data6(env);
}

void	init_print_condition_target_data4(t_env *env)
{
	env->print_condition_target_data[SECTOR_CEILING_SPRITES_SCALE_Y] =
	&print_ceiling_sprite_condition_target;
	env->print_condition_target_data[SECTOR_BRIGHTNESS] =
	&print_sector_condition_target;
	env->print_condition_target_data[SECTOR_LIGHT_COLOR] =
	&print_sector_condition_target;
	env->print_condition_target_data[SECTOR_INTENSITY] =
	&print_sector_condition_target;
	env->print_condition_target_data[SECTOR_GRAVITY] =
	&print_sector_condition_target;
	env->print_condition_target_data[VERTEX_X] = &print_vertex_condition_target;
	env->print_condition_target_data[VERTEX_Y] = &print_vertex_condition_target;
	env->print_condition_target_data[PLAYER_X] =
	&print_nothing_condition_target;
	env->print_condition_target_data[PLAYER_Y] =
	&print_nothing_condition_target;
	env->print_condition_target_data[PLAYER_Z] =
	&print_nothing_condition_target;
	env->print_condition_target_data[PLAYER_HP] =
	&print_nothing_condition_target;
	env->print_condition_target_data[PLAYER_ARMOR] =
	&print_nothing_condition_target;
	init_print_condition_target_data5(env);
}

void	init_print_condition_target_data3(t_env *env)
{
	env->print_condition_target_data[SECTOR_WALL_SPRITES_SCALE_X] =
	&print_wall_sprite_condition_target;
	env->print_condition_target_data[SECTOR_WALL_SPRITES_SCALE_Y] =
	&print_wall_sprite_condition_target;
	env->print_condition_target_data[SECTOR_FLOOR_SPRITES_SPRITE] =
	&print_floor_sprite_condition_target;
	env->print_condition_target_data[SECTOR_FLOOR_SPRITES_POS_X] =
	&print_floor_sprite_condition_target;
	env->print_condition_target_data[SECTOR_FLOOR_SPRITES_POS_Y] =
	&print_floor_sprite_condition_target;
	env->print_condition_target_data[SECTOR_FLOOR_SPRITES_SCALE_X] =
	&print_floor_sprite_condition_target;
	env->print_condition_target_data[SECTOR_FLOOR_SPRITES_SCALE_Y] =
	&print_floor_sprite_condition_target;
	env->print_condition_target_data[SECTOR_CEILING_SPRITES_SPRITE] =
	&print_ceiling_sprite_condition_target;
	env->print_condition_target_data[SECTOR_CEILING_SPRITES_POS_X] =
	&print_ceiling_sprite_condition_target;
	env->print_condition_target_data[SECTOR_CEILING_SPRITES_POS_Y] =
	&print_ceiling_sprite_condition_target;
	env->print_condition_target_data[SECTOR_CEILING_SPRITES_SCALE_X] =
	&print_ceiling_sprite_condition_target;
	init_print_condition_target_data4(env);
}

void	init_print_condition_target_data2(t_env *env)
{
	env->print_condition_target_data[SECTOR_CEILING_ALIGN_Y] =
	&print_sector_condition_target;
	env->print_condition_target_data[SECTOR_CEILING_SCALE_X] =
	&print_sector_condition_target;
	env->print_condition_target_data[SECTOR_CEILING_SCALE_Y] =
	&print_sector_condition_target;
	env->print_condition_target_data[SECTOR_WALL_TEXTURE] =
	&print_wall_condition_target;
	env->print_condition_target_data[SECTOR_WALL_ALIGN_X] =
	&print_wall_condition_target;
	env->print_condition_target_data[SECTOR_WALL_ALIGN_Y] =
	&print_wall_condition_target;
	env->print_condition_target_data[SECTOR_WALL_SCALE_X] =
	&print_wall_condition_target;
	env->print_condition_target_data[SECTOR_WALL_SCALE_Y] =
	&print_wall_condition_target;
	env->print_condition_target_data[SECTOR_WALL_PORTAL] =
	&print_wall_condition_target;
	env->print_condition_target_data[SECTOR_WALL_SPRITES_SPRITE] =
	&print_wall_sprite_condition_target;
	env->print_condition_target_data[SECTOR_WALL_SPRITES_POS_X] =
	&print_wall_sprite_condition_target;
	env->print_condition_target_data[SECTOR_WALL_SPRITES_POS_Y] =
	&print_wall_sprite_condition_target;
	init_print_condition_target_data3(env);
}

void	init_print_condition_target_data(t_env *env)
{
	env->print_condition_target_data[SECTOR_FLOOR_HEIGHT] =
	&print_sector_condition_target;
	env->print_condition_target_data[SECTOR_FLOOR_SLOPE] =
	&print_sector_condition_target;
	env->print_condition_target_data[SECTOR_FLOOR_TEXTURE] =
	&print_sector_condition_target;
	env->print_condition_target_data[SECTOR_FLOOR_ALIGN_X] =
	&print_sector_condition_target;
	env->print_condition_target_data[SECTOR_FLOOR_ALIGN_Y] =
	&print_sector_condition_target;
	env->print_condition_target_data[SECTOR_FLOOR_SCALE_X] =
	&print_sector_condition_target;
	env->print_condition_target_data[SECTOR_FLOOR_SCALE_Y] =
	&print_sector_condition_target;
	env->print_condition_target_data[SECTOR_CEILING_HEIGHT] =
	&print_sector_condition_target;
	env->print_condition_target_data[SECTOR_CEILING_SLOPE] =
	&print_sector_condition_target;
	env->print_condition_target_data[SECTOR_CEILING_TEXTURE] =
	&print_sector_condition_target;
	env->print_condition_target_data[SECTOR_CEILING_ALIGN_X] =
	&print_sector_condition_target;
	init_print_condition_target_data2(env);
}

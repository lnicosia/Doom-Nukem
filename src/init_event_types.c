/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_event_types.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 08:49:32 by lnicosia          #+#    #+#             */
/*   Updated: 2020/04/30 11:59:48 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "events_parser.h"
#include "parser.h"

void	init_event_types3(t_env *env)
{
	env->event_types[PLAYER_SPEED] = "Player speed";
	env->event_types[PLAYER_SECTOR] = "Player sector";
	env->event_types[PLAYER_INVINCIBLE] = "Invincible mode";
	env->event_types[PLAYER_INFINITE_AMMO] = "Infinite ammo mode";
	env->event_types[PLAYER_SECTOR] = "Player sector";
	env->event_types[WEAPON_DAMAGE] = "damage";
	env->event_types[WEAPON_RANGE] = "range";
	env->event_types[ENEMY_SPRITE] = "sprite";
	env->event_types[ENEMY_SCALE] = "scale";
	env->event_types[ENEMY_DAMAGE] = "damage";
	env->event_types[ENEMY_HP] = "HP";
	env->event_types[ENEMY_SPEED] = "speed";
	env->event_types[ENEMY_X] = "X";
	env->event_types[ENEMY_Y] = "Y";
	env->event_types[ENEMY_Z] = "Z";
	env->event_types[OBJECT_SPRITE] = "sprite";
	env->event_types[OBJECT_SCALE] = "scale";
	env->event_types[OBJECT_DAMAGE] = "damage";
	env->event_types[OBJECT_HP] = "HP";
	env->event_types[OBJECT_X] = "X";
	env->event_types[OBJECT_Y] = "Y";
	env->event_types[OBJECT_Z] = "Z";
	env->event_types[WIN] = "Win";
	env->event_types[DIALOG] = "Dialogue";
}

void	init_event_types2(t_env *env)
{
	env->event_types[SECTOR_WALL_SPRITES_SCALE_Y] = "scale Y";
	env->event_types[SECTOR_FLOOR_SPRITES_SPRITE] = "sprite";
	env->event_types[SECTOR_FLOOR_SPRITES_POS_X] = "pos X";
	env->event_types[SECTOR_FLOOR_SPRITES_POS_Y] = "pos Y";
	env->event_types[SECTOR_FLOOR_SPRITES_SCALE_X] = "scale X";
	env->event_types[SECTOR_FLOOR_SPRITES_SCALE_Y] = "scale Y";
	env->event_types[SECTOR_CEILING_SPRITES_SPRITE] = "sprite";
	env->event_types[SECTOR_CEILING_SPRITES_POS_X] = "pos X";
	env->event_types[SECTOR_CEILING_SPRITES_POS_Y] = "pos Y";
	env->event_types[SECTOR_CEILING_SPRITES_SCALE_X] = "scale X";
	env->event_types[SECTOR_CEILING_SPRITES_SCALE_Y] = "scale Y";
	env->event_types[SECTOR_BRIGHTNESS] = " light brightness";
	env->event_types[SECTOR_LIGHT_COLOR] = "light color";
	env->event_types[SECTOR_INTENSITY] = "light intensity";
	env->event_types[SECTOR_GRAVITY] = "gravity";
	env->event_types[VERTEX_X] = "X";
	env->event_types[VERTEX_Y] = "Y";
	env->event_types[PLAYER_X] = "Player X";
	env->event_types[PLAYER_Y] = "Player Y";
	env->event_types[PLAYER_Z] = "Player Z";
	env->event_types[PLAYER_HP] = "Player HP";
	env->event_types[PLAYER_ARMOR] = "Player armor";
	init_event_types3(env);
}

void	init_event_types(t_env *env)
{
	env->event_types[SECTOR_FLOOR_HEIGHT] = "floor height";
	env->event_types[SECTOR_FLOOR_SLOPE] = "floor slope";
	env->event_types[SECTOR_FLOOR_TEXTURE] = "floor texture";
	env->event_types[SECTOR_FLOOR_ALIGN_X] = "floor texture align X";
	env->event_types[SECTOR_FLOOR_ALIGN_Y] = "floor texture align Y";
	env->event_types[SECTOR_FLOOR_SCALE_X] = "floor texture scale X";
	env->event_types[SECTOR_FLOOR_SCALE_Y] = "floor texture scale Y";
	env->event_types[SECTOR_CEILING_HEIGHT] = "ceiling height";
	env->event_types[SECTOR_CEILING_SLOPE] = "ceiling slope";
	env->event_types[SECTOR_CEILING_TEXTURE] = "ceiling texture";
	env->event_types[SECTOR_CEILING_ALIGN_X] = "ceiling texture align X";
	env->event_types[SECTOR_CEILING_ALIGN_Y] = "ceiling texture align Y";
	env->event_types[SECTOR_CEILING_SCALE_X] = "ceiling texture scale X";
	env->event_types[SECTOR_CEILING_SCALE_Y] = "ceiling texture scale Y";
	env->event_types[SECTOR_WALL_TEXTURE] = "texture";
	env->event_types[SECTOR_WALL_ALIGN_X] = "texture align X";
	env->event_types[SECTOR_WALL_ALIGN_Y] = "texture align Y";
	env->event_types[SECTOR_WALL_SCALE_X] = "texture scale X";
	env->event_types[SECTOR_WALL_SCALE_Y] = "texture scale Y";
	env->event_types[SECTOR_WALL_PORTAL] = "portal";
	env->event_types[SECTOR_WALL_SPRITES_SPRITE] = "sprite";
	env->event_types[SECTOR_WALL_SPRITES_POS_X] = "pos X";
	env->event_types[SECTOR_WALL_SPRITES_POS_Y] = "pos Y";
	env->event_types[SECTOR_WALL_SPRITES_SCALE_X] = "scale X";
	init_event_types2(env);
}

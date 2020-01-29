/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_event_types.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 08:49:32 by lnicosia          #+#    #+#             */
/*   Updated: 2020/01/29 11:54:17 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "events_parser.h"

void	init_event_types3(t_env *env)
{
	env->event_types[PLAYER_SPEED] = "Player speed";
	env->event_types[PLAYER_INVINCIBLE] = "Invincible mode";
	env->event_types[PLAYER_INFINITE_AMMO] = "Infinite ammo mode";
	env->event_types[PLAYER_SECTOR] = "Player sector";
	env->event_types[WEAPON_DAMAGE] = "Weapon          damage";
	env->event_types[WEAPON_RANGE] = "Weapon          range";
	env->event_types[ENEMY_SPRITE] = "Enemy           sprite";
	env->event_types[ENEMY_SCALE] = "Enemy           scale";
	env->event_types[ENEMY_DAMAGE] = "Enemy           damage";
	env->event_types[ENEMY_HP] = "Enemy           HP";
	env->event_types[ENEMY_SPEED] = "Enemy          speed";
	env->event_types[ENEMY_X] = "Enemy          X";
	env->event_types[ENEMY_Y] = "Enemy          Y";
	env->event_types[ENEMY_Z] = "Enemy          Z";
	env->event_types[OBJECT_SPRITE] = "Object          sprite";
	env->event_types[OBJECT_SCALE] = "Object          scale";
	env->event_types[OBJECT_DAMAGE] = "Object          damage";
	env->event_types[OBJECT_HP] = "Object          HP";
	env->event_types[OBJECT_X] = "Object          X";
	env->event_types[OBJECT_Y] = "Object          Y";
	env->event_types[OBJECT_Z] = "Object          Z";
}

void	init_event_types2(t_env *env)
{
	env->event_types[SECTOR_FLOOR_SPRITES_SPRITE] = "Sector          floor"
	"          sprite           sprite";
	env->event_types[SECTOR_FLOOR_SPRITES_POS_X] = "Sector          floor"
	"          sprite          pos X";
	env->event_types[SECTOR_FLOOR_SPRITES_POS_Y] = "Sector          floor"
	"          sprite          pos Y";
	env->event_types[SECTOR_FLOOR_SPRITES_SCALE_X] = "Sector          floor"
	"          sprite          scale X";
	env->event_types[SECTOR_FLOOR_SPRITES_SCALE_Y] = "Sector          floor"
	"          sprite          scale Y";
	env->event_types[SECTOR_CEILING_SPRITES_SPRITE] = "Sector          ceiling"
	"          sprite          sprite";
	env->event_types[SECTOR_CEILING_SPRITES_POS_X] = "Sector          ceiling"
	"          sprite          pos X";
	env->event_types[SECTOR_CEILING_SPRITES_POS_Y] = "Sector          ceiling"
	"          sprite          pos Y";
	env->event_types[SECTOR_CEILING_SPRITES_SCALE_X] = "Sector          ceiling"
	"          sprite          scale X";
	env->event_types[SECTOR_CEILING_SPRITES_SCALE_Y] = "Sector          ceiling"
	"          sprite          scale Y";
	env->event_types[SECTOR_BRIGHTNESS] = "Sector           light brightness";
	env->event_types[SECTOR_LIGHT_COLOR] = "Sector          light color";
	env->event_types[SECTOR_INTENSITY] = "Sector          light intensity";
	env->event_types[SECTOR_GRAVITY] = "Sector          gravity";
	env->event_types[VERTEX_X] = "Vertex          X";
	env->event_types[VERTEX_Y] = "Vertex          Y";
	env->event_types[PLAYER_X] = "Player X";
	env->event_types[PLAYER_Y] = "Player Y";
	env->event_types[PLAYER_Z] = "Player Z";
	env->event_types[PLAYER_HP] = "Player HP";
	env->event_types[PLAYER_ARMOR] = "Player armor";
	init_event_types3(env);
}

void	init_event_types(t_env *env)
{
	env->event_types[SECTOR_FLOOR_HEIGHT] = "Sector          floor height";
	env->event_types[SECTOR_FLOOR_SLOPE] = "Sector          floor slope";
	env->event_types[SECTOR_FLOOR_TEXTURE] = "Sector          floor texture";
	env->event_types[SECTOR_FLOOR_ALIGN_X] = "Sector          floor texture "
	"align X";
	env->event_types[SECTOR_FLOOR_ALIGN_Y] = "Sector          floor texture "
	"align Y";
	env->event_types[SECTOR_FLOOR_SCALE_X] = "Sector          floor texture "
	"scale X";
	env->event_types[SECTOR_FLOOR_SCALE_Y] = "Sector          floor texture "
	"scale Y";
	env->event_types[SECTOR_CEILING_HEIGHT] = "Sector          ceiling height";
	env->event_types[SECTOR_CEILING_SLOPE] = "Sector          ceiling slope";
	env->event_types[SECTOR_CEILING_TEXTURE] = "Sector          ceiling "
	"texture";
	env->event_types[SECTOR_CEILING_ALIGN_X] = "Sector          ceiling texture"
	" align X";
	env->event_types[SECTOR_CEILING_ALIGN_Y] = "Sector          ceiling texture"
	" align Y";
	env->event_types[SECTOR_CEILING_SCALE_X] = "Sector          ceiling texture"
	" scale X";
	env->event_types[SECTOR_CEILING_SCALE_Y] = "Sector          ceiling texture"
	" scale Y";
	env->event_types[SECTOR_WALL_TEXTURE] = "Sector          wall          "
	"texture";
	env->event_types[SECTOR_WALL_ALIGN_X] = "Sector          wall          "
	"texture align X";
	env->event_types[SECTOR_WALL_ALIGN_Y] = "Sector          wall          "
	"texture align Y";
	env->event_types[SECTOR_WALL_SCALE_X] = "Sector          wall          "
	"texture scale X";
	env->event_types[SECTOR_WALL_SCALE_Y] = "Sector          wall          "
	"texture scale Y";
	env->event_types[SECTOR_WALL_PORTAL] = "Sector          wall          "
	"portal";
	env->event_types[SECTOR_WALL_SPRITES_SPRITE] = "Sector          "
	"wall          sprite          sprite";
	env->event_types[SECTOR_WALL_SPRITES_POS_X] = "Sector          "
	"wall          sprite          pos X";
	env->event_types[SECTOR_WALL_SPRITES_POS_Y] = "Sector          "
	"wall          sprite          pos Y";
	env->event_types[SECTOR_WALL_SPRITES_SCALE_X] = "Sector          "
	"wall          sprite          scale X";
	env->event_types[SECTOR_WALL_SPRITES_SCALE_Y] = "Sector          "
	"wall          sprite          scale Y";
	init_event_types2(env);
}

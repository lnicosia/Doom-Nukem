/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_event_target2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 10:49:41 by lnicosia          #+#    #+#             */
/*   Updated: 2020/03/03 12:02:33 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "events_parser.h"
#include "parser.h"

void		*set_event_target8(t_env *env, t_events_parser *eparser)
{
	if (eparser->target_index == OBJECT_SPRITE)
		return (&env->objects[eparser->target_object].sprite);
	else if (eparser->target_index == OBJECT_SCALE)
		return (&env->objects[eparser->target_object].scale);
	else if (eparser->target_index == OBJECT_DAMAGE)
		return (&env->objects[eparser->target_object].damage);
	else if (eparser->target_index == OBJECT_HP)
		return (&env->objects[eparser->target_object].health);
	else if (eparser->target_index == OBJECT_X)
		return (&env->objects[eparser->target_object].pos.x);
	else if (eparser->target_index == OBJECT_Y)
		return (&env->objects[eparser->target_object].pos.y);
	else if (eparser->target_index == OBJECT_Z)
		return (&env->objects[eparser->target_object].pos.z);
	else if (eparser->target_index >= MAX_REAL_TARGET_TYPES)
		return (set_event_function(env, eparser));
	return (0);
}

void		*set_event_target7(t_env *env, t_events_parser *eparser)
{
	if (eparser->target_index == WEAPON_DAMAGE)
		return (&env->weapons[eparser->target_weapon].damage);
	else if (eparser->target_index == WEAPON_RANGE)
		return (&env->weapons[eparser->target_weapon].range);
	else if (eparser->target_index == ENEMY_SPRITE)
		return (&env->enemies[eparser->target_enemy].
		main_sprite);
	else if (eparser->target_index == ENEMY_SCALE)
		return (&env->enemies[eparser->target_enemy].scale);
	else if (eparser->target_index == ENEMY_DAMAGE)
		return (&env->enemies[eparser->target_enemy].damage);
	else if (eparser->target_index == ENEMY_HP)
		return (&env->enemies[eparser->target_enemy].health);
	else if (eparser->target_index == ENEMY_X)
		return (&env->enemies[eparser->target_enemy].pos.x);
	else if (eparser->target_index == ENEMY_Y)
		return (&env->enemies[eparser->target_enemy].pos.y);
	else if (eparser->target_index == ENEMY_Z)
		return (&env->enemies[eparser->target_enemy].pos.z);
	else
		return (set_event_target8(env, eparser));
}

void		*set_event_target6(t_env *env, t_events_parser *eparser)
{
	if (eparser->target_index == PLAYER_X)
		return (&env->player.pos.x);
	else if (eparser->target_index == PLAYER_Y)
		return (&env->player.pos.y);
	else if (eparser->target_index == PLAYER_Z)
		return (&env->player.pos.z);
	else if (eparser->target_index == PLAYER_SPEED)
		return (&env->player.speed);
	else if (eparser->target_index == PLAYER_HP)
		return (&env->player.health);
	else if (eparser->target_index == PLAYER_ARMOR)
		return (&env->player.armor);
	else if (eparser->target_index == PLAYER_INVINCIBLE)
		return (&env->player.invincible);
	else if (eparser->target_index == PLAYER_INFINITE_AMMO)
		return (&env->player.infinite_ammo);
	else if (eparser->target_index == PLAYER_SECTOR)
		return (&env->player.sector);
	else
		return (set_event_target7(env, eparser));
}

void		*set_event_target5(t_env *env, t_events_parser *eparser)
{
	if (eparser->target_index == SECTOR_BRIGHTNESS)
		return (&env->sectors[eparser->target_sector].
		brightness);
	else if (eparser->target_index == SECTOR_LIGHT_COLOR)
		return (&env->sectors[eparser->target_sector].
		light_color);
	else if (eparser->target_index == SECTOR_INTENSITY)
		return (&env->sectors[eparser->target_sector].intensity);
	else if (eparser->target_index == SECTOR_GRAVITY)
		return (&env->sectors[eparser->target_sector].gravity);
	else if (eparser->target_index == VERTEX_X)
		return (&env->vertices[eparser->target_vertex].x);
	else if (eparser->target_index == VERTEX_Y)
		return (&env->vertices[eparser->target_vertex].y);
	else
		return (set_event_target6(env, eparser));
}

void		*set_event_target4(t_env *env, t_events_parser *eparser)
{
	if (eparser->target_index == SECTOR_CEILING_SPRITES_SPRITE)
		return (&env->sectors[eparser->target_sector].
		floor_sprites.sprite[eparser->target_sprite]);
	else if (eparser->target_index == SECTOR_CEILING_SPRITES_POS_X)
		return (&env->sectors[eparser->target_sector].
		floor_sprites.pos[eparser->target_sprite].x);
	else if (eparser->target_index == SECTOR_CEILING_SPRITES_POS_Y)
		return (&env->sectors[eparser->target_sector].
		floor_sprites.pos[eparser->target_sprite].y);
	else if (eparser->target_index == SECTOR_CEILING_SPRITES_SCALE_X)
		return (&env->sectors[eparser->target_sector].
		floor_sprites.scale[eparser->target_sprite].x);
	else if (eparser->target_index == SECTOR_CEILING_SPRITES_SCALE_Y)
		return (&env->sectors[eparser->target_sector].
		floor_sprites.scale[eparser->target_sprite].y);
	else
		return (set_event_target5(env, eparser));
}

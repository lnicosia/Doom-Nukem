/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_condition_target2.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 10:49:41 by lnicosia          #+#    #+#             */
/*   Updated: 2020/02/25 18:37:01 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "events_parser.h"

void		*set_condition_target8(t_env *env, t_events_parser *eparser)
{
	if (eparser->condition_index == OBJECT_SPRITE)
		return (&env->objects[eparser->condition_object].sprite);
	else if (eparser->condition_index == OBJECT_SCALE)
		return (&env->objects[eparser->condition_object].scale);
	else if (eparser->condition_index == OBJECT_DAMAGE)
		return (&env->objects[eparser->condition_object].damage);
	else if (eparser->condition_index == OBJECT_HP)
		return (&env->objects[eparser->condition_object].health);
	else if (eparser->condition_index == OBJECT_X)
		return (&env->objects[eparser->condition_object].pos.x);
	else if (eparser->condition_index == OBJECT_Y)
		return (&env->objects[eparser->condition_object].pos.y);
	else if (eparser->condition_index == OBJECT_Z)
		return (&env->objects[eparser->condition_object].pos.z);
	return (0);
}

void		*set_condition_target7(t_env *env, t_events_parser *eparser)
{
	if (eparser->condition_index == WEAPON_DAMAGE)
		return (&env->weapons[eparser->condition_weapon].damage);
	else if (eparser->condition_index == WEAPON_RANGE)
		return (&env->weapons[eparser->condition_weapon].range);
	else if (eparser->condition_index == ENEMY_SPRITE)
		return (&env->enemies[eparser->condition_enemy].
		main_sprite);
	else if (eparser->condition_index == ENEMY_SCALE)
		return (&env->enemies[eparser->condition_enemy].scale);
	else if (eparser->condition_index == ENEMY_DAMAGE)
		return (&env->enemies[eparser->condition_enemy].damage);
	else if (eparser->condition_index == ENEMY_HP)
		return (&env->enemies[eparser->condition_enemy].health);
	else if (eparser->condition_index == ENEMY_X)
		return (&env->enemies[eparser->condition_enemy].pos.x);
	else if (eparser->condition_index == ENEMY_Y)
		return (&env->enemies[eparser->condition_enemy].pos.y);
	else if (eparser->condition_index == ENEMY_Z)
		return (&env->enemies[eparser->condition_enemy].pos.z);
	else
		return (set_condition_target8(env, eparser));
}

void		*set_condition_target6(t_env *env, t_events_parser *eparser)
{
	if (eparser->condition_index == PLAYER_X)
		return (&env->player.pos.x);
	else if (eparser->condition_index == PLAYER_Y)
		return (&env->player.pos.y);
	else if (eparser->condition_index == PLAYER_Z)
		return (&env->player.pos.z);
	else if (eparser->condition_index == PLAYER_SPEED)
		return (&env->player.speed);
	else if (eparser->condition_index == PLAYER_HP)
		return (&env->player.health);
	else if (eparser->condition_index == PLAYER_ARMOR)
		return (&env->player.armor);
	else if (eparser->condition_index == PLAYER_INVINCIBLE)
		return (&env->player.invincible);
	else if (eparser->condition_index == PLAYER_INFINITE_AMMO)
		return (&env->player.infinite_ammo);
	else if (eparser->condition_index == PLAYER_SECTOR)
		return (&env->player.sector);
	else
		return (set_condition_target7(env, eparser));
}

void		*set_condition_target5(t_env *env, t_events_parser *eparser)
{
	if (eparser->condition_index == SECTOR_BRIGHTNESS)
		return (&env->sectors[eparser->condition_sector].
		brightness);
	else if (eparser->condition_index == SECTOR_LIGHT_COLOR)
		return (&env->sectors[eparser->condition_sector].
		light_color);
	else if (eparser->condition_index == SECTOR_INTENSITY)
		return (&env->sectors[eparser->condition_sector].intensity);
	else if (eparser->condition_index == SECTOR_GRAVITY)
		return (&env->sectors[eparser->condition_sector].gravity);
	else if (eparser->condition_index == VERTEX_X)
		return (&env->vertices[eparser->condition_vertex].x);
	else if (eparser->condition_index == VERTEX_Y)
		return (&env->vertices[eparser->condition_vertex].y);
	else
		return (set_condition_target6(env, eparser));
}

void		*set_condition_target4(t_env *env, t_events_parser *eparser)
{
	if (eparser->condition_index == SECTOR_CEILING_SPRITES_SPRITE)
		return (&env->sectors[eparser->condition_sector].
		floor_sprites.sprite[eparser->condition_sprite]);
	else if (eparser->condition_index == SECTOR_CEILING_SPRITES_POS_X)
		return (&env->sectors[eparser->condition_sector].
		floor_sprites.pos[eparser->condition_sprite].x);
	else if (eparser->condition_index == SECTOR_CEILING_SPRITES_POS_Y)
		return (&env->sectors[eparser->condition_sector].
		floor_sprites.pos[eparser->condition_sprite].y);
	else if (eparser->condition_index == SECTOR_CEILING_SPRITES_SCALE_X)
		return (&env->sectors[eparser->condition_sector].
		floor_sprites.scale[eparser->condition_sprite].x);
	else if (eparser->condition_index == SECTOR_CEILING_SPRITES_SCALE_Y)
		return (&env->sectors[eparser->condition_sector].
		floor_sprites.scale[eparser->condition_sprite].y);
	else
		return (set_condition_target5(env, eparser));
}

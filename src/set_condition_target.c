/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_condition_target.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 10:49:41 by lnicosia          #+#    #+#             */
/*   Updated: 2020/01/16 15:20:33 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "events_parser.h"

void	*set_condition_target3(t_env *env, t_events_parser *eparser)
{
	if (eparser->condition_index == SECTOR_FLOOR_SPRITES_SPRITE)
		return (&env->sectors[eparser->condition_sector].
		floor_sprites.sprite[eparser->condition_sprite]);
	else if (eparser->condition_index == SECTOR_FLOOR_SPRITES_POS_X)
		return (&env->sectors[eparser->condition_sector].
		floor_sprites.pos[eparser->condition_sprite].x);
	else if (eparser->condition_index == SECTOR_FLOOR_SPRITES_POS_Y)
		return (&env->sectors[eparser->condition_sector].
		floor_sprites.pos[eparser->condition_sprite].y);
	else if (eparser->condition_index == SECTOR_FLOOR_SPRITES_SCALE_X)
		return (&env->sectors[eparser->condition_sector].
		floor_sprites.scale[eparser->condition_sprite].x);
	else if (eparser->condition_index == SECTOR_FLOOR_SPRITES_SCALE_Y)
		return (&env->sectors[eparser->condition_sector].
		floor_sprites.scale[eparser->condition_sprite].y);
	else
		return (set_condition_target4(env, eparser));
}

void	*set_condition_target2(t_env *env, t_events_parser *eparser)
{
	if (eparser->condition_index == SECTOR_WALL_SPRITES_SPRITE)
		return (&env->sectors[eparser->condition_sector].
		wall_sprites[eparser->condition_wall].sprite[eparser->
		condition_sprite]);
	else if (eparser->condition_index == SECTOR_WALL_SPRITES_POS_X)
		return (&env->sectors[eparser->condition_sector].
		wall_sprites[eparser->condition_wall].pos[eparser->
		condition_sprite].x);
	else if (eparser->condition_index == SECTOR_WALL_SPRITES_POS_Y)
		return (&env->sectors[eparser->condition_sector].
		wall_sprites[eparser->condition_wall].pos[eparser->
		condition_sprite].y);
	else if (eparser->condition_index == SECTOR_WALL_SPRITES_SCALE_X)
		return (&env->sectors[eparser->condition_sector].
		wall_sprites[eparser->condition_wall].scale[eparser->
		condition_sprite].x);
	else if (eparser->condition_index == SECTOR_WALL_SPRITES_SCALE_Y)
		return (&env->sectors[eparser->condition_sector].
		wall_sprites[eparser->condition_wall].scale[eparser->
		condition_sprite].y);
	else
		return (set_condition_target3(env, eparser));
}

void	*set_condition_target1(t_env *env, t_events_parser *eparser)
{
	if (eparser->condition_index == SECTOR_WALL_TEXTURE)
		return (&env->sectors[eparser->condition_sector].
		textures[eparser->condition_wall]);
	else if (eparser->condition_index == SECTOR_WALL_ALIGN_X)
		return (&env->sectors[eparser->condition_sector].
		align[eparser->condition_wall].x);
	else if (eparser->condition_index == SECTOR_WALL_ALIGN_Y)
		return (&env->sectors[eparser->condition_sector].
		align[eparser->condition_wall].y);
	else if (eparser->condition_index == SECTOR_WALL_SCALE_X)
		return (&env->sectors[eparser->condition_sector].
		scale[eparser->condition_wall].x);
	else if (eparser->condition_index == SECTOR_WALL_SCALE_Y)
		return (&env->sectors[eparser->condition_sector].
		scale[eparser->condition_wall].y);
	if (eparser->condition_index == SECTOR_WALL_PORTAL)
		return (&env->sectors[eparser->condition_sector].
		portals[eparser->condition_wall]);
	else
		return (set_condition_target2(env, eparser));
}

void	*set_condition_target0(t_env *env, t_events_parser *eparser)
{
	if (eparser->condition_index == SECTOR_CEILING_HEIGHT)
		return (&env->sectors[eparser->condition_sector].ceiling);
	else if (eparser->condition_index == SECTOR_CEILING_SLOPE)
		return (&env->sectors[eparser->condition_sector].ceiling_slope);
	else if (eparser->condition_index == SECTOR_CEILING_TEXTURE)
		return (&env->sectors[eparser->condition_sector].
		ceiling_texture);
	else if (eparser->condition_index == SECTOR_CEILING_ALIGN_X)
		return (&env->sectors[eparser->condition_sector].
		ceiling_map_align.x);
	else if (eparser->condition_index == SECTOR_CEILING_ALIGN_Y)
		return (&env->sectors[eparser->condition_sector].
		ceiling_map_align.y);
	else if (eparser->condition_index == SECTOR_CEILING_SCALE_X)
		return (&env->sectors[eparser->condition_sector].
		ceiling_map_scale.x);
	else if (eparser->condition_index == SECTOR_CEILING_SCALE_Y)
		return (&env->sectors[eparser->condition_sector].
		ceiling_map_scale.y);
	else
		return (set_condition_target1(env, eparser));
}

void	*set_condition_target(t_env *env, t_events_parser *eparser)
{
	if (eparser->condition_index == SECTOR_FLOOR_HEIGHT)
		return (&env->sectors[eparser->condition_sector].floor);
	else if (eparser->condition_index == SECTOR_FLOOR_SLOPE)
		return (&env->sectors[eparser->condition_sector].floor_slope);
	else if (eparser->condition_index == SECTOR_FLOOR_TEXTURE)
		return (&env->sectors[eparser->condition_sector].floor_texture);
	else if (eparser->condition_index == SECTOR_FLOOR_ALIGN_X)
		return (&env->sectors[eparser->condition_sector].
		floor_map_align.x);
	else if (eparser->condition_index == SECTOR_FLOOR_ALIGN_Y)
		return (&env->sectors[eparser->condition_sector].
		floor_map_align.y);
	else if (eparser->condition_index == SECTOR_FLOOR_SCALE_X)
		return (&env->sectors[eparser->condition_sector].
		floor_map_scale.x);
	else if (eparser->condition_index == SECTOR_FLOOR_SCALE_Y)
		return (&env->sectors[eparser->condition_sector].
		floor_map_scale.y);
	else
		return (set_condition_target0(env, eparser));
}

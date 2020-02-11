/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_event_target.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 10:49:41 by lnicosia          #+#    #+#             */
/*   Updated: 2020/02/11 17:22:36 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "events_parser.h"

void	*set_event_target3(t_env *env, t_events_parser *eparser)
{
	if (eparser->target_index == SECTOR_FLOOR_SPRITES_SPRITE)
		return (&env->sectors[eparser->target_sector].
		floor_sprites.sprite[eparser->target_sprite]);
	else if (eparser->target_index == SECTOR_FLOOR_SPRITES_POS_X)
		return (&env->sectors[eparser->target_sector].
		floor_sprites.pos[eparser->target_sprite].x);
	else if (eparser->target_index == SECTOR_FLOOR_SPRITES_POS_Y)
		return (&env->sectors[eparser->target_sector].
		floor_sprites.pos[eparser->target_sprite].y);
	else if (eparser->target_index == SECTOR_FLOOR_SPRITES_SCALE_X)
		return (&env->sectors[eparser->target_sector].
		floor_sprites.scale[eparser->target_sprite].x);
	else if (eparser->target_index == SECTOR_FLOOR_SPRITES_SCALE_Y)
		return (&env->sectors[eparser->target_sector].
		floor_sprites.scale[eparser->target_sprite].y);
	else
		return (set_event_target4(env, eparser));
}

void	*set_event_target2(t_env *env, t_events_parser *eparser)
{
	if (eparser->target_index == SECTOR_WALL_SPRITES_SPRITE)
		return (&env->sectors[eparser->target_sector].
		wall_sprites[eparser->target_wall].sprite[eparser->target_sprite]);
	else if (eparser->target_index == SECTOR_WALL_SPRITES_POS_X)
		return (&env->sectors[eparser->target_sector].
		wall_sprites[eparser->target_wall].pos[eparser->target_sprite].x);
	else if (eparser->target_index == SECTOR_WALL_SPRITES_POS_Y)
		return (&env->sectors[eparser->target_sector].
		wall_sprites[eparser->target_wall].pos[eparser->target_sprite].y);
	else if (eparser->target_index == SECTOR_WALL_SPRITES_SCALE_X)
		return (&env->sectors[eparser->target_sector].
		wall_sprites[eparser->target_wall].scale[eparser->target_sprite].x);
	else if (eparser->target_index == SECTOR_WALL_SPRITES_SCALE_Y)
		return (&env->sectors[eparser->target_sector].
		wall_sprites[eparser->target_wall].scale[eparser->target_sprite].y);
	else
		return (set_event_target3(env, eparser));
}

void	*set_event_target1(t_env *env, t_events_parser *eparser)
{
	if (eparser->target_index == SECTOR_WALL_TEXTURE)
		return (&env->sectors[eparser->target_sector].
		textures[eparser->target_wall]);
	else if (eparser->target_index == SECTOR_WALL_ALIGN_X)
		return (&env->sectors[eparser->target_sector].
		align[eparser->target_wall].x);
	else if (eparser->target_index == SECTOR_WALL_ALIGN_Y)
		return (&env->sectors[eparser->target_sector].
		align[eparser->target_wall].y);
	else if (eparser->target_index == SECTOR_WALL_SCALE_X)
		return (&env->sectors[eparser->target_sector].
		scale[eparser->target_wall].x);
	else if (eparser->target_index == SECTOR_WALL_SCALE_Y)
		return (&env->sectors[eparser->target_sector].
		scale[eparser->target_wall].y);
	if (eparser->target_index == SECTOR_WALL_PORTAL)
		return (&env->sectors[eparser->target_sector].
		portals[eparser->target_wall]);
	else
		return (set_event_target2(env, eparser));
}

void	*set_event_target0(t_env *env, t_events_parser *eparser)
{
	if (eparser->target_index == SECTOR_CEILING_HEIGHT)
		return (&env->sectors[eparser->target_sector].ceiling);
	else if (eparser->target_index == SECTOR_CEILING_SLOPE)
		return (&env->sectors[eparser->target_sector].ceiling_slope);
	else if (eparser->target_index == SECTOR_CEILING_TEXTURE)
		return (&env->sectors[eparser->target_sector].ceiling_texture);
	else if (eparser->target_index == SECTOR_CEILING_ALIGN_X)
		return (&env->sectors[eparser->target_sector].ceiling_map_align.x);
	else if (eparser->target_index == SECTOR_CEILING_ALIGN_Y)
		return (&env->sectors[eparser->target_sector].ceiling_map_align.y);
	else if (eparser->target_index == SECTOR_CEILING_SCALE_X)
		return (&env->sectors[eparser->target_sector].ceiling_map_scale.x);
	else if (eparser->target_index == SECTOR_CEILING_SCALE_Y)
		return (&env->sectors[eparser->target_sector].ceiling_map_scale.y);
	else
		return (set_event_target1(env, eparser));
}

void	*set_event_target(t_env *env, t_events_parser *eparser)
{
	if (eparser->target_index == SECTOR_FLOOR_HEIGHT)
		return (&env->sectors[eparser->target_sector].floor);
	else if (eparser->target_index == SECTOR_FLOOR_SLOPE)
		return (&env->sectors[eparser->target_sector].floor_slope);
	else if (eparser->target_index == SECTOR_FLOOR_TEXTURE)
		return (&env->sectors[eparser->target_sector].floor_texture);
	else if (eparser->target_index == SECTOR_FLOOR_ALIGN_X)
		return (&env->sectors[eparser->target_sector].floor_map_align.x);
	else if (eparser->target_index == SECTOR_FLOOR_ALIGN_Y)
		return (&env->sectors[eparser->target_sector].floor_map_align.y);
	else if (eparser->target_index == SECTOR_FLOOR_SCALE_X)
		return (&env->sectors[eparser->target_sector].floor_map_scale.x);
	else if (eparser->target_index == SECTOR_FLOOR_SCALE_Y)
		return (&env->sectors[eparser->target_sector].floor_map_scale.y);
	else
		return (set_event_target0(env, eparser));
}

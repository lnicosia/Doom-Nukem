/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   precompute_floor_ceiling_sprites_scales.c          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 09:52:06 by lnicosia          #+#    #+#             */
/*   Updated: 2020/01/31 11:00:01 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

int			precompute_floor_sprite_scales(int sector, int sprite, t_env *env)
{
	env->sectors[sector].floor_sprites_scale[sprite].x = env->
	object_sprites[env->sectors[sector].floor_sprites.sprite[sprite]].
	size[0].x / env->sectors[sector].floor_sprites.scale[sprite].x;
	env->sectors[sector].floor_sprites_scale[sprite].y = env->
	object_sprites[env->sectors[sector].floor_sprites.sprite[sprite]].
	size[0].y / env->sectors[sector].floor_sprites.scale[sprite].y;
	return (0);
}

int			precompute_ceiling_sprite_scales(int sector, int sprite, t_env *env)
{
	env->sectors[sector].ceiling_sprites_scale[sprite].x = env->
	object_sprites[env->sectors[sector].ceiling_sprites.sprite[sprite]].
	size[0].x / env->sectors[sector].ceiling_sprites.scale[sprite].x;
	env->sectors[sector].ceiling_sprites_scale[sprite].y = env->
	object_sprites[env->sectors[sector].ceiling_sprites.sprite[sprite]].
	size[0].y / env->sectors[sector].ceiling_sprites.scale[sprite].y;
	return (0);
}

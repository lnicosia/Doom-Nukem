/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_candle.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/30 11:47:34 by lnicosia          #+#    #+#             */
/*   Updated: 2020/04/30 11:47:34 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

void	init_candle_on(t_env *env)
{
	env->object_sprites[18].texture = env->objects_sprites_start + 1;
	env->object_sprites[18].death_counterpart = 19;
	env->object_sprites[18].nb_death_sprites = 1;
	env->object_sprites[18].oriented = 0;
	env->object_sprites[18].rest_sprite = 18;
	env->object_sprites[18].reversed[0] = 0;
	env->object_sprites[18].start[0].x = 597;
	env->object_sprites[18].start[0].y = 159;
	env->object_sprites[18].end[0].x = 612;
	env->object_sprites[18].end[0].y = 173;
	env->object_sprites[18].size[0].x = 16;
	env->object_sprites[18].size[0].y = 15;
}

void	init_candle_destroyed(t_env *env)
{
	env->object_sprites[19].texture = env->objects_sprites_start + 1;
	env->object_sprites[19].death_counterpart = 19;
	env->object_sprites[19].oriented = 0;
	env->object_sprites[19].rest_sprite = 19;
	env->object_sprites[19].reversed[0] = 0;
	env->object_sprites[19].start[0].x = 528;
	env->object_sprites[19].start[0].y = 280;
	env->object_sprites[19].end[0].x = 558;
	env->object_sprites[19].end[0].y = 293;
	env->object_sprites[19].size[0].x = 31;
	env->object_sprites[19].size[0].y = 14;
}

void	init_candle(t_env *env)
{
	init_candle_on(env);
	init_candle_destroyed(env);
}

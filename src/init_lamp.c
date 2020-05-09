/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_lamp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/30 12:02:27 by lnicosia          #+#    #+#             */
/*   Updated: 2020/04/30 12:02:28 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

void	init_lamp_anim_four(t_env *env)
{
	env->object_sprites[10].texture = env->objects_sprites_start;
	env->object_sprites[10].death_counterpart = 10;
	env->object_sprites[10].oriented = 0;
	env->object_sprites[10].rest_sprite = 7;
	env->object_sprites[10].reversed[0] = 0;
	env->object_sprites[10].start[0].x = 539;
	env->object_sprites[10].start[0].y = 329;
	env->object_sprites[10].end[0].x = 561;
	env->object_sprites[10].end[0].y = 412;
	env->object_sprites[10].size[0].x = 23;
	env->object_sprites[10].size[0].y = 84;
}

void	init_lamp_anim_three(t_env *env)
{
	env->object_sprites[9].texture = env->objects_sprites_start;
	env->object_sprites[9].death_counterpart = 9;
	env->object_sprites[9].oriented = 0;
	env->object_sprites[9].rest_sprite = 10;
	env->object_sprites[9].reversed[0] = 0;
	env->object_sprites[9].start[0].x = 509;
	env->object_sprites[9].start[0].y = 329;
	env->object_sprites[9].end[0].x = 531;
	env->object_sprites[9].end[0].y = 412;
	env->object_sprites[9].size[0].x = 23;
	env->object_sprites[9].size[0].y = 84;
}

void	init_lamp_anim_two(t_env *env)
{
	env->object_sprites[8].texture = env->objects_sprites_start;
	env->object_sprites[8].death_counterpart = 8;
	env->object_sprites[8].oriented = 0;
	env->object_sprites[8].rest_sprite = 9;
	env->object_sprites[8].reversed[0] = 0;
	env->object_sprites[8].start[0].x = 479;
	env->object_sprites[8].start[0].y = 329;
	env->object_sprites[8].end[0].x = 501;
	env->object_sprites[8].end[0].y = 412;
	env->object_sprites[8].size[0].x = 23;
	env->object_sprites[8].size[0].y = 84;
}

void	init_lamp_anim(t_env *env)
{
	env->object_sprites[7].texture = env->objects_sprites_start;
	env->object_sprites[7].death_counterpart = 7;
	env->object_sprites[7].oriented = 0;
	env->object_sprites[7].rest_sprite = 8;
	env->object_sprites[7].reversed[0] = 0;
	env->object_sprites[7].start[0].x = 449;
	env->object_sprites[7].start[0].y = 329;
	env->object_sprites[7].end[0].x = 471;
	env->object_sprites[7].end[0].y = 412;
	env->object_sprites[7].size[0].x = 23;
	env->object_sprites[7].size[0].y = 84;
}

void	init_lamp(t_env *env)
{
	init_lamp_anim(env);
	init_lamp_anim_two(env);
	init_lamp_anim_three(env);
	init_lamp_anim_four(env);
}

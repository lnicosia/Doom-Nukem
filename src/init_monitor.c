/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_monitor.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/30 12:03:23 by lnicosia          #+#    #+#             */
/*   Updated: 2020/04/30 12:03:24 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

void	init_monitor_off(t_env *env)
{
	env->object_sprites[11].texture = 22;
	env->object_sprites[11].death_counterpart = 16;
	env->object_sprites[11].nb_death_sprites = 1;
	env->object_sprites[11].oriented = 0;
	env->object_sprites[11].rest_sprite = 11;
	env->object_sprites[11].reversed[0] = 0;
	env->object_sprites[11].start[0].x = 511;
	env->object_sprites[11].start[0].y = 122;
	env->object_sprites[11].end[0].x = 538;
	env->object_sprites[11].end[0].y = 148;
	env->object_sprites[11].size[0].x = 28;
	env->object_sprites[11].size[0].y = 27;
}

void	init_monitor_anim(t_env *env)
{
	env->object_sprites[12].texture = 22;
	env->object_sprites[12].death_counterpart = 16;
	env->object_sprites[12].nb_death_sprites = 1;
	env->object_sprites[12].oriented = 0;
	env->object_sprites[12].rest_sprite = 13;
	env->object_sprites[12].reversed[0] = 0;
	env->object_sprites[12].start[0].x = 48;
	env->object_sprites[12].start[0].y = 228;
	env->object_sprites[12].end[0].x = 75;
	env->object_sprites[12].end[0].y = 254;
	env->object_sprites[12].size[0].x = 28;
	env->object_sprites[12].size[0].y = 27;
	env->object_sprites[13].texture = 22;
	env->object_sprites[13].death_counterpart = 16;
	env->object_sprites[13].nb_death_sprites = 1;
	env->object_sprites[13].oriented = 0;
	env->object_sprites[13].rest_sprite = 14;
	env->object_sprites[13].reversed[0] = 0;
	env->object_sprites[13].start[0].x = 78;
	env->object_sprites[13].start[0].y = 228;
	env->object_sprites[13].end[0].x = 105;
	env->object_sprites[13].end[0].y = 254;
	env->object_sprites[13].size[0].x = 28;
	env->object_sprites[13].size[0].y = 27;
}

void	init_monitor_anim_two(t_env *env)
{
	env->object_sprites[14].texture = 22;
	env->object_sprites[14].death_counterpart = 16;
	env->object_sprites[14].nb_death_sprites = 1;
	env->object_sprites[14].oriented = 0;
	env->object_sprites[14].rest_sprite = 15;
	env->object_sprites[14].reversed[0] = 0;
	env->object_sprites[14].start[0].x = 108;
	env->object_sprites[14].start[0].y = 228;
	env->object_sprites[14].end[0].x = 135;
	env->object_sprites[14].end[0].y = 254;
	env->object_sprites[14].size[0].x = 28;
	env->object_sprites[14].size[0].y = 27;
	env->object_sprites[15].texture = 22;
	env->object_sprites[15].death_counterpart = 16;
	env->object_sprites[15].nb_death_sprites = 1;
	env->object_sprites[15].oriented = 0;
	env->object_sprites[15].rest_sprite = 12;
	env->object_sprites[15].reversed[0] = 0;
	env->object_sprites[15].start[0].x = 138;
	env->object_sprites[15].start[0].y = 228;
	env->object_sprites[15].end[0].x = 165;
	env->object_sprites[15].end[0].y = 254;
	env->object_sprites[15].size[0].x = 28;
	env->object_sprites[15].size[0].y = 27;
}

void	init_monitor_destroyed(t_env *env)
{
	env->object_sprites[16].texture = 22;
	env->object_sprites[16].death_counterpart = 16;
	env->object_sprites[16].nb_death_sprites = 1;
	env->object_sprites[16].oriented = 0;
	env->object_sprites[16].rest_sprite = 16;
	env->object_sprites[16].reversed[0] = 0;
	env->object_sprites[16].start[0].x = 646;
	env->object_sprites[16].start[0].y = 268;
	env->object_sprites[16].end[0].x = 673;
	env->object_sprites[16].end[0].y = 294;
	env->object_sprites[16].size[0].x = 28;
	env->object_sprites[16].size[0].y = 27;
}

void	init_monitor(t_env *env)
{
	init_monitor_destroyed(env);
	init_monitor_off(env);
	init_monitor_anim(env);
	init_monitor_anim_two(env);
}

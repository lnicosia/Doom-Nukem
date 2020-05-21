/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_rocket.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/30 12:06:28 by lnicosia          #+#    #+#             */
/*   Updated: 2020/04/30 12:06:29 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

void	init_rocket5(t_env *env)
{
	env->object_sprites[1].start[7].x = 110;
	env->object_sprites[1].start[7].y = 817;
	env->object_sprites[1].end[7].x = 141;
	env->object_sprites[1].end[7].y = 830;
	env->object_sprites[1].size[7].x = 32;
	env->object_sprites[1].size[7].y = 14;
	env->object_sprites[1].reversed[7] = 1;
}

void	init_rocket4(t_env *env)
{
	env->object_sprites[1].start[5].x = 33;
	env->object_sprites[1].start[5].y = 817;
	env->object_sprites[1].end[5].x = 58;
	env->object_sprites[1].end[5].y = 830;
	env->object_sprites[1].size[5].x = 26;
	env->object_sprites[1].size[5].y = 14;
	env->object_sprites[1].reversed[5] = 1;
	env->object_sprites[1].start[6].x = 60;
	env->object_sprites[1].start[6].y = 817;
	env->object_sprites[1].end[6].x = 108;
	env->object_sprites[1].end[6].y = 830;
	env->object_sprites[1].size[6].x = 49;
	env->object_sprites[1].size[6].y = 14;
	env->object_sprites[1].reversed[6] = 1;
	init_rocket5(env);
}

void	init_rocket3(t_env *env)
{
	env->object_sprites[1].start[3].x = 33;
	env->object_sprites[1].start[3].y = 817;
	env->object_sprites[1].end[3].x = 58;
	env->object_sprites[1].end[3].y = 830;
	env->object_sprites[1].size[3].x = 26;
	env->object_sprites[1].size[3].y = 14;
	env->object_sprites[1].reversed[3] = 0;
	env->object_sprites[1].start[4].x = 17;
	env->object_sprites[1].start[4].y = 817;
	env->object_sprites[1].end[4].x = 31;
	env->object_sprites[1].end[4].y = 830;
	env->object_sprites[1].size[4].x = 15;
	env->object_sprites[1].size[4].y = 14;
	env->object_sprites[1].reversed[4] = 0;
	init_rocket4(env);
}

void	init_rocket2(t_env *env)
{
	env->object_sprites[1].start[1].x = 110;
	env->object_sprites[1].start[1].y = 817;
	env->object_sprites[1].end[1].x = 141;
	env->object_sprites[1].end[1].y = 830;
	env->object_sprites[1].size[1].x = 32;
	env->object_sprites[1].size[1].y = 14;
	env->object_sprites[1].reversed[1] = 0;
	env->object_sprites[1].start[2].x = 60;
	env->object_sprites[1].start[2].y = 817;
	env->object_sprites[1].end[2].x = 108;
	env->object_sprites[1].end[2].y = 830;
	env->object_sprites[1].size[2].x = 49;
	env->object_sprites[1].size[2].y = 14;
	env->object_sprites[1].reversed[2] = 0;
	init_rocket3(env);
}

void	init_rocket(t_env *env)
{
	env->object_sprites[1].texture = env->objects_sprites_start + 1;
	env->object_sprites[1].death_counterpart = 22;
	env->object_sprites[1].pursuit_sprite = 1;
	env->object_sprites[1].firing_sprite = 1;
	env->object_sprites[1].rest_sprite = 1;
	env->object_sprites[1].curr_sprite = 1;
	env->object_sprites[1].oriented = 1;
	env->object_sprites[1].nb_death_sprites = 3;
	env->object_sprites[1].start[0].x = 1;
	env->object_sprites[1].start[0].y = 817;
	env->object_sprites[1].end[0].x = 15;
	env->object_sprites[1].end[0].y = 830;
	env->object_sprites[1].size[0].x = 15;
	env->object_sprites[1].size[0].y = 14;
	env->object_sprites[1].reversed[0] = 0;
	init_rocket2(env);
}

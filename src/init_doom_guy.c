/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_doom_guy.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/30 11:49:00 by lnicosia          #+#    #+#             */
/*   Updated: 2020/04/30 11:49:01 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

void	init_doom_guy_four(t_env *env)
{
	env->object_sprites[33].start[6].x = 540;
	env->object_sprites[33].start[6].y = 421;
	env->object_sprites[33].end[6].x = 596;
	env->object_sprites[33].end[6].y = 476;
	env->object_sprites[33].size[6].x = 56;
	env->object_sprites[33].size[6].y = 56;
	env->object_sprites[33].reversed[6] = 1;
	env->object_sprites[33].start[7].x = 640;
	env->object_sprites[33].start[7].y = 421;
	env->object_sprites[33].end[7].x = 688;
	env->object_sprites[33].end[7].y = 476;
	env->object_sprites[33].size[7].x = 48;
	env->object_sprites[33].size[7].y = 56;
	env->object_sprites[33].reversed[7] = 1;
}

void	init_doom_guy_three(t_env *env)
{
	env->object_sprites[33].start[4].x = 378;
	env->object_sprites[33].start[4].y = 421;
	env->object_sprites[33].end[4].x = 404;
	env->object_sprites[33].end[4].y = 472;
	env->object_sprites[33].size[4].x = 26;
	env->object_sprites[33].size[4].y = 51;
	env->object_sprites[33].reversed[4] = 1;
	env->object_sprites[33].start[5].x = 448;
	env->object_sprites[33].start[5].y = 421;
	env->object_sprites[33].end[5].x = 496;
	env->object_sprites[33].end[5].y = 477;
	env->object_sprites[33].size[5].x = 48;
	env->object_sprites[33].size[5].y = 56;
	env->object_sprites[33].reversed[5] = 1;
	init_doom_guy_four(env);
}

void	init_doom_guy_two(t_env *env)
{
	env->object_sprites[33].start[2].x = 201;
	env->object_sprites[33].start[2].y = 421;
	env->object_sprites[33].end[2].x = 252;
	env->object_sprites[33].end[2].y = 474;
	env->object_sprites[33].size[2].x = 51;
	env->object_sprites[33].size[2].y = 53;
	env->object_sprites[33].reversed[2] = 1;
	env->object_sprites[33].start[3].x = 296;
	env->object_sprites[33].start[3].y = 421;
	env->object_sprites[33].end[3].x = 334;
	env->object_sprites[33].end[3].y = 473;
	env->object_sprites[33].size[3].x = 38;
	env->object_sprites[33].size[3].y = 52;
	env->object_sprites[33].reversed[3] = 1;
	init_doom_guy_three(env);
}

void	init_doom_guy(t_env *env)
{
	env->object_sprites[33].texture = env->editor_start;
	env->object_sprites[33].oriented = 1;
	env->object_sprites[33].rest_sprite = 33;
	env->object_sprites[33].start[0].x = 44;
	env->object_sprites[33].start[0].y = 421;
	env->object_sprites[33].end[0].x = 70;
	env->object_sprites[33].end[0].y = 476;
	env->object_sprites[33].size[0].x = 26;
	env->object_sprites[33].size[0].y = 56;
	env->object_sprites[33].reversed[0] = 1;
	env->object_sprites[33].start[1].x = 114;
	env->object_sprites[33].start[1].y = 421;
	env->object_sprites[33].end[1].x = 157;
	env->object_sprites[33].end[1].y = 476;
	env->object_sprites[33].size[1].x = 43;
	env->object_sprites[33].size[1].y = 55;
	env->object_sprites[33].reversed[1] = 1;
	init_doom_guy_two(env);
}

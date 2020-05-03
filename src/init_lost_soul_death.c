/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_lost_soul_death.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/30 12:02:42 by lnicosia          #+#    #+#             */
/*   Updated: 2020/04/30 12:02:43 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

void	init_lost_soul_death4(t_env *env)
{
	env->enemy_sprites[4].start[5].x = 535;
	env->enemy_sprites[4].start[5].y = 448;
	env->enemy_sprites[4].end[5].x = 637;
	env->enemy_sprites[4].end[5].y = 537;
	env->enemy_sprites[4].size[5].x = 103;
	env->enemy_sprites[4].size[5].y = 90;
	env->enemy_sprites[4].reversed[5] = 0;
}

void	init_lost_soul_death3(t_env *env)
{
	env->enemy_sprites[4].start[3].x = 291;
	env->enemy_sprites[4].start[3].y = 448;
	env->enemy_sprites[4].end[3].x = 358;
	env->enemy_sprites[4].end[3].y = 507;
	env->enemy_sprites[4].size[3].x = 68;
	env->enemy_sprites[4].size[3].y = 60;
	env->enemy_sprites[4].reversed[3] = 0;
	env->enemy_sprites[4].start[4].x = 403;
	env->enemy_sprites[4].start[4].y = 448;
	env->enemy_sprites[4].end[4].x = 490;
	env->enemy_sprites[4].end[4].y = 519;
	env->enemy_sprites[4].size[4].x = 88;
	env->enemy_sprites[4].size[4].y = 72;
	env->enemy_sprites[4].reversed[4] = 0;
	init_lost_soul_death4(env);
}

void	init_lost_soul_death2(t_env *env)
{
	env->enemy_sprites[4].start[1].x = 122;
	env->enemy_sprites[4].start[1].y = 448;
	env->enemy_sprites[4].end[1].x = 157;
	env->enemy_sprites[4].end[1].y = 500;
	env->enemy_sprites[4].size[1].x = 36;
	env->enemy_sprites[4].size[1].y = 53;
	env->enemy_sprites[4].reversed[1] = 0;
	env->enemy_sprites[4].start[2].x = 202;
	env->enemy_sprites[4].start[2].y = 448;
	env->enemy_sprites[4].end[2].x = 246;
	env->enemy_sprites[4].end[2].y = 495;
	env->enemy_sprites[4].size[2].x = 45;
	env->enemy_sprites[4].size[2].y = 48;
	env->enemy_sprites[4].reversed[2] = 0;
	init_lost_soul_death3(env);
}

void	init_lost_soul_death(t_env *env)
{
	env->enemy_sprites[4].texture = 23;
	env->enemy_sprites[4].death_counterpart = 4;
	env->enemy_sprites[4].pursuit_sprite = 4;
	env->enemy_sprites[4].firing_sprite = 4;
	env->enemy_sprites[4].rest_sprite = 4;
	env->enemy_sprites[4].curr_sprite = 4;
	env->enemy_sprites[4].oriented = 0;
	env->enemy_sprites[4].nb_death_sprites = 6;
	env->enemy_sprites[4].start[0].x = 44;
	env->enemy_sprites[4].start[0].y = 448;
	env->enemy_sprites[4].end[0].x = 77;
	env->enemy_sprites[4].end[0].y = 498;
	env->enemy_sprites[4].size[0].x = 34;
	env->enemy_sprites[4].size[0].y = 51;
	env->enemy_sprites[4].reversed[0] = 0;
	init_lost_soul_death2(env);
}

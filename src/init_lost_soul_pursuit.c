/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_lost_soul_pursuit.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/30 12:02:53 by lnicosia          #+#    #+#             */
/*   Updated: 2020/04/30 12:02:54 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

void	init_lost_soul_pursuit5(t_env *env)
{
	env->enemy_sprites[2].start[7].x = 132;
	env->enemy_sprites[2].start[7].y = 207;
	env->enemy_sprites[2].end[7].x = 191;
	env->enemy_sprites[2].end[7].y = 242;
	env->enemy_sprites[2].size[7].x = 60;
	env->enemy_sprites[2].size[7].y = 36;
	env->enemy_sprites[2].reversed[7] = 1;
}

void	init_lost_soul_pursuit4(t_env *env)
{
	env->enemy_sprites[2].start[5].x = 347;
	env->enemy_sprites[2].start[5].y = 207;
	env->enemy_sprites[2].end[5].x = 400;
	env->enemy_sprites[2].end[5].y = 238;
	env->enemy_sprites[2].size[5].x = 54;
	env->enemy_sprites[2].size[5].y = 32;
	env->enemy_sprites[2].reversed[5] = 1;
	env->enemy_sprites[2].start[6].x = 236;
	env->enemy_sprites[2].start[6].y = 207;
	env->enemy_sprites[2].end[6].x = 302;
	env->enemy_sprites[2].end[6].y = 239;
	env->enemy_sprites[2].size[6].x = 67;
	env->enemy_sprites[2].size[6].y = 33;
	env->enemy_sprites[2].reversed[6] = 1;
	init_lost_soul_pursuit5(env);
}

void	init_lost_soul_pursuit3(t_env *env)
{
	env->enemy_sprites[2].start[3].x = 347;
	env->enemy_sprites[2].start[3].y = 207;
	env->enemy_sprites[2].end[3].x = 400;
	env->enemy_sprites[2].end[3].y = 238;
	env->enemy_sprites[2].size[3].x = 54;
	env->enemy_sprites[2].size[3].y = 32;
	env->enemy_sprites[2].reversed[3] = 0;
	env->enemy_sprites[2].start[4].x = 445;
	env->enemy_sprites[2].start[4].y = 207;
	env->enemy_sprites[2].end[4].x = 488;
	env->enemy_sprites[2].end[4].y = 232;
	env->enemy_sprites[2].size[4].x = 44;
	env->enemy_sprites[2].size[4].y = 26;
	env->enemy_sprites[2].reversed[4] = 0;
	init_lost_soul_pursuit4(env);
}

void	init_lost_soul_pursuit2(t_env *env)
{
	env->enemy_sprites[2].start[1].x = 132;
	env->enemy_sprites[2].start[1].y = 207;
	env->enemy_sprites[2].end[1].x = 191;
	env->enemy_sprites[2].end[1].y = 242;
	env->enemy_sprites[2].size[1].x = 60;
	env->enemy_sprites[2].size[1].y = 36;
	env->enemy_sprites[2].reversed[1] = 0;
	env->enemy_sprites[2].start[2].x = 236;
	env->enemy_sprites[2].start[2].y = 207;
	env->enemy_sprites[2].end[2].x = 302;
	env->enemy_sprites[2].end[2].y = 239;
	env->enemy_sprites[2].size[2].x = 67;
	env->enemy_sprites[2].size[2].y = 33;
	env->enemy_sprites[2].reversed[2] = 0;
	init_lost_soul_pursuit3(env);
}

void	init_lost_soul_pursuit(t_env *env)
{
	env->enemy_sprites[2].texture = env->enemies_start;
	env->enemy_sprites[2].death_counterpart = 4;
	env->enemy_sprites[2].pursuit_sprite = 3;
	env->enemy_sprites[2].firing_sprite = 3;
	env->enemy_sprites[2].rest_sprite = 0;
	env->enemy_sprites[2].curr_sprite = 2;
	env->enemy_sprites[2].oriented = 1;
	env->enemy_sprites[2].nb_death_sprites = 6;
	env->enemy_sprites[2].start[0].x = 44;
	env->enemy_sprites[2].start[0].y = 207;
	env->enemy_sprites[2].end[0].x = 87;
	env->enemy_sprites[2].end[0].y = 250;
	env->enemy_sprites[2].size[0].x = 44;
	env->enemy_sprites[2].size[0].y = 44;
	env->enemy_sprites[2].reversed[0] = 0;
	init_lost_soul_pursuit2(env);
}

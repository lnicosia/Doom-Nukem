/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_lost_soul_pursuit_two.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/30 12:02:49 by lnicosia          #+#    #+#             */
/*   Updated: 2020/04/30 12:02:50 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

void	init_lost_soul_pursuit_two5(t_env *env)
{
	env->enemy_sprites[3].start[7].x = 132;
	env->enemy_sprites[3].start[7].y = 284;
	env->enemy_sprites[3].end[7].x = 184;
	env->enemy_sprites[3].end[7].y = 319;
	env->enemy_sprites[3].size[7].x = 53;
	env->enemy_sprites[3].size[7].y = 36;
	env->enemy_sprites[3].reversed[7] = 1;
}

void	init_lost_soul_pursuit_two4(t_env *env)
{
	env->enemy_sprites[3].start[5].x = 340;
	env->enemy_sprites[3].start[5].y = 284;
	env->enemy_sprites[3].end[5].x = 387;
	env->enemy_sprites[3].end[5].y = 315;
	env->enemy_sprites[3].size[5].x = 48;
	env->enemy_sprites[3].size[5].y = 32;
	env->enemy_sprites[3].reversed[5] = 1;
	env->enemy_sprites[3].start[6].x = 229;
	env->enemy_sprites[3].start[6].y = 284;
	env->enemy_sprites[3].end[6].x = 295;
	env->enemy_sprites[3].end[6].y = 316;
	env->enemy_sprites[3].size[6].x = 67;
	env->enemy_sprites[3].size[6].y = 33;
	env->enemy_sprites[3].reversed[6] = 1;
	init_lost_soul_pursuit_two5(env);
}

void	init_lost_soul_pursuit_two3(t_env *env)
{
	env->enemy_sprites[3].start[3].x = 340;
	env->enemy_sprites[3].start[3].y = 284;
	env->enemy_sprites[3].end[3].x = 387;
	env->enemy_sprites[3].end[3].y = 315;
	env->enemy_sprites[3].size[3].x = 48;
	env->enemy_sprites[3].size[3].y = 32;
	env->enemy_sprites[3].reversed[3] = 0;
	env->enemy_sprites[3].start[4].x = 433;
	env->enemy_sprites[3].start[4].y = 284;
	env->enemy_sprites[3].end[4].x = 475;
	env->enemy_sprites[3].end[4].y = 309;
	env->enemy_sprites[3].size[4].x = 44;
	env->enemy_sprites[3].size[4].y = 26;
	env->enemy_sprites[3].reversed[4] = 0;
	init_lost_soul_pursuit_two4(env);
}

void	init_lost_soul_pursuit_two2(t_env *env)
{
	env->enemy_sprites[3].start[1].x = 132;
	env->enemy_sprites[3].start[1].y = 284;
	env->enemy_sprites[3].end[1].x = 184;
	env->enemy_sprites[3].end[1].y = 319;
	env->enemy_sprites[3].size[1].x = 53;
	env->enemy_sprites[3].size[1].y = 36;
	env->enemy_sprites[3].reversed[1] = 0;
	env->enemy_sprites[3].start[2].x = 229;
	env->enemy_sprites[3].start[2].y = 284;
	env->enemy_sprites[3].end[2].x = 295;
	env->enemy_sprites[3].end[2].y = 316;
	env->enemy_sprites[3].size[2].x = 67;
	env->enemy_sprites[3].size[2].y = 33;
	env->enemy_sprites[3].reversed[2] = 0;
	init_lost_soul_pursuit_two3(env);
}

void	init_lost_soul_pursuit_two(t_env *env)
{
	env->enemy_sprites[3].texture = 23;
	env->enemy_sprites[3].death_counterpart = 4;
	env->enemy_sprites[3].pursuit_sprite = 2;
	env->enemy_sprites[3].firing_sprite = 2;
	env->enemy_sprites[3].rest_sprite = 0;
	env->enemy_sprites[3].curr_sprite = 3;
	env->enemy_sprites[3].oriented = 1;
	env->enemy_sprites[3].nb_death_sprites = 6;
	env->enemy_sprites[3].start[0].x = 44;
	env->enemy_sprites[3].start[0].y = 284;
	env->enemy_sprites[3].end[0].x = 87;
	env->enemy_sprites[3].end[0].y = 327;
	env->enemy_sprites[3].size[0].x = 44;
	env->enemy_sprites[3].size[0].y = 44;
	env->enemy_sprites[3].reversed[0] = 0;
	init_lost_soul_pursuit_two2(env);
}

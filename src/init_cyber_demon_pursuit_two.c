/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_cyber_demon_pursuit_two.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/30 11:48:46 by lnicosia          #+#    #+#             */
/*   Updated: 2020/04/30 11:48:47 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

void	init_cyber_demon_pursuit_two5(t_env *env)
{
	env->enemy_sprites[6].start[7].x = 173;
	env->enemy_sprites[6].start[7].y = 176;
	env->enemy_sprites[6].end[7].x = 246;
	env->enemy_sprites[6].end[7].y = 283;
	env->enemy_sprites[6].size[7].x = 74;
	env->enemy_sprites[6].size[7].y = 108;
	env->enemy_sprites[6].reversed[7] = 0;
}

void	init_cyber_demon_pursuit_two4(t_env *env)
{
	env->enemy_sprites[6].start[5].x = 394;
	env->enemy_sprites[6].start[5].y = 176;
	env->enemy_sprites[6].end[5].x = 478;
	env->enemy_sprites[6].end[5].y = 285;
	env->enemy_sprites[6].size[5].x = 85;
	env->enemy_sprites[6].size[5].y = 110;
	env->enemy_sprites[6].reversed[5] = 0;
	env->enemy_sprites[6].start[6].x = 291;
	env->enemy_sprites[6].start[6].y = 176;
	env->enemy_sprites[6].end[6].x = 349;
	env->enemy_sprites[6].end[6].y = 283;
	env->enemy_sprites[6].size[6].x = 59;
	env->enemy_sprites[6].size[6].y = 108;
	env->enemy_sprites[6].reversed[6] = 0;
	init_cyber_demon_pursuit_two5(env);
}

void	init_cyber_demon_pursuit_two3(t_env *env)
{
	env->enemy_sprites[6].start[3].x = 651;
	env->enemy_sprites[6].start[3].y = 176;
	env->enemy_sprites[6].end[3].x = 725;
	env->enemy_sprites[6].end[3].y = 283;
	env->enemy_sprites[6].size[3].x = 75;
	env->enemy_sprites[6].size[3].y = 108;
	env->enemy_sprites[6].reversed[3] = 0;
	env->enemy_sprites[6].start[4].x = 523;
	env->enemy_sprites[6].start[4].y = 176;
	env->enemy_sprites[6].end[4].x = 606;
	env->enemy_sprites[6].end[4].y = 283;
	env->enemy_sprites[6].size[4].x = 84;
	env->enemy_sprites[6].size[4].y = 108;
	env->enemy_sprites[6].reversed[4] = 0;
	init_cyber_demon_pursuit_two4(env);
}

void	init_cyber_demon_pursuit_two2(t_env *env)
{
	env->enemy_sprites[6].start[1].x = 873;
	env->enemy_sprites[6].start[1].y = 176;
	env->enemy_sprites[6].end[1].x = 955;
	env->enemy_sprites[6].end[1].y = 284;
	env->enemy_sprites[6].size[1].x = 83;
	env->enemy_sprites[6].size[1].y = 109;
	env->enemy_sprites[6].reversed[1] = 0;
	env->enemy_sprites[6].start[2].x = 770;
	env->enemy_sprites[6].start[2].y = 176;
	env->enemy_sprites[6].end[2].x = 828;
	env->enemy_sprites[6].end[2].y = 284;
	env->enemy_sprites[6].size[2].x = 59;
	env->enemy_sprites[6].size[2].y = 109;
	env->enemy_sprites[6].reversed[2] = 0;
	init_cyber_demon_pursuit_two3(env);
}

void	init_cyber_demon_pursuit_two(t_env *env)
{
	env->enemy_sprites[6].texture = env->enemies_start;
	env->enemy_sprites[6].death_counterpart = 12;
	env->enemy_sprites[6].pursuit_sprite = 7;
	env->enemy_sprites[6].firing_sprite = 9;
	env->enemy_sprites[6].rest_sprite = 6;
	env->enemy_sprites[6].curr_sprite = 6;
	env->enemy_sprites[6].oriented = 1;
	env->enemy_sprites[6].nb_death_sprites = 8;
	env->enemy_sprites[6].start[0].x = 44;
	env->enemy_sprites[6].start[0].y = 176;
	env->enemy_sprites[6].end[0].x = 128;
	env->enemy_sprites[6].end[0].y = 284;
	env->enemy_sprites[6].size[0].x = 85;
	env->enemy_sprites[6].size[0].y = 109;
	env->enemy_sprites[6].reversed[0] = 0;
	init_cyber_demon_pursuit_two2(env);
}

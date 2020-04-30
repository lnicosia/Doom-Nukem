/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_cyber_demon_pursuit.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/30 11:48:49 by lnicosia          #+#    #+#             */
/*   Updated: 2020/04/30 11:48:52 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

void	init_cyber_demon_pursuit5(t_env *env)
{
	env->enemy_sprites[5].start[7].x = 170;
	env->enemy_sprites[5].start[7].y = 33;
	env->enemy_sprites[5].end[7].x = 256;
	env->enemy_sprites[5].end[7].y = 139;
	env->enemy_sprites[5].size[7].x = 87;
	env->enemy_sprites[5].size[7].y = 107;
	env->enemy_sprites[5].reversed[7] = 0;
}

void	init_cyber_demon_pursuit4(t_env *env)
{
	env->enemy_sprites[5].start[5].x = 424;
	env->enemy_sprites[5].start[5].y = 33;
	env->enemy_sprites[5].end[5].x = 499;
	env->enemy_sprites[5].end[5].y = 142;
	env->enemy_sprites[5].size[5].x = 76;
	env->enemy_sprites[5].size[5].y = 110;
	env->enemy_sprites[5].reversed[5] = 0;
	env->enemy_sprites[5].start[6].x = 301;
	env->enemy_sprites[5].start[6].y = 33;
	env->enemy_sprites[5].end[6].x = 379;
	env->enemy_sprites[5].end[6].y = 139;
	env->enemy_sprites[5].size[6].x = 79;
	env->enemy_sprites[5].size[6].y = 107;
	env->enemy_sprites[5].reversed[6] = 0;
	init_cyber_demon_pursuit5(env);
}

void	init_cyber_demon_pursuit3(t_env *env)
{
	env->enemy_sprites[5].start[3].x = 670;
	env->enemy_sprites[5].start[3].y = 33;
	env->enemy_sprites[5].end[3].x = 752;
	env->enemy_sprites[5].end[3].y = 142;
	env->enemy_sprites[5].size[3].x = 83;
	env->enemy_sprites[5].size[3].y = 110;
	env->enemy_sprites[5].reversed[3] = 0;
	env->enemy_sprites[5].start[4].x = 544;
	env->enemy_sprites[5].start[4].y = 33;
	env->enemy_sprites[5].end[4].x = 625;
	env->enemy_sprites[5].end[4].y = 142;
	env->enemy_sprites[5].size[4].x = 82;
	env->enemy_sprites[5].size[4].y = 110;
	env->enemy_sprites[5].reversed[4] = 0;
	init_cyber_demon_pursuit4(env);
}

void	init_cyber_demon_pursuit2(t_env *env)
{
	env->enemy_sprites[5].start[1].x = 925;
	env->enemy_sprites[5].start[1].y = 33;
	env->enemy_sprites[5].end[1].x = 999;
	env->enemy_sprites[5].end[1].y = 141;
	env->enemy_sprites[5].size[1].x = 75;
	env->enemy_sprites[5].size[1].y = 109;
	env->enemy_sprites[5].reversed[1] = 0;
	env->enemy_sprites[5].start[2].x = 798;
	env->enemy_sprites[5].start[2].y = 33;
	env->enemy_sprites[5].end[2].x = 880;
	env->enemy_sprites[5].end[2].y = 141;
	env->enemy_sprites[5].size[2].x = 84;
	env->enemy_sprites[5].size[2].y = 109;
	env->enemy_sprites[5].reversed[2] = 0;
	init_cyber_demon_pursuit3(env);
}

void	init_cyber_demon_pursuit(t_env *env)
{
	env->enemy_sprites[5].texture = 24;
	env->enemy_sprites[5].death_counterpart = 12;
	env->enemy_sprites[5].pursuit_sprite = 6;
	env->enemy_sprites[5].firing_sprite = 9;
	env->enemy_sprites[5].rest_sprite = 6;
	env->enemy_sprites[5].curr_sprite = 5;
	env->enemy_sprites[5].oriented = 1;
	env->enemy_sprites[5].nb_death_sprites = 8;
	env->enemy_sprites[5].start[0].x = 44;
	env->enemy_sprites[5].start[0].y = 33;
	env->enemy_sprites[5].end[0].x = 125;
	env->enemy_sprites[5].end[0].y = 140;
	env->enemy_sprites[5].size[0].x = 82;
	env->enemy_sprites[5].size[0].y = 108;
	env->enemy_sprites[5].reversed[0] = 0;
	init_cyber_demon_pursuit2(env);
}

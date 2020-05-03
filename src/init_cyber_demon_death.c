/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_cyber_demon_death.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/30 11:47:49 by lnicosia          #+#    #+#             */
/*   Updated: 2020/04/30 11:47:50 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

void	init_cyber_demon_death5(t_env *env)
{
	env->enemy_sprites[12].start[7].x = 1200;
	env->enemy_sprites[12].start[7].y = 1038;
	env->enemy_sprites[12].end[7].x = 1338;
	env->enemy_sprites[12].end[7].y = 1171;
	env->enemy_sprites[12].size[7].x = 139;
	env->enemy_sprites[12].size[7].y = 134;
	env->enemy_sprites[12].reversed[7] = 0;
}

void	init_cyber_demon_death4(t_env *env)
{
	env->enemy_sprites[12].start[5].x = 836;
	env->enemy_sprites[12].start[5].y = 1038;
	env->enemy_sprites[12].end[5].x = 970;
	env->enemy_sprites[12].end[5].y = 1168;
	env->enemy_sprites[12].size[5].x = 136;
	env->enemy_sprites[12].size[5].y = 131;
	env->enemy_sprites[12].reversed[5] = 0;
	env->enemy_sprites[12].start[6].x = 1015;
	env->enemy_sprites[12].start[6].y = 1038;
	env->enemy_sprites[12].end[6].x = 1155;
	env->enemy_sprites[12].end[6].y = 1171;
	env->enemy_sprites[12].size[6].x = 141;
	env->enemy_sprites[12].size[6].y = 134;
	env->enemy_sprites[12].reversed[6] = 0;
	init_cyber_demon_death5(env);
}

void	init_cyber_demon_death3(t_env *env)
{
	env->enemy_sprites[12].start[3].x = 509;
	env->enemy_sprites[12].start[3].y = 1038;
	env->enemy_sprites[12].end[3].x = 621;
	env->enemy_sprites[12].end[3].y = 1154;
	env->enemy_sprites[12].size[3].x = 113;
	env->enemy_sprites[12].size[3].y = 117;
	env->enemy_sprites[12].reversed[3] = 0;
	env->enemy_sprites[12].start[4].x = 666;
	env->enemy_sprites[12].start[4].y = 1038;
	env->enemy_sprites[12].end[4].x = 790;
	env->enemy_sprites[12].end[4].y = 1161;
	env->enemy_sprites[12].size[4].x = 125;
	env->enemy_sprites[12].size[4].y = 124;
	env->enemy_sprites[12].reversed[4] = 0;
	init_cyber_demon_death4(env);
}

void	init_cyber_demon_death2(t_env *env)
{
	env->enemy_sprites[12].start[1].x = 210;
	env->enemy_sprites[12].start[1].y = 1038;
	env->enemy_sprites[12].end[1].x = 320;
	env->enemy_sprites[12].end[1].y = 1150;
	env->enemy_sprites[12].size[1].x = 111;
	env->enemy_sprites[12].size[1].y = 113;
	env->enemy_sprites[12].reversed[1] = 0;
	env->enemy_sprites[12].start[2].x = 365;
	env->enemy_sprites[12].start[2].y = 1038;
	env->enemy_sprites[12].end[2].x = 464;
	env->enemy_sprites[12].end[2].y = 1153;
	env->enemy_sprites[12].size[2].x = 100;
	env->enemy_sprites[12].size[2].y = 116;
	env->enemy_sprites[12].reversed[2] = 0;
	init_cyber_demon_death3(env);
}

void	init_cyber_demon_death(t_env *env)
{
	env->enemy_sprites[12].texture = 24;
	env->enemy_sprites[12].death_counterpart = 12;
	env->enemy_sprites[12].pursuit_sprite = 12;
	env->enemy_sprites[12].firing_sprite = 12;
	env->enemy_sprites[12].rest_sprite = 12;
	env->enemy_sprites[12].curr_sprite = 12;
	env->enemy_sprites[12].oriented = 0;
	env->enemy_sprites[12].nb_death_sprites = 8;
	env->enemy_sprites[12].start[0].x = 44;
	env->enemy_sprites[12].start[0].y = 1038;
	env->enemy_sprites[12].end[0].x = 165;
	env->enemy_sprites[12].end[0].y = 1148;
	env->enemy_sprites[12].size[0].x = 122;
	env->enemy_sprites[12].size[0].y = 111;
	env->enemy_sprites[12].reversed[0] = 0;
	init_cyber_demon_death2(env);
}

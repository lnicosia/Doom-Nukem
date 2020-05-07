/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_cyber_demon_pursuit_three.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/30 11:48:42 by lnicosia          #+#    #+#             */
/*   Updated: 2020/04/30 11:48:43 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

void	init_cyber_demon_pursuit_three5(t_env *env)
{
	env->enemy_sprites[7].start[7].x = 170;
	env->enemy_sprites[7].start[7].y = 319;
	env->enemy_sprites[7].end[7].x = 250;
	env->enemy_sprites[7].end[7].y = 427;
	env->enemy_sprites[7].size[7].x = 81;
	env->enemy_sprites[7].size[7].y = 109;
	env->enemy_sprites[7].reversed[7] = 0;
}

void	init_cyber_demon_pursuit_three4(t_env *env)
{
	env->enemy_sprites[7].start[5].x = 419;
	env->enemy_sprites[7].start[5].y = 319;
	env->enemy_sprites[7].end[5].x = 510;
	env->enemy_sprites[7].end[5].y = 429;
	env->enemy_sprites[7].size[5].x = 92;
	env->enemy_sprites[7].size[5].y = 111;
	env->enemy_sprites[7].reversed[5] = 0;
	env->enemy_sprites[7].start[6].x = 295;
	env->enemy_sprites[7].start[6].y = 319;
	env->enemy_sprites[7].end[6].x = 374;
	env->enemy_sprites[7].end[6].y = 425;
	env->enemy_sprites[7].size[6].x = 80;
	env->enemy_sprites[7].size[6].y = 107;
	env->enemy_sprites[7].reversed[6] = 0;
	init_cyber_demon_pursuit_three5(env);
}

void	init_cyber_demon_pursuit_three3(t_env *env)
{
	env->enemy_sprites[7].start[3].x = 682;
	env->enemy_sprites[7].start[3].y = 319;
	env->enemy_sprites[7].end[3].x = 761;
	env->enemy_sprites[7].end[3].y = 428;
	env->enemy_sprites[7].size[3].x = 80;
	env->enemy_sprites[7].size[3].y = 110;
	env->enemy_sprites[7].reversed[3] = 0;
	env->enemy_sprites[7].start[4].x = 555;
	env->enemy_sprites[7].start[4].y = 319;
	env->enemy_sprites[7].end[4].x = 637;
	env->enemy_sprites[7].end[4].y = 428;
	env->enemy_sprites[7].size[4].x = 83;
	env->enemy_sprites[7].size[4].y = 110;
	env->enemy_sprites[7].reversed[4] = 0;
	init_cyber_demon_pursuit_three4(env);
}

void	init_cyber_demon_pursuit_three2(t_env *env)
{
	env->enemy_sprites[7].start[1].x = 926;
	env->enemy_sprites[7].start[1].y = 319;
	env->enemy_sprites[7].end[1].x = 1020;
	env->enemy_sprites[7].end[1].y = 430;
	env->enemy_sprites[7].size[1].x = 95;
	env->enemy_sprites[7].size[1].y = 112;
	env->enemy_sprites[7].reversed[1] = 0;
	env->enemy_sprites[7].start[2].x = 806;
	env->enemy_sprites[7].start[2].y = 319;
	env->enemy_sprites[7].end[2].x = 881;
	env->enemy_sprites[7].end[2].y = 429;
	env->enemy_sprites[7].size[2].x = 76;
	env->enemy_sprites[7].size[2].y = 111;
	env->enemy_sprites[7].reversed[2] = 0;
	init_cyber_demon_pursuit_three3(env);
}

void	init_cyber_demon_pursuit_three(t_env *env)
{
	env->enemy_sprites[7].texture = env->enemies_start;
	env->enemy_sprites[7].death_counterpart = 12;
	env->enemy_sprites[7].pursuit_sprite = 8;
	env->enemy_sprites[7].firing_sprite = 9;
	env->enemy_sprites[7].rest_sprite = 8;
	env->enemy_sprites[7].curr_sprite = 7;
	env->enemy_sprites[7].oriented = 1;
	env->enemy_sprites[7].nb_death_sprites = 8;
	env->enemy_sprites[7].start[0].x = 44;
	env->enemy_sprites[7].start[0].y = 319;
	env->enemy_sprites[7].end[0].x = 125;
	env->enemy_sprites[7].end[0].y = 428;
	env->enemy_sprites[7].size[0].x = 82;
	env->enemy_sprites[7].size[0].y = 110;
	env->enemy_sprites[7].reversed[0] = 0;
	init_cyber_demon_pursuit_three2(env);
}

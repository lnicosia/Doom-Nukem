/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_cyber_demon_firing_anim_three.c               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/30 11:48:24 by lnicosia          #+#    #+#             */
/*   Updated: 2020/04/30 11:48:25 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

void	init_cyber_demon_firing_anim_three5(t_env *env)
{
	env->enemy_sprites[11].start[7].x = 1046;
	env->enemy_sprites[11].start[7].y = 894;
	env->enemy_sprites[11].end[7].x = 1152;
	env->enemy_sprites[11].end[7].y = 1002;
	env->enemy_sprites[11].size[7].x = 107;
	env->enemy_sprites[11].size[7].y = 109;
	env->enemy_sprites[11].reversed[7] = 0;
}

void	init_cyber_demon_firing_anim_three4(t_env *env)
{
	env->enemy_sprites[11].start[5].x = 792;
	env->enemy_sprites[11].start[5].y = 894;
	env->enemy_sprites[11].end[5].x = 882;
	env->enemy_sprites[11].end[5].y = 1003;
	env->enemy_sprites[11].size[5].x = 91;
	env->enemy_sprites[11].size[5].y = 110;
	env->enemy_sprites[11].reversed[5] = 0;
	env->enemy_sprites[11].start[6].x = 927;
	env->enemy_sprites[11].start[6].y = 894;
	env->enemy_sprites[11].end[6].x = 1001;
	env->enemy_sprites[11].end[6].y = 1003;
	env->enemy_sprites[11].size[6].x = 75;
	env->enemy_sprites[11].size[6].y = 110;
	env->enemy_sprites[11].reversed[6] = 0;
	init_cyber_demon_firing_anim_three5(env);
}

void	init_cyber_demon_firing_anim_three3(t_env *env)
{
	env->enemy_sprites[11].start[3].x = 484;
	env->enemy_sprites[11].start[3].y = 894;
	env->enemy_sprites[11].end[3].x = 601;
	env->enemy_sprites[11].end[3].y = 1003;
	env->enemy_sprites[11].size[3].x = 118;
	env->enemy_sprites[11].size[3].y = 110;
	env->enemy_sprites[11].reversed[3] = 0;
	env->enemy_sprites[11].start[4].x = 646;
	env->enemy_sprites[11].start[4].y = 894;
	env->enemy_sprites[11].end[4].x = 747;
	env->enemy_sprites[11].end[4].y = 1002;
	env->enemy_sprites[11].size[4].x = 102;
	env->enemy_sprites[11].size[4].y = 109;
	env->enemy_sprites[11].reversed[4] = 0;
	init_cyber_demon_firing_anim_three4(env);
}

void	init_cyber_demon_firing_anim_three2(t_env *env)
{
	env->enemy_sprites[11].start[1].x = 211;
	env->enemy_sprites[11].start[1].y = 894;
	env->enemy_sprites[11].end[1].x = 301;
	env->enemy_sprites[11].end[1].y = 1004;
	env->enemy_sprites[11].size[1].x = 91;
	env->enemy_sprites[11].size[1].y = 111;
	env->enemy_sprites[11].reversed[1] = 0;
	env->enemy_sprites[11].start[2].x = 346;
	env->enemy_sprites[11].start[2].y = 894;
	env->enemy_sprites[11].end[2].x = 439;
	env->enemy_sprites[11].end[2].y = 1003;
	env->enemy_sprites[11].size[2].x = 94;
	env->enemy_sprites[11].size[2].y = 110;
	env->enemy_sprites[11].reversed[2] = 0;
	init_cyber_demon_firing_anim_three3(env);
}

void	init_cyber_demon_firing_anim_three(t_env *env)
{
	env->enemy_sprites[11].texture = env->enemies_start;
	env->enemy_sprites[11].death_counterpart = 12;
	env->enemy_sprites[11].pursuit_sprite = 5;
	env->enemy_sprites[11].firing_sprite = 9;
	env->enemy_sprites[11].rest_sprite = 5;
	env->enemy_sprites[11].curr_sprite = 11;
	env->enemy_sprites[11].oriented = 1;
	env->enemy_sprites[11].nb_death_sprites = 8;
	env->enemy_sprites[11].start[0].x = 44;
	env->enemy_sprites[11].start[0].y = 894;
	env->enemy_sprites[11].end[0].x = 166;
	env->enemy_sprites[11].end[0].y = 1003;
	env->enemy_sprites[11].size[0].x = 123;
	env->enemy_sprites[11].size[0].y = 110;
	env->enemy_sprites[11].reversed[0] = 0;
	init_cyber_demon_firing_anim_three2(env);
}

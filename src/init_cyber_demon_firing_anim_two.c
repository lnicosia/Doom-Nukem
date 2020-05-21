/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_cyber_demon_firing_anim_two.c                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/30 11:48:30 by lnicosia          #+#    #+#             */
/*   Updated: 2020/04/30 11:48:31 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

void	init_cyber_demon_firing_anim_two5(t_env *env)
{
	env->enemy_sprites[10].start[7].x = 1081;
	env->enemy_sprites[10].start[7].y = 751;
	env->enemy_sprites[10].end[7].x = 1210;
	env->enemy_sprites[10].end[7].y = 860;
	env->enemy_sprites[10].size[7].x = 130;
	env->enemy_sprites[10].size[7].y = 110;
	env->enemy_sprites[10].reversed[7] = 0;
}

void	init_cyber_demon_firing_anim_two4(t_env *env)
{
	env->enemy_sprites[10].start[5].x = 786;
	env->enemy_sprites[10].start[5].y = 751;
	env->enemy_sprites[10].end[5].x = 878;
	env->enemy_sprites[10].end[5].y = 860;
	env->enemy_sprites[10].size[5].x = 93;
	env->enemy_sprites[10].size[5].y = 110;
	env->enemy_sprites[10].reversed[5] = 0;
	env->enemy_sprites[10].start[6].x = 923;
	env->enemy_sprites[10].start[6].y = 751;
	env->enemy_sprites[10].end[6].x = 1036;
	env->enemy_sprites[10].end[6].y = 860;
	env->enemy_sprites[10].size[6].x = 114;
	env->enemy_sprites[10].size[6].y = 110;
	env->enemy_sprites[10].reversed[6] = 0;
	init_cyber_demon_firing_anim_two5(env);
}

void	init_cyber_demon_firing_anim_two3(t_env *env)
{
	env->enemy_sprites[10].start[3].x = 490;
	env->enemy_sprites[10].start[3].y = 751;
	env->enemy_sprites[10].end[3].x = 608;
	env->enemy_sprites[10].end[3].y = 859;
	env->enemy_sprites[10].size[3].x = 119;
	env->enemy_sprites[10].size[3].y = 109;
	env->enemy_sprites[10].reversed[3] = 0;
	env->enemy_sprites[10].start[4].x = 653;
	env->enemy_sprites[10].start[4].y = 751;
	env->enemy_sprites[10].end[4].x = 741;
	env->enemy_sprites[10].end[4].y = 860;
	env->enemy_sprites[10].size[4].x = 89;
	env->enemy_sprites[10].size[4].y = 110;
	env->enemy_sprites[10].reversed[4] = 0;
	init_cyber_demon_firing_anim_two4(env);
}

void	init_cyber_demon_firing_anim_two2(t_env *env)
{
	env->enemy_sprites[10].start[1].x = 187;
	env->enemy_sprites[10].start[1].y = 751;
	env->enemy_sprites[10].end[1].x = 280;
	env->enemy_sprites[10].end[1].y = 860;
	env->enemy_sprites[10].size[1].x = 94;
	env->enemy_sprites[10].size[1].y = 110;
	env->enemy_sprites[10].reversed[1] = 0;
	env->enemy_sprites[10].start[2].x = 325;
	env->enemy_sprites[10].start[2].y = 751;
	env->enemy_sprites[10].end[2].x = 445;
	env->enemy_sprites[10].end[2].y = 860;
	env->enemy_sprites[10].size[2].x = 121;
	env->enemy_sprites[10].size[2].y = 110;
	env->enemy_sprites[10].reversed[2] = 0;
	init_cyber_demon_firing_anim_two3(env);
}

void	init_cyber_demon_firing_anim_two(t_env *env)
{
	env->enemy_sprites[10].texture = env->enemies_start + 1;
	env->enemy_sprites[10].death_counterpart = 12;
	env->enemy_sprites[10].pursuit_sprite = 5;
	env->enemy_sprites[10].firing_sprite = 11;
	env->enemy_sprites[10].rest_sprite = 5;
	env->enemy_sprites[10].curr_sprite = 10;
	env->enemy_sprites[10].oriented = 1;
	env->enemy_sprites[10].nb_death_sprites = 8;
	env->enemy_sprites[10].start[0].x = 44;
	env->enemy_sprites[10].start[0].y = 751;
	env->enemy_sprites[10].end[0].x = 142;
	env->enemy_sprites[10].end[0].y = 860;
	env->enemy_sprites[10].size[0].x = 99;
	env->enemy_sprites[10].size[0].y = 110;
	env->enemy_sprites[10].reversed[0] = 0;
	init_cyber_demon_firing_anim_two2(env);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_cyber_demon_firing_anim.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/30 11:48:12 by lnicosia          #+#    #+#             */
/*   Updated: 2020/04/30 13:32:55 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

void	init_cyber_demon_firing_anim5(t_env *env)
{
	env->enemy_sprites[9].start[7].x = 996;
	env->enemy_sprites[9].start[7].y = 608;
	env->enemy_sprites[9].end[7].x = 1110;
	env->enemy_sprites[9].end[7].y = 717;
	env->enemy_sprites[9].size[7].x = 115;
	env->enemy_sprites[9].size[7].y = 110;
	env->enemy_sprites[9].reversed[7] = 0;
}

void	init_cyber_demon_firing_anim4(t_env *env)
{
	env->enemy_sprites[9].start[5].x = 729;
	env->enemy_sprites[9].start[5].y = 608;
	env->enemy_sprites[9].end[5].x = 810;
	env->enemy_sprites[9].end[5].y = 717;
	env->enemy_sprites[9].size[5].x = 82;
	env->enemy_sprites[9].size[5].y = 110;
	env->enemy_sprites[9].reversed[5] = 0;
	env->enemy_sprites[9].start[6].x = 855;
	env->enemy_sprites[9].start[6].y = 608;
	env->enemy_sprites[9].end[6].x = 951;
	env->enemy_sprites[9].end[6].y = 717;
	env->enemy_sprites[9].size[6].x = 97;
	env->enemy_sprites[9].size[6].y = 110;
	env->enemy_sprites[9].reversed[6] = 0;
	init_cyber_demon_firing_anim5(env);
}

void	init_cyber_demon_firing_anim3(t_env *env)
{
	env->enemy_sprites[9].start[3].x = 450;
	env->enemy_sprites[9].start[3].y = 608;
	env->enemy_sprites[9].end[3].x = 555;
	env->enemy_sprites[9].end[3].y = 716;
	env->enemy_sprites[9].size[3].x = 106;
	env->enemy_sprites[9].size[3].y = 109;
	env->enemy_sprites[9].reversed[3] = 0;
	env->enemy_sprites[9].start[4].x = 600;
	env->enemy_sprites[9].start[4].y = 608;
	env->enemy_sprites[9].end[4].x = 684;
	env->enemy_sprites[9].end[4].y = 717;
	env->enemy_sprites[9].size[4].x = 85;
	env->enemy_sprites[9].size[4].y = 110;
	env->enemy_sprites[9].reversed[4] = 0;
	init_cyber_demon_firing_anim4(env);
}

void	init_cyber_demon_firing_anim2(t_env *env)
{
	env->enemy_sprites[9].start[1].x = 174;
	env->enemy_sprites[9].start[1].y = 608;
	env->enemy_sprites[9].end[1].x = 256;
	env->enemy_sprites[9].end[1].y = 717;
	env->enemy_sprites[9].size[1].x = 83;
	env->enemy_sprites[9].size[1].y = 110;
	env->enemy_sprites[9].reversed[1] = 0;
	env->enemy_sprites[9].start[2].x = 301;
	env->enemy_sprites[9].start[2].y = 608;
	env->enemy_sprites[9].end[2].x = 405;
	env->enemy_sprites[9].end[2].y = 717;
	env->enemy_sprites[9].size[2].x = 105;
	env->enemy_sprites[9].size[2].y = 110;
	env->enemy_sprites[9].reversed[2] = 0;
	init_cyber_demon_firing_anim3(env);
}

void	init_cyber_demon_firing_anim(t_env *env)
{
	env->enemy_sprites[9].texture = env->enemies_start;
	env->enemy_sprites[9].death_counterpart = 12;
	env->enemy_sprites[9].pursuit_sprite = 5;
	env->enemy_sprites[9].firing_sprite = 10;
	env->enemy_sprites[9].rest_sprite = 5;
	env->enemy_sprites[9].curr_sprite = 9;
	env->enemy_sprites[9].oriented = 1;
	env->enemy_sprites[9].nb_death_sprites = 8;
	env->enemy_sprites[9].start[0].x = 44;
	env->enemy_sprites[9].start[0].y = 608;
	env->enemy_sprites[9].end[0].x = 129;
	env->enemy_sprites[9].end[0].y = 717;
	env->enemy_sprites[9].size[0].x = 86;
	env->enemy_sprites[9].size[0].y = 110;
	env->enemy_sprites[9].reversed[0] = 0;
	init_cyber_demon_firing_anim2(env);
}

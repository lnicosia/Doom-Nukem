/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_lost_soul_sprite.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/30 12:03:04 by lnicosia          #+#    #+#             */
/*   Updated: 2020/04/30 12:03:05 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

void	init_lost_soul_sprite5(t_env *env)
{
	env->enemy_sprites[0].start[7].x = 374;
	env->enemy_sprites[0].start[7].y = 120;
	env->enemy_sprites[0].end[7].x = 405;
	env->enemy_sprites[0].end[7].y = 172;
	env->enemy_sprites[0].size[7].x = 32;
	env->enemy_sprites[0].size[7].y = 53;
	env->enemy_sprites[0].reversed[7] = 1;
}

void	init_lost_soul_sprite4(t_env *env)
{
	env->enemy_sprites[0].start[5].x = 220;
	env->enemy_sprites[0].start[5].y = 120;
	env->enemy_sprites[0].end[5].x = 254;
	env->enemy_sprites[0].end[5].y = 171;
	env->enemy_sprites[0].size[5].x = 35;
	env->enemy_sprites[0].size[5].y = 52;
	env->enemy_sprites[0].reversed[5] = 1;
	env->enemy_sprites[0].start[6].x = 299;
	env->enemy_sprites[0].start[6].y = 120;
	env->enemy_sprites[0].end[6].x = 329;
	env->enemy_sprites[0].end[6].y = 173;
	env->enemy_sprites[0].size[6].x = 31;
	env->enemy_sprites[0].size[6].y = 54;
	env->enemy_sprites[0].reversed[6] = 1;
	init_lost_soul_sprite5(env);
}

void	init_lost_soul_sprite3(t_env *env)
{
	env->enemy_sprites[0].start[3].x = 220;
	env->enemy_sprites[0].start[3].y = 120;
	env->enemy_sprites[0].end[3].x = 254;
	env->enemy_sprites[0].end[3].y = 171;
	env->enemy_sprites[0].size[3].x = 35;
	env->enemy_sprites[0].size[3].y = 52;
	env->enemy_sprites[0].reversed[3] = 0;
	env->enemy_sprites[0].start[4].x = 132;
	env->enemy_sprites[0].start[4].y = 120;
	env->enemy_sprites[0].end[4].x = 175;
	env->enemy_sprites[0].end[4].y = 165;
	env->enemy_sprites[0].size[4].x = 44;
	env->enemy_sprites[0].size[4].y = 46;
	env->enemy_sprites[0].reversed[4] = 0;
	init_lost_soul_sprite4(env);
}

void	init_lost_soul_sprite2(t_env *env)
{
	env->enemy_sprites[0].start[1].x = 374;
	env->enemy_sprites[0].start[1].y = 120;
	env->enemy_sprites[0].end[1].x = 405;
	env->enemy_sprites[0].end[1].y = 172;
	env->enemy_sprites[0].size[1].x = 32;
	env->enemy_sprites[0].size[1].y = 53;
	env->enemy_sprites[0].reversed[1] = 0;
	env->enemy_sprites[0].start[2].x = 299;
	env->enemy_sprites[0].start[2].y = 120;
	env->enemy_sprites[0].end[2].x = 329;
	env->enemy_sprites[0].end[2].y = 173;
	env->enemy_sprites[0].size[2].x = 31;
	env->enemy_sprites[0].size[2].y = 54;
	env->enemy_sprites[0].reversed[2] = 0;
	init_lost_soul_sprite3(env);
}

void	init_lost_soul_sprite(t_env *env)
{
	env->enemy_sprites[0].texture = 23;
	env->enemy_sprites[0].death_counterpart = 4;
	env->enemy_sprites[0].pursuit_sprite = 2;
	env->enemy_sprites[0].firing_sprite = 2;
	env->enemy_sprites[0].rest_sprite = 1;
	env->enemy_sprites[0].curr_sprite = 0;
	env->enemy_sprites[0].oriented = 1;
	env->enemy_sprites[0].nb_death_sprites = 6;
	env->enemy_sprites[0].start[0].x = 44;
	env->enemy_sprites[0].start[0].y = 120;
	env->enemy_sprites[0].end[0].x = 87;
	env->enemy_sprites[0].end[0].y = 165;
	env->enemy_sprites[0].size[0].x = 44;
	env->enemy_sprites[0].size[0].y = 46;
	env->enemy_sprites[0].reversed[0] = 0;
	init_lost_soul_sprite2(env);
}

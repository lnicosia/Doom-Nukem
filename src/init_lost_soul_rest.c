/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_lost_soul_rest.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/30 12:03:01 by lnicosia          #+#    #+#             */
/*   Updated: 2020/04/30 12:03:08 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

void	init_lost_soul_rest5(t_env *env)
{
	env->enemy_sprites[1].start[7].x = 132;
	env->enemy_sprites[1].start[7].y = 33;
	env->enemy_sprites[1].end[7].x = 163;
	env->enemy_sprites[1].end[7].y = 79;
	env->enemy_sprites[1].size[7].x = 32;
	env->enemy_sprites[1].size[7].y = 47;
	env->enemy_sprites[1].reversed[7] = 1;
}

void	init_lost_soul_rest4(t_env *env)
{
	env->enemy_sprites[1].start[5].x = 283;
	env->enemy_sprites[1].start[5].y = 33;
	env->enemy_sprites[1].end[5].x = 317;
	env->enemy_sprites[1].end[5].y = 84;
	env->enemy_sprites[1].size[5].x = 35;
	env->enemy_sprites[1].size[5].y = 52;
	env->enemy_sprites[1].reversed[5] = 1;
	env->enemy_sprites[1].start[6].x = 208;
	env->enemy_sprites[1].start[6].y = 33;
	env->enemy_sprites[1].end[6].x = 238;
	env->enemy_sprites[1].end[6].y = 86;
	env->enemy_sprites[1].size[6].x = 31;
	env->enemy_sprites[1].size[6].y = 54;
	env->enemy_sprites[1].reversed[6] = 1;
	init_lost_soul_rest5(env);
}

void	init_lost_soul_rest3(t_env *env)
{
	env->enemy_sprites[1].start[3].x = 283;
	env->enemy_sprites[1].start[3].y = 33;
	env->enemy_sprites[1].end[3].x = 317;
	env->enemy_sprites[1].end[3].y = 84;
	env->enemy_sprites[1].size[3].x = 35;
	env->enemy_sprites[1].size[3].y = 52;
	env->enemy_sprites[1].reversed[3] = 0;
	env->enemy_sprites[1].start[4].x = 362;
	env->enemy_sprites[1].start[4].y = 33;
	env->enemy_sprites[1].end[4].x = 405;
	env->enemy_sprites[1].end[4].y = 78;
	env->enemy_sprites[1].size[4].x = 44;
	env->enemy_sprites[1].size[4].y = 46;
	env->enemy_sprites[1].reversed[4] = 0;
	init_lost_soul_rest4(env);
}

void	init_lost_soul_rest2(t_env *env)
{
	env->enemy_sprites[1].start[1].x = 132;
	env->enemy_sprites[1].start[1].y = 33;
	env->enemy_sprites[1].end[1].x = 163;
	env->enemy_sprites[1].end[1].y = 79;
	env->enemy_sprites[1].size[1].x = 32;
	env->enemy_sprites[1].size[1].y = 47;
	env->enemy_sprites[1].reversed[1] = 0;
	env->enemy_sprites[1].start[2].x = 208;
	env->enemy_sprites[1].start[2].y = 33;
	env->enemy_sprites[1].end[2].x = 238;
	env->enemy_sprites[1].end[2].y = 86;
	env->enemy_sprites[1].size[2].x = 31;
	env->enemy_sprites[1].size[2].y = 54;
	env->enemy_sprites[1].reversed[2] = 0;
	init_lost_soul_rest3(env);
}

void	init_lost_soul_rest(t_env *env)
{
	env->enemy_sprites[1].texture = env->enemies_start + 1;
	env->enemy_sprites[1].death_counterpart = 4;
	env->enemy_sprites[1].pursuit_sprite = 2;
	env->enemy_sprites[1].firing_sprite = 2;
	env->enemy_sprites[1].rest_sprite = 0;
	env->enemy_sprites[1].curr_sprite = 1;
	env->enemy_sprites[1].oriented = 1;
	env->enemy_sprites[1].nb_death_sprites = 6;
	env->enemy_sprites[1].start[0].x = 44;
	env->enemy_sprites[1].start[0].y = 33;
	env->enemy_sprites[1].end[0].x = 87;
	env->enemy_sprites[1].end[0].y = 79;
	env->enemy_sprites[1].size[0].x = 44;
	env->enemy_sprites[1].size[0].y = 47;
	env->enemy_sprites[1].reversed[0] = 0;
	init_lost_soul_rest2(env);
}

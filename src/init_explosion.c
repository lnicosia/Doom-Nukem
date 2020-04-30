/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_explosion.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/30 11:59:57 by lnicosia          #+#    #+#             */
/*   Updated: 2020/04/30 11:59:58 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

void	init_explosion(t_env *env)
{
	env->object_sprites[22].texture = 25;
	env->object_sprites[22].death_counterpart = 22;
	env->object_sprites[22].curr_sprite = 22;
	env->object_sprites[22].nb_death_sprites = 3;
	env->object_sprites[22].oriented = 0;
	env->object_sprites[22].rest_sprite = 22;
	env->object_sprites[22].reversed[0] = 0;
	env->object_sprites[22].start[0].x = 1;
	env->object_sprites[22].start[0].y = 858;
	env->object_sprites[22].end[0].x = 73;
	env->object_sprites[22].end[0].y = 917;
	env->object_sprites[22].size[0].x = 73;
	env->object_sprites[22].size[0].y = 60;
	env->object_sprites[22].start[1].x = 75;
	env->object_sprites[22].start[1].y = 846;
	env->object_sprites[22].end[1].x = 162;
	env->object_sprites[22].end[1].y = 917;
	env->object_sprites[22].size[1].x = 88;
	env->object_sprites[22].size[1].y = 72;
	env->object_sprites[22].start[2].x = 164;
	env->object_sprites[22].start[2].y = 832;
	env->object_sprites[22].end[2].x = 266;
	env->object_sprites[22].end[2].y = 917;
	env->object_sprites[22].size[2].x = 103;
	env->object_sprites[22].size[2].y = 86;
}

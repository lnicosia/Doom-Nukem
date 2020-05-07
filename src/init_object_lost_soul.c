/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_object_lost_soul.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/30 12:04:15 by lnicosia          #+#    #+#             */
/*   Updated: 2020/04/30 12:04:15 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

void	init_object_lost_soul(t_env *env)
{
	env->object_sprites[27].texture = env->enemies_start + 1;
	env->object_sprites[27].death_counterpart = 4;
	env->object_sprites[27].pursuit_sprite = 2;
	env->object_sprites[27].firing_sprite = 2;
	env->object_sprites[27].rest_sprite = 27;
	env->object_sprites[27].curr_sprite = 0;
	env->object_sprites[27].oriented = 0;
	env->object_sprites[27].nb_death_sprites = 6;
	env->object_sprites[27].start[0].x = 44;
	env->object_sprites[27].start[0].y = 120;
	env->object_sprites[27].end[0].x = 87;
	env->object_sprites[27].end[0].y = 165;
	env->object_sprites[27].size[0].x = 44;
	env->object_sprites[27].size[0].y = 46;
	env->object_sprites[27].reversed[0] = 0;
}

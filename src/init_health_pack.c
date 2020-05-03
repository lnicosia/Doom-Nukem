/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_health_pack.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/30 12:01:06 by lnicosia          #+#    #+#             */
/*   Updated: 2020/04/30 12:01:07 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

void	init_health_pack(t_env *env)
{
	env->object_sprites[2].texture = 22;
	env->object_sprites[2].death_counterpart = 2;
	env->object_sprites[2].oriented = 0;
	env->object_sprites[2].rest_sprite = 2;
	env->object_sprites[2].reversed[0] = 0;
	env->object_sprites[2].start[0].x = 47;
	env->object_sprites[2].start[0].y = 70;
	env->object_sprites[2].end[0].x = 80;
	env->object_sprites[2].end[0].y = 88;
	env->object_sprites[2].size[0].x = 34;
	env->object_sprites[2].size[0].y = 19;
}

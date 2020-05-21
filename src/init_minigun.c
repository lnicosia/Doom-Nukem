/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_minigun.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/30 12:03:14 by lnicosia          #+#    #+#             */
/*   Updated: 2020/04/30 12:03:14 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

void	init_minigun(t_env *env)
{
	env->object_sprites[0].texture = env->objects_sprites_start;
	env->object_sprites[0].death_counterpart = 0;
	env->object_sprites[0].oriented = 0;
	env->object_sprites[0].rest_sprite = 0;
	env->object_sprites[0].reversed[0] = 0;
	env->object_sprites[0].start[0].x = 511;
	env->object_sprites[0].start[0].y = 78;
	env->object_sprites[0].end[0].x = 562;
	env->object_sprites[0].end[0].y = 102;
	env->object_sprites[0].size[0].x = 51;
	env->object_sprites[0].size[0].y = 24;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_gun.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/30 12:06:25 by lnicosia          #+#    #+#             */
/*   Updated: 2020/04/30 12:06:25 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

void	init_gun_sprite(t_env *env)
{
	env->object_sprites[35].texture = env->objects_sprites_start + 5;
	env->object_sprites[35].oriented = 0;
	env->object_sprites[35].rest_sprite = 33;
	env->object_sprites[35].start[0].x = 1228;
	env->object_sprites[35].start[0].y = 40;
	env->object_sprites[35].end[0].x = 1257;
	env->object_sprites[35].end[0].y = 54;
	env->object_sprites[35].size[0].x = 29;
	env->object_sprites[35].size[0].y = 14;
	env->object_sprites[35].reversed[0] = 0;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_rocket_launcher_sprite.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/30 12:06:25 by lnicosia          #+#    #+#             */
/*   Updated: 2020/04/30 12:06:25 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

void	init_rocket_launcher_sprite(t_env *env)
{
	env->object_sprites[34].texture = env->objects_sprites_start + 4;
	env->object_sprites[34].oriented = 0;
	env->object_sprites[34].rest_sprite = 33;
	env->object_sprites[34].start[0].x = 2;
	env->object_sprites[34].start[0].y = 157;
	env->object_sprites[34].end[0].x = 53;
	env->object_sprites[34].end[0].y = 179;
	env->object_sprites[34].size[0].x = 51;
	env->object_sprites[34].size[0].y = 22;
	env->object_sprites[34].reversed[0] = 0;
}

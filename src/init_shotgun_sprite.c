/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_shotgun_sprite.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/30 12:07:38 by lnicosia          #+#    #+#             */
/*   Updated: 2020/04/30 12:07:40 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

void	init_shotgun_sprite(t_env *env)
{
	env->object_sprites[31].texture = 22;
	env->object_sprites[31].oriented = 0;
	env->object_sprites[31].rest_sprite = 31;
	env->object_sprites[31].start[0].x = 512;
	env->object_sprites[31].start[0].y = 42;
	env->object_sprites[31].end[0].x = 560;
	env->object_sprites[31].end[0].y = 53;
	env->object_sprites[31].size[0].x = 48;
	env->object_sprites[31].size[0].y = 11;
	env->object_sprites[31].reversed[0] = 0;
}

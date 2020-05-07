/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_doom_guy_face.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/30 11:48:55 by lnicosia          #+#    #+#             */
/*   Updated: 2020/04/30 11:48:56 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

void	init_doom_guy_face(t_env *env)
{
	env->object_sprites[29].texture = env->editor_start + 2;
	env->object_sprites[29].oriented = 0;
	env->object_sprites[29].rest_sprite = 29;
	env->object_sprites[29].start[0].x = 40;
	env->object_sprites[29].start[0].y = 13;
	env->object_sprites[29].end[0].x = 64;
	env->object_sprites[29].end[0].y = 42;
	env->object_sprites[29].size[0].x = 24;
	env->object_sprites[29].size[0].y = 29;
	env->object_sprites[29].reversed[0] = 0;
}

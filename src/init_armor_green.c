/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_armor_green.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/30 11:46:00 by lnicosia          #+#    #+#             */
/*   Updated: 2020/04/30 11:46:01 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

void	init_armor_green(t_env *env)
{
	env->object_sprites[17].texture = 22;
	env->object_sprites[17].death_counterpart = 17;
	env->object_sprites[17].oriented = 0;
	env->object_sprites[17].rest_sprite = 17;
	env->object_sprites[17].reversed[0] = 0;
	env->object_sprites[17].start[0].x = 337;
	env->object_sprites[17].start[0].y = 224;
	env->object_sprites[17].end[0].x = 367;
	env->object_sprites[17].end[0].y = 240;
	env->object_sprites[17].size[0].x = 31;
	env->object_sprites[17].size[0].y = 17;
}

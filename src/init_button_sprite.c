/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_button_sprite.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/30 11:47:17 by lnicosia          #+#    #+#             */
/*   Updated: 2020/04/30 11:47:17 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

void	init_button_off(t_env *env)
{
	env->object_sprites[24].texture = 32;
	env->object_sprites[24].death_counterpart = 1;
	env->object_sprites[24].pursuit_sprite = 1;
	env->object_sprites[24].rest_sprite = 24;
	env->object_sprites[24].curr_sprite = 1;
	env->object_sprites[24].oriented = 0;
	env->object_sprites[24].nb_death_sprites = 1;
	env->object_sprites[24].start[0].x = 0;
	env->object_sprites[24].start[0].y = 0;
	env->object_sprites[24].end[0].x = 64;
	env->object_sprites[24].end[0].y = 64;
	env->object_sprites[24].size[0].x = 64;
	env->object_sprites[24].size[0].y = 64;
	env->object_sprites[24].reversed[0] = 0;
}

void	init_button_on(t_env *env)
{
	env->object_sprites[25].texture = 33;
	env->object_sprites[25].death_counterpart = 2;
	env->object_sprites[25].pursuit_sprite = 2;
	env->object_sprites[25].rest_sprite = 25;
	env->object_sprites[25].curr_sprite = 0;
	env->object_sprites[25].oriented = 0;
	env->object_sprites[25].nb_death_sprites = 2;
	env->object_sprites[25].start[0].x = 0;
	env->object_sprites[25].start[0].y = 0;
	env->object_sprites[25].end[0].x = 64;
	env->object_sprites[25].end[0].y = 64;
	env->object_sprites[25].size[0].x = 64;
	env->object_sprites[25].size[0].y = 64;
	env->object_sprites[25].reversed[0] = 0;
}

void	init_button_sprite(t_env *env)
{
	init_button_off(env);
	init_button_on(env);
}

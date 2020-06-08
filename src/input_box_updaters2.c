/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_box_updaters2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipatry <sipatry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 12:05:50 by lnicosia          #+#    #+#             */
/*   Updated: 2020/02/20 10:38:03 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "collision.h"

int			update_object_scale_input_box(void *penv)
{
	t_env	*env;

	env = (t_env*)penv;
	env->objects[env->selected_object].size_2d =
	env->objects[env->selected_object].scale / (env->object_sprites[env->
	objects[env->selected_object].sprite].size[0].y
	/ (double)env->object_sprites[env->objects[env->selected_object].sprite].
	size[0].x) / 2;
	return (0);
}

int			update_enemy_scale_input_box(void *penv)
{
	t_env	*env;

	env = (t_env*)penv;
	env->enemies[env->selected_enemy].size_2d =
	env->enemies[env->selected_enemy].scale / (env->enemy_sprites[env->
	enemies[env->selected_enemy].sprite].size[0].y
	/ (double)env->enemy_sprites[env->enemies[env->selected_enemy].sprite].
	size[0].x) / 2;
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_drag.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaerhard <gaerhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 13:25:44 by lnicosia          #+#    #+#             */
/*   Updated: 2020/03/03 10:51:08 by gaerhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "enemies.h"

int		enemy_drag(t_env *env)
{
	if (env->editor.dragged_enemy != -1 && env->inputs.left_click)
	{
		env->enemies[env->editor.dragged_enemy].pos.x =
		(env->sdl.mx - env->editor.center.x) / env->editor.scale;
		env->enemies[env->editor.dragged_enemy].pos.y =
		(env->sdl.my - env->editor.center.y) / env->editor.scale;
	}
	else
	{
		update_enemy(env, env->editor.dragged_enemy);
		if (check_entities_height_in_sector(
			&env->sectors[env->enemies[env->editor.dragged_enemy].sector],
			env))
		{
			env->enemies[env->editor.dragged_enemy].pos.x =
			env->editor.start_pos.x;
			env->enemies[env->editor.dragged_enemy].pos.y =
			env->editor.start_pos.y;
			update_enemy(env, env->editor.dragged_enemy);
			env->editor.dragged_enemy = -1;
			if (update_confirmation_box(&env->confirmation_box,
				"This enemy does not fit at this pos", ERROR, env))
				return (-1);
		}
		env->editor.dragged_enemy = -1;
	}
	return (0);
}

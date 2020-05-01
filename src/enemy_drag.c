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

void	enemy_drag(t_env *env)
{
	if (env->editor.dragged_enemy != -1 && env->inputs.left_click)
	{
		env->enemies[env->editor.dragged_enemy].pos.x =
		(env->sdl.mx - env->editor.center.x) / env->editor.scale;
		env->enemies[env->editor.dragged_enemy].pos.y =
		(env->sdl.my - env->editor.center.y) / env->editor.scale;
		update_enemy(env, env->editor.dragged_enemy);
	}
	else
		env->editor.dragged_enemy = -1;
}

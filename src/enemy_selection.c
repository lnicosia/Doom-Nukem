/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_selection.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 14:54:00 by lnicosia          #+#    #+#             */
/*   Updated: 2020/01/27 14:54:04 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

void	enemy_selection(t_env *env)
{
	if (env->editor.dragged_enemy != -1 && env->inputs.left_click)
	{
			env->enemies[env->editor.dragged_enemy].pos.x =	(env->sdl.mx - env->editor.center.x) / env->editor.scale;
			env->enemies[env->editor.dragged_enemy].pos.y =	(env->sdl.my - env->editor.center.y) / env->editor.scale;
	}
	else
		env->editor.dragged_enemy = -1;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/13 10:05:10 by lnicosia          #+#    #+#             */
/*   Updated: 2019/05/20 11:23:58 by sipatry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void		keys(t_env *env)
{
	if (env->inputs.forward || env->inputs.backward || env->inputs.left
			|| env->inputs.right || env->inputs.space || env->jump.on_going == 1
			|| env->squat.on_going || env->inputs.ctrl)
		move_player(env);
	if (env->inputs.plus && !env->inputs.shift
			&& env->options.minimap_scale * 1.2 < 100)
		env->options.minimap_scale *= 1.2;
	if (env->inputs.minus && !env->inputs.shift
			&& env->options.minimap_scale / 1.2 > 5)
		env->options.minimap_scale /= 1.2;
	if (env->inputs.plus && env->inputs.shift
			&& env->camera.near_z * 1.1 < 5)
		env->camera.near_z *= 1.1;
	if (env->inputs.minus && env->inputs.shift
			&& env->camera.near_z / 1.1 > 0)
		env->camera.near_z /= 1.1;
}

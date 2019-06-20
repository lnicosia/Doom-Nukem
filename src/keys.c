/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaerhard <gaerhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/13 10:05:10 by lnicosia          #+#    #+#             */
/*   Updated: 2019/06/14 14:39:31 by gaerhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void		keys(t_env *env)
{
	if (!env->jump.on_going && env->inputs.space)
		update_floor(env);
	if (env->inputs.forward || env->inputs.backward || env->inputs.left
			|| env->inputs.right)
		Mix_PlayChannel(-1, env->sound.footstep, 0);
	if (env->inputs.forward || env->inputs.backward || env->inputs.left
			|| env->inputs.right || env->inputs.space || env->jump.on_going == 1
			|| env->squat.on_going || env->inputs.ctrl || env->gravity.on_going)
		move_player(env);
	if (env->inputs.plus && !env->inputs.shift
			&& env->options.minimap_scale * 1.2 < 100)
		env->options.minimap_scale *= 1.2;
	if (env->inputs.minus && !env->inputs.shift
			&& env->options.minimap_scale / 1.2 > 5)
		env->options.minimap_scale /= 1.2;
	if (env->inputs.up && !env->inputs.shift)
	{
		env->sectors[env->player.sector].floor_slope += 0.01;
		update_sector_slope(env, env->player.sector);
		if (env->sectors[env->player.sector].floor_max
			> env->sectors[env->player.sector].ceiling_min)
		{
			env->sectors[env->player.sector].floor_slope -= 0.01;
			update_sector_slope(env, env->player.sector);
		}
	}
	if (env->inputs.down && !env->inputs.shift)
	{
		env->sectors[env->player.sector].floor_slope -= 0.01;
		update_sector_slope(env, env->player.sector);
	}
	if (env->inputs.up && env->inputs.shift)
	{
		env->sectors[env->player.sector].ceiling_slope += 0.01;
		update_sector_slope(env, env->player.sector);
	}
	if (env->inputs.down && env->inputs.shift)
	{
		env->sectors[env->player.sector].ceiling_slope -= 0.01;
		update_sector_slope(env, env->player.sector);
		if (env->sectors[env->player.sector].floor_max
			> env->sectors[env->player.sector].ceiling_min)
		{
			env->sectors[env->player.sector].ceiling_slope += 0.01;
			update_sector_slope(env, env->player.sector);
		}
	}
}

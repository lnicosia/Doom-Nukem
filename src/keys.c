/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/13 10:05:10 by lnicosia          #+#    #+#             */
/*   Updated: 2019/05/21 12:08:51 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void		keys(t_env *env)
{
	if (env->inputs.forward || env->inputs.backward || env->inputs.left
			|| env->inputs.right)
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

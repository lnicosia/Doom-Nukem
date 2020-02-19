/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3d_edit_slopes.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipatry <sipatry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 17:41:53 by sipatry           #+#    #+#             */
/*   Updated: 2020/02/12 18:20:47 by sipatry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

int		increase_slope(t_env *env)
{
	if (env->selected_ceiling != -1)
	{
		env->sectors[env->selected_ceiling].ceiling_slope += 0.01;
		update_sector_slope(env, &env->sectors[env->selected_ceiling]);
		update_sector_entities_z(env, env->selected_ceiling);
	}
	if (env->selected_floor != -1)
	{
		env->sectors[env->selected_floor].floor_slope += 0.01;
		update_sector_slope(env, &env->sectors[env->selected_floor]);
		update_sector_entities_z(env, env->selected_floor);
	}
	return (0);
}

int		decrease_slope(t_env *env)
{
	if (env->selected_ceiling != -1)
	{
		env->sectors[env->selected_ceiling].ceiling_slope -= 0.01;
		update_sector_slope(env, &env->sectors[env->selected_ceiling]);
		update_sector_entities_z(env, env->selected_ceiling);
	}
	if (env->selected_floor != -1)
	{
		env->sectors[env->selected_floor].floor_slope -= 0.01;
		update_sector_slope(env, &env->sectors[env->selected_floor]);
		update_sector_entities_z(env, env->selected_floor);
	}
	return (0);
}
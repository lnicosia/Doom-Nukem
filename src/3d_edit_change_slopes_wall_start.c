/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3d_edit_change_slopes_wall_start.c                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipatry <sipatry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 12:29:41 by sipatry           #+#    #+#             */
/*   Updated: 2020/02/13 15:10:39 by sipatry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

void	change_floor_slope_start(t_env *env)
{
	if (env->inputs.left
	&& env->sectors[env->selected_floor].start_floor_slope
	< env->sectors[env->selected_floor].nb_vertices - 1)
		env->sectors[env->selected_floor].start_floor_slope++;
	else if (env->inputs.right
	&& env->sectors[env->selected_floor].start_floor_slope > 0)
		env->sectors[env->selected_floor].start_floor_slope--;
	env->sectors[env->selected_floor].floor_normal =
	get_sector_normal(env->sectors[env->selected_floor], env,
	env->sectors[env->selected_floor]. start_floor_slope);
	update_sector_slope(env, &env->sectors[env->selected_floor]);
}

void	change_ceiling_slope_start(t_env *env)
{
	if (env->inputs.left
	&& env->sectors[env->selected_ceiling].start_ceiling_slope
	< env->sectors[env->selected_ceiling].nb_vertices - 1)
		env->sectors[env->selected_ceiling].start_ceiling_slope++;
	else if (env->sectors[env->selected_ceiling].start_ceiling_slope > 0)
		env->sectors[env->selected_ceiling].start_ceiling_slope--;
	env->sectors[env->selected_ceiling].ceiling_normal =
	get_sector_normal(env->sectors[env->selected_ceiling], env,
	env->sectors[env->selected_ceiling].start_ceiling_slope);
	update_sector_slope(env, &env->sectors[env->selected_ceiling]);
}

void	change_slope_start(t_env *env)
{
	int	i;

	i = 0;
	if (env->selected_floor != -1)
		change_floor_slope_start(env);
	else if (env->selected_ceiling != -1)
		change_ceiling_slope_start(env);
	clear_portals(env);
	while (i < env->nb_sectors)
	{
		create_portals(env, env->sectors[i]);
		i++;
	}
}
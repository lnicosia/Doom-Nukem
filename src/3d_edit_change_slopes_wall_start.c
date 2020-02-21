/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3d_edit_change_slopes_wall_start.c                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipatry <sipatry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 12:29:41 by sipatry           #+#    #+#             */
/*   Updated: 2020/02/20 18:33:35 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

int		change_floor_slope_start(t_env *env)
{
	if ((env->inputs.left || env->sdl.event.key.keysym.sym == SDLK_LEFT)
	&& env->sectors[env->selected_floor].start_floor_slope
	< env->sectors[env->selected_floor].nb_vertices - 1)
	{
		env->sectors[env->selected_floor].start_floor_slope++;
		env->sectors[env->selected_floor].floor_normal =
		get_sector_normal(env->sectors[env->selected_floor], env,
		env->sectors[env->selected_floor]. start_floor_slope);
		update_sector_slope(env, &env->sectors[env->selected_floor]);
		if (check_entities_height(env))
		{
			env->sectors[env->selected_floor].start_floor_slope--;
			env->sectors[env->selected_floor].floor_normal =
			get_sector_normal(env->sectors[env->selected_floor], env,
			env->sectors[env->selected_floor]. start_floor_slope);
			update_sector_slope(env, &env->sectors[env->selected_floor]);
			return (update_confirmation_box(&env->confirmation_box,
			"An entity position will be outside the map", ERROR, env));
		}
	}
	else if ((env->inputs.right || env->sdl.event.key.keysym.sym == SDLK_RIGHT)
	&& env->sectors[env->selected_floor].start_floor_slope > 0)
	{
		env->sectors[env->selected_floor].start_floor_slope--;
		env->sectors[env->selected_floor].floor_normal =
		get_sector_normal(env->sectors[env->selected_floor], env,
		env->sectors[env->selected_floor]. start_floor_slope);
		update_sector_slope(env, &env->sectors[env->selected_floor]);
		if (check_entities_height(env))
		{
			env->sectors[env->selected_floor].start_floor_slope++;
			env->sectors[env->selected_floor].floor_normal =
			get_sector_normal(env->sectors[env->selected_floor], env,
			env->sectors[env->selected_floor]. start_floor_slope);
			update_sector_slope(env, &env->sectors[env->selected_floor]);
			return (update_confirmation_box(&env->confirmation_box,
			"An entity position will be outside the map", ERROR, env));
		}
	}
	return (0);
}

int		change_ceiling_slope_start(t_env *env)
{
	if ((env->inputs.left || env->sdl.event.key.keysym.sym == SDLK_LEFT)
	&& env->sectors[env->selected_ceiling].start_ceiling_slope
	< env->sectors[env->selected_ceiling].nb_vertices - 1)
	{
		env->sectors[env->selected_ceiling].start_ceiling_slope++;
		env->sectors[env->selected_ceiling].ceiling_normal =
		get_sector_normal(env->sectors[env->selected_ceiling], env,
		env->sectors[env->selected_ceiling].start_ceiling_slope);
		update_sector_slope(env, &env->sectors[env->selected_ceiling]);
		if (check_entities_height(env))
		{
			env->sectors[env->selected_ceiling].start_ceiling_slope--;
			env->sectors[env->selected_ceiling].ceiling_normal =
			get_sector_normal(env->sectors[env->selected_ceiling], env,
			env->sectors[env->selected_ceiling].start_ceiling_slope);
			update_sector_slope(env, &env->sectors[env->selected_ceiling]);
			return (update_confirmation_box(&env->confirmation_box,
			"An entity position will be outside the map", ERROR, env));
		}
	}
	else if ((env->inputs.right || env->sdl.event.key.keysym.sym == SDLK_RIGHT)
	&& env->sectors[env->selected_ceiling].start_ceiling_slope > 0)
	{
		env->sectors[env->selected_ceiling].start_ceiling_slope--;
		env->sectors[env->selected_ceiling].ceiling_normal =
		get_sector_normal(env->sectors[env->selected_ceiling], env,
		env->sectors[env->selected_ceiling].start_ceiling_slope);
		update_sector_slope(env, &env->sectors[env->selected_ceiling]);
		if (check_entities_height(env))
		{
			env->sectors[env->selected_ceiling].start_ceiling_slope++;
			env->sectors[env->selected_ceiling].ceiling_normal =
			get_sector_normal(env->sectors[env->selected_ceiling], env,
			env->sectors[env->selected_ceiling].start_ceiling_slope);
			update_sector_slope(env, &env->sectors[env->selected_ceiling]);
			return (update_confirmation_box(&env->confirmation_box,
			"An entity position will be outside the map", ERROR, env));
		}
	}
	return (0);
}

int		change_slope_start(t_env *env)
{
	int	i;
	int	sect;

	i = 0;
	sect = 0;
	if (env->selected_floor != -1)
	{
		if (change_floor_slope_start(env))
			return (-1);
		sect = env->selected_floor;
	}
	else if (env->selected_ceiling != -1)
	{
		if (change_ceiling_slope_start(env))
			return (-1);
		sect = env->selected_ceiling;
	}
	update_sector_entities_z(env, sect);
	return (0);
}

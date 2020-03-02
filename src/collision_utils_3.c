/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collision_utils_3.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaerhard <gaerhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 12:13:55 by gaerhard          #+#    #+#             */
/*   Updated: 2020/03/02 12:18:26 by gaerhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "collision.h"

/*
** This function returns 1 if the ceiling is high enough and 0 if it is too low
*/

int		check_ceiling(t_env *env, t_motion motion, int sector_dest)
{
	if (motion.future.z + motion.eyesight >
		get_ceiling_at_pos(env->sectors[sector_dest], motion.future, env) - 1)
		return (0);
	return (1);
}

/*
** This function returns 0 if the floor is too high and 1 if it isn't
*/

int		check_floor(t_env *env, t_motion motion, int sector_dest)
{
	double	floor;

	floor = get_floor_at_pos(env->sectors[sector_dest], motion.future, env);
	if (floor > motion.future.z + 2 && sector_dest != motion.sector)
		return (0);
	else if ((floor > motion.future.z + 0.5 && sector_dest == motion.sector &&
		!motion.flight) ||
		(floor > motion.future.z && sector_dest == motion.sector &&
		motion.flight))
		return (0);
	if (env->player.state.jump && motion.future.z < floor)
		return (0);
	return (1);
}

/*
** CHecks both the ceiling and the floor
*/

int		check_floor_ceil(t_env *env, t_motion motion, int sector_dest)
{
	if (!check_floor(env, motion, sector_dest)
		|| !check_ceiling(env, motion, sector_dest))
		return (0);
	return (1);
}

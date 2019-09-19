/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_sector.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaerhard <gaerhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/30 10:33:34 by lnicosia          #+#    #+#             */
/*   Updated: 2019/09/17 15:50:40 by gaerhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "collision.h"

/*
** Returns an object sector according to its position.
** Starts by looking into the given sector.
*/

int		get_sector(t_env *env, t_v3 pos, short origin)
{
	int		i;

	if (origin < 0 || origin >= env->nb_sectors)
		return (-1);
	if (is_in_sector(env, origin, pos))
		return (origin);
	i = 0;
	while (i < env->sectors[origin].nb_vertices)
	{
		if (env->sectors[origin].neighbors[i] >= 0)
		{
			if (is_in_sector(env, env->sectors[origin].neighbors[i], pos))
				return (env->sectors[origin].neighbors[i]);
		}
		i++;
	}
	i = 0;
	while (i < env->nb_sectors)
	{
		if (i != origin && is_in_sector(env, i, pos))
			return (i);
		i++;
	}
	return (-1);
}

/*
** Returns an object sector according to its position.
** Looks up every sector.
*/

int		get_sector_global(t_env *env, t_v3 pos)
{
	int		i;

	i = 0;
	while (i < env->nb_sectors)
	{
		if (is_in_sector(env, i, pos))
			return (i);
		i++;
	}
	return (-1);
}

/*
** Returns an object sector according to its position ignoring z.
** Looks up every sector.
*/

int		get_sector_no_z(t_env *env, t_v3 pos)
{
	int		i;

	i = 0;
	while (i < env->nb_sectors)
	{
		if (is_in_sector_no_z(env, i, new_v2(pos.x, pos.y)))
			return (i);
		i++;
	}
	return (-1);
}

/*
** Returns an object sector according to its position ignoring z.
** Starts by looking into the given sector.
*/

int		get_sector_no_z_origin(t_env *env, t_v3 pos, int origin)
{
	int		i;

	if (origin < 0 || origin >= env->nb_sectors)
		return (-1);
	if (is_in_sector_no_z(env, origin, new_v2(pos.x, pos.y)))
		return (origin);
	i = 0;
	while (i < env->sectors[origin].nb_vertices)
	{
		if (env->sectors[origin].neighbors[i] >= 0)
		{
			if (is_in_sector_no_z(env, env->sectors[origin].neighbors[i], new_v2(pos.x, pos.y)))
				return (env->sectors[origin].neighbors[i]);
		}
		i++;
	}
	i = 0;
	while (i < env->nb_sectors)
	{
		if (i != origin && is_in_sector_no_z(env, i, new_v2(pos.x, pos.y)))
			return (i);
		i++;
	}
	return (-1);
}

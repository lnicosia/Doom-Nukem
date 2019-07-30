/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_sector.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/30 10:33:34 by lnicosia          #+#    #+#             */
/*   Updated: 2019/07/30 10:40:34 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

/*
**	Returns camera sector according to the last player movement
*/

int		get_sector(t_env *env, t_v3 p, short origin)
{
	int		i;

	if (origin < 0 || origin >= env->nb_sectors)
		return (-1);
	if (is_in_sector(env, origin, p.x, p.y))
		return (origin);
	i = 0;
	while (i < env->sectors[origin].nb_vertices)
	{
		if (env->sectors[origin].neighbors[i] >= 0)
		{
			if (is_in_sector(env, env->sectors[origin].neighbors[i], p.x, p.y))
				return (env->sectors[origin].neighbors[i]);
		}
		i++;
	}
	i = 0;
	while (i < env->nb_sectors)
	{
		if (is_in_sector(env, i, p.x, p.y))
			return (i);
		i++;
	}
	return (-1);
}

int		get_sector_global(t_env *env, t_v3 p)
{
	int		i;

	i = 0;
	while (i < env->nb_sectors)
	{
		if (is_in_sector(env, i, p.x, p.y))
			return (i);
		i++;
	}
	return (-1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys_checkers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipatry <sipatry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 10:17:18 by sipatry           #+#    #+#             */
/*   Updated: 2020/02/12 12:06:41 by sipatry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

int		check_entities_height(t_env *env)
{
	int			i;
	t_sector	sector;
	
	i = 0;
	if (env->selected_ceiling != -1)
		sector = env->sectors[env->selected_ceiling];
	else if (env->selected_floor != -1)
		sector = env->sectors[env->selected_floor];
	while (i < env->nb_enemies)
	{
		if (env->enemies[i].sector == sector.num
		&& get_floor_at_pos(sector, env->enemies[i].pos, env) +
		env->enemies[i].scale + env->enemies[i].height_on_floor >=
		get_ceiling_at_pos(sector, env->enemies[i].pos, env))
			return (0);
		i++;
	}
	if (sector.ceiling - sector.floor < env->player.eyesight + 1)
		return (0);
	return (1);
}

int		height_check(t_env *env)
{
	t_sector	*sector;

	sector = NULL;
	if (env->selected_ceiling != -1)
		sector = &env->sectors[env->selected_ceiling];
	else if (env->selected_floor != -1)
		sector = &env->sectors[env->selected_floor];
	if (sector->ceiling - sector->floor > 1000)
		return (0);
	return (1);
}
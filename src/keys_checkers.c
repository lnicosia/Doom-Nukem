/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys_checkers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 10:17:18 by sipatry           #+#    #+#             */
/*   Updated: 2020/04/30 16:57:42 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

int		check_height_at_pos(t_env *env, t_sector *sector,
		t_v3 pos, int target_height)
{
	if (get_floor_at_pos(sector, pos, env) + (double)target_height >=
	get_ceiling_at_pos(sector, pos, env))
		return (-1);
	return (0);
}

int		check_entities_height(t_env *env)
{
	int			i;
	t_sector	*sector;

	i = 0;
	sector = NULL;
	if (env->selected_ceiling != -1)
		sector = &env->sectors[env->selected_ceiling];
	else if (env->selected_floor != -1)
		sector = &env->sectors[env->selected_floor];
	while (i < env->nb_enemies)
	{
		if (env->enemies[i].sector == sector->num
		&& check_height_at_pos(env, sector, env->enemies[i].pos,
		(env->enemies[i].scale + 1)))
			return (-1);
		i++;
	}
	if (env->player.sector == sector->num
	&& check_height_at_pos(env, sector, env->player.pos,
	env->player.eyesight + 1))
		return (-1);
	return (0);
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
		return (-1);
	return (0);
}

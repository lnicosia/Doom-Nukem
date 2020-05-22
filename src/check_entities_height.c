/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_entities_height.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 10:17:18 by sipatry           #+#    #+#             */
/*   Updated: 2020/04/30 16:57:42 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

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
	else
		sector = &env->sectors[env->editor.selected_sector];
	update_sector_slope(env, sector);
	update_sector_entities_z(env, sector->num);
	while (i < env->nb_enemies)
	{
		if (env->enemies[i].sector == sector->num
		&& check_height_at_pos(env, sector, env->enemies[i].pos,
		(env->enemies[i].scale)))
			return (-1);
		i++;
	}
	if (check_player_height(sector, env)
		|| check_start_player_height(sector, env))
		return (-1);
	return (0);
}

int		check_entities_height_in_sector(t_sector *sector, t_env *env)
{
	int			i;
	
	i = 0;
	update_sector_slope(env, sector);
	update_sector_entities_z(env, sector->num);
	while (i < env->nb_enemies)
	{
		if (env->enemies[i].sector == sector->num
		&& check_height_at_pos(env, sector, env->enemies[i].pos,
		(env->enemies[i].scale)))
			return (-1);
		i++;
	}
	if (check_player_height(sector, env)
		|| check_start_player_height(sector, env))
		return (-1);
	return (0);
}

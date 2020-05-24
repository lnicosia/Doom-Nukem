/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_sector_input_box.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/30 16:19:00 by lnicosia          #+#    #+#             */
/*   Updated: 2020/04/30 16:19:00 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

int			update_sector_input_box(void *penv)
{
	t_env	*env;
	int		sector;

	env = (t_env*)penv;
	sector = -1;
	if (env->selected_floor != -1)
	{
		update_sector_slope(env, &env->sectors[env->selected_floor]);
		update_sector_entities_z(env, env->selected_floor);
		sector = env->selected_floor;
	}
	else if (env->editor.selected_sector != -1)
	{
		update_sector_slope(env, &env->sectors[env->editor.selected_sector]);
		update_sector_entities_z(env, env->editor.selected_sector);
		sector = env->editor.selected_sector;
	}
	else if (env->selected_ceiling != -1)
	{
		update_sector_slope(env, &env->sectors[env->selected_ceiling]);
		sector = env->selected_ceiling;
	}
	if (get_sector_no_z(env, env->player.starting_pos) == sector)
		update_start_player_z(env);
	return (0);
}

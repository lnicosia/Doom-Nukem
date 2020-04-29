/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3d_edit_change_slopes_start.c                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipatry <sipatry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 12:29:41 by sipatry           #+#    #+#             */
/*   Updated: 2020/02/20 18:33:35 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

int		change_slope_start(t_env *env)
{
	int	sect;

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

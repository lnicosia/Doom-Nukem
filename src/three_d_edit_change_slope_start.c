/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   three_d_edit_change_slope_start.c                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/01 11:29:23 by lnicosia          #+#    #+#             */
/*   Updated: 2020/05/01 11:29:24 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

int		change_slope_start(t_env *env)
{
	if (env->selected_floor != -1)
	{
		if (change_floor_slope_start(env))
			return (-1);
	}
	else if (env->selected_ceiling != -1)
	{
		if (change_ceiling_slope_start(env))
			return (-1);
	}
	return (0);
}

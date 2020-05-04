/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_hud_button_function.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipatry <sipatry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 11:38:03 by sipatry           #+#    #+#             */
/*   Updated: 2020/03/04 18:08:54 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

int		open_wall_sprite_selection(void *param)
{
	t_env *env;

	env = ((t_button_param*)param)->env;
	env->editor.draw_sprite_tab = 1;
	return (0);
}

int		add_sprite(void *param)
{
	t_env *env;

	env = (t_env *)param;
	if (env->selected_floor != -1)
	{
		if (update_floor_sprite_arrays(env))
			return (-1);
	}
	if (env->selected_ceiling != -1)
	{
		if (update_ceiling_sprite_arrays(env))
			return (-1);
	}
	if (env->selected_wall_sprite_wall != -1
	|| env->editor.selected_wall != -1)
	{
		if (update_wall_sprite_arrays(env))
			return (-1);
	}
	return (0);
}

int		nothing(void *target)
{
	(void)target;
	return (0);
}

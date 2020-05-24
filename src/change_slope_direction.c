/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_slope_direction.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/29 14:58:31 by lnicosia          #+#    #+#             */
/*   Updated: 2020/04/29 14:58:32 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

int		change_floor_slope_direction(t_button_next *button, t_env *env)
{
	t_sector		*sector;

	sector = &env->sectors[env->selected_floor];
	if (button->button_type == NEXT)
	{
		if (sector->start_floor_slope < sector->nb_vertices - 1)
			return (increase_floor_slope_start(env));
	}
	else if (button->button_type == PREVIOUS)
	{
		if (sector->start_floor_slope > 0)
			return (decrease_floor_slope_start(env));
	}
	return (0);
}

int		change_ceiling_slope_direction(t_button_next *button, t_env *env)
{
	t_sector		*sector;

	sector = &env->sectors[env->selected_ceiling];
	if (button->button_type == NEXT)
	{
		if (sector->start_ceiling_slope < sector->nb_vertices - 1)
			return (increase_ceiling_slope_start(env));
	}
	else if (button->button_type == PREVIOUS)
	{
		if (sector->start_ceiling_slope > 0)
			return (decrease_ceiling_slope_start(env));
	}
	return (0);
}

int		change_slope_direction(void *target)
{
	t_env			*env;
	t_button_next	*button;

	button = NULL;
	env = (t_env *)target;
	if (env->editor.next_slope_swap.state == DOWN)
		button = &env->editor.next_slope_swap_env;
	if (env->editor.previous_slope_swap.state == DOWN)
		button = &env->editor.previous_slope_swap_env;
	if (env->selected_ceiling != -1)
	{
		change_ceiling_slope_direction(button, env);
	}
	else if (env->selected_floor != -1)
	{
		change_floor_slope_direction(button, env);
	}
	env->editor.previous_slope_swap.state = UP;
	env->editor.previous_slope_swap.anim_state = REST;
	env->editor.next_slope_swap.state = UP;
	env->editor.next_slope_swap.anim_state = REST;
	return (0);
}

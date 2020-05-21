/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   three_d_edit_function_slopes.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 17:25:50 by sipatry           #+#    #+#             */
/*   Updated: 2020/05/01 11:29:55 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

void	update_slope(t_env *env, t_sector *sector)
{
	if (env->editor.keyup_allowed && env->selected_ceiling != -1)
		sector->ceiling_slope -= 0.1;
	else if (env->editor.key_delay > INPUT_DELAY && env->selected_ceiling != -1)
		sector->ceiling_slope -= (0.1 * (env->editor.key_delay / 500));
	if (env->editor.keyup_allowed && env->selected_floor != -1)
		sector->floor_slope -= 0.1;
	else if (env->editor.key_delay > INPUT_DELAY && env->selected_floor != -1)
		sector->floor_slope -= (0.1 * (env->editor.key_delay / 500));
}

void	update_slope_for_entities(t_env *env, t_sector *sector)
{
	if (env->selected_ceiling != -1 && !env->inputs.ctrl
	&& env->editor.key_delay > INPUT_DELAY)
		sector->ceiling_slope += (0.1 * (env->editor.key_delay / 500));
	else if (env->selected_ceiling != -1 && !env->inputs.ctrl
	&& env->editor.keyup_allowed)
		sector->ceiling_slope += 0.1;
	if (env->selected_floor != -1 && !env->inputs.ctrl
	&& env->editor.key_delay > INPUT_DELAY)
		sector->floor_slope -= (0.1 * (env->editor.key_delay / 500));
	else if (env->selected_floor != -1 && !env->inputs.ctrl
	&& env->editor.keyup_allowed && env->editor.key_delay < INPUT_DELAY)
		sector->floor_slope -= 0.1;
	if (env->selected_ceiling != -1 && env->inputs.ctrl
	&& env->editor.keyup_allowed && env->editor.key_delay < INPUT_DELAY)
		sector->ceiling_slope += 1;
	else if (env->selected_ceiling != -1 && env->inputs.ctrl
	&& env->editor.key_delay > INPUT_DELAY)
		sector->ceiling_slope += (0.01 * (env->editor.key_delay / 500));
	if (env->selected_floor != -1 && env->inputs.ctrl
	&& env->editor.key_delay > INPUT_DELAY)
		sector->floor_slope -= (0.01 * (env->editor.key_delay / 500));
	else if (env->selected_floor != -1 && env->inputs.ctrl
	&& env->editor.keyup_allowed && env->editor.key_delay < INPUT_DELAY)
		sector->floor_slope -= 1;
}

void	check_slopes_protections(t_env *env, t_sector *sector)
{
	ft_printf("hola\n");
	if (env->editor.key_delay > INPUT_DELAY
	|| env->editor.keyup_allowed)
	{
		if (height_check(env))
			update_slope(env, sector);
		if (check_entities_height(env))
			update_slope_for_entities(env, sector);
	}
}

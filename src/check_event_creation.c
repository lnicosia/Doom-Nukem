/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_event_creation.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 10:36:41 by lnicosia          #+#    #+#             */
/*   Updated: 2020/02/11 10:39:40 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

int		check_event_creation(t_env *env)
{
	t_target_panel	panel;

	if (env->editor.selecting_target == 0)
		return (0);
	panel = env->editor.event_panel.target_panel;
	if (panel.floor_type)
	{
		if (env->selected_floor == -1 && env->editor.selected_sector == -1)
			return (update_confirmation_box(&env->confirmation_box,
			"Please select a floor", ERROR, env));
	}
	if (panel.ceiling_type)
	{
		if (env->selected_ceiling == -1 && env->editor.selected_sector == -1)
			return (update_confirmation_box(&env->confirmation_box,
			"Please select a ceiling", ERROR, env));
	}
	env->editor.creating_event = 1;
	env->editor.event_panel.target_tab.anim_state = REST;
	env->editor.event_panel.target_tab.state = UP;
	env->editor.event_panel.action_tab.state = DOWN;
	set_new_event_target(env);
	return (0);
}

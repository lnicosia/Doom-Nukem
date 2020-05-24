/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   choose_target.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/29 15:21:01 by lnicosia          #+#    #+#             */
/*   Updated: 2020/04/29 15:21:02 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

int		choose_target3(t_env *env)
{
	if (update_confirmation_box(&env->confirmation_box, "Select a target",
		CONFIRM, env))
		return (-1);
	return (0);
}

int		choose_target2(t_target_panel *panel, t_env *env)
{
	int				i;
	int				select;

	reset_selection(env);
	new_tabs_position(env);
	select = 0;
	i = -1;
	while (++i < 9)
	{
		if (panel->targets[i].state == DOWN && panel->selected_button != i
			&& select == 0)
		{
			panel->selected_button = i;
			select = 1;
		}
		panel->targets[i].state = UP;
		panel->targets[i].anim_state = REST;
	}
	if (panel->player_type || panel->other_type)
	{
		check_event_creation(env);
		return (0);
	}
	return (choose_target3(env));
}

int		choose_target(void *param)
{
	t_env			*env;
	t_target_panel	*panel;

	env = (t_env*)param;
	if (env->editor.creating_condition)
	{
		panel = &env->editor.condition_panel.target_panel;
		env->editor.creating_condition = 0;
		env->editor.creating_event = 0;
		if (panel->weapon_type)
			env->editor.selecting_condition_weapon = 1;
		else
			env->editor.selecting_condition_target = 1;
	}
	else
	{
		panel = &env->editor.event_panel.target_panel;
		env->editor.creating_event = 0;
		if (panel->weapon_type)
			env->editor.selecting_weapon = 1;
		else
			env->editor.selecting_target = 1;
	}
	return (choose_target2(panel, env));
}

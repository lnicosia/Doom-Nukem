/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_events_selection_buttons.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipatry <sipatry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 17:25:57 by lnicosia          #+#    #+#             */
/*   Updated: 2020/02/21 15:37:44 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

/*
**	Next events array
**	Only if they are mutilple arrays for the current selection
**	Ex: Sector:
**				_Stand events
**				_Walk in events
**				_Walk out events
*/

int		next_events(void *penv)
{
	t_env	*env;

	env = (t_env *)penv;
	if (env->selected_enemy != -1 || env->selected_wall_sprite_wall != -1)
		env->editor.selected_events = env->editor.selected_events >= 1 ? 0 : 1;
	else if (env->selected_floor != -1 || env->editor.selected_sector != -1)
	{
		env->editor.selected_events++;
		if (env->editor.selected_events == 3)
			env->editor.selected_events = 0;
	}
	env->editor.selected_event = 0;
	env->editor.selected_launch_condition = 0;
	env->editor.selected_exec_condition = 0;
	return (0);
}

/*
**	Previous events array
**	Only if they are mutilple arrays for the current selection
**	Ex: Sector:
**				_Stand events
**				_Walk in events
**				_Walk out events
*/

int		prec_events(void *penv)
{
	t_env	*env;

	env = (t_env *)penv;
	if (env->selected_enemy != -1 || env->selected_wall_sprite_wall != -1)
		env->editor.selected_events = env->editor.selected_events >= 1 ? 0 : 1;
	else if (env->selected_floor != -1 || env->editor.selected_sector != -1)
	{
		env->editor.selected_events--;
		if (env->editor.selected_events < 0)
			env->editor.selected_events = 2;
	}
	env->editor.selected_event = 0;
	env->editor.selected_launch_condition = 0;
	env->editor.selected_exec_condition = 0;
	return (0);
}

void	init_events_selection_buttons(t_env *env)
{
	env->editor.next_events = new_next_button(ON_RELEASE,
			&next_events, env, env);
	env->editor.next_events.pos = new_point(310, 470);
	env->editor.previous_events = new_previous_button(ON_RELEASE,
			&prec_events, env, env);
	env->editor.previous_events.pos = new_point(70, 470);
	env->editor.next_event = new_next_button(ON_RELEASE,
			&next_event, env, env);
	env->editor.next_event.pos = new_point(290, 500);
	env->editor.previous_event = new_previous_button(ON_RELEASE,
			&previous_event, env, env);
	env->editor.previous_event.pos = new_point(90, 500);
	env->editor.next_launch_condition = new_next_button(ON_RELEASE,
			&next_launch_condition, env, env);
	env->editor.next_launch_condition.pos = new_point(290, 680);
	env->editor.previous_launch_condition = new_previous_button(ON_RELEASE,
			&previous_launch_condition, env, env);
	env->editor.previous_launch_condition.pos = new_point(90, 680);
	env->editor.next_exec_condition = new_next_button(ON_RELEASE,
			&next_exec_condition, env, env);
	env->editor.next_exec_condition.pos = new_point(300, 800);
	env->editor.previous_exec_condition = new_previous_button(ON_RELEASE,
			&previous_exec_condition, env, env);
	env->editor.previous_exec_condition.pos = new_point(90, 800);
}

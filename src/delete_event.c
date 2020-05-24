/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_event.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 15:42:32 by lnicosia          #+#    #+#             */
/*   Updated: 2020/02/25 14:25:55 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "events_parser.h"
#include "parser.h"
#include "events.h"

int		delete_selected_event(void *param)
{
	t_env			*env;
	t_event_trigger	trigger;

	env = (t_env*)param;
	trigger = env->editor.event_panel.trigger;
	return (delete_selected_event1(env, trigger));
}

int		delete_event(void *param)
{
	t_env	*env;

	env = (t_env*)param;
	if (modify_event(env))
		return (-1);
	env->editor.creating_event = 0;
	env->editor.selected_launch_condition = 0;
	env->editor.selected_exec_condition = 0;
	if (update_confirmation_box(&env->confirmation_box,
		"Delete this event?", YESNO, env))
		return (-1);
	env->editor.event_panel.selected_event = env->editor.selected_event;
	env->confirmation_box.yes_action = &delete_selected_event;
	env->confirmation_box.yes_target = env;
	return (0);
}

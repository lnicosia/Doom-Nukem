/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_event.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 16:44:54 by lnicosia          #+#    #+#             */
/*   Updated: 2020/02/12 18:57:23 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "events_parser.h"

int		check_event_validity(t_env *env, t_event event)
{
	if (!event.target)
	{
		if (update_confirmation_box(&env->confirmation_box, "Please set"
			" a target before saving the event", ERROR, env))
			return (-1);
		return (-1);
	}
	if (env->editor.event_panel.event.speed < 0)
	{
		if (update_confirmation_box(&env->confirmation_box, "Speed"
			" can not be negative", ERROR, env))
			return (-1);
		return (-1);
	}
	if (env->editor.event_panel.action_panel.delay_value < 0)
	{
		if (update_confirmation_box(&env->confirmation_box, "Delay"
			" can not be negative", ERROR, env))
			return (-1);
		return (-1);
	}
	if (env->editor.event_panel.event.max_uses < 0)
	{
		if (update_confirmation_box(&env->confirmation_box, "Number"
			" of uses can not be negative", ERROR, env))
			return (-1);
		return (-1);
	}
	return (0);
}

int		create_event2(t_env *env)
{
	if (env->editor.event_panel.trigger.index == WALK_IN
		&& new_walk_in_event(env, env->editor.event_panel.trigger,
		env->editor.event_panel.event))
		return (-1);
	else if (env->editor.event_panel.trigger.index == WALK_OUT
		&& new_walk_out_event(env, env->editor.event_panel.trigger,
		env->editor.event_panel.event))
		return (-1);
	else if (env->editor.event_panel.trigger.index == DEATH
		&& new_death_event(env, env->editor.event_panel.trigger,
		env->editor.event_panel.event))
		return (-1);
	if (update_confirmation_box(&env->confirmation_box, "Your event has"
		" been saved!", CONFIRM, env))
		return (-1);
	env->editor.creating_event = 0;
	return (0);
}

void	set_event(t_env *env, t_event *event)
{
	event->delay = env->editor.event_panel.action_panel.delay_value;
	event->speed = 0;
	if (event->type == INT)
	{
		event->goal = env->editor.event_panel.action_panel.int_value;
		event->start_incr = env->editor.event_panel.action_panel.int_value;
	}
	else if (event->type == DOUBLE)
	{
		event->goal = env->editor.event_panel.action_panel.double_value;
		event->start_incr = env->editor.event_panel.action_panel.double_value;
	}
	else if (event->type == UINT32)
	{
		event->goal = env->editor.event_panel.action_panel.uint32_value;
		event->start_incr = env->editor.event_panel.action_panel.uint32_value;
	}
}

int		create_event(void *param)
{
	t_env	*env;

	env = (t_env*)param;
	if (check_event_validity(env, env->editor.event_panel.event))
		return (0);
	set_event(env, &env->editor.event_panel.event);
	if (env->editor.event_panel.trigger.index == GLOBAL
		&& new_global_event(env, env->editor.event_panel.trigger,
		env->editor.event_panel.event))
		return (-1);
	else if (env->editor.event_panel.trigger.index == PRESS
		&& new_press_event(env, env->editor.event_panel.trigger,
		env->editor.event_panel.event))
		return (-1);
	else if (env->editor.event_panel.trigger.index == SHOOT
		&& new_shoot_event(env, env->editor.event_panel.trigger,
		env->editor.event_panel.event))
		return (-1);
	else if (env->editor.event_panel.trigger.index == STAND
		&& new_stand_event(env, env->editor.event_panel.trigger,
		env->editor.event_panel.event))
		return (-1);
	return (create_event2(env));
}

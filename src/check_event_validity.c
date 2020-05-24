/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_event_validity.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/29 15:03:18 by lnicosia          #+#    #+#             */
/*   Updated: 2020/04/29 15:03:19 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "events_parser.h"

int		check_event_validity2(t_env *env, t_event event)
{
	(void)event;
	if (env->editor.event_panel.event.max_uses < 0)
	{
		if (update_confirmation_box(&env->confirmation_box, "Number"
			" of uses can not be negative", ERROR, env))
			return (-1);
		return (1);
	}
	return (0);
}

int		check_event_validity(t_env *env, t_event event)
{
	if (event.target_index == -1)
	{
		if (update_confirmation_box(&env->confirmation_box, "Please set"
			" a target before saving the event", ERROR, env))
			return (-1);
		return (1);
	}
	if (env->editor.event_panel.event.speed < 0)
	{
		if (update_confirmation_box(&env->confirmation_box, "Speed"
			" can not be negative", ERROR, env))
			return (-1);
		return (1);
	}
	if (env->editor.event_panel.action_panel.delay_value < 0)
	{
		if (update_confirmation_box(&env->confirmation_box, "Delay"
			" can not be negative", ERROR, env))
			return (-1);
		return (1);
	}
	return (check_event_validity2(env, event));
}

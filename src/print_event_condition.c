/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_event_condition.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 15:00:22 by lnicosia          #+#    #+#             */
/*   Updated: 2020/04/30 18:39:34 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "events_conditions.h"

char	*get_condition_type_str(t_condition *condition)
{
	if (condition->type == EQUALS)
		return ("is equal to");
	else if (condition->type == DIFFERENT)
		return ("is different from");
	else if (condition->type == LESS)
		return ("is less than");
	else if (condition->type == GREATER)
		return ("is greater than");
	else if (condition->type == LESS_OR_EQUALS)
		return ("is less than or equal to");
	else if (condition->type == GREATER_OR_EQUALS)
		return ("is greater than or equal to");
	else if (condition->type == EVENT_ENDED)
		return ("event ended");
	else if (condition->type == EVENT_ENDED_START)
		return ("event ended (start)");
	else if (condition->type == FUNCTION)
		return ("Function");
	return ("");
}

void	print_event_link(t_env *env, t_condition *condition)
{
	env->print_link_target_data[condition->target_type](env, condition,
	new_point(710, 30), 15);
}

void	print_event_launch_condition(t_env *env, t_condition *condition)
{
	if (condition->type < EVENT_ENDED)
		env->print_condition_target_data[condition->target_index](env,
		condition, new_point(710, 30), 15);
	else
		print_event_link(env, condition);
}

void	print_event_exec_condition(t_env *env, t_condition *condition)
{
	env->print_condition_target_data[condition->target_index](env,
	condition, new_point(830, 30), 15);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_event_condition.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 15:00:22 by lnicosia          #+#    #+#             */
/*   Updated: 2020/01/30 14:42:50 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "events_conditions.h"

static char	*get_condition_type_str(t_condition *condition)
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
		return ("Event ended");
	else if (condition->type == EVENT_ENDED_START)
		return ("Event ended (start)");
	else if (condition->type == FUNCTION)
		return ("Function");
	return ("");
}

void		print_event_launch_condition(t_env *env, t_event *event,
t_condition *condition)
{
	print_text(new_point(710, 30), new_printable_text(
	env->event_types[condition->target_index],
	env->sdl.fonts.lato20, 0xFFFFFFFF, 0b0101), env);
	env->print_target_data[condition->target_index](env, event,
	new_point(710, 90));
	print_text(new_point(740, 120), new_printable_text(
	get_condition_type_str(condition),
	env->sdl.fonts.lato20, 0xFFFFFFFF, 30), env);
	if (condition->type < EVENT_ENDED)
		print_text(new_point(740, 250), new_printable_text(
		ft_sitoa(condition->value),
		env->sdl.fonts.lato20, 0xFFFFFFFF, 30), env);
}

void		print_event_exec_condition(t_env *env, t_event *event,
t_condition *condition)
{
	print_text(new_point(830, 30), new_printable_text(
	env->event_types[condition->target_index],
	env->sdl.fonts.lato20, 0xFFFFFFFF, 30), env);
	env->print_target_data[condition->target_index](env, event,
	new_point(830, 90));
	print_text(new_point(860, 120), new_printable_text(
	get_condition_type_str(condition),
	env->sdl.fonts.lato20, 0xFFFFFFFF, 30), env);
	if (condition->type < EVENT_ENDED)
		print_text(new_point(860, 250), new_printable_text(
		ft_sitoa(condition->value),
		env->sdl.fonts.lato20, 0xFFFFFFFF, 30), env);
}

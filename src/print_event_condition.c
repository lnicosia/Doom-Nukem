/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_event_condition.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 15:00:22 by lnicosia          #+#    #+#             */
/*   Updated: 2020/01/30 16:36:14 by lnicosia         ###   ########.fr       */
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

void		print_event_link(t_env *env, t_event *event,
t_condition *condition)
{
	t_point	text_size;
	int		pos;

	(void)event;
	pos = 30;
	pos = env->print_link_target_data[condition->target_type](env, condition,
	new_point(710, pos), 15);
	print_text(new_point(710, pos), new_printable_text(
	env->event_links_types[condition->target_type],
	env->sdl.fonts.lato15, 0xFFFFFFFF, 0b0101), env);
	TTF_SizeText(env->sdl.fonts.lato15,
	env->event_links_types[condition->target_type], &text_size.x, &text_size.y);
	pos += text_size.x + 5;
	print_text(new_point(710, pos), new_printable_text(
	ft_sitoa(condition->target_index),
	env->sdl.fonts.lato15, 0xFFFFFFFF, 0b0101), env);
	TTF_SizeText(env->sdl.fonts.lato15, ft_sitoa(condition->target_index),
	&text_size.x, &text_size.y);
	pos += text_size.x + 5;
	if (condition->type == EVENT_ENDED)
	{
		print_text(new_point(710, pos),
		new_printable_text("ended", env->sdl.fonts.lato15, 0xFFFFFFFF, 0), env);
	}
	else
	{
		print_text(new_point(710, pos),
		new_printable_text("ended (starter)", env->sdl.fonts.lato15, 0xFFFFFFFF,
		0b0101), env);
	}
}

void		print_event_launch_condition(t_env *env, t_event *event,
t_condition *condition)
{
	t_point	text_size;
	int		pos;

	if (condition->type < EVENT_ENDED)
	{
		pos = env->print_condition_target_data[condition->target_index](env,
		condition, new_point(710, 30), 15);
		print_text(new_point(710, pos), new_printable_text(
		env->event_types[condition->target_index],
		env->sdl.fonts.lato15, 0xFFFFFFFF, 0b0101), env);
		TTF_SizeText(env->sdl.fonts.lato15,
		env->event_types[condition->target_index], &text_size.x, &text_size.y);
		pos += text_size.x + 5;
		print_text(new_point(710, pos), new_printable_text(
		get_condition_type_str(condition),
		env->sdl.fonts.lato15, 0xFFFFFFFF, 30), env);
		TTF_SizeText(env->sdl.fonts.lato15, get_condition_type_str(condition),
		&text_size.x, &text_size.y);
		pos += text_size.x + 5;
		print_text(new_point(710, pos), new_printable_text(
		ft_sitoa(condition->value),
		env->sdl.fonts.lato15, 0xFFFFFFFF, 30), env);
	}
	else
		print_event_link(env, event, condition);
}

void		print_event_exec_condition(t_env *env, t_event *event,
t_condition *condition)
{
	t_point	text_size;
	int		pos;

	(void)event;
	pos = env->print_condition_target_data[condition->target_index](env,
	condition, new_point(830, 30), 15);
	print_text(new_point(830, pos), new_printable_text(
	env->event_types[condition->target_index],
	env->sdl.fonts.lato15, 0xFFFFFFFF, 30), env);
	TTF_SizeText(env->sdl.fonts.lato15,
	env->event_types[condition->target_index], &text_size.x, &text_size.y);
	pos += text_size.x + 5;
	print_text(new_point(830, pos), new_printable_text(
	get_condition_type_str(condition),
	env->sdl.fonts.lato15, 0xFFFFFFFF, 30), env);
	TTF_SizeText(env->sdl.fonts.lato15, get_condition_type_str(condition),
	&text_size.x, &text_size.y);
	pos += text_size.x + 5;
	print_text(new_point(830, pos), new_printable_text(
	ft_sitoa(condition->value),
	env->sdl.fonts.lato15, 0xFFFFFFFF, 30), env);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_event_action.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/30 18:39:18 by lnicosia          #+#    #+#             */
/*   Updated: 2020/04/30 18:39:19 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

void	print_incr_action(t_env *env, t_event *event)
{
	if (event->type == INT)
		ft_snprintf(env->snprintf, SNPRINTF_SIZE, "Action: Add %d"
		" Speed = %.*f", (int)event->start_incr,
		get_decimal_len(event->speed), event->speed);
	else if (event->type == DOUBLE)
		ft_snprintf(env->snprintf, SNPRINTF_SIZE, "Action: Add %.*f"
		" Speed = %.*f", get_decimal_len(event->start_incr),
		event->start_incr, get_decimal_len(event->speed), event->speed);
	if (event->type == UINT32)
		ft_snprintf(env->snprintf, SNPRINTF_SIZE, "Action: Add 0x%X"
		" Speed = %.*f", (Uint32)event->start_incr,
		get_decimal_len(event->speed), event->speed);
}

void	print_fixed_action(t_env *env, t_event *event)
{
	if (event->type == INT)
		ft_snprintf(env->snprintf, SNPRINTF_SIZE, "Action: Go to %d"
		" Speed = %.*f", (int)event->goal,
		get_decimal_len(event->speed), event->speed);
	else if (event->type == DOUBLE)
		ft_snprintf(env->snprintf, SNPRINTF_SIZE, "Action: Go to %.*f"
		" Speed = %.*f", get_decimal_len(event->goal), event->goal,
		get_decimal_len(event->speed), event->speed);
	if (event->type == UINT32)
		ft_snprintf(env->snprintf, SNPRINTF_SIZE, "Action: Go to 0x%X"
		" Speed = %.*f", (Uint32)event->goal,
		get_decimal_len(event->speed), event->speed);
}

int		print_event_action(t_env *env, t_event *event)
{
	t_point	text_size;

	if (event->mod_type == FIXED)
	{
		print_fixed_action(env, event);
	}
	else if (event->mod_type == INCR)
	{
		print_incr_action(env, event);
	}
	if (event->target_index >= MAX_REAL_TARGET_TYPES)
	{
	}
	else
	{
		if (TTF_SizeText(env->sdl.fonts.lato20, env->snprintf, &text_size.x,
		&text_size.y))
			return (-1);
		if (print_text(new_point(570, 200 - text_size.x / 2),
		new_printable_text(env->snprintf,
		env->sdl.fonts.lato20, 0x333333FF, 30), env))
			return (-1);
	}
	return (0);
}

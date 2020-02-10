/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_event.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 16:47:06 by lnicosia          #+#    #+#             */
/*   Updated: 2020/02/10 17:28:19 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

void	print_event_action(t_env *env, t_event *event)
{
	char	*speed;

	if (event->speed != 0)
		speed = ft_sitoa(event->speed);
	else
		speed = "Instant";
	if (event->mod_type == FIXED)
	{
		if (event->type == INT)
			ft_snprintf(env->snprintf, SNPRINTF_SIZE, "Action: Go to %d"
			" Speed = %s", (int)event->goal, speed);
		else if (event->type == DOUBLE)
			ft_snprintf(env->snprintf, SNPRINTF_SIZE, "Action: Go to %.*f"
			" Speed = %s", get_decimal_len(event->goal), event->goal, speed);
		if (event->type == UINT32)
			ft_snprintf(env->snprintf, SNPRINTF_SIZE, "Action: Go to 0x%X"
			" Speed = %s", (Uint32)event->goal, speed);
	}
	else if (event->mod_type == INCR)
	{
		if (event->type == INT)
			ft_snprintf(env->snprintf, SNPRINTF_SIZE, "Action: Add %d"
			" Speed = %s", (int)event->start_incr, speed);
		else if (event->type == DOUBLE)
			ft_snprintf(env->snprintf, SNPRINTF_SIZE, "Action: Add %.*f"
			" Speed = %s", get_decimal_len(event->start_incr),
			event->start_incr, speed);
		if (event->type == UINT32)
			ft_snprintf(env->snprintf, SNPRINTF_SIZE, "Action: Add 0x%X"
			" Speed = %s", (Uint32)event->start_incr, speed);
	}
	if (event->mod_type == FUNC)
		print_text(new_point(570, 75), new_printable_text("Func",
		env->sdl.fonts.lato20, 0xFFFFFFFF, 30), env);
	if (event->mod_type != FUNC)
		print_text(new_point(570, 15), new_printable_text(env->snprintf,
		env->sdl.fonts.lato20, 0xFFFFFFFF, 30), env);
}

void	print_event_various_data(t_env *env, t_event *event)
{
	if (event->max_uses != 0)
		ft_snprintf(env->snprintf, SNPRINTF_SIZE, "Delay: %u Max uses: %d",
		event->delay, event->max_uses);
	else
		ft_snprintf(env->snprintf, SNPRINTF_SIZE, "Delay: %u Max uses: inf.",
		event->max_uses);
	print_text(new_point(600, 15), new_printable_text(env->snprintf,
	env->sdl.fonts.lato20, 0xFFFFFFFF, 30), env);
}

void	print_event_launch_conditions(t_env *env, t_event *event)
{
	print_text(new_point(650, 130), new_printable_text("Launch conditions",
	env->sdl.fonts.lato20, 0xFFFFFFFF, 30), env);
	if (event->nb_launch_conditions == 0)
		return ;
	ft_snprintf(env->snprintf, SNPRINTF_SIZE, "Condition %d",
	env->editor.selected_launch_condition);
	print_text(new_point(680, 150), new_printable_text(env->snprintf,
	env->sdl.fonts.lato20, 0xFFFFFFFF, 30), env);
	print_event_launch_condition(env,
	&event->launch_conditions[env->editor.selected_launch_condition]);
	if (event->nb_launch_conditions <= 1)
		return ;
	draw_button(env, env->editor.next_launch_condition,
	env->editor.next_launch_condition.str);
	draw_button(env, env->editor.previous_launch_condition,
	env->editor.previous_launch_condition.str);
}

void	print_event_exec_conditions(t_env *env, t_event *event)
{
	print_text(new_point(770, 117), new_printable_text("Execution conditions",
	env->sdl.fonts.lato20, 0xFFFFFFFF, 30), env);
	if (event->nb_exec_conditions == 0)
		return ;
	ft_snprintf(env->snprintf, SNPRINTF_SIZE, "Condition %d",
	env->editor.selected_exec_condition);
	print_text(new_point(800, 150), new_printable_text(env->snprintf,
	env->sdl.fonts.lato20, 0xFFFFFFFF, 30), env);
	print_event_exec_condition(env,
	&event->exec_conditions[env->editor.selected_exec_condition]);
	if (event->nb_launch_conditions <= 1)
		return ;
	draw_button(env, env->editor.next_exec_condition,
	env->editor.next_exec_condition.str);
	draw_button(env, env->editor.previous_exec_condition,
	env->editor.previous_exec_condition.str);
}

void	print_event(t_env *env, t_event *event)
{
	env->print_target_data[event->target_index](env, event,
	new_point(540, 15), 20);
	print_text(new_point(540, 15), new_printable_text(env->snprintf,
	env->sdl.fonts.lato20, 0xFFFFFFFF, 0), env);
	print_event_action(env, event);
	print_event_various_data(env, event);
	print_event_launch_conditions(env, event);
	print_event_exec_conditions(env, event);
}

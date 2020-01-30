/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_event.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 16:47:06 by lnicosia          #+#    #+#             */
/*   Updated: 2020/01/30 16:52:47 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

void	print_event_action(t_env *env, t_event *event)
{
	if (event->mod_type == FIXED)
	{
		print_text(new_point(570, 75), new_printable_text("Go to",
		env->sdl.fonts.lato20, 0xFFFFFFFF, 30), env);
		print_text(new_point(570, 130), new_printable_text(
		ft_sitoa((int)event->goal),
		env->sdl.fonts.lato20, 0xFFFFFFFF, 30), env);
	}
	else if (event->mod_type == INCR)
	{
		print_text(new_point(570, 75), new_printable_text("Add",
		env->sdl.fonts.lato20, 0xFFFFFFFF, 30), env);
		print_text(new_point(570, 115), new_printable_text(
		ft_sitoa((int)event->start_incr),
		env->sdl.fonts.lato20, 0xFFFFFFFF, 30), env);
	}
	if (event->mod_type == FUNC)
		print_text(new_point(570, 75), new_printable_text("Func",
		env->sdl.fonts.lato20, 0xFFFFFFFF, 30), env);
	if (event->mod_type != FUNC)
	{
		print_text(new_point(570, 275), new_printable_text("Speed: ",
		env->sdl.fonts.lato20, 0xFFFFFFFF, 30), env);
		if (event->speed != 0)
			print_text(new_point(570, 335), new_printable_text(
			ft_sitoa(event->speed),
			env->sdl.fonts.lato20, 0xFFFFFFFF, 30), env);
		else
			print_text(new_point(570, 335), new_printable_text("Instant",
			env->sdl.fonts.lato20, 0xFFFFFFFF, 30), env);
	}
}

void	print_event_various_data(t_env *env, t_event *event)
{
	print_text(new_point(600, 50), new_printable_text("Delay:",
	env->sdl.fonts.lato20, 0xFFFFFFFF, 30), env);
	print_text(new_point(600, 120), new_printable_text(
	ft_sitoa(event->delay),
	env->sdl.fonts.lato20, 0xFFFFFFFF, 30), env);
	print_text(new_point(600, 200), new_printable_text("Max uses:",
	env->sdl.fonts.lato20, 0xFFFFFFFF, 30), env);
	if (event->max_uses != 0)
		print_text(new_point(600, 300), new_printable_text(
		ft_sitoa((int)event->max_uses),
		env->sdl.fonts.lato20, 0xFFFFFFFF, 30), env);
	else
		print_text(new_point(600, 300), new_printable_text("Inf.",
		env->sdl.fonts.lato20, 0xFFFFFFFF, 30), env);
}

void	print_event_launch_conditions(t_env *env, t_event *event)
{
	print_text(new_point(650, 130), new_printable_text("Launch conditions",
	env->sdl.fonts.lato20, 0xFFFFFFFF, 30), env);
	if (event->nb_launch_conditions == 0)
		return ;
	print_text(new_point(680, 150), new_printable_text("Condition",
	env->sdl.fonts.lato20, 0xFFFFFFFF, 30), env);
	print_text(new_point(680, 245), new_printable_text(
	ft_sitoa((int)env->editor.selected_launch_condition),
	env->sdl.fonts.lato20, 0xFFFFFFFF, 30), env);
	print_event_launch_condition(env, event, &event->
	launch_conditions[env->editor.selected_launch_condition]);
	if (event->nb_launch_conditions <= 1)
		return ;
	draw_button(env, env->editor.next_launch_condition);
	draw_button(env, env->editor.previous_launch_condition);
}

void	print_event_exec_conditions(t_env *env, t_event *event)
{
	print_text(new_point(770, 117), new_printable_text("Execution conditions",
	env->sdl.fonts.lato20, 0xFFFFFFFF, 30), env);
	if (event->nb_exec_conditions == 0)
		return ;
	print_text(new_point(800, 150), new_printable_text("Condition",
	env->sdl.fonts.lato20, 0xFFFFFFFF, 30), env);
	print_text(new_point(800, 245), new_printable_text(
	ft_sitoa((int)env->editor.selected_exec_condition),
	env->sdl.fonts.lato20, 0xFFFFFFFF, 30), env);
	print_event_exec_condition(env, event, &event->
	exec_conditions[env->editor.selected_exec_condition]);
	if (event->nb_launch_conditions <= 1)
		return ;
	draw_button(env, env->editor.next_exec_condition);
	draw_button(env, env->editor.previous_exec_condition);
}

void	print_event(t_env *env, t_event *event)
{
	print_text(new_point(540, 10), new_printable_text("Target: ",
	env->sdl.fonts.lato20, 0xFFFFFFFF, 30), env);
	/*print_text(new_point(540, 75), new_printable_text(env->
	event_types[event->target_index],
	env->sdl.fonts.lato20, 0xFFFFFFFF, 30), env);*/
	env->print_target_data[event->target_index](env, event,
	new_point(540, 75), 20);
	print_text(new_point(570, 10), new_printable_text("Action: ",
	env->sdl.fonts.lato20, 0xFFFFFFFF, 30), env);
	print_event_action(env, event);
	print_event_various_data(env, event);
	print_event_launch_conditions(env, event);
	print_event_exec_conditions(env, event);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_event.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 16:47:06 by lnicosia          #+#    #+#             */
/*   Updated: 2020/02/21 10:07:44 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "draw.h"

void	print_event_various_data(t_env *env, t_event *event)
{
	t_point	text_size;

	if (event->max_uses != 0)
		ft_snprintf(env->snprintf, SNPRINTF_SIZE, "Delay: %u Max uses: %d",
		event->delay, event->max_uses);
	else
		ft_snprintf(env->snprintf, SNPRINTF_SIZE, "Delay: %u Max uses: inf.",
		event->delay);
	TTF_SizeText(env->sdl.fonts.lato20, env->snprintf, &text_size.x,
	&text_size.y);
	print_text(new_point(600, 200 - text_size.x / 2),
	new_printable_text(env->snprintf,
	env->sdl.fonts.lato20, 0x333333FF, 30), env);
}

void	print_event_launch_conditions(t_env *env, t_event *event)
{
	print_text(new_point(650, 130), new_printable_text("Launch conditions",
	env->sdl.fonts.lato20, 0x333333FF, 30), env);
	ft_printf("%d launch conditions\n", event->nb_launch_conditions);
	if (event->nb_launch_conditions == 0)
		return ;
	ft_snprintf(env->snprintf, SNPRINTF_SIZE, "Condition %d",
	env->editor.selected_launch_condition);
	print_text(new_point(680, 150), new_printable_text(env->snprintf,
	env->sdl.fonts.lato20, 0x333333FF, 30), env);
	ft_printf("launch condition %d selected\n",
	env->editor.selected_launch_condition);
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
	env->sdl.fonts.lato20, 0x333333FF, 30), env);
	if (event->nb_exec_conditions == 0)
		return ;
	ft_snprintf(env->snprintf, SNPRINTF_SIZE, "Condition %d",
	env->editor.selected_exec_condition);
	print_text(new_point(800, 150), new_printable_text(env->snprintf,
	env->sdl.fonts.lato20, 0x333333FF, 30), env);
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
	t_point	text_size;

	env->print_target_data[event->target_index](env, event,
	new_point(540, 15), 20);
	TTF_SizeText(env->sdl.fonts.lato20, env->snprintf, &text_size.x,
	&text_size.y);
	print_text(new_point(540, 200 - text_size.x / 2),
	new_printable_text(env->snprintf, env->sdl.fonts.lato20,
	0x333333FF, 0), env);
	print_event_action(env, event);
	print_event_various_data(env, event);
	draw_button(env, env->editor.modify_event, "Modify event");
	draw_button(env, env->editor.delete_event, "Delete event");
	if (env->editor.selecting_event)
		draw_button(env, env->editor.select_event, "Select me");
}

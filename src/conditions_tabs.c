/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conditions_tabs.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 18:07:34 by lnicosia          #+#    #+#             */
/*   Updated: 2020/05/15 18:41:30 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "events_conditions.h"
#include "draw.h"

int		draw_conditions_panel4(t_env *env)
{
	if (env->editor.event_panel.launch_conditions_tab.state == DOWN)
	{
		if (draw_condition(env, &env->editor.event_panel.event.
			launch_conditions[env->editor.selected_launch_condition]))
			return (-1);
	}
	else if (env->editor.event_panel.exec_conditions_tab.state == DOWN)
	{
		if (draw_condition(env, &env->editor.event_panel.event.
			exec_conditions[env->editor.selected_exec_condition]))
			return (-1);
	}
	return (0);
}

int		draw_conditions_panel3(t_event_panel *panel, t_env *env)
{
	if ((env->editor.event_panel.launch_conditions_tab.state == DOWN
		&& panel->event.nb_launch_conditions > 1)
		|| (env->editor.event_panel.exec_conditions_tab.state == DOWN
		&& panel->event.nb_exec_conditions > 1))
	{
		if (draw_button(env, panel->previous_condition, NULL))
			return (-1);
		if (draw_button(env, panel->next_condition, NULL))
			return (-1);
	}
	if ((env->editor.event_panel.launch_conditions_tab.state == DOWN
		&& panel->event.nb_launch_conditions == 0)
		|| (env->editor.event_panel.exec_conditions_tab.state == DOWN
		&& panel->event.nb_exec_conditions == 0))
		return (0);
	return (draw_conditions_panel4(env));
}

int		draw_conditions_panel2(t_event_panel *panel, t_point text_size,
t_env *env)
{
	if (print_text(new_point(panel->pos.y + panel->top_size + 17,
		panel->pos.x + 100 + panel->content_panel_size.x / 2 - text_size.x / 2),
		new_printable_text(env->snprintf,
		env->sdl.fonts.lato_black30, 0x333333FF, 0), env))
		return (-1);
	if (draw_button(env, panel->new_condition, "New condition"))
		return (-1);
	if ((env->editor.event_panel.launch_conditions_tab.state == DOWN
		&& panel->event.nb_launch_conditions > 0)
		|| (env->editor.event_panel.exec_conditions_tab.state == DOWN
		&& panel->event.nb_exec_conditions > 0))
	{
		if (draw_button(env, panel->modify_condition, "Modify condition"))
			return (-1);
		if (draw_button(env, panel->delete_condition, "Delete condition"))
			return (-1);
	}
	return (draw_conditions_panel3(panel, env));
}

int		draw_conditions_panel(t_env *env)
{
	t_point			text_size;
	t_event_panel	*panel;

	panel = &env->editor.event_panel;
	if (env->editor.event_panel.launch_conditions_tab.state == DOWN)
	{
		if (panel->event.nb_launch_conditions == 0)
			ft_snprintf(env->snprintf, SNPRINTF_SIZE, "Launch conditions");
		else
			ft_snprintf(env->snprintf, SNPRINTF_SIZE, "Launch condition %d",
			env->editor.selected_launch_condition);
	}
	else if (env->editor.event_panel.exec_conditions_tab.state == DOWN)
	{
		if (panel->event.nb_exec_conditions == 0)
			ft_snprintf(env->snprintf, SNPRINTF_SIZE, "Exec conditions");
		else
			ft_snprintf(env->snprintf, SNPRINTF_SIZE, "Exec condition %d",
			env->editor.selected_exec_condition);
	}
	if (TTF_SizeText(env->sdl.fonts.lato_black30, env->snprintf, &text_size.x,
		&text_size.y))
		return (-1);
	return (draw_conditions_panel2(panel, text_size, env));
}

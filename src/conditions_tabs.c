/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conditions_tabs.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 18:07:34 by lnicosia          #+#    #+#             */
/*   Updated: 2020/02/21 17:30:35 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "events_conditions.h"

int		draw_condition(t_env *env, t_condition *condition)
{
	t_point			text_size;
	t_event_panel	*panel;

	panel = &env->editor.event_panel;
	if (condition->type < EVENT_ENDED)
	{
		env->print_condition_target_data[condition->target_index](env,
		condition, new_point(panel->pos.x + 100,
		panel->pos.y + panel->top_size + panel->content_panel_size.y / 4), 20);
		TTF_SizeText(env->sdl.fonts.lato_bold20, env->snprintf, &text_size.x,
		&text_size.y);
		print_text(new_point(panel->pos.y + panel->top_size + 17 +
		panel->content_panel_size.y / 6, panel->pos.x + 100 +
		panel->content_panel_size.x / 2 - text_size.x / 2),
		new_printable_text(env->snprintf,
		env->sdl.fonts.lato_bold20, 0x333333FF, 0), env);
	}
	else
	{
		env->print_link_target_data[condition->target_trigger.type](env,
		condition, new_point(panel->pos.x + 100,
		panel->pos.y + panel->top_size + panel->content_panel_size.y / 4), 20);
		TTF_SizeText(env->sdl.fonts.lato_bold20, env->snprintf, &text_size.x,
		&text_size.y);
		print_text(new_point(panel->pos.y + panel->top_size + 17 +
		panel->content_panel_size.y / 6, panel->pos.x + 100 +
		panel->content_panel_size.x / 2 - text_size.x / 2),
		new_printable_text(env->snprintf,
		env->sdl.fonts.lato_bold20, 0x333333FF, 0), env);
	}
	return (0);
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
	TTF_SizeText(env->sdl.fonts.lato_black30, env->snprintf, &text_size.x,
	&text_size.y);
	print_text(new_point(panel->pos.y + panel->top_size + 17,
	panel->pos.x + 100 + panel->content_panel_size.x / 2 - text_size.x / 2),
	new_printable_text(env->snprintf,
	env->sdl.fonts.lato_black30, 0x333333FF, 0), env);
	draw_button(env, panel->new_condition, "New condition");
	if ((env->editor.event_panel.launch_conditions_tab.state == DOWN
		&& panel->event.nb_launch_conditions > 0)
		|| (env->editor.event_panel.exec_conditions_tab.state == DOWN
		&& panel->event.nb_exec_conditions > 0))
	{
		draw_button(env, panel->modify_condition, "Modify condition");
		draw_button(env, panel->delete_condition, "Delete condition");
	}
	if ((env->editor.event_panel.launch_conditions_tab.state == DOWN
		&& panel->event.nb_launch_conditions > 1)
		|| (env->editor.event_panel.exec_conditions_tab.state == DOWN
		&& panel->event.nb_exec_conditions > 1))
	{
		draw_button(env, panel->previous_condition, NULL);
		draw_button(env, panel->next_condition, NULL);
	}
	if ((env->editor.event_panel.launch_conditions_tab.state == DOWN
		&& panel->event.nb_launch_conditions == 0)
		|| (env->editor.event_panel.exec_conditions_tab.state == DOWN
		&& panel->event.nb_exec_conditions == 0))
	return (0);
	if (env->editor.event_panel.launch_conditions_tab.state == DOWN)
		draw_condition(env, &env->editor.event_panel.event.
		launch_conditions[env->editor.selected_launch_condition]);
	else if (env->editor.event_panel.exec_conditions_tab.state == DOWN)
		draw_condition(env, &env->editor.event_panel.event.
		exec_conditions[env->editor.selected_exec_condition]);
	return (0);
}

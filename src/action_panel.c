/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_panel.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 18:06:05 by lnicosia          #+#    #+#             */
/*   Updated: 2020/03/11 13:21:42 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "events_parser.h"

int		draw_event_value_panel(t_env *env)
{
	t_point		text_size;

	TTF_SizeText(env->sdl.fonts.lato20, "Value",
	&text_size.x, &text_size.y);
	print_text(new_point(env->editor.event_panel.action_panel.value.pos.y
	- text_size.y - 5, env->editor.event_panel.action_panel.value.pos.x +
	env->editor.event_panel.action_panel.value.size_up.x / 2 - text_size.x / 2),
	new_printable_text("Value", env->sdl.fonts.lato20, 0x333333FF, 0), env);
	if (env->editor.event_panel.event.type == INT)
		ft_snprintf(env->snprintf, SNPRINTF_SIZE, "%d",
		env->editor.event_panel.action_panel.int_value);
	else if (env->editor.event_panel.event.type == DOUBLE)
		ft_snprintf(env->snprintf, SNPRINTF_SIZE, "%.*f",
		get_decimal_len(env->editor.event_panel.action_panel.double_value),
		env->editor.event_panel.action_panel.double_value);
	else if (env->editor.event_panel.event.type == UINT32)
		ft_snprintf(env->snprintf, SNPRINTF_SIZE, "0x%X",
		env->editor.event_panel.action_panel.uint32_value);
	draw_button(env, env->editor.event_panel.action_panel.value, env->snprintf);
	return (0);
}

int		draw_event_speed_panel(t_env *env)
{
	t_point		text_size;

	TTF_SizeText(env->sdl.fonts.lato20, "Speed",
	&text_size.x, &text_size.y);
	print_text(new_point(env->editor.event_panel.action_panel.speed.pos.y
	- text_size.y - 5, env->editor.event_panel.action_panel.speed.pos.x +
	env->editor.event_panel.action_panel.speed.size_up.x / 2 - text_size.x / 2),
	new_printable_text("Speed", env->sdl.fonts.lato20, 0x333333FF, 0), env);
	ft_snprintf(env->snprintf, SNPRINTF_SIZE, "%.*f",
	get_decimal_len(env->editor.event_panel.event.speed),
	env->editor.event_panel.event.speed);
	draw_button(env, env->editor.event_panel.action_panel.speed, env->snprintf);
	return (0);
}

int		draw_real_target_action_panel(t_event_panel panel, t_env *env)
{
	draw_button(env, panel.action_panel.go_to, "Go to");
	draw_button(env, panel.action_panel.add, "Add");
	draw_event_value_panel(env);
	draw_event_speed_panel(env);
	draw_action_panel_bottom(env);
	return (0);
}

int		draw_function_target_action_panel(t_event_panel panel, t_env *env)
{
	t_point			text_size;

	(void)env;
	if (panel.event.target_index == WIN)
	{
		TTF_SizeText(env->sdl.fonts.lato_black30, "Win the game",
		&text_size.x, &text_size.y);
		print_text(new_point(panel.pos.y + panel.top_size
		+ panel.content_panel_size.y / 2 - text_size.y / 2,
		panel.pos.x + 100 + panel.content_panel_size.x / 2 - text_size.x / 2),
		new_printable_text("Win the game",
		env->sdl.fonts.lato_black30, 0x333333FF, 0), env);
	}
	else if (panel.event.target_index == DIALOG)
		draw_button(env, panel.action_panel.text, "Text");
	draw_action_panel_bottom(env);
	return (0);
}

int		draw_action_panel(t_env *env)
{
	t_point			text_size;
	t_event_panel	panel;

	panel = env->editor.event_panel;
	TTF_SizeText(env->sdl.fonts.lato_black30, "Tell what your event does",
	&text_size.x, &text_size.y);
	print_text(new_point(panel.pos.y + panel.top_size + 17,
	panel.pos.x + 100 + panel.content_panel_size.x / 2 - text_size.x / 2),
	new_printable_text("Tell what your event does",
	env->sdl.fonts.lato_black30, 0x333333FF, 0), env);
	if (env->editor.event_panel.event.target_index < MAX_REAL_TARGET_TYPES)
		return (draw_real_target_action_panel(panel, env));
	else
		return (draw_function_target_action_panel(panel, env));
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_panel.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 18:06:05 by lnicosia          #+#    #+#             */
/*   Updated: 2020/02/11 18:48:03 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

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
	draw_button(env, panel.action_panel.go_to, "Go to");
	draw_button(env, panel.action_panel.go_to, "Add");
	draw_button(env, panel.action_panel.go_to, "Other");
	draw_button(env, panel.action_panel.go_to, "Delay");
	draw_button(env, panel.action_panel.go_to, "Max uses");
	return (0);
}

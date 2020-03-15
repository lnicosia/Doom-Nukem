/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   condition_event_panel.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 11:48:51 by lnicosia          #+#    #+#             */
/*   Updated: 2020/02/18 13:18:00 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

int		draw_condition_event_panel(t_env *env)
{
	t_point			text_size1;
	t_point			text_size2;
	t_event_panel	panel;

	panel = env->editor.event_panel;
	TTF_SizeText(env->sdl.fonts.lato_black30, "Choose an event in the bottom",
	&text_size1.x, &text_size1.y);
	print_text(new_point(panel.pos.y + panel.top_size + 100 - text_size1.y,
	panel.pos.x + 100 + panel.content_panel_size.x / 2 - text_size1.x / 2),
	new_printable_text("Choose an event in the bottom",
	env->sdl.fonts.lato_black30, 0x333333FF, 0), env);
	TTF_SizeText(env->sdl.fonts.lato_black30, "left of the screen",
	&text_size2.x, &text_size2.y);
	print_text(new_point(panel.pos.y + panel.top_size + 100,
	panel.pos.x + 100 + panel.content_panel_size.x / 2 - text_size2.x / 2),
	new_printable_text("left of the screen",
	env->sdl.fonts.lato_black30, 0x333333FF, 0), env);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   condition_target_panel.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 15:30:12 by lnicosia          #+#    #+#             */
/*   Updated: 2020/02/17 15:13:29 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "draw.h"
#include "events.h"

int		draw_condition_targets_panel(t_env *env)
{
	t_point			text_size1;
	t_event_panel	panel;
	int				phase;

	panel = env->editor.event_panel;
	TTF_SizeText(env->sdl.fonts.lato_black30, "Choose your condition's target",
	&text_size1.x, &text_size1.y);
	print_text(new_point(panel.pos.y + panel.top_size + 17,
	panel.pos.x + 100 + panel.content_panel_size.x / 2 - text_size1.x / 2),
	new_printable_text("Choose your condition's target",
	env->sdl.fonts.lato_black30, 0x333333FF, 0), env);
	phase =
	get_target_selection_phase(&env->editor.condition_panel.target_panel);
	if (phase == 0)
		draw_first_phase_selection(env,
		&env->editor.condition_panel.target_panel);
	else if (phase == 1)
		draw_second_phase_selection(env,
		&env->editor.condition_panel.target_panel);
	else if (phase == 2)
		draw_third_phase_selection(env,
		&env->editor.condition_panel.target_panel);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_events_tabs.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 17:14:42 by lnicosia          #+#    #+#             */
/*   Updated: 2020/01/27 17:45:50 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

void	print_global_events_tab(t_env *env)
{
	print_text(new_point(480, 150), new_printable_text("Global events",
	env->sdl.fonts.lato20, 0xFFFFFFFF, 0), env);
}

void	print_sector_events_tab(t_env *env)
{
	if (env->editor.selected_events == 0)
		print_text(new_point(480, 150), new_printable_text("Stand events",
	env->sdl.fonts.lato20, 0xFFFFFFFF, 0), env);
	else if (env->editor.selected_events == 1)
		print_text(new_point(480, 145), new_printable_text("Walk in events",
	env->sdl.fonts.lato20, 0xFFFFFFFF, 0), env);
	else if (env->editor.selected_events == 1)
		print_text(new_point(480, 145), new_printable_text("Walk out events",
	env->sdl.fonts.lato20, 0xFFFFFFFF, 0), env);
	draw_button(env, env->editor.next_events);
	draw_button(env, env->editor.previous_events);
}

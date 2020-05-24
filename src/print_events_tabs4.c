/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_events_tabs4.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/19 13:46:05 by marvin            #+#    #+#             */
/*   Updated: 2020/05/19 15:44:41 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "draw.h"

int	collision_event_tab(t_env *env, t_point text_size)
{
	if (TTF_SizeText(env->sdl.fonts.lato20, "Collision events",
	&text_size.x, &text_size.y))
		return (-1);
	if (print_text(new_point(470, 200 - text_size.x / 2),
	new_printable_text("Collision events",
	env->sdl.fonts.lato20, 0x333333FF, 0), env))
		return (-1);
	if (env->enemies[env->selected_enemy].nb_collision_events > 0)
	{
		if (print_event_selection(env, env->enemies[env->selected_enemy].
		nb_collision_events))
			return (-1);
		if (print_event(env, &env->enemies[env->selected_enemy].
		collision_events[env->editor.selected_event]))
			return (-1);
	}
	return (0);
}

int	print_enemy_events_tab(t_env *env)
{
	t_point		text_size;

	if (env->editor.selected_events == 0)
	{
		if (collision_event_tab(env, text_size))
			return (-1);
	}
	else if (env->editor.selected_events == 1)
	{
		if (print_on_death_events_tab(env))
			return (-1);
	}
	if (draw_button(env, env->editor.next_events, env->editor.next_events.str))
		return (-1);
	if (draw_button(env, env->editor.previous_events,
	env->editor.previous_events.str))
		return (-1);
	return (0);
}

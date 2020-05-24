/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_events_tabs2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/30 18:39:47 by lnicosia          #+#    #+#             */
/*   Updated: 2020/05/19 13:46:22 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "draw.h"

int		print_event_selection(t_env *env, size_t nb)
{
	ft_snprintf(env->snprintf, SNPRINTF_SIZE, "Event %d",
	env->editor.selected_event);
	if (print_text(new_point(500, 170), new_printable_text(env->snprintf,
	env->sdl.fonts.lato20, 0x333333FF, 0), env))
		return (-1);
	if (nb > 1)
	{
		if (draw_button(env, env->editor.next_event,
			env->editor.next_event.str))
			return (-1);
		if (draw_button(env, env->editor.previous_event,
			env->editor.previous_event.str))
			return (-1);
	}
	return (0);
}

int		print_global_events_tab(t_env *env)
{
	t_point		text_size;

	if (TTF_SizeText(env->sdl.fonts.lato20, "Global events",
	&text_size.x, &text_size.y))
		return (-1);
	if (print_text(new_point(470, 200 - text_size.x / 2),
	new_printable_text("Global events",
	env->sdl.fonts.lato20, 0x333333FF, 0), env))
		return (-1);
	if (env->nb_global_events > 0)
	{
		if (print_event_selection(env, env->nb_global_events))
			return (-1);
		if (print_event(env, &env->global_events[env->editor.selected_event]))
			return (-1);
	}
	return (0);
}

int		print_object_events_tab(t_env *env)
{
	t_point		text_size;

	if (TTF_SizeText(env->sdl.fonts.lato20, "Collision events",
	&text_size.x, &text_size.y))
		return (-1);
	if (print_text(new_point(470, 200 - text_size.x / 2),
	new_printable_text("Collision events",
	env->sdl.fonts.lato20, 0x333333FF, 0), env))
		return (-1);
	if (env->objects[env->selected_object].nb_collision_events > 0)
	{
		if (print_event_selection(env, env->objects[env->selected_object].
		nb_collision_events))
			return (-1);
		if (print_event(env, &env->objects[env->selected_object].
		collision_events[env->editor.selected_event]))
			return (-1);
	}
	return (0);
}

int		print_on_death_events_tab(t_env *env)
{
	t_point		text_size;

	if (TTF_SizeText(env->sdl.fonts.lato20, "On death events",
	&text_size.x, &text_size.y))
		return (-1);
	if (print_text(new_point(470, 200 - text_size.x / 2),
	new_printable_text("On death events",
	env->sdl.fonts.lato20, 0x333333FF, 0), env))
		return (-1);
	if (env->enemies[env->selected_enemy].nb_death_events > 0)
	{
		if (print_event_selection(env, env->enemies[env->selected_enemy].
		nb_death_events))
			return (-1);
		if (print_event(env, &env->enemies[env->selected_enemy].
		death_events[env->editor.selected_event]))
			return (-1);
	}
	return (0);
}

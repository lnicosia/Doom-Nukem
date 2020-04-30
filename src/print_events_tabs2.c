/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_events_tabs2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/30 18:39:47 by lnicosia          #+#    #+#             */
/*   Updated: 2020/04/30 18:39:48 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

void	print_event_selection(t_env *env, size_t nb)
{
	ft_snprintf(env->snprintf, SNPRINTF_SIZE, "Event %d",
	env->editor.selected_event);
	print_text(new_point(500, 170), new_printable_text(env->snprintf,
	env->sdl.fonts.lato20, 0x333333FF, 0), env);
	if (nb > 1)
	{
		draw_button(env, env->editor.next_event, env->editor.next_event.str);
		draw_button(env, env->editor.previous_event,
		env->editor.previous_event.str);
	}
}

void	print_global_events_tab(t_env *env)
{
	t_point		text_size;

	TTF_SizeText(env->sdl.fonts.lato20, "Global events",
	&text_size.x, &text_size.y);
	print_text(new_point(470, 200 - text_size.x / 2),
	new_printable_text("Global events",
	env->sdl.fonts.lato20, 0x333333FF, 0), env);
	if (env->nb_global_events > 0)
	{
		print_event_selection(env, env->nb_global_events);
		print_event(env, &env->global_events[env->editor.selected_event]);
	}
}

void	print_object_events_tab(t_env *env)
{
	t_point		text_size;

	TTF_SizeText(env->sdl.fonts.lato20, "Collision events",
	&text_size.x, &text_size.y);
	print_text(new_point(470, 200 - text_size.x / 2),
	new_printable_text("Collision events",
	env->sdl.fonts.lato20, 0x333333FF, 0), env);
	if (env->objects[env->selected_object].nb_collision_events > 0)
	{
		print_event_selection(env, env->objects[env->selected_object].
		nb_collision_events);
		print_event(env, &env->objects[env->selected_object].
		collision_events[env->editor.selected_event]);
	}
}

void	print_on_death_events_tab(t_env *env)
{
	t_point		text_size;

	TTF_SizeText(env->sdl.fonts.lato20, "On death events",
	&text_size.x, &text_size.y);
	print_text(new_point(470, 200 - text_size.x / 2),
	new_printable_text("On death events",
	env->sdl.fonts.lato20, 0x333333FF, 0), env);
	if (env->enemies[env->selected_enemy].nb_death_events > 0)
	{
		print_event_selection(env, env->enemies[env->selected_enemy].
		nb_death_events);
		print_event(env, &env->enemies[env->selected_enemy].
		death_events[env->editor.selected_event]);
	}
}

void	print_enemy_events_tab(t_env *env)
{
	t_point		text_size;

	if (env->editor.selected_events == 0)
	{
		TTF_SizeText(env->sdl.fonts.lato20, "Collision events",
		&text_size.x, &text_size.y);
		print_text(new_point(470, 200 - text_size.x / 2),
		new_printable_text("Collision events",
		env->sdl.fonts.lato20, 0x333333FF, 0), env);
		if (env->enemies[env->selected_enemy].nb_collision_events > 0)
		{
			print_event_selection(env, env->enemies[env->selected_enemy].
			nb_collision_events);
			print_event(env, &env->enemies[env->selected_enemy].
			collision_events[env->editor.selected_event]);
		}
	}
	else if (env->editor.selected_events == 1)
	{
		print_on_death_events_tab(env);
	}
	draw_button(env, env->editor.next_events, env->editor.next_events.str);
	draw_button(env, env->editor.previous_events,
	env->editor.previous_events.str);
}

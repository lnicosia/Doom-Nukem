/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_events_tabs.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipatry <sipatry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 17:14:42 by lnicosia          #+#    #+#             */
/*   Updated: 2020/02/13 11:27:07 by lnicosia         ###   ########.fr       */
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
	print_text(new_point(470, 150), new_printable_text("Global events",
	env->sdl.fonts.lato20, 0x333333FF, 0), env);
	if (env->nb_global_events > 0)
	{
		print_event_selection(env, env->nb_global_events);
		print_event(env, &env->global_events[env->editor.selected_event]);
	}
}

void	print_sector_events(t_env *env)
{
	t_sector	sector;

	if (env->selected_floor != -1)
		sector = env->sectors[env->selected_floor];
	else if (env->editor.selected_sector != -1)
		sector = env->sectors[env->editor.selected_sector];
	if (env->editor.selected_events == 0
		&& sector.nb_stand_events > 0)
		print_event_selection(env, sector.nb_stand_events);
	else if (env->editor.selected_events == 1
		&& sector.nb_walk_in_events > 0)
		print_event_selection(env,
		sector.nb_walk_in_events);
	if (env->editor.selected_events == 2
		&& sector.nb_walk_out_events > 0)
		print_event_selection(env,
		sector.nb_walk_out_events);
}

void	print_wall_sprite_events(t_env *env)
{
	if (env->editor.selected_events == 0
		&& env->sectors[env->editor.selected_sector].wall_sprites[env->
		selected_wall_sprite_wall].nb_press_events[env->
		selected_wall_sprite_sprite] > 0)
		print_event_selection(env,
		env->sectors[env->editor.selected_sector].wall_sprites[env->
		selected_wall_sprite_wall].nb_press_events[env->
		selected_wall_sprite_sprite]);
	else if (env->editor.selected_events == 1
		&& env->sectors[env->editor.selected_sector].wall_sprites[env->
		selected_wall_sprite_wall].nb_shoot_events[env->
		selected_wall_sprite_sprite] > 0)
		print_event_selection(env,
		env->sectors[env->editor.selected_sector].wall_sprites[env->
		selected_wall_sprite_wall].nb_shoot_events[env->
		selected_wall_sprite_sprite]);
}

void	print_sector_events_tab(t_env *env)
{
	t_sector	sector;

	if (env->selected_floor != -1)
		sector = env->sectors[env->selected_floor];
	else if (env->editor.selected_sector != -1)
		sector = env->sectors[env->editor.selected_sector];
	if (env->editor.selected_events == 0)
		print_text(new_point(470, 150), new_printable_text("Stand events",
	env->sdl.fonts.lato20, 0x333333FF, 0), env);
	else if (env->editor.selected_events == 1)
		print_text(new_point(470, 145), new_printable_text("Walk in events",
	env->sdl.fonts.lato20, 0x333333FF, 0), env);
	else if (env->editor.selected_events == 2)
		print_text(new_point(470, 145), new_printable_text("Walk out events",
	env->sdl.fonts.lato20, 0x333333FF, 0), env);
	draw_button(env, env->editor.next_events, env->editor.next_events.str);
	draw_button(env, env->editor.previous_events,
	env->editor.previous_events.str);
	print_sector_events(env);
	if (env->editor.selected_events == 0 && sector.nb_stand_events > 0)
		print_event(env, &sector.stand_events[env->editor.selected_event]);
	else if (env->editor.selected_events == 1 && sector.nb_walk_in_events > 0)
		print_event(env, &sector.walk_in_events[env->editor.selected_event]);
	else if (env->editor.selected_events == 2 && sector.nb_walk_out_events > 0)
		print_event(env, &sector.walk_out_events[env->editor.selected_event]);
}

void	print_wall_sprite_events_tab(t_env *env)
{
	if (env->editor.selected_events == 0)
		print_text(new_point(470, 150), new_printable_text("Press events",
	env->sdl.fonts.lato20, 0x333333FF, 0), env);
	else if (env->editor.selected_events == 1)
		print_text(new_point(470, 150), new_printable_text("Shoot events",
	env->sdl.fonts.lato20, 0x333333FF, 0), env);
	draw_button(env, env->editor.next_events, env->editor.next_events.str);
	draw_button(env, env->editor.previous_events,
	env->editor.previous_events.str);
	print_wall_sprite_events(env);
	if (env->editor.selected_events == 0
		&& env->sectors[env->editor.selected_sector]
		.wall_sprites[env->selected_wall_sprite_wall]
		.nb_press_events[env->selected_wall_sprite_sprite] > 0)
		print_event(env, &env->sectors[env->editor.selected_sector]
		.wall_sprites[env->selected_wall_sprite_wall]
		.press_events[env->selected_wall_sprite_sprite]
		[env->editor.selected_event]);
	else if (env->editor.selected_events == 1
		&& env->sectors[env->editor.selected_sector]
		.wall_sprites[env->selected_wall_sprite_wall]
		.nb_shoot_events[env->selected_wall_sprite_sprite] > 0)
		print_event(env, &env->sectors[env->editor.selected_sector]
		.wall_sprites[env->selected_wall_sprite_wall]
		.shoot_events[env->selected_wall_sprite_sprite]
		[env->editor.selected_event]);
}

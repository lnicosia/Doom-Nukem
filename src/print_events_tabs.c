/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_events_tabs.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 17:14:42 by lnicosia          #+#    #+#             */
/*   Updated: 2020/04/30 18:40:42 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

void	print_sector_events(t_env *env)
{
	t_sector	sector;

	if (env->selected_floor != -1)
		sector = env->sectors[env->selected_floor];
	else
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
	else
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
	if (env->editor.selected_events == 0 && env->sectors[env->editor.
		selected_sector].wall_sprites[env->selected_wall_sprite_wall].
		nb_press_events[env->selected_wall_sprite_sprite] > 0)
		print_event(env, &env->sectors[env->editor.selected_sector].
		wall_sprites[env->selected_wall_sprite_wall].
		press_events[env->selected_wall_sprite_sprite]
		[env->editor.selected_event]);
	else if (env->editor.selected_events == 1
		&& env->sectors[env->editor.selected_sector].
		wall_sprites[env->selected_wall_sprite_wall].
		nb_shoot_events[env->selected_wall_sprite_sprite] > 0)
		print_event(env, &env->sectors[env->editor.selected_sector].
		wall_sprites[env->selected_wall_sprite_wall].
		shoot_events[env->selected_wall_sprite_sprite]
		[env->editor.selected_event]);
}

void	print_events_tab(t_env *env)
{
	if (env->selected_enemy != -1)
		print_enemy_events_tab(env);
	else if (env->selected_object != -1)
		print_object_events_tab(env);
	else if (env->selected_wall_sprite_wall == -1
		&& (env->selected_floor != -1 || env->editor.selected_sector != -1))
		print_sector_events_tab(env);
	else if (env->selected_wall_sprite_wall != -1)
		print_wall_sprite_events_tab(env);
	else if (env->selected_floor == -1 && env->editor.selected_sector == -1
		&& env->selected_enemy == -1 && env->selected_object == -1)
		print_global_events_tab(env);
	draw_button(env, env->editor.new_event, "New event");
}

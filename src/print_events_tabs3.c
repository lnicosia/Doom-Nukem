/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_events_tabs3.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/19 13:33:13 by marvin            #+#    #+#             */
/*   Updated: 2020/05/19 15:38:08 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "draw.h"

int	print_sector_events_tab3(t_env *env, t_sector sector)
{
	if (env->editor.selected_events == 0 && sector.nb_stand_events > 0)
	{
		if (print_event(env,
			&sector.stand_events[env->editor.selected_event]))
			return (-1);
	}
	else if (env->editor.selected_events == 1 && sector.nb_walk_in_events > 0)
	{
		if (print_event(env,
			&sector.walk_in_events[env->editor.selected_event]))
			return (-1);
	}
	else if (env->editor.selected_events == 2 && sector.nb_walk_out_events > 0)
	{
		if (print_event(env,
			&sector.walk_out_events[env->editor.selected_event]))
			return (-1);
	}
	return (0);
}

int	print_sector_events_tab2(t_env *env)
{
	t_sector	sector;

	if (env->selected_floor != -1)
		sector = env->sectors[env->selected_floor];
	else
		sector = env->sectors[env->editor.selected_sector];
	if (draw_button(env, env->editor.next_events, env->editor.next_events.str))
		return (-1);
	if (draw_button(env, env->editor.previous_events,
	env->editor.previous_events.str))
		return (-1);
	if (print_sector_events(env))
		return (-1);
	return (print_sector_events_tab3(env, sector));
}

int	print_sector_events_tab(t_env *env)
{
	if (env->editor.selected_events == 0)
	{
		if (print_text(new_point(470, 150), new_printable_text("Stand events",
		env->sdl.fonts.lato20, 0x333333FF, 0), env))
			return (-1);
	}
	else if (env->editor.selected_events == 1)
	{
		if (print_text(new_point(470, 145),
		new_printable_text("Walk in events",
		env->sdl.fonts.lato20, 0x333333FF, 0), env))
			return (-1);
	}
	else if (env->editor.selected_events == 2)
	{
		if (print_text(new_point(470, 145),
		new_printable_text("Walk out events",
		env->sdl.fonts.lato20, 0x333333FF, 0), env))
			return (-1);
	}
	return (print_sector_events_tab2(env));
}

int	print_wall_sprite_events_tab2(t_env *env)
{
	if (env->editor.selected_events == 0 && env->sectors[env->editor.
	selected_sector].wall_sprites[env->selected_wall_sprite_wall].
	nb_press_events[env->selected_wall_sprite_sprite] > 0)
	{
		if (print_event(env, &env->sectors[env->editor.selected_sector].
		wall_sprites[env->selected_wall_sprite_wall].
		press_events[env->selected_wall_sprite_sprite]
		[env->editor.selected_event]))
			return (-1);
	}
	else if (env->editor.selected_events == 1
	&& env->sectors[env->editor.selected_sector].
	wall_sprites[env->selected_wall_sprite_wall].
	nb_shoot_events[env->selected_wall_sprite_sprite] > 0)
	{
		if (print_event(env, &env->sectors[env->editor.selected_sector].
		wall_sprites[env->selected_wall_sprite_wall].
		shoot_events[env->selected_wall_sprite_sprite]
		[env->editor.selected_event]))
			return (-1);
	}
	return (0);
}

int	print_wall_sprite_events_tab(t_env *env)
{
	if (env->editor.selected_events == 0)
	{
		if (print_text(new_point(470, 150), new_printable_text("Press events",
		env->sdl.fonts.lato20, 0x333333FF, 0), env))
			return (-1);
	}
	else if (env->editor.selected_events == 1)
	{
		if (print_text(new_point(470, 150), new_printable_text("Shoot events",
		env->sdl.fonts.lato20, 0x333333FF, 0), env))
			return (-1);
	}
	if (draw_button(env, env->editor.next_events, env->editor.next_events.str))
		return (-1);
	if (draw_button(env, env->editor.previous_events,
	env->editor.previous_events.str))
		return (-1);
	if (print_wall_sprite_events(env))
		return (-1);
	return (print_wall_sprite_events_tab2(env));
}

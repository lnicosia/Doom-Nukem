/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_events_tabs.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 17:14:42 by lnicosia          #+#    #+#             */
/*   Updated: 2020/05/19 15:37:23 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "draw.h"

int		print_sector_events(t_env *env)
{
	t_sector	sector;

	if (env->selected_floor != -1)
		sector = env->sectors[env->selected_floor];
	else
		sector = env->sectors[env->editor.selected_sector];
	if (env->editor.selected_events == 0
		&& sector.nb_stand_events > 0)
	{
		if (print_event_selection(env, sector.nb_stand_events))
			return (-1);
	}
	else if (env->editor.selected_events == 1
		&& sector.nb_walk_in_events > 0)
	{
		if (print_event_selection(env, sector.nb_walk_in_events))
			return (-1);
	}
	if (env->editor.selected_events == 2
		&& sector.nb_walk_out_events > 0)
	{
		if (print_event_selection(env, sector.nb_walk_out_events))
			return (-1);
	}
	return (0);
}

int		print_wall_sprite_events(t_env *env)
{
	if (env->editor.selected_events == 0
		&& env->sectors[env->editor.selected_sector].wall_sprites[env->
		selected_wall_sprite_wall].nb_press_events[env->
		selected_wall_sprite_sprite] > 0)
	{
		if (print_event_selection(env,
		env->sectors[env->editor.selected_sector].wall_sprites[env->
		selected_wall_sprite_wall].nb_press_events[env->
		selected_wall_sprite_sprite]))
			return (-1);
	}
	else if (env->editor.selected_events == 1
		&& env->sectors[env->editor.selected_sector].wall_sprites[env->
		selected_wall_sprite_wall].nb_shoot_events[env->
		selected_wall_sprite_sprite] > 0)
	{
		if (print_event_selection(env,
		env->sectors[env->editor.selected_sector].wall_sprites[env->
		selected_wall_sprite_wall].nb_shoot_events[env->
		selected_wall_sprite_sprite]))
			return (-1);
	}
	return (0);
}

int		print_events_tab2(t_env *env)
{
	if (env->selected_wall_sprite_wall != -1)
	{
		if (print_wall_sprite_events_tab(env))
			return (-1);
	}
	else if (env->selected_floor == -1 && env->editor.selected_sector == -1
		&& env->selected_enemy == -1 && env->selected_object == -1)
	{
		if (print_global_events_tab(env))
			return (-1);
	}
	return (0);
}

int		print_events_tab(t_env *env)
{
	if (env->selected_enemy != -1)
	{
		if (print_enemy_events_tab(env))
			return (-1);
	}
	else if (env->selected_object != -1)
	{
		if (print_object_events_tab(env))
			return (-1);
	}
	else if (env->selected_wall_sprite_wall == -1
		&& (env->selected_floor != -1 || env->editor.selected_sector != -1))
	{
		if (print_sector_events_tab(env))
			return (-1);
	}
	else if (print_events_tab2(env))
		return (-1);
	if (draw_button(env, env->editor.new_event, "New event"))
		return (-1);
	return (0);
}

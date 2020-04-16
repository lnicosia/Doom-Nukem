/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events_tab_conditions.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 15:35:45 by lnicosia          #+#    #+#             */
/*   Updated: 2020/03/05 11:36:57 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

int			check_sprites_nb_events(t_env *env, int sector, size_t nb)
{
	if (env->selected_wall_sprite_wall != -1
		&& ((env->editor.selected_events == 0
		&& env->sectors[sector].wall_sprites[env->
		selected_wall_sprite_wall].nb_press_events[env->
		selected_wall_sprite_sprite] > nb)
		|| (env->editor.selected_events == 1
		&& env->sectors[sector].wall_sprites[env->
		selected_wall_sprite_wall].nb_shoot_events[env->
		selected_wall_sprite_sprite] > nb)))
		return (1);
	return (0);
}

int			check_sector_nb_events(t_env *env, int sector, size_t nb)
{
	if (sector != -1
		&& ((env->editor.selected_events == 0
		&& env->sectors[sector].nb_stand_events > nb)
		|| (env->editor.selected_events == 1
		&& env->sectors[sector].nb_walk_in_events > nb)
		|| (env->editor.selected_events == 2
		&& env->sectors[sector].nb_walk_out_events > nb)))
		return (1);
	return (0);
}

int			check_event_nb_events(t_env *env, int sector, size_t nb)
{
	if ((sector == -1 && env->selected_enemy == -1
		&& env->selected_object == -1 && env->nb_global_events > nb)
		|| (env->selected_enemy != -1
		&& ((env->editor.selected_events == 1
		&& env->enemies[env->selected_enemy].nb_death_events > nb)
		|| (env->editor.selected_events == 0
		&& env->enemies[env->selected_enemy].nb_collision_events > nb)))
		|| (env->selected_object != -1
		&& env->objects[env->selected_object].nb_collision_events > nb)
		|| check_sector_nb_events(env, sector, nb)
		|| check_sprites_nb_events(env, sector, nb))
		return (1);
	return (0);
}

int			are_event_selection_buttons_visible(t_env *env)
{
	int	sector;

	if (env->selected_floor != -1)
		sector = env->selected_floor;
	else
		sector = env->editor.selected_sector;
	return (check_event_nb_events(env, sector, 1));
}

int			is_modify_event_button_visible(t_env *env)
{
	int	sector;

	if (env->editor.selecting_target || env->editor.selecting_event
		|| env->editor.selecting_condition_target)
		return (0);
	if (env->selected_floor != -1)
		sector = env->selected_floor;
	else
		sector = env->editor.selected_sector;
	return (check_event_nb_events(env, sector, 0));
}

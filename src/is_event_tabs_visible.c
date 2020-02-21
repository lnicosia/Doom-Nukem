/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_event_tabs_visible.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 14:38:43 by lnicosia          #+#    #+#             */
/*   Updated: 2020/02/21 14:49:30 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

int		is_sector_events_tab_visible(t_env *env)
{
	int		sector;

	if (env->editor.selected_sector != -1)
		sector = env->editor.selected_sector;
	else
		sector = env->selected_floor;
	if (sector != -1 && (env->sectors[sector].nb_stand_events > 0
		|| env->sectors[sector].nb_walk_in_events > 0
		|| env->sectors[sector].nb_walk_out_events > 0))
		return (1);
	return (0);
}

int		is_wall_sprite_events_tab_visible(t_env *env)
{
	if (env->selected_wall_sprite_sprite != -1 &&
		(env->sectors[env->editor.selected_sector].wall_sprites[env->
		selected_wall_sprite_wall].nb_press_events[env->
		selected_wall_sprite_sprite] > 0
		|| env->sectors[env->editor.selected_sector].wall_sprites[env->
		selected_wall_sprite_wall].nb_shoot_events[env->
		selected_wall_sprite_sprite] > 0))
		return (1);
	return (0);
}

int		is_enemy_events_tab_visible(t_env *env)
{
	if (env->selected_enemy != -1
		&& (env->enemies[env->selected_enemy].nb_death_events > 0
		|| env->enemies[env->selected_enemy].nb_collision_events > 0))
		return (1);
	return (0);
}

int		is_events_tab_visible(t_env *env)
{
	if ((env->editor.selected_sector == -1 && env->selected_floor == -1
		&& env->nb_global_events > 0)
		|| (env->selected_object != -1
		&& env->objects[env->selected_object].nb_collision_events > 0)
		|| is_enemy_events_tab_visible(env)
		|| is_sector_events_tab_visible(env)
		|| is_wall_sprite_events_tab_visible(env))
		return (1);
	return (0);
}

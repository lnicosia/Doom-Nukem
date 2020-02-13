/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events_tab_conditions.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 15:35:45 by lnicosia          #+#    #+#             */
/*   Updated: 2020/02/13 14:46:50 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

int			is_events_tab_visible(t_env *env)
{
	if ((env->editor.selected_sector == -1 && env->selected_floor == -1
		&& env->nb_global_events > 0)
		|| (env->editor.selected_sector != -1 &&
		(env->sectors[env->editor.selected_sector].nb_stand_events > 0
		|| env->sectors[env->editor.selected_sector].nb_walk_in_events > 0
		|| env->sectors[env->editor.selected_sector].nb_walk_out_events > 0))
		|| (env->selected_floor != -1 &&
		(env->sectors[env->selected_floor].nb_stand_events > 0
		|| env->sectors[env->selected_floor].nb_walk_in_events > 0
		|| env->sectors[env->selected_floor].nb_walk_out_events > 0))
		|| (env->selected_wall_sprite_sprite != -1 &&
		(env->sectors[env->editor.selected_sector].wall_sprites[env->
		selected_wall_sprite_wall].nb_press_events[env->
		selected_wall_sprite_sprite] > 0
		|| env->sectors[env->editor.selected_sector].wall_sprites[env->
		selected_wall_sprite_wall].nb_shoot_events[env->
		selected_wall_sprite_sprite] > 0)))
		return (1);
	return (0);
}

int			are_event_selection_buttons_visible(t_env *env)
{
	if ((env->selected_wall_sprite_wall != -1
		&& ((env->editor.selected_events == 0 && env->sectors[env->
		editor.selected_sector].wall_sprites[env->
		selected_wall_sprite_wall].nb_press_events[env->
		selected_wall_sprite_sprite] > 1)
		|| (env->editor.selected_events == 0 && env->sectors[env->
		editor.selected_sector].wall_sprites[env->
		selected_wall_sprite_wall].nb_shoot_events[env->
		selected_wall_sprite_sprite] > 1)))
		|| (env->editor.selected_sector != -1
		&& ((env->editor.selected_events == 0 && env->sectors[env->
		editor.selected_sector].nb_stand_events > 1)
		|| (env->editor.selected_events == 1 && env->sectors[env->
		editor.selected_sector].nb_walk_in_events > 1)
		|| (env->editor.selected_events == 2 && env->sectors[env->
		editor.selected_sector].nb_walk_out_events > 1)))
		|| (env->editor.selected_sector == -1
		&& env->selected_floor == -1 && env->nb_global_events > 1))
		return (1);
	return (0);
}

int			is_modify_event_button_visible(t_env *env)
{
	if ((env->selected_wall_sprite_wall != -1
		&& ((env->editor.selected_events == 0 && env->sectors[env->
		editor.selected_sector].wall_sprites[env->
		selected_wall_sprite_wall].nb_press_events[env->
		selected_wall_sprite_sprite] > 0)
		|| (env->editor.selected_events == 0 && env->sectors[env->
		editor.selected_sector].wall_sprites[env->
		selected_wall_sprite_wall].nb_shoot_events[env->
		selected_wall_sprite_sprite] > 0)))
		|| (env->editor.selected_sector != -1
		&& ((env->editor.selected_events == 0 && env->sectors[env->
		editor.selected_sector].nb_stand_events > 0)
		|| (env->editor.selected_events == 1 && env->sectors[env->
		editor.selected_sector].nb_walk_in_events > 0)
		|| (env->editor.selected_events == 2 && env->sectors[env->
		editor.selected_sector].nb_walk_out_events > 0)))
		|| (env->editor.selected_sector == -1
		&& env->selected_floor == -1 && env->nb_global_events > 0))
		return (1);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   are_exec_condition_selection_buttons_visible.c     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 17:18:22 by lnicosia          #+#    #+#             */
/*   Updated: 2020/02/21 14:08:59 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

int			check_sector_exec_conditions(t_env *env,
int sector)
{
	int		event;
	int		events;

	event = env->editor.selected_event;
	events = env->editor.selected_events;
	if (sector != -1 && ((events == 0 && env->sectors[sector].
		nb_stand_events > 0 && env->sectors[sector].stand_events[event].
		nb_exec_conditions > 1) || (events == 1 && env->sectors[sector].
		nb_walk_in_events > 0 && env->sectors[sector].walk_in_events[event].
		nb_exec_conditions > 1)
		|| (events == 2 && env->sectors[sector].
		nb_walk_out_events > 0 && env->sectors[sector].walk_out_events[event].
		nb_exec_conditions > 1)))
		return (1);
	return (0);
}

int			check_wall_sprite_exec_conditions(t_env *env, int sector,
int wall, int sprite)
{
	int		event;
	int		events;

	event = env->editor.selected_event;
	events = env->editor.selected_events;
	if (env->selected_wall_sprite_wall != -1
		&& ((events == 0 && env->sectors[sector].wall_sprites[wall].
		nb_press_events[sprite] > 0 && env->sectors[sector].
		wall_sprites[wall].press_events[sprite][event].
		nb_exec_conditions > 1) || (events == 1 && env->sectors[sector].
		wall_sprites[wall].nb_shoot_events[sprite] > 0 && env->sectors[sector].
		wall_sprites[wall].shoot_events[sprite][event].nb_exec_conditions >
		1)))
		return (1);
	return (0);
}

int			check_object_exec_conditions(t_env *env,
int object)
{
	int		event;
	int		events;

	event = env->editor.selected_event;
	events = env->editor.selected_events;
	if (env->selected_object != -1
		&& env->objects[object].nb_collision_events > 0
		&& env->objects[object].collision_events[event].nb_exec_conditions > 1)
		return (1);
	return (0);
}

int			check_enemy_exec_conditions(t_env *env,
int enemy)
{
	int		event;
	int		events;

	event = env->editor.selected_event;
	events = env->editor.selected_events;
	if (env->selected_enemy != -1
		&& ((env->enemies[enemy].nb_death_events > 0
		&& env->enemies[enemy].death_events[event].nb_exec_conditions > 1)
		|| (env->enemies[enemy].nb_collision_events > 0
		&& env->enemies[enemy].collision_events[event].nb_exec_conditions > 1)))
		return (1);
	return (0);
}

int			check_global_exec_conditions(t_env *env)
{
	int		event;
	int		events;

	event = env->editor.selected_event;
	events = env->editor.selected_events;
	if (env->nb_global_events > 0 && env->global_events[event].
		nb_exec_conditions > 1)
		return (1);
	return (0);
}

int			are_exec_condition_selection_buttons_visible(t_env *env)
{
	int			sector;
	int			wall;
	int			sprite;

	sector = env->editor.selected_sector;
	wall = env->selected_wall_sprite_wall;
	sprite = env->selected_wall_sprite_sprite;
	if (check_wall_sprite_exec_conditions(env, sector, wall, sprite)
		|| check_sector_exec_conditions(env, sector)
		|| check_enemy_exec_conditions(env, env->selected_enemy)
		|| check_object_exec_conditions(env, env->selected_object)
		|| check_global_exec_conditions(env))
		return (1);
	return (0);
}

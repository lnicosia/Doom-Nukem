/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   are_condition_selection_buttons_visible.c          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 17:18:22 by lnicosia          #+#    #+#             */
/*   Updated: 2020/02/13 17:25:27 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

int			condition_selection_buttons_condition1(t_env *env,
int sector, int wall, int sprite)
{
	int		event;
	int		events;

	event = env->editor.selected_event;
	events = env->editor.selected_events;
	ft_printf("sector = %d\n", sector);
	ft_printf("event = %d\n", event);
	if ((env->selected_wall_sprite_wall != -1
		&& ((events == 0 && env->sectors[sector].wall_sprites[wall].
		nb_press_events[sprite] > 0 && env->sectors[sector].
		wall_sprites[wall].press_events[sprite][event].
		nb_launch_conditions > 1) || (events == 1 && env->sectors[sector].
		wall_sprites[wall].nb_shoot_events[sprite] > 0 && env->sectors[sector].
		wall_sprites[wall].shoot_events[sprite][event].nb_launch_conditions >
		1))) || (sector != -1 && ((events == 0 && env->sectors[sector].
		nb_stand_events > 0 && env->sectors[sector].stand_events[event].
		nb_launch_conditions > 1) || (events == 1 && env->sectors[sector].
		nb_walk_in_events > 0 && env->sectors[sector].walk_in_events[event].
		nb_launch_conditions > 1) || (events == 2 && env->sectors[sector].
		nb_walk_out_events > 0 && env->sectors[sector].walk_out_events[event].
		nb_launch_conditions > 1))) || (sector == -1 && env->selected_floor ==
		-1 && env->nb_global_events > 0 && env->global_events[event].
		nb_launch_conditions > 1))
		return (1);
	return (0);
}

int			are_launch_condition_selection_buttons_visible(t_env *env)
{
	int			sector;
	int			wall;
	int			sprite;

	sector = env->editor.selected_sector;
	wall = env->selected_wall_sprite_wall;
	sprite = env->selected_wall_sprite_sprite;
	return (condition_selection_buttons_condition1(env, sector, wall, sprite));
}

int			condition_selection_buttons_condition2(t_env *env,
int sector, int wall, int sprite)
{
	int		event;
	int		events;

	event = env->editor.selected_event;
	events = env->editor.selected_events;
	if ((env->selected_wall_sprite_wall != -1
		&& ((events == 0 && env->sectors[sector].wall_sprites[wall].
		nb_press_events[sprite] > 0 && env->sectors[sector].
		wall_sprites[wall].press_events[sprite][event].
		nb_exec_conditions > 1) || (events == 1 && env->sectors[sector].
		wall_sprites[wall].nb_shoot_events[sprite] > 0 && env->sectors[sector].
		wall_sprites[wall].shoot_events[sprite][event].nb_exec_conditions >
		1))) || (sector != -1 && ((events == 0 && env->sectors[sector].
		nb_stand_events > 0 && env->sectors[sector].stand_events[event].
		nb_exec_conditions > 1) || (events == 1 && env->sectors[sector].
		nb_walk_in_events > 0 && env->sectors[sector].walk_in_events[event].
		nb_exec_conditions > 1) || (events == 2 && env->sectors[sector].
		nb_walk_out_events > 0 && env->sectors[sector].walk_out_events[event].
		nb_exec_conditions > 1))) || (sector == -1 && env->selected_floor ==
		-1 && env->nb_global_events > 0 && env->global_events[event].
		nb_exec_conditions > 1))
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
	return (condition_selection_buttons_condition2(env, sector, wall, sprite));
}

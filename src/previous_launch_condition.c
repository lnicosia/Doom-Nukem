/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   previous_launch_condition.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/30 18:38:22 by lnicosia          #+#    #+#             */
/*   Updated: 2020/05/21 18:14:22 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

void	select_sector_launch_condition(t_env *env)
{
	int		sector;

	sector = -1;
	if (env->selected_floor != -1)
		sector = env->selected_floor;
	else
		sector = env->editor.selected_sector;
	if (env->editor.selected_events == 0)
		env->editor.selected_launch_condition = env->sectors[sector].
		stand_events[env->editor.selected_event].
		nb_launch_conditions - 1;
	else if (env->editor.selected_events == 1)
		env->editor.selected_launch_condition =
		env->sectors[sector].
		walk_in_events[env->editor.selected_event].
		nb_launch_conditions - 1;
	else if (env->editor.selected_events == 2)
		env->editor.selected_launch_condition = env->sectors[sector].
		walk_out_events[env->editor.selected_event].
		nb_launch_conditions - 1;
}

int		previous_launch_condition3(t_env *env)
{
	if (env->selected_floor != -1 || env->editor.selected_sector != -1)
	{
		select_sector_launch_condition(env);
	}
	else if (env->selected_floor == -1 && env->editor.selected_sector == -1
		&& env->selected_enemy == -1 && env->selected_object == -1)
		env->editor.selected_launch_condition =
		env->global_events[env->editor.selected_event].nb_launch_conditions - 1;
	return (0);
}

int		previous_launch_condition2(t_env *env)
{
	if (env->selected_wall_sprite_wall != -1)
	{
		if (env->editor.selected_events == 0)
			env->editor.selected_launch_condition =
			env->sectors[env->editor.selected_sector].
			wall_sprites[env->selected_wall_sprite_wall].
			press_events[env->selected_wall_sprite_sprite]
			[env->editor.selected_event].nb_launch_conditions - 1;
		else if (env->editor.selected_events == 1)
			env->editor.selected_launch_condition =
			env->sectors[env->editor.selected_sector].
			wall_sprites[env->selected_wall_sprite_wall].
			shoot_events[env->selected_wall_sprite_sprite]
			[env->editor.selected_event].nb_launch_conditions - 1;
	}
	else
		return (previous_launch_condition3(env));
	return (0);
}

void	previous_enemy_launch_condition(t_env *env)
{
	if (env->editor.selected_events == 0)
		env->editor.selected_launch_condition = env->enemies[env->
		selected_enemy].collision_events[env->editor.selected_event].
		nb_launch_conditions - 1;
	else if (env->editor.selected_events == 1)
		env->editor.selected_launch_condition = env->enemies[env->
		selected_enemy].death_events[env->editor.selected_event].
		nb_launch_conditions - 1;
}

int		previous_launch_condition(void *penv)
{
	t_env	*env;

	env = (t_env *)penv;
	if (env->editor.selected_launch_condition > 0)
		env->editor.selected_launch_condition--;
	else
	{
		if (env->selected_enemy != -1)
			previous_enemy_launch_condition(env);
		else if (env->selected_object != -1)
			env->editor.selected_launch_condition = env->objects[env->
			selected_object].collision_events[env->editor.selected_event].
			nb_launch_conditions - 1;
		else
			return (previous_launch_condition2(env));
	}
	return (0);
}

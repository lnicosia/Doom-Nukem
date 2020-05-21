/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   next_launch_condition.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/30 17:39:45 by lnicosia          #+#    #+#             */
/*   Updated: 2020/04/30 17:39:46 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

int		next_launch_condition4(t_env *env)
{
	if (env->selected_floor == -1 && env->editor.selected_sector == -1
		&& env->selected_enemy == -1 && env->selected_object == -1
		&& env->editor.selected_launch_condition >=
		env->global_events[env->editor.selected_event].nb_launch_conditions)
		env->editor.selected_launch_condition = 0;
	return (0);
}

int		next_launch_condition3(int sector, t_env *env)
{
	if (env->selected_floor != -1 || env->editor.selected_sector != -1)
	{
		if (env->selected_floor != -1)
			sector = env->selected_floor;
		else
			sector = env->editor.selected_sector;
		if (env->editor.selected_events == 0
		&& env->editor.selected_launch_condition >=
		env->sectors[sector].stand_events[env->editor.selected_event].
		nb_launch_conditions)
			env->editor.selected_launch_condition = 0;
		else if (env->editor.selected_events == 1
		&& env->editor.selected_launch_condition >=
		env->sectors[sector].walk_in_events[env->editor.selected_event].
		nb_launch_conditions)
			env->editor.selected_launch_condition = 0;
		else if (env->editor.selected_events == 2
		&& env->editor.selected_launch_condition >=
		env->sectors[sector].walk_out_events[env->editor.selected_event].
		nb_launch_conditions)
			env->editor.selected_launch_condition = 0;
	}
	else
		return (next_launch_condition4(env));
	return (0);
}

int		next_launch_condition2(int sector, t_env *env)
{
	if (env->selected_wall_sprite_wall != -1)
	{
		if (env->editor.selected_events == 0
		&& env->editor.selected_launch_condition >= env->sectors[env->
		editor.selected_sector].wall_sprites[env->selected_wall_sprite_wall].
		press_events[env->selected_wall_sprite_sprite]
		[env->editor.selected_event].nb_launch_conditions)
			env->editor.selected_launch_condition = 0;
		else if (env->editor.selected_events == 1
		&& env->editor.selected_launch_condition >= env->sectors[env->
		editor.selected_sector].wall_sprites[env->selected_wall_sprite_wall].
		shoot_events[env->selected_wall_sprite_sprite]
		[env->editor.selected_event].nb_launch_conditions)
			env->editor.selected_launch_condition = 0;
	}
	else
		return (next_launch_condition3(sector, env));
	return (0);
}

int		next_launch_condition(void *penv)
{
	t_env	*env;
	int		sector;

	env = (t_env *)penv;
	sector = -1;
	env->editor.selected_launch_condition++;
	if (env->selected_enemy != -1)
	{
		if (env->editor.selected_events == 0
			&& env->editor.selected_launch_condition >=
			env->enemies[env->selected_enemy].
			collision_events[env->editor.selected_events].nb_launch_conditions)
			env->editor.selected_launch_condition = 0;
		else if (env->editor.selected_events == 1
			&& env->editor.selected_launch_condition >=
			env->enemies[env->selected_enemy].
			death_events[env->editor.selected_events].nb_launch_conditions)
			env->editor.selected_launch_condition = 0;
	}
	else if (env->selected_object != -1
		&& env->editor.selected_launch_condition >=
		env->objects[env->selected_object].
		collision_events[env->editor.selected_events].nb_launch_conditions)
		env->editor.selected_launch_condition = 0;
	else
		return (next_launch_condition2(sector, env));
	return (0);
}

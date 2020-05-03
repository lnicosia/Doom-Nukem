/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   previous_event.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/30 18:30:59 by lnicosia          #+#    #+#             */
/*   Updated: 2020/04/30 18:30:59 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

int		previous_event3(int sector, t_env *env)
{
	if (env->selected_floor != -1 || env->editor.selected_sector != -1)
	{
		if (env->selected_floor != -1)
			sector = env->selected_floor;
		else
			sector = env->editor.selected_sector;
		if (env->editor.selected_events == 0)
			env->editor.selected_event =
			env->sectors[sector].nb_stand_events - 1;
		else if (env->editor.selected_events == 1)
			env->editor.selected_event =
			env->sectors[sector].nb_walk_in_events - 1;
		else if (env->editor.selected_events == 2)
			env->editor.selected_event =
			env->sectors[sector].nb_walk_out_events - 1;
	}
	else if (env->selected_floor == -1 && env->editor.selected_sector == -1
		&& env->selected_enemy == -1 && env->selected_object == -1)
		env->editor.selected_event = env->nb_global_events - 1;
	return (0);
}

int		previous_event2(int sector, t_env *env)
{
	if (env->selected_wall_sprite_wall != -1)
	{
		if (env->editor.selected_events == 0)
			env->editor.selected_event = env->sectors[env->
				editor.selected_sector].wall_sprites[env->
				selected_wall_sprite_wall].nb_press_events[env->
				selected_wall_sprite_sprite] - 1;
		else if (env->editor.selected_events == 1)
			env->editor.selected_event = env->sectors[env->
				editor.selected_sector].wall_sprites[env->
				selected_wall_sprite_wall].nb_shoot_events[env->
				selected_wall_sprite_sprite] - 1;
	}
	return (previous_event3(sector, env));
}

int		previous_event(void *penv)
{
	t_env	*env;
	int		sector;

	env = (t_env *)penv;
	sector = -1;
	env->editor.selected_launch_condition = 0;
	env->editor.selected_exec_condition = 0;
	env->editor.selected_event -= env->editor.selected_event > 0 ? 1 : 0;
	if (env->editor.selected_event <= 0)
	{
		if (env->selected_enemy != -1)
		{
			if (env->editor.selected_events == 0)
				env->editor.selected_event = env->enemies[env->selected_enemy].
				nb_collision_events - 1;
			else if (env->editor.selected_events == 1)
				env->editor.selected_event = env->enemies[env->selected_enemy].
				nb_death_events - 1;
		}
		else if (env->selected_object != -1)
			env->editor.selected_event = env->objects[env->selected_object].
			nb_collision_events - 1;
		return (previous_event2(sector, env));
	}
	return (0);
}

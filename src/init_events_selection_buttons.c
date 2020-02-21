/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_events_selection_buttons.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipatry <sipatry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 17:25:57 by lnicosia          #+#    #+#             */
/*   Updated: 2020/02/21 15:19:11 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

/*
**	Next events array
**	Only if they are mutilple arrays for the current selection
**	Ex: Sector:
**				_Stand events
**				_Walk in events
**				_Walk out events
*/

int		next_events(void *penv)
{
	t_env	*env;

	env = (t_env *)penv;
	if (env->selected_enemy != -1 || env->selected_wall_sprite_wall != -1)
		env->editor.selected_events = env->editor.selected_events >= 1 ? 0 : 1;
	else if (env->selected_floor != -1 || env->editor.selected_sector != -1)
	{
		env->editor.selected_events++;
		if (env->editor.selected_events == 3)
			env->editor.selected_events = 0;
	}
	env->editor.selected_event = 0;
	env->editor.selected_launch_condition = 0;
	env->editor.selected_exec_condition = 0;
	return (0);
}

/*
**	Previous events array
**	Only if they are mutilple arrays for the current selection
**	Ex: Sector:
**				_Stand events
**				_Walk in events
**				_Walk out events
*/

int		prec_events(void *penv)
{
	t_env	*env;

	env = (t_env *)penv;
	if (env->selected_enemy != -1 || env->selected_wall_sprite_wall != -1)
		env->editor.selected_events = env->editor.selected_events >= 1 ? 0 : 1;
	else if (env->selected_floor != -1 || env->editor.selected_sector != -1)
	{
		env->editor.selected_events--;
		if (env->editor.selected_events < 0)
			env->editor.selected_events = 2;
	}
	env->editor.selected_event = 0;
	env->editor.selected_launch_condition = 0;
	env->editor.selected_exec_condition = 0;
	return (0);
}

int		next_event(void *penv)
{
	t_env	*env;
	int		sector;

	env = (t_env *)penv;
	sector = -1;
	env->editor.selected_event++;
	if (env->selected_enemy != -1
		&& ((env->editor.selected_events == 0
		&& env->editor.selected_event >= env->enemies[env->selected_enemy].
		nb_collision_events)
		|| ((env->editor.selected_events == 1
		&& env->editor.selected_event >= env->enemies[env->selected_enemy].
		nb_death_events))))
		env->editor.selected_event = 0;
	else if (env->selected_object != -1
		&& env->editor.selected_event >= env->objects[env->selected_object].
		nb_collision_events)
		env->editor.selected_event = 0;
	else if (env->selected_wall_sprite_wall != -1)
	{
		if ((env->editor.selected_events == 0
			&& env->editor.selected_event >= env->sectors[env->
			editor.selected_sector].wall_sprites[env->selected_wall_sprite_wall].
			nb_press_events[env->selected_wall_sprite_sprite])
			|| (env->editor.selected_events == 1
			&& env->editor.selected_event >= env->sectors[env->
			editor.selected_sector].wall_sprites[env->selected_wall_sprite_wall].
			nb_shoot_events[env->selected_wall_sprite_sprite]))
			env->editor.selected_event = 0;
	}
	else if (env->selected_floor != -1 || env->editor.selected_sector != -1)
	{
		if (env->selected_floor != -1)
			sector = env->selected_floor;
		else
			sector = env->editor.selected_sector;
		if ((env->editor.selected_events == 0
			&& env->editor.selected_event >=
			env->sectors[sector].nb_stand_events)
			|| (env->editor.selected_events == 1
			&& env->editor.selected_event >=
			env->sectors[sector].nb_walk_in_events)
			|| (env->editor.selected_events == 2
			&& env->editor.selected_event >=
			env->sectors[sector].nb_walk_out_events))
			env->editor.selected_event = 0;
	}
	else if (env->selected_floor == -1 && env->editor.selected_sector == -1
			&& env->editor.selected_event >= env->nb_global_events)
		env->editor.selected_event = 0;
	env->editor.selected_launch_condition = 0;
	env->editor.selected_exec_condition = 0;
	return (0);
}

int		previous_event(void *penv)
{
	t_env	*env;
	int		sector;

	env = (t_env *)penv;
	sector = -1;
	if (env->editor.selected_event > 0)
		env->editor.selected_event--;
	else
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
		else if (env->selected_wall_sprite_wall != -1)
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
		else if (env->selected_floor != -1 || env->editor.selected_sector != -1)
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
		else if (env->selected_floor == -1 && env->editor.selected_sector == -1)
			env->editor.selected_event = env->nb_global_events - 1;
	}
	env->editor.selected_launch_condition = 0;
	env->editor.selected_exec_condition = 0;
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
	else if (env->selected_wall_sprite_wall != -1)
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
	else if (env->selected_floor != -1 || env->editor.selected_sector != -1)
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
	else if (env->selected_floor == -1 && env->editor.selected_sector == -1
		&& env->editor.selected_launch_condition >=
		env->global_events[env->editor.selected_event].nb_launch_conditions)
		env->editor.selected_launch_condition = 0;
	return (0);
}

int		previous_launch_condition(void *penv)
{
	t_env	*env;
	int		sector;

	env = (t_env *)penv;
	sector = -1;
	if (env->editor.selected_launch_condition > 0)
		env->editor.selected_launch_condition--;
	else
	{
		if (env->selected_enemy != -1)
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
		else if (env->selected_object != -1)
			env->editor.selected_launch_condition = env->objects[env->
			selected_object].collision_events[env->editor.selected_event].
			nb_launch_conditions - 1;
		else if (env->selected_wall_sprite_wall != -1)
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
		else if (env->selected_floor != -1 || env->editor.selected_sector != -1)
		{
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
				env->editor.selected_launch_condition =
				env->sectors[sector].
				walk_out_events[env->editor.selected_event].
				nb_launch_conditions - 1;
		}
		else if (env->selected_floor == -1 && env->editor.selected_sector == -1)
			env->editor.selected_launch_condition =
			env->global_events[env->editor.selected_event].nb_launch_conditions - 1;
	}
	return (0);
}

int		next_exec_condition(void *penv)
{
	t_env	*env;
	int		sector;

	env = (t_env *)penv;
	sector = -1;
	env->editor.selected_exec_condition++;
	if (env->selected_enemy != -1)
	{
		if (env->editor.selected_events == 0
			&& env->editor.selected_exec_condition >=
			env->enemies[env->selected_enemy].
			collision_events[env->editor.selected_events].nb_exec_conditions)
			env->editor.selected_exec_condition = 0;
		else if (env->editor.selected_events == 1
			&& env->editor.selected_exec_condition >=
			env->enemies[env->selected_enemy].
			death_events[env->editor.selected_events].nb_exec_conditions)
			env->editor.selected_exec_condition = 0;
	}
	else if (env->selected_object != -1
		&& env->editor.selected_exec_condition >=
		env->objects[env->selected_object].
		collision_events[env->editor.selected_events].nb_exec_conditions)
		env->editor.selected_exec_condition = 0;
	else if (env->selected_wall_sprite_wall != -1)
	{
		if (env->editor.selected_events == 0
		&& env->editor.selected_exec_condition >= env->sectors[env->
		editor.selected_sector].wall_sprites[env->selected_wall_sprite_wall].
		press_events[env->selected_wall_sprite_sprite]
		[env->editor.selected_event].nb_exec_conditions)
			env->editor.selected_exec_condition = 0;
		else if (env->editor.selected_events == 1
		&& env->editor.selected_exec_condition >= env->sectors[env->
		editor.selected_sector].wall_sprites[env->selected_wall_sprite_wall].
		shoot_events[env->selected_wall_sprite_sprite]
		[env->editor.selected_event].nb_exec_conditions)
			env->editor.selected_exec_condition = 0;
	}
	else if (env->selected_floor != -1 || env->editor.selected_sector != -1)
	{
		if (env->selected_floor != -1)
			sector = env->selected_floor;
		else
			sector = env->editor.selected_sector;
		if (env->editor.selected_events == 0
		&& env->editor.selected_exec_condition >= env->sectors[sector].
		stand_events[env->editor.selected_event].nb_exec_conditions)
			env->editor.selected_exec_condition = 0;
		else if (env->editor.selected_events == 1
		&& env->editor.selected_exec_condition >= env->sectors[sector].
		walk_in_events[env->editor.selected_event].nb_exec_conditions)
			env->editor.selected_exec_condition = 0;
		else if (env->editor.selected_events == 2
		&& env->editor.selected_exec_condition >= env->sectors[sector].
		walk_out_events[env->editor.selected_event].nb_exec_conditions)
			env->editor.selected_exec_condition = 0;
	}
	else if (env->selected_floor == -1 && env->editor.selected_sector == -1
		&& env->editor.selected_exec_condition >=
		env->global_events[env->editor.selected_event].nb_exec_conditions)
		env->editor.selected_exec_condition = 0;
	return (0);
}

int		previous_exec_condition(void *penv)
{
	t_env	*env;

	env = (t_env *)penv;
	if (env->editor.selected_exec_condition > 0)
		env->editor.selected_exec_condition--;
	else
	{
		if (env->selected_enemy != -1)
		{
			if (env->editor.selected_events == 0)
				env->editor.selected_exec_condition = env->enemies[env->
				selected_enemy].collision_events[env->editor.selected_event].
				nb_exec_conditions - 1;
			else if (env->editor.selected_events == 1)
				env->editor.selected_exec_condition = env->enemies[env->
				selected_enemy].death_events[env->editor.selected_event].
				nb_exec_conditions - 1;
		}
		else if (env->selected_object != -1)
			env->editor.selected_exec_condition = env->objects[env->
			selected_object].collision_events[env->editor.selected_event].
			nb_exec_conditions - 1;
		else if (env->selected_wall_sprite_wall != -1)
		{
			if (env->editor.selected_events == 0)
				env->editor.selected_exec_condition =
				env->sectors[env->editor.selected_sector].
				wall_sprites[env->selected_wall_sprite_wall].
				press_events[env->selected_wall_sprite_sprite]
				[env->editor.selected_event].nb_exec_conditions - 1;
			else if (env->editor.selected_events == 1)
				env->editor.selected_exec_condition =
				env->sectors[env->editor.selected_sector].
				wall_sprites[env->selected_wall_sprite_wall].
				shoot_events[env->selected_wall_sprite_sprite]
				[env->editor.selected_event].nb_exec_conditions - 1;
		}
		else if (env->selected_floor != -1 || env->editor.selected_sector != -1)
		{
			if (env->editor.selected_events == 0)
				env->editor.selected_exec_condition =
				env->sectors[env->editor.selected_sector].
				stand_events[env->editor.selected_event].
				nb_exec_conditions - 1;
			else if (env->editor.selected_events == 1)
				env->editor.selected_exec_condition =
				env->sectors[env->editor.selected_sector].
				walk_in_events[env->editor.selected_event].
				nb_exec_conditions - 1;
			else if (env->editor.selected_events == 2)
				env->editor.selected_exec_condition =
				env->sectors[env->editor.selected_sector].
				walk_out_events[env->editor.selected_event].
				nb_exec_conditions - 1;
		}
		else if (env->selected_floor == -1 && env->editor.selected_sector == -1)
			env->editor.selected_exec_condition =
			env->global_events[env->editor.selected_event].nb_exec_conditions - 1;
	}
	return (0);
}

void	init_events_selection_buttons(t_env *env)
{
	env->editor.next_events = new_next_button(ON_RELEASE,
			&next_events, env, env);
	env->editor.next_events.pos = new_point(290, 470);
	env->editor.previous_events = new_previous_button(ON_RELEASE,
			&prec_events, env, env);
	env->editor.previous_events.pos = new_point(90, 470);
	env->editor.next_event = new_next_button(ON_RELEASE,
			&next_event, env, env);
	env->editor.next_event.pos = new_point(290, 500);
	env->editor.previous_event = new_previous_button(ON_RELEASE,
			&previous_event, env, env);
	env->editor.previous_event.pos = new_point(90, 500);
	env->editor.next_launch_condition = new_next_button(ON_RELEASE,
			&next_launch_condition, env, env);
	env->editor.next_launch_condition.pos = new_point(290, 680);
	env->editor.previous_launch_condition = new_previous_button(ON_RELEASE,
			&previous_launch_condition, env, env);
	env->editor.previous_launch_condition.pos = new_point(90, 680);
	env->editor.next_exec_condition = new_next_button(ON_RELEASE,
			&next_exec_condition, env, env);
	env->editor.next_exec_condition.pos = new_point(300, 800);
	env->editor.previous_exec_condition = new_previous_button(ON_RELEASE,
			&previous_exec_condition, env, env);
	env->editor.previous_exec_condition.pos = new_point(90, 800);
}

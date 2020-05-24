/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_existing_events.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipatry <sipatry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 12:29:41 by sipatry           #+#    #+#             */
/*   Updated: 2020/02/25 12:08:06 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "update_existing_events.h"
#include "events_parser.h"
#include "init.h"
#include "events.h"
#include "parser.h"

int		check_objects_events_targets(t_env *env, t_event_target target,
t_event_trigger *trigger)
{
	int		i;
	size_t	j;

	i = 0;
	trigger->type = OBJECT_COLLISION;
	while (i < env->nb_objects)
	{
		trigger->object = i;
		j = 0;
		while (j < env->objects[i].nb_collision_events)
		{
			trigger->index = j;
			if (check_event_targets(env, &env->objects[i].collision_events[j],
				target, trigger))
				return (-1);
			j++;
		}
		i++;
	}
	return (0);
}

int		check_wall_sprite_shoot_events_targets(t_env *env,
t_event_target target, t_event_trigger *trigger, t_wall_sprites *wall_sprites)
{
	int		i;
	size_t	j;

	i = 0;
	trigger->type = SHOOT;
	while (i < wall_sprites->nb_sprites)
	{
		j = 0;
		trigger->sprite = i;
		while (j < wall_sprites->nb_shoot_events[i])
		{
			trigger->index = j;
			if (check_event_targets(env, &wall_sprites->shoot_events[i][j],
				target, trigger))
				return (-1);
			j++;
		}
		i++;
	}
	return (0);
}

int		check_wall_sprite_press_events_targets(t_env *env,
t_event_target target, t_event_trigger *trigger, t_wall_sprites *wall_sprites)
{
	int		i;
	size_t	j;

	i = 0;
	trigger->type = PRESS;
	while (i < wall_sprites->nb_sprites)
	{
		j = 0;
		trigger->sprite = i;
		while (j < wall_sprites->nb_press_events[i])
		{
			trigger->index = j;
			if (check_event_targets(env, &wall_sprites->press_events[i][j],
				target, trigger))
				return (-1);
			j++;
		}
		i++;
	}
	return (0);
}

int		check_wall_sprites_events_targets(t_env *env, t_event_target target,
t_event_trigger *trigger)
{
	int		i;
	int		j;

	i = 0;
	while (i < env->nb_sectors)
	{
		j = 0;
		trigger->sector = i;
		while (j < env->sectors[i].nb_vertices)
		{
			trigger->wall = j;
			if (env->sectors[i].wall_sprites[j].nb_sprites > 0)
			{
				if (check_wall_sprite_shoot_events_targets(env, target, trigger,
					&env->sectors[i].wall_sprites[j]))
					return (-1);
				if (check_wall_sprite_press_events_targets(env, target, trigger,
					&env->sectors[i].wall_sprites[j]))
					return (-1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

/*
**	Check if any existing events had the deleted sector as a target
**	Things to check:
**	Every trigger (enemies, objects, wall sprites, global, sector)
*/

int		update_sector_existing_events(t_env *env, t_event_target target)
{
	t_event_trigger		trigger;

	init_trigger(&trigger);
	if (check_sectors_events_targets(env, target, &trigger))
		return (-1);
	init_trigger(&trigger);
	if (check_enemies_events_targets(env, target, &trigger))
		return (-1);
	init_trigger(&trigger);
	if (check_objects_events_targets(env, target, &trigger))
		return (-1);
	init_trigger(&trigger);
	if (check_wall_sprites_events_targets(env, target, &trigger))
		return (-1);
	init_trigger(&trigger);
	if (env->nb_global_events > 0 && check_global_events_targets(env, target,
		&trigger))
		return (-1);
	return (0);
}

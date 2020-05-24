/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_existing_events2.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/01 11:36:49 by lnicosia          #+#    #+#             */
/*   Updated: 2020/05/01 11:36:50 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "update_existing_events.h"
#include "events_parser.h"
#include "events.h"
#include "parser.h"

int		check_sectors_events_targets(t_env *env, t_event_target target,
t_event_trigger *trigger)
{
	int		i;

	i = -1;
	while (++i < env->nb_sectors)
	{
		if (i == target.sector)
			continue;
		if (env->sectors[i].nb_stand_events > 0
			&& check_stand_events_targets(env, &env->sectors[i],
			target, trigger))
			return (-1);
		if (env->sectors[i].nb_walk_in_events > 0
			&& check_walk_in_events_targets(env, &env->sectors[i],
			target, trigger))
			return (-1);
		if (env->sectors[i].nb_walk_out_events > 0
			&& check_walk_out_events_targets(env, &env->sectors[i],
				target, trigger))
			return (-1);
	}
	return (0);
}

int		check_global_events_targets(t_env *env, t_event_target target,
t_event_trigger *trigger)
{
	size_t	i;

	i = 0;
	trigger->type = GLOBAL;
	while (i < env->nb_global_events)
	{
		trigger->index = i;
		if (check_event_targets(env, &env->global_events[i],
			target, trigger))
			return (-1);
		i++;
	}
	return (0);
}

int		check_enemy_collision_events_targets(t_env *env, t_enemy *enemy,
t_event_target target, t_event_trigger *trigger)
{
	size_t	j;

	j = 0;
	trigger->type = ENEMY_COLLISION;
	while (j < enemy->nb_collision_events)
	{
		trigger->index = j;
		if (check_event_targets(env, &enemy->collision_events[j],
			target, trigger))
			return (-1);
		j++;
	}
	return (0);
}

int		check_enemy_death_events_targets(t_env *env, t_enemy *enemy,
t_event_target target, t_event_trigger *trigger)
{
	size_t	j;

	j = 0;
	trigger->type = DEATH;
	while (j < enemy->nb_death_events)
	{
		trigger->index = j;
		if (check_event_targets(env, &enemy->death_events[j],
			target, trigger))
			return (-1);
		j++;
	}
	return (0);
}

int		check_enemies_events_targets(t_env *env, t_event_target target,
t_event_trigger *trigger)
{
	int		i;

	i = 0;
	while (i < env->nb_enemies)
	{
		trigger->enemy = i;
		if (check_enemy_collision_events_targets(env, &env->enemies[i],
			target, trigger))
			return (-1);
		if (check_enemy_death_events_targets(env, &env->enemies[i],
			target, trigger))
			return (-1);
		i++;
	}
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_selected_event.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/29 15:59:12 by lnicosia          #+#    #+#             */
/*   Updated: 2020/04/29 15:59:13 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "free.h"
#include "events_parser.h"

int		delete_selected_event4(t_env *env, t_event_trigger trigger,
t_event **events, size_t *nb)
{
	if (trigger.type == OBJECT_COLLISION)
	{
		events = &env->objects[trigger.object].collision_events;
		nb = &env->objects[trigger.object].nb_collision_events;
	}
	free_event(&(*events)[trigger.index]);
	*events = (t_event*)ft_delindex(*events, sizeof(t_event) * *nb,
	sizeof(t_event), sizeof(t_event) * trigger.index);
	(*nb)--;
	if (*nb > 0 && !(*events))
		return (-1);
	if (env->editor.selected_event == *nb)
		env->editor.selected_event--;
	return (0);
}

int		delete_selected_event3(t_env *env, t_event_trigger trigger,
t_event **events, size_t *nb)
{
	if (trigger.type == WALK_OUT)
	{
		events = &env->sectors[trigger.sector].walk_out_events;
		nb = &env->sectors[trigger.sector].nb_walk_out_events;
	}
	else if (trigger.type == DEATH)
	{
		events = &env->enemies[trigger.enemy].death_events;
		nb = &env->enemies[trigger.enemy].nb_death_events;
	}
	else if (trigger.type == ENEMY_COLLISION)
	{
		events = &env->enemies[trigger.enemy].collision_events;
		nb = &env->enemies[trigger.enemy].nb_collision_events;
	}
	return (delete_selected_event4(env, trigger, events, nb));
}

int		delete_selected_event2(t_env *env, t_event_trigger trigger,
t_event **events, size_t *nb)
{
	if (trigger.type == SHOOT)
	{
		events = &env->sectors[trigger.sector].
		wall_sprites[trigger.wall].shoot_events[trigger.sprite];
		nb = &env->sectors[trigger.sector].wall_sprites[trigger.
		wall].nb_shoot_events[trigger.sprite];
	}
	else if (trigger.type == STAND)
	{
		events = &env->sectors[trigger.sector].stand_events;
		nb = &env->sectors[trigger.sector].nb_stand_events;
	}
	else if (trigger.type == WALK_IN)
	{
		events = &env->sectors[trigger.sector].walk_in_events;
		nb = &env->sectors[trigger.sector].nb_walk_in_events;
	}
	return (delete_selected_event3(env, trigger, events, nb));
}

int		delete_selected_event1(t_env *env, t_event_trigger trigger)
{
	t_event			**events;
	size_t			*nb;

	events = NULL;
	nb = 0;
	if (trigger.type == GLOBAL)
	{
		events = &env->global_events;
		nb = &env->nb_global_events;
	}
	else if (trigger.type == PRESS)
	{
		events = &env->sectors[trigger.sector].
		wall_sprites[trigger.wall].press_events[trigger.sprite];
		nb = &env->sectors[trigger.sector].wall_sprites[trigger.
		wall].nb_press_events[trigger.sprite];
	}
	return (delete_selected_event2(env, trigger, events, nb));
}

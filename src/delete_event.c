/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_event.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 15:42:32 by lnicosia          #+#    #+#             */
/*   Updated: 2020/02/21 14:59:29 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
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
	delete_selected_event4(env, trigger, events, nb);
	return (0);
}

int		delete_selected_event2(t_env *env, t_event_trigger trigger,
t_event **events, size_t *nb)
{
	if (trigger.type == SHOOT)
	{
		events = &env->sectors[trigger.sector].
		wall_sprites[trigger.wall].press_events[trigger.sprite];
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
	delete_selected_event3(env, trigger, events, nb);
	return (0);
}

int		delete_selected_event1(t_env *env, t_event_trigger trigger,
t_event **events, size_t *nb)
{
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
	delete_selected_event2(env, trigger, events, nb);
	return (0);
}

int		delete_selected_event(void *param)
{
	t_env			*env;
	t_event_trigger	trigger;
	t_event			**events;
	size_t			*nb;

	env = (t_env*)param;
	trigger = env->editor.event_panel.trigger;
	events = NULL;
	nb = 0;
	delete_selected_event1(env, trigger, events, nb);
	return (0);
}

int		delete_event(void *param)
{
	t_env	*env;

	env = (t_env*)param;
	if (modify_event(env))
		return (-1);
	env->editor.creating_event = 0;
	env->editor.selected_launch_condition = 0;
	env->editor.selected_exec_condition = 0;
	if (update_confirmation_box(&env->confirmation_box,
		"Delete this event?", YESNO, env))
		return (-1);
	env->editor.event_panel.selected_event = env->editor.selected_event;
	env->confirmation_box.yes_action = &delete_selected_event;
	env->confirmation_box.yes_target = env;
	return (0);
}

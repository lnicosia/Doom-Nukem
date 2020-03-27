/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_event.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 16:44:54 by lnicosia          #+#    #+#             */
/*   Updated: 2020/02/21 17:47:02 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "events_parser.h"

void	set_event(t_env *env, t_event *event)
{
	event->delay = env->editor.event_panel.action_panel.delay_value;
	if (event->type == INT)
	{
		event->goal = env->editor.event_panel.action_panel.int_value;
		event->start_incr = env->editor.event_panel.action_panel.int_value;
	}
	else if (event->type == DOUBLE)
	{
		event->goal = env->editor.event_panel.action_panel.double_value;
		event->start_incr = env->editor.event_panel.action_panel.double_value;
	}
	else if (event->type == UINT32)
	{
		event->goal = env->editor.event_panel.action_panel.uint32_value;
		event->start_incr = env->editor.event_panel.action_panel.uint32_value;
	}
}

int		save_event2(t_env *env, t_event_panel *panel)
{
	if (panel->trigger.type == STAND)
		env->sectors[panel->trigger.sector].
		stand_events[panel->selected_event] = panel->event;
	else if (panel->trigger.type == WALK_IN)
		env->sectors[panel->trigger.sector].
		walk_in_events[panel->selected_event] = panel->event;
	else if (panel->trigger.type == WALK_OUT)
		env->sectors[panel->trigger.sector].
		walk_out_events[panel->selected_event] = panel->event;
	else if (panel->trigger.type == DEATH)
		env->enemies[panel->trigger.enemy].
		death_events[panel->selected_event] = panel->event;
	else if (panel->trigger.type == ENEMY_COLLISION)
		env->enemies[panel->trigger.enemy].
		collision_events[panel->selected_event] = panel->event;
	else if (panel->trigger.type == OBJECT_COLLISION)
		env->objects[panel->trigger.object].
		collision_events[panel->selected_event] = panel->event;
	panel->selected_event = -1;
	return (0);
}

int		save_event(void *param)
{
	t_env			*env;
	t_event_panel	*panel;

	env = (t_env*)param;
	panel = &env->editor.event_panel;
	if (check_event_validity(env, panel->event))
		return (0);
	env->editor.creating_event = 0;
	env->editor.selecting_target = 0;
	set_event(env, &panel->event);
	if (panel->trigger.type == GLOBAL)
		env->global_events[panel->selected_event] = panel->event;
	else if (panel->trigger.type == PRESS)
		env->sectors[panel->trigger.sector].wall_sprites[panel->trigger.wall].
		press_events[panel->trigger.sprite][panel->selected_event] =
		panel->event;
	else if (panel->trigger.type == SHOOT)
		env->sectors[panel->trigger.sector].wall_sprites[panel->trigger.wall].
		shoot_events[panel->trigger.sprite][panel->selected_event] =
		panel->event;
	return (save_event2(env, panel));
}

int		create_event2(t_env *env)
{
	if (env->editor.event_panel.trigger.type == WALK_IN
		&& new_walk_in_event(env, env->editor.event_panel.trigger,
		env->editor.event_panel.event))
		return (-1);
	else if (env->editor.event_panel.trigger.type == WALK_OUT
		&& new_walk_out_event(env, env->editor.event_panel.trigger,
		env->editor.event_panel.event))
		return (-1);
	else if (env->editor.event_panel.trigger.type == DEATH
		&& new_death_event(env, env->editor.event_panel.trigger,
		env->editor.event_panel.event))
		return (-1);
	else if (env->editor.event_panel.trigger.type == ENEMY_COLLISION
		&& new_enemy_collision_event(env, env->editor.event_panel.trigger,
		env->editor.event_panel.event))
		return (-1);
	else if (env->editor.event_panel.trigger.type == OBJECT_COLLISION
		&& new_object_collision_event(env, env->editor.event_panel.trigger,
		env->editor.event_panel.event))
		return (-1);
	if (update_confirmation_box(&env->confirmation_box, "Event saved",
		CONFIRM, env))
		return (-1);
	env->editor.creating_event = 0;
	env->editor.selecting_target = 0;
	return (0);
}

int		create_event(void *param)
{
	t_env	*env;
	int		validity;

	env = (t_env*)param;
	validity = check_event_validity(env, env->editor.event_panel.event);
	if (validity == 1)
		return (0);
	else if (validity == -1)
		return (-1);
	set_event(env, &env->editor.event_panel.event);
	if (env->editor.event_panel.trigger.type == GLOBAL && new_global_event(env,
	  env->editor.event_panel.trigger, env->editor.event_panel.event))
		return (-1);
	else if (env->editor.event_panel.trigger.type == PRESS
		&& new_press_event(env, env->editor.event_panel.trigger,
		env->editor.event_panel.event))
		return (-1);
	else if (env->editor.event_panel.trigger.type == SHOOT
		&& new_shoot_event(env, env->editor.event_panel.trigger,
		env->editor.event_panel.event))
		return (-1);
	else if (env->editor.event_panel.trigger.type == STAND
		&& new_stand_event(env, env->editor.event_panel.trigger,
		env->editor.event_panel.event))
		return (-1);
	return (create_event2(env));
}

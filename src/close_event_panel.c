/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_event_panel.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/30 16:09:37 by lnicosia          #+#    #+#             */
/*   Updated: 2020/04/30 16:09:37 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

void	close_condition_panel(t_env *env)
{
	if (env->editor.creating_launch_condition)
		env->editor.event_panel.launch_conditions_tab.state = DOWN;
	else
		env->editor.event_panel.exec_conditions_tab.state = DOWN;
	env->editor.creating_condition = 0;
	env->editor.creating_launch_condition = 0;
	env->editor.creating_exec_condition = 0;
	env->editor.selecting_condition_target = 0;
	env->editor.selecting_event = 0;
}

t_event	*get_event2(t_env *env, t_event_panel *panel)
{
	if (panel->trigger.type == ENEMY_COLLISION)
		return (&env->enemies[panel->trigger.enemy].
		collision_events[panel->selected_event]);
	else if (panel->trigger.type == OBJECT_COLLISION)
		return (&env->objects[panel->trigger.object].
		collision_events[panel->selected_event]);
	return (0);
}

t_event	*get_event(t_env *env, t_event_panel *panel)
{
	if (panel->trigger.type == GLOBAL)
	{
		ft_printf("returning global event %d\n", panel->selected_event);
		return (&env->global_events[panel->selected_event]);
	}
	else if (panel->trigger.type == PRESS)
		return (&env->sectors[panel->trigger.sector].wall_sprites[panel->
		trigger.wall].press_events[panel->trigger.sprite]
		[panel->selected_event]);
	else if (panel->trigger.type == SHOOT)
		return (&env->sectors[panel->trigger.sector].wall_sprites[panel->
		trigger.wall].shoot_events[panel->trigger.sprite][panel->
		selected_event]);
	else if (panel->trigger.type == STAND)
		return (&env->sectors[panel->trigger.sector].
		stand_events[panel->selected_event]);
	else if (panel->trigger.type == WALK_IN)
		return (&env->sectors[panel->trigger.sector].
		walk_in_events[panel->selected_event]);
	else if (panel->trigger.type == WALK_OUT)
		return (&env->sectors[panel->trigger.sector].
		walk_out_events[panel->selected_event]);
	else if (panel->trigger.type == DEATH)
		return (&env->enemies[panel->trigger.enemy].
		death_events[panel->selected_event]);
	else
		return (get_event2(env, panel));
	return (0);
}

void	restore_conditions(t_env *env)
{
	t_event	*event;

	if (env->editor.launch_conditions_save)
	{
		event = get_event(env, &env->editor.event_panel);	
		ft_memdel((void**)&env->editor.event_panel.event.launch_conditions);
		event->launch_conditions = env->editor.launch_conditions_save;
		event->nb_launch_conditions = env->editor.nb_launch_conditions_save;
		env->editor.launch_conditions_save = NULL;
	}
	if (env->editor.exec_conditions_save)
	{
		event = get_event(env, &env->editor.event_panel);	
		ft_memdel((void**)&env->editor.event_panel.event.exec_conditions);
		event->exec_conditions = env->editor.exec_conditions_save;
		event->nb_exec_conditions = env->editor.nb_exec_conditions_save;
		env->editor.exec_conditions_save = NULL;
	}
}

int		close_event_panel(void *param)
{
	t_env	*env;

	env = (t_env*)param;
	env->editor.event_panel.target_tab.state = UP;
	env->editor.event_panel.action_tab.state = UP;
	env->editor.event_panel.launch_conditions_tab.state = UP;
	env->editor.event_panel.exec_conditions_tab.state = UP;
	if (env->editor.creating_condition)
	{
		close_condition_panel(env);
	}
	else
	{
		restore_conditions(env);
		env->editor.creating_event = 0;
		env->editor.selecting_target = 0;
		env->editor.event_panel.selected_event = -1;
	}
	return (0);
}

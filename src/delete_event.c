/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_event.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 15:42:32 by lnicosia          #+#    #+#             */
/*   Updated: 2020/02/18 14:22:34 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "events_parser.h"

void	delete_selected_event3(t_env *env, t_event_panel *panel,
t_event **events, size_t *nb)
{
	if (panel->trigger.type == WALK_IN)
	{
		events = &env->sectors[panel->trigger.sector].walk_in_events;
		nb = &env->sectors[panel->trigger.sector].nb_walk_in_events;
	}
	else if (panel->trigger.type == WALK_OUT)
	{
		events = &env->sectors[panel->trigger.sector].walk_out_events;
		nb = &env->sectors[panel->trigger.sector].nb_walk_out_events;
	}
	free_event(&(*events)[panel->selected_event]);
	*events = (t_event*)ft_delindex(*events, sizeof(t_event) * *nb,
	sizeof(t_event), sizeof(t_event) * panel->selected_event);
	(*nb)--;
	if (env->editor.selected_event == *nb)
		env->editor.selected_event--;
}

void	delete_selected_event2(t_env *env, t_event_panel *panel,
t_event **events, size_t *nb)
{
	if (panel->trigger.type == SHOOT)
	{
		events = &env->sectors[panel->trigger.sector].
		wall_sprites[panel->trigger.wall].press_events[panel->trigger.sprite];
		nb = &env->sectors[panel->trigger.sector].wall_sprites[panel->trigger.
		wall].nb_shoot_events[panel->trigger.sprite];
	}
	else if (panel->trigger.type == STAND)
	{
		events = &env->sectors[panel->trigger.sector].stand_events;
		nb = &env->sectors[panel->trigger.sector].nb_stand_events;
	}
	delete_selected_event3(env, panel, events, nb);
}

void	delete_selected_event(void *param)
{
	t_env			*env;
	t_event_panel	*panel;
	t_event			**events;
	size_t			*nb;

	env = (t_env*)param;
	panel = &env->editor.event_panel;
	events = NULL;
	nb = 0;
	if (panel->trigger.type == GLOBAL)
	{
		events = &env->global_events;
		nb = &env->nb_global_events;
	}
	else if (panel->trigger.type == PRESS)
	{
		events = &env->sectors[panel->trigger.sector].
		wall_sprites[panel->trigger.wall].press_events[panel->trigger.sprite];
		nb = &env->sectors[panel->trigger.sector].wall_sprites[panel->trigger.
		wall].nb_press_events[panel->trigger.sprite];
	}
	delete_selected_event2(env, panel, events, nb);
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

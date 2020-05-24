/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modify_event.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 10:26:41 by lnicosia          #+#    #+#             */
/*   Updated: 2020/03/10 10:01:34 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "events_parser.h"
#include "parser.h"
#include "events.h"

int		apply_modifications_to_event(t_env *env)
{
	set_modified_event(env, &env->editor.event_panel.event);
	env->editor.event_panel.ok.release_action = &save_event;
	set_action_type_buttons_state(env);
	return (0);
}

int		modify_event4(t_env *env, int sector)
{
	if (env->selected_wall_sprite_wall == -1
		&& (env->selected_floor != -1 || env->editor.selected_sector != -1))
	{
		if (env->editor.selected_events == 0)
		{
			env->editor.event_panel.event =
			env->sectors[sector].stand_events[env->editor.selected_event];
		}
		else if (env->editor.selected_events == 1)
		{
			env->editor.event_panel.event =
			env->sectors[sector].walk_in_events[env->editor.selected_event];
		}
		else if (env->editor.selected_events == 2)
		{
			env->editor.event_panel.event =
			env->sectors[sector].walk_out_events[env->editor.selected_event];
		}
	}
	else if (env->selected_floor == -1 && env->editor.selected_sector == -1)
		env->editor.event_panel.event =
		env->global_events[env->editor.selected_event];
	return (0);
}

int		modify_event3(t_env *env, int sector)
{
	if (env->selected_wall_sprite_wall != -1)
	{
		if (env->editor.selected_events == 0)
		{
			env->editor.event_panel.event =
			env->sectors[env->editor.selected_sector].
			wall_sprites[env->selected_wall_sprite_wall].
			press_events[env->selected_wall_sprite_sprite]
			[env->editor.selected_event];
		}
		else if (env->editor.selected_events == 1)
		{
			env->editor.event_panel.event =
			env->sectors[env->editor.selected_sector].
			wall_sprites[env->selected_wall_sprite_wall].
			shoot_events[env->selected_wall_sprite_sprite]
			[env->editor.selected_event];
		}
	}
	else
		modify_event4(env, sector);
	return (0);
}

int		modify_event2(t_env *env, int sector)
{
	if (env->selected_enemy != -1)
	{
		if (env->editor.selected_events == 0)
			env->editor.event_panel.event = env->enemies[env->selected_enemy].
			collision_events[env->editor.selected_event];
		else if (env->editor.selected_events == 1)
			env->editor.event_panel.event = env->enemies[env->selected_enemy].
			death_events[env->editor.selected_event];
	}
	else if (env->selected_object != -1)
		env->editor.event_panel.event = env->objects[env->selected_object].
		collision_events[env->editor.selected_event];
	else
		modify_event3(env, sector);
	return (0);
}

int		modify_event(void *param)
{
	t_env	*env;
	int		sector;

	env = (t_env*)param;
	target_tab_func(env);
	env->editor.creating_event = 1;
	env->editor.event_panel.target_tab.state = DOWN;
	reset_target_selection(&env->editor.event_panel.target_panel);
	env->editor.event_panel.selected_event = env->editor.selected_event;
	ft_bzero(&env->editor.event_panel.trigger,
	sizeof(env->editor.event_panel.trigger));
	set_trigger(env, &env->editor.event_panel.trigger);
	if (env->selected_floor != -1)
		sector = env->selected_floor;
	else
		sector = env->editor.selected_sector;
	modify_event2(env, sector);
	return (apply_modifications_to_event(env));
}

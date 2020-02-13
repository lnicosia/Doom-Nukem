/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_events_creation_buttons.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 11:22:47 by lnicosia          #+#    #+#             */
/*   Updated: 2020/02/13 15:12:49 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "events_parser.h"

int		new_event(void *param)
{
	t_env	*env;

	env = (t_env*)param;
	env->editor.creating_event = 1;
	ft_bzero(&env->editor.event_panel.event,
	sizeof(env->editor.event_panel.event));
	ft_bzero(&env->editor.event_panel.trigger,
	sizeof(env->editor.event_panel.trigger));
	if (env->selected_wall_sprite_wall != -1)
	{
		if (env->editor.selected_events == 0)
			env->editor.event_panel.trigger.index = PRESS;
		else if (env->editor.selected_events == 1)
			env->editor.event_panel.trigger.index = SHOOT;
		env->editor.event_panel.trigger.sector = env->editor.selected_sector;
		env->editor.event_panel.trigger.wall = env->selected_wall_sprite_wall;
		env->editor.event_panel.trigger.sprite =
		env->selected_wall_sprite_sprite;
	}
	else if (env->selected_wall_sprite_wall == -1
		&& (env->selected_floor != -1 || env->editor.selected_sector != -1))
	{
		if (env->editor.selected_events == 0)
			env->editor.event_panel.trigger.index = STAND;
		else if (env->editor.selected_events == 1)
			env->editor.event_panel.trigger.index = WALK_IN;
		else if (env->editor.selected_events == 2)
			env->editor.event_panel.trigger.index = WALK_OUT;
		if (env->selected_floor != -1)
			env->editor.event_panel.trigger.sector = env->selected_floor;
		else if (env->editor.selected_sector != -1)
			env->editor.event_panel.trigger.sector =
			env->editor.selected_sector;
	}
	else if (env->selected_floor == -1 && env->editor.selected_sector == -1)
		env->editor.event_panel.trigger.index = GLOBAL;
	env->editor.event_panel.ok.release_action = &create_event;
	return (0);
}

void	set_modified_event(t_env *env, t_event *event)
{
	env->editor.event_panel.action_panel.delay_value = event->delay;
	if (event->type == INT)
	{
		if (event->mod_type == FIXED)
			env->editor.event_panel.action_panel.int_value = event->goal;
		else if (event->mod_type == INCR)
			env->editor.event_panel.action_panel.int_value = event->start_incr;
	}
	else if (event->type == DOUBLE)
	{
		if (event->mod_type == FIXED)
			env->editor.event_panel.action_panel.double_value = event->goal;
		else if (event->mod_type == INCR)
			env->editor.event_panel.action_panel.double_value =
			event->start_incr;
	}
	else if (event->type == UINT32)
	{
		if (event->mod_type == FIXED)
			env->editor.event_panel.action_panel.uint32_value = event->goal;
		else if (event->mod_type == INCR)
			env->editor.event_panel.action_panel.uint32_value =
			event->start_incr;
	}
}

int		modify_event(void *param)
{
	t_env	*env;
	int		sector;

	env = (t_env*)param;
	env->editor.creating_event = 1;
	env->editor.event_panel.selected_event = env->editor.selected_event;
	if (env->selected_floor != -1)
		sector = env->selected_floor;
	else
		sector = env->editor.selected_sector;
	ft_bzero(&env->editor.event_panel.trigger,
	sizeof(env->editor.event_panel.trigger));
	if (env->selected_wall_sprite_wall != -1)
	{
		if (env->editor.selected_events == 0)
		{
			env->editor.event_panel.trigger.index = PRESS;
			env->editor.event_panel.event =
			env->sectors[env->editor.selected_sector].
			wall_sprites[env->selected_wall_sprite_wall].
			press_events[env->selected_wall_sprite_sprite]
			[env->editor.selected_event];
		}
		else if (env->editor.selected_events == 1)
		{
			env->editor.event_panel.trigger.index = SHOOT;
			env->editor.event_panel.event =
			env->sectors[env->editor.selected_sector].
			wall_sprites[env->selected_wall_sprite_wall].
			shoot_events[env->selected_wall_sprite_sprite]
			[env->editor.selected_event];
		}
		env->editor.event_panel.trigger.sector = env->editor.selected_sector;
		env->editor.event_panel.trigger.wall = env->selected_wall_sprite_wall;
		env->editor.event_panel.trigger.sprite =
		env->selected_wall_sprite_sprite;
	}
	else if (env->selected_wall_sprite_wall == -1
		&& (env->selected_floor != -1 || env->editor.selected_sector != -1))
	{
		if (env->editor.selected_events == 0)
		{
			env->editor.event_panel.trigger.index = STAND;
			env->editor.event_panel.event =
			env->sectors[sector].stand_events[env->editor.selected_event];
		}
		else if (env->editor.selected_events == 1)
		{
			env->editor.event_panel.trigger.index = WALK_IN;
			env->editor.event_panel.event =
			env->sectors[sector].walk_in_events[env->editor.selected_event];
		}
		else if (env->editor.selected_events == 2)
		{
			env->editor.event_panel.trigger.index = WALK_OUT;
			env->editor.event_panel.event =
			env->sectors[sector].walk_out_events[env->editor.selected_event];
		}
		env->editor.event_panel.trigger.sector = sector;
	}
	else if (env->selected_floor == -1 && env->editor.selected_sector == -1)
	{
		env->editor.event_panel.trigger.index = GLOBAL;
	}
	set_modified_event(env, &env->editor.event_panel.event);
	env->editor.event_panel.ok.release_action = &save_event;
	return (0);
}

void	init_events_creation_buttons(t_env *env)
{
	env->editor.new_event = new_dark_panel_button(ON_RELEASE,
	&new_event, env, env);
	env->editor.new_event.pos = new_point(60, env->h - 100);
	env->editor.new_event.size_up.x = 120;
	env->editor.new_event.size_down = env->editor.new_event.size_up;
	env->editor.new_event.size_pressed = env->editor.new_event.size_up;
	env->editor.new_event.size_hover = env->editor.new_event.size_up;
	env->editor.modify_event = new_dark_panel_button(ON_RELEASE,
	&modify_event, env, env);
	env->editor.modify_event.pos = new_point(220, env->h - 100);
	env->editor.modify_event.size_up = env->editor.new_event.size_up;
	env->editor.modify_event.size_down = env->editor.new_event.size_up;
	env->editor.modify_event.size_pressed = env->editor.new_event.size_up;
	env->editor.modify_event.size_hover = env->editor.new_event.size_up;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_events_creation_buttons.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 11:22:47 by lnicosia          #+#    #+#             */
/*   Updated: 2020/02/18 15:11:40 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "events_parser.h"

void	set_trigger(t_env *env, t_event_trigger *trigger)
{
	if (env->selected_wall_sprite_wall != -1)
	{
		if (env->editor.selected_events == 0)
			trigger->type = PRESS;
		else if (env->editor.selected_events == 1)
			trigger->type = SHOOT;
		trigger->sector = env->editor.selected_sector;
		trigger->wall = env->selected_wall_sprite_wall;
		trigger->sprite = env->selected_wall_sprite_sprite;
	}
	else if (env->selected_wall_sprite_wall == -1
		&& (env->selected_floor != -1 || env->editor.selected_sector != -1))
	{
		if (env->editor.selected_events == 0)
			trigger->type = STAND;
		else if (env->editor.selected_events == 1)
			trigger->type = WALK_IN;
		else if (env->editor.selected_events == 2)
			trigger->type = WALK_OUT;
		if (env->selected_floor != -1)
			trigger->sector = env->selected_floor;
		else if (env->editor.selected_sector != -1)
			trigger->sector = env->editor.selected_sector;
	}
	else if (env->selected_floor == -1 && env->editor.selected_sector == -1)
		trigger->type = GLOBAL;
	trigger->index = env->editor.selected_event;
}

/*
**	Select an event when clicking on "Select me"
*/

int		select_event(void *param)
{
	t_env			*env;

	env = (t_env*)param;
	env->editor.condition_panel.condition.source_trigger =
	env->editor.event_panel.trigger;
	set_trigger(env, &env->editor.condition_panel.condition.target_trigger);
	env->editor.condition_panel.condition.target =
	get_event_array(env, env->editor.condition_panel.condition.target_trigger);
	return (0);
}

int		new_event(void *param)
{
	t_env	*env;

	env = (t_env*)param;
	env->editor.creating_event = 1;
	ft_bzero(&env->editor.event_panel.event,
	sizeof(env->editor.event_panel.event));
	ft_bzero(&env->editor.event_panel.trigger,
	sizeof(env->editor.event_panel.trigger));
	set_trigger(env, &env->editor.event_panel.trigger);
	env->editor.event_panel.ok.release_action = &create_event;
	return (0);
}

void	init_events_creation_buttons(t_env *env)
{
	env->editor.new_event = new_dark_panel_button(ON_RELEASE,
	&new_event, env, env);
	env->editor.new_event.pos = new_point(140, env->h - 175);
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
	env->editor.delete_event = new_dark_panel_button(ON_RELEASE,
	&delete_event, env, env);
	env->editor.delete_event.pos = new_point(60, env->h - 100);
	env->editor.delete_event.size_up = env->editor.new_event.size_up;
	env->editor.delete_event.size_down = env->editor.new_event.size_up;
	env->editor.delete_event.size_pressed = env->editor.new_event.size_up;
	env->editor.delete_event.size_hover = env->editor.new_event.size_up;
	env->editor.select_event = new_dark_panel_button(ON_RELEASE,
	&select_event, env, env);
	env->editor.select_event.pos = new_point(140, env->h - 250);
	env->editor.select_event.size_up = env->editor.new_event.size_up;
	env->editor.select_event.size_down = env->editor.new_event.size_up;
	env->editor.select_event.size_pressed = env->editor.new_event.size_up;
	env->editor.select_event.size_hover = env->editor.new_event.size_up;
}

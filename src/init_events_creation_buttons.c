/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_events_creation_buttons.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 11:22:47 by lnicosia          #+#    #+#             */
/*   Updated: 2020/02/21 18:05:54 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "events_parser.h"

void	set_trigger(t_env *env, t_event_trigger *trigger)
{
	int		sector;

	sector = -1;
	if (env->selected_enemy != -1)
	{
		if (env->editor.selected_events == 0)
			trigger->type = ENEMY_COLLISION;
		else if (env->editor.selected_events == 1)
			trigger->type = DEATH;
		trigger->enemy = env->selected_enemy;
	}
	else if (env->selected_object != -1)
	{
		trigger->type = OBJECT_COLLISION;
		trigger->object = env->selected_object;
	}
	else if (env->selected_wall_sprite_wall != -1)
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
		if (env->selected_floor != -1)
			sector = env->selected_floor;
		else if (env->editor.selected_sector != -1)
			sector = env->editor.selected_sector;
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
	env->editor.selecting_event = 0;
	env->editor.event_panel.target_tab.state = UP;
	env->editor.event_panel.action_tab.state = DOWN;
	if (update_confirmation_box(&env->confirmation_box,
		"Event selected", CONFIRM, env))
		return (-1);
	return (0);
}

void	reset_target_selection(t_target_panel *panel)
{
	panel->sector_type = 0;
	panel->wall_type = 0;
	panel->wall_sprite_type = 0;
	panel->weapon_type = 0;
	panel->object_type = 0;
	panel->vertex_type = 0;
	panel->enemy_type = 0;
	panel->floor_type = 0;
	panel->ceiling_type = 0;
	panel->player_type = 0;
	panel->other_type = 0;
	panel->sector_other_type = 0;
	panel->target_selection_phase = 0;
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
	env->editor.event_panel.target_tab.state = DOWN;
	env->editor.event_panel.action_tab.state = UP;
	env->editor.event_panel.launch_conditions_tab.state = UP;
	env->editor.event_panel.exec_conditions_tab.state = UP;
	env->editor.event_panel.action_panel.go_to.state = DOWN;
	env->editor.event_panel.action_panel.add.state = UP;
	env->editor.event_panel.action_panel.delay_value = 0;
	env->editor.event_panel.action_panel.uint32_value = 0;
	env->editor.event_panel.action_panel.double_value = 0;
	env->editor.event_panel.action_panel.int_value = 0;
	env->editor.event_panel.selected_event = -1;
	env->editor.event_panel.event.target_index = -1;
	reset_target_selection(&env->editor.event_panel.target_panel);
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

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_trigger.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/01 10:46:31 by lnicosia          #+#    #+#             */
/*   Updated: 2020/05/01 10:46:32 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "events_parser.h"

void	set_trigger2(t_env *env, t_event_trigger *trigger)
{
	if (env->selected_wall_sprite_wall == -1
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

void	set_trigger(t_env *env, t_event_trigger *trigger)
{
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
	else
		set_trigger2(env, trigger);
}

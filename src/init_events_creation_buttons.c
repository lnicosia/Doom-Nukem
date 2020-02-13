/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_events_creation_buttons.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 11:22:47 by lnicosia          #+#    #+#             */
/*   Updated: 2020/02/13 13:21:42 by lnicosia         ###   ########.fr       */
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
			env->editor.event_panel.trigger.sector = env->editor.selected_sector;
	}
	else if (env->selected_floor == -1 && env->editor.selected_sector == -1)
		env->editor.event_panel.trigger.index = GLOBAL;
	return (0);
}

void	init_events_creation_buttons(t_env *env)
{
	env->editor.new_event = new_dark_panel_button(ON_RELEASE,
	&new_event, env, env);
	env->editor.new_event.pos = new_point(50, env->h - 100);
	env->editor.modify_event = new_dark_panel_button(ON_RELEASE,
	&new_event, env, env);
	env->editor.modify_event.pos = new_point(150, env->h - 100);
}

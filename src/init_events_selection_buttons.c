/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_events_selection_buttons.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 17:25:57 by lnicosia          #+#    #+#             */
/*   Updated: 2020/01/28 15:49:15 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

void	next_events(void *penv)
{
	t_env	*env;

	env = (t_env *)penv;
	if (env->selected_wall_sprite_wall != -1)
	{
		env->editor.selected_events = env->editor.selected_events >= 1 ? 0 : 1;
	}
	else if (env->selected_floor != -1 || env->editor.selected_sector != -1)
	{
		env->editor.selected_events++;
		if (env->editor.selected_events == 3)
			env->editor.selected_events = 0;
	}
	env->editor.selected_event = 0;
}

void	prec_events(void *penv)
{
	t_env	*env;

	env = (t_env *)penv;
	if (env->selected_wall_sprite_wall != -1)
	{
		env->editor.selected_events = env->editor.selected_events >= 1 ? 0 : 1;
	}
	else if (env->selected_floor != -1 || env->editor.selected_sector != -1)
	{
		env->editor.selected_events--;
		if (env->editor.selected_events < 0)
			env->editor.selected_events = 2;
	}
	env->editor.selected_event = 0;
}

void	next_event(void *penv)
{
	t_env	*env;

	env = (t_env *)penv;
	env->editor.selected_event++;
	if (env->selected_wall_sprite_wall != -1)
	{
		if ((env->editor.selected_events == 0
					&& env->editor.selected_event >= env->sectors[env->
					editor.selected_sector].wall_sprites[env->selected_wall_sprite_wall]
					.nb_press_events[env->selected_wall_sprite_sprite])
				|| (env->editor.selected_events == 1
					&& env->editor.selected_event >= env->sectors[env->
					editor.selected_sector].wall_sprites[env->selected_wall_sprite_wall]
					.nb_shoot_events[env->selected_wall_sprite_sprite]))
			env->editor.selected_event = 0;
	}
	else if (env->selected_floor != -1 || env->editor.selected_sector != -1)
	{
		if ((env->editor.selected_events == 0
					&& env->editor.selected_event >= env->sectors[env->
					editor.selected_sector].nb_stand_events)
				|| (env->editor.selected_events == 1
					&& env->editor.selected_event >= env->sectors[env->
					editor.selected_sector].nb_walk_in_events)
				|| (env->editor.selected_events == 2
					&& env->editor.selected_event >= env->sectors[env->
					editor.selected_sector].nb_walk_out_events))
			env->editor.selected_event = 0;
	}
	else if (env->selected_floor == -1 && env->editor.selected_sector == -1
			&& env->editor.selected_event >= env->nb_global_events)
		env->editor.selected_event = 0;
}

void	previous_event(void *penv)
{
	t_env	*env;

	env = (t_env *)penv;
	if (env->editor.selected_event > 0)
		env->editor.selected_event--;
	else
	{
		if (env->selected_wall_sprite_wall != -1)
		{
			if (env->editor.selected_events == 0)
				env->editor.selected_event = env->sectors[env->
					editor.selected_sector].wall_sprites[env->
					selected_wall_sprite_wall].nb_press_events[env->
					selected_wall_sprite_sprite] - 1;
			else if (env->editor.selected_events == 1)
				env->editor.selected_event = env->sectors[env->
					editor.selected_sector].wall_sprites[env->
					selected_wall_sprite_wall].nb_shoot_events[env->
					selected_wall_sprite_sprite] - 1;
		}
		else if (env->selected_floor != -1 || env->editor.selected_sector != -1)
		{
			if (env->editor.selected_events == 0)
				env->editor.selected_event = env->sectors[env->
					editor.selected_sector].nb_stand_events - 1;
			else if (env->editor.selected_events == 1)
				env->editor.selected_event = env->sectors[env->
					editor.selected_sector].nb_walk_in_events - 1;
			else if (env->editor.selected_events == 2)
				env->editor.selected_event = env->sectors[env->
					editor.selected_sector].nb_walk_out_events - 1;
		}
		else if (env->selected_floor == -1 && env->editor.selected_sector == -1)
			env->editor.selected_event = env->nb_global_events - 1;
	}
}

void	init_events_selection_buttons(t_env *env)
{
	env->editor.next_events = new_next_button(ON_RELEASE,
			next_events, env, env);
	env->editor.next_events.pos = new_point(300, 470);
	env->editor.previous_events = new_previous_button(ON_RELEASE,
			prec_events, env, env);
	env->editor.previous_events.pos = new_point(90, 470);

	env->editor.next_event = new_next_button(ON_RELEASE,
			next_event, env, env);
	env->editor.next_event.pos = new_point(300, 500);
	env->editor.previous_event = new_previous_button(ON_RELEASE,
			previous_event, env, env);
	env->editor.previous_event.pos = new_point(90, 500);
}

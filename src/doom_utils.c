/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doom_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/29 16:06:53 by lnicosia          #+#    #+#             */
/*   Updated: 2020/05/15 22:20:21 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "events.h"
#include "collision.h"
#include "draw.h"

int		launch_events3bis(t_env *env)
{
	if (env->player.old_sector != -1
			&& env->sectors[env->player.old_sector].nb_walk_out_events > 0)
	{
		if (start_event(&env->sectors[env->player.old_sector].
			walk_out_events, &env->sectors[env->player.old_sector].
			nb_walk_out_events, env))
			return (-1);
	}
	env->player.changed_sector = 0;
	env->player.old_sector = -1;
	return (0);
}

int		launch_events3(t_env *env)
{
	if (env->sectors[env->player.sector].gravity == 0)
	{
		reset_state(env);
		env->player.state.fly = 1;
	}
	else
	{
		env->player.state.fly = 0;
		init_fall(env);
	}
	if (env->player.sector != -1 && env->sectors[env->player.sector]
		.nb_walk_in_events > 0)
	{
		if (start_event(&env->sectors[env->player.sector].walk_in_events,
		&env->sectors[env->player.sector].nb_walk_in_events, env))
			return (-1);
	}
	return (launch_events3bis(env));
}

int		launch_events2(t_env *env)
{
	if (env->floor_bullet_holes_events
			&& env->nb_floor_bullet_holes_events)
	{
		if (start_event(&env->floor_bullet_holes_events,
					&env->nb_floor_bullet_holes_events, env))
			return (-1);
	}
	if (env->ceiling_bullet_holes_events
			&& env->nb_ceiling_bullet_holes_events)
	{
		if (start_event(&env->ceiling_bullet_holes_events,
					&env->nb_ceiling_bullet_holes_events, env))
			return (-1);
	}
	if (env->player.changed_sector)
	{
		if (launch_events3(env))
			return (-1);
	}
	return (0);
}

int		launch_events(t_env *env)
{
	if (env->player.sector != -1
			&& env->sectors[env->player.sector].stand_events
			&& env->sectors[env->player.sector].nb_stand_events
			&& !env->player.state.jump)
	{
		if (start_event(&env->sectors[env->player.sector].stand_events,
					&env->sectors[env->player.sector].nb_stand_events, env))
			return (-1);
	}
	if (env->global_events && env->nb_global_events)
	{
		if (start_event(&env->global_events,
					&env->nb_global_events, env))
			return (-1);
	}
	if (env->wall_bullet_holes_events && env->nb_wall_bullet_holes_events
			&& env->wall_bullet_holes_events)
	{
		if (start_event(&env->wall_bullet_holes_events,
					&env->nb_wall_bullet_holes_events, env))
			return (-1);
	}
	return (launch_events2(env));
}

int		first_frame(t_env *env)
{
	reset_clipped(env);
	clear_image(env);
	while (SDL_PollEvent(&env->sdl.event))
	{
	}
	if (draw_game(env))
		return (-1);
	return (0);
}

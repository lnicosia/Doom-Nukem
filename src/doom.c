/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipatry <sipatry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 17:39:16 by sipatry           #+#    #+#             */
/*   Updated: 2020/01/07 17:27:01 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "collision.h"

int		launch_global_events(t_env *env)
{
	if (env->player.sector != -1
		&& env->sectors[env->player.sector].stand_on_me_event
		&& env->sectors[env->player.sector].nb_stand_events)
	{
		if (start_event(&env->sectors[env->player.sector].stand_on_me_event,
				&env->sectors[env->player.sector].nb_stand_events, env))
			return (-1);
	}
	if (env->global_events && env->nb_global_events && env->global_events)
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
	if (env->floor_bullet_holes_events && env->floor_bullet_holes_events
			&& env->nb_floor_bullet_holes_events)
	{
		if (start_event(&env->floor_bullet_holes_events,
				&env->nb_floor_bullet_holes_events, env))
			return (-1);
	}
	if (env->ceiling_bullet_holes_events && env->ceiling_bullet_holes_events
			&& env->nb_ceiling_bullet_holes_events)
	{
		if (start_event(&env->ceiling_bullet_holes_events,
				&env->nb_ceiling_bullet_holes_events, env))
			return (-1);
	}
	return (0);
}

int		doom(t_env *env)
{
	while (env->running)
	{
		env->player.health = 100;
		Mix_VolumeMusic(MIX_MAX_VOLUME/env->sound.g_music);
		reset_clipped(env);
		clear_image(env);
		SDL_GetRelativeMouseState(&env->sdl.mouse_x, &env->sdl.mouse_y);
		SDL_GetMouseState(&env->sdl.mx, &env->sdl.my);
		if (env->first_frame)
		{
			while (SDL_PollEvent(&env->sdl.event))
			{
				if (env->sdl.event.type == SDL_QUIT || (env->sdl.event.type == SDL_KEYUP && env->sdl.event.key.keysym.sym == SDLK_ESCAPE))
					env->running = 0;
				else if (env->sdl.event.type == SDL_KEYDOWN
						|| env->sdl.event.type == SDL_KEYUP || env->sdl.event.type == SDL_MOUSEBUTTONDOWN
						|| env->sdl.event.type == SDL_MOUSEBUTTONUP || env->sdl.event.type == SDL_MOUSEWHEEL)
					update_inputs(env);
				if (env->sdl.event.type == SDL_KEYUP || env->sdl.event.type == SDL_MOUSEBUTTONUP)
					keyup(env);
				if (env->sdl.event.type == SDL_MOUSEWHEEL && !env->weapon_change.on_going && !env->shot.on_going && env->player.health > 0)
					weapon_change(env);
			}
			update_sprites_state(env);
			if (env->player.health > 0)
			{
				enemy_ai(env);
				objects_collision(env);
				enemy_melee_hit(env);
				keys(env);
			}
			if (launch_global_events(env))
				return (-1);
			if (projectiles_movement(env))
				return (-1);
			if (env->player.health <= 0)
				death(env);
			if (env->confirmation_box.state)
				confirmation_box_keys(&env->confirmation_box, env);
			if (env->events)
			{
				if (pop_events2(env))
					return (-1);
			}
		}
		if (env->menu_start)
			start_game_menu(env);
		else
		{
			if (env->option)
			{
				if (open_options(env))
					return (crash("Could not process options pannel\n", env));
			}
			else if (draw_game(env))
				return (ft_printf("Crash in game loop\n"));
		}
	}
	free_all(env);
	return (0);
}

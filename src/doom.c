/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaerhard <gaerhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 17:39:16 by sipatry           #+#    #+#             */
/*   Updated: 2020/02/13 12:37:03 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "collision.h"

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
	if (env->player.changed_sector)
	{
		if (env->sectors[env->player.sector].gravity == 0)
			env->player.state.fly = 1;
		else
			env->player.state.fly = 0;
		if (env->player.sector != -1 && env->sectors[env->player.sector]
			.nb_walk_in_events > 0)
			start_event(&env->sectors[env->player.sector].walk_in_events,
			&env->sectors[env->player.sector].nb_walk_in_events, env);
		if (env->player.old_sector != -1
				&& env->sectors[env->player.old_sector].nb_walk_out_events > 0)
			start_event(&env->sectors[env->player.old_sector].walk_out_events,
				&env->sectors[env->player.old_sector].nb_walk_out_events, env);
		env->player.changed_sector = 0;
		env->player.old_sector = -1;
	}
	return (0);
}

int		doom(t_env *env)
{
	while (env->running)
	{
		//env->player.health = 100;
		reset_clipped(env);
		clear_image(env);
		SDL_GetRelativeMouseState(&env->sdl.mouse_x, &env->sdl.mouse_y);
		SDL_GetMouseState(&env->sdl.mx, &env->sdl.my);
		if (env->in_game && !env->menu & !env->option)
		{
			while (SDL_PollEvent(&env->sdl.event))
			{
				if (env->sdl.event.type == SDL_QUIT
					|| (env->sdl.event.type == SDL_KEYUP
					&& env->sdl.event.key.keysym.sym == SDLK_ESCAPE))
					env->running = 0;
				else if (env->sdl.event.type == SDL_KEYDOWN
						|| env->sdl.event.type == SDL_KEYUP
						|| env->sdl.event.type == SDL_MOUSEBUTTONDOWN
						|| env->sdl.event.type == SDL_MOUSEBUTTONUP
						|| env->sdl.event.type == SDL_MOUSEWHEEL)
					update_inputs(env);
				if (env->sdl.event.type == SDL_KEYUP
					|| env->sdl.event.type == SDL_MOUSEBUTTONUP)
				{
					if (keyup(env))
						return (-1);
				}
				if (env->sdl.event.type == SDL_MOUSEWHEEL
					&& !env->weapon_change.on_going &&
					!env->shot.on_going && env->player.health > 0)
					weapon_change(env);
			}
			update_sprites_state(env);
			if (projectiles_movement(env))
				return (-1);
			if (env->player.health > 0)
			{
				enemy_ai(env);
				objects_collision(env, env->player.pos);
				explosion_collision_objects(env);
				explosion_collision_enemies(env);
				explosion_collision_player(env);
				enemy_melee_hit(env);
				player_combat_state(env);
				if (keys(env))
					return (-1);
			}
			if (env->events)
			{
				if (pop_events(env))
					return (-1);
			}
			if (launch_events(env))
				return (-1);
			if (env->player.health <= 0)
				death(env);
			if (env->confirmation_box.state)
			{
				if (confirmation_box_keys(&env->confirmation_box, env))
					return (-1);
			}
		}
		if (env->menu && !env->in_game && !env->option)
			start_game_menu(env);
		else
		{
			if (env->option)
			{
				option_menu(env);
				/*if (open_options(env))
					return (crash("Could not process options pannel\n", env));*/
			}
			else if (draw_game(env))
				return (ft_printf("Crash in game loop\n"));
		}
		FMOD_System_Update(env->sound.system);
	}
	free_all(env);
	return (0);
}

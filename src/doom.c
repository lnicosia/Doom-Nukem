/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipatry <sipatry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 17:39:16 by sipatry           #+#    #+#             */
/*   Updated: 2019/11/15 15:30:19 by sipatry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "collision.h"

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
		if (env->player.sector != -1)
				start_event(env->sectors[env->player.sector].walk_on_me_event,
				env->sectors[env->player.sector].nb_walk_events, env);
		if (env->global_events)
				start_event(env->global_events, env->nb_global_events, env);
		projectiles_movement(env);
		if (env->player.health <= 0)
			death(env);
		if (env->confirmation_box.state)
			confirmation_box_keys(&env->confirmation_box, env);
		if (env->events)
				pop_events2(env);
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

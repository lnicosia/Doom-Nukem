/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipatry <sipatry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 17:39:16 by sipatry           #+#    #+#             */
/*   Updated: 2020/03/11 19:13:27 by sipatry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "collision.h"

int		doom4(t_env *env)
{
	if (env->menu && !env->in_game && !env->option)
		start_game_menu(env);
	else
	{
		if (env->option)
		{
			option_menu_ig(env);
		}
		else if (draw_game(env))
			return (ft_printf("Crash in game loop\n"));
	}
	return (0);
}
int		doom3(t_env *env)
{
	if (env->player.health <= 0)
		death(env);
	if (env->confirmation_box.state)
	{
		if (confirmation_box_keys(&env->confirmation_box, env))
			return (crash("Crash from a confirmation box\n", env));
	}
	return (0);
}

int		doom2(t_env *env)
{
	update_sprites_state(env);
	if (projectiles_movement(env))
		return (crash("Projectile creation or impact creation failed\n",
		env));
	if (!env->confirmation_box.state)
	{
		enemy_ai(env);
		objects_collision(env, env->player.pos);
		explosion_collision_objects(env);
		explosion_collision_enemies(env);
		explosion_collision_player(env);
		if (enemy_melee_hit(env))
			return (crash("Collision with a melee enemy failed\n",
			env));
		player_combat_state(env);
		if (keys(env))
			return (crash("Keys failed\n", env));
	}
	if (env->events)
	{
		if (pop_events(env))
			return (crash("Events failed\n", env));
	}
	if (launch_events(env))
		return (crash("Events Failed\n", env));
	return (0);
}

int		doom1(t_env *env)
{
	while (SDL_PollEvent(&env->sdl.event))
	{
		if (env->sdl.event.type == SDL_QUIT || (env->sdl.event.type == SDL_KEYUP
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
				return (crash("Keyup failed\n", env));
		}
		if (env->sdl.event.type == SDL_MOUSEWHEEL && !env->weapon_change.
		  	on_going && !env->shot.on_going && env->player.health > 0)
		{
			env->player.next_weapon = next_possessed_weapon(env);
			if (env->player.next_weapon >= 0)
				weapon_change(env);
		}
	}
	return (0);
}

int		doom(t_env *env)
{
	if (env->in_game && !env->menu && !env->option && first_frame(env))
		return (crash("First frame failed\n", env));
	while (env->running)
	{
		reset_clipped(env);
		clear_image(env);
		SDL_GetRelativeMouseState(&env->sdl.mouse_x, &env->sdl.mouse_y);
		SDL_GetMouseState(&env->sdl.mx, &env->sdl.my);
		if (env->in_game && !env->menu & !env->option)
		{
	  		if (doom1(env))
		  		return (-1);
	  		if (doom2(env))
		  		return (-1);
	  		if (doom3(env))
		  		return (-1);
		}
		if (doom4(env))
		  	return (-1);
		FMOD_System_Update(env->sound.system);
	}
	free_all(env);
	return (0);
}

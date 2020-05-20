/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 17:39:16 by sipatry           #+#    #+#             */
/*   Updated: 2020/04/29 16:05:15 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "free.h"
#include "collision.h"
#include "events.h"
#include "enemies.h"
#include "draw.h"

int		doom4(t_env *env)
{
	if (env->menu && !env->in_game && !env->option)
	{
		if (start_game_menu(env))
			return (custom_error("Start game menu error"));
	}
	else
	{
		if (env->option)
		{
			if (option_menu_ig(env))
				return (custom_error("Option menu in game error"));
		}
		else if (draw_game(env))
			return (custom_error("Crash in game loop\n"));
	}
	return (0);
}

int		doom3(t_env *env)
{
	if (env->player.health <= 0)
	{
		if (death(env))
			return (custom_error("Crash from death\n"));
	}
	if (env->confirmation_box.state)
	{
		if (confirmation_box_keys(&env->confirmation_box, env))
			return (custom_error("Crash from a confirmation box\n"));
	}
	return (0);
}

int		doom_events(t_env *env)
{
	if (env->events)
	{
		if (pop_events(env))
			return (custom_error("Events failed\n"));
	}
	if (launch_events(env))
		return (custom_error("Events Failed\n"));
	return (0);
}

int		doom2(t_env *env)
{
	update_sprites_state(env);
	if (projectiles_movement(env))
		return (custom_error("Projectile creation or impact creation"
		" failed\n"));
	if (!env->confirmation_box.state)
	{
		if (enemy_ai(env))
			return (custom_error("Enemy ai error"));
		objects_collision(env, env->player.pos);
		if (explosion_collision_objects(env))
			return (custom_error("Explosion collision objects error"));
		if (explosion_collision_enemies(env))
			return (custom_error("Explosion collision enmies error"));
		if (explosion_collision_player(env))
			return (custom_error("Explosion collision player error"));
		if (enemy_melee_hit(env))
			return (custom_error("Collision with a melee enemy failed\n"));
		if (player_combat_state(env))
			return (custom_error("Updating player combat state failed\n"));
		if (keys(env))
			return (custom_error("Keys failed\n"));
	}
	if (doom_events(env))
		return (custom_error("", env));
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
			if (doom_poll_event(env))
				return (crash("Doom events failed", env));
			if (doom2(env))
				return (crash("Doom part 2 failed", env));
			if (doom3(env))
				return (crash("Doom part 3 failed", env));
		}
		if (doom4(env))
			return (crash("Doom part 4 failed", env));
		if (FMOD_System_Update(env->sound.system))
			return (custom_error("FMOD_System_Update error\n"));
	}
	free_all(env);
	return (0);
}

/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   doom.c											 :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: gaerhard <gaerhard@student.42.fr>		  +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2019/04/03 15:26:12 by lnicosia		  #+#	#+#			 */
/*   Updated: 2019/10/17 14:25:22 by gaerhard		 ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "env.h"
#include "collision.h"

int		doom(t_env *env)
{
	/*init_animations(env);
	init_weapons(env);
	env->player.speed = 0.5;
	env->player.size_2d = 0.5;
	ft_printf("Starting music..\n");
	Mix_PlayMusic(env->sound.background, -1);
	//ft_printf("launching game loop..\n");
	env->flag = 0;
	env->player.fall = 1;*/
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
			enemy_collision(env);
			keys(env);
		}
		projectiles_movement(env);
		if (env->player.health <= 0)
			death(env);
		if (env->confirmation_box.state)
			confirmation_box_keys(&env->confirmation_box, env);
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
	ft_printf("User quit the game\n");
	free_all(env);
	return (0);
}

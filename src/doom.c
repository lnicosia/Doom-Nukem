/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaerhard <gaerhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 15:26:12 by lnicosia          #+#    #+#             */
/*   Updated: 2019/09/06 15:34:59 by gaerhard         ###   ########.fr       */
/*                                                                            */
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
		//ft_printf("l29\n");
		Mix_VolumeMusic(MIX_MAX_VOLUME/env->sound.g_music);
		//ft_printf("l31\n");
		reset_clipped(env);
		//ft_printf("l33\n");
		clear_image(env);
		//ft_printf("l35\n");
		SDL_GetRelativeMouseState(&env->sdl.mouse_x, &env->sdl.mouse_y);
		//ft_printf("l37\n");
		SDL_GetMouseState(&env->sdl.mx, &env->sdl.my);
		//ft_printf("l39\n");
		while (SDL_PollEvent(&env->sdl.event))
		{
			//ft_printf("l42\n");
			if (env->sdl.event.type == SDL_QUIT || (env->sdl.event.type == SDL_KEYUP && env->sdl.event.key.keysym.sym == SDLK_ESCAPE))
			{
				//ft_printf("l45\n");
				env->running = 0;
				//ft_printf("l47\n");
			}
			else if (env->sdl.event.type == SDL_KEYDOWN
					|| env->sdl.event.type == SDL_KEYUP || env->sdl.event.type == SDL_MOUSEBUTTONDOWN
					|| env->sdl.event.type == SDL_MOUSEBUTTONUP || env->sdl.event.type == SDL_MOUSEWHEEL)
			{
				//ft_printf("l53\n");
				update_inputs(env);
				//ft_printf("l55\n");
			}
			//ft_printf("l57\n");
			if (env->sdl.event.type == SDL_KEYUP)
			{
				//ft_printf("l60\n");
				keyup(env);
				//ft_printf("l62\n");
			}
			//ft_printf("l64\n");
			if (env->sdl.event.type == SDL_MOUSEWHEEL && !env->weapon_change.on_going && !env->shot.on_going)
			{
				//ft_printf("l67\n");
				weapon_change(env);
				//ft_printf("l69\n");
			}
			//ft_printf("l71\n");
		}
		//ft_printf("l73\n");
		enemy_pursuit(env);
		//ft_printf("l75\n");
		objects_collision(env);
		//ft_printf("l77\n");
		enemy_collision(env);
		//ft_printf("l79\n");
		keys(env);
		//ft_printf("l81\n");
		if (env->menu_start)
		{
			//ft_printf("l84\n");
			start_game_menu(env);
			//ft_printf("l86\n");
		}
		else
		{
			//ft_printf("l90\n");
			if (env->option)
			{
				//ft_printf("l93\n");
				if (open_options(env))
				{
					//ft_printf("l96\n");
					return (crash("Could not process options pannel\n", env));
				}
				//ft_printf("l99\n");
			}
			else if (draw_game(env))
			{
				//ft_printf("l103\n");
				return (ft_printf("Crash in game loop\n"));
				//ft_printf("l105\n");
			}
			//ft_printf("l107\n");
		}
	//	SDL_Delay(5);
	}
	ft_printf("User quit the game\n");
	free_all(env);
	return (0);
}

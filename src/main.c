/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 15:26:12 by lnicosia          #+#    #+#             */
/*   Updated: 2019/04/12 15:06:30 by aherriau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int		main(int ac, char **av)
{
	t_env	env;

	if (ac != 2)
		return (ft_printf("No map file.\n"));
	env.w = 1366;
	env.h = 768;
	env.running = 1;
	if (init_sdl(&env) != 0)
	{
		free_all(&env);
		return (ft_printf("Init error\nExiting the programm..\n"));
	}
	ft_printf("Parsing\n");
	parsing(open(av[1], O_RDONLY), &env);
	//check_parsing(&env);
	ft_printf("[OK]\n");
	SDL_SetRelativeMouseMode(1);
	env.player.speed = 3;
	while (env.running)
	{
		clear_image(&env);
		map_process(&env);
		map_render(&env);
		while (SDL_PollEvent(&env.sdl.event))
		{
			if (env.sdl.event.type == SDL_QUIT || (env.sdl.event.type == SDL_KEYUP && env.sdl.event.key.keysym.sym == SDLK_ESCAPE))
				env.running = 0;
			else if (env.sdl.event.type == SDL_KEYDOWN)
				move_player(&env);
		}
		SDL_GetRelativeMouseState(&env.sdl.mouse_x, &env.sdl.mouse_y);
		view(&env);
		SDL_Delay(10);

		/*
		clear_image(&env);
		draw(&env);
		render(&env);
		while (SDL_PollEvent(&env.sdl.event))
		{
			SDL_CaptureMouse(SDL_TRUE);
			if (env.sdl.event.type == SDL_QUIT
					|| (env.sdl.event.type == SDL_KEYUP
						&& env.sdl.event.key.keysym.sym == SDLK_ESCAPE))
				env.running = 0;
		}
		SDL_GetRelativeMouseState(&env.sdl.mouse_x, &env.sdl.mouse_y);
		env.player.angle += env.sdl.mouse_x * 0.03;
		env.player.dir.x = cos(env.player.angle);
		env.player.dir.y = sin(env.player.angle);
		env.player.dir.z = ft_fclamp(env.player.dir.z + env.sdl.mouse_y * 0.05, -5, 5);
		//ft_printf("player angle = %f\n", env.player.angle);
		SDL_Delay(10);
		*/
	}
	return (0);
}

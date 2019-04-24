/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 15:26:12 by lnicosia          #+#    #+#             */
/*   Updated: 2019/04/24 16:09:24 by lnicosia         ###   ########.fr       */
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
	if (init_sdl(&env) != 0 || init_ttf(&env) != 0)
	{
		free_all(&env);
		return (ft_printf("Init error\nExiting the programm..\n"));
	}
	parsing(open(av[1], O_RDONLY), &env);
	precompute_slopes(&env);
	init_options(&env);
	init_keys(&env);
	init_inputs(&env);
	//check_parsing(&env);
	SDL_SetRelativeMouseMode(1);
	env.player.speed = 0.5;
	env.player.size = 0.5;
	//draw(&env);
	while (env.running)
	{
		clear_image(&env);
		move_player(&env);
		draw(&env);
		draw_crosshair(&env);
		env.sdl.render = 0;
		if (env.options.show_minimap)
			minimap(&env);
		if (env.options.show_fps)
			fps(&env);
		update_screen(&env);
		while (SDL_PollEvent(&env.sdl.event))
		{
			env.sdl.render = 1;
			if (env.sdl.event.type == SDL_QUIT || (env.sdl.event.type == SDL_KEYUP && env.sdl.event.key.keysym.sym == SDLK_ESCAPE))
				env.running = 0;
			else if (env.sdl.event.type == SDL_KEYDOWN
					|| env.sdl.event.type == SDL_KEYUP)
				keys(&env);
		}
		SDL_GetRelativeMouseState(&env.sdl.mouse_x, &env.sdl.mouse_y);
		view(&env);
		SDL_Delay(5);
	}
	return (0);
}

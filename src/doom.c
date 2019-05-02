/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 15:26:12 by lnicosia          #+#    #+#             */
/*   Updated: 2019/05/02 11:53:14 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int		doom(int ac, char **av)
{
	t_env	env;

	if (ac != 2)
		return (ft_printf("No map file.\n"));
	env.w = 1366;
	env.h = 768;
	env.running = 1;
	init_pointers(&env);
	init_options(&env);
	init_keys(&env);
	init_inputs(&env);
	if (init_sdl(&env))
		return (crash("Coulnt not initialize SDL!\n", &env));
	if (init_ttf(&env))
		return (crash("Could not initialize fonts!\n", &env));
	ft_printf("Parsing map \"%s\"..\n", av[1]);
	if (parsing(open(av[1], O_RDONLY), &env))
		return (crash("Parsing error!\n", &env));
	//check_parsing(&env);
	if (valid_map(&env))
		return (crash("Invalid map!\n", &env));
	precompute_slopes(&env);
	if (parse_bmp("images/w3c_home_2.bmp", &env))
		return (crash("Invalid bmp file!\n", &env));
	SDL_SetRelativeMouseMode(1);
	env.player.speed = 0.5;
	env.player.size = 0.5;
	ft_printf("Launching game loop..\n");
	while (env.running)
	{
		clear_image(&env);
		move_player(&env);
		/*if (draw(&env) != 0)
			return (crash("Render function failed\n", &env));*/
		draw_crosshair(&env);
		if (env.options.show_minimap)
			minimap(&env);
		if (env.options.show_fps)
			fps(&env);
		//update_screen(&env);
		//SDL_Renderer *renderer = SDL_CreateRenderer(env.sdl.window, -1, SDL_RENDERER_SOFTWARE);
		SDL_Texture *texture = SDL_CreateTextureFromSurface(env.sdl.renderer, env.sdl.image);
		SDL_RenderCopy(env.sdl.renderer, texture, NULL, NULL);
		SDL_DestroyTexture(texture);
		SDL_RenderPresent(env.sdl.renderer);
		while (SDL_PollEvent(&env.sdl.event))
		{
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
	ft_printf("User quit the game\n");
	free_all(&env);
	return (0);
}

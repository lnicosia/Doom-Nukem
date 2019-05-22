/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaerhard <gaerhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 15:26:12 by lnicosia          #+#    #+#             */
/*   Updated: 2019/05/22 19:03:21 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int		doom(int ac, char **av)
{
	t_env	env;

	if (ac != 2)
		return (ft_printf("No map file.\n"));
	env.w = 1600;
	env.h = 900;
	env.running = 1;
	init_pointers(&env);
	init_options(&env);
	init_keys(&env);
	init_inputs(&env);
	init_camera(&env);
	init_animations(&env);
	env.player.eyesight = 6.00;
	env.player.z = 6.00;
	if (init_sdl(&env))
		return (crash("Coulnt not initialize SDL!\n", &env));
	if (init_ttf(&env))
		return (crash("Could not initialize fonts!\n", &env));
	ft_printf("Parsing map \"%s\"..\n", av[1]);
	if (parsing(open(av[1], O_RDONLY), &env))
		return (crash("Parsing error!\n", &env));
	precompute_slopes(&env);
	//check_parsing(&env);
	if (valid_map(&env))
		return (crash("Invalid map!\n", &env));
	if (parse_bmp("images/wall2.bmp", &env))
		return (crash("Invalid bmp file!\n", &env));
	env.textures[0].surface = env.sdl.image;
	env.textures[0].w = 20;
	env.textures[0].h = 5;
	SDL_SetRelativeMouseMode(1);
	env.flag = 0;
	env.player.speed = 0.2;
	env.player.size_2d = 0.5;
	env.player.gravity = 1;
	ft_printf("Launching game loop..\n");
	env.flag = 0;
	while (env.running)
	{
		SDL_GetRelativeMouseState(&env.sdl.mouse_x, &env.sdl.mouse_y);
		reset_clipped(&env);
		clear_image(&env);
		// BMP parser
		/*apply_surface(env.sdl.image, new_v2(0, 0), new_v2(env.sdl.image->w, env.sdl.image->h), &env);
		SDL_UpdateTexture(env.sdl.texture, NULL, env.sdl.texture_pixels, env.w * sizeof(Uint32));
		SDL_RenderCopy(env.sdl.renderer, env.sdl.texture, NULL, NULL);
		SDL_RenderPresent(env.sdl.renderer);*/
		while (SDL_PollEvent(&env.sdl.event))
		{
			if (env.sdl.event.type == SDL_QUIT || (env.sdl.event.type == SDL_KEYUP && env.sdl.event.key.keysym.sym == SDLK_ESCAPE))
				env.running = 0;
			else if (env.sdl.event.type == SDL_KEYDOWN
					|| env.sdl.event.type == SDL_KEYUP)
				update_inputs(&env);
		}
		keys(&env);
		if (env.options.show_minimap)
			minimap(&env);
		if (draw(&env) != 0)
			return (crash("Render function failed\n", &env));
		draw_crosshair(&env);
		if (env.options.show_fps)
			fps(&env);
		if (env.options.test)
			print_debug(&env);
		update_screen(&env);
		view(&env);
	//	SDL_Delay(5);
	}
	ft_printf("User quit the game\n");
	free_all(&env);
	return (0);
}

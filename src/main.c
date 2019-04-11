/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 15:26:12 by lnicosia          #+#    #+#             */
/*   Updated: 2019/04/11 13:24:58 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int		main(void)
{
	t_env	env;

	env.w = 1366;
	env.h = 768;
	env.running = 1;
	if (init_sdl(&env) != 0)
	{
		free_all(&env);
		return (ft_printf("Init error\nExiting the programm..\n"));
	}
	ft_printf("Parsing\n");
	//parsing(open("../piece.map", O_RDONLY), &env);
	parsing(open("piece.map", O_RDONLY), &env);
	ft_printf("[OK]\n");
	while (env.running)
	{
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
		SDL_Delay(10);
	}
	return (0);
}

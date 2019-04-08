/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 15:26:12 by lnicosia          #+#    #+#             */
/*   Updated: 2019/04/04 14:09:29 by lnicosia         ###   ########.fr       */
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
	init_map(&env);
	while (env.running)
	{
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

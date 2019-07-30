/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   editor.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipatry <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 17:14:57 by sipatry           #+#    #+#             */
/*   Updated: 2019/07/30 14:26:16 by sipatry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

int		editor(t_env *env)
{
	while (env->running)
	{
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
			if (!env->editor.in_game && env->sdl.event.type == SDL_MOUSEWHEEL)
			{
				if (env->sdl.event.wheel.y > 0 && env->editor.scale * 1.1 < 500)
					env->editor.scale *= 1.1;
				if (env->sdl.event.wheel.y < 0 && env->editor.scale / 1.1 > 10)
					env->editor.scale /= 1.1;
			}

		}
		if (!env->editor.in_game)
		{
			if (editor_keys(env))
				return (ft_printf("Error in inputs\n"));
			draw_grid(env);
			draw_grid_vertices(env);
			editor_hud(env);
			if (env->editor.new_player)
				draw_grid_player(env);
			if (env->editor.objects)
				draw_grid_objects(env);
			if (env->editor.new_sector)
				draw_grid_current_sector(env);
			draw_grid_sectors(env);
		}
		else
		{
			if (editor_render(env))
				return (crash("Render function failed\n", env));
		}
		update_screen(env);
	}
	free_all(env);
	return (0);
}

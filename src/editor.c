/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   editor.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipatry <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 17:14:57 by sipatry           #+#    #+#             */
/*   Updated: 2019/07/29 16:38:46 by sipatry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

void	editor(t_env *env)
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
			if (env->sdl.event.type == SDL_MOUSEWHEEL)
			{
				if (env->sdl.event.wheel.y > 0 && env->edit.scale * 1.1 < 500)
					env->edit.scale *= 1.1;
				if (env->sdl.event.wheel.y < 0 && env->edit.scale / 1.1 > 10)
					env->edit.scale /= 1.1;
			}

		}
		editor_keys(env);
		if (env->edit.menu)
			start_editor_menu(env);
		draw_grid(env);
		draw_grid_vertices(env);
		draw_grid_walls(env);
		editor_hud(env);
		if (env->edit.new_player)
			draw_grid_player(env);
		update_screen(env);
	}
}

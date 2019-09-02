/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   editor.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipatry <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 17:14:57 by sipatry           #+#    #+#             */
/*   Updated: 2019/09/02 17:48:57 by lnicosia         ###   ########.fr       */
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
			if (env->sdl.event.type == SDL_KEYUP)
				editor_options(env);
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
			draw_grid(env);
			draw_grid_vertices(env);
			if (editor_keys(env))
				return (ft_printf("Error in inputs\n"));
			editor_hud(env);
			if (env->editor.new_player || env->editor.dragged_player == 1)
				draw_grid_player(env);
			if (env->editor.dragged_object != -1 || env->nb_objects > 0)
				draw_grid_objects(env);
			if (env->editor.start_vertex != -1)
				draw_grid_current_sector(env);
			draw_grid_sectors(env);
		}
		else
		{
			if (editor_render(env))
				return (crash("Render function failed\n", env));
		}
		env->confirmation_box.font = env->sdl.fonts.alice30;
		if (env->confirmation_box.state == 1)
			env->confirmation_box.state = confirmation_box(env->confirmation_box, env);
		/*t_rectangle a = new_rectangle(0xFFDDDDDD, 0xFF888888, 1, 2);
		t_rectangle b = new_rectangle(0xFFDDDDDD, 0xFF444444, 1, 2);
		t_rectangle c = new_rectangle(0xFFDDDDDD, 0xFF444444, 1, 2);
		t_button bu = new_button(a, b, c);
		bu.pos = new_point(env->w / 2, env->h / 2);
		bu.size = new_point(100, 20);
		draw_button(env, bu);*/
		if (env->editor.in_game && env->inputs.shift)
			update_screen_zbuffer(env);
		else
			update_screen(env);
	}
	free_all(env);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_menu.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 15:53:19 by lnicosia          #+#    #+#             */
/*   Updated: 2020/02/13 11:17:08 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "draw.h"

int		print_difficulty(t_env *env)
{
	if (env->difficulty == 0.5)
	{
		if (print_text(new_point(env->h_h + env->next_difficulty.size_down.y,
			env->h_w), new_printable_text("EASY",
			env->sdl.fonts.lato30, 0xFFFFFFFF, 30), env))
			return (-1);
	}
	if (env->difficulty == 1)
	{
		if (print_text(new_point(env->h_h + env->next_difficulty.size_down.y,
			env->h_w), new_printable_text("NORMAL",
			env->sdl.fonts.lato30, 0xFFFFFFFF, 30), env))
			return (-1);
	}
	if (env->difficulty == 1.5)
	{
		if (print_text(new_point(env->h_h + env->next_difficulty.size_down.y,
			env->h_w), new_printable_text("HARD",
			env->sdl.fonts.lato30, 0xFFFFFFFF, 30), env))
			return (-1);
	}
	return (0);
}

int		start_game_menu(t_env *env)
{
	clear_image(env);
	SDL_SetRelativeMouseMode(0);
	apply_surface(env->wall_textures[6].surface, new_point(0, 0),
		new_point(env->w, env->h), env);
	draw_button(env, env->start_game_button, "START");
	draw_button(env, env->next_difficulty, NULL);
	draw_button(env, env->previous_difficulty, NULL);
	draw_button(env, env->option_menu_ig, "OPTIONS");
	draw_button(env, env->exit_button, "EXIT");
	if (print_difficulty(env))
		return (-1);
	while (SDL_PollEvent(&env->sdl.event))
	{
		if (env->sdl.event.type == SDL_QUIT ||
			(env->sdl.event.type == SDL_KEYUP &&
			env->sdl.event.key.keysym.sym == SDLK_ESCAPE))
			env->running = 0;
		update_inputs(env);
		if (env->sdl.event.type == SDL_MOUSEBUTTONUP)
			menu_keyup(env);
		menu_keys(env);
	}
	if (update_screen(env))
		return (-1);
	return (0);
}

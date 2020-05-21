/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_menu.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 15:53:19 by lnicosia          #+#    #+#             */
/*   Updated: 2020/05/18 15:35:50 by marvin           ###   ########.fr       */
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

int		start_game_menu_button(t_env *env)
{
	if (draw_button(env, env->start_game_button, "START"))
		return (-1);
	if (draw_button(env, env->next_difficulty, NULL))
		return (-1);
	if (draw_button(env, env->previous_difficulty, NULL))
		return (-1);
	if (draw_button(env, env->option_menu_ig, "OPTIONS"))
		return (-1);
	if (draw_button(env, env->exit_button, "EXIT"))
		return (-1);
	if (print_difficulty(env))
		return (-1);
	return (0);
}

int		start_game_menu(t_env *env)
{
	clear_image(env);
	SDL_SetRelativeMouseMode(0);
	apply_surface(env->wall_textures[6].surface, new_point(0, 0),
		new_point(env->w, env->h), env);
	if (start_game_menu_button(env))
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

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_menu.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaerhard <gaerhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 15:53:19 by lnicosia          #+#    #+#             */
/*   Updated: 2020/05/14 14:17:01 by gaerhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "draw.h"

int		print_difficulty(t_env *env)
{
	int		w;
	int		h;
	char	*str;

	if (env->difficulty == 0.5)
		str = "EASY";
	if (env->difficulty == 1)
		str = "NORMAL";
	if (env->difficulty == 1.5)
		str = "HARD";
	if (TTF_SizeText(env->sdl.fonts.lato30, str, &w, &h))
		return (-1);
	if (print_text(new_point(env->h_h + env->next_difficulty.size_down.y
		- h /2 , env->h_w - w / 2), new_printable_text(str,
		env->sdl.fonts.lato30, 0x222222FF, 30), env))
		return (-1);
	return (0);
}

int		game_menu_hud(t_env *env)
{
	int w;
	int h;

	apply_surface(env->wall_textures[15].surface, new_point(0, 0),
		new_point(env->w, env->h), env);
	if (TTF_SizeText(env->sdl.fonts.amazdoom70, "DOOM NUKEM", &w, &h))
		return (-1);
	if (print_text(new_point(env->h / 12, env->w / 2 - w / 2),
		new_printable_text("DOOM NUKEM", env->sdl.fonts.amazdoom70,
		0xFFFFFFFF, 70), env))
		return (-1);
	draw_rectangle(env,
		new_rectangle(0xe3e4e8, 0xbdc3c7, 1, 0),
		new_point(env->w / 3, env->h / 6), new_point(env->w / 3,
			3 * env->h / 4));
	return (0);
}

int		draw_menu_buttons(t_env *env)
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
	if (game_menu_hud(env))
		return (-1);
	SDL_SetRelativeMouseMode(0);
	if (draw_menu_buttons(env))
		return (-1);
	while (SDL_PollEvent(&env->sdl.event))
	{
		if (env->sdl.event.type == SDL_QUIT ||
			(env->sdl.event.type == SDL_KEYUP &&
			env->sdl.event.key.keysym.sym == SDLK_ESCAPE))
			env->running = 0;
		update_inputs(env);
		if (env->sdl.event.type == SDL_MOUSEBUTTONUP)
		{
			if (menu_keyup(env))
				return (-1);
		}
		if (menu_keys(env))
			return (-1);
	}
	if (update_screen(env))
		return (-1);
	return (0);
}

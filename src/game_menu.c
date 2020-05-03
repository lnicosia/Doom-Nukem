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

void	print_difficulty(t_env *env)
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
	TTF_SizeText(env->sdl.fonts.lato30, str, &w, &h);
	print_text(new_point(env->h_h + env->next_difficulty.size_down.y,
		env->h_w - w / 2), new_printable_text(str,
		env->sdl.fonts.lato30, 0x222222FF, 30), env);
}

void	game_menu_hud(t_env *env)
{
	int w;
	int h;

	TTF_SizeText(env->sdl.fonts.amazdoom70, "DOOM NUKEM", &w, &h);
	print_text(new_point(env->h / 12, env->w / 2 - w / 2),
		new_printable_text("DOOM NUKEM", env->sdl.fonts.amazdoom70,
		0xFFFFFFFF, 70), env);
	draw_rectangle(env,
		new_rectangle(0xe3e4e8, 0xbdc3c7, 1, 0),
		new_point(env->w / 3, env->h / 6), new_point(env->w / 3,
			3 * env->h / 4));
}

void	start_game_menu(t_env *env)
{
	clear_image(env);
	game_menu_hud(env);
	SDL_SetRelativeMouseMode(0);
	draw_button(env, env->start_game_button, "START");
	draw_button(env, env->next_difficulty, NULL);
	draw_button(env, env->previous_difficulty, NULL);
	draw_button(env, env->option_menu_ig, "OPTIONS");
	draw_button(env, env->exit_button, "EXIT");
	print_difficulty(env);
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
	update_screen(env);
}

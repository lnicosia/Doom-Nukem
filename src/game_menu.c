/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_menu.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 15:53:19 by lnicosia          #+#    #+#             */
/*   Updated: 2019/11/21 15:53:20 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

int		start_game(void	*target)
{
	t_env *env;

	env = (t_env*)target;
	env->menu = 0;
	env->option = 0;
	env->in_game = 1;
	SDL_SetRelativeMouseMode(1);
	return (1);
}

int		next_difficulty(void *target)
{
	t_env *env;

	env = (t_env*)target;
	if (env->difficulty < 1.5)
		env->difficulty += 0.5;
	return (1);
}

int		previous_difficulty(void *target)
{
	t_env *env;

	env = (t_env*)target;
	if (env->difficulty > 0.5)
		env->difficulty -= 0.5;
	return (1);
}

int		open_options(void *target)
{
	t_env *env;

	env = (t_env*)target;
	env->menu = 1;
	env->option = 1;
	env->in_game = 0;
	return (1);
}

int		exit_button_func(void *target)
{
	t_env *env;

	env = (t_env*)target;
	env->running = 0;
	return (1);
}

int		start_game_button(t_env *env)
{
	env->start_game_button = new_image_button(ON_RELEASE, &start_game,
		env, env);
	env->start_game_button.pos =
		new_point(env->h_w - env->start_game_button.size_down.x / 2,
		(env->h_h - env->start_game_button.size_down.y / 2) / 2);
	return (0);
}

int		option_menu_button(t_env *env)
{
	env->option_menu = new_image_button(ON_RELEASE, &open_options,
		env, env);
	env->option_menu.pos = new_point(env->h_w - env->option_menu.size_up.x / 2,
		env->h_h + env->h_h / 4 + env->option_menu.size_up.y);
	return (0);
}

int		exit_button(t_env *env)
{
	env->exit_button = new_image_button(ON_RELEASE, &exit_button_func,
		env, env);
	env->exit_button.pos = new_point(env->h_w - env->exit_button.size_up.x / 2,
		env->h_h + env->h_h / 2 + env->exit_button.size_up.y);
	return (0);
}

int		next_difficulty_button(t_env *env)
{
	env->next_difficulty = new_next_button(ON_RELEASE, &next_difficulty, env,
		env);
	env->next_difficulty.pos = new_point(env->h_w + env->h_w / 2,
		env->h_h +env->next_difficulty.size_down.y);
	return (0);
}

int		prev_difficulty_button(t_env *env)
{
	env->previous_difficulty = new_previous_button(ON_RELEASE,
		&previous_difficulty, env, env);
	env->previous_difficulty.pos = new_point(env->h_w - env->h_w / 2,
		env->h_h + env->previous_difficulty.size_down.y);
	return (0);
}

void	print_difficulty(t_env *env)
{
	if (env->difficulty == 0.5)
		print_text(new_point(env->h_h + env->next_difficulty.size_down.y,
			env->h_w), new_printable_text("EASY",
			env->sdl.fonts.alice30, 0xFFFFFFFF, 30), env);
	if (env->difficulty == 1)
		print_text(new_point(env->h_h + env->next_difficulty.size_down.y,
			env->h_w), new_printable_text("NORMAL",
			env->sdl.fonts.alice30, 0xFFFFFFFF, 30), env);
	if (env->difficulty == 1.5)
		print_text(new_point(env->h_h + env->next_difficulty.size_down.y,
			env->h_w), new_printable_text("HARD",
			env->sdl.fonts.alice30, 0xFFFFFFFF, 30), env);
}

void	start_game_menu(t_env *env)
{
	clear_image(env);
	SDL_SetRelativeMouseMode(0);
	apply_surface(env->wall_textures[6].surface, new_point(0, 0),
		new_point(env->w, env->h), env);
	draw_button(env, env->start_game_button, "START");
	draw_button(env, env->next_difficulty, NULL);
	draw_button(env, env->previous_difficulty, NULL);
	draw_button(env, env->option_menu, "OPTIONS");
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

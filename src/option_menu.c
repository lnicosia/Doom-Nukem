/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   option_menu.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaerhard <gaerhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 16:18:10 by gaerhard          #+#    #+#             */
/*   Updated: 2020/02/04 18:05:46 by gaerhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

int		return_button_func(void	*target)
{
	t_env *env;

	env = (t_env*)target;
	env->option = 0;
	if (env->in_game)
		SDL_SetRelativeMouseMode(1);
	return (1);
}

int		return_button(t_env *env)
{
	env->return_button = new_image_button(ON_RELEASE, &return_button_func,
		env, env);
	env->return_button.pos =
		new_point(env->h_w - env->start_game_button.size_down.x / 2,
		(env->h_h - env->start_game_button.size_down.y / 2) / 2);
	return (0);
}

void	option_menu(t_env *env)
{
	clear_image(env);
	SDL_SetRelativeMouseMode(0);
	apply_surface(env->wall_textures[6].surface, new_point(0, 0),
		new_point(env->w, env->h), env);
	draw_button(env, env->return_button, "RETURN");
	draw_button(env, env->exit_button, "EXIT");
	//draw_button(env, env->music_vol_up_menu);
	//draw_button(env, env->music_vol_down_menu);
	while (SDL_PollEvent(&env->sdl.event))
	{
		if (env->sdl.event.type == SDL_QUIT ||
			(env->sdl.event.type == SDL_KEYUP &&
			env->sdl.event.key.keysym.sym == SDLK_ESCAPE))
			env->running = 0;
		update_inputs(env);
		if (env->sdl.event.type == SDL_MOUSEBUTTONUP)
			option_menu_keyup(env);
		option_menu_keys(env);
	}
	update_screen(env);
}
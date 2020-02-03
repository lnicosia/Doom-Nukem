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

int			start_game(void	*target)
{
	t_env *env;

	env = (t_env*)target;
	env->menu_start = 0;
	SDL_SetRelativeMouseMode(1);
	return (1);
}

int		start_game_button(t_env *env)
{
	env->start_game_button = new_image_button(ON_RELEASE, &start_game, env, env);
	env->start_game_button.str = "START";
	env->start_game_button.pos = new_point(env->h_w - env->start_game_button.size_down.x / 2, env->h_h - env->start_game_button.size_down.y / 2);
	return (0);
}

void		start_game_menu(t_env *env)
{
	clear_image(env);
	SDL_SetRelativeMouseMode(0);
	apply_surface(env->wall_textures[11].surface, new_point(0, 0),
		new_point(env->w, env->h), env);
	draw_button(env, env->start_game_button);
	while (SDL_PollEvent(&env->sdl.event))
	{
		if (env->sdl.event.type == SDL_QUIT || (env->sdl.event.type == SDL_KEYUP &&
			env->sdl.event.key.keysym.sym == SDLK_ESCAPE))
			env->running = 0;
		update_inputs(env);
		if (env->sdl.event.type == SDL_MOUSEBUTTONUP)
			menu_keyup(env);
		menu_keys(env);
	}
	update_screen(env);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   option_menu4.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <gaerhard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/12 11:59:22 by gaerhard          #+#    #+#             */
/*   Updated: 2020/05/12 11:59:22 by gaerhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

int     fps_option_func(void *target)
{
    t_env *env;

    env = (t_env*)target;
    env->options.show_fps = (env->options.show_fps ? 0 : 1);
    return (0);
}

int		fps_option_button(t_env *env)
{
	env->fps_option = new_image_button(ON_RELEASE, &fps_option_func,
		env, env);
	env->fps_option.pos =
		new_point(env->h_w - env->start_game_button.size_down.x / 2,
		(env->h_h - env->start_game_button.size_down.y / 2) - env->h_h / 3);
	return (0);
}

int		return_button_func(void *target)
{
	t_env *env;

	env = (t_env*)target;
	env->option = 0;
	if (env->in_game)
		SDL_SetRelativeMouseMode(1);
	return (0);
}

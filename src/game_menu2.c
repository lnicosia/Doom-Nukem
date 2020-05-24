/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_menu2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/30 11:15:17 by lnicosia          #+#    #+#             */
/*   Updated: 2020/04/30 11:15:17 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "draw.h"

int		start_game(void *target)
{
	t_env *env;

	env = (t_env*)target;
	env->menu = 0;
	env->option = 0;
	env->in_game = 1;
	SDL_SetRelativeMouseMode(1);
	return (0);
}

int		next_difficulty(void *target)
{
	t_env *env;

	env = (t_env*)target;
	if (env->difficulty < 1.5)
		env->difficulty += 0.5;
	return (0);
}

int		previous_difficulty(void *target)
{
	t_env *env;

	env = (t_env*)target;
	if (env->difficulty > 0.5)
		env->difficulty -= 0.5;
	return (0);
}

int		open_options(void *target)
{
	t_env *env;

	env = (t_env*)target;
	env->menu = 1;
	env->option = 1;
	env->in_game = 0;
	return (0);
}

int		exit_button_func(void *target)
{
	t_env *env;

	env = (t_env*)target;
	env->running = 0;
	return (0);
}

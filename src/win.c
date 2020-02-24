/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   win.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 11:48:12 by lnicosia          #+#    #+#             */
/*   Updated: 2020/02/20 17:58:23 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

int		title_screen(void *param)
{
	t_env	*env;

	env = (t_env*)param;
	env->confirmation_box.state = 0;
	respawn(env);
	env->in_game = 0;
	env->menu = 1;
	return (0);
}

int		win(void *param, void *penv)
{
	t_env	*env;
	int		i;

	(void)param;
	env = (t_env*)penv;
	i = 0;
	if (env->player.nb_shots > 0)
		env->player.accuracy = ((env->player.touched / env->player.nb_shots) * 100);
	if (!env->confirmation_box.state)
	{
		SDL_SetRelativeMouseMode(0);
		while (++i < env->nb_enemies)
			env->enemies[i].state = RESTING;
		if (update_confirmation_box(&env->confirmation_box,
					"WOUHHHHHHHHHHHHHHHHHHH", CONFIRM, env))
			return (-1);
		env->confirmation_box.yes_action = &title_screen;
		env->confirmation_box.yes_target = env;
	}
	return (1);
}

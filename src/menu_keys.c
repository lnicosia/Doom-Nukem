/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu_keys.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 17:24:05 by gaerhard          #+#    #+#             */
/*   Updated: 2020/05/19 10:57:05 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

int		menu_keys(t_env *env)
{
	if (button_keys(&env->start_game_button, env))
		return (-1);
	if (button_keys(&env->previous_difficulty, env))
		return (-1);
	if (button_keys(&env->next_difficulty, env))
		return (-1);
	if (button_keys(&env->exit_button, env))
		return (-1);
	if (button_keys(&env->option_menu_ig, env))
		return (-1);
	return (0);
}

int		menu_keyup(t_env *env)
{
	if (button_keyup(&env->start_game_button, env))
		return (-1);
	if (button_keyup(&env->next_difficulty, env))
		return (-1);
	if (button_keyup(&env->previous_difficulty, env))
		return (-1);
	if (button_keyup(&env->exit_button, env))
		return (-1);
	if (button_keyup(&env->option_menu_ig, env))
		return (-1);
	return (0);
}

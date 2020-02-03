/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu_keys.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaerhard <gaerhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 17:24:05 by gaerhard          #+#    #+#             */
/*   Updated: 2020/02/03 17:48:08 by gaerhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

int		menu_keys(t_env *env)
{
	button_keys(&env->start_game_button, env);
	return (0);
}

int		menu_keyup(t_env *env)
{
	button_keyup(&env->start_game_button, env);
	return (0);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   option_menu_keys.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaerhard <gaerhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 17:10:33 by gaerhard          #+#    #+#             */
/*   Updated: 2020/03/08 14:38:17 by gaerhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

int		option_menu_ig_keys(t_env *env)
{
	button_keys(&env->return_button, env);
	button_keys(&env->exit_button, env);
	button_keys(&env->music_vol_down, env);
	button_keys(&env->music_vol_up, env);
	button_keys(&env->sounds_vol_up, env);
	button_keys(&env->sounds_vol_down, env);
	return (0);
}

int		option_menu_ig_keyup(t_env *env)
{
	button_keyup(&env->return_button, env);
	button_keyup(&env->exit_button, env);
	button_keyup(&env->music_vol_down, env);
	button_keyup(&env->music_vol_up, env);
	button_keyup(&env->sounds_vol_up, env);
	button_keyup(&env->sounds_vol_down, env);
	return (0);
}
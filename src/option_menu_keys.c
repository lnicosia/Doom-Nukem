/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   option_menu_keys.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaerhard <gaerhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 17:10:33 by gaerhard          #+#    #+#             */
/*   Updated: 2020/02/04 17:11:40 by gaerhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

int		option_menu_keys(t_env *env)
{
	button_keys(&env->return_button, env);
	button_keys(&env->exit_button, env);
/*	button_keys(&env->music_vol_down_menu, env);
	button_keys(&env->music_vol_down_menu, env);*/
	return (0);
}

int		option_menu_keyup(t_env *env)
{
	button_keyup(&env->return_button, env);
	button_keyup(&env->exit_button, env);
/*	button_keyup(&env->music_vol_down_menu, env);
	button_keyup(&env->music_vol_up_menu, env);*/
	return (0);
}
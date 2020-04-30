/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   option_menu_keys.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 17:10:33 by gaerhard          #+#    #+#             */
/*   Updated: 2020/04/30 17:46:42 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

int		option_menu_ig_keys(t_env *env)
{
	if (button_keys(&env->return_button, env))
		return (-1);
	if (button_keys(&env->exit_button, env))
		return (-1);
	if (button_keys(&env->music_vol_down, env))
		return (-1);
	if (button_keys(&env->music_vol_up, env))
		return (-1);
	if (button_keys(&env->sounds_vol_up, env))
		return (-1);
	if (button_keys(&env->sounds_vol_down, env))
		return (-1);
	return (0);
}

int		option_menu_ig_keyup(t_env *env)
{
	if (button_keyup(&env->return_button, env))
		return (-1);
	if (button_keyup(&env->exit_button, env))
		return (-1);
	if (button_keyup(&env->music_vol_down, env))
		return (-1);
	if (button_keyup(&env->music_vol_up, env))
		return (-1);
	if (button_keyup(&env->sounds_vol_up, env))
		return (-1);
	if (button_keyup(&env->sounds_vol_down, env))
		return (-1);
	return (0);
}

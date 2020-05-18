/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu_keys.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 17:24:05 by gaerhard          #+#    #+#             */
/*   Updated: 2020/04/30 17:16:04 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

int		menu_keys(t_env *env)
{
	button_keys(&env->start_game_button, env);
	button_keys(&env->previous_difficulty, env);
	button_keys(&env->next_difficulty, env);
	button_keys(&env->exit_button, env);
	button_keys(&env->option_menu_ig, env);
	button_keys(&env->music_vol_down_menu, env);
	button_keys(&env->music_vol_down_menu, env);
	return (0);
}

int		menu_keyup(t_env *env)
{
	button_keyup(&env->start_game_button, env);
	button_keyup(&env->next_difficulty, env);
	button_keyup(&env->previous_difficulty, env);
	button_keyup(&env->exit_button, env);
	button_keyup(&env->option_menu_ig, env);
	button_keyup(&env->music_vol_down_menu, env);
	button_keyup(&env->music_vol_up_menu, env);
	return (0);
}

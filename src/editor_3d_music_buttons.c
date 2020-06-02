/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   editor_3d_music_buttons.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaerhard <gaerhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/14 16:41:28 by gaerhard          #+#    #+#             */
/*   Updated: 2020/05/14 16:41:28 by gaerhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

int		music_keys(t_env *env)
{
	if (button_keys(&env->editor.next_ambiance_music, env))
		return (-1);
	if (button_keys(&env->editor.next_fighting_music, env))
		return (-1);
	if (button_keys(&env->editor.previous_ambiance_music, env))
		return (-1);
	if (button_keys(&env->editor.previous_fighting_music, env))
		return (-1);
	return (0);
}

int		music_keyup(t_env *env)
{
	if (button_keyup(&env->editor.next_ambiance_music, env))
		return (-1);
	if (button_keyup(&env->editor.next_fighting_music, env))
		return (-1);
	if (button_keyup(&env->editor.previous_ambiance_music, env))
		return (-1);
	if (button_keyup(&env->editor.previous_fighting_music, env))
		return (-1);
	return (0);
}

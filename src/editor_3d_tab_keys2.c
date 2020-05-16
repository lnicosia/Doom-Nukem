/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   editor_3d_tab_keys2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/15 22:59:22 by marvin            #+#    #+#             */
/*   Updated: 2020/05/16 12:33:30 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "events.h"

int	general_selection_buttons_keys(t_env *env)
{
	if (button_keys(&env->editor.current_texture_selection, env))
		return (-1);
	if (button_keys(&env->editor.current_enemy_selection, env))
		return (-1);
	if (button_keys(&env->editor.current_object_selection, env))
		return (-1);
	if (button_keys(&env->editor.texture_background, env))
		return (-1);
	return (0);
}

int	general_music_keys(t_env *env)
{
	if (button_keys(&env->editor.previous_fighting_music, env))
		return (-1);
	if (button_keys(&env->editor.previous_ambiance_music, env))
		return (-1);
	if (button_keys(&env->editor.next_ambiance_music, env))
		return (-1);
	if (button_keys(&env->editor.next_fighting_music, env))
		return (-1);
    return (0);
}


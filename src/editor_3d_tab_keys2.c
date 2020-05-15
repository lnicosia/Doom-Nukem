/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   editor_3d_tab_keys2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/15 22:59:22 by marvin            #+#    #+#             */
/*   Updated: 2020/05/15 23:00:41 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "events.h"

int general_music_keys(t_env *env)
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
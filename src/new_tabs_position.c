/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_tabs_position.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipatry <sipatry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 15:14:02 by sipatry           #+#    #+#             */
/*   Updated: 2020/01/31 15:54:37 by sipatry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

void	new_tabs_position(t_env *env)
{
	/*
	**	In_game editor mode: when a sprite is selected
	*/

	if (env->editor.in_game && env->editor.tab &&
	(env->selected_ceiling_sprite != -1 || env->selected_floor_sprite != -1
	|| env->selected_wall_sprite_sprite != -1))
	{
		env->editor.sprite_tab.pos = new_point(0, 425);
		env->editor.events_tab.pos = new_point(238, 425);
	}
	else
	{
		env->editor.sprite_tab.pos = new_point(238, 425);
		env->editor.events_tab.pos = new_point(357, 425);
	}
}
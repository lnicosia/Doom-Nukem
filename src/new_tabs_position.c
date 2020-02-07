/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_tabs_position.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipatry <sipatry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 15:14:02 by sipatry           #+#    #+#             */
/*   Updated: 2020/02/07 19:08:37 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

/*
**	Places editor tabs correctly
*/

void	new_tabs_position(t_env *env)
{

	if (env->editor.selected_sector == -1
		&& env->selected_floor == -1 && env->selected_ceiling == -1)
	{
		env->editor.events_tab.pos.x = 0;
		env->editor.general_tab.pos.x = -1000;
		env->editor.sector_tab.pos.x = -1000;
		env->editor.sprite_tab.pos.x = -1000;
	}
	if (!env->editor.in_game && env->editor.selected_sector != -1)
	{
		env->editor.events_tab.pos.x = 119;
		env->editor.general_tab.pos.x = 0;
		env->editor.sector_tab.pos.x = -1000;
		env->editor.sprite_tab.pos.x = -1000;
	}
	if (env->editor.selected_wall != -1 || env->selected_enemy != -1
		|| env->selected_object != -1 || env->selected_floor != -1
		|| env->selected_ceiling != -1 || env->editor.selected_player != -1)
	{
		env->editor.events_tab.pos.x = 238;
		env->editor.general_tab.pos.x = 0;
		env->editor.sector_tab.pos.x = 119;
		env->editor.sprite_tab.pos.x = -1000;
	}
}

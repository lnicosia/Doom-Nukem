/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   are_events_selection_buttons_visible.c             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/28 16:37:07 by lnicosia          #+#    #+#             */
/*   Updated: 2020/04/28 16:37:08 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

int			are_events_selection_buttons_visible(t_env *env)
{
	int	sector;

	if (env->selected_floor != -1)
		sector = env->selected_floor;
	else
		sector = env->editor.selected_sector;
	if (env->editor.events_tab.state == DOWN
		&& (env->selected_wall_sprite_wall != -1 || sector != -1
		|| env->selected_enemy != -1))
		return (1);
	return (0);
}

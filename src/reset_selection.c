/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reset_selection.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipatry <sipatry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/01 13:22:45 by lnicosia          #+#    #+#             */
/*   Updated: 2020/02/06 21:45:08 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

void	reset_selection(t_env *env)
{
	env->editor.selected_sector = -1;
	env->selected_wall1 = -1;
	env->selected_wall2 = -1;
	env->selected_floor = -1;
	env->selected_ceiling = -1;
	env->selected_object = -1;
	env->selected_enemy = -1;
	env->editor.selected_vertex = -1;
	env->editor.selected_sector = -1;
	env->editor.selected_player = -1;
	env->editor.selected_wall = -1;
	env->selected_wall_sprite_sprite = -1;
	env->selected_wall_sprite_wall = -1;
	env->selected_floor_sprite = -1;
	env->selected_ceiling_sprite = -1;
	env->editor.selected_events = 0;
	env->editor.selected_event = 0;
	env->editor.selected_launch_condition = 0;
	env->editor.selected_exec_condition = 0;
	env->editor.dragged_vertex = -1;
	env->editor.dragged_object = -1;
	env->editor.dragged_enemy = -1;
	env->editor.dragged_player = -1;
	env->editor.event_panel_dragged = -1;
	env->editor.start_vertex = -1;
}

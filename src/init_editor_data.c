/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_editor_data.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipatry <sipatry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 09:05:18 by lnicosia          #+#    #+#             */
/*   Updated: 2020/01/20 16:06:00 by sipatry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

void	init_editor_data(t_env *env)
{
	env->editor.scale = 10;
	env->editor.current_vertices = NULL;
	env->editor.start_vertex = -1;
	env->player.sector = -1;
	env->editor.selected_sector = -1;
	env->editor.selected_object = -1;
	env->editor.selected_vertex = -1;
	env->editor.selected_player = -1;
	env->editor.selected_wall = -1;
	env->editor.selected_wall_sprite = -1;
	env->editor.dragged_object = -1;
	env->editor.dragged_vertex = -1;
	env->editor.dragged_player = -1;
	env->editor.dragged_enemy = -1;
	env->selected_wall1 = -1;
	env->selected_wall2 = -1;
	env->selected_floor = -1;
	env->selected_ceiling = -1;
	env->selected_wall_sprite_sprite = -1;
	env->selected_wall_sprite_wall = -1;
	env->hovered_wall_sprite_sprite = -1;
	env->hovered_wall_sprite_wall = -1;
	env->hovered_wall_sprite_sector = -1;
	env->selected_enemy = -1;
	env->selected_object = -1;
}

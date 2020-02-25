/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   editor_env_vertices_buttons.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipatry <sipatry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 10:46:18 by sipatry           #+#    #+#             */
/*   Updated: 2020/02/25 11:12:58 by sipatry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

void	init_vertices_general_env(t_env *env)
{
	env->editor.hud.g_vertex.t_pos_x.env = env;
	env->editor.hud.g_vertex.t_pos_x.pos = new_point(0, 0);
	env->editor.hud.g_vertex.t_pos_x.type = DOUBLE;
	env->editor.hud.g_vertex.t_pos_y.env = env;
	env->editor.hud.g_vertex.t_pos_y.pos = new_point(0, 0);
	env->editor.hud.g_vertex.t_pos_y.type = DOUBLE;
	env->editor.hud.g_vertex.t_num.env = env;
	env->editor.hud.g_vertex.t_num.pos = new_point(0, 0);
	env->editor.hud.g_vertex.t_num.type = DOUBLE;
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   editor_vertices_tab_button.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipatry <sipatry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 10:43:03 by sipatry           #+#    #+#             */
/*   Updated: 2020/03/11 11:40:27 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

void	init_vertices_general_buttons(t_env *env)
{
	env->editor.hud.g_vertex.num = new_hud_button(ON_RELEASE,
	NULL, &env->editor.hud.g_vertex.t_num, env);
	env->editor.hud.g_vertex.num.pos = new_point(170, 500);
	env->editor.hud.g_vertex.t_num.pos = new_point(170, 500);
	env->editor.hud.g_vertex.pos_x = new_hud_button(ON_RELEASE,
	NULL, &env->editor.hud.g_vertex.t_pos_x, env);
	env->editor.hud.g_vertex.pos_x.pos = new_point(170, 560);
	env->editor.hud.g_vertex.t_pos_x.pos = new_point(170, 560);
	env->editor.hud.g_vertex.pos_y = new_hud_button(ON_RELEASE,
	NULL, &env->editor.hud.g_vertex.t_pos_y, env);
	env->editor.hud.g_vertex.pos_y.pos = new_point(170, 600);
	env->editor.hud.g_vertex.t_pos_y.pos = new_point(170, 600);
}

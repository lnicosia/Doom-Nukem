/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   editor_vertices_tab.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipatry <sipatry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 10:23:44 by sipatry           #+#    #+#             */
/*   Updated: 2020/03/04 17:11:35 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

int		print_vertices_general_tab(t_env *env)
{
	print_text(new_point(500, 60), new_printable_text("Vertex Num: ",
	env->sdl.fonts.lato20, 0x00000000, 30), env);
	ft_snprintf(env->snprintf, SNPRINTF_SIZE, "%d",
	env->editor.selected_vertex);
	env->editor.hud.g_vertex.t_num.target = &env->editor.selected_vertex;
	draw_button(env, env->editor.hud.g_vertex.num, env->snprintf);
	print_text(new_point(560, 60), new_printable_text("Pos X: ",
	env->sdl.fonts.lato20, 0x00000000, 30), env);
	ft_snprintf(env->snprintf, SNPRINTF_SIZE, "%.*f",
	get_decimal_len(env->vertices[env->editor.selected_vertex].x),
	env->vertices[env->editor.
	selected_vertex].x);
	env->editor.hud.g_vertex.t_pos_x.target =
	&env->vertices[env->editor.selected_vertex].x;
	draw_button(env, env->editor.hud.g_vertex.pos_x, env->snprintf);
	print_text(new_point(600, 60), new_printable_text("Pos Y: ",
	env->sdl.fonts.lato20, 0x00000000, 30), env);
	ft_snprintf(env->snprintf, SNPRINTF_SIZE, "%.*f",
	get_decimal_len(env->vertices[env->editor.selected_vertex].y),
	env->vertices[env->editor.
	selected_vertex].y);
	env->editor.hud.g_vertex.t_pos_y.target =
	&env->vertices[env->editor.selected_vertex].y;
	draw_button(env, env->editor.hud.g_vertex.pos_y, env->snprintf);
	return (0);
}

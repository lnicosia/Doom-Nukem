/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   editor_vertices_tab.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 10:23:44 by sipatry           #+#    #+#             */
/*   Updated: 2020/04/29 18:46:47 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "draw.h"

int		print_vertices_general_tab2(t_env *env)
{
	ft_snprintf(env->snprintf, SNPRINTF_SIZE, "%.*f",
	get_decimal_len(env->vertices[env->editor.selected_vertex].y),
	env->vertices[env->editor.
	selected_vertex].y);
	env->editor.hud.g_vertex.t_pos_y.target =
	&env->vertices[env->editor.selected_vertex].y;
	draw_button(env, env->editor.hud.g_vertex.pos_y, env->snprintf);
	return (0);
}

int		print_vertices_general_tab(t_env *env)
{
	t_point		size;

	ft_snprintf(env->snprintf, SNPRINTF_SIZE, "Vertex %d",
	env->editor.selected_vertex);
	if (TTF_SizeText(env->sdl.fonts.lato_black30,
		env->snprintf, &size.x, &size.y))
		return (-1);
	if (print_text(new_point(465, 200 - size.x / 2),
	new_printable_text(env->snprintf,
	env->sdl.fonts.lato_black30, 0x333333FF, 30), env))
		return (-1);
	env->editor.hud.g_vertex.t_num.target = &env->editor.selected_vertex;
	if (print_text(new_point(560, 60), new_printable_text("X ",
	env->sdl.fonts.lato20, 0x00000000, 30), env))
		return (-1);
	ft_snprintf(env->snprintf, SNPRINTF_SIZE, "%.*f",
	get_decimal_len(env->vertices[env->editor.selected_vertex].x),
	env->vertices[env->editor.
	selected_vertex].x);
	env->editor.hud.g_vertex.t_pos_x.target =
	&env->vertices[env->editor.selected_vertex].x;
	draw_button(env, env->editor.hud.g_vertex.pos_x, env->snprintf);
	if (print_text(new_point(600, 60), new_printable_text("Y",
	env->sdl.fonts.lato20, 0x00000000, 30), env))
		return (-1);
	return (print_vertices_general_tab2(env));
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   editor_hud.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipatry <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/29 15:44:44 by sipatry           #+#    #+#             */
/*   Updated: 2019/09/03 15:26:03 by sipatry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

void	print_vertex_informations(t_env *env)
{
	print_text(new_point(10, 380), new_printable_text("vertex ",
				env->sdl.fonts.alice30, 0xFFFFFFFF, 30), env);
	print_text(new_point(10, 480), new_printable_text(ft_sitoa(env->editor.selected_vertex),
				env->sdl.fonts.alice30, 0xFFFFFFFF, 30), env);
}

void	print_sector_informations(t_env *env)
{
	print_text(new_point(10, 390), new_printable_text("sector ", env->sdl.fonts.alice30, 0xFFFFFFFF, 30), env);
	print_text(new_point(10, 480), new_printable_text(ft_sitoa(env->editor.selected_sector), env->sdl.fonts.alice30, 0xFFFFFFFF, 30), env);
}

void	print_object_informations(t_env *env)
{
	print_text(new_point(10, 390), new_printable_text("object ", env->sdl.fonts.alice30, 0xFFFFFFFF, 30), env);
	print_text(new_point(10, 480), new_printable_text(ft_sitoa(env->editor.selected_object), env->sdl.fonts.alice30, 0xFFFFFFFF, 30), env);

}

void	editor_hud(t_env *env)
{
	t_point	center;

	center.x = 100;
	center.y = 100;
	draw_circle(new_circle(0xFFFF0000, 0xFFFF0000, center, (env->editor.scale / 2)), env);
	print_text(new_point(50, 60), new_printable_text("Player", env->sdl.fonts.alice30, 0xFFFFFFFF, 30), env);
	center.x = 100;
	center.y = 200;
	draw_circle(new_circle(0xFFFFFF00, 0xFFFFFF00, center, (env->editor.scale / 2)), env);
	print_text(new_point(150, 60), new_printable_text("Object", env->sdl.fonts.alice30, 0xFFFFFFFF, 30), env);
	print_text(new_point(10, 240), new_printable_text("Selected: ", env->sdl.fonts.alice30, 0xFFFFFFFF, 30), env);
	if (env->editor.tab)
	{
		draw_rectangle(env,
				new_rectangle(0x00000000, 0xFF888888, 1, 5),
				new_point( 220 , 60),
				new_point(300, 400));
		if (env->editor.selected_vertex != -1)
			print_vertex_informations(env);
		else if (env->editor.selected_player != -1)
			print_text(new_point(10, 430), new_printable_text("player ", env->sdl.fonts.alice30, 0xFFFFFFFF, 30), env);
		else if (env->editor.selected_object != -1)
			print_object_informations(env);
		else if (env->editor.selected_sector != -1)
			print_sector_informations(env);
		else
			print_text(new_point(10, 430), new_printable_text("none", env->sdl.fonts.alice30, 0xFFFFFFFF, 30), env);
	}
}

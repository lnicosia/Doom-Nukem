/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   editor_options_menu_hud_2.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaerhard <gaerhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 17:18:52 by gaerhard          #+#    #+#             */
/*   Updated: 2020/03/12 18:56:35 by gaerhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

void	print_on_off(t_env *env, int bool, t_point p)
{
	if (bool)
		print_text(p, new_printable_text("ON", env->sdl.fonts.lato20,
			0x009246FF, 20), env);
	else
		print_text(p, new_printable_text("OFF", env->sdl.fonts.lato20,
			0xCC0000FF, 20), env);
}

void	editor_options_rectangles(t_env *env)
{
	draw_rectangle(env,
		new_rectangle(0xe3e4e8, 0xbdc3c7, 1, 0),
		new_point(20, 40), new_point(360, 230));
	draw_rectangle(env,
		new_rectangle(0xe3e4e8, 0xbdc3c7, 1, 0),
		new_point(20, 310), new_point(360, 92));
	draw_rectangle(env,
		new_rectangle(0xe3e4e8, 0xbdc3c7, 1, 0),
		new_point(20, 415), new_point(360, 92));
	draw_rectangle(env,
		new_rectangle(0xe3e4e8, 0xbdc3c7, 1, 0),
		new_point(20, 520), new_point(360, 72));
	draw_rectangle(env,
		new_rectangle(0xe3e4e8, 0xbdc3c7, 1, 0),
		new_point(20, 605), new_point(360, 52));
	draw_rectangle(env,
		new_rectangle(0xe3e4e8, 0xbdc3c7, 1, 0),
		new_point(20, 670), new_point(360, 210));
}

void	editor_options_buttons(t_env *env)
{
	draw_button(env, env->editor.quit_options,
		env->editor.quit_options.str);
	print_text(new_point(5, 155), new_printable_text("OPTIONS",
		env->sdl.fonts.lato_bold25, 0x000000FF, 25), env);
	print_text(new_point(275, 167), new_printable_text("HELP",
		env->sdl.fonts.lato_bold25, 0x000000FF, 25), env);
	draw_button(env, env->editor.mipmapping,
		env->editor.mipmapping.str);
	draw_button(env, env->editor.zbuffer, env->editor.zbuffer.str);
	draw_button(env, env->editor.light, env->editor.light.str);
	draw_button(env, env->editor.fps, env->editor.fps.str);
	print_on_off(env, env->options.mipmapping, new_point(64, 265));
	print_on_off(env, env->options.zbuffer, new_point(114, 265));
	print_on_off(env, env->options.lighting, new_point(164, 265));
	print_on_off(env, env->options.show_fps, new_point(214, 265));
}
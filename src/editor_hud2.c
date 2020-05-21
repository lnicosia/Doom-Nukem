/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   editor_hud2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/29 18:07:36 by lnicosia          #+#    #+#             */
/*   Updated: 2020/04/29 18:07:36 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "draw.h"

int		print_on_off(t_env *env, int bool, t_point p)
{
	if (bool)
	{
		if (print_text(p, new_printable_text("ON", env->sdl.fonts.lato20,
			0x009246FF, 20), env))
			return (-1);
	}
	else
	{
		if (print_text(p, new_printable_text("OFF", env->sdl.fonts.lato20,
			0xCC0000FF, 20), env))
			return (-1);
	}
	return (0);
}

void	editor_options_rectangles(t_env *env)
{
	draw_rectangle(env,
		new_rectangle(0xe3e4e8, 0xbdc3c7, 1, 0),
		new_point(20, 40), new_point(360, 230));
	draw_rectangle(env,
		new_rectangle(0xe3e4e8, 0xbdc3c7, 1, 0),
		new_point(20, 310), new_point(360, 112));
	draw_rectangle(env,
		new_rectangle(0xe3e4e8, 0xbdc3c7, 1, 0),
		new_point(20, 435), new_point(360, 112));
	draw_rectangle(env,
		new_rectangle(0xe3e4e8, 0xbdc3c7, 1, 0),
		new_point(20, 560), new_point(360, 92));
	draw_rectangle(env,
		new_rectangle(0xe3e4e8, 0xbdc3c7, 1, 0),
		new_point(20, 665), new_point(360, 52));
	draw_rectangle(env,
		new_rectangle(0xe3e4e8, 0xbdc3c7, 1, 0),
		new_point(20, 730), new_point(360, 150));
}

int		editor_options_buttons(t_env *env)
{
	if (draw_button(env, env->editor.quit_options,
		env->editor.quit_options.str))
		return (-1);
	if (print_text(new_point(5, 155), new_printable_text("OPTIONS",
		env->sdl.fonts.lato_bold25, 0x000000FF, 25), env))
		return (-1);
	if (print_text(new_point(275, 167), new_printable_text("HELP",
		env->sdl.fonts.lato_bold25, 0x000000FF, 25), env))
		return (-1);
	if (draw_button(env, env->editor.mipmapping,
		env->editor.mipmapping.str))
		return (-1);
	if (draw_button(env, env->editor.zbuffer, env->editor.zbuffer.str))
		return (-1);
	if (draw_button(env, env->editor.light, env->editor.light.str))
		return (-1);
	if (draw_button(env, env->editor.fps, env->editor.fps.str))
		return (-1);
	if (print_on_off(env, env->options.mipmapping, new_point(64, 265)))
		return (-1);
	if (print_on_off(env, env->options.zbuffer, new_point(114, 265)))
		return (-1);
	if (print_on_off(env, env->options.lighting, new_point(164, 265)))
		return (-1);
	if (print_on_off(env, env->options.show_fps, new_point(214, 265)))
		return (-1);
	return (0);
}

int		editor_options_ceil_floor(t_env *env)
{
	if (print_text(new_point(315, 50), new_printable_text("Ceiling/Floor",
		env->sdl.fonts.lato_bold15, 0x000000FF, 15), env))
		return (-1);
	ft_snprintf(env->snprintf, SNPRINTF_SIZE, "Select%*s", 55, "left-click");
	if (print_text(new_point(340, 70), new_printable_text(env->snprintf,
		env->sdl.fonts.lato15, 0x000000FF, 15), env))
		return (-1);
	ft_snprintf(env->snprintf, SNPRINTF_SIZE, "Height%*s", 53, "+/-");
	if (print_text(new_point(360, 70), new_printable_text(env->snprintf,
		env->sdl.fonts.lato15, 0x000000FF, 15), env))
		return (-1);
	ft_snprintf(env->snprintf, SNPRINTF_SIZE, "Slope %*s", 56, "ctrl +/-");
	if (print_text(new_point(380, 70), new_printable_text(env->snprintf,
		env->sdl.fonts.lato15, 0x000000FF, 15), env))
		return (-1);
	ft_snprintf(env->snprintf, SNPRINTF_SIZE, "Start slope%*s", 45,
		"ctrl shift <-/->");
	if (print_text(new_point(400, 70), new_printable_text(env->snprintf,
		env->sdl.fonts.lato15, 0x000000FF, 15), env))
		return (-1);
	return (0);
}

int		editor_options_textures(t_env *env)
{
	if (print_text(new_point(440, 50), new_printable_text("Textures",
		env->sdl.fonts.lato_bold15, 0x000000FF, 15), env))
		return (-1);
	ft_snprintf(env->snprintf, SNPRINTF_SIZE, "Select%*s", 55, "left-click");
	if (print_text(new_point(465, 70), new_printable_text(env->snprintf,
		env->sdl.fonts.lato15, 0x000000FF, 15), env))
		return (-1);
	ft_snprintf(env->snprintf, SNPRINTF_SIZE, "Add texture%*s", 41, "T");
	if (print_text(new_point(485, 70), new_printable_text(env->snprintf,
		env->sdl.fonts.lato15, 0x000000FF, 15), env))
		return (-1);
	ft_snprintf(env->snprintf, SNPRINTF_SIZE, "Scale %*s", 57,
		"ctrl shift +/-");
	if (print_text(new_point(505, 70), new_printable_text(env->snprintf,
		env->sdl.fonts.lato15, 0x000000FF, 15), env))
		return (-1);
	ft_snprintf(env->snprintf, SNPRINTF_SIZE, "Align %*s", 57,
		"ctrl shift </>");
	if (print_text(new_point(525, 70), new_printable_text(env->snprintf,
		env->sdl.fonts.lato15, 0x000000FF, 15), env))
		return (-1);
	return (0);
}

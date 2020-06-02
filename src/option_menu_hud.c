/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   option_menu_hud.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 16:18:10 by gaerhard          #+#    #+#             */
/*   Updated: 2020/05/23 19:18:04 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "draw.h"

int		option_menu_hud2(t_env *env)
{
	if (env->options.show_fps)
	{
		if (print_text(new_point(env->fps_option.pos.y, env->fps_option.pos.x +
			150), new_printable_text("ON", env->sdl.fonts.lato20,
			0x009246FF, 20), env))
			return (-1);
	}
	else
	{
		if (print_text(new_point(env->fps_option.pos.y, env->fps_option.pos.x +
			150), new_printable_text("OFF", env->sdl.fonts.lato20,
			0xCC0000FF, 20), env))
			return (-1);
	}
	return (0);
}

int		option_menu_hud(t_env *env)
{
	int w;
	int h;

	apply_surface(env->wall_textures[15].surface, new_point(0, 0),
		new_point(env->w, env->h), env);
	if (TTF_SizeText(env->sdl.fonts.amazdoom70, "DOOM NUKEM", &w, &h))
		return (-1);
	if (print_text(new_point(env->h / 12, env->w / 2 - w / 2),
		new_printable_text("DOOM NUKEM", env->sdl.fonts.amazdoom70,
		0xFFFFFFFF, 70), env))
		return (-1);
	draw_rectangle(env,
		new_rectangle(0xe3e4e8, 0xbdc3c7, 1, 0),
		new_point(env->w / 3, env->h / 6), new_point(env->w / 3,
			3 * env->h / 4));
	return (option_menu_hud2(env));
}

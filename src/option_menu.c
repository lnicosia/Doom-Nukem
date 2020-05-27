/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   option_menu.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 16:18:10 by gaerhard          #+#    #+#             */
/*   Updated: 2020/05/23 19:18:04 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "draw.h"

int		options_menu_hud(t_env *env)
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

int		print_music_vol(t_env *env)
{
	int w;
	int h;

	if (TTF_SizeText(env->sdl.fonts.lato30, "MUSIC", &w, &h))
		return (-1);
	if (print_text(new_point(env->h_h +
		env->music_vol_up.size_down.y - h /2, env->h_w - w / 2),
		new_printable_text("MUSIC", env->sdl.fonts.lato30,
		0x222222FF, 30), env))
		return (-1);
	ft_snprintf(env->snprintf, 4, "%.f",
		env->sound.music_vol * 100);
	if (TTF_SizeText(env->sdl.fonts.lato30, env->snprintf, &w, &h))
		return (-1);
	if (print_text(new_point(env->h_h +
		env->music_vol_up.size_down.y + 35, env->h_w - w / 2),
		new_printable_text(env->snprintf, env->sdl.fonts.lato30,
		0x222222FF, 30), env))
		return (-1);
	return (0);
}

int		print_sounds_vol(t_env *env)
{
	int w;
	int h;

	if (TTF_SizeText(env->sdl.fonts.lato30, "SOUNDS", &w, &h))
		return (-1);
	if (print_text(new_point(env->h_h + env->h_h / 4
	  	+ env->sounds_vol_down.size_up.y - h / 2, env->h_w - w / 2),
		new_printable_text("SOUNDS", env->sdl.fonts.lato30,
		0x222222FF, 30), env))
		return (-1);
	ft_snprintf(env->snprintf, 4, "%.f",
		env->sound.ambient_vol * 100);
	if (TTF_SizeText(env->sdl.fonts.lato30, env->snprintf, &w, &h))
		return (-1);
	if (print_text(new_point(env->h_h + env->h_h / 4 +
		env->sounds_vol_up.size_down.y + 35, env->h_w - w / 2),
		new_printable_text(env->snprintf, env->sdl.fonts.lato30,
		0x222222FF, 30), env))
		return (-1);
	return (0);
}

int		draw_option_menu_ig_buttons(t_env *env)
{
	if (draw_button(env, env->return_button, "RETURN"))
		return (-1);
	if (draw_button(env, env->exit_button, "EXIT"))
		return (-1);
	if (draw_button(env, env->music_vol_up, NULL))
		return (-1);
	if (draw_button(env, env->music_vol_down, NULL))
		return (-1);
	if (draw_button(env, env->sounds_vol_up, NULL))
		return (-1);
	if (draw_button(env, env->sounds_vol_down, NULL))
		return (-1);
	if (draw_button(env, env->fps_option, "FPS"))
		return (-1);
	return (0);
}

int		option_menu_ig(t_env *env)
{
	clear_image(env);
	SDL_SetRelativeMouseMode(0);
	if (options_menu_hud(env))
		return (-1);
	if (draw_option_menu_ig_buttons(env))
		return (-1);
	if (print_music_vol(env))
		return (-1);
	if (print_sounds_vol(env))
		return (-1);
	if (print_hfov_value(env))
		return (-1);
	while (SDL_PollEvent(&env->sdl.event))
	{
		if (env->sdl.event.type == SDL_QUIT ||
			(env->sdl.event.type == SDL_KEYUP &&
			env->sdl.event.key.keysym.sym == SDLK_ESCAPE))
			env->running = 0;
		update_inputs(env);
		if (env->sdl.event.type == SDL_MOUSEBUTTONUP
			|| env->sdl.event.type == SDL_KEYUP)
		{
			if (option_menu_ig_keyup(env))
				return (-1);
		}
		if (option_menu_ig_keys(env))
			return (-1);
	}
	if (update_screen(env))
		return (-1);
	return (0);
}

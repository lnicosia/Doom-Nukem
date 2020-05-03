/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   option_menu.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 16:18:10 by gaerhard          #+#    #+#             */
/*   Updated: 2020/04/30 17:46:20 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

void	options_menu_hud(t_env *env)
{
	int w;
	int h;

	TTF_SizeText(env->sdl.fonts.amazdoom70, "DOOM NUKEM", &w, &h);
	print_text(new_point(env->h / 12, env->w / 2 - w / 2),
		new_printable_text("DOOM NUKEM", env->sdl.fonts.amazdoom70,
		0xFFFFFFFF, 70), env);
	draw_rectangle(env,
		new_rectangle(0xe3e4e8, 0xbdc3c7, 1, 0),
		new_point(env->w / 3, env->h / 6), new_point(env->w / 3,
			3 * env->h / 4));
	if (env->options.show_fps)
		print_text(new_point(env->fps_option.pos.y, env->fps_option.pos.x +
			150), new_printable_text("ON", env->sdl.fonts.lato20,
			0x009246FF, 20), env);
	else
		print_text(new_point(env->fps_option.pos.y, env->fps_option.pos.x +
			150), new_printable_text("OFF", env->sdl.fonts.lato20,
			0xCC0000FF, 20), env);
}

void	print_music_vol(t_env *env)
{
	int w;
	int h;

	TTF_SizeText(env->sdl.fonts.lato30, "MUSIC", &w, &h);
	print_text(new_point(env->h_h +
		env->music_vol_up.size_down.y, env->h_w - w / 2),
		new_printable_text("MUSIC", env->sdl.fonts.lato30,
		0x222222FF, 30), env);
	ft_snprintf(env->snprintf, 4, "%.f",
		env->sound.music_vol * 100);
	TTF_SizeText(env->sdl.fonts.lato30, env->snprintf, &w, &h);
	print_text(new_point(env->h_h +
		env->music_vol_up.size_down.y + 35, env->h_w - w / 2),
		new_printable_text(env->snprintf, env->sdl.fonts.lato30,
		0x222222FF, 30), env);
}

void	print_sounds_vol(t_env *env)
{
	int w;
	int h;

	TTF_SizeText(env->sdl.fonts.lato30, "SOUNDS", &w, &h);
	print_text(new_point(env->h_h + env->h_h / 4 +
		env->sounds_vol_up.size_down.y, env->h_w - w / 2),
		new_printable_text("SOUNDS", env->sdl.fonts.lato30,
		0x222222FF, 30), env);
	ft_snprintf(env->snprintf, 4, "%.f",
		env->sound.ambient_vol * 100);
	TTF_SizeText(env->sdl.fonts.lato30, env->snprintf, &w, &h);
	print_text(new_point(env->h_h + env->h_h / 4 +
		env->sounds_vol_up.size_down.y + 35, env->h_w - w / 2),
		new_printable_text(env->snprintf, env->sdl.fonts.lato30,
		0x222222FF, 30), env);
}

void	draw_option_menu_ig_buttons(t_env *env)
{
	draw_button(env, env->return_button, "RETURN");
	draw_button(env, env->exit_button, "EXIT");
	draw_button(env, env->music_vol_up, NULL);
	draw_button(env, env->music_vol_down, NULL);
	draw_button(env, env->sounds_vol_up, NULL);
	draw_button(env, env->sounds_vol_down, NULL);
	draw_button(env, env->fps_option, "FPS");
}

void	option_menu_ig(t_env *env)
{
	clear_image(env);
	SDL_SetRelativeMouseMode(0);
	options_menu_hud(env);
	draw_option_menu_ig_buttons(env);
	print_music_vol(env);
	print_sounds_vol(env);
	while (SDL_PollEvent(&env->sdl.event))
	{
		if (env->sdl.event.type == SDL_QUIT ||
			(env->sdl.event.type == SDL_KEYUP &&
			env->sdl.event.key.keysym.sym == SDLK_ESCAPE))
			env->running = 0;
		update_inputs(env);
		if (env->sdl.event.type == SDL_MOUSEBUTTONUP)
			option_menu_ig_keyup(env);
		option_menu_ig_keys(env);
	}
	update_screen(env);
}

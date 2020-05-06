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
#include "draw.h"

int		print_music_vol(t_env *env)
{
	if (print_text(new_point(env->h_h +
		env->music_vol_up.size_down.y, env->h_w),
		new_printable_text("MUSIC", env->sdl.fonts.lato30,
		0xFFFFFFFF, 30), env))
		return (-1);
	ft_snprintf(env->snprintf, 4, "%.f",
		env->sound.music_vol * 100);
	if (print_text(new_point(env->h_h +
		env->music_vol_up.size_down.y + 35, env->h_w),
		new_printable_text(env->snprintf, env->sdl.fonts.lato30,
		0xFFFFFFFF, 30), env))
		return (-1);
	return (0);
}

int		print_sounds_vol(t_env *env)
{
	if (print_text(new_point(env->h_h + env->h_h / 4 +
		env->sounds_vol_up.size_down.y, env->h_w),
		new_printable_text("SOUNDS", env->sdl.fonts.lato30,
		0xFFFFFFFF, 30), env))
		return (-1);
	ft_snprintf(env->snprintf, 4, "%.f",
		env->sound.ambient_vol * 100);
	if (print_text(new_point(env->h_h + env->h_h / 4 +
		env->sounds_vol_up.size_down.y + 35, env->h_w),
		new_printable_text(env->snprintf, env->sdl.fonts.lato30,
		0xFFFFFFFF, 30), env))
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
	return (0);
}

int		option_menu_ig(t_env *env)
{
	clear_image(env);
	SDL_SetRelativeMouseMode(0);
	apply_surface(env->wall_textures[6].surface, new_point(0, 0),
		new_point(env->w, env->h), env);
	if (draw_option_menu_ig_buttons(env))
		return (-1);
	if (print_music_vol(env))
		return (-1);
	if (print_sounds_vol(env))
		return (-1);
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
	if (update_screen(env))
		return (-1);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   option_menu.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaerhard <gaerhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 16:18:10 by gaerhard          #+#    #+#             */
/*   Updated: 2020/03/09 11:20:27 by gaerhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

int		return_button_func(void	*target)
{
	t_env *env;

	env = (t_env*)target;
	env->option = 0;
	if (env->in_game)
		SDL_SetRelativeMouseMode(1);
	return (1);
}

int		music_volume_up(void *target)
{
	t_env *env;

	env = (t_env*)target;
	if (env->sound.music_vol <= 0.90)
	{
		FMOD_Channel_SetPaused(env->sound.music_chan,1);
		env->sound.music_vol += 0.1;
		FMOD_Channel_SetVolume(env->sound.music_chan, env->sound.music_vol);
		FMOD_Channel_SetPaused(env->sound.music_chan, 0);
	}
	return (1);
}

int		music_volume_down(void *target)
{
	t_env *env;

	env = (t_env*)target;
	if (env->sound.music_vol >= 0.10)
	{
		FMOD_Channel_SetPaused(env->sound.music_chan, 1);
		env->sound.music_vol -= 0.1;
		FMOD_Channel_SetVolume(env->sound.music_chan, env->sound.music_vol);
		FMOD_Channel_SetPaused(env->sound.music_chan, 0);
	}
	return (1);
}

int		sounds_volume_down(void *target)
{
	t_env *env;

	env = (t_env*)target;
	if (env->sound.ambient_vol >= 0.10)
	{
		FMOD_Channel_SetPaused(env->sound.player_shots_chan, 1);
		FMOD_Channel_SetPaused(env->sound.footstep_chan, 1);
		env->sound.ambient_vol -= 0.1;
		FMOD_Channel_SetVolume(env->sound.footstep_chan, env->sound.ambient_vol);
		FMOD_Channel_SetVolume(env->sound.player_shots_chan,
			env->sound.ambient_vol);
		FMOD_Channel_SetPaused(env->sound.footstep_chan, 0);
		FMOD_Channel_SetPaused(env->sound.player_shots_chan, 0);
	}
	return (1);
}

int		sounds_volume_up(void *target)
{
	t_env *env;

	env = (t_env*)target;
	if (env->sound.ambient_vol <= 0.90)
	{
		FMOD_Channel_SetPaused(env->sound.player_shots_chan, 1);
		FMOD_Channel_SetPaused(env->sound.footstep_chan, 1);
		env->sound.ambient_vol += 0.1;
		FMOD_Channel_SetVolume(env->sound.footstep_chan, env->sound.ambient_vol);
		FMOD_Channel_SetVolume(env->sound.player_shots_chan,
			env->sound.ambient_vol);
		FMOD_Channel_SetPaused(env->sound.footstep_chan, 0);
		FMOD_Channel_SetPaused(env->sound.player_shots_chan, 0);
	}
	return (1);
}

int		return_button(t_env *env)
{
	env->return_button = new_image_button(ON_RELEASE, &return_button_func,
		env, env);
	env->return_button.pos =
		new_point(env->h_w - env->start_game_button.size_down.x / 2,
		(env->h_h - env->start_game_button.size_down.y / 2) / 2);
	return (0);
}

int		music_vol_up_button(t_env *env)
{
	env->music_vol_up = new_add_button(ON_RELEASE,
		&music_volume_up, env, env);
	env->music_vol_up.pos = new_point(env->h_w + env->h_w / 4,
		env->h_h + env->music_vol_up.size_down.y);
	return (0);	
}

int		music_vol_down_button(t_env *env)
{
	env->music_vol_down = new_minus_button(ON_RELEASE,
		&music_volume_down, env, env);
	env->music_vol_down.pos = new_point(env->h_w - env->h_w / 4,
		env->h_h + env->music_vol_down.size_down.y);
	return (0);	
}

int		sounds_vol_up_button(t_env *env)
{
	env->sounds_vol_up = new_add_button(ON_RELEASE,
		&sounds_volume_up, env, env);
	env->sounds_vol_up.pos = new_point(env->h_w + env->h_w / 4,
		env->h_h + env->h_h / 4 + env->sounds_vol_up.size_down.y);
	return (0);	
}

int		sounds_vol_down_button(t_env *env)
{
	env->sounds_vol_down = new_minus_button(ON_RELEASE,
		&sounds_volume_down, env, env);
	env->sounds_vol_down.pos = new_point(env->h_w - env->h_w / 4,
		env->h_h + env->h_h / 4 + env->sounds_vol_down.size_down.y);
	return (0);	
}

void	print_music_vol(t_env *env)
{
	print_text(new_point(env->h_h +
		env->music_vol_up.size_down.y, env->h_w),
		new_printable_text("MUSIC", env->sdl.fonts.lato30,
		0xFFFFFFFF, 30), env);
	ft_snprintf(env->snprintf, 4, "%.f",
		env->sound.music_vol * 100);
	print_text(new_point(env->h_h +
		env->music_vol_up.size_down.y + 35, env->h_w),
		new_printable_text(env->snprintf, env->sdl.fonts.lato30,
		0xFFFFFFFF, 30), env);
}

void	print_sounds_vol(t_env *env)
{
	print_text(new_point(env->h_h + env->h_h / 4 +
		env->sounds_vol_up.size_down.y, env->h_w),
		new_printable_text("SOUNDS", env->sdl.fonts.lato30,
		0xFFFFFFFF, 30), env);
	ft_snprintf(env->snprintf, 4, "%.f",
		env->sound.ambient_vol * 100);
	print_text(new_point( env->h_h + env->h_h / 4 +
		env->sounds_vol_up.size_down.y + 35, env->h_w),
		new_printable_text(env->snprintf, env->sdl.fonts.lato30,
		0xFFFFFFFF, 30), env);
}

void	draw_option_menu_ig_buttons(t_env *env)
{
	draw_button(env, env->return_button, "RETURN");
	draw_button(env, env->exit_button, "EXIT");
	draw_button(env, env->music_vol_up, NULL);
	draw_button(env, env->music_vol_down, NULL);
	draw_button(env, env->sounds_vol_up, NULL);
	draw_button(env, env->sounds_vol_down, NULL);
}

void	option_menu_ig(t_env *env)
{
	clear_image(env);
	SDL_SetRelativeMouseMode(0);
	apply_surface(env->wall_textures[6].surface, new_point(0, 0),
		new_point(env->w, env->h), env);
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

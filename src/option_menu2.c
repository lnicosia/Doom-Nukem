/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   option_menu2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/30 17:45:54 by lnicosia          #+#    #+#             */
/*   Updated: 2020/05/23 20:52:15 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "draw.h"

int		return_button_func(void *target)
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
	t_env	*env;
	double	volume;

	env = (t_env*)target;
	volume = env->sound.music_vol * 100;
	if (volume <= 90)
	{
		if (FMOD_Channel_SetPaused(env->sound.music_chan, 1))
			return (custom_error("FMOD_Channel_SetPaused error\n"));
		volume += 10;
		env->sound.music_vol = volume / 100;
		if (FMOD_Channel_SetVolume(env->sound.music_chan,
			env->sound.music_vol) != FMOD_OK)
			return (custom_error("FMOD_Channel_SetVolume error\n"));
		if (FMOD_Channel_SetPaused(env->sound.music_chan, 0) != FMOD_OK)
			return (custom_error("FMOD_Channel_SetPaused error\n"));
	}
	return (1);
}

int		music_volume_down(void *target)
{
	t_env	*env;
	double	volume;

	env = (t_env*)target;
	volume = env->sound.music_vol * 100;
	if (volume >= 10)
	{
		if (FMOD_Channel_SetPaused(env->sound.music_chan, 1) != FMOD_OK)
			return (custom_error("FMOD_Channel_SetPaused error\n"));
		volume -= 10;
		env->sound.music_vol = volume / 100;
		if (FMOD_Channel_SetVolume(env->sound.music_chan,
			env->sound.music_vol) != FMOD_OK)
			return (custom_error("FMOD_Channel_SetVolume error\n"));
		if (FMOD_Channel_SetPaused(env->sound.music_chan, 0) != FMOD_OK)
			return (custom_error("FMOD_Channel_SetPaused error\n"));
	}
	return (1);
}

int		sounds_volume_down(void *target)
{
	t_env	*env;
	double	volume;

	env = (t_env*)target;
	volume = env->sound.ambient_vol * 100;
	if (volume >= 10)
	{
		if (pause_sounds_channels(env, 1))
			return (custom_error("Could not pause sound channels\n"));
		volume -= 10;
		env->sound.ambient_vol = volume / 100;
		if (set_volume_sounds(env))
			return (custom_error("Could not set volume of sound channels\n"));
		if (pause_sounds_channels(env, 0))
			return (custom_error("Could not pause sound channels\n"));
	}
	return (1);
}

int		sounds_volume_up(void *target)
{
	t_env	*env;
	double	volume;

	env = (t_env*)target;
	volume = env->sound.ambient_vol * 100;
	if (volume <= 90)
	{
		if (pause_sounds_channels(target, 1))
			return (custom_error("Could not pause sounds channels\n"));
		volume += 10;
		env->sound.ambient_vol = volume / 100;
		if (set_volume_sounds(env))
			return (custom_error("Could not set volume of sound channels\n"));
		if (pause_sounds_channels(env, 0))
			return (custom_error("Could not pause sounds channels\n"));
	}
	return (1);
}

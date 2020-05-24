/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   option_menu2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/30 17:45:54 by lnicosia          #+#    #+#             */
/*   Updated: 2020/04/30 17:45:55 by lnicosia         ###   ########.fr       */
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
	t_env *env;

	env = (t_env*)target;
	if (env->sound.music_vol <= 0.90)
	{
		env->sound.music_vol += 0.1;
		if (FMOD_Channel_SetPaused(env->sound.music_chan, 1))
			return (custom_error("FMOD_Channel_SetPaused error\n"));
		if (FMOD_Channel_SetVolume(env->sound.music_chan, env->sound.music_vol))
			return (custom_error("FMOD_Channel_SetVolume error\n"));
		if (FMOD_Channel_SetPaused(env->sound.music_chan, 0))
			return (custom_error("FMOD_Channel_SetPaused error\n"));
	}
	return (1);
}

int		music_volume_down(void *target)
{
	t_env *env;

	env = (t_env*)target;
	if (env->sound.music_vol >= 0.10)
	{
		if (FMOD_Channel_SetPaused(env->sound.music_chan, 1))
			return (custom_error("FMOD_Channel_SetPaused error\n"));
		env->sound.music_vol -= 0.1;
		if (FMOD_Channel_SetVolume(env->sound.music_chan, env->sound.music_vol))
			return (custom_error("FMOD_Channel_SetVolume error\n"));
		if (FMOD_Channel_SetPaused(env->sound.music_chan, 0))
			return (custom_error("FMOD_Channel_SetPaused error\n"));
	}
	return (1);
}

int		sounds_volume_down(void *target)
{
	t_env *env;

	env = (t_env*)target;
	if (env->sound.ambient_vol >= 0.10)
	{
		if (FMOD_Channel_SetPaused(env->sound.player_shots_chan, 1))
			return (custom_error("FMOD_Channel_SetPaused error\n"));
		if (FMOD_Channel_SetPaused(env->sound.footstep_chan, 1))
			return (custom_error("FMOD_Channel_SetPaused error\n"));
		env->sound.ambient_vol -= 0.1;
		if (FMOD_Channel_SetVolume(env->sound.footstep_chan,
			env->sound.ambient_vol))
			return (custom_error("FMOD_Channel_SetVolume error\n"));
		if (FMOD_Channel_SetVolume(env->sound.player_shots_chan,
			env->sound.ambient_vol))
			return (custom_error("FMOD_Channel_SetVolume error\n"));
		if (FMOD_Channel_SetPaused(env->sound.footstep_chan, 0))
			return (custom_error("FMOD_Channel_SetPaused error\n"));
		if (FMOD_Channel_SetPaused(env->sound.player_shots_chan, 0))
			return (custom_error("FMOD_Channel_SetPaused error\n"));
	}
	return (1);
}

int		sounds_volume_up(void *target)
{
	t_env *env;

	env = (t_env*)target;
	if (env->sound.ambient_vol <= 0.90)
	{
		if (FMOD_Channel_SetPaused(env->sound.player_shots_chan, 1))
			return (custom_error("FMOD_Channel_SetPaused error\n"));
		if (FMOD_Channel_SetPaused(env->sound.footstep_chan, 1))
			return (custom_error("FMOD_Channel_SetPaused error\n"));
		env->sound.ambient_vol += 0.1;
		if (FMOD_Channel_SetVolume(env->sound.footstep_chan,
			env->sound.ambient_vol))
			return (custom_error("FMOD_Channel_SetVolume error\n"));
		if (FMOD_Channel_SetVolume(env->sound.player_shots_chan,
			env->sound.ambient_vol))
			return (custom_error("FMOD_Channel_SetVolume error\n"));
		if (FMOD_Channel_SetPaused(env->sound.footstep_chan, 0))
			return (custom_error("FMOD_Channel_SetPaused error\n"));
		if (FMOD_Channel_SetPaused(env->sound.player_shots_chan, 0))
			return (custom_error("FMOD_Channel_SetPaused error\n"));
	}
	return (1);
}

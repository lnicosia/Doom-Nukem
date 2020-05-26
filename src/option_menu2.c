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
	return (0);
}

int		music_volume_up(void *target)
{
	t_env	*env;
	float	volume;

	env = (t_env*)target;
	volume = env->sound.music_vol * 100;
	if ((int)volume <= 90)
	{
		volume += 10;
		env->sound.music_vol = volume / 100;
		if (change_volume_if_playing(env->sound.music_chan,
			env->sound.music_vol) != FMOD_OK)
			return (custom_error("Could not change music volume\n"));
	}
	return (0);
}

int		music_volume_down(void *target)
{
	t_env	*env;
	float	volume;

	env = (t_env*)target;
	volume = env->sound.music_vol * 100;
	if ((int)volume >= 10)
	{
		volume -= 10;
		env->sound.music_vol = volume / 100;
		if (change_volume_if_playing(env->sound.music_chan,
			env->sound.music_vol) != FMOD_OK)
			return (custom_error("Could not change music volume\n"));
	}
	return (0);
}

int		sounds_volume_down(void *target)
{
	t_env	*env;
	float	volume;

	env = (t_env*)target;
	volume = env->sound.ambient_vol * 100;
	if ((int)volume >= 10)
	{
		volume -= 10;
		env->sound.ambient_vol = volume / 100;
	}
	return (0);
}

int		sounds_volume_up(void *target)
{
	t_env	*env;
	float	volume;

	env = (t_env*)target;
	volume = env->sound.ambient_vol * 100;
	if ((int)volume <= 90)
	{
		volume += 10;
		env->sound.ambient_vol = volume / 100;
	}
	return (0);
}

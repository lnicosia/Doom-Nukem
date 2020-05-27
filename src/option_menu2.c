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

int		restart_music(t_env *env)
{
	if (env->player.in_combat == 0)
	{
		if (play_music(env, &env->sound.music_chan,
			env->sound.musics[env->sound.ambient_music].music,
			env->sound.music_vol))
			return (custom_error("Could not launch ambient music\n"));
	}
	else
	{
		if (play_music(env, &env->sound.music_chan,
			env->sound.musics[env->sound.fight_music].music,
			env->sound.music_vol))
			return (custom_error("Could not launch fight music\n"));
	}
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
			env->sound.music_vol))
			return (custom_error("Could not change music volume\n"));
		if ((int)volume == 10)
		{
			if (restart_music(env))
				return (-1);
		}
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
			env->sound.music_vol))
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
		if (change_sounds_volume(env->sound.ambient_vol, env))
			return (custom_error("Could not change sounds volume\n"));
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
		if (change_sounds_volume(env->sound.ambient_vol, env))
			return (custom_error("Could not change sounds volume\n"));
	}
	return (0);
}

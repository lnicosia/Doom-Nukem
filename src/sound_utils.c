/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sound_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaerhard <gaerhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 11:53:54 by gaerhard          #+#    #+#             */
/*   Updated: 2020/03/04 11:00:17 by gaerhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

void	play_sound(t_env *env, FMOD_CHANNEL **chan, FMOD_SOUND *sound, float v)
{
	FMOD_BOOL is_playing;

	if (FMOD_Channel_IsPlaying(*chan, &is_playing) != FMOD_OK)
	{
		FMOD_System_PlaySound(env->sound.system, sound, 0, 0, chan);
		FMOD_Channel_SetVolume(*chan, v);
	}
}

void	play_music(t_env *env, FMOD_CHANNEL **chan, FMOD_SOUND *music, float v)
{
	FMOD_Channel_SetPaused(*chan, 1);
	FMOD_System_PlaySound(env->sound.system, music, 0, 0, chan);
	FMOD_Channel_SetVolume(*chan, v);
	FMOD_Channel_SetPaused(*chan, 0);
}

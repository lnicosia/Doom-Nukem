/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sound_misc_functions.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/23 20:22:18 by user42            #+#    #+#             */
/*   Updated: 2020/05/23 20:52:12 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "init.h"

int		change_volume_if_playing(FMOD_CHANNEL *channel, float volume)
{
	FMOD_BOOL	is_playing;
	int			err;

	if ((err = FMOD_Channel_IsPlaying(channel, &is_playing)) != FMOD_OK
		|| is_playing == 0)
		return (0);
	if ((err = FMOD_Channel_SetPaused(channel, 1)) != FMOD_OK)
		return (custom_error("FMOD_Channel_SetPaused error %d\n", err));
	if ((err = FMOD_Channel_SetVolume(channel, volume)) != FMOD_OK)
		return (custom_error("FMOD_Channel_SetVolume error %d\n", err));
	if ((err = FMOD_Channel_SetPaused(channel, 0)) != FMOD_OK)
		return (custom_error("FMOD_Channel_SetPaused error %d\n", err));
	return (0);
}

int		change_sounds_volume(float volume, t_env *env)
{
	if (change_volume_if_playing(env->sound.player_shots_chan, volume))
		return (custom_error("Could not update player shots chan volume\n"));
	if (change_volume_if_playing(env->sound.footstep_chan, volume))
		return (custom_error("Could not update footstep chan volume\n"));
	if (change_volume_if_playing(env->sound.player_movement_chan, volume))
		return (custom_error("Could not update player movement chan volume\n"));
	if (change_volume_if_playing(env->sound.player_reaction_chan, volume))
		return (custom_error("Could not update player reaction chan volume\n"));
	if (change_volume_if_playing(env->sound.enemies_reaction_chan, volume))
		return (custom_error("Could not update ennemies reactions"
		" chan volume\n"));
	if (change_volume_if_playing(env->sound.enemies_shots_chan, volume))
		return (custom_error("Could not update ennemies shots chan volume\n"));
	if (change_volume_if_playing(env->sound.explosions_chan, volume))
		return (custom_error("Could not update explosions chan volume\n"));
	return (0);
}

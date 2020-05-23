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

int     pause_sounds_channels(void *target, int mode)
{
    t_env *env;

    env = (t_env*)target;
	if (FMOD_Channel_SetPaused(env->sound.player_shots_chan, mode) != FMOD_OK)
		return (custom_error("FMOD_Channel_SetPaused error\n"));
	if (FMOD_Channel_SetPaused(env->sound.footstep_chan, mode) != FMOD_OK)
		return (custom_error("FMOD_Channel_SetPaused error\n")); 
	if (FMOD_Channel_SetPaused(env->sound.player_movement_chan, mode) !=
        FMOD_OK)
		return (custom_error("FMOD_Channel_SetPaused error\n"));
	if (FMOD_Channel_SetPaused(env->sound.player_reaction_chan, mode) !=
        FMOD_OK)
		return (custom_error("FMOD_Channel_SetPaused error\n"));
	if (FMOD_Channel_SetPaused(env->sound.enemies_reaction_chan, mode) !=
        FMOD_OK)
		return (custom_error("FMOD_Channel_SetPaused error\n"));
	if (FMOD_Channel_SetPaused(env->sound.enemies_shots_chan, mode) !=
        FMOD_OK)
		return (custom_error("FMOD_Channel_SetPaused error\n"));
	if (FMOD_Channel_SetPaused(env->sound.explosions_chan, mode) != FMOD_OK)
		return (custom_error("FMOD_Channel_SetPaused error\n"));
    return (0);
}

int     set_volume_sounds(t_env *env)
{
	if (FMOD_Channel_SetVolume(env->sound.footstep_chan,
		env->sound.ambient_vol) != FMOD_OK)
		return (custom_error("FMOD_Channel_SetVolume error\n"));
	if (FMOD_Channel_SetVolume(env->sound.player_shots_chan,
		env->sound.ambient_vol) != FMOD_OK)
		return (custom_error("FMOD_Channel_SetVolume error\n"));
	if (FMOD_Channel_SetVolume(env->sound.player_movement_chan,
		env->sound.ambient_vol) != FMOD_OK)
		return (custom_error("FMOD_Channel_SetVolume error\n"));
	if (FMOD_Channel_SetVolume(env->sound.player_reaction_chan,
		env->sound.ambient_vol) != FMOD_OK)
		return (custom_error("FMOD_Channel_SetVolume error\n"));
	if (FMOD_Channel_SetVolume(env->sound.enemies_shots_chan,
		env->sound.ambient_vol) != FMOD_OK)
		return (custom_error("FMOD_Channel_SetVolume error\n"));
	if (FMOD_Channel_SetVolume(env->sound.enemies_reaction_chan,
		env->sound.ambient_vol) != FMOD_OK)
		return (custom_error("FMOD_Channel_SetVolume error\n"));
	if (FMOD_Channel_SetVolume(env->sound.explosions_chan,
		env->sound.ambient_vol) != FMOD_OK)
		return (custom_error("FMOD_Channel_SetVolume error\n"));
    return (0);
}
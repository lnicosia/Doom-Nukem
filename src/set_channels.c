/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_channels.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 10:56:57 by gaerhard          #+#    #+#             */
/*   Updated: 2020/05/20 16:46:35 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

int	set_channels2(t_env *env)
{
	int		err;

	if ((err = FMOD_System_GetChannel(env->sound.system, 7,
		&env->sound.explosions_chan)) != FMOD_OK)
		return (custom_error("Could not set channel 7. Error %d\n", err));
	return (0);
}

int	set_channels(t_env *env)
{
	int		err;

	if ((err = FMOD_System_GetChannel(env->sound.system, 0,
		&env->sound.music_chan)) != FMOD_OK)
		return (custom_error("Could not set channel 0. Error %d\n", err));
	if ((err = FMOD_System_GetChannel(env->sound.system, 1,
		&env->sound.player_movement_chan)) != FMOD_OK)
		return (custom_error("Could not set channel 1. Error %d\n", err));
	if ((err = FMOD_System_GetChannel(env->sound.system, 2,
		&env->sound.player_reaction_chan)) != FMOD_OK)
		return (custom_error("Could not set channel 2. Error %d\n", err));
	if ((err = FMOD_System_GetChannel(env->sound.system, 3,
		&env->sound.player_shots_chan)) != FMOD_OK)
		return (custom_error("Could not set channel 3. Error %d\n", err));
	if ((err = FMOD_System_GetChannel(env->sound.system, 4,
		&env->sound.enemies_reaction_chan)) != FMOD_OK)
		return (custom_error("Could not set channel 4. Error %d\n", err));
	if ((err = FMOD_System_GetChannel(env->sound.system, 5,
		&env->sound.enemies_shots_chan)) != FMOD_OK)
		return (custom_error("Could not set channel 5. Error %d\n", err));
	if ((err = FMOD_System_GetChannel(env->sound.system, 6,
		&env->sound.footstep_chan)) != FMOD_OK)
		return (custom_error("Could not set channel 6. Error %d\n", err));
	return (set_channels2(env));
}

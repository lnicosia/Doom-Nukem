/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   init_sound.c									   :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: gaerhard <gaerhard@student.42.fr>		  +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2019/06/13 15:13:11 by gaerhard		  #+#	#+#			 */
/*   Updated: 2019/07/24 15:00:05 by sipatry		  ###   ########.fr	   */
/*						                                                    */
/* ************************************************************************** */

#include "env.h"

int     init_sound(t_env *env)
{
	if (FMOD_System_Create(&env->sound.system) != FMOD_OK)
		return (ft_printf("Failed to create fmod system\n"));
	if (FMOD_System_Init(env->sound.system, 42, FMOD_INIT_NORMAL, NULL) != FMOD_OK)
		return (ft_printf("Could not Init fmod system\n"));
	if (FMOD_System_CreateSound(env->sound.system, "audio/shotgun_shot.wav",
		FMOD_CREATESAMPLE, 0, &env->weapons[0].shot) != FMOD_OK)
		return (ft_printf("Failed to load shotgun_shot.wav with FMOD lib"));
	if (FMOD_System_CreateSound(env->sound.system, "audio/raygun_shot.wav",
		FMOD_CREATESAMPLE, 0, &env->weapons[1].shot) != FMOD_OK)
		return (ft_printf("Failed to load raygun_shot.wav with FMOD lib"));
	if (FMOD_System_CreateSound(env->sound.system, "audio/at_dooms_gate.wav",
		FMOD_2D | FMOD_CREATESTREAM | FMOD_LOOP_NORMAL, 0, &env->sound.at_dooms_gate) != FMOD_OK)
		return (ft_printf("Failed to load at_dooms_gate.wav with FMOD lib"));
	FMOD_Sound_SetLoopCount(env->sound.at_dooms_gate, -1);
	env->sound.b_jump = 20;
	env->sound.b_footstep = 20;
	env->sound.b_weapon = 20;
	env->sound.g_music = 100;
    /*if (Mix_OpenAudio(MIX_DEFAULT_FREQUENCY, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024) == -1)
		return (ft_printf("SDL_OpenAudio error %s\n", Mix_GetError()));
	if(!(env->sound.background = Mix_LoadMUS("audio/at_dooms_gate.wav")))
    	return (ft_printf("Failed to load Music %s\n", Mix_GetError()));
	Mix_AllocateChannels(3);
	if (!(env->sound.footstep = Mix_LoadWAV("audio/footstep.wav")))
		return (ft_printf("Failed to load footstep.wav %s\n", Mix_GetError()));
	if (!(env->sound.jump = Mix_LoadWAV("audio/jump.wav")))
		return (ft_printf("Failed to load jump.wav %s\n", Mix_GetError()));
	if (!(env->weapons[0].sound = Mix_LoadWAV("audio/shotgun_shot.wav")))
		return (ft_printf("Failed to load shotgun_shot.wav %s\n", Mix_GetError()));
	if (!(env->weapons[0].empty = Mix_LoadWAV("audio/shotgun_no_ammo.wav")))
		return (ft_printf("Failed to load raygun_shot.wav %s\n", Mix_GetError()));
	if (!(env->weapons[1].sound = Mix_LoadWAV("audio/raygun_shot.wav")))
		return (ft_printf("Failed to load raygun_shot.wav %s\n", Mix_GetError()));
	if (!(env->weapons[1].empty = Mix_LoadWAV("audio/shotgun_no_ammo.wav")))
		return (ft_printf("Failed to load shotgun_no_ammo.wav %s\n", Mix_GetError()));
	Mix_VolumeChunk(env->sound.jump, MIX_MAX_VOLUME / env->sound.b_jump);
	Mix_VolumeChunk(env->sound.footstep, MIX_MAX_VOLUME / env->sound.b_footstep);
	Mix_VolumeChunk(env->weapons[0].sound, MIX_MAX_VOLUME / env->sound.b_weapon);
	Mix_VolumeChunk(env->weapons[1].sound, MIX_MAX_VOLUME / env->sound.b_weapon);*/
    return (0);
}

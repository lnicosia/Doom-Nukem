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
	env->sound.b_jump = 20;
	env->sound.b_footstep = 20;
	env->sound.b_weapon = 20;
	env->sound.g_music = 100;
    if (Mix_OpenAudio(MIX_DEFAULT_FREQUENCY, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024) == -1)
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
		return (ft_printf("Failed to load raygun_shot.wav %s\n", Mix_GetError()));
	Mix_VolumeChunk(env->sound.jump, MIX_MAX_VOLUME / env->sound.b_jump);
	Mix_VolumeChunk(env->sound.footstep, MIX_MAX_VOLUME / env->sound.b_footstep);
	Mix_VolumeChunk(env->weapons[0].sound, MIX_MAX_VOLUME / env->sound.b_weapon);
	Mix_VolumeChunk(env->weapons[1].sound, MIX_MAX_VOLUME / env->sound.b_weapon);
    return (0);
}

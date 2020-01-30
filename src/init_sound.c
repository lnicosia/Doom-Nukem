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
		return (ft_printf("Failed to load shotgun_shot.wav"));
	if (FMOD_System_CreateSound(env->sound.system, "audio/raygun_shot.wav",
		FMOD_CREATESAMPLE, 0, &env->weapons[1].shot) != FMOD_OK)
		return (ft_printf("Failed to load raygun_shot.wav"));
	if (FMOD_System_CreateSound(env->sound.system, "audio/at_dooms_gate.wav",
		FMOD_2D | FMOD_CREATESTREAM | FMOD_LOOP_NORMAL, 0, &env->sound.at_dooms_gate) != FMOD_OK)
		return (ft_printf("Failed to load at_dooms_gate.wav"));
	FMOD_Sound_SetLoopCount(env->sound.at_dooms_gate, -1);
	if (FMOD_System_CreateSound(env->sound.system, "audio/footstep.wav",
		FMOD_CREATESAMPLE, 0, &env->sound.footstep) != FMOD_OK)
		return (ft_printf("Failed to load footsteps.wav\n"));
	env->sound.music_vol = 0.3;
	env->sound.ambient_vol = 0.3;
    return (0);
}

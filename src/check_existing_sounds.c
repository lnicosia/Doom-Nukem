/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_existing_sounds.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/29 13:14:58 by marvin            #+#    #+#             */
/*   Updated: 2020/04/29 13:14:58 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
/*
int     check_sounds(t_env *env)
{
    if (env->init.musics[0] && FMOD_System_CreateSound(env->sound.system, "audio/Mt_Erebus.wav",
		FMOD_2D | FMOD_CREATESTREAM | FMOD_LOOP_NORMAL, 0,
		&env->sound.musics[0].music) != FMOD_OK)
		return (custom_error("Failed to load Mt_Erebus.wav"));
	if (env->init.musics[1] && FMOD_System_CreateSound(env->sound.system, "audio/bim_bam_boum.wav",
		FMOD_2D | FMOD_CREATESTREAM | FMOD_LOOP_NORMAL, 0,
		&env->sound.musics[1].music) != FMOD_OK)
		return (custom_error("Failed to load bim_bam_boum.wav"));
	if (env->init.musics[2] && FMOD_System_CreateSound(env->sound.system, "audio/at_dooms_gate.wav",
		FMOD_2D | FMOD_CREATESTREAM | FMOD_LOOP_NORMAL, 0,
		&env->sound.musics[2].music) != FMOD_OK)
		return (custom_error("Failed to load at_dooms_gate.wav"));
    if (env->init.sounds[0] && FMOD_System_CreateSound(env->sound.system, "audio/handgun_shot.wav",
		FMOD_CREATESAMPLE, 0, &env->weapons[0].shot) != FMOD_OK)//Should be a gun shot
		return (custom_error("Failed to load handgun_shot.wav\n"));
	if (env->init.sounds[1] && FMOD_System_CreateSound(env->sound.system, "audio/shotgun_shot.wav",
		FMOD_CREATESAMPLE, 0, &env->weapons[1].shot) != FMOD_OK)
		return (custom_error("Failed to load shotgun_shot.wav\n"));
	if (env->init.sounds[2] && FMOD_System_CreateSound(env->sound.system, "audio/raygun_shot.wav",
		FMOD_CREATESAMPLE, 0, &env->weapons[2].shot) != FMOD_OK)
		return (custom_error("Failed to load raygun_shot.wav\n"));
	if (env->init.sounds[3] && FMOD_System_CreateSound(env->sound.system, "audio/footstep.wav",
		FMOD_CREATESAMPLE, 0, &env->sound.footstep) != FMOD_OK)
		return (custom_error("Failed to load footsteps.wav\n"));
    return (0);
}
*/
int     check_existing_sounds(t_env *env, char *name)
{
    int i;

    i = 0;
    (void)env;
    (void)i;
    (void)name;
 /*   while (i < NB_SOUNDS)
    {
        if (!(ft_strcmp(name, env->init.sounds_names[i]))
        && env->init.sounds[i] == 1)
            return (1);
        i++;
    }*/
    return (0);
}

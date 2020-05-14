/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_audio.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipatry <sipatry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 10:56:57 by gaerhard          #+#    #+#             */
/*   Updated: 2020/03/11 19:11:33 by sipatry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

int		init_musics(t_env *env)
{
	int	i;

	i = 0;
	 if (FMOD_System_CreateSound(env->sound.system, "audio/Mt_Erebus.wav",
		FMOD_2D | FMOD_CREATESTREAM | FMOD_LOOP_NORMAL, 0,
		&env->sound.musics[0].music) != FMOD_OK)
		return (custom_error("Failed to load Mt_Erebus.wav"));
	if (FMOD_System_CreateSound(env->sound.system, "audio/bim_bam_boum.wav",
		FMOD_2D | FMOD_CREATESTREAM | FMOD_LOOP_NORMAL, 0,
		&env->sound.musics[1].music) != FMOD_OK)
		return (custom_error("Failed to load bim_bam_boum.wav"));
	if (FMOD_System_CreateSound(env->sound.system, "audio/at_dooms_gate.wav",
		FMOD_2D | FMOD_CREATESTREAM | FMOD_LOOP_NORMAL, 0,
		&env->sound.musics[2].music) != FMOD_OK)
		return (custom_error("Failed to load at_dooms_gate.wav"));
	while (++i < NB_MUSICS)
		FMOD_Sound_SetLoopCount(env->sound.musics[i].music, -1);
	return (0);
}

int     init_sounds(t_env *env)
{
   
    if (FMOD_System_CreateSound(env->sound.system, "audio/handgun_shot.wav",
		FMOD_CREATESAMPLE, 0, &env->weapons[0].shot) != FMOD_OK)
		return (custom_error("Failed to load handgun_shot.wav\n"));
	if (FMOD_System_CreateSound(env->sound.system, "audio/shotgun_shot.wav",
		FMOD_CREATESAMPLE, 0, &env->weapons[1].shot) != FMOD_OK)
		return (custom_error("Failed to load shotgun_shot.wav\n"));
	if (FMOD_System_CreateSound(env->sound.system, "audio/raygun_shot.wav",
		FMOD_CREATESAMPLE, 0, &env->weapons[2].shot) != FMOD_OK)
		return (custom_error("Failed to load raygun_shot.wav\n"));
	if (FMOD_System_CreateSound(env->sound.system, "audio/footstep.wav",
		FMOD_CREATESAMPLE, 0, &env->sound.footstep) != FMOD_OK)
		return (custom_error("Failed to load footsteps.wav\n"));
    return (0);
}

int		init_audio(t_env *env)
{
	if (FMOD_System_Create(&env->sound.system) != FMOD_OK)
		return (custom_error("Failed to create fmod system\n"));
	if (FMOD_System_Init(env->sound.system, 42, FMOD_INIT_NORMAL, NULL)
		!= FMOD_OK)
		return (custom_error("Could not Init fmod system\n"));
	if (init_musics(env) != 0)
		return (custom_error("Could not init musics\n"));
	if (init_sounds(env) != 0)
		return (custom_error("Could not init sounds\n"));
	env->sound.music_vol = 0.3;
	env->sound.ambient_vol = 0.3;
	env->sound.ambient_music = 0;
	env->sound.musics[0].music_name = "Mt Erebus";
	env->sound.musics[1].music_name = "Bim Bam Boum";
	env->sound.musics[2].music_name = "At Dooms Gate";
	env->sound.fight_music = 0;
	return (0);
}

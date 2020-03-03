/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sound_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaerhard <gaerhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 11:53:54 by gaerhard          #+#    #+#             */
/*   Updated: 2020/03/03 16:46:27 by gaerhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

void	play_sound(t_env *env, FMOD_CHANNEL **chan, FMOD_SOUND *sound, float vol)
{
	FMOD_BOOL is_playing;

	if (FMOD_Channel_IsPlaying(*chan, &is_playing) != FMOD_OK)
	{
		FMOD_System_PlaySound(env->sound.system, sound, 0, 0, chan);
		FMOD_Channel_SetVolume(*chan, vol);
	}
}

void	play_music(t_env *env, FMOD_CHANNEL **chan, FMOD_SOUND *music, float vol)
{
	FMOD_Channel_SetPaused(*chan, 1);
	FMOD_System_PlaySound(env->sound.system, music, 0, 0, chan);
	FMOD_Channel_SetVolume(*chan, vol);
	FMOD_Channel_SetPaused(*chan, 0);
}

int		init_sound(t_env *env)
{
	int i;

	i = 0;
	if (FMOD_System_Create(&env->sound.system) != FMOD_OK)
		return (ft_printf("Failed to create fmod system\n"));
	if (FMOD_System_Init(env->sound.system, 42, FMOD_INIT_NORMAL, NULL)
		!= FMOD_OK)
		return (ft_printf("Could not Init fmod system\n"));
	if (FMOD_System_CreateSound(env->sound.system, "audio/shotgun_shot.wav",
		FMOD_CREATESAMPLE, 0, &env->weapons[0].shot) != FMOD_OK)
		return (ft_printf("Failed to load shotgun_shot.wav"));
	if (FMOD_System_CreateSound(env->sound.system, "audio/raygun_shot.wav",
		FMOD_CREATESAMPLE, 0, &env->weapons[1].shot) != FMOD_OK)
		return (ft_printf("Failed to load raygun_shot.wav"));
	if (FMOD_System_CreateSound(env->sound.system, "audio/Mt_Erebus.wav",
		FMOD_2D | FMOD_CREATESTREAM | FMOD_LOOP_NORMAL, 0,
		&env->sound.musics[0].music) != FMOD_OK)
		return (ft_printf("Failed to load Mt_Erebus.wav"));
	if (FMOD_System_CreateSound(env->sound.system, "audio/bim_bam_boum.wav",
		FMOD_2D | FMOD_CREATESTREAM | FMOD_LOOP_NORMAL, 0,
		&env->sound.musics[1].music) != FMOD_OK)
		return (ft_printf("Failed to load bim_bam_boum.wav"));
	if (FMOD_System_CreateSound(env->sound.system, "audio/at_dooms_gate.wav",
		FMOD_2D | FMOD_CREATESTREAM | FMOD_LOOP_NORMAL, 0,
		&env->sound.musics[2].music) != FMOD_OK)
		return (ft_printf("Failed to load at_dooms_gate.wav"));
	while (++i < NB_MUSICS)
		FMOD_Sound_SetLoopCount(env->sound.musics[i].music, -1);
	if (FMOD_System_CreateSound(env->sound.system, "audio/footstep.wav",
		FMOD_CREATESAMPLE, 0, &env->sound.footstep) != FMOD_OK)
		return (ft_printf("Failed to load footsteps.wav\n"));
	env->sound.music_vol = 0.3;
	env->sound.ambient_vol = 0.3;
	env->sound.ambient_music = 0;
	env->sound.musics[0].music_name = "Mt Erebus";
	env->sound.musics[1].music_name = "Bim Bam Boum";
	env->sound.musics[2].music_name = "At Dooms Gate";
	env->sound.fight_music = 0;
	return (0);
}

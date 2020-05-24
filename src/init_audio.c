/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_audio.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 10:56:57 by gaerhard          #+#    #+#             */
/*   Updated: 2020/05/20 16:46:35 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

int	init_musics(t_env *env)
{
	int	i;

	i = 0;
	if (FMOD_System_CreateSound(env->sound.system, "audio/Mt_Erebus.wav",
		FMOD_2D | FMOD_CREATESTREAM | FMOD_LOOP_NORMAL, 0,
		&env->sound.musics[0].music) != FMOD_OK)
		return (custom_error("Failed to load Mt_Erebus.wav\n"));
	if (FMOD_System_CreateSound(env->sound.system, "audio/bim_bam_boum.wav",
		FMOD_2D | FMOD_CREATESTREAM | FMOD_LOOP_NORMAL, 0,
		&env->sound.musics[1].music) != FMOD_OK)
		return (custom_error("Failed to load bim_bam_boum.wav\n"));
	if (FMOD_System_CreateSound(env->sound.system, "audio/at_dooms_gate.wav",
		FMOD_2D | FMOD_CREATESTREAM | FMOD_LOOP_NORMAL, 0,
		&env->sound.musics[2].music) != FMOD_OK)
		return (custom_error("Failed to load at_dooms_gate.wav\n"));
	while (++i < NB_MUSICS)
	{
		if (FMOD_Sound_SetLoopCount(env->sound.musics[i].music, -1) != FMOD_OK)
			return (custom_error("FMOD_Sound_SetLoopCount error\n"));
	}
	return (0);
}

int	init_sounds2(t_env *env)
{
	if (FMOD_System_CreateSound(env->sound.system, "audio/player_death.wav",
		FMOD_CREATESAMPLE, 0, &env->sound.player_death) != FMOD_OK)
		return (custom_error("Failed to load player death sound\n"));
	if (FMOD_System_CreateSound(env->sound.system, "audio/cyberdemon_death.wav",
		FMOD_CREATESAMPLE, 0, &env->sound.cyberdemon_death) != FMOD_OK)
		return (custom_error("Failed to load cyberdemon death sound\n"));
	if (FMOD_System_CreateSound(env->sound.system, "audio/lost_soul_death.wav",
		FMOD_CREATESAMPLE, 0, &env->sound.lost_soul_death) != FMOD_OK)
		return (custom_error("Failed to load lost soul death sound\n"));
	if (FMOD_System_CreateSound(env->sound.system, "audio/lost_soul_attack.wav",
		FMOD_CREATESAMPLE, 0, &env->sound.lost_soul_attack) != FMOD_OK)
		return (custom_error("Failed to load lost soul attack sound\n"));
	if (FMOD_System_CreateSound(env->sound.system, "audio/monster_hit.wav",
		FMOD_CREATESAMPLE, 0, &env->sound.monster_hit) != FMOD_OK)
		return (custom_error("Failed to load monster hit sound\n"));
	if (FMOD_System_CreateSound(env->sound.system, "audio/monster_nearby.wav",
		FMOD_CREATESAMPLE, 0, &env->sound.monster_nearby) != FMOD_OK)
		return (custom_error("Failed to load monster nearby sound\n"));
	if (FMOD_System_CreateSound(env->sound.system, "audio/explosion.wav",
		FMOD_CREATESAMPLE, 0, &env->sound.explosion) != FMOD_OK)
		return (custom_error("Failed to load explosion sound\n"));
	return (0);
}

int	init_sounds(t_env *env)
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
	if (FMOD_System_CreateSound(env->sound.system,
		"audio/rocket_launcher_shot.wav",
		FMOD_CREATESAMPLE, 0, &env->weapons[3].shot) != FMOD_OK)
		return (custom_error("Failed to load rocket launcher\n"));
	if (FMOD_System_CreateSound(env->sound.system, "audio/gatling_shot.wav",
		FMOD_CREATESAMPLE, 0, &env->weapons[4].shot) != FMOD_OK)
		return (custom_error("Failed to load gatling shot\n"));
	if (FMOD_System_CreateSound(env->sound.system, "audio/footstep.wav",
		FMOD_CREATESAMPLE, 0, &env->sound.footstep) != FMOD_OK)
		return (custom_error("Failed to load footsteps.wav\n"));
	if (FMOD_System_CreateSound(env->sound.system, "audio/player_hit.wav",
		FMOD_CREATESAMPLE, 0, &env->sound.player_hit) != FMOD_OK)
		return (custom_error("Failed to load player hit sound\n"));
	return (init_sounds2(env));
}

int	init_audio(t_env *env)
{
	if (FMOD_System_Create(&env->sound.system) != FMOD_OK)
		return (custom_error("Failed to create fmod system\n"));
	if (FMOD_System_Init(env->sound.system, 32, FMOD_INIT_NORMAL, NULL)
		!= FMOD_OK)
		return (custom_error("Could not Init fmod system\n"));
	if (init_musics(env) != 0)
		return (custom_error("Could not init musics\n"));
	if (init_sounds(env) != 0)
		return (custom_error("Could not init sounds\n"));
	env->sound.music_vol = 0.3;
	env->sound.ambient_vol = 0.3;
	env->sound.musics[0].music_name = "Mt Erebus";
	env->sound.musics[1].music_name = "Bim Bam Boum";
	env->sound.musics[2].music_name = "At Dooms Gate";
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all5.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/21 19:53:05 by marvin            #+#    #+#             */
/*   Updated: 2020/05/21 20:03:20 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "free.h"

void	free_audio4(t_env *env)
{
	int i;

	i = 0;
	while (i < NB_MUSICS)
	{
		if (env->sound.musics[i].music)
		{
			if (FMOD_Sound_Release(env->sound.musics[i].music))
				custom_error("FMOD_Sound_Relase error\n");
		}
		i++;
	}
}

void	free_audio3(t_env *env)
{
	if (env->sound.monster_nearby)
	{
		if (FMOD_Sound_Release(env->sound.monster_nearby))
			custom_error("FMOD_Sound_Relase error\n");
	}
	if (env->sound.explosion)
	{
		if (FMOD_Sound_Release(env->sound.explosion))
			custom_error("FMOD_Sound_Relase error\n");
	}
	free_audio4(env);
	if (env->sound.system)
	{
		if (FMOD_System_Close(env->sound.system))
			custom_error("FMOD_System_Close error\n");
		if (FMOD_System_Release(env->sound.system))
			custom_error("FMOD_System_Release error\n");
	}
}

void	free_audio2(t_env *env)
{
	if (env->sound.player_death)
	{
		if (FMOD_Sound_Release(env->sound.player_death))
			custom_error("FMOD_Sound_Relase error\n");
	}
	if (env->sound.cyberdemon_death)
	{
		if (FMOD_Sound_Release(env->sound.cyberdemon_death))
			custom_error("FMOD_Sound_Relase error\n");
	}
	if (env->sound.lost_soul_death)
	{
		if (FMOD_Sound_Release(env->sound.lost_soul_death))
			custom_error("FMOD_Sound_Relase error\n");
	}
	if (env->sound.lost_soul_attack)
	{
		if (FMOD_Sound_Release(env->sound.lost_soul_attack))
			custom_error("FMOD_Sound_Relase error\n");
	}
	if (env->sound.monster_hit)
	{
		if (FMOD_Sound_Release(env->sound.monster_hit))
			custom_error("FMOD_Sound_Relase error\n");
	}
}

void	free_audio(t_env *env, int i)
{
	while (i < NB_WEAPONS)
	{
		if (env->weapons[i].shot)
		{
			if (FMOD_Sound_Release(env->weapons[i].shot))
				custom_error("FMOD_Sound_Relase error\n");
		}
		i++;
	}
	if (env->sound.footstep)
	{
		if (FMOD_Sound_Release(env->sound.footstep))
			custom_error("FMOD_Sound_Relase error\n");
	}
	if (env->sound.player_hit)
	{
		if (FMOD_Sound_Release(env->sound.player_hit))
			custom_error("FMOD_Sound_Relase error\n");
	}
	free_audio2(env);
	free_audio3(env);
}

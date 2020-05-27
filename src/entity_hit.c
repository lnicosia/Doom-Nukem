/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   entity_hit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/21 19:44:32 by marvin            #+#    #+#             */
/*   Updated: 2020/05/22 15:48:37 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

int		player_hit_sound(t_env *env)
{
	if (env->player.health <= 0)
	{
		if (play_sound(env, &env->sound.player_reaction_chan,
			env->sound.player_death, env->sound.ambient_vol))
			return (-1);
	}
	else if (play_sound(env, &env->sound.player_reaction_chan,
		env->sound.player_hit, env->sound.ambient_vol))
		return (-1);
	return (0);
}

int		stop_enemies_reaction_chan(t_env *env)
{
	int	err;
	int	is_playing;

	if ((err = FMOD_Channel_IsPlaying(env->sound.enemies_reaction_chan,
		&is_playing)) == FMOD_OK && is_playing == 1)
	{
		if ((err = FMOD_Channel_Stop(env->sound.enemies_reaction_chan)) !=
			FMOD_OK)
			return (custom_error("Could not stop enemies reaction channel"
				" (error \n"));
	}
	return (0);
}

int		enemy_hit_sound(int enemy, t_env *env)
{
	if (stop_enemies_reaction_chan(env))
		return (-1);
	if (env->enemies[enemy].health <= 0)
	{
		if (env->enemies[enemy].main_sprite < CYBER_DEMON
			&& play_sound(env, &env->sound.enemies_reaction_chan,
			env->sound.lost_soul_death, env->sound.ambient_vol))
			return (-1);
		else if (play_sound(env, &env->sound.enemies_reaction_chan,
			env->sound.cyberdemon_death, env->sound.ambient_vol))
			return (-1);
	}
	else
	{
		if (play_sound(env, &env->sound.enemies_reaction_chan,
			env->sound.monster_hit, env->sound.ambient_vol))
			return (-1);
	}
	return (0);
}

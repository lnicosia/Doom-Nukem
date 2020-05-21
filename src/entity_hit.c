/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   entity_hit.c         :                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/30 12:05:15 by lnicosia          #+#    #+#             */
/*   Updated: 2020/04/30 12:05:15 by lnicosia         ###   ########.fr       */
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

int		enemy_hit_sound(int enemy, t_env *env)
{
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
		if (env->enemies[enemy].main_sprite < CYBER_DEMON
			&& play_sound(env, &env->sound.enemies_reaction_chan,
			env->sound.monster_hit, env->sound.ambient_vol))
			return (-1);
	}
	return (0);
}

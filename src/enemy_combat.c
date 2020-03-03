/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_combat.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaerhard <gaerhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 10:34:48 by gaerhard          #+#    #+#             */
/*   Updated: 2020/03/03 12:04:35 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "collision.h"

/*
** Changes the music if the player starts or leaves a fight
** observing_enemies is the number of enemies who actually see the player
** returns 1 if the music was changed and 0 otherwise
*/

int		change_music(t_env *env, int observing_enemies)
{
	if (env->player.in_combat == 0 && observing_enemies != env->nb_enemies)
	{
		env->player.in_combat = 1;
		play_music(env, &env->sound.music_chan,
			env->sound.musics[1].music, env->sound.music_vol);
		return (1);
	}
	if (env->player.in_combat == 1 && observing_enemies == env->nb_enemies)
	{
		env->player.in_combat = 0;
		play_music(env, &env->sound.music_chan, env->sound.musics[0].music,
			env->sound.music_vol);
		return (1);
	}
	return (0);
}

/*
** Checks if the player is in combat or not and plays the appropriate music
*/

void	player_combat_state(t_env *env)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (i < env->nb_enemies)
	{
		if (env->enemies[i].exists && env->enemies[i].health > 0)
		{
			if (enemy_is_seeing_player(env, i))
			{
				if (change_music(env, count))
					return ;
			}
			else
				count++;
		}
		else
			count++;
		i++;
	}
	change_music(env, count);
}

/*
** Applies the damage from an enemy with aimbot or a melee fighter to the player
*/

void	damage_player(t_env *env, int damage)
{
	if (env->player.invincible)
		return ;
	env->player.hit = 1;
	env->player.health -= ft_clamp(damage * env->difficulty - env->player.armor,
		0, damage);
	env->player.armor -= ft_clamp(damage * env->difficulty, 0,
		env->player.armor);
	if (env->player.health < 0)
		env->player.health = 0;
}

/*
** Manages the collisions between an enemy and the player and the consequences
** of that collision: event, player damage, enemy death for instance
*/

int		enemy_melee_hit(t_env *env)
{
	int i;

	i = -1;
	while (++i < env->nb_enemies)
	{
		if (enemy_collision_player(env, i))
		{
			if (!enemy_collision_event(env, i))
				return (-1);
			env->player.colliding_enemies[i] = 1;
			if (env->enemies[i].behavior == MELEE_KAMIKAZE ||
				env->enemies[i].behavior == MELEE_FIGHTER)
			{
				damage_player(env, env->enemies[i].damage);
				if (env->enemies[i].behavior == MELEE_KAMIKAZE)
				{
					env->enemies[i].health = 0;
					env->enemies[i].exists = 0;
				}
			}
		}
		else
			env->player.colliding_enemies[i] = 0;
	}
	return (0);
}

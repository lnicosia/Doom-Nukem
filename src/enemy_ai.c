/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_ai.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 10:20:09 by gaerhard          #+#    #+#             */
/*   Updated: 2020/04/29 18:59:14 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "enemies.h"
#include "collision.h"

/*
** Tests a random direction to free the enemy if he's stuck
*/

t_v3	random_move(t_env *env, int nb, t_motion motion, t_v3 move)
{
	env->enemies[nb].dir = rand_dir(env, nb);
	move.x = (env->enemies[nb].dir) ? move.y : -move.y;
	move.y = (env->enemies[nb].dir) ? -move.x : move.x;
	move = check_collision(env, move, motion);
	return (move);
}

/*
** Manages the ai of a melee enemy
*/

void	melee_ai(t_env *env, t_enemy foe, int i)
{
	t_v3		move;
	t_motion	motion;

	if (foe.exists)
	{
		if (distance_two_points_2d(foe.pos.x, foe.pos.y, foe.last_player_pos.x,
			foe.last_player_pos.y) > 0.1)
		{
			env->enemies[i].state = PURSUING;
			move = sprite_movement(env, (double)foe.speed / 200, foe.pos,
				foe.last_player_pos);
			motion = new_motion(foe.sector, foe.size_2d, foe.eyesight, foe.pos);
			motion.flight = foe.type;
			motion.lowest_ceiling = find_lowest_ceiling(env, motion);
			move = check_collision(env, move, motion);
			if (move.x == 0 && move.y == 0 && foe.speed != 0)
				move = random_move(env, i, motion, move);
			update_enemy_pos(env, i, move);
		}
		update_enemy_angle(env, i);
	}
}

/*
** Manages the ai of a ranged enemy so that he only fires at the player when he
** sees him and is on range
** foe contains the stats of the enemy
** distance is the distance between the player and the enemy
** i is the number of the enemy
*/

int		ranged_ai_attack(t_env *env, t_enemy foe, double distance, int i)
{
	env->enemies[i].saw_player = 0;
	enemy_sight(env, i, 1);
	if (distance <= 31 && env->enemies[i].saw_player)
	{
		env->enemies[i].state = FIRING;
		if (env->enemies[i].shot)
		{
			if (env->enemies[i].behavior == RANGED_PROJECTILE)
			{
				if (create_projectile(env, new_projectile_data(foe.pos,
					foe.angle * CONVERT_RADIANS, 1, 1),
					new_projectile_stats(0.6, foe.damage *
					env->difficulty, 0.8, foe.eyesight - 2.2),
					new_projectile_data_2(enemy_angle_z(env, i), foe.size_2d)))
					return (-1);
				if (play_sound(env, &env->sound.enemies_shots_chan,
					env->weapons[3].shot, env->sound.ambient_vol))
					return (-1);
			}
			else if (env->enemies[i].behavior == RANGED_AIMBOT)
			{
				if (damage_player(env, foe.damage))
					return (-1);
			}
		}
		env->enemies[i].shot = 0;
	}
	return (0);
}

/*
** Manages the movement of a ranged enemy and then calls ranged_ai_attack to
** manage his attacks
** foe contains the stats of the enemy
** distance is the distance between the player and the enemy
** i is the number of the enemy
*/

int		ranged_ai(t_env *env, t_enemy foe, double distance, int i)
{
	t_v3		move;
	t_motion	motion;

	if (foe.exists)
	{
		if (distance_two_points_2d(foe.pos.x, foe.pos.y, foe.last_player_pos.x,
			foe.last_player_pos.y) > 0.1 && (distance >= 30 || !foe.saw_player))
		{
			env->enemies[i].state = PURSUING;
			move = sprite_movement(env, (double)foe.speed / 100, foe.pos,
				foe.last_player_pos);
			motion = new_motion(foe.sector, foe.size_2d, foe.eyesight, foe.pos);
			motion.lowest_ceiling = find_lowest_ceiling(env, motion);
			motion.flight = foe.type;
			move = check_collision(env, move, motion);
			if (move.x == 0 && move.y == 0)
				random_move(env, i, motion, move);
			update_enemy_pos(env, i, move);
		}
		update_enemy_angle(env, i);
		if (ranged_ai_attack(env, foe, distance, i))
			return (-1);
	}
	return (0);
}

/*
** Manages all enemies ai
*/

int		enemy_ai(t_env *env)
{
	int		i;
	double	distance;

	i = 0;
	while (i < env->nb_enemies)
	{
		env->enemies[i].state = RESTING;
		distance = enemy_sight(env, i, 0);
		if (env->enemies[i].exists && env->enemies[i].health > 0
			&& env->enemies[i].saw_player)
		{
			env->enemies[i].last_player_pos.x = env->player.pos.x;
			env->enemies[i].last_player_pos.y = env->player.pos.y;
			env->enemies[i].last_player_pos.z = env->player.head_z;
		}
		if (env->enemies[i].behavior == MELEE_KAMIKAZE
			|| env->enemies[i].behavior == MELEE_FIGHTER)
			melee_ai(env, env->enemies[i], i);
		else if ((env->enemies[i].behavior == RANGED_AIMBOT
			|| env->enemies[i].behavior == RANGED_PROJECTILE)
			&& ranged_ai(env, env->enemies[i], distance, i))
			return (-1);
		i++;
	}
	return (0);
}

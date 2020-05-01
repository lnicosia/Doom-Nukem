/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_collision.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaerhard <gaerhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 10:31:40 by gaerhard          #+#    #+#             */
/*   Updated: 2020/03/03 10:34:06 by gaerhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "events.h"
#include "collision.h"

/*
** Manages the enemy collision events
** i is the enemy number
*/

int		enemy_collision_event(t_env *env, int i)
{
	if (env->in_game && !env->player.colliding_enemies[i]
		&& env->enemies[i].nb_collision_events > 0
		&& env->enemies[i].collision_events)
	{
		if (start_event(&env->enemies[i].collision_events,
			&env->enemies[i].nb_collision_events, env))
			return (0);
	}
	return (1);
}

/*
** Checks if an enemy and the player are colliding
** i is the number of the enemy
*/

int		enemy_collision_player(t_env *env, int i)
{
	if (env->enemies[i].health > 0
		&& distance_two_points_2d(env->enemies[i].pos.x,
		env->enemies[i].pos.y, PLAYER_XPOS, PLAYER_YPOS) < 1.75
		&& env->enemies[i].exists
		&& env->enemies[i].pos.z >= env->player.pos.z - 1
		&& env->enemies[i].pos.z <= env->player.head_z + 1)
		return (1);
	return (0);
}

/*
** Checks if an object/projectile will collide with an enemy
** the object/projectile origin position is in e_coll.pos
** i is the number of the enemy
** e_coll.enemy contains the address of the nearest_enemy touched
*/

void	enemy_distance_coll(t_env *env, int i, t_ecoll e_coll)
{
	double	distance;
	t_v3	pos;

	pos = e_coll.pos;
	if (env->enemies[i].health > 0 && env->enemies[i].exists
		&& distance_two_points_2d(env->enemies[i].pos.x, env->enemies[i].pos.y,
		pos.x, pos.y) < env->enemies[i].size_2d + e_coll.radius
		&& pos.z <= env->enemies[i].eyesight + env->enemies[i].pos.z &&
		pos.z >= env->enemies[i].pos.z)
	{
		distance = distance_two_points_2d(env->enemies[i].pos.x,
			env->enemies[i].pos.y, pos.x, pos.y);
		if (distance < *(e_coll.nearest_dist))
		{
			*(e_coll.nearest_dist) = distance;
			*(e_coll.enemy) = i;
		}
	}
}

/*
** Checks if an object/projectile will collide with an enemy hitbox
** the object/projectile origin position is in e_coll.pos
** the object/projectile destination position is in dest
** i is the number of the enemy
** e_coll.enemy contains the address of the nearest_enemy touched
*/

void	enemy_hitbox_coll(t_env *env, int i, t_ecoll e_coll, t_v3 dest)
{
	t_v3	pos;
	double	radius;
	double	distance;

	pos = e_coll.pos;
	radius = e_coll.radius;
	if (hitbox_collision(new_v2(pos.x, pos.y), new_v2(dest.x, dest.y),
		new_v2(env->enemies[i].pos.x, env->enemies[i].pos.y), radius
		+ env->enemies[i].size_2d) && env->enemies[i].exists
		&& pos.z <= env->enemies[i].eyesight + env->enemies[i].pos.z
		&& pos.z >= env->enemies[i].pos.z)
	{
		distance = distance_two_points_2d(env->enemies[i].pos.x,
		env->enemies[i].pos.y, pos.x, pos.y);
		if (distance < *(e_coll.nearest_dist))
		{
			*(e_coll.nearest_dist) = distance;
			*(e_coll.enemy) = i;
		}
	}
}

/*
** This function checks if the pos is within an enemy radius and returns which
** enemy was hit
*/

int		enemy_collision(t_env *env, t_v3 pos, t_v3 dest, double radius)
{
	int		i;
	int		enemy;
	double	nearest_dist;

	i = 0;
	enemy = -1;
	nearest_dist = 2147483647;
	while (i < env->nb_enemies)
	{
		enemy_distance_coll(env, i, new_e_coll(radius, pos, &nearest_dist,
			&enemy));
		enemy_hitbox_coll(env, i, new_e_coll(radius, pos, &nearest_dist,
			&enemy), dest);
		i++;
	}
	return (enemy);
}

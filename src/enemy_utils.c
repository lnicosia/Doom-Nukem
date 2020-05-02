/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaerhard <gaerhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 16:15:29 by gaerhard          #+#    #+#             */
/*   Updated: 2020/03/04 11:05:38 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "collision.h"
#include "enemies.h"
#include <math.h>

/*
** Creates and returns a new wall segment
** between vertex and vertex + 1 from the given sector
*/

t_segment	new_wall_segment(t_env *env, int sector, int vertex)
{
	t_segment	wall;

	wall.p1.x = env->vertices[env->sectors[sector].vertices[vertex]].x;
	wall.p1.y = env->vertices[env->sectors[sector].vertices[vertex]].y;
	wall.p2.x = env->vertices[env->sectors[sector].vertices[vertex + 1]].x;
	wall.p2.y = env->vertices[env->sectors[sector].vertices[vertex + 1]].y;
	return (wall);
}

/*
** Creates and returns a new segment between p1 and p2
*/

t_segment	new_segment(t_v2 p1, t_v2 p2)
{
	t_segment new;

	new.p1 = p1;
	new.p2 = p2;
	return (new);
}

/*
** Updates the pos of an enemy
** nb is the number of the enemy
** move is the movement applied to the enemy
*/

void		update_enemy_pos(t_env *env, int nb, t_v3 move)
{
	env->enemies[nb].pos.x += move.x;
	env->enemies[nb].pos.y += move.y;
	env->enemies[nb].sector = get_sector_no_z_origin(env, env->enemies[nb].pos,
		env->enemies[nb].sector);
	if (env->enemies[nb].type == AERIAL)
		env->enemies[nb].pos.z += move.z;
	else
		update_enemy_z(env, nb);
}

/*
** Updates the angle of an enemy so that he faces the pos of the player
** nb is the number of the enemy
*/

void		update_enemy_angle(t_env *env, int nb)
{
	if (env->enemies[nb].saw_player)
		env->enemies[nb].angle = atan2(env->enemies[nb].last_player_pos.y -
			env->enemies[nb].pos.y, env->enemies[nb].last_player_pos.x -
			env->enemies[nb].pos.x) * CONVERT_DEGREES;
}

/*
** Creates and returns a new e_coll structure (enemy_collision)
*/

t_ecoll		new_e_coll(double radius, t_v3 pos, double *near_dist, int *enemy)
{
	t_ecoll	new;

	new.pos = pos;
	new.radius = radius;
	new.nearest_dist = near_dist;
	new.enemy = enemy;
	return (new);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_sight.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaerhard <gaerhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 10:25:56 by gaerhard          #+#    #+#             */
/*   Updated: 2020/03/03 11:06:24 by gaerhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init.h"
#include "collision.h"

/*
** Returns 1 if an enemy is STILL seeing the player and 0 otherwise
** i is the enemy number
*/

int		enemy_is_seeing_player(t_env *env, int i)
{
	if (env->enemies[i].last_player_pos.x == env->player.pos.x
		&& env->enemies[i].last_player_pos.y == env->player.pos.y
		&& env->enemies[i].last_player_pos.z == env->player.head_z)
		return (1);
	return (0);
}

/*
** Checks if the player is in the line of sight of an enemy
** enemy being the pos of the enemy in 2d
** player is the position of the player in 2d
** sector is the sector of the enemy being tested
*/

int		enemy_line_of_sight(t_env *env, t_v2 enemy, t_v2 player, int sector)
{
	int i;

	if (sector < 0)
		return (0);
	init_sector_list(env, sector);
	i = -1;
	while (++i < env->sectors[sector].nb_vertices)
	{
		if (sector == env->player.sector)
			return (1);
		if (env->sectors[sector].neighbors[i] >= 0
			&& env->sector_list[env->sectors[sector].neighbors[i]] == 0)
		{
			if (env->player.sector == env->sectors[sector].neighbors[i])
				return (1);
			env->sector_list[env->sectors[sector].neighbors[i]] = 1;
			if (!(check_sect(env, &sector, &i, new_segment(enemy, player))))
				return (0);
		}
	}
	return (0);
}

/*
** Returns 1 if the player is inside an enemy fov and if he's close enough
** returns 0 otherwise
*/

int		is_in_enemy_fov(t_enemy enemy, t_player player, double distance)
{
	t_v2	player_pos;
	t_v2	enemy_pos;
	int		left;
	int		right;

	player_pos = new_v2(player.pos.x, player.pos.y);
	enemy_pos = new_v2(enemy.pos.x, enemy.pos.y);
	right = 0;
	left = 0;
	relative_pos(direction_of_point(enemy_pos, enemy.far_left, player_pos),
		&left, &right);
	relative_pos(direction_of_point(enemy.far_left, enemy.far_right,
		player_pos), &left, &right);
	relative_pos(direction_of_point(enemy.far_right, enemy_pos, player_pos),
		&left, &right);
	if (distance <= 50 && (right == 3 || left == 3))
		return (1);
	return (0);
}

/*
** Checks if an enemy sees or "hears" the player
*/

double	enemy_sight(t_env *env, int i, int shot_flag)
{
	double	distance;

	enemy_far_left_right(env, i);
	env->enemies[i].saw_player = 0;
	distance = distance_two_points_2d(env->enemies[i].pos.x,
		env->enemies[i].pos.y, env->player.pos.x, env->player.pos.y);
	env->enemies[i].saw_player = is_in_enemy_fov(env->enemies[i],
		env->player, distance);
	if (distance <= 30 && !env->player.state.crouch)
		env->enemies[i].saw_player = 1;
	if (distance <= 10)
		env->enemies[i].saw_player = 1;
	if (env->enemies[i].saw_player)
		env->enemies[i].saw_player = enemy_line_of_sight(env,
			new_v2(env->enemies[i].pos.x, env->enemies[i].pos.y),
			new_v2(env->player.pos.x, env->player.pos.y),
			env->enemies[i].sector);
	if (env->enemies[i].hit && !shot_flag)
		env->enemies[i].saw_player = 1;
	return (distance);
}

/*
** Updates the values of sect and vertex if needed (function created only
** for the norme of the school)
*/

int		check_sect(t_env *env, int *sect, int *vertex, t_segment enemy_player)
{
	int		sector_check;
	t_v2	enemy;
	t_v2	player;

	enemy = enemy_player.p1;
	player = enemy_player.p2;
	sector_check = check_segment_in_sector(env, enemy, player,
		env->sectors[*sect].neighbors[*vertex]);
	if (sector_check == -1)
		return (0);
	else if (sector_check == 1)
	{
		*sect = env->sectors[*sect].neighbors[*vertex];
		*vertex = -1;
	}
	return (1);
}

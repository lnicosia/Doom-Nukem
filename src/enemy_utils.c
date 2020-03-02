/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaerhard <gaerhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 16:15:29 by gaerhard          #+#    #+#             */
/*   Updated: 2020/03/02 19:45:06 by gaerhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
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
** Returns the movement a sprite should do to go from the point origin
** to the point destination with the given speed
*/

t_v3	sprite_movement(t_env *env, double speed, t_v3 origin, t_v3 destination)
{
	Uint32	time;
	t_v3	direction;
	double  distance;

	time = SDL_GetTicks() - env->time.milli_s;
	speed *= time / 3;
	direction.x = destination.x - origin.x;
	direction.y = destination.y - origin.y;
	direction.z = destination.z - origin.z;
	if (direction.x == 0 && direction.y == 0 && direction.z == 0)
		return (direction);
	distance = sqrt(direction.x * direction.x + direction.y * direction.y
		+ direction.z * direction.z);
	direction.x = direction.x * speed / distance;
	direction.y = direction.y * speed / distance;
	direction.z = direction.z * speed / distance;
	return (direction);
}

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
** Checks if a segment cross a sector and if it cross only portals and no walls
** Returns 1 if it crosses the sector properly and 0 otherwise
*/

int	 check_segment_in_sector(t_env *env, t_v2 enemy, t_v2 player, int sector)
{
	int		 i;
	int		 count;
	t_segment   ray;
	t_segment   wall;

	i = -1;
	count = 0;
	ray.p1.x = enemy.x;
	ray.p1.y = enemy.y;
	ray.p2.x = player.x;
	ray.p2.y = player.y;
	while (++i < env->sectors[sector].nb_vertices)
	{
		wall = new_wall_segment(env, sector, i);
		if (intersection_check(ray.p1, ray.p2, wall.p1, wall.p2))
		{
			if (env->sectors[sector].neighbors[i] < 0)
				return (-1);
			else
				count++;
		}
		if (count == 2)
			return (1);
	}
	return (0);
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
** Updates the values of sect and vertex if needed (function created only 
** for the norme of the school)
*/

int		check_sector(t_env *env, int *sect, int *vertex, t_segment enemy_player)
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

/*
** Checks if the player is in the line of sight of an enemy
** enemy being the pos of the enemy in 2d
** player is the position of the player in 2d
** sector is the sector of the enemy being tested
*/

int	 enemy_line_of_sight(t_env *env, t_v2 enemy, t_v2 player, int sector)
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
			if (!(check_sector(env, &sector, &i, new_segment(enemy, player))))
				return (0);
		}
	}
	return (0);
}

int	 directionOfPoint(t_v2 A, t_v2 B, t_v2 P) 
{ 
	int cross_product;

	B.x -= A.x; 
	B.y -= A.y; 
	P.x -= A.x; 
	P.y -= A.y;   
	cross_product = B.x * P.y - B.y * P.x; 
	if (cross_product > 0) 
		return 1; 
	if (cross_product < 0) 
		return -1;  
	return 0;
}

/*
** the function computes the coordinates of the two extremites of an enemy fov
** nb is the number of the enemy
*/

void	enemy_far_left_right(t_env *env, int nb)
{
	double angle_left;
	double angle_right;

	angle_left = env->enemies[nb].angle + 65;
	angle_right = env->enemies[nb].angle - 65;
	angle_left -= (angle_left > 360) ? 360 : 0;
	angle_right += (angle_right < 360) ? 360 : 0;
	env->enemies[nb].far_left.x = 1000 * cos(angle_left * CONVERT_RADIANS)
		+ env->enemies[nb].pos.x;
	env->enemies[nb].far_left.y = 1000 * sin(angle_left * CONVERT_RADIANS)
		+ env->enemies[nb].pos.y;
	env->enemies[nb].far_right.x = 1000 * cos(angle_right * CONVERT_RADIANS)
		+ env->enemies[nb].pos.x;
	env->enemies[nb].far_right.y = 1000 * sin(angle_right * CONVERT_RADIANS)
		+ env->enemies[nb].pos.y;
}

/*
** Increments left or right if a point is on the left or right side of a line
*/

void	relative_pos(int direction, int *left, int *right)
{
	if (direction < 0)
		(*left)++;
	else if (direction > 0)
		(*right)++;
	else
	{
		(*left)++;
		(*right)++;
	}
}

/*
** Returns 1 if the player is inside an enemy fov and if he's close enough
** returns 0 otherwise
*/

int	 is_in_enemy_fov(t_enemy enemy, t_player player, double distance)
{
	t_v2	player_pos;
	t_v2	enemy_pos;
	int	 left;
	int	 right;

	player_pos = new_v2(player.pos.x, player.pos.y);
	enemy_pos = new_v2(enemy.pos.x, enemy.pos.y);
	right = 0;
	left = 0;
	relative_pos(directionOfPoint(enemy_pos, enemy.far_left, player_pos),
		&left, &right);
	relative_pos(directionOfPoint(enemy.far_left, enemy.far_right, player_pos),
		&left, &right);
	relative_pos(directionOfPoint(enemy.far_right, enemy_pos, player_pos),
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
	double  distance;

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
** Updates the pos of an enemy
** nb is the number of the enemy
** move is the movement applied to the enemy
*/

void	update_enemy_pos(t_env *env, int nb, t_v3 move)
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

void	update_enemy_angle(t_env *env, int nb)
{
	if (env->enemies[nb].saw_player)
		env->enemies[nb].angle = atan2(env->enemies[nb].last_player_pos.y -
			env->enemies[nb].pos.y, env->enemies[nb].last_player_pos.x -
			env->enemies[nb].pos.x) * CONVERT_DEGREES;
}

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

void	melee_ai(t_env *env, t_enemy foe, int i)
{
	t_v3 		move;
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
** Computes the z angle of the enemy
*/

double	enemy_angle_z(t_env *env, int i)
{
	double	dist_enemy_player;
	double	diff_z;
	double	angle_z;

	dist_enemy_player = distance_two_points_2d(env->enemies[i].pos.x,
		env->enemies[i].pos.y, env->player.pos.x, env->player.pos.y);
	diff_z = (env->enemies[i].pos.z + env->enemies[i].eyesight)
		- (env->player.pos.z + env->player.eyesight);
	if (dist_enemy_player != 0)
		angle_z = diff_z / dist_enemy_player;
	else
		angle_z = 0;
	return (angle_z);
}

/*
** Applies the damage from an enemy with aimbot or a melee fighter to the player
*/

void	damage_player(t_env *env, int damage)
{
	env->player.hit = 1;
	env->player.health -= ft_clamp(damage * env->difficulty - env->player.armor,
		0, damage);
	env->player.armor -= ft_clamp(damage * env->difficulty, 0,
		env->player.armor);
	if (env->player.health < 0)
		env->player.health = 0;
}

/*
** Manages the ai of a ranged enemy so that he only fires at the player when he
** sees him and is on range
** foe contains the stats of the enemy
** distance is the distance between the player and the enemy
** i is the number of the enemy
*/

void	ranged_ai_attack(t_env *env, t_enemy foe, double distance, int i)
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
				create_projectile(env, new_projectile_data(foe.pos,
					foe.angle * CONVERT_RADIANS, 1, 1),
					new_projectile_stats(0.6, foe.damage *
					env->difficulty, 0.8, foe.eyesight - 2.2),
					new_projectile_data_2(enemy_angle_z(env, i), foe.size_2d));
			}
			else if (env->enemies[i].behavior == RANGED_AIMBOT)
				damage_player(env, foe.damage);
		}
		env->enemies[i].shot = 0;
	}
}

/*
** Manages the movement of a ranged enemy and then calls ranged_ai_attack to
** manage his attacks
** foe contains the stats of the enemy
** distance is the distance between the player and the enemy
** i is the number of the enemy
*/

void	ranged_ai(t_env *env, t_enemy foe, double distance, int i)
{
	t_v3 		move;
	t_motion 	motion;

	if (foe.exists)
	{
		if (distance_two_points_2d(foe.pos.x, foe.pos.y, foe.last_player_pos.x,
			foe.last_player_pos.y) > 0.1 && (distance >= 30 || !foe.saw_player))
		{
			env->enemies[i].state = PURSUING;
			move = sprite_movement(env, (double)foe.speed / 100 , foe.pos,
				foe.last_player_pos);
			motion = new_motion(foe.sector, foe.size_2d, foe.eyesight, foe.pos);
			motion.lowest_ceiling = find_lowest_ceiling(env, motion);
			motion.flight = foe.type;
			move = check_collision(env, move, motion);
			if (move.x == 0 && move.y == 0)
				random_move(env, i, motion, move);
				env->enemies[i].dir = rand_dir(env, i);
			update_enemy_pos(env, i, move);
		}
		update_enemy_angle(env, i);
		ranged_ai_attack(env, foe, distance, i);
	}
}

/*
** Manages all enemies ai
*/

void	enemy_ai(t_env *env)
{
	int	 i;
	double  distance;

	i = 0;
	while (i < env->nb_enemies)
	{
;		env->enemies[i].state = RESTING;
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
		else if (env->enemies[i].behavior == RANGED_AIMBOT
			|| env->enemies[i].behavior == RANGED_PROJECTILE)
			ranged_ai(env, env->enemies[i], distance, i);
		i++;
	}
}

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
** Creates and returns a new e_coll structure (enemy_collision)
*/

t_ecoll	new_e_coll(double radius, t_v3 pos, double *near_dist, int *enemy)
{
	t_ecoll	new;

	new.pos = pos;
	new.radius = radius;
	new.nearest_dist = near_dist;
	new.enemy = enemy;
	return (new);
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

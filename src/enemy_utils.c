/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaerhard <gaerhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 16:15:29 by gaerhard          #+#    #+#             */
/*   Updated: 2019/11/25 15:48:14 by gaerhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "collision.h"

/*
** Function needs to be moved to another file
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
	distance = sqrt(direction.x * direction.x + direction.y * direction.y + direction.z * direction.z);
	direction.x = direction.x * speed / distance;
	direction.y = direction.y * speed / distance;
	direction.z = direction.z * speed / distance;
	return (direction);
}

double	sprite_rotate(double a_origin, double a_dest)
{
	if (a_origin < a_dest)
	{
		a_origin -= 10;
		ft_fclamp(a_origin, a_dest, a_origin);
	}
	else
	{
		a_origin += 10;
		ft_fclamp(a_origin, a_origin, a_dest);
	}
	return (a_origin);
}

double  max(double a, double b)
{
	return ((a > b) ? a : b);
}

double  min(double a, double b)
{
	return ((a < b) ? a : b);
}

int onSegment(t_v2 p, t_v2 q, t_v2 r) 
{ 
	if (q.x <= max(p.x, r.x) && q.x >= min(p.x, r.x) && 
		q.y <= max(p.y, r.y) && q.y >= min(p.y, r.y)) 
	   return (1); 
  
	return (0); 
} 
  
// To find orientation of ordered triplet (p, q, r). 
// The function returns following values 
// 0 --> p, q and r are colinear 
// -1 --> Clockwise 
// 1 --> Counterclockwise 
int orientation(t_v2 p, t_v2 q, t_v2 r) 
{ 
	int val;
	
	val = (q.y - p.y) * (r.x - q.x) - 
			  (q.x - p.x) * (r.y - q.y); 
	if (val == 0)
		return 0;  // colinear 
	return ((val > 0) ? -1: 1); // clock or counterclock wise 
} 
  
// The main function that returns true if line segment 'p1q1' 
// and 'p2q2' intersect. 
int doIntersect(t_v2 p1, t_v2 q1, t_v2 p2, t_v2 q2) 
{ 
	// Find the four orientations needed for general and 
	// special cases 
	int o1 = orientation(p1, q1, p2); 
	int o2 = orientation(p1, q1, q2); 
	int o3 = orientation(p2, q2, p1); 
	int o4 = orientation(p2, q2, q1); 
  
	// General case 
	if (o1 != o2 && o3 != o4) 
		return 1; 
  
	// Special Cases 
	// p1, q1 and p2 are colinear and p2 lies on segment p1q1 
	if (o1 == 0 && onSegment(p1, p2, q1)) return 1; 
  
	// p1, q1 and q2 are colinear and q2 lies on segment p1q1 
	if (o2 == 0 && onSegment(p1, q2, q1)) return 1; 
  
	// p2, q2 and p1 are colinear and p1 lies on segment p2q2 
	if (o3 == 0 && onSegment(p2, p1, q2)) return 1; 
  
	 // p2, q2 and q1 are colinear and q1 lies on segment p2q2 
	if (o4 == 0 && onSegment(p2, q1, q2)) return 1; 
  
	return 0; // Doesn't fall in any of the above cases 
} 



int	 check_segment_in_sector(t_env *env, t_v2 enemy, t_v2 player, int sector)
{
	int		 i;
	int		 count;
	t_segment   ray;
	t_segment   wall;

	i = 0;
	count = 0;
	ray.p1.x = enemy.x;
	ray.p1.y = enemy.y;
	ray.p2.x = player.x;
	ray.p2.y = player.y;
	while (i < env->sectors[sector].nb_vertices)
	{
		wall.p1.x = env->vertices[env->sectors[sector].vertices[i]].x;
		wall.p1.y = env->vertices[env->sectors[sector].vertices[i]].y;
		wall.p2.x = env->vertices[env->sectors[sector].vertices[i + 1]].x;
		wall.p2.y = env->vertices[env->sectors[sector].vertices[i + 1]].y;
		if (doIntersect(ray.p1, ray.p2, wall.p1, wall.p2))
		{
			if (env->sectors[sector].neighbors[i] < 0)
				return (-1);
			else
				count++;
		}
		if (count == 2)
			return (1);
		i++;
	}
	return (0);
}

int	 enemy_line_of_sight(t_env *env, t_v2 enemy, t_v2 player, int sector)
{
	int i;
	int sector_check;

	init_sector_list(env, sector);
	i = 0;
	if (sector < 0)
		return (0);
	while (i < env->sectors[sector].nb_vertices)
	{
		if (sector == env->player.sector)
			return (1);
		if (env->sectors[sector].neighbors[i] >= 0 && env->sector_list[env->sectors[sector].neighbors[i]] == 0)
		{
			if (env->player.sector == env->sectors[sector].neighbors[i])
				return (1);
			env->sector_list[env->sectors[sector].neighbors[i]] = 1;
			sector_check = check_segment_in_sector(env, enemy, player, env->sectors[sector].neighbors[i]);
			if (sector_check == -1)
				return (0);
			else if (sector_check == 1)
			{
				sector = env->sectors[sector].neighbors[i];
				i = -1;
			}
		}
		i++;
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

void	enemy_far_left_right(t_env *env, int nb)
{
	double angle_left;
	double angle_right;

	angle_left = env->enemies[nb].angle + 65;
	angle_right = env->enemies[nb].angle - 65;
	angle_left -= (angle_left > 360) ? 360 : 0;
	angle_right += (angle_right < 360) ? 360 : 0;
	env->enemies[nb].far_left.x = 1000 * cos(angle_left * CONVERT_RADIANS) + env->enemies[nb].pos.x;
	env->enemies[nb].far_left.y = 1000 * sin(angle_left * CONVERT_RADIANS) + env->enemies[nb].pos.y;
	env->enemies[nb].far_right.x = 1000 * cos(angle_right * CONVERT_RADIANS) + env->enemies[nb].pos.x;
	env->enemies[nb].far_right.y = 1000 * sin(angle_right * CONVERT_RADIANS) + env->enemies[nb].pos.y;
}

int	 is_in_enemy_fov(t_enemies enemy, t_player player, double distance)
{
	t_v2	player_pos;
	t_v2	enemy_pos;
	int	 direction;
	int	 left;
	int	 right;

	player_pos = new_v2(player.pos.x, player.pos.y);
	enemy_pos = new_v2(enemy.pos.x, enemy.pos.y);
	right = 0;
	left = 0;
	direction = directionOfPoint(enemy_pos, enemy.far_left, player_pos);
	if (direction < 0)
		left++;
	else if (direction > 0)
		right++;
	else
	{
		right++;
		left++;
	}
	direction = directionOfPoint(enemy.far_left, enemy.far_right, player_pos);
	if (direction < 0)
		left++;
	else if (direction > 0)
		right++;
	else
	{
		right++;
		left++;
	}
	direction = directionOfPoint(enemy.far_right, enemy_pos, player_pos);
	if (direction < 0)
		left++;
	else if (direction > 0)
		right++;
	else
	{
		right++;
		left++;
	}
	if (distance <= 50 && (right == 3 || left == 3))
		return (1);
	return (0);
}

double	enemy_sight(t_env *env, int i, int shot_flag)
{
	double  distance;

	enemy_far_left_right(env, i);
	env->enemies[i].saw_player = 0;
	distance = distance_two_points(env->enemies[i].pos.x, env->enemies[i].pos.y, env->player.pos.x, env->player.pos.y);
	env->enemies[i].saw_player = is_in_enemy_fov(env->enemies[i], env->player, distance);
	if (distance <= 30)
		env->enemies[i].saw_player = 1;
	if (env->enemies[i].saw_player)
		env->enemies[i].saw_player = enemy_line_of_sight(env, new_v2(env->enemies[i].pos.x, env->enemies[i].pos.y), new_v2(env->player.pos.x, env->player.pos.y), env->enemies[i].sector);
	if (env->enemies[i].hit && !shot_flag)
		env->enemies[i].saw_player = 1; //obligé de mettre ça apres pour eviter de pouvoir tirer sur un ennemi en restant a moitié caché
	return (distance);
}

void	melee_ai(t_env *env, t_enemies enemy, double distance, int i)
{
	t_v3 		direction;
	t_v3 		move;
	t_movement	motion;

	(void)distance;
	if (enemy.exists )
	{
		if (distance_two_points(enemy.pos.x, enemy.pos.y, enemy.last_player_pos.x, enemy.last_player_pos.y) > 0.1)
		{
			env->enemies[i].state = PURSUING;
			direction = sprite_movement(env, (double)enemy.speed / 200, enemy.pos, enemy.last_player_pos);
			move.x = direction.x;
			move.y = direction.y;
			move.z = (env->enemies[i].type == AERIAL) ? direction.z : 0;
			motion = new_movement(enemy.sector, enemy.size_2d, enemy.eyesight, enemy.pos);
			motion.lowest_ceiling = find_lowest_ceiling(env, motion);
			move = check_collision(env, move, motion, 0);
			if (move.x == 0 && move.y == 0 && enemy.speed != 0)
			{
				env->enemies[i].dir = rand_dir(env, i);
				if (env->enemies[i].dir == 0)
				{
					move.x = -direction.y;
					move.y = direction.x;
				}
				else if (env->enemies[i].dir == 1)
				{
					move.x = direction.y;
					move.y = -direction.x;
				}
				move = check_collision(env, move, motion, 1);
			}
			env->enemies[i].pos.x += move.x;
			env->enemies[i].pos.y += move.y;
			if (env->enemies[i].type == AERIAL)
				env->enemies[i].pos.z += move.z;
			else
				update_enemy_z(env, i);
			env->enemies[i].sector = get_sector_no_z_origin(env, env->enemies[i].pos, env->enemies[i].sector);
		}
			if (enemy.saw_player)
				env->enemies[i].angle = atan2(enemy.last_player_pos.y - env->enemies[i].pos.y, enemy.last_player_pos.x - env->enemies[i].pos.x) * CONVERT_DEGREES;
	}
}

double	enemy_angle_z(t_env *env, int i)
{
	double	dist_enemy_player;
	double	diff_z;
	double	angle_z;

	dist_enemy_player = distance_two_points(env->enemies[i].pos.x, env->enemies[i].pos.y, env->player.pos.x, env->player.pos.y);
	diff_z = (env->enemies[i].pos.z + env->enemies[i].eyesight) - (env->player.pos.z + env->player.eyesight);
	if (dist_enemy_player != 0)
		angle_z = diff_z / dist_enemy_player;
	else
		angle_z = 0;
	return (angle_z);
}

void	ranged_ai(t_env *env, t_enemies enemy, double distance, int i)
{
	t_v3		direction;
	t_v3 		move;
	t_movement 	motion;

	if (enemy.exists)
	{
		if (distance_two_points(enemy.pos.x, enemy.pos.y, enemy.last_player_pos.x, enemy.last_player_pos.y) > 0.1 &&
			(distance >= 30 || !enemy.saw_player))
		{
			env->enemies[i].state = PURSUING;
			direction = sprite_movement(env, (double)enemy.speed / 100 , enemy.pos, enemy.last_player_pos);
			move.x = direction.x;
			move.y = direction.y;
			move.z = (env->enemies[i].type == AERIAL) ? direction.z : 0;
			motion = new_movement(enemy.sector, enemy.size_2d, enemy.eyesight, enemy.pos);
			motion.lowest_ceiling = find_lowest_ceiling(env, motion);
			move = check_collision(env, move, motion, 0);
			if (move.x == 0 && move.y == 0)
			{
				env->enemies[i].dir = rand_dir(env, i);
				if (env->enemies[i].dir == 0)
				{
					move.x = -direction.y;
					move.y = direction.x;
				}
				else if (env->enemies[i].dir == 1)
				{
					move.x = direction.y;
					move.y = -direction.x;
				}
				move = check_collision(env, move, motion, 1);
			}
			env->enemies[i].pos.x += move.x;
			env->enemies[i].pos.y += move.y;
			env->enemies[i].sector = get_sector_no_z_origin(env, env->enemies[i].pos, env->enemies[i].sector);
			if (env->enemies[i].type == AERIAL)
				env->enemies[i].pos.z += move.z;
			else
				update_enemy_z(env, i);
		}
		if (env->enemies[i].saw_player)
			env->enemies[i].angle = atan2(enemy.last_player_pos.y - env->enemies[i].pos.y, enemy.last_player_pos.x - env->enemies[i].pos.x) * CONVERT_DEGREES;
		env->enemies[i].saw_player = 0;
		enemy_sight(env, i, 1);
		if (distance <= 31 && env->enemies[i].saw_player)
		{
			env->enemies[i].state = FIRING;
			if (env->enemies[i].shot)
			{
				if (env->enemies[i].behavior == RANGED_PROJECTILE)
				{
					create_projectile(env, new_projectile_data(env->enemies[i].pos, env->enemies[i].angle, 50, 1),
						new_projectile_stats(0.6, env->enemies[i].damage, 0.8, env->enemies[i].eyesight - 2.2),
						enemy_angle_z(env, i));
				}
				else if (env->enemies[i].behavior == RANGED_AIMBOT)
				{
					env->player.hit = 1;
					env->player.health -= env->enemies[i].damage;
				}
				if (env->player.health < 0)
					env->player.health = 0;
			}
			env->enemies[i].shot = 0;
		}
	}
}

void	enemy_ai(t_env *env)
{
	int	 i;
	double  distance;

	i = 0;
	while (i < env->nb_enemies)
	{
;		env->enemies[i].state = RESTING;
		distance = enemy_sight(env, i, 0);
		if (env->enemies[i].exists && env->enemies[i].health > 0 && env->enemies[i].saw_player)
		{
			env->enemies[i].last_player_pos.x = env->player.pos.x;
			env->enemies[i].last_player_pos.y = env->player.pos.y;
			env->enemies[i].last_player_pos.z = env->player.head_z;
		}
		if (env->enemies[i].behavior == MELEE_KAMIKAZE || env->enemies[i].behavior == MELEE_FIGHTER)
			melee_ai(env, env->enemies[i], distance, i);
		else if (env->enemies[i].behavior == RANGED_AIMBOT
			|| env->enemies[i].behavior == RANGED_PROJECTILE)
			ranged_ai(env, env->enemies[i], distance, i);
		i++;
	}
}

void		enemy_melee_hit(t_env *env)
{
	int i;

	i = 0;
	while (i < env->nb_enemies)
	{
		if (env->enemies[i].health > 0 && distance_two_points(env->enemies[i].pos.x, env->enemies[i].pos.y, PLAYER_XPOS, PLAYER_YPOS) < 1.75 && env->enemies[i].exists
			&& env->enemies[i].pos.z >= PLAYER_ZPOS - 1 && env->enemies[i].pos.z <= env->player.head_z + 1 && (env->enemies[i].behavior == MELEE_KAMIKAZE ||
			env->enemies[i].behavior == MELEE_FIGHTER))
		{
			env->player.hit = 1;
			env->player.health -= env->enemies[i].damage;
			if (env->player.health < 0)
				env->player.health = 0;
			if (env->enemies[i].behavior == MELEE_KAMIKAZE)
			env->enemies[i].exists = 0;
		}
		i++;
	}
}

/*
** This function checks if the pos is within an enemy radius and returns which enemy
** was hit
*/

int			enemy_collision(t_env *env, t_v3 pos, t_v3 dest, double radius)
{
	int		i;
	int		enemy;
	double	nearest_dist;
	double	distance;

	i = 0;
	enemy = -1;
	nearest_dist = 2147483647;
	while (i < env->nb_enemies)
	{
		if (env->enemies[i].health > 0 && distance_two_points(env->enemies[i].pos.x, env->enemies[i].pos.y, pos.x, pos.y) < env->enemies[i].size_2d + radius && env->enemies[i].exists
			&& pos.z <= env->enemies[i].eyesight + env->enemies[i].pos.z && pos.z >= env->enemies[i].pos.z)
		{
			distance = distance_two_points(env->enemies[i].pos.x, env->enemies[i].pos.y, pos.x, pos.y);
			if (distance < nearest_dist)
			{
				nearest_dist = distance;
				enemy = i;
			}
		}
		if (hitbox_collision(new_v2(pos.x, pos.y), new_v2(dest.x, dest.y),
			new_v2(env->enemies[i].pos.x, env->enemies[i].pos.y), radius + env->enemies[i].size_2d) && env->enemies[i].exists
			&& pos.z <= env->enemies[i].eyesight + env->enemies[i].pos.z && pos.z >= env->enemies[i].pos.z)
		{
			distance = distance_two_points(env->enemies[i].pos.x, env->enemies[i].pos.y, pos.x, pos.y);
			if (distance < nearest_dist)
			{
				nearest_dist = distance;
				enemy = i;
			}
		}
		i++;
	}
	return (enemy);
}
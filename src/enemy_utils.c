/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaerhard <gaerhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 16:03:54 by gaerhard          #+#    #+#             */
/*   Updated: 2019/10/10 15:41:05 by gaerhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "collision.h"

/*
** Function needs to be moved to another file
*/

t_v3    sprite_movement(double speed, t_v3 origin, t_v3 destination)
{
    t_v3    direction;
    double  distance;

    //ft_printf("%f\n", speed);
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

double    sprite_rotate(double a_origin, double a_dest)
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



int     check_segment_in_sector(t_env *env, t_v2 enemy, t_v2 player, int sector)
{
    int         i;
    int         count;
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

int     enemy_line_of_sight(t_env *env, t_v2 enemy, t_v2 player, int sector)
{
    int i;
    int sector_check;

    i = 0;
    while (i < env->nb_sectors)
    {
        env->sector_list[i] = 0;
        if (i == sector)
            env->sector_list[i] = 1;
        i++;
    }
    i = 0;
    while (i < env->sectors[sector].nb_vertices)
    {
        if (sector == env->player.sector)
            return (1);
        if (env->sector_list[env->sectors[sector].neighbors[i]] == 0 && env->sectors[sector].neighbors[i] >= 0)
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

int     directionOfPoint(t_v2 A, t_v2 B, t_v2 P) 
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

void    enemy_far_left_right(t_env *env, int nb)
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

int     is_in_enemy_fov(t_enemies enemy, t_player player, double distance)
{
    t_v2    player_pos;
    t_v2    enemy_pos;
    int     direction;
    int     left;
    int     right;

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

double    enemy_sight(t_env *env, int i, int shot_flag)
{
    double  distance;

    enemy_far_left_right(env, i);
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

void    enemy_pursuit(t_env *env)
{
    int     i;
    int     j;
    double  distance;
    t_v3    direction;
    t_v2    move;

    i = 0;
    while (i < env->nb_enemies)
    {
        j = 0;
        while (j < env->nb_sectors)
        {
            if (j == env->enemies[i].sector)
                env->sector_list[j] = 1;
            else
                env->sector_list[j] = 0;
            j++;
        }
        env->enemies[i].state = RESTING;
        distance = enemy_sight(env, i, 0);
        ft_printf("distance = %f\n", distance);
        if (env->enemies[i].exists && env->enemies[i].health > 0 && 
            distance <= 50 && (distance >= 30 || !env->enemies[i].ranged) && env->enemies[i].saw_player)
        {
            env->enemies[i].last_player_pos.x = env->player.pos.x;
            env->enemies[i].last_player_pos.y = env->player.pos.y;
            env->enemies[i].last_player_pos.z = env->player.head_z;
        }
        if (env->enemies[i].exists &&
            distance_two_points(env->enemies[i].pos.x, env->enemies[i].pos.y, env->enemies[i].last_player_pos.x, env->enemies[i].last_player_pos.y) > 0.1 &&
            (distance >= 30 || !env->enemies[i].ranged || !env->enemies[i].saw_player))
        {
            env->enemies[i].state = PURSUING;
            direction = sprite_movement((double)env->enemies[i].speed / 200, env->enemies[i].pos, env->enemies[i].last_player_pos);
            move.x = direction.x;
            move.y = direction.y;
            move = check_collision(env, move, new_movement(env->enemies[i].sector, env->enemies[i].size_2d, env->enemies[i].eyesight, env->enemies[i].pos), 0);
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
                move = check_collision(env, move, new_movement(env->enemies[i].sector, env->enemies[i].size_2d, env->enemies[i].eyesight, env->enemies[i].pos), 1);
            }
            env->enemies[i].pos.x += move.x;
            env->enemies[i].pos.y += move.y;
            env->enemies[i].sector = get_sector_no_z_origin(env, env->enemies[i].pos, env->enemies[i].sector);
            if (env->enemies[i].flying)
                env->enemies[i].pos.z += direction.z;
            else
                update_enemy_z(env, i);
            env->enemies[i].angle = atan2(env->enemies[i].last_player_pos.y - env->enemies[i].pos.y, env->enemies[i].last_player_pos.x - env->enemies[i].pos.x) * CONVERT_DEGREES;
        }
        env->enemies[i].saw_player = 0;
        enemy_sight(env, i, 1);
        if (env->enemies[i].ranged && distance <= 31 && env->enemies[i].saw_player)
        {
            env->enemies[i].state = FIRING;
            if (env->enemies[i].shot)
            {
                env->player.health -= env->enemies[i].damage;
                if (env->player.health < 0)
                    env->player.health = 0;
                env->player.hit = 1;
            }
            env->enemies[i].shot = 0;
        }
        i++;
    }
}

void        enemy_collision(t_env *env)
{
    int i;

    i = 0;
    while (i < env->nb_enemies)
    {
        if (env->enemies[i].health > 0 && distance_two_points(env->enemies[i].pos.x, env->enemies[i].pos.y, PLAYER_XPOS, PLAYER_YPOS) < 1.75 && env->enemies[i].exists
            && env->enemies[i].pos.z >= PLAYER_ZPOS - 1 && env->enemies[i].pos.z <= env->player.eyesight + env->player.pos.z + 1 && !env->enemies[i].ranged)
        {
            env->player.hit = 1;
            env->player.health -= env->enemies[i].damage;
            if (env->player.health < 0)
                env->player.health = 0;
            env->enemies[i].exists = 0;
        }
        i++;
    }
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_collision.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaerhard <gaerhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 17:45:07 by gaerhard          #+#    #+#             */
/*   Updated: 2019/07/30 14:13:39 by sipatry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "collision.h"

int     in_range(double nb, double val1, double val2)
{
    double min;
    double max;

    min = (val1 <= val2) ? val1 : val2;
    max = (val1 > val2) ? val1 : val2;
    if (nb > min && nb <= max)
        return (1);
    return (0);
}

void    move_alongside_wall(t_env *env, double x_move, double y_move, int i)
{
    float xd;
    float yd;
    t_movement motion;
    
    xd = X2 - X1;
    yd = Y2 - Y1;
    x_move = xd * (x_move*xd + yd*y_move) / (xd*xd + yd*yd);
    y_move = yd * (x_move*xd + yd*y_move) / (xd*xd + yd*yd);
    FUTURE_X = PLAYER_XPOS + x_move;
    FUTURE_Y = PLAYER_YPOS + y_move;
    motion.old_sector = env->player.sector;
    if (check_inside_sector(env, motion))
    {
        PLAYER_XPOS = FUTURE_X;
        PLAYER_YPOS = FUTURE_Y;
    }
}

int     diff_value(int nb1, int nb2, int a, int b)
{
    if ((nb1 == a && nb2 == b) || (nb1 == b && nb2 == a))
        return (0);
    return (1);
}

int     diff_sign(double nb1, double nb2)
{
    if ((nb1 > 0 && nb2 > 0) || (nb1 < 0 && nb2 < 0) || nb1 == 0)
        return (0);
    return (1);
}

int     check_ceiling(t_env *env, t_movement motion)
{
    FUTURE_Z = env->player.eyesight + env->sectors[env->player.sector].floor + (env->sectors[env->player.sector].normal.x * (FUTURE_X - FUTURE_V0X) - env->sectors[env->player.sector].normal.y * (FUTURE_Y - FUTURE_V0Y)) * env->sectors[env->player.sector].floor_slope;
    if (FUTURE_Z > env->sectors[env->player.sector].ceiling + (env->sectors[env->player.sector].normal.x * (FUTURE_X - FUTURE_V0X) - env->sectors[env->player.sector].normal.y * (FUTURE_Y - FUTURE_V0Y)) * env->sectors[env->player.sector].ceiling_slope - 1)
        return (0);
    return (1);
}

int     check_floor(t_env *env, t_movement motion)
{
    FUTURE_Z = env->sectors[env->player.sector].floor + (env->sectors[env->player.sector].normal.x * (FUTURE_X - FUTURE_V0X) - env->sectors[env->player.sector].normal.y * (FUTURE_Y - FUTURE_V0Y)) * env->sectors[env->player.sector].floor_slope;
    if (FUTURE_Z > env->player.pos.z + 2)
		        return (0);
    return (1);
}

int     check_wall(t_env *env, int i, t_movement motion)
{
    if ((PLAYER_XPOS >= X1 && PLAYER_XPOS <= X2) || (PLAYER_XPOS >= X2 && PLAYER_XPOS <= X1))
        return (1);
    if ((PLAYER_YPOS >= Y1 && PLAYER_YPOS <= Y2) || (PLAYER_YPOS >= Y2 && PLAYER_YPOS <= Y1))
        return (1);
    if ((FUTURE_Y >= Y1 && FUTURE_Y <= Y2) || (FUTURE_Y >= Y2 && FUTURE_Y <= Y1))
        return (1);
    if ((FUTURE_X >= X1 && FUTURE_X <= X2) || (FUTURE_X >= X2 && FUTURE_X <= X1))
        return (1);
    return (0);
}

int     check_on_wall(t_env *env, int i, t_movement motion)
{
    int curr;
    int fut;

    curr = 0;
    fut = 0;
    if ((PLAYER_XPOS >= X1 && PLAYER_XPOS <= X2) || (PLAYER_XPOS >= X2 && PLAYER_XPOS <= X1))
        curr++;
    if ((PLAYER_YPOS >= Y1 && PLAYER_YPOS <= Y2) || (PLAYER_YPOS >= Y2 && PLAYER_YPOS <= Y1))
        curr++;
    if ((FUTURE_Y >= Y1 && FUTURE_Y <= Y2) || (FUTURE_Y >= Y2 && FUTURE_Y <= Y1))
        fut++;
    if ((FUTURE_X >= X1 && FUTURE_X <= X2) || (FUTURE_X >= X2 && FUTURE_X <= X1))
        fut++;
    if (curr == 2 && fut == 2)
        return (-1);
    if (curr == 2 || fut == 2)
        return (1);
    return (0);
}

int     check_inside_sector_bis(t_env *env, t_movement motion)
{
    int     count;
    int     i;
    double  start_pos;
    double  end_pos;

    i = 0;
    count = 0;
    while (i < VERTICES_AMOUNT)
    {
        start_pos = (FUTURE_X - X1) * (Y2 - Y1) - (FUTURE_Y - Y1) * (X2 - X1);
        end_pos = (env->sectors[env->player.sector].x_max + 1 - X1) * (Y2 - Y1) - (FUTURE_Y - Y1) * (X2 - X1);
        if (diff_sign(start_pos, end_pos) && in_range(FUTURE_Y, Y1, Y2))
            count++;
        i++;
    }
    if (count % 2 == 0 || !check_floor(env, motion))
        return (0);
    return (1);
}

int     check_collision_rec(t_env *env, t_movement motion)
{
    short   i;
    double  start_pos;
    double  end_pos;

    i = 0;
    if (env->options.wall_lover == 1)
        return (1);
    env->player.pos.z = env->sectors[env->player.sector].floor + (env->sectors[env->player.sector].normal.x * (FUTURE_X - FUTURE_V0X) - env->sectors[env->player.sector].normal.y * (FUTURE_Y - FUTURE_V0Y)) * env->sectors[env->player.sector].floor_slope;
	env->player.head_z = env->player.pos.z + env->player.eyesight;
    while (i < VERTICES_AMOUNT)
    {
        start_pos = (PLAYER_XPOS - X1) * (Y2 - Y1) - (PLAYER_YPOS - Y1) * (X2 - X1);
        end_pos = (FUTURE_X - X1) * (Y2 - Y1) - (FUTURE_Y - Y1) * (X2 - X1);
        if (end_pos == 0 && check_on_wall(env, i, motion))
        {
                env->player.speed = env->player.speed * 0.7;
                FUTURE_X *= 0.7;
                FUTURE_Y *= 0.7;
                return (check_collision_rec(env, motion));
        }
        if (diff_sign(start_pos, end_pos) && check_wall(env, i, motion) && NEIGHBOR < 0 && end_pos != 0
            && diff_value(motion.wall_v1 , motion.wall_v2, env->vertices[env->sectors[env->player.sector].vertices[i]].num,  env->vertices[env->sectors[env->player.sector].vertices[i + 1]].num))
            return (0);
        else if (diff_sign(start_pos, end_pos) && check_wall(env, i, motion) && NEIGHBOR >= 0
         && diff_value(motion.wall_v1, motion.wall_v2, env->vertices[env->sectors[env->player.sector].vertices[i]].num, env->vertices[env->sectors[env->player.sector].vertices[i + 1]].num))
        {
            env->player.sector = NEIGHBOR;
            motion.wall_v1 = env->vertices[env->sectors[env->player.sector].vertices[i]].num;
            motion.wall_v2 = env->vertices[env->sectors[env->player.sector].vertices[i + 1]].num;
            if (!check_inside_sector_bis(env, motion) || !check_floor(env, motion))
            {
                env->player.sector = motion.old_sector;
                return (0);
            }
            return (1);
        }
        i++;
    }
    return (0);
}

int     check_inside_sector(t_env *env, t_movement motion)
{
    int     count;
    int     i;
    double  start_pos;
    double  end_pos;

    i = 0;
    count = 0;
    if (!check_floor(env, motion))
        return (0);
    while (i < VERTICES_AMOUNT)
    {
        start_pos = (FUTURE_X - X1) * (Y2 - Y1) - (FUTURE_Y - Y1) * (X2 - X1);
        end_pos = (env->sectors[env->player.sector].x_max + 1 - X1) * (Y2 - Y1) - (FUTURE_Y - Y1) * (X2 - X1);
        if (diff_sign(start_pos, end_pos) && in_range(FUTURE_Y, Y1, Y2))
            count++;
        i++;
    }
    //ft_printf("count = %d\n", count);
    if (count % 2 == 0)
    {
        if (check_collision_rec(env, motion))
            return (1);
        return (0);
    }
    else if (!check_floor(env, motion))
	{
		ft_printf("test\n");
        return (0);
	}
    return (1);
}

int     check_collision(t_env *env, double x_move, double y_move)
{
    short		i;
    t_movement  motion;
    double		start_pos;
    double  	end_pos;

    if (env->options.wall_lover == 1)
        return (1);
    i = 0;
    FUTURE_X = env->player.pos.x + x_move;
    FUTURE_Y = env->player.pos.y + y_move;
    if (!check_ceiling(env, motion) || !check_floor(env, motion))
        return (0);
    while (i < env->sectors[env->player.sector].nb_vertices)
    {
        start_pos = (PLAYER_XPOS - X1) * (Y2 - Y1) - (PLAYER_YPOS - Y1) * (X2 - X1);
        end_pos = (FUTURE_X - X1) * (Y2 - Y1) - (FUTURE_Y - Y1) * (X2 - X1);
        motion.old_sector = env->player.sector;
        if (end_pos == 0  && check_on_wall(env, i, motion))
        {
                env->player.speed = env->player.speed * 0.7;
                return (check_collision(env, x_move * 0.7, y_move * 0.7));
        }
        if (diff_sign(start_pos, end_pos) && check_wall(env, i, motion) && NEIGHBOR < 0 && end_pos != 0)
        {
            move_alongside_wall(env, x_move, y_move, i);
            return (0);
        }
        else if (diff_sign(start_pos, end_pos) && check_wall(env, i, motion) && NEIGHBOR >= 0)
        {
            motion.wall_v1 = env->vertices[env->sectors[env->player.sector].vertices[i]].num;
            motion.wall_v2 = env->vertices[env->sectors[env->player.sector].vertices[i + 1]].num;
            motion.old_z = env->player.pos.z;
            env->player.sector = NEIGHBOR;
            if (!check_inside_sector(env, motion) || !check_ceiling(env, motion))
            {
                env->player.sector = motion.old_sector;
                env->player.pos.z = motion.old_z;
				env->player.head_z = env->player.pos.z + env->player.eyesight;
                move_alongside_wall(env, x_move, y_move, i);
                return (0);
            }
            return (1);
        }
        i++;
    }
    return (1);
}

int     is_in_sector(t_env *env, short sector, double x, double y)
{
    int     count;
    int     i;
    double  start_pos;
    double  end_pos;

    i = 0;
    count = 0;
	//ft_printf("Checking sector %d\n", sector);
	if (sector < 0 || sector >= env->nb_sectors)
		return (-1);
    while (i < env->sectors[sector].nb_vertices)
    {
        start_pos = (x - SECTOR_X1) * (SECTOR_Y2 - SECTOR_Y1) - (y - SECTOR_Y1) * (SECTOR_X2 - SECTOR_X1);
        end_pos = (env->sectors[sector].x_max + 1 - SECTOR_X1) * (SECTOR_Y2 - SECTOR_Y1) - (y - SECTOR_Y1) * (SECTOR_X2 - SECTOR_X1);
        if (diff_sign(start_pos, end_pos) && in_range(y, SECTOR_Y1, SECTOR_Y2))
            count++;
        i++;
    }
    if (count % 2 == 0)
	{
		//ft_printf("KO\n");
        return (0);
	}
	//ft_printf("OK\n");
    return (1);
}


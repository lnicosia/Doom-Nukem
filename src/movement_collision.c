/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_collision.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaerhard <gaerhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 18:54:00 by gaerhard          #+#    #+#             */
/*   Updated: 2020/03/02 10:50:51 by gaerhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "collision.h"

/*
** sets the values of sect and i by receiving their address
** Returns 0 if the floor or the ceiling is too high/low for the entity
** returns 1 if the movement is possible
*/

int		testing_portal_slide(t_env *env, t_motion motion, int *sect, int *i)
{
	if (!check_floor_ceil(env, motion, env->sectors[*sect].neighbors[*i]))
		return (0);
	env->sector_list[env->sectors[*sect].neighbors[*i]] = 1;
	*sect = env->sectors[*sect].neighbors[*i];
	*i = -1;
	return (1);
}

/*
** Returns movement vector of an entity after checking if the entity collides
** with somithing in the map
** move is the initial movemement vector
** motion contains the stats of the moving entity (hitbox_size, sector, etc...)
*/

t_v3	check_collision_slide(t_env *env, t_v3 move, t_motion motion, int sect)
{
	int		i;
	int		o_sect;

	o_sect = sect;
	motion.future = calculate_motion_future(motion, move);
	i = 0;
	while (i < env->sectors[sect].nb_vertices)
	{
		if (cross_wall(env, motion, sect, i))
			return (new_v3(0, 0, 0));
		if (cross_portal(env, motion, sect, i))
			if (!testing_portal_slide(env, motion, &sect, &i))
				return (new_v3(0, 0, 0));
		if (++i >= env->sectors[sect].nb_vertices && sect != o_sect)
		{
			i = 0;
			sect = o_sect;
		}
	}
	return (move);
}

/*
** addr.s is the number of the sector being checked
** addr.v is the number of the vertex being checked
** Thank you norminette for this horrendous code
*/

void	testing_portal(t_env *env, t_v3 *move, t_coll_addr addr)
{
	if (!check_floor_ceil(env, *(addr.motion),
		env->sectors[*(addr.s)].neighbors[*(addr.v)]))
		addr.motion->future = update_move(env, new_c(*(addr.s),
		*(addr.v), *(addr.motion)), move);
	else
	{
		env->sector_list[env->sectors[*(addr.s)].neighbors[(*addr.v)]] = 1;
		*(addr.s) = env->sectors[*(addr.s)].neighbors[*(addr.v)];
		*(addr.v) = -1;
	}
}

/*
** Returns movement vector of an entity after checking if the entity collides
** with somithing in the map
** move is the initial movemement vector
** motion contains the stats of the moving entity (hitbox_size, sector, etc...)
*/

t_v3	check_collision(t_env *env, t_v3 move, t_motion motion)
{
	int		sect;
	int		i;

	if ((sect = motion.sector) < 0)
		return (new_v3(0, 0, 0));
	motion.future = calculate_motion_future(motion, move);
	init_sector_list(env, sect);
	move = collisions_z_axis(env, motion, move);
	if (move.x == 0 && move.y == 0 && move.z == 0)
		return (move);
	i = 0;
	while (i < env->sectors[sect].nb_vertices)
	{
		if (cross_wall(env, motion, sect, i))
			motion.future = update_move(env, new_c(sect, i, motion), &move);
		if (cross_portal(env, motion, sect, i))
			testing_portal(env, &move, new_coll_addr(&motion, &sect, &i));
		if (++i >= env->sectors[sect].nb_vertices && sect != motion.sector)
			reset_loop(&i, &sect, motion);
		if (move.x == 0 && move.y == 0)
			return (move);
	}
	return (move);
}

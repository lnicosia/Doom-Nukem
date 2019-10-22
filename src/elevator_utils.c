/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   elevator_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipatry <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 10:54:04 by sipatry           #+#    #+#             */
/*   Updated: 2019/10/21 18:11:37 by sipatry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
/*
   void	create_activationg_list_sectors(t_env *env)
   {

   }

   void	create_elevator(t_env *env)
   {
   get_nb_floors(env, &env->sectors[env->player.sector]);
   create_activating_list_sectors(env);
   }
 */

void	call_elevator(t_env *env)
{
	t_sector	sector;
	int			i;
	int			calling;
	int			elevator;

	i = 0;
	while (env->sectors[sector.neighbors[i]].statue != 1)
		i++;
	elevator = sector.neighbors[i];	
	if (env->elevator.down)
	{
		env->sectors[elevator].floor -= 0.1;
		env->sectors[elevator].ceiling
			= env->sectors[elevator].floor + 10;
	}
	else if (env->elevator.up)
	{
		env->sectors[elevator].floor += 0.1;
		env->sectors[elevator].ceiling
			= env->sectors[elevator].floor + 10;
	}
	if ((env->sectors[elevator].floor > env->elevator.next_stop && env->elevator.up)
	|| (env->sectors[elevator].floor < env->elevator.next_stop && env->elevator.down))
	{
		env->sectors[env->player.sector].floor = env->elevator.next_stop;	
		env->elevator.next_stop = 0;
		env->elevator.on = 0;
		env->elevator.up = 0;
		env->elevator.down = 0;
		env->elevator.off = 1;
	}
}

void	check_up_down(t_env *env, t_sector sector)
{
	int	i;

	i = 0;
	if (!env->elevator.on)
	{
		while (i < sector.nb_vertices)
		{
			if (sector.neighbors[i] != -1)
			{
				if (env->sectors[sector.neighbors[i]].statue == 2
						&& env->sectors[sector.neighbors[i]].floor != sector.floor)
					env->elevator.next_stop = env->sectors[sector.neighbors[i]].floor;
			}
			i++;
		}
		if (env->elevator.next_stop > sector.floor)
		{
			env->elevator.down = 0;
			env->elevator.up = 1;
		}
		if (env->elevator.next_stop < sector.floor)
		{
			env->elevator.up = 0;
			env->elevator.down = 1;	
		}
	}

}

void	activate_elevator(t_env *env)
{
	int	i;
	t_sector sector;

	i = 0;
	sector = env->sectors[env->player.sector];
	if (sector.statue == 1)
	{
		check_up_down(env, sector);
		env->elevator.on = 1;
		if (env->elevator.down)
		{
			env->sectors[env->player.sector].floor -= 0.1;
			env->sectors[env->player.sector].ceiling
				= env->sectors[env->player.sector].floor + 10;
		}
		else if (env->elevator.up)
		{
			env->sectors[env->player.sector].floor += 0.1;
			env->sectors[env->player.sector].ceiling
				= env->sectors[env->player.sector].floor + 10;
		}
		if ((env->sectors[env->player.sector].floor > env->elevator.next_stop && env->elevator.up)
				|| (env->sectors[env->player.sector].floor < env->elevator.next_stop && env->elevator.down))
		{
			env->sectors[env->player.sector].floor = env->elevator.next_stop;	
			env->elevator.next_stop = 0;
			env->elevator.on = 0;
			env->elevator.up = 0;
			env->elevator.down = 0;
			env->elevator.off = 1;
		}
	}
	else
		call_elevator(env);
}

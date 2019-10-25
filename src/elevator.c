/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   elevator.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipatry <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 14:34:12 by sipatry           #+#    #+#             */
/*   Updated: 2019/10/25 15:31:02 by sipatry          ###   ########.fr       */
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
				if ((env->sectors[sector.neighbors[i]].statue == 2
							|| env->sectors[sector.neighbors[i]].statue == 1 )
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

void	find_call(t_env *env, t_sector sector, int elevator)
{
	if (env->sectors[elevator].floor > sector.floor)
	{
		env->elevator.down = 1;
		env->elevator.up = 0;
	}
	if (env->sectors[elevator].floor < sector.floor)
	{
		env->elevator.up = 1;
		env->elevator.down = 0;	
	}

}

void	call_elevator(t_env *env)
{
	t_sector	sector;
	int			i;

	i = 0;
	if (env->elevator.called_from == -1)
		env->elevator.called_from = env->player.sector;
	sector = env->sectors[env->elevator.called_from];
	if (env->elevator.sector == -1)
	{	
		while (i < sector.nb_vertices)
		{
			if (sector.neighbors[i] != -1 && env->sectors[sector.neighbors[i]].statue == 1)
				env->elevator.sector = sector.neighbors[i];
			i++;
		}
	}
	if ((env->sectors[env->elevator.sector].floor != env->sectors[env->elevator.called_from].floor) || env->elevator.call)
	{
		env->elevator.call = 1;
		find_call(env, sector, env->elevator.sector);
		env->elevator.on = 1;
		if (env->elevator.down)
		{
			env->sectors[env->elevator.sector].floor -= 0.1;
			env->sectors[env->elevator.sector].ceiling
				= env->sectors[env->elevator.sector].floor + 10;
		}
		else if (env->elevator.up)
		{
			env->sectors[env->elevator.sector].floor += 0.1;
			env->sectors[env->elevator.sector].ceiling
				= env->sectors[env->elevator.sector].floor + 10;
		}
		update_sector_slope(env, &env->sectors[env->elevator.sector]);
		if ((env->sectors[env->elevator.sector].floor > env->sectors[env->elevator.called_from].floor && env->elevator.up)
				|| (env->sectors[env->elevator.sector].floor < env->sectors[env->elevator.called_from].floor && env->elevator.down))
		{
			env->sectors[env->elevator.sector].floor = env->sectors[env->elevator.called_from].floor;	
			env->elevator.next_stop = 0;
			env->elevator.on = 0;
			env->elevator.up = 0;
			env->elevator.down = 0;
			env->elevator.off = 1;
			env->elevator.sector = -1;
			env->elevator.call = 0;
			env->elevator.called_from = -1;
		}
	}
	else
	{
		env->elevator.called_from = -1;
	}
}

void	activate_elevator(t_env *env)
{
	int	i;
	t_sector sector;

	i = 0;
	sector = env->sectors[env->player.sector];
	if (sector.statue == 1 && !env->elevator.call)
	{
		check_up_down(env, sector);
		env->elevator.on = 1;
		if (env->elevator.down)
		{
			env->sectors[env->elevator.sector].floor -= 0.1;
			env->sectors[env->elevator.sector].ceiling
				= env->sectors[env->player.sector].floor + 10;
		}
		else if (env->elevator.up)
		{
			env->sectors[env->elevator.sector].floor += 0.1;
			env->sectors[env->elevator.sector].ceiling
				= env->sectors[env->elevator.sector].floor + 10;
		}
		if ((env->sectors[env->elevator.sector].floor > env->elevator.next_stop && env->elevator.up)
				|| (env->sectors[env->elevator.sector].floor < env->elevator.next_stop && env->elevator.down))
		{
			env->sectors[env->elevator.sector].floor = env->elevator.next_stop;	
			env->elevator.next_stop = 0;
			env->elevator.on = 0;
			env->elevator.up = 0;
			env->elevator.down = 0;
			env->elevator.off = 1;
			env->elevator.sector = -1;
		}
		update_sector_slope(env, &env->sectors[env->player.sector]);
	}
	else
		call_elevator(env);
}

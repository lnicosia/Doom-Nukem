/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   elevator.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipatry <sipatry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 14:34:12 by sipatry           #+#    #+#             */
/*   Updated: 2019/10/29 14:05:22 by sipatry          ###   ########.fr       */
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
				if ((env->sectors[sector.neighbors[i]].status == 2
				|| env->sectors[sector.neighbors[i]].status == 1 )
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
	double		time;
	double		new_floor;

	i = 0;
	if (env->elevator.called_from == -1)
		env->elevator.called_from = env->player.sector;
	sector = env->sectors[env->elevator.called_from];
	if (env->elevator.sector == -1)
	{	
		while (i < sector.nb_vertices)
		{
			if (sector.neighbors[i] != -1 && env->sectors[sector.neighbors[i]].status == 1)
				env->elevator.sector = sector.neighbors[i];
			i++;
		}
	}
	if ((env->sectors[env->elevator.sector].floor
	!= env->sectors[env->elevator.called_from].floor) || env->elevator.call)
	{
		time = SDL_GetTicks();
		env->elevator.call = 1;
		find_call(env, sector, env->elevator.sector);
		env->elevator.on = 1;
		if (!env->elevator.time)
		{
			env->elevator.start_floor = env->sectors[env->elevator.sector].floor;
			env->elevator.time = SDL_GetTicks();
		}
		env->time.d_time = time - env->elevator.time;
		if (env->elevator.down)
		{
			new_floor = env->elevator.start_floor - (env->elevator.speed * env->time.d_time);
			env->sectors[env->elevator.sector].floor = new_floor;
			env->sectors[env->elevator.sector].ceiling
				= env->sectors[env->elevator.sector].floor + 10;
		}
		else if (env->elevator.up)
		{
			new_floor = env->elevator.start_floor + (env->elevator.speed * env->time.d_time);
			env->sectors[env->elevator.sector].floor = new_floor;
			env->sectors[env->elevator.sector].ceiling
				= env->sectors[env->elevator.sector].floor + 10;
		}
		update_sector_slope(env, &env->sectors[env->elevator.sector]);
		if ((env->sectors[env->elevator.sector].floor > env->sectors[env->elevator.called_from].floor && env->elevator.up)
				|| (env->sectors[env->elevator.sector].floor < env->sectors[env->elevator.called_from].floor && env->elevator.down))
		{
			env->sectors[env->elevator.sector].floor = env->sectors[env->elevator.called_from].floor;
			env->sectors[env->elevator.sector].ceiling
				= env->sectors[env->elevator.sector].floor + 10;
			update_sector_slope(env, &env->sectors[env->elevator.sector]);
			env->elevator.next_stop = 0;
			env->elevator.on = 0;
			env->elevator.up = 0;
			env->elevator.down = 0;
			env->elevator.off = 1;
			env->elevator.sector = -1;
			env->elevator.call = 0;
			env->elevator.called_from = -1;
			env->elevator.time = 0;
		}	
	}
	else
	{
		env->elevator.called_from = -1;
		env->elevator.sector = -1;
	}
}

void	activate_elevator(t_env *env)
{
	int		i;
	double		time;
	t_sector	sector;
	double		new_floor;

	i = 0;
	time = 0;
	new_floor = 0;
	sector = env->sectors[env->player.sector];
	if ((sector.status == 1 && !env->elevator.call) || env->elevator.used)
	{
		check_up_down(env, sector);
		env->elevator.on = 1;
		env->elevator.used = 1;
		if (env->elevator.used)
		{
			time = SDL_GetTicks();
		}
		if (env->elevator.sector == -1)
			env->elevator.sector = env->player.sector;
		if (!env->elevator.time)
		{
			env->elevator.start_floor = env->sectors[env->elevator.sector].floor;
			env->elevator.time = SDL_GetTicks();
		}
;		env->time.d_time = time - env->elevator.time;
		if (env->elevator.down)
		{
			new_floor = env->elevator.start_floor - (env->elevator.speed * env->time.d_time);
			env->sectors[env->elevator.sector].floor = new_floor;
			env->sectors[env->elevator.sector].ceiling
				= env->sectors[env->player.sector].floor + 10;
		}
		else if (env->elevator.up)
		{
			new_floor = env->elevator.start_floor + (env->elevator.speed * env->time.d_time);
			env->sectors[env->elevator.sector].floor = new_floor;
			env->sectors[env->elevator.sector].ceiling
				= env->sectors[env->elevator.sector].floor + 10;
		}
		update_sector_slope(env, &env->sectors[env->elevator.sector]);
		if ((env->sectors[env->elevator.sector].floor > env->elevator.next_stop && env->elevator.up)
				|| (env->sectors[env->elevator.sector].floor < env->elevator.next_stop && env->elevator.down))
		{
			env->sectors[env->elevator.sector].floor = env->elevator.next_stop;
			env->sectors[env->elevator.sector].ceiling
				= env->sectors[env->elevator.sector].floor + 10;
			update_sector_slope(env, &env->sectors[env->elevator.sector]);
			env->elevator.next_stop = 0;
			env->elevator.on = 0;
			env->elevator.up = 0;
			env->elevator.down = 0;
			env->elevator.off = 1;
			env->elevator.sector = -1;
			env->elevator.used  = 0;
			env->time.d_time = 0;
			env->elevator.time = 0;
			env->elevator.start_floor = 0;
		}
		ft_printf("player_z: %f | floor: %f\n", env->player.pos.z, env->sectors[env->elevator.sector].floor);
		update_player_z(env);
	}
	else if (!env->elevator.used)
		call_elevator(env);
}

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

	i= 0;
	sector = env->sectors[env->player.sector];
	while (env->sectors[sector.neighbors[i]].statue != 1)
		i++;
	calling = env->sectors[sector.neighbors[i]].floor > sector.floor ? 0 : 1;
	if (calling)
	{
		while (env->sectors[sector.neighbors[i]].floor > sector.floor)
			env->sectors[sector.neighbors[i]].floor -= 0.05;
	}
	else
	{
		while (env->sectors[sector.neighbors[i]].floor < sector.floor)
			env->sectors[sector.neighbors[i]].floor += 0.05;
	}
}

void	activate_elevator(t_env *env)
{
	int	i;
	int	on;
	t_sector sector;

	i = 0;
	on = 0;
	sector = env->sectors[env->player.sector];
	env->elevator.up = 1;
	env->elevator.down = 0;
	if (sector.statue == 1)
	{
		if (env->elevator.down)
		{
			while (sector.floor > 6)
				env->sectors[sector.neighbors[i]].floor -= 0.05;
		}
		else if (env->elevator.up)
		{
		//	ft_printf("up\n");
		/*	while (sector.floor < 20)
			{
				env->sectors[env->player.sector].floor += 0.05;
				env->sectors[env->player.sector].ceiling
				= env->sectors[env->player.sector].floor + 10;
			}*/
		}
	}
	else
		call_elevator(env);
	env->elevator.down = 1;
	env->elevator.up = 0;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_sector.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipatry <sipatry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 17:17:28 by sipatry           #+#    #+#             */
/*   Updated: 2019/11/27 11:56:46 by sipatry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

int	check_sectors(t_env *env)
{
	int	i;
	int	j;
	int	first;

	first = 0;
	i = 0;
	while (i < env->nb_sectors)
	{
		j = 0;
		while (j < env->sectors[i].nb_vertices)
		{
			if ((env->sectors[i].vertices[j] == env->editor.split.v1
			|| env->sectors[i].vertices[j] == env->editor.split.v2) && !first)
				first = 1;
			else if (first && (env->sectors[i].vertices[j] == env->editor.split.v1
			|| env->sectors[i].vertices[j] == env->editor.split.v2))
			{
				env->editor.split.sector = i;
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

int	check_pos_vertices(t_env *env)
{
	t_list	*tmp;

	tmp = env->editor.current_vertices;
	env->editor.split.v1 = ((t_vertex*)tmp->content)->num;
	tmp = env->editor.current_vertices->next;
	env->editor.split.v2 = ((t_vertex*)tmp->content)->num;
	if (check_sectors(env))
		return (1);
	return (0);
}

void	update_neighbor(t_env *env, int index, t_sector *sector)
{

	env->sectors[sector->neighbors[index]].neighbors

}

void	update_sector_data(t_env *env, int start, int end, t_sector *sector)
{
	int	i;

	i = start + 1;
	
	while (i < end)
	{
		update_neighbors(env, start, end, sector);

		i++;
	}
}

int		create_new_sector(t_env *env, int start, int end, t_sector *sector)
{
	int	i;

	i = start;
	while (i <= end)
	{
		add_vertex_to_current_sector(env, sector->vertices[i]);
		i++;
	}
	env->editor.reverted = get_clockwise_order(env) ? 0 : 1;
	env->editor.start_vertex = -1;
	if (add_sector(env))
		return (ft_printf("Error while creating new sector\n"));
	return (0);
}

void	split_sector(t_env *env)
{
	int			i;
	int			start;
	int			end;
	t_sector	*sector;

	i = 0;
	start = -1;
	end = -1;
	sector = &env->sectors[env->editor.split.sector];
	while (i < sector->nb_vertices)
	{
		if (start == -1 && (sector->vertices[i] == env->editor.split.v1
		|| sector->vertices[i] == env->editor.split.v2))
			start = i;
		else if (start != -1 && (sector->vertices[i] == env->editor.split.v1
		|| sector->vertices[i] == env->editor.split.v2))
			end = i;
		i++;
	}
	free_current_vertices(env);
	ft_printf("IN: nb_sectors: %d\n", env->nb_sectors);
	create_new_sector(env, start, end, sector);
	ft_printf("OUT: nb_sectors: %d\n", env->nb_sectors);

	//update_sector_data(env, start, end , sector);
	free_current_vertices(env);
}
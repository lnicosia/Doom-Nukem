/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_new_sector.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/29 11:19:19 by lnicosia          #+#    #+#             */
/*   Updated: 2019/08/26 17:50:26 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

void	revert_sector(t_sector *sector, t_env *env)
{
	int			i;
	int			index;
	int			j;
	short		*tmp;

	i = 1;
	j = 1;
	if (!(tmp = (short *)malloc(sizeof(short) * (sector->nb_vertices + 1))))
		return ;
	tmp[0] = sector->vertices[0];
	while (i < sector->nb_vertices)
	{
		if (env->editor.reverted)
			index = sector->nb_vertices - j;
		else
			index = j;
		tmp[i] = sector->vertices[index];
		i++;
		j++;
	}
	if (!env->editor.reverted)
		tmp[sector->nb_vertices] = tmp[0];
	else
		tmp[0] = tmp[sector->nb_vertices];
	free(sector->vertices);
	sector->vertices = tmp;
}

void	fill_new_sector(t_sector *sector, t_env *env)
{
	int			i;
	int			index;
	t_list		*tmp;
	t_vertex	*vertex;

	tmp = env->editor.current_vertices;
	i = 0;
	while (tmp)
	{
		vertex = (t_vertex*)tmp->content;
		if (env->editor.reverted)
			index = sector->nb_vertices - i;
		else
			index = i;
		sector->vertices[index] = vertex->num;
		sector->neighbors[index] = -1;
		sector->textures[index] = 0;
		tmp = tmp->next;
		i++;
	}
	if (!env->editor.reverted)
	{
		sector->vertices[sector->nb_vertices] = sector->vertices[0];
		sector->neighbors[sector->nb_vertices] = sector->neighbors[0];
		sector->textures[sector->nb_vertices] = sector->textures[0];
	}
	else
	{
		sector->vertices[0] = sector->vertices[sector->nb_vertices];
		sector->neighbors[0] = sector->neighbors[sector->nb_vertices];
		sector->textures[0] = sector->textures[sector->nb_vertices];
	}
}

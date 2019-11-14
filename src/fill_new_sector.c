/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_new_sector.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/01 16:05:01 by lnicosia          #+#    #+#             */
/*   Updated: 2019/11/14 11:10:14 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

//	PROTECTION!!

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
	tmp[sector->nb_vertices] = tmp[0];
	free(sector->vertices);
	sector->vertices = tmp;
}

//	PROTECTION!!

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
		sector->textures[index] = 32;
		sector->nb_sprites[index] = 0;
		sector->align[index] = new_v2(0, 0);
		sector->scale[index] = new_v2(env->textures[sector->textures[index]].surface->w,
env->textures[sector->textures[index]].surface->h);
		tmp = tmp->next;
		i++;
	}
	if (!env->editor.reverted)
	{
		sector->vertices[sector->nb_vertices] = sector->vertices[0];
		sector->neighbors[sector->nb_vertices] = sector->neighbors[0];
		sector->textures[sector->nb_vertices] = sector->textures[0];
		sector->sprites[sector->nb_vertices] = sector->sprites[0];
		sector->align[sector->nb_vertices] = sector->align[0];
		sector->scale[sector->nb_vertices] = sector->scale[0];
		sector->nb_sprites[sector->nb_vertices] = 0;
	}
	else
	{
		sector->vertices[0] = sector->vertices[sector->nb_vertices];
		sector->neighbors[0] = sector->neighbors[sector->nb_vertices];
		sector->textures[0] = sector->textures[sector->nb_vertices];
		sector->sprites[0] = sector->sprites[sector->nb_vertices];
		sector->align[0] = sector->align[sector->nb_vertices];
		sector->scale[0] = sector->scale[sector->nb_vertices];
		sector->nb_sprites[0] = 0;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_sector2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/01 10:49:53 by lnicosia          #+#    #+#             */
/*   Updated: 2020/05/01 10:49:54 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

void	update_neighbors_indexes(t_env *env, int index, int num,
t_sector *sector)
{
	int	i;
	int	j;

	i = 0;
	while (i < sector->nb_vertices)
	{
		if (sector->neighbors[index] != -1)
		{
			j = 0;
			while (j < env->sectors[sector->neighbors[index]].nb_vertices)
			{
				if (env->sectors[sector->neighbors[index]].
					neighbors[j] == num)
					env->sectors[sector->neighbors[index]].
					neighbors[j] = env->nb_sectors - 1;
				j++;
			}
		}
		i++;
	}
}

int		update_neighbors(t_env *env, int index, int num, t_sector *sector)
{
	int	i;

	if (index == 1)
		return (0);
	update_neighbors_indexes(env, index, num, sector);
	i = 0;
	while (i < sector->nb_vertices)
	{
		if (sector->neighbors[i] == num)
			update_int_tab(i, sector->nb_vertices + 1, &sector->neighbors);
		i++;
	}
	return (0);
}

void	update_current_wall2(t_env *env, int i, t_sector *sector)
{
	update_double_tab(i, sector->nb_vertices + 1,
	&env->sectors[sector->num].clipped_floors1);
	update_double_tab(i, sector->nb_vertices + 1,
	&env->sectors[sector->num].clipped_floors2);
	update_double_tab(i, sector->nb_vertices + 1,
	&env->sectors[sector->num].clipped_ceilings1);
	update_double_tab(i, sector->nb_vertices + 1,
	&env->sectors[sector->num].clipped_ceilings2);
	update_double_tab(i, sector->nb_vertices + 1,
	&env->sectors[sector->num].wall_width);
	update_t_v2_tab(i, sector->nb_vertices + 1,
	&env->sectors[sector->num].scale);
	update_t_v2_tab(i, sector->nb_vertices + 1,
	&env->sectors[sector->num].align);
	update_t_list_tab(i, sector->nb_vertices + 1,
	&env->sectors[sector->num].wall_bullet_holes);
	update_t_wall_sprite_tab(i, sector->nb_vertices + 1,
	&env->sectors[sector->num].wall_sprites);
	ft_memdel((void**)&sector->walls_map_lvl[i]);
	update_walls_map_lvl_tab(i, sector->nb_vertices + 1,
	&env->sectors[sector->num].walls_map_lvl);
	sector->nb_vertices--;
}

int		update_current_wall(t_env *env, int i, t_sector *sector)
{
	update_neighbors(env, i, sector->vertices[i], sector);
	update_int_tab(i, sector->nb_vertices + 1,
	&env->sectors[sector->num].vertices);
	update_int_tab(i, sector->nb_vertices + 1,
	&env->sectors[sector->num].textures);
	update_int_tab(i, sector->nb_vertices + 1,
	&env->sectors[sector->num].selected);
	update_int_tab(i, sector->nb_vertices + 1,
	&env->sectors[sector->num].portals);
	update_double_tab(i, sector->nb_vertices + 1,
	&env->sectors[sector->num].floors);
	update_double_tab(i, sector->nb_vertices + 1,
	&env->sectors[sector->num].ceilings);
	update_current_wall2(env, i, sector);
	if (!sector->neighbors || !sector->wall_sprites || !sector->walls_map_lvl
		|| !sector->wall_width || !sector->floors
		|| !sector->ceilings || !sector->vertices
		|| !sector->portals || !sector->textures
		|| !sector->wall_bullet_holes || !sector->scale
		|| !sector->align || !sector->selected)
		return (-1);
	return (0);
}

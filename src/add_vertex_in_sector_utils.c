/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_vertex_in_sector_utils.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/28 16:21:28 by lnicosia          #+#    #+#             */
/*   Updated: 2020/04/28 16:21:29 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "add_vertex.h"
#include "collision.h"
#include <math.h>

int		is_sector_clicked(t_sector *sector, int j, int v1, int v2)
{
	if (((j > 0 && sector->vertices[j] == v1
		&& (sector->vertices[j - 1] == v2
		|| sector->vertices[j + 1] == v2)))
		|| (sector->vertices[j] == v1 && j == 0
		&& (sector->vertices[sector->nb_vertices - 1] == v2
		|| sector->vertices[j + 1] == v2)))
		return (1);
	return (0);
}

int		*get_sectors_list(t_env *env, int v1, int v2)
{
	int	*sectors;
	int	i;
	int	j;
	int	k;

	i = -1;
	k = 1;
	sectors = NULL;
	while (++i < env->nb_sectors)
	{
		j = -1;
		while (++j < env->sectors[i].nb_vertices)
		{
			if (!is_sector_clicked(&env->sectors[i], j, v1, v2))
				continue;
			if (!(sectors = (int *)ft_realloc(sectors,
				sizeof(int) * k, sizeof(int) * (k + 1))))
				return (0);
			sectors[k] = i;
			k++;
		}
	}
	sectors[0] = k - 1;
	return (k != 1 ? sectors : NULL);
}

int		is_mouse_on_a_wall(t_env *env)
{
	int		i;
	int		j;

	i = -1;
	while (++i < env->nb_sectors)
	{
		j = -1;
		while (++j < env->sectors[i].nb_vertices)
		{
			if (get_existing_vertex(env) != -1)
				return (0);
			if (!hitbox_collision(new_v2(env->vertices[env->sectors[i].
				vertices[j]].x, env->vertices[env->sectors[i].vertices[j]].y),
				new_v2(env->vertices[env->sectors[i].vertices[j + 1]].x,
				env->vertices[env->sectors[i].vertices[j + 1]].y),
				new_v2(round((env->sdl.mx - env->editor.center.x) /
				env->editor.scale), round((env->sdl.my - env->editor.
				center.y) / env->editor.scale)), 0.5))
				continue;
			env->editor.add.v1 = env->sectors[i].vertices[j];
			env->editor.add.v2 = env->sectors[i].vertices[j + 1];
			return (1);
		}
	}
	return (0);
}

int		modify_vertices_in_sector(t_env *env, int index, int sector)
{
	int	i;

	if (!(env->sectors[sector].vertices =
		(int *)ft_realloc(env->sectors[sector].vertices,
		sizeof(int) * (env->sectors[sector].nb_vertices + 1),
		sizeof(int) * (env->sectors[sector].nb_vertices + 2))))
		return (ft_perror("Could not realloc vertices"));
	env->sectors[sector].nb_vertices++;
	i = env->sectors[sector].nb_vertices;
	while (i > index + 1)
	{
		env->sectors[sector].vertices[i] = env->sectors[sector].vertices[i - 1];
		i--;
	}
	env->sectors[sector].vertices[i] = env->vertices[env->nb_vertices - 1].num;
	env->sectors[sector].vertices[env->sectors[sector].nb_vertices] =
	env->sectors[sector].vertices[0];
	return (0);
}

int		modify_textures(t_env *env, int index, int sector)
{
	int	i;

	if (!(env->sectors[sector].textures =
		(int *)ft_realloc(env->sectors[sector].textures,
		sizeof(int) * env->sectors[sector].nb_vertices,
		sizeof(int) * (env->sectors[sector].nb_vertices + 1))))
		return (ft_perror("Could not realloc textures"));
	i = env->sectors[sector].nb_vertices;
	while (i > index + 1)
	{
		env->sectors[sector].textures[i] = env->sectors[sector].textures[i - 1];
		i--;
	}
	env->sectors[sector].textures[i] = env->sectors[sector].textures[i - 1];
	return (0);
}

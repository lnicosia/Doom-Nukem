/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_vertex_in_sector_utils2.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/28 16:16:41 by lnicosia          #+#    #+#             */
/*   Updated: 2020/04/28 16:37:54 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "add_vertex.h"

int		modify_double_tab_in_sector(t_env *env, int index, int sector,
double **tab)
{
	int	i;

	if (!(*tab = (double *)ft_realloc(*tab,
		sizeof(double) * env->sectors[sector].nb_vertices,
		sizeof(double) * (env->sectors[sector].nb_vertices + 1))))
		return (ft_perror("Could not realloc double tab"));
	i = env->sectors[sector].nb_vertices;
	while (i > index + 1)
	{
		(*tab)[i] = (*tab)[i - 1];
		i--;
	}
	(*tab)[i] = (*tab)[i - 1];
	return (0);
}

int		modify_int_tab_in_sector(t_env *env, int index, int sector, int **tab)
{
	int	i;

	if (!(*tab = (int*)ft_realloc(*tab,
		sizeof(int) * env->sectors[sector].nb_vertices,
		sizeof(int) * (env->sectors[sector].nb_vertices + 1))))
		return (ft_perror("Could not realloc int tab"));
	i = env->sectors[sector].nb_vertices;
	while (i > index + 1)
	{
		(*tab)[i] = (*tab)[i - 1];
		i--;
	}
	(*tab)[i] = (*tab)[i - 1];
	return (0);
}

int		modify_t_v2_tab_in_sector(t_env *env, int index, int sector, t_v2 **tab)
{
	int		i;

	if (!(*tab = (t_v2*)ft_realloc(*tab,
		sizeof(t_v2) * env->sectors[sector].nb_vertices,
		sizeof(t_v2) * (env->sectors[sector].nb_vertices + 1))))
		return (ft_perror("Could not realloc int tab"));
	i = env->sectors[sector].nb_vertices;
	while (i > index + 1)
	{
		(*tab)[i] = (*tab)[i - 1];
		i--;
	}
	(*tab)[i] = (*tab)[i - 1];
	return (0);
}

int		modify_t_wall_sprites_tab_in_sector(t_env *env, int index, int sector,
t_wall_sprites **tab)
{
	int	i;

	(void)index;
	if (!(*tab = (t_wall_sprites*)ft_realloc(*tab,
		sizeof(t_wall_sprites) * env->sectors[sector].nb_vertices,
		sizeof(t_wall_sprites) * (env->sectors[sector].nb_vertices + 1))))
		return (ft_perror("Could not realloc t_wall_sprites tab"));
	i = env->sectors[sector].nb_vertices - 1;
	while (i > index + 1)
	{
		ft_memmove(&(*tab)[i], &(*tab)[i - 1], sizeof(t_wall_sprites));
		i--;
	}
	ft_bzero(&(*tab)[i], sizeof(t_wall_sprites));
	return (0);
}

int		modify_t_list_tab_in_sector(t_env *env, int index, int sector,
t_list ***tab)
{
	int	i;

	(void)index;
	if (!(*tab = (t_list**)ft_realloc(*tab,
		sizeof(t_list*) * env->sectors[sector].nb_vertices,
		sizeof(t_list*) * (env->sectors[sector].nb_vertices + 1))))
		return (ft_perror("Could not realloc t_list tab"));
	i = env->sectors[sector].nb_vertices;
	ft_bzero(&(*tab)[i], sizeof(t_list*));
	return (0);
}

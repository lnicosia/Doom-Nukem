/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_sector.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/29 10:01:25 by lnicosia          #+#    #+#             */
/*   Updated: 2019/07/29 11:55:37 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

int			init_new_sector_arrays(t_sector *sector)
{
	if (!(sector->vertices = (short*)malloc(sizeof(short) * (sector->nb_vertices + 1))))
		return (ft_printf("could not malloc sector vertices\n"));
	if (!(sector->neighbors = (short*)malloc(sizeof(short) * sector->nb_vertices)))
		return (ft_printf("Could not malloc sector neighbors\n"));
	if (!(sector->textures = (short*)malloc(sizeof(short) * (sector->nb_vertices + 1))))
		return (ft_printf("Could not malloc sector textures\n"));
	if (!(sector->ceilings = (double*)malloc(sizeof(double) * (sector->nb_vertices + 1))))
		return (ft_printf("Could not malloc sector ceilings\n"));
	if (!(sector->floors = (double*)malloc(sizeof(double) * (sector->nb_vertices + 1))))
		return (ft_printf("Could not malloc sector floors\n"));
	if (!(sector->clipped_ceilings1 = (double*)malloc(sizeof(double) * (sector->nb_vertices + 1))))
		return (ft_printf("Could not malloc sector clipped_ceilings1\n"));
	if (!(sector->clipped_ceilings2 = (double*)malloc(sizeof(double) * (sector->nb_vertices + 1))))
		return (ft_printf("Could not malloc sector clipped_ceilings2\n"));
	if (!(sector->clipped_floors1 = (double*)malloc(sizeof(double) * (sector->nb_vertices + 1))))
		return (ft_printf("Could not malloc sector clipped_floors1\n"));
	if (!(sector->clipped_floors2 = (double*)malloc(sizeof(double) * (sector->nb_vertices + 1))))
		return (ft_printf("Could not malloc sector clipped_floors2\n"));
	if (!(sector->wall_width = (double*)malloc(sizeof(double) * (sector->nb_vertices + 1))))
		return (ft_printf("could not malloc sector vertices\n"));
	return (0);
}

int			get_new_sector_len(t_env *env)
{
	t_list	*tmp;
	int		res;

	tmp = env->editor.current_vertices;
	res = 0;
	while (tmp)
	{
		res++;
		tmp = tmp->next;
	}
	return (res);
}

t_sector	new_default_sector(t_env *env)
{
	t_sector	sector;

	sector.floor = 0;
	sector.floor_slope = 0;
	sector.floor_texture = 4;
	sector.ceiling = 12;
	sector.ceiling_slope = 0;
	sector.ceiling_texture = 4;
	sector.light = 100;
	sector.num = env->nb_sectors;
	sector.nb_vertices = get_new_sector_len(env);
	return (sector);
}

int			create_sector(t_env *env)
{
	t_sector	sector;

	sector = new_default_sector(env);
	if (init_new_sector_arrays(&sector))
		return (ft_printf("Error while initializing new sector arrays\n"));
	fill_new_sector(&sector, env);
	//sector.normal = get_sector_normal(sector, env);
	//update_sector_slope(env, &sector);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_sector.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipatry <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 12:06:46 by sipatry           #+#    #+#             */
/*   Updated: 2019/09/11 12:15:38 by sipatry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

int			init_new_sector_arrays(t_sector *sector)
{
	if (!(sector->vertices = (short*)malloc(sizeof(short) * (sector->nb_vertices + 1))))
		return (ft_perror("Could not malloc sector vertices"));
	if (!(sector->neighbors = (short*)malloc(sizeof(short) * (sector->nb_vertices + 1))))
		return (ft_perror("Could not malloc sector neighbors"));
	if (!(sector->textures = (short*)malloc(sizeof(short) * (sector->nb_vertices + 1))))
		return (ft_perror("Could not malloc sector textures"));
	if (!(sector->ceilings = (double*)malloc(sizeof(double) * (sector->nb_vertices + 1))))
		return (ft_perror("Could not malloc sector ceilings"));
	if (!(sector->floors = (double*)malloc(sizeof(double) * (sector->nb_vertices + 1))))
		return (ft_perror("Could not malloc sector floors"));
	if (!(sector->clipped_ceilings1 = (double*)malloc(sizeof(double) * (sector->nb_vertices + 1))))
		return (ft_perror("Could not malloc sector clipped_ceilings1"));
	if (!(sector->clipped_ceilings2 = (double*)malloc(sizeof(double) * (sector->nb_vertices + 1))))
		return (ft_perror("Could not malloc sector clipped_ceilings2"));
	if (!(sector->clipped_floors1 = (double*)malloc(sizeof(double) * (sector->nb_vertices + 1))))
		return (ft_perror("Could not malloc sector clipped_floors1"));
	if (!(sector->clipped_floors2 = (double*)malloc(sizeof(double) * (sector->nb_vertices + 1))))
		return (ft_perror("Could not malloc sector clipped_floors2"));
	if (!(sector->wall_width = (double*)malloc(sizeof(double) * (sector->nb_vertices + 1))))
		return (ft_perror("could not malloc sector vertices"));
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
	sector.light_color = 0xFFFFFFFF;
	sector.brightness = 0;
	sector.skybox = 0;
	sector.num = env->nb_sectors;
	sector.x_max = -2147483648;
	sector.nb_vertices = get_new_sector_len(env);
	return (sector);
}

int			add_sector(t_env *env)
{
	t_sector	sector;

	sector = new_default_sector(env);
	if (init_new_sector_arrays(&sector))
		return (ft_printf("Error while initializing new sector arrays\n"));
	fill_new_sector(&sector, env);
	sector.normal = get_sector_normal(sector, env);
	update_sector_slope(env, &sector);
	if (!(env->sectors = (t_sector*)ft_realloc(env->sectors,
					sizeof(t_sector) * env->nb_sectors,
					sizeof(t_sector) * (env->nb_sectors + 1))))
		return (ft_printf("Could not realloc sectors\n"));
	env->sectors[env->nb_sectors] = sector;
	create_portals(env, sector);
	set_sectors_xmax(env);
	env->nb_sectors++;
	return (0);
}

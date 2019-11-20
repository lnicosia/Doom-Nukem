/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_sector.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipatry <sipatry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 12:06:46 by sipatry           #+#    #+#             */
/*   Updated: 2019/11/20 08:47:16 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

void	get_new_floor_and_ceiling(t_env *env)
{
	t_sector sector;
	int		i;
	int		flag;

	flag = 0;
	i = 0;
	sector = env->sectors[env->nb_sectors - 1];
	while (i < sector.nb_vertices)
	{
		if (sector.neighbors[i] != -1)
		{
			if (!flag)
			{
				flag = 1;
				sector.floor = env->sectors[sector.neighbors[i]].floor;
				sector.ceiling = env->sectors[sector.neighbors[i]].ceiling;
			}
			if (sector.floor > env->sectors[sector.neighbors[i]].floor)
				sector.floor = env->sectors[sector.neighbors[i]].floor;
			if (sector.ceiling < env->sectors[sector.neighbors[i]].ceiling)
				sector.ceiling = env->sectors[sector.neighbors[i]].ceiling;

		}
		i++;
	}
	env->sectors[env->nb_sectors - 1].floor = sector.floor;
	env->sectors[env->nb_sectors - 1].ceiling = sector.ceiling;
}

int			init_new_sector_arrays(t_sector *sector, t_env *env)
{
	if (!(sector->vertices = (short*)malloc(sizeof(short) * (sector->nb_vertices + 1))))
		return (ft_perror("Could not malloc sector vertices"));
	if (!(sector->neighbors = (short*)malloc(sizeof(short) * (sector->nb_vertices + 1))))
		return (ft_perror("Could not malloc sector neighbors"));
	if (!(sector->textures = (short*)malloc(sizeof(short) * (sector->nb_vertices + 1))))
		return (ft_perror("Could not malloc sector textures"));
	if (!(sector->nb_sprites = (short*)malloc(sizeof(short) * (sector->nb_vertices + 1))))
		return (ft_perror("Could not malloc sector vertices"));
	if (!(sector->sprites = (t_wall_sprites*)malloc(sizeof(t_wall_sprites) * (sector->nb_vertices + 1))))
		return (ft_perror("Could not malloc sector textures"));
	if (!(sector->align = (t_v2*)malloc(sizeof(t_v2) * (sector->nb_vertices + 1))))
		return (ft_perror("Could not malloc sector align"));
	if (!(sector->scale = (t_v2*)malloc(sizeof(t_v2) * (sector->nb_vertices + 1))))
		return (ft_perror("Could not malloc sector scale"));
	if (!(sector->selected = (short*)malloc(sizeof(short) * (sector->nb_vertices + 1))))
		return (ft_perror("Could not malloc sector vertices"));
	if (!(sector->ceilings = (double*)malloc(sizeof(double) * (sector->nb_vertices + 1))))
		return (ft_perror("Could not malloc sector ceiling"));
	(void)env;
	/*if (!(sector->ceiling_map_lvl = (double*)malloc(sizeof(double) * env->wall_textures[sector->ceiling_texture].nb_maps)))
		return (ft_perror("Could not malloc sector ceiling texture"));
	if (!(sector->ceiling_scale = (t_v2*)malloc(
		sizeof(t_v2) * env->wall_textures[sector->ceiling_texture].nb_maps)))
		return (custom_error("Could not malloc sector floor_scale array"));
	if (!(sector->floor_map_lvl = (double*)malloc(sizeof(double) * env->wall_textures[sector->floor_texture].nb_maps)))
		return (ft_perror("Could not malloc sector ceiling texture"));
	if (!(sector->floor_scale = (t_v2*)malloc(
		sizeof(t_v2) * env->wall_textures[sector->floor_texture].nb_maps)))
		return (custom_error("Could not malloc sector floor_scale array"));*/
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
	if (!(sector->xmin = (int*)malloc(sizeof(int) * (sector->nb_vertices + 1))))
		return (ft_perror("Could not malloc sector textures"));
	if (!(sector->xmax = (int*)malloc(sizeof(int) * (sector->nb_vertices + 1))))
		return (ft_perror("Could not malloc sector textures"));
	if (!(sector->walls_map_lvl = (double**)
				malloc(sizeof(double*) * (sector->nb_vertices + 1))))
		return (ft_perror("Could not malloc sector vertices:"));
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

	ft_bzero(&sector, sizeof(sector));
	sector.floor = 0;
	sector.floor_slope = 0;
	sector.floor_texture = 4;
	sector.ceiling = 10;
	sector.ceiling_slope = 0;
	sector.ceiling_texture = 4;
	sector.floor_map_scale = new_v2(10, 10);
	sector.ceiling_map_scale = new_v2(10, 10);
	//sector.floor_scale.x = env->wall_textures[sector.floor_texture].surface->w / 10;
	//sector.floor_scale.y = env->wall_textures[sector.floor_texture].surface->h / 10;
	//sector.ceiling_scale = sector.floor_scale;
	sector.floor_align = new_v2(0, 0);
	sector.ceiling_align = new_v2(0, 0);
	sector.light_color = 0xFFFFFFFF;
	sector.brightness = 0;
	sector.skybox = 0;
	sector.num = env->nb_sectors;
	sector.x_max = -2147483648;
	sector.nb_vertices = get_new_sector_len(env);
	sector.status = 0;
	sector.enemy_flag = -1;
	sector.activated = 0;
	sector.start_floor = sector.floor;
	return (sector);
}

int			add_sector(t_env *env)
{
	t_sector	sector;

	sector = new_default_sector(env);
	if (init_new_sector_arrays(&sector, env))
		return (ft_printf("Error while initializing new sector arrays\n"));
	if (set_sector_floor_map_array(&sector, 
		env->wall_textures[sector.floor_texture],
		env))
		return (-1);
	if (set_sector_ceiling_map_array(&sector, 
		env->wall_textures[sector.ceiling_texture],
		env))
		return (-1);
	if (fill_new_sector(&sector, env))
		return (-1);
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
	get_new_floor_and_ceiling(env);
	return (0);
}

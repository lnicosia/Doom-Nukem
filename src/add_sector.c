/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_sector.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 12:06:46 by sipatry           #+#    #+#             */
/*   Updated: 2020/04/28 16:17:50 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "free.h"
#include "init.h"

void		get_new_floor_and_ceiling(t_env *env)
{
	t_sector	sector;
	int			i;
	int			flag;

	flag = 0;
	i = -1;
	sector = env->sectors[env->nb_sectors - 1];
	while (++i < sector.nb_vertices)
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
	}
	env->sectors[env->nb_sectors - 1].floor = sector.floor;
	env->sectors[env->nb_sectors - 1].ceiling = sector.ceiling;
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
	sector.floor_texture = env->editor.current_texture;
	sector.ceiling = 10;
	sector.ceiling_slope = 0;
	sector.ceiling_texture = env->editor.current_texture;
	sector.floor_map_scale = new_v2(10, 10);
	sector.ceiling_map_scale = new_v2(10, 10);
	sector.floor_map_align = new_v2(0, 0);
	sector.ceiling_map_align = new_v2(0, 0);
	sector.light_color = 0xFFFFFFFF;
	sector.brightness = 0;
	sector.gravity = -9.81;
	sector.skybox = 0;
	sector.num = env->nb_sectors;
	sector.x_max = -2147483648;
	sector.nb_vertices = get_new_sector_len(env);
	return (sector);
}

int			add_sector2(t_sector *sector, t_env *env)
{
	if (!(env->sectors = (t_sector*)ft_realloc(env->sectors,
					sizeof(t_sector) * env->nb_sectors,
					sizeof(t_sector) * (env->nb_sectors + 1))))
		return (ft_perror("Could not realloc sectors"));
	env->sectors[env->nb_sectors] = *sector;
	create_portals(env, *sector);
	env->nb_sectors++;
	ft_memdel((void**)&env->sector_list);
	if (!(env->sector_list = (int*)ft_memalloc(sizeof(int) * env->nb_sectors)))
		return (ft_perror("Could not allocate sector list"));
	ft_memdel((void**)&env->rendered_sectors);
	if (!(env->rendered_sectors =
		(int*)ft_memalloc(sizeof(int) * env->nb_sectors)))
		return (ft_perror("Could not allocate sector list"));
	get_new_floor_and_ceiling(env);
	if (check_sector(*sector, env) && !env->editor.split_sector)
	{
		env->editor.selected_sector = env->nb_sectors - 1;
		free_current_vertices(env);
		delete_sector(env);
		env->editor.selected_sector = -1;
		return (-1);
	}
	return (0);
}

int			add_sector(t_env *env)
{
	t_sector	sector;

	sector = new_default_sector(env);
	if (init_new_sector_arrays(&sector))
		return (custom_error("Error while initializing new sector arrays\n"));
	if (set_sector_floor_map_array(&sector,
		&env->wall_textures[sector.floor_texture], env))
		return (-1);
	if (set_sector_ceiling_map_array(&sector,
		&env->wall_textures[sector.ceiling_texture], env))
		return (-1);
	if (fill_new_sector(&sector, env))
		return (-1);
	sector.ceiling_normal = get_sector_normal(&sector, env,
	sector.start_ceiling_slope);
	sector.floor_normal = get_sector_normal(&sector, env,
	sector.start_floor_slope);
	set_sector_xmax(env, &sector);
	update_sector_slope(env, &sector);
	return (add_sector2(&sector, env));
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_current_floor_map.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 15:22:29 by lnicosia          #+#    #+#             */
/*   Updated: 2019/11/18 16:57:18 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

int		set_sector_floor_map_array(t_sector *sector, t_texture texture,
		t_env *env)
{
	size_t		j;
	double		divider;
	int			size;

	//ft_printf("sector %d floor has %d maps\n", sector->num,	texture.nb_maps);
	if (sector->floor_map_scale.x * env->w >
			sector->floor_map_scale.y * env->h)
	{
		size = sector->floor_map_scale.x * env->w;
		divider = 2;
	}
	else
	{
		size = sector->floor_map_scale.y * env->h;
		divider = 1.25;
	}
	j = 0;
	while (j < texture.nb_maps)
	{
		sector->floor_map_lvl[j] = size / (double)(pow(2, j) * divider);
		//ft_printf("z = %f at map %d\n", sector->floor_map_lvl[j], (int)j);
		/*ft_printf("map %d at z = %f\n", 
		(int)ceil(log2(size / (double)(divider * sector->map_lvl[j]))),
		sector->map_lvl[j]);*/
		j++;
	}
	return (0);
}

int		get_current_floor_map(int texture, double z, t_render *render, t_env *env)
{
	size_t		j;
	double			res;
	//int			res2;
	t_texture	text;
	t_sector	sector;

	if (texture == -1)
		text = env->skyboxes[0].textures[0];
	else
		text = env->wall_textures[texture];
	sector = env->sectors[render->sector];
	res = 0;
	//res2 = 0;
	j = text.nb_maps - 1;
	//ft_printf("sector %d floor %d, texture = %d, nb_maps = %d\n",
	//render->sector, render->i, texture, text.nb_floor_maps);
	//ft_printf("z = %f\n", z);
	if (env->options.o)
	{
		res = log2(fmax(
			env->w * sector.floor_map_scale.x
			/ (2 * z),
			env->h * sector.floor_map_scale.y
			/ (1.25 * z)));
		//ft_printf("res = %f\n", res);
		res = ceil(res);
		//ft_printf("res ceiled = %f\n", res);
	}
	else
	{
		while (j > 0)
		{
			if (z < sector.floor_map_lvl[j])
			{
				//ft_printf("z = %f\n", z);
				//ft_printf("z at index %d = %f\n", j, sector.map_lvl[render->i][j]);
				res = j + 1;
				//ft_printf("res2 = %d\n", j);
				break;
			}
			j--;
		}
	}
	//ft_printf("tab: \n");
	/*j = 0;
	while (j < text.nb_maps)
	{
		//ft_printf("[%d] = %f\n", j, sector.map_lvl[render->i][j]);
		j++;
	}*/
	res = ft_clamp(res, 0, text.nb_maps - 1);
	render->texture_w = text.maps[(int)res]->w;
	render->texture_h = text.maps[(int)res]->h;
	return (res);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_current_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipatry <sipatry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 13:51:10 by lnicosia          #+#    #+#             */
/*   Updated: 2019/11/18 19:10:15 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

int		set_sector_wall_map_array(t_sector *sector, t_texture texture, int i,
		t_env *env)
{
	size_t		j;
	double		divider;
	int			size;

	//ft_printf("sector %d wall %d has %d maps\n", sector->num, i,
	//texture.nb_maps);
	if (sector->map_scale[i].x * env->w >
			sector->map_scale[i].y * env->h)
	{
		size = sector->map_scale[i].x * env->w;
		divider = 2;
	}
	else
	{
		size = sector->map_scale[i].y * env->h;
		divider = 1.25;
	}
	j = 0;
	while (j < texture.nb_maps)
	{
		sector->walls_map_lvl[i][j] = size / (double)(pow(2, j) * divider);
		//ft_printf("z = %f at map %d\n", sector->walls_map_lvl[i][j], (int)j);
		/*ft_printf("map %d at z = %f\n", 
		(int)ceil(log2(size / (double)(divider * sector->map_lvl[i][j]))),
		sector->map_lvl[i][j]);*/
		j++;
	}
	return (0);
}

int		get_current_wall_map(int texture, double z, t_render *render, t_env *env)
{
	size_t		j;
	int			res;
	//int			res2;
	t_texture	text;
	t_sector	sector;

	if (texture == -1)
		text = env->skyboxes[0].textures[0];
	else
		text = env->wall_textures[texture];
	sector = env->sectors[render->sector];
	res = 0;
	if (env->options.o)
	{
		res = ceil(log2(fmax(
			env->w * sector.map_scale[render->i].x
			/ (2 * z),
			env->h * sector.map_scale[render->i].y
			/ (1.25 * z))));
	}
	else
	{
	j = text.nb_maps - 1;
		while (j > 0)
		{
			if (z < sector.walls_map_lvl[render->i][j])
			{
				res = j + 1;
				break;
			}
			j--;
		}
	}
	res = ft_clamp(res, 0, text.nb_maps - 1);
	render->texture_w = text.maps[(int)res]->w;
	render->texture_h = text.maps[(int)res]->h;
	return (res);
}

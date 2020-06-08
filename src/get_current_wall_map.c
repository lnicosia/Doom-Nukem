/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_current_wall_map.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 13:51:10 by lnicosia          #+#    #+#             */
/*   Updated: 2020/04/30 11:33:41 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"
#include <math.h>

int		realloc_sector_walls_map_lvl(t_sector *sector, t_texture *texture,
int i)
{
	if (sector->walls_map_lvl[i])
		ft_memdel((void**)&sector->walls_map_lvl[i]);
	if (!(sector->walls_map_lvl[i] = (double*)ft_memalloc(sizeof(double)
		* texture->nb_maps)))
		return (ft_perror("Could not malloc a sector map_lvl array"));
	return (0);
}

int		set_sector_wall_map_array(t_sector *sector, t_texture *texture, int i,
		t_env *env)
{
	size_t		j;
	double		divider;
	int			size;

	if (realloc_sector_walls_map_lvl(sector, texture, i))
		return (-1);
	if (sector->scale[i].x * env->w >
			sector->scale[i].y * env->h)
	{
		size = sector->scale[i].x * env->w;
		divider = 2;
	}
	else
	{
		size = sector->scale[i].y * env->h;
		divider = 1.25;
	}
	j = 0;
	while (j < texture->nb_maps)
	{
		sector->walls_map_lvl[i][j] = size / (double)(pow(2, j) * divider);
		j++;
	}
	return (0);
}

int		decrease_current_wall_map(int i, size_t j, double z, t_sector *sector)
{
	int	res;

	res = 0;
	while (j > 0)
	{
		if (z < sector->walls_map_lvl[i][j])
		{
			res = j + 1;
			break ;
		}
		j--;
	}
	return (res);
}

int		get_current_wall_map(int texture, double z, t_render *render,
t_env *env)
{
	int			res;
	t_texture	*text;
	t_sector	*sector;

	if (texture == -1)
		return (0);
	text = &env->wall_textures[texture];
	sector = render->sector;
	res = 0;
	if (env->options.o)
		res = ceil(log2(fmax(env->w * sector->scale[render->i].x / (2 * z),
			env->h * sector->scale[render->i].y / (1.25 * z))));
	else
		res =
		decrease_current_wall_map(render->i, text->nb_maps - 1, z, sector);
	res = ft_clamp(res, 0, text->nb_maps - 1);
	render->texture_w = text->maps[(int)res]->w;
	render->texture_h = text->maps[(int)res]->h;
	return (res);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_current_floor_map.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 15:22:29 by lnicosia          #+#    #+#             */
/*   Updated: 2020/04/30 11:17:58 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"
#include <math.h>

void	compute_floor_scales(t_texture *texture, t_sector *sector)
{
	size_t	i;

	i = 0;
	while (i < texture->nb_maps)
	{
		sector->floor_scale[i].x =
		(texture->maps[i]->w / sector->floor_map_scale.x);
		sector->floor_scale[i].y =
		(texture->maps[i]->h / sector->floor_map_scale.y);
		sector->floor_align[i].x =
		(texture->maps[i]->w * sector->floor_map_align.x) / 10;
		sector->floor_align[i].y =
		(texture->maps[i]->h * sector->floor_map_align.y) / 10;
		i++;
	}
}

void	set_sector_floor_map_array2(t_sector *sector, t_texture *texture,
		t_env *env)
{
	size_t		j;
	double		divider;
	int			size;

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
	while (j < texture->nb_maps)
	{
		sector->floor_map_lvl[j] = size / (double)(pow(2, j) * divider);
		j++;
	}
}

int		set_sector_floor_map_array(t_sector *sector, t_texture *texture,
		t_env *env)
{
	if (sector->floor_scale)
		free(sector->floor_scale);
	if (!(sector->floor_scale = (t_v2*)ft_memalloc(sizeof(t_v2)
		* texture->nb_maps)))
		return (custom_error("Could not malloc sector floor_scale array"));
	if (sector->floor_align)
		free(sector->floor_align);
	if (!(sector->floor_align = (t_v2*)ft_memalloc(sizeof(t_v2)
		* texture->nb_maps)))
		return (custom_error("Could not malloc sector floor_scale array"));
	compute_floor_scales(texture, sector);
	if (sector->floor_map_lvl)
		free(sector->floor_map_lvl);
	if (!(sector->floor_map_lvl = (double*)ft_memalloc(
		sizeof(double) * texture->nb_maps)))
		return (custom_error("Could not malloc a sector map_lvl array"));
	set_sector_floor_map_array2(sector, texture, env);
	return (0);
}

void	decrease_current_floor_map(double *res, size_t j, double z,
t_sector *sector)
{
	while (j > 0)
	{
		if (z < sector->floor_map_lvl[j])
		{
			*res = j + 1;
			break ;
		}
		j--;
	}
}

int		get_current_floor_map(int texture, double z, t_render *render,
t_env *env)
{
	double		res;
	t_texture	*text;
	t_sector	*sector;

	if (texture == -1)
		text = &env->skyboxes[0].textures[0];
	else
		text = &env->wall_textures[texture];
	sector = render->sector;
	res = 0;
	if (env->options.o)
		res = ceil(log2(fmax(env->w * sector->floor_map_scale.x / (2 * z),
			env->h * sector->floor_map_scale.y / (1.25 * z))));
	else
		decrease_current_floor_map(&res, text->nb_maps - 1, z, sector);
	res = ft_clamp(res, 0, text->nb_maps - 1);
	render->texture_w = text->maps[(int)res]->w;
	render->texture_h = text->maps[(int)res]->h;
	return (res);
}

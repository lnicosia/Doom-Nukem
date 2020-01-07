/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_current_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipatry <sipatry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 13:51:10 by lnicosia          #+#    #+#             */
/*   Updated: 2019/11/20 09:24:28 by sipatry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

int		set_sector_map_array(t_sector *sector, t_texture texture, int i,
t_env *env)
{
	size_t		j;

	(void)sector;
	(void)i;
	(void)env;
	j = 0;
	while (j < texture.nb_maps - 1)
	{
		j++;
	}
	return (0);
}

int		get_current_map(int texture, double z, t_render *render, t_env *env)
{
	//size_t	i;
	int		res;
	//int		line;
	t_texture	text;

	//i = 0;
	if (texture != -1)
	{
		/*	text = env->skyboxes[0].textures[0];
		else*/
		text = env->wall_textures[texture];
		/*line = text.maps[0]->w * 40 / render->z;
		while (i < text.nb_maps
			&& text.maps[i]->w > line)
			i++;
		i = ft_clamp(i, 0, text.nb_maps - 1);*/
		res = ceil(log2(fmax(
		env->w * env->sectors[render->sector].map_scale[render->i].x
		/ (2 * z),
		env->h * env->sectors[render->sector].map_scale[render->i].y
		/ (1.25 * z))));
		res = ft_clamp(res, 0, text.nb_maps - 1);
		render->texture_w = text.maps[res]->w;
		render->texture_h = text.maps[res]->h;
		return (res);
	}
	return (0);
}

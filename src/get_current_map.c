/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_current_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 13:51:10 by lnicosia          #+#    #+#             */
/*   Updated: 2019/11/15 20:11:04 by lnicosia         ###   ########.fr       */
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
	size_t	i;
	int		res;
	int		line;

	i = 0;
	texture = texture == -1 ? 38 : texture;
	line = env->textures[texture].maps[0]->w * 40 / render->z;
	while (i < env->textures[texture].nb_maps
		&& env->textures[texture].maps[i]->w > line)
		i++;
	i = ft_clamp(i, 0, env->textures[texture].nb_maps - 1);
	res = ceil(log2(fmax(
	env->w * env->sectors[render->sector].map_scale[render->i].x
	/ (2 * z),
	env->h * env->sectors[render->sector].map_scale[render->i].y
	/ (1.25 * z))));
	res = ft_clamp(res, 0, env->textures[texture].nb_maps - 1);
	render->texture_w = env->textures[texture].maps[res]->w;
	render->texture_h = env->textures[texture].maps[res]->h;
	return (res);
}

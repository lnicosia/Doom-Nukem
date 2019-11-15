/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_current_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipatry <sipatry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 13:51:10 by lnicosia          #+#    #+#             */
/*   Updated: 2019/11/15 17:47:46 by sipatry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

int		get_current_map(int texture, t_render *render, t_env *env)
{
	size_t	i;
	int	res;
	int	line;

	i = 0;
	line = (int)render->max_floor - (int)render->max_ceiling;
	if(texture != -1)
	{
		while (i < env->wall_textures[texture].nb_maps
			&& env->wall_textures[texture].maps[i]->w > line)
		{
			//ft_printf("i = %d\n", i);
			i++;
		}
		i = ft_clamp(i, 0, env->wall_textures[texture].nb_maps - 1);
		res = i;

		render->texture_w = env->wall_textures[texture].maps[res]->w;
		render->texture_h = env->wall_textures[texture].maps[res]->h;
		return (res);
	}
	return (0);
	/*size_t	i;
	int		line;

	i = 0;
	texture = render->texture == -1 ? 38 : render->texture;
	line = env->wall_textures[texture].maps[0]->w * 40 / render->z;
	while (i < env->wall_textures[texture].nb_maps
		&& env->wall_textures[texture].maps[i]->w > line)
		i++;
	i = ft_clamp(i, 0, env->wall_textures[texture].nb_maps - 1);
	ft_printf("i = %d\n", i);
	ft_printf("test = %d\n", (int)floor(log2(fmax(
	env->wall_textures[texture].maps[0]->w * 100 / render->z,
	env->wall_textures[texture].maps[0]->h * 100 / render->z))));
	render->texture_w = env->wall_textures[texture].maps[i]->w;
	render->texture_h = env->wall_textures[texture].maps[i]->h;*/
	return (i);
}

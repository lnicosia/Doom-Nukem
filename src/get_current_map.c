/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_current_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 13:51:10 by lnicosia          #+#    #+#             */
/*   Updated: 2019/11/15 12:25:49 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

int		get_current_map(int texture, t_render *render, t_env *env)
{
	int	res;

	res = 0;
	texture = render->texture == -1 ? 38 : render->texture;
	(void)texture;
	(void)env;
	// Methode 1: log2
	/*ft_printf("current line = %d\n", (int)render->current_floor
	- (int)render->current_ceiling);
	ft_printf("original texture map %d: [%d][%d]\n", res,
	env->textures[texture].maps[0]->w,
	env->textures[texture].maps[0]->h);
	res = floor(log2(render->current_floor - render->current_ceiling));
	ft_printf("res = %d\n", res);
	ft_printf("nb_map = %d\n", env->textures[texture].nb_maps);
	//res = res - env->textures[texture].nb_maps + 1;
	render->texture_w = env->textures[texture].maps[res]->w;
	render->texture_h = env->textures[texture].maps[res]->h;
	ft_printf("res = %d\n", res);
	ft_printf("texture = %d\n", texture);
	ft_printf("size of text at map lvl %d: [%d][%d]\n", res,
	env->textures[texture].maps[res]->w,
	env->textures[texture].maps[res]->h);*/
	//res = 0;

	// Methode 2: comparaison
	size_t	i;
	int	line;

	i = 0;
	line = (int)render->max_floor - (int)render->max_ceiling;
	/*ft_printf("original texture size %d: [%d][%d]\n", res,
	env->textures[texture].maps[0]->w,
	env->textures[texture].maps[0]->h);
	ft_printf("current line = %d\n", line);
	ft_printf("nb_map = %d\n", env->textures[texture].nb_maps);*/
	while (i < env->textures[texture].nb_maps
		&& env->textures[texture].maps[i]->w > line)
	{
		//ft_printf("i = %d\n", i);
		i++;
	}
	i = ft_clamp(i, 0, env->textures[texture].nb_maps - 1);
	res = i;
	/*ft_printf("res = %d\n", res);
	ft_printf("size of text at map lvl %d: [%d][%d]\n", res,
	env->textures[texture].maps[res]->w,
	env->textures[texture].maps[res]->h);*/

	render->texture_w = env->textures[texture].maps[res]->w;
	render->texture_h = env->textures[texture].maps[res]->h;
	return (res);
	return (0);
}

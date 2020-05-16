/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_mipmaps.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipatry <sipatry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 10:49:09 by lnicosia          #+#    #+#             */
/*   Updated: 2020/03/02 11:14:52 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include <math.h>

int		generate_mipmaps2(size_t i, size_t nb_maps, t_texture *texture,
t_env *env)
{
	i = 0;
	while (i < MAX_SPRITES_TEXTURES)
	{
		texture = &env->sprite_textures[i];
		nb_maps = floor(log2(fmax(texture->surface->w,
			texture->surface->h))) + 1;
		env->sprite_textures[i].nb_maps = nb_maps;
		if (generate_maps_for_texture(texture))
			return (-1);
		i++;
	}
	return (0);
}

int		generate_mipmaps(t_env *env)
{
	size_t		i;
	size_t		nb_maps;
	t_texture	*texture;

	i = 0;
	texture = NULL;
	nb_maps = 0;
	ft_printf("Generating mipmaps..\n");
	while (i < MAX_WALL_TEXTURE)
	{
		texture = &env->wall_textures[i];
		nb_maps = floor(log2(fmax(texture->surface->w,
			texture->surface->h))) + 1;
		env->wall_textures[i].nb_maps = nb_maps;
		if (generate_maps_for_texture(texture))
			return (-1);
		i++;
	}
	return (generate_mipmaps2(i, nb_maps, texture, env));
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_mipmaps_utils.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/30 11:16:01 by lnicosia          #+#    #+#             */
/*   Updated: 2020/04/30 11:16:02 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include <math.h>

int		get_color(int x, int y, int w, Uint32 *prec_pixels)
{
	uint8_t		red;
	uint8_t		green;
	uint8_t		blue;
	uint32_t	res;

	red = sqrt((pow((prec_pixels[x * 2 + (y * 2) * w] >> 16 & 0xFF), 2) +
	pow((prec_pixels[x * 2 + 1 + (y * 2) * w] >> 16 & 0xFF), 2) +
	pow((prec_pixels[x * 2 + (y * 2 + 1) * w] >> 16 & 0xFF), 2) +
	pow((prec_pixels[x * 2 + 1 + (y * 2 + 1) * w] >> 16 & 0xFF), 2)) / 4);
	green = sqrt((pow((prec_pixels[x * 2 + (y * 2) * w] >> 8 & 0xFF), 2) +
	pow((prec_pixels[x * 2 + 1 + (y * 2) * w] >> 8 & 0xFF), 2) +
	pow((prec_pixels[x * 2 + (y * 2 + 1) * w] >> 8 & 0xFF), 2) +
	pow((prec_pixels[x * 2 + 1 + (y * 2 + 1) * w] >> 8 & 0xFF), 2)) / 4);
	blue = sqrt((pow((prec_pixels[x * 2 + (y * 2) * w] >> 0 & 0xFF), 2) +
	pow((prec_pixels[x * 2 + 1 + (y * 2) * w] >> 0 & 0xFF), 2) +
	pow((prec_pixels[x * 2 + (y * 2 + 1) * w] >> 0 & 0xFF), 2) +
	pow((prec_pixels[x * 2 + 1 + (y * 2 + 1) * w] >> 0 & 0xFF), 2)) / 4);
	res = 0xFF << 24 | red << 16 | green << 8 | blue;
	return (res);
}

int		fill_map_at_lvl(t_texture *texture, int lvl)
{
	Uint32	*pixels;
	Uint32	*prec_pixels;
	int		x;
	int		y;

	pixels = texture->maps[lvl]->pixels;
	prec_pixels = texture->maps[lvl + 1]->pixels;
	y = 0;
	while (y < texture->maps[lvl]->h)
	{
		x = 0;
		while (x < texture->maps[lvl]->w)
		{
			if (x * 2 < texture->maps[lvl + 1]->w
				&& x * 2 + 1 < texture->maps[lvl + 1]->w
				&& y * 2 < texture->maps[lvl + 1]->h
				&& y * 2 + 1 < texture->maps[lvl + 1]->h)
				pixels[x + y * texture->maps[lvl]->w] = get_color(
					x, y, texture->maps[lvl + 1]->w, prec_pixels);
			x++;
		}
		y++;
	}
	return (0);
}

int		generate_map_at_lvl(t_texture *texture, int lvl)
{
	if (!(texture->maps[lvl] = SDL_CreateRGBSurfaceWithFormat(0,
		ft_max((int)(texture->maps[texture->nb_maps - 1]->w
		/ (pow(2, texture->nb_maps - 1 - lvl))), 1),
		ft_max((int)(texture->maps[texture->nb_maps - 1]->h
		/ (pow(2, texture->nb_maps - 1 - lvl))), 1),
		24, SDL_PIXELFORMAT_ARGB8888)))
		return (custom_error("Can not malloc one of the texture maps"));
	fill_map_at_lvl(texture, lvl);
	return (0);
}

int		generate_maps_for_texture(t_texture *texture)
{
	int	i;

	if (!(texture->maps = (SDL_Surface**)ft_memalloc(sizeof(SDL_Surface*)
		* texture->nb_maps)))
		return (custom_error("Can not malloc textures maps array\n"));
	texture->maps[texture->nb_maps - 1] = texture->surface;
	i = texture->nb_maps - 2;
	while (i >= 0)
	{
		generate_map_at_lvl(texture, i);
		i--;
	}
	return (0);
}

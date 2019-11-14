/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_mipmaps.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 10:49:09 by lnicosia          #+#    #+#             */
/*   Updated: 2019/11/14 18:07:17 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

int		get_color(int x, int y, int w, Uint32 *prec_pixels)
{
	uint8_t		red;
	uint8_t		green;
	uint8_t		blue;
	uint32_t	res;

	// RAW
	/*red = ((prec_pixels[x * 2 + (y * 2) * w] >> 16 & 0xFF) +
	(prec_pixels[x * 2 + 1 + (y * 2) * w] >> 16 & 0xFF) +
	(prec_pixels[x * 2 + (y * 2 + 1) * w] >> 16 & 0xFF) +
	(prec_pixels[x * 2 + 1 + (y * 2 + 1) * w] >> 16 & 0xFF)) / 4;
	//ft_printf("red = 0x%X\n", red);
	green = ((prec_pixels[x * 2 + (y * 2) * w] >> 8 & 0xFF) +
	(prec_pixels[x * 2 + 1 + (y * 2) * w] >> 8 & 0xFF) +
	(prec_pixels[x * 2 + (y * 2 + 1) * w] >> 8 & 0xFF) +
	(prec_pixels[x * 2 + 1 + (y * 2 + 1) * w] >> 8 & 0xFF)) / 4;
	//ft_printf("green = 0x%X\n", green);
	blue = ((prec_pixels[x * 2 + (y * 2) * w] >> 0 & 0xFF) +
	(prec_pixels[x * 2 + 1 + (y * 2) * w] >> 0 & 0xFF) +
	(prec_pixels[x * 2 + (y * 2 + 1) * w] >> 0 & 0xFF) +
	(prec_pixels[x * 2 + 1 + (y * 2 + 1) * w] >> 0 & 0xFF)) / 4;*/
	//ft_printf("blue = 0x%X\n", blue);

	// GAMMA FILTER
	red = sqrt((pow((prec_pixels[x * 2 + (y * 2) * w] >> 16 & 0xFF), 2) +
	pow((prec_pixels[x * 2 + 1 + (y * 2) * w] >> 16 & 0xFF), 2) +
	pow((prec_pixels[x * 2 + (y * 2 + 1) * w] >> 16 & 0xFF), 2) +
	pow((prec_pixels[x * 2 + 1 + (y * 2 + 1) * w] >> 16 & 0xFF), 2)) / 4);
	//ft_printf("red = 0x%X\n", red);
	green = sqrt((pow((prec_pixels[x * 2 + (y * 2) * w] >> 8 & 0xFF), 2) +
	pow((prec_pixels[x * 2 + 1 + (y * 2) * w] >> 8 & 0xFF), 2) +
	pow((prec_pixels[x * 2 + (y * 2 + 1) * w] >> 8 & 0xFF), 2) +
	pow((prec_pixels[x * 2 + 1 + (y * 2 + 1) * w] >> 8 & 0xFF), 2)) / 4);
	//ft_printf("green = 0x%X\n", green);
	blue = sqrt((pow((prec_pixels[x * 2 + (y * 2) * w] >> 0 & 0xFF), 2) +
	pow((prec_pixels[x * 2 + 1 + (y * 2) * w] >> 0 & 0xFF), 2) +
	pow((prec_pixels[x * 2 + (y * 2 + 1) * w] >> 0 & 0xFF), 2) +
	pow((prec_pixels[x * 2 + 1 + (y * 2 + 1) * w] >> 0 & 0xFF), 2)) / 4);
	res = 0xFF << 24 | red << 16 | green << 8 | blue;
	//ft_printf("res = 0x%X\n", res);
	return (res);
}

int		fill_map_at_lvl(t_texture *texture, size_t lvl)
{
	Uint32	*pixels;
	Uint32	*prec_pixels;
	int		x;
	int		y;

	pixels = texture->maps[lvl]->pixels;
	prec_pixels = texture->maps[lvl - 1]->pixels;
	y = 0;
	while (y < texture->maps[lvl]->h)
	{
		x = 0;
		while (x < texture->maps[lvl]->w)
		{
			pixels[x + y * texture->maps[lvl]->w] = get_color(
					x, y, texture->maps[lvl - 1]->w, prec_pixels);
			x++;
		}
		y++;
	}
	return (0);
}

int		generate_map_at_lvl(t_texture *texture, size_t lvl)
{
	if (!(texture->maps[lvl] = SDL_CreateRGBSurfaceWithFormat(0,
					(int)(texture->maps[0]->w / (pow(2, lvl))),
					(int)(texture->maps[0]->h / (pow(2, lvl))),
					24, SDL_PIXELFORMAT_ARGB8888)))
		return (custom_error("Can not malloc one of the texture maps"));
	//ft_printf("created size of lvl %d: [%d][%d]\n", lvl,
	//		texture->maps[lvl]->w, texture->maps[lvl]->h);
	fill_map_at_lvl(texture, lvl);
	return (0);
}

int		generate_maps_for_texture(t_texture *texture)
{
	size_t	i;

	if (!(texture->maps = (SDL_Surface**)malloc(sizeof(SDL_Surface*)
					* texture->nb_maps)))
		return (custom_error("Can not malloc textures maps array\n"));
	texture->maps[0] = texture->surface;
	//ft_printf("texture original size = [%d][%d]\n",
	//		texture->maps[0]->w, texture->maps[0]->h);
	i = 1;
	while (i < texture->nb_maps)
	{
		generate_map_at_lvl(texture, i);
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
	ft_printf("Generating mipmaps..\n");
	while (i < MAX_TEXTURE)
	{
		texture = &env->textures[i];
		nb_maps = floor(log2(fmax(texture->surface->w,
						texture->surface->h))) + 1;
		//ft_printf("texture %d needs %d levels\n", i, nb_maps);
		env->textures[i].nb_maps = nb_maps;
		if (generate_maps_for_texture(texture))
			return (-1);
		i++;
	}
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_image.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 18:58:55 by lnicosia          #+#    #+#             */
/*   Updated: 2020/02/25 19:03:23 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

/*
**	Copy a surface into our main texture
**	TODO Protection
**	ex: si size depasse la taille de la surface
*/

void    apply_surface(SDL_Surface *surface, t_point pos, t_point size, t_env *env)
{
	int				x;
	int				y;
	Uint32			*pixels;
	Uint32			pixel;
	SDL_PixelFormat	*fmt;
	Uint32			*texture_pixels;

	texture_pixels = env->sdl.texture_pixels;
	size.x = ft_min(size.x, surface->w);
	size.y = ft_min(size.y, surface->h);
	if (!surface)
	{
		ft_printf("apply_surface error: surface is NULL\n");
		return ;
	}
	pixels = (Uint32*)surface->pixels;
	fmt = surface->format;
	y = 0;
	while (y < size.y)
	{
		x = 0;
		while (x < size.x)
		{
			pixel = pixels[x + surface->w * y];
			//if (surface == env->ui_textures[0].surface)
			//ft_printf("trying pixel [%d][%d]\n", x, y);
			/*if ((Uint8)(((pixel & fmt->Amask) >> fmt->Ashift) << fmt->Aloss) != 0
			  &&*/ /*if (pos.y + x >= 0 && pos.y + x < env->w && pos.x + y >= 0 && pos.x + y < env->h)
					 texture_pixels[pos.y + x + env->w * (pos.x + y)] =
					 (Uint8)(((pixel & fmt->Amask) >> fmt->Ashift) << fmt->Aloss) << 24
					 | (Uint8)(((pixel & fmt->Rmask) >> fmt->Rshift) << fmt->Rloss) << 16
					 | (Uint8)(((pixel & fmt->Gmask) >> fmt->Gshift) << fmt->Gloss) << 8
					 | (Uint8)(((pixel & fmt->Bmask) >> fmt->Bshift) << fmt->Bloss) << 0;*/
			if (pos.y + x >= 0 && pos.y + x < env->w && pos.x + y >= 0 && pos.x + y < env->h
					&& pixel != 0xFFC10099)
			{
				texture_pixels[pos.y + x + env->w * (pos.x + y)] = blend_alpha(texture_pixels[pos.y + x + env->w * (pos.x + y)], pixel, (Uint8)(((pixel & fmt->Amask) >> fmt->Ashift) << fmt->Aloss));
			}
			x++;
		}
		y++;
	}
}

Uint32	get_pixel(SDL_Surface *surface, int x, int y, t_point size)
{
	double	xalpha;
	double	yalpha;
	Uint32	*pixels;

	xalpha = x / (double)size.x;
	yalpha = y / (double)size.y;
	pixels = (Uint32*)surface->pixels;
	return (pixels[(int)(xalpha * surface->w) +
	(int)(yalpha * surface->h) * surface->w]);
}

SDL_Surface	*get_closest_mipmap(t_texture texture, t_point size)
{
	int		map;

	map = texture.nb_maps - ceil(log2(fmax(texture.surface->w / (double)size.x,
	texture.surface->h / (double)size.y)));
	map = ft_clamp(map, 0, texture.nb_maps - 1);
	return (texture.maps[map]);
}

/*
**	Copy a surface into our main texture
**	with scaling
*/

void    apply_image(t_texture texture, t_point pos, t_point size, t_env *env)
{
	int				x;
	int				y;
	Uint32			pixel;
	SDL_PixelFormat	*fmt;
	SDL_Surface		*surface;
	Uint32			*texture_pixels;

	texture_pixels = env->sdl.texture_pixels;
	surface = get_closest_mipmap(texture, size);
	fmt = surface->format;
	y = 0;
	while (y < size.y)
	{
		x = 0;
		while (x < size.x)
		{
			pixel = get_pixel(surface, x, y, size);
			//if (surface == env->ui_textures[0].surface)
			//ft_printf("trying pixel [%d][%d]\n", x, y);
			/*if ((Uint8)(((pixel & fmt->Amask) >> fmt->Ashift) << fmt->Aloss) != 0
			  &&*/ /*if (pos.y + x >= 0 && pos.y + x < env->w && pos.x + y >= 0 && pos.x + y < env->h)
					 texture_pixels[pos.y + x + env->w * (pos.x + y)] =
					 (Uint8)(((pixel & fmt->Amask) >> fmt->Ashift) << fmt->Aloss) << 24
					 | (Uint8)(((pixel & fmt->Rmask) >> fmt->Rshift) << fmt->Rloss) << 16
					 | (Uint8)(((pixel & fmt->Gmask) >> fmt->Gshift) << fmt->Gloss) << 8
					 | (Uint8)(((pixel & fmt->Bmask) >> fmt->Bshift) << fmt->Bloss) << 0;*/
			if (pos.y + x >= 0 && pos.y + x < env->w && pos.x + y >= 0 && pos.x + y < env->h
					&& pixel != 0xFFC10099)
			{
				texture_pixels[pos.y + x + env->w * (pos.x + y)] = blend_alpha(texture_pixels[pos.y + x + env->w * (pos.x + y)], pixel, (Uint8)(((pixel & fmt->Amask) >> fmt->Ashift) << fmt->Aloss));
			}
			x++;
		}
		y++;
	}
}

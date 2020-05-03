/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_image2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/28 16:34:37 by lnicosia          #+#    #+#             */
/*   Updated: 2020/04/28 16:34:37 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

/*
**	Copy a surface into our main texture
**	TODO Protection
**	ex: si size depasse la taille de la surface
*/

void		apply_surface(SDL_Surface *surface, t_point pos, t_point size,
t_env *env)
{
	t_point			i;
	Uint32			pixel;
	SDL_PixelFormat	*fmt;

	size = new_point(ft_min(size.x, surface->w), ft_min(size.y, surface->h));
	if (!surface)
		return ;
	fmt = surface->format;
	i.y = -1;
	while (++i.y < size.y)
	{
		i.x = -1;
		while (++i.x < size.x)
		{
			pixel = ((Uint32*)(surface->pixels))[i.x + surface->w * i.y];
			if (pos.y + i.x >= 0 && pos.y + i.x < env->w && pos.x + i.y >= 0
				&& pos.x + i.y < env->h && pixel != 0xFFC10099)
			{
				env->sdl.texture_pixels[pos.y + i.x + env->w * (pos.x + i.y)] =
				blend_alpha(env->sdl.
				texture_pixels[pos.y + i.x + env->w * (pos.x + i.y)], pixel,
				(Uint8)(((pixel & fmt->Amask) >> fmt->Ashift) << fmt->Aloss));
			}
		}
	}
}

Uint32		get_image_pixel(SDL_Surface *surface, int x, int y, t_point size)
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
**	Copy a texture into our main texture
**	with scaling
*/

void		apply_image(t_texture texture, t_point pos, t_point size,
t_env *env)
{
	int				x;
	int				y;
	Uint32			pixel;
	SDL_PixelFormat	*fmt;
	SDL_Surface		*surface;

	surface = get_closest_mipmap(texture, size);
	fmt = surface->format;
	y = -1;
	while (++y < size.y)
	{
		x = -1;
		while (++x < size.x)
		{
			pixel = get_image_pixel(surface, x, y, size);
			if (pos.y + x >= 0 && pos.y + x < env->w && pos.x + y >= 0
				&& pos.x + y < env->h && pixel != 0xFFC10099)
			{
				env->sdl.texture_pixels[pos.y + x + env->w * (pos.x + y)] =
				blend_alpha(env->sdl.
				texture_pixels[pos.y + x + env->w * (pos.x + y)], pixel,
				(Uint8)(((pixel & fmt->Amask) >> fmt->Ashift) << fmt->Aloss));
			}
		}
	}
}

/*
**	Copy a texture into our main texture
**	with scaling and a green selection filter
*/

void		apply_image_selected(t_texture texture, t_point pos, t_point size,
t_env *env)
{
	int				x;
	int				y;
	Uint32			pixel;
	SDL_Surface		*surface;
	Uint32			*texture_pixels;

	texture_pixels = env->sdl.texture_pixels;
	surface = get_closest_mipmap(texture, size);
	y = 0;
	while (y < size.y)
	{
		x = 0;
		while (x < size.x)
		{
			pixel = get_image_pixel(surface, x, y, size);
			if (pos.y + x >= 0 && pos.y + x < env->w && pos.x + y >= 0
				&& pos.x + y < env->h && pixel != 0xFFC10099)
			{
				texture_pixels[pos.y + x + env->w * (pos.x + y)] =
				blend_alpha(pixel, 0x1ABC9C, 128);
			}
			x++;
		}
		y++;
	}
}

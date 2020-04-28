/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_image.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 18:58:55 by lnicosia          #+#    #+#             */
/*   Updated: 2020/04/28 16:38:05 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

Uint32	get_sprite_pixel(SDL_Surface *surface, t_sprite sprite, t_point curr,
t_point size)
{
	double	xalpha;
	double	yalpha;
	Uint32	*pixels;

	xalpha = curr.x / (double)size.x;
	yalpha = curr.y / (double)size.y;
	pixels = (Uint32*)surface->pixels;
	return (pixels[(int)(sprite.start[0].x + xalpha * sprite.size[0].x) +
	(int)(sprite.start[0].y + yalpha * sprite.size[0].y) * surface->w]);
}

/*
**	Copy a sprite into our main texture
**	with scaling
*/

void	apply_sprite(t_sprite sprite, t_point pos, t_point size, t_env *env)
{
	int				x;
	int				y;
	Uint32			pixel;
	SDL_PixelFormat	*fmt;
	SDL_Surface		*surface;

	surface = env->sprite_textures[sprite.texture].surface;
	fmt = surface->format;
	y = -1;
	while (++y < size.y)
	{
		x = -1;
		while (++x < size.x)
		{
			pixel = get_sprite_pixel(surface, sprite, new_point(x, y), size);
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
**	Copy a sprite into our main texture
**	with scaling and a green selection filter
*/

void	apply_sprite_selected(t_sprite sprite, t_point pos, t_point size,
t_env *env)
{
	int				x;
	int				y;
	Uint32			pixel;
	SDL_Surface		*surface;
	Uint32			*texture_pixels;

	texture_pixels = env->sdl.texture_pixels;
	surface = env->sprite_textures[sprite.texture].surface;
	y = -1;
	while (++y < size.y)
	{
		x = -1;
		while (++x < size.x)
		{
			pixel = get_sprite_pixel(surface, sprite, new_point(x, y), size);
			if (pos.y + x >= 0 && pos.y + x < env->w && pos.x + y >= 0
				&& pos.x + y < env->h && pixel != 0xFFC10099)
				texture_pixels[pos.y + x + env->w * (pos.x + y)] =
				blend_alpha(pixel, 0x1ABC9C, 128);
		}
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 12:24:46 by lnicosia          #+#    #+#             */
/*   Updated: 2019/07/03 12:31:36 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

// TODO Protection

void	update_screen(t_env *env)
{
	if (SDL_UpdateTexture(env->sdl.texture, NULL, env->sdl.texture_pixels, env->w * sizeof(Uint32)))
	//if (SDL_UpdateTexture(env->sdl.texture, NULL, env->depth_array, env->w * sizeof(Uint32)))
	{
		ft_printf("Failed to update screen: %s\n", SDL_GetError());
		return ;
	}
	SDL_RenderCopy(env->sdl.renderer, env->sdl.texture, NULL, NULL);
	SDL_RenderPresent(env->sdl.renderer);
}

/*
**	Copy a surface into our main texture
**	TODO Protection
*/

void	apply_surface(SDL_Surface *surface, t_point pos, t_point size, t_env *env)
{
	int				x;
	int				y;
	Uint32			*pixels;
	Uint32			pixel;
	SDL_PixelFormat	*fmt;
	Uint32	*texture_pixels;

	texture_pixels = env->sdl.texture_pixels;
	if (!surface)
	{
		ft_printf("apply_surface error: surface is NULL\n");
		return ;
	}
	pixels = surface->pixels;
	fmt = surface->format;
	y = 0;
	while (y < size.y)
	{
		x = 0;
		while (x < size.x)
		{
			pixel = pixels[x + surface->w * y];
			if ((Uint8)(((pixel & fmt->Amask) >> fmt->Ashift) << fmt->Aloss) != 0
					&& pos.y + x >= 0 && pos.y + x < env->w && pos.x + y >= 0 && pos.x + y < env->h)
			texture_pixels[pos.y + x + env->w * (pos.x + y)] =
				(Uint8)(((pixel & fmt->Amask) >> fmt->Ashift) << fmt->Aloss) << 24
				| (Uint8)(((pixel & fmt->Rmask) >> fmt->Rshift) << fmt->Rloss) << 16
				| (Uint8)(((pixel & fmt->Gmask) >> fmt->Gshift) << fmt->Gloss) << 8
				| (Uint8)(((pixel & fmt->Bmask) >> fmt->Bshift) << fmt->Bloss) << 0;
			x++;
		}
		y++;
	}
}

void	draw_axes(t_env *env)
{
	int		i;
	int		max;
	Uint32	*pixels;

	pixels = env->sdl.texture_pixels;
	i = 0;
	max = env->h;
	while (i < max)
	{
		//env->sdl.img_str[i * env->w + env->w / 2] = 0xFFFFFFFF;
		pixels[i * env->w + env->w / 2] = 0xFFFFFFFF;
		i++;
	}
	i = 0;
	max = env->w;
	while (i < max)
	{
		//env->sdl.img_str[env->h / 2 * env->w + i] = 0xFFFFFFFF;
		pixels[env->h / 2 * env->w + i] = 0xFFFFFFFF;
		i++;
	}
}

void	draw_crosshair(t_env *env)
{
	int y;
	int	x; 
	int max;
	Uint32	*pixels;

	pixels = env->sdl.texture_pixels;
	x = env->w / 2;
	y = env->h / 2 - 10;
	max = env->h / 2 - 2;
	while (y < max)
	{
		pixels[x + y * env->w] = 0xFFFFFFFF;
		y++;
	}
	y = env->h / 2 + 10;
	max = env->h / 2 + 2;
	while (y > max)
	{
		pixels[x + y * env->w] = 0xFFFFFFFF;
		y--;
	}
	y = env->h / 2;
	x = env->w / 2 - 10;
	max = env->w / 2 - 2;
	while (x < max)
	{
		pixels[x + y * env->w] = 0xFFFFFFFF;
		x++;
	}
	x = env->w / 2 + 10;
	max = env->w / 2 + 2;
	while (x > max)
	{
		pixels[x + y * env->w] = 0xFFFFFFFF;
		x--;
	}
}

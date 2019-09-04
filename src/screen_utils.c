/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 12:24:46 by lnicosia          #+#    #+#             */
/*   Updated: 2019/09/04 11:54:49 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

// TODO Protection

void	update_screen(t_env *env)
{
	if (SDL_UpdateTexture(env->sdl.texture, NULL, env->sdl.texture_pixels, env->w * sizeof(Uint32)))
	{
		ft_printf("Failed to update screen: %s\n", SDL_GetError());
		return ;
	}
	SDL_RenderCopy(env->sdl.renderer, env->sdl.texture, NULL, NULL);
	SDL_RenderPresent(env->sdl.renderer);
}

/*
**	Give every pixel a shade according to the zbuffer
*/

void	set_zbuffer_colors(t_env *env)
{
	double	max_z;
	double	min_z;
	int		max;
	int		i;
	int		y;
	int		x;
	double	alpha;

	i = 0;
	max_z = 0;
	min_z = 9999999999;
	max = env->w * env->h;
	while (i < max)
	{
		if (env->depth_array[i] > max_z)
			max_z = env->depth_array[i];
		if (env->depth_array[i] < min_z)
			min_z = env->depth_array[i];
		i++;
	}
	max_z = 30;
	y = 0;
	while (y < env->h)
	{
		x = 0;
		while (x < env->w)
		{
			if ((y <= 300 && x < env->w - 300) || y > 300 || env->editor.in_game || !env->options.show_minimap)
			{
				alpha = 1 - env->depth_array[x + env->w * y] / max_z;
				//ft_printf("alpha = %f\n", alpha);
				if (env->depth_array[x + env->w * y] >= 0 && alpha >= 0 && alpha <= 1)
					env->sdl.texture_pixels[x + env->w * y] = (int)(alpha * 0xFF) << 24
						| (int)(alpha * 0xFF) << 16
						| (int)(alpha * 0xFF) << 8
						| (int)(alpha * 0xFF);
				else if (env->depth_array[x + env->w * y] == 100000000)
					env->sdl.texture_pixels[x + env->w * y] = 0xFFAA0000;
				else
					env->sdl.texture_pixels[x + env->w * y] = 0;
			}
			x++;
		}
		y++;
	}
}

/*
**	Show Zbuffer
*/

void	update_screen_zbuffer(t_env *env)
{
	set_zbuffer_colors(env);
	if (SDL_UpdateTexture(env->sdl.texture, NULL, env->sdl.texture_pixels, env->w * sizeof(Uint32)))
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
	Uint32			*texture_pixels;

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
			/*if ((Uint8)(((pixel & fmt->Amask) >> fmt->Ashift) << fmt->Aloss) != 0
					&&*/ /*if (pos.y + x >= 0 && pos.y + x < env->w && pos.x + y >= 0 && pos.x + y < env->h)
			texture_pixels[pos.y + x + env->w * (pos.x + y)] =
				(Uint8)(((pixel & fmt->Amask) >> fmt->Ashift) << fmt->Aloss) << 24
				| (Uint8)(((pixel & fmt->Rmask) >> fmt->Rshift) << fmt->Rloss) << 16
				| (Uint8)(((pixel & fmt->Gmask) >> fmt->Gshift) << fmt->Gloss) << 8
				| (Uint8)(((pixel & fmt->Bmask) >> fmt->Bshift) << fmt->Bloss) << 0;*/
			if (pos.y + x >= 0 && pos.y + x < env->w && pos.x + y >= 0 && pos.x + y < env->h)
				texture_pixels[pos.y + x + env->w * (pos.x + y)] = blend_alpha(texture_pixels[pos.y + x + env->w * (pos.x + y)], pixel, (Uint8)(((pixel & fmt->Amask) >> fmt->Ashift) << fmt->Aloss));
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
		pixels[i * env->w + env->h_w] = 0xFFFFFFFF;
		i++;
	}
	i = 0;
	max = env->w;
	while (i < max)
	{
		pixels[env->h_h * env->w + i] = 0xFFFFFFFF;
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
	x = env->h_w;
	y = env->h_h - 10;
	max = env->h_h - 2;
	while (y < max)
	{
		pixels[x + y * env->w] = 0xFFFFFFFF;
		y++;
	}
	y = env->h_h + 10;
	max = env->h_h + 2;
	while (y > max)
	{
		pixels[x + y * env->w] = 0xFFFFFFFF;
		y--;
	}
	y = env->h_h;
	x = env->h_w - 10;
	max = env->h_w - 2;
	while (x < max)
	{
		pixels[x + y * env->w] = 0xFFFFFFFF;
		x++;
	}
	x = env->h_w + 10;
	max = env->h_w + 2;
	while (x > max)
	{
		pixels[x + y * env->w] = 0xFFFFFFFF;
		x--;
	}
}

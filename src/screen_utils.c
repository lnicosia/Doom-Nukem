/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 12:24:46 by lnicosia          #+#    #+#             */
/*   Updated: 2019/05/19 19:06:17 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

// TODO Protection

void	update_screen(t_env *env)
{
	//env->sdl.texture = SDL_CreateTextureFromSurface(env->sdl.renderer, env->sdl.surface);
	//SDL_SetTextureBlendMode(env->sdl.texture, SDL_BLENDMODE_BLEND);
	SDL_UpdateTexture(env->sdl.texture, NULL, env->sdl.texture_pixels, env->w * sizeof(Uint32));
	SDL_RenderCopy(env->sdl.renderer, env->sdl.texture, NULL, NULL);
	//SDL_DestroyTexture(env->sdl.texture);
	SDL_RenderPresent(env->sdl.renderer);
}

/*
**	Copy a surface into our main texture
*/

void	apply_surface(SDL_Surface *surface, t_v2 pos, t_v2 size, t_env *env)
{
	int		x;
	int		y;
	Uint32	*pixels;
	SDL_PixelFormat	*fmt;

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
			if ((Uint8)(((pixels[(int)(x + surface->w * y)] & fmt->Amask) >> fmt->Ashift) << fmt->Aloss) != 0
					&& pos.y + x >= 0 && pos.y + x < env->w && pos.x + y >= 0 && pos.x + y < env->h)
				/*env->sdl.texture_pixels[(int)(pos.y + x + env->w * (pos.x + y))] =
					pixels[(int)(x + surface->w * y)];*/
			env->sdl.texture_pixels[(int)(pos.y + x + env->w * (pos.x + y))] =
				(Uint8)(((pixels[(int)(x + surface->w * y)] & fmt->Rmask) >> fmt->Rshift) << fmt->Rloss) << 24
				| (Uint8)(((pixels[(int)(x + surface->w * y)] & fmt->Gmask) >> fmt->Gshift) << fmt->Gloss) << 16
				| (Uint8)(((pixels[(int)(x + surface->w * y)] & fmt->Bmask) >> fmt->Bshift) << fmt->Bloss) << 8
				| (Uint8)(((pixels[(int)(x + surface->w * y)] & fmt->Amask) >> fmt->Ashift) << fmt->Aloss);
			x++;
		}
		y++;
	}
}

void	draw_axes(t_env *env)
{
	int	i;

	i = 0;
	while (i < env->h)
	{
		//env->sdl.img_str[i * env->w + env->w / 2] = 0xFFFFFFFF;
		env->sdl.texture_pixels[i * env->w + env->w / 2] = 0xFFFFFFFF;
		i++;
	}
	i = 0;
	while (i < env->w)
	{
		//env->sdl.img_str[env->h / 2 * env->w + i] = 0xFFFFFFFF;
		env->sdl.texture_pixels[env->h / 2 * env->w + i] = 0xFFFFFFFF;
		i++;
	}
}

void	draw_crosshair(t_env *env)
{
	int y;
	int	x; 

	x = env->w / 2;
	y = env->h / 2 - 10;
	while (y < env->h / 2 - 2)
	{
		//env->sdl.img_str[x + y * env->w] = 0xFFFFFFFF;
		env->sdl.texture_pixels[x + y * env->w] = 0xFFFFFFFF;
		y++;
	}
	y = env->h / 2 + 10;
	while (y > env->h / 2 + 2)
	{
		//env->sdl.img_str[x + y * env->w] = 0xFFFFFFFF;
		env->sdl.texture_pixels[x + y * env->w] = 0xFFFFFFFF;
		y--;
	}
	y = env->h / 2;
	x = env->w / 2 - 10;
	while (x < env->w / 2 - 2)
	{
		//env->sdl.img_str[x + y * env->w] = 0xFFFFFFFF;
		env->sdl.texture_pixels[x + y * env->w] = 0xFFFFFFFF;
		x++;
	}
	x = env->w / 2 + 10;
	while (x > env->w / 2 + 2)
	{
		//env->sdl.img_str[x + y * env->w] = 0xFFFFFFFF;
		env->sdl.texture_pixels[x + y * env->w] = 0xFFFFFFFF;
		x--;
	}
}

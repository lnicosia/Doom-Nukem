/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 12:24:46 by lnicosia          #+#    #+#             */
/*   Updated: 2020/03/11 13:51:38 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

void	update_screen(t_env *env)
{
	if (SDL_UpdateTexture(env->sdl.texture, NULL, env->sdl.texture_pixels,
	  	env->w * sizeof(Uint32)))
	{
		ft_printf("Failed to update screen: %s\n", SDL_GetError());
		return ;
	}
	SDL_RenderCopy(env->sdl.renderer, env->sdl.texture, NULL, NULL);
	SDL_RenderPresent(env->sdl.renderer);
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

void	draw_crosshair2(t_env *env)
{
	int		y;
	int		x; 
	int		max;
	Uint32	*pixels;

	pixels = env->sdl.texture_pixels;
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

void	draw_crosshair(t_env *env)
{
	int		y;
	int		x; 
	int		max;
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
	draw_crosshair2(env);
}

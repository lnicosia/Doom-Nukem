/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 12:24:46 by lnicosia          #+#    #+#             */
/*   Updated: 2019/04/29 17:09:57 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

// TODO Protection

void	update_screen(t_env *env)
{
	env->sdl.texture = SDL_CreateTextureFromSurface(env->sdl.renderer, env->sdl.surface);
	SDL_RenderCopy(env->sdl.renderer, env->sdl.texture, NULL, NULL);
	SDL_DestroyTexture(env->sdl.texture);
	SDL_RenderPresent(env->sdl.renderer);
}

void	draw_axes(t_env *env)
{
	int	i;

	i = 0;
	while (i < env->h)
	{
		env->sdl.img_str[i * env->w + env->w / 2] = 0xFFFFFFFF;
		i++;
	}
	i = 0;
	while (i < env->w)
	{
		env->sdl.img_str[env->h / 2 * env->w + i] = 0xFFFFFFFF;
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
		env->sdl.img_str[x + y * env->w] = 0xFFFFFFFF;
		y++;
	}
	y = env->h / 2 + 10;
	while (y > env->h / 2 + 2)
	{
		env->sdl.img_str[x + y * env->w] = 0xFFFFFFFF;
		y--;
	}
	y = env->h / 2;
	x = env->w / 2 - 10;
	while (x < env->w / 2 - 2)
	{
		env->sdl.img_str[x + y * env->w] = 0xFFFFFFFF;
		x++;
	}
	x = env->w / 2 + 10;
	while (x > env->w / 2 + 2)
	{
		env->sdl.img_str[x + y * env->w] = 0xFFFFFFFF;
		x--;
	}
}

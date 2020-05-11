/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_sdl.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 15:43:13 by lnicosia          #+#    #+#             */
/*   Updated: 2020/04/30 13:40:55 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

int		set_sdl2(t_env *env)
{
	if (SDL_RenderCopy(env->sdl.renderer, env->sdl.texture, NULL, NULL) != 0)
		return (ft_printf("SDL_RendererCopy error: %s\n", SDL_GetError()));
	SDL_RenderPresent(env->sdl.renderer);
	SDL_SetWindowDisplayMode(env->sdl.window, NULL);
	SDL_GetRelativeMouseState(&env->sdl.mouse_x, &env->sdl.mouse_y);
	return (0);
}

int		set_sdl(t_env *env)
{
	if (!(env->sdl.window = SDL_CreateWindow("Dookme", SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED, env->w, env->h, SDL_WINDOW_MOUSE_FOCUS)))
		return (ft_printf("SDL_CreateWindow error: %s\n", SDL_GetError()));
	if (!(env->sdl.renderer = SDL_CreateRenderer(env->sdl.window,
		-1, SDL_RENDERER_TARGETTEXTURE)))
		return (ft_printf("SDL_CreateRenderer error: %s\n", SDL_GetError()));
	if (!(env->sdl.texture = SDL_CreateTexture(env->sdl.renderer,
		SDL_PIXELFORMAT_ARGB8888, SDL_TEXTUREACCESS_STREAMING, env->w, env->h)))
		return (ft_printf("SDL_CreateTextureFromSurface error: %s\n",
		SDL_GetError()));
		if (!(env->sdl.texture_pixels = (Uint32*)ft_memalloc(sizeof(Uint32)
		* env->w * env->h)))
		return (custom_error("Could not malloc texture pixels\n"));
	if (!(env->zbuffer = (double*)ft_memalloc(sizeof(double)
		* env->w * env->h)))
		return (custom_error("Could not malloc depth array\n"));
	if (!(env->ymin = (int*)ft_memalloc(sizeof(int) * env->w)))
		return (custom_error("Could not malloc ymin array\n"));
	if (!(env->ymax = (int*)ft_memalloc(sizeof(int) * env->w)))
		return (custom_error("Could not malloc ymax array\n"));
	clear_image(env);
	return (set_sdl2(env));
}

int		init_sdl(t_env *env)
{
	ft_printf("Initializing SDL..\n");
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
		return (ft_printf("SDL_Init error: %s\n", SDL_GetError()));
	env->time.milli_s = 0;
	if (set_sdl(env))
		return (custom_error("Could not set SDL\n"));
	return (0);
}

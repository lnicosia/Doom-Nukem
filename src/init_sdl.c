/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_sdl.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 15:43:13 by lnicosia          #+#    #+#             */
/*   Updated: 2019/06/05 15:12:55 by sipatry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int		init_sdl(t_env *env)
{
	ft_printf("Initializing SDL..\n");
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
		return(ft_printf("SDL_Init error: %s\n", SDL_GetError()));
	if (!(env->sdl.window = SDL_CreateWindow(
					"Portals !!!!!",
					SDL_WINDOWPOS_CENTERED,
					SDL_WINDOWPOS_CENTERED,
					env->w,
					env->h,
					SDL_WINDOW_MOUSE_FOCUS)))
		return (ft_printf("SDL_CreateWindow error: %s\n", SDL_GetError()));
	if (!(env->sdl.renderer = SDL_CreateRenderer(
					env->sdl.window,
					-1,
					SDL_RENDERER_TARGETTEXTURE)))
		return (ft_printf("SDL_CreateRenderer error: %s\n", SDL_GetError()));
	/*if (SDL_SetRenderDrawBlendMode(env->sdl.renderer, SDL_BLENDMODE_NONE))
		return (ft_printf("SDL_RendererDrawBlendMode error: %s\n", SDL_GetError()));*/
	if (!(env->sdl.surface = SDL_CreateRGBSurfaceWithFormat(
					0,
					env->w,
					env->h,
					32,
					SDL_PIXELFORMAT_RGBA8888)))
		return (ft_printf("SDL_CreateRGBSurface error: %s\n", SDL_GetError()));
	if (SDL_SetSurfaceBlendMode(env->sdl.surface, SDL_BLENDMODE_BLEND))
		return (ft_printf("SDL_SurfaceDrawBlendMode error: %s\n", SDL_GetError()));
	env->sdl.img_str = env->sdl.surface->pixels;
	if (!(env->sdl.texture = SDL_CreateTexture(
					env->sdl.renderer,
					SDL_PIXELFORMAT_ARGB8888,
					SDL_TEXTUREACCESS_STREAMING,
					env->w,
					env->h)))
		return (ft_printf("SDL_CreateTextureFromSurface error: %s\n", SDL_GetError()));
	if (!(env->sdl.texture_pixels = (Uint32*)malloc(sizeof(Uint32) * env->w * env->h)))
		return (ft_printf("Could not malloc texture pixels\n"));
	if (!(env->depth_array = (double*)malloc(sizeof(double) * env->w)))
		return (ft_printf("Could not malloc depth array\n"));
	clear_image(env);
	if (SDL_SetRelativeMouseMode(1))
		return (ft_printf("SDL_SetRelativeMouseMode error: %s\n", SDL_GetError()));
	/*if (SDL_RenderCopy(
				env->sdl.renderer,
				env->sdl.texture,
				NULL,
				NULL) != 0)
		return (ft_printf("SDL_RendererCopy error: %s\n", SDL_GetError()));
	SDL_RenderPresent(env->sdl.renderer);*/
	env->time.milli_s =  0;
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_sdl.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaerhard <gaerhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 15:43:13 by lnicosia          #+#    #+#             */
/*   Updated: 2019/11/21 17:02:00 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

int		set_sdl(t_env *env)
{
	/*env->w = 1280;
	env->h = 720;*/
	if (!(env->sdl.window = SDL_CreateWindow(
					"Dookme",
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
	// Check renderer info
	/*SDL_RendererInfo	info;
	SDL_GetRendererInfo(env->sdl.renderer, &info);
	ft_printf("renderer:\nname: %s\nflags: %X\nnum_texture_formats: %x\n",
			info.name, info.flags, info.num_texture_formats);
	ft_printf("SDL_RENDER_SOFTWARE = %X\n", SDL_RENDERER_SOFTWARE);
	ft_printf("SDL_RENDER_ACCELERATED = %X\n", SDL_RENDERER_ACCELERATED);
	ft_printf("SDL_RENDER_PRESENTVSYNC = %X\n", SDL_RENDERER_PRESENTVSYNC);
	ft_printf("SDL_RENDER_TARGETTEXTURE = %X\n", SDL_RENDERER_TARGETTEXTURE);
	ft_printf("OR'd = %X\n", 2 | 8);
	ft_printf("texture formats:\n");
	unsigned int i = 0;
	while (i < info.num_texture_formats)
	{
		ft_printf("%s\n", SDL_GetPixelFormatName(info.texture_formats[i]));
		i++;
	}
	ft_printf("max width = %d\n", info.max_texture_width);
	ft_printf("max height = %d\n", info.max_texture_height);*/
	/*if (SDL_SetRenderDrawBlendMode(env->sdl.renderer, SDL_BLENDMODE_NONE))
		return (ft_printf("SDL_RendererDrawBlendMode error: %s\n", SDL_GetError()));*/
	if (!(env->sdl.texture = SDL_CreateTexture(
					env->sdl.renderer,
					SDL_PIXELFORMAT_ARGB8888,
					SDL_TEXTUREACCESS_STREAMING,
					env->w,
					env->h)))
		return (ft_printf("SDL_CreateTextureFromSurface error: %s\n", SDL_GetError()));
	if (!(env->sdl.texture_pixels = (Uint32*)malloc(sizeof(Uint32) * env->w * env->h)))
		return (ft_printf("Could not malloc texture pixels\n"));
	if (!(env->zbuffer = (double*)malloc(sizeof(double) * env->w * env->h)))
		return (ft_printf("Could not malloc depth array\n"));
	if (!(env->ymin = (int*)malloc(sizeof(int) * env->w)))
		return (ft_printf("Could not malloc ymin array\n"));
	if (!(env->ymax = (int*)malloc(sizeof(int) * env->w)))
		return (ft_printf("Could not malloc ymax array\n"));
	if (!(env->xmin = (int*)malloc(sizeof(int) * env->h)))
		return (ft_printf("Could not malloc ymin array\n"));
	if (!(env->xmax = (int*)malloc(sizeof(int) * env->h)))
		return (ft_printf("Could not malloc ymax array\n"));
	if (!(env->current_ceiling = (double*)malloc(sizeof(double) * env->w)))
		return (ft_printf("Could not malloc depth array\n"));
	if (!(env->current_floor = (double*)malloc(sizeof(double) * env->w)))
		return (ft_printf("Could not malloc depth array\n"));
	if (!(env->max_ceiling = (double*)malloc(sizeof(double) * env->w)))
		return (ft_printf("Could not malloc depth array\n"));
	if (!(env->max_floor = (double*)malloc(sizeof(double) * env->w)))
		return (ft_printf("Could not malloc depth array\n"));
	if (!(env->z = (double*)malloc(sizeof(double) * env->w)))
		return (ft_printf("Could not malloc depth array\n"));
	if (!(env->clipped_alpha = (double*)malloc(sizeof(double) * env->w)))
		return (ft_printf("Could not malloc depth array\n"));
	if (!(env->line_height = (double*)malloc(sizeof(double) * env->w)))
		return (ft_printf("Could not malloc depth array\n"));
	if (!(env->divider = (double*)malloc(sizeof(double) * env->w)))
		return (ft_printf("Could not malloc depth array\n"));
	if (!(env->no_slope_current_floor = (double*)malloc(sizeof(double) * env->w)))
		return (ft_printf("Could not malloc depth array\n"));
	if (!(env->no_slope_current_ceiling = (double*)malloc(sizeof(double) * env->w)))
		return (ft_printf("Could not malloc depth array\n"));
	if (!(env->ceiling_start = (double*)malloc(sizeof(double) * env->w)))
		return (ft_printf("Could not malloc depth array\n"));
	if (!(env->floor_start = (double*)malloc(sizeof(double) * env->w)))
		return (ft_printf("Could not malloc depth array\n"));
	if (!(env->z_near_z = (double*)malloc(sizeof(double) * env->w)))
		return (ft_printf("Could not malloc depth array\n"));
	if (!(env->neighbor_current_floor = (double*)malloc(sizeof(double) * env->w)))
		return (ft_printf("Could not malloc depth array\n"));
	if (!(env->neighbor_current_ceiling = (double*)malloc(sizeof(double) * env->w)))
		return (ft_printf("Could not malloc depth array\n"));
	if (!(env->neighbor_max_floor = (double*)malloc(sizeof(double) * env->w)))
		return (ft_printf("Could not malloc depth array\n"));
	if (!(env->neighbor_max_ceiling = (double*)malloc(sizeof(double) * env->w)))
		return (ft_printf("Could not malloc depth array\n"));
	if (!(env->zrange = (double*)malloc(sizeof(double) * env->w)))
		return (ft_printf("Could not malloc depth array\n"));
	if (!(env->texel = (t_v2*)malloc(sizeof(t_v2) * env->w)))
		return (ft_printf("Could not malloc depth array\n"));
	if (!(env->texel_near_z = (t_v2*)malloc(sizeof(t_v2) * env->w)))
		return (ft_printf("Could not malloc depth array\n"));
	if (!(env->texel_camera_range = (t_v2*)malloc(sizeof(t_v2) * env->w)))
		return (ft_printf("Could not malloc depth array\n"));
	if (!(env->camera_z = (t_v2*)malloc(sizeof(t_v2) * env->w)))
		return (ft_printf("Could not malloc depth array\n"));
	if (!(env->wall_texel = (t_v2*)malloc(sizeof(t_v2) * env->w)))
		return (ft_printf("Could not malloc depth array\n"));
	if (!(env->vline_data = (t_vline_data*)malloc(sizeof(t_vline_data) * env->w)))
		return (ft_printf("Could not malloc depth array\n"));
	clear_image(env);
	if (SDL_RenderCopy(
				env->sdl.renderer,
				env->sdl.texture,
				NULL,
				NULL) != 0)
		return (ft_printf("SDL_RendererCopy error: %s\n", SDL_GetError()));
	SDL_RenderPresent(env->sdl.renderer);
	SDL_SetWindowDisplayMode(env->sdl.window, NULL);
	SDL_GetRelativeMouseState(&env->sdl.mouse_x, &env->sdl.mouse_y);
	return (0);
}

int		init_sdl(t_env *env)
{
	ft_printf("Initializing SDL..\n");
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
		return(ft_printf("SDL_Init error: %s\n", SDL_GetError()));
	env->time.milli_s =  0;
	if (set_sdl(env))
		return (ft_printf("Could not set SDL\n"));
	return (0);
}

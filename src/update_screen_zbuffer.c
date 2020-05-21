/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_screen_zbuffer.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/01 11:37:27 by lnicosia          #+#    #+#             */
/*   Updated: 2020/05/01 11:38:44 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

void	set_zbuffer_pixel_color(int x, int y, double max_z, t_env *env)
{
	double	alpha;

	alpha = 1 - env->zbuffer[x + env->w * y] / max_z;
	if (env->zbuffer[x + env->w * y] >= 0 && alpha >= 0 && alpha <= 1)
		env->sdl.texture_pixels[x + env->w * y] = (int)(alpha * 0xFF) << 24
			| (int)(alpha * 0xFF) << 16
			| (int)(alpha * 0xFF) << 8
			| (int)(alpha * 0xFF);
	else if (env->zbuffer[x + env->w * y] == 100000000)
		env->sdl.texture_pixels[x + env->w * y] = 0xFFAA0000;
	else
		env->sdl.texture_pixels[x + env->w * y] = 0;
}

/*
**	Give every pixel a shade according to the zbuffer
*/

void	set_zbuffer_colors(t_env *env)
{
	double	max_z;
	int		y;
	int		x;

	max_z = 30;
	y = 0;
	while (y < env->h)
	{
		if (env->editor.tab)
			x = 400;
		else
			x = 0;
		while (x < env->w)
		{
			if ((y <= 300 && x < env->w - 300) || y > 300
				|| env->editor.in_game || !env->options.show_minimap)
				set_zbuffer_pixel_color(x, y, max_z, env);
			x++;
		}
		y++;
	}
}

/*
**	Show Zbuffer
*/

int		update_screen_zbuffer(t_env *env)
{
	set_zbuffer_colors(env);
	if (SDL_UpdateTexture(env->sdl.texture, NULL, env->sdl.texture_pixels,
		env->w * sizeof(Uint32)))
		return (custom_error("Failed to update screen: %s\n", SDL_GetError()));
	if (SDL_RenderCopy(env->sdl.renderer, env->sdl.texture, NULL, NULL))
		return (custom_error("SDL_RenderCopy error: %s\n", SDL_GetError()));
	SDL_RenderPresent(env->sdl.renderer);
	return (0);
}

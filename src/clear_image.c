/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_image.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 15:54:43 by lnicosia          #+#    #+#             */
/*   Updated: 2019/06/20 18:01:38 by sipatry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	clear_image(t_env *env)
{
	int		y;
	int		x;
	int		y_env;
	int		xmax;
	int		ymax;

	y = 0;
	xmax = env->w;
	ymax = env->h;
	while (y < ymax)
	{
		x = 0;
		y_env = y * xmax;
		while (x < xmax)
		{
			//env->sdl.img_str[x + y * env->w] = 0xFF;
			env->sdl.texture_pixels[x + y_env] = 0xFF000000;
			x++;
		}
		y++;
	}
	/*int y = 0;
	while (y < env->h / 2)
	{
		int x = 0;
		while (x < env->w)
		{
			env->sdl.img_str[x + y * env->w] = 0x222222FF;
			x++;
		}
		y++;
	}
	y = env->h / 2;
	while (y < env->h)
	{
		int x = 0;
		while (x < env->w)
		{
			env->sdl.img_str[x + y * env->w] = 0x444444FF;
			x++;
		}
		y++;
	}*/
	//SDL_UpdateTexture(env->sdl.texture, NULL, env->sdl.texture_pixels, sizeof(Uint32) * env->w);
}

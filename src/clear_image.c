/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_image.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 15:54:43 by lnicosia          #+#    #+#             */
/*   Updated: 2019/05/20 11:21:05 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	clear_image(t_env *env)
{
	int		y;
	int		x;

	y = 0;
	while (y < env->h)
	{
		x = 0;
		while (x < env->w)
		{
			//env->sdl.img_str[x + y * env->w] = 0xFF;
			env->sdl.texture_pixels[x + y * env->w] = 0;
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

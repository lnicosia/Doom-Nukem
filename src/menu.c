/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipatry <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/26 14:04:47 by sipatry           #+#    #+#             */
/*   Updated: 2019/06/26 16:21:31 by sipatry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	add_image(t_env *env, int i, int x, int y)
{
	int	xx;
	int	yy;

	xx = 0;
	while (xx < env->textures[i].surface->w && xx < env->w)
	{
		yy = 0;
		while (yy < env->textures[i].surface->h && yy < env->h)
		{
			if (env->textures[i].str[xx + env->textures[i].surface->w * yy] != 0xFFC10099)
				env->sdl.texture_pixels[(x + (y * env->w)) + xx + env->w * yy] = env->textures[i].str[xx + env->textures[i].surface->w * yy];
			yy++;
		}
		xx++;
	}

}

void	start_menu(t_env *env)
{
	clear_image(env);
	SDL_SetRelativeMouseMode(0);
	add_image(env, 32, 0, 0);
	print_text(new_point(780, 850), new_printable_text("START", env->sdl.fonts.amazdoom70, 0xFFFFFFFF, 70), env);
	update_screen(env);
}

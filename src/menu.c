/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipatry <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/26 14:04:47 by sipatry           #+#    #+#             */
/*   Updated: 2019/07/03 14:07:06 by sipatry          ###   ########.fr       */
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

void	add_button(t_env *env, int text, int x, int y, int ref_but)
{
	env->button[ref_but].x = x;
	env->button[ref_but].y = y;
	env->button[ref_but].image = text;
	env->button[ref_but].id = ref_but;
	if (text != 0)
		add_image(env, text, x, y);
}

void	start_menu(t_env *env)
{
	clear_image(env);
	SDL_SetRelativeMouseMode(0);
	add_image(env, 32, 0, 0);
	add_button(env, 0, 850, 780, 0);
	print_text(new_point(780, 850), new_printable_text("START", env->sdl.fonts.amazdoom70, 0xFFFFFFFF, 70), env);
	update_screen(env);
}

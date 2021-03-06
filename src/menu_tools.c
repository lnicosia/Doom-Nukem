/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu_tools.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/23 11:36:49 by sipatry           #+#    #+#             */
/*   Updated: 2020/05/19 10:53:13 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

void	add_image(t_env *env, int i, int x, int y)
{
	int	xx;
	int	yy;

	xx = 0;
	while (xx < env->sprite_textures[i].surface->w && xx < env->w)
	{
		yy = 0;
		while (yy < env->sprite_textures[i].surface->h && yy < env->h)
		{
			if (env->sprite_textures[i].str[xx + env->sprite_textures[i].
				surface->w * yy] != 0xFFC10099)
				env->sdl.texture_pixels[(x + (y * env->w)) + xx + env->w * yy] =
				env->sprite_textures[i].str[xx
				+ env->sprite_textures[i].surface->w * yy];
			yy++;
		}
		xx++;
	}
}

void	add_button(t_env *env, int text, t_point nb, int ref_but)
{
	env->button[ref_but].x = nb.x;
	env->button[ref_but].y = nb.y;
	env->button[ref_but].image = text;
	env->button[ref_but].id = ref_but;
	if (text != 0)
		add_image(env, text, nb.x, nb.y);
}

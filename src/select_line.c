/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select_line.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 15:14:43 by lnicosia          #+#    #+#             */
/*   Updated: 2019/11/28 15:17:10 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

void	select_line(t_vline vline, t_env *env)
{
	int	coord;

	while (vline.start <= vline.end)
	{
		coord = vline.x + env->w * vline.start;
		env->sdl.texture_pixels[coord] =
		blend_alpha(env->sdl.texture_pixels[coord], 0x1ABC9C, 128);
		vline.start++;
	}
}

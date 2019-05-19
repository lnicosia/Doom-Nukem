/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_pointers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/25 13:25:06 by lnicosia          #+#    #+#             */
/*   Updated: 2019/05/19 19:08:36 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	init_pointers(t_env *env)
{
	ft_printf("Initializing pointers..\n");
	env->sectors = NULL;
	env->vertices = NULL;
	env->sdl.window = NULL;
	env->sdl.renderer = NULL;
	env->sdl.surface = NULL;
	env->sdl.texture = NULL;
	env->sdl.img_str = NULL;
	env->sdl.texture_pixels = NULL;
	env->xmin = NULL;
	env->xmax = NULL;
	env->screen_sectors = NULL;
	env->depth_array = NULL;
	env->rendered_sectors = NULL;
	env->sdl.fonts.amazdoom20 = NULL;
	env->sdl.fonts.amazdoom50 = NULL;
	env->sdl.fonts.bebasneue = NULL;
	env->sdl.fonts.alice = NULL;
}

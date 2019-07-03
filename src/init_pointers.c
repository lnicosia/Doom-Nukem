/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_pointers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaerhard <gaerhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/25 13:25:06 by lnicosia          #+#    #+#             */
/*   Updated: 2019/07/03 14:36:49 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	init_pointers(t_env *env)
{
	int	i;

	ft_printf("Initializing pointers..\n");
	env->sectors = NULL;
	env->vertices = NULL;
	env->objects = NULL;
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
	env->sdl.fonts.alice30 = NULL;
	env->sdl.fonts.alice70 = NULL;
	env->screen_pos = NULL;
	env->sound.background = NULL;
	env->sound.footstep = NULL;
	env->sound.jump = NULL;
	i = 0;
	while (i < MAX_TEXTURE)
	{
		env->textures[i].surface = NULL;
		env->textures[i].str = NULL;
		i++;
	}
	i = 0;
	while (i < NB_WEAPONS)
	{
		env->weapons[i].sound = NULL;
		env->weapons[i].empty = NULL;
		i++;
	}
}

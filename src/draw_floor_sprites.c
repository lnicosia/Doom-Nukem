/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_floor_sprites.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 10:12:52 by lnicosia          #+#    #+#             */
/*   Updated: 2019/11/20 10:57:09 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "render.h"

void	draw_floor_sprites(t_sector sector, t_render render, t_env *env)
{
	int		i;
	int		start;

	i = 0;
	while (i < sector.nb_floor_sprites)
	{
		if (sector.floor_sprites.sprite[i] != -1)
		{
			start = env->wall_sprites[sector.floor_sprites.sprite[i]].start[0].x;
		}
		i++;
	}
	(void)render;
	(void)sector;
	(void)env;
}

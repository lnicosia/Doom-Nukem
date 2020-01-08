/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_floor_sprites.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 18:45:04 by lnicosia          #+#    #+#             */
/*   Updated: 2019/11/28 18:58:21 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"   

void	draw_floor_sprites(t_sector sector, t_render render, t_env *env)
{
	if (!env->options.lighting || (!sector.brightness && !sector.intensity))
		draw_floor_sprites_no_light(sector, render, env);
	else if (!sector.brightness)
		draw_floor_sprites_color(sector, render, env);
	else if (!sector.intensity)
		draw_floor_sprites_brightness(sector, render, env);
	else
		draw_floor_sprites_both(sector, render, env);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_ceiling_sprites.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 10:12:52 by lnicosia          #+#    #+#             */
/*   Updated: 2019/11/28 18:58:15 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "render.h"

void	draw_ceiling_sprites(t_sector *sector, t_render *render, t_env *env)
{
	if (!env->options.lighting || (!sector->brightness && !sector->intensity))
		draw_ceiling_sprites_no_light(sector, render, env);
	else if (!sector->brightness)
		draw_ceiling_sprites_color(sector, render, env);
	else if (!sector->intensity)
		draw_ceiling_sprites_brightness(sector, render, env);
	else
		draw_ceiling_sprites_both(sector, render, env);
}

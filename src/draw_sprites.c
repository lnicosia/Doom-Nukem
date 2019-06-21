/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_sprites.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/20 15:04:12 by lnicosia          #+#    #+#             */
/*   Updated: 2019/06/21 16:08:14 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "render.h"

void		draw_object(t_object object, t_env *env, t_render *render)
{
	t_render_object	orender;
	int				x;
	int				xend;
	int				y;
	int				yend;

	(void)render;
	get_translated_object_pos(&orender, object, env);
	get_rotated_object_pos(&orender, env);
	project_object(&orender, object, env);
	x = orender.screen_pos.x - object.size.x / 2.0;
	xend = orender.screen_pos.x + object.size.x / 2.0;
	yend = orender.screen_pos.y;
	/*ft_printf("bas gauche = [%d][%d]\n", x, yend);
	ft_printf("haut droit = [%d][%d]\n", xend, orender.screen_pos.y - object.size.y);*/
	while (x <= xend)
	{
		y = orender.screen_pos.y - object.size.y;
		while (y <= yend)
		{
			if (x >= 0 && x < env->w && y >= 0 && y < env->h)
				env->sdl.texture_pixels[x + y * env->w] = 0xFFFF0000;
			y++;
		}
		x++;
	}
}

void		draw_sprites(t_env *env, t_render *render)
{
	int	i;

	i = 0;
	while (i < env->nb_objects)
	{
		if (env->objects[i].sector == render->sector && !env->objects[i].drawn)
			draw_object(env->objects[i], env, render);
		i++;
	}
}

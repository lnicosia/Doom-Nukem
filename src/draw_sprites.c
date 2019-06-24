/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_sprites.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/20 15:04:12 by lnicosia          #+#    #+#             */
/*   Updated: 2019/06/24 12:12:01 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "render.h"

void		draw_object(t_object object, t_env *env, t_render *render)
{
	t_render_object	orender;
	int				x;
	int				xstart;
	int				xend;
	int				y;
	int				ystart;
	int				yend;
	int				textx;
	int				texty;
	double			xalpha;
	double			yalpha;
	t_texture		texture;

	(void)render;
	get_translated_object_pos(&orender, object, env);
	get_rotated_object_pos(&orender, env);
	project_object(&orender, object, env);
	if (orender.rotated_pos.z <= 0)
		return ;
	xstart = orender.screen_pos.x - object.size.x / 2.0 / (orender.dist / object.scale);
	ystart = orender.screen_pos.y - object.size.y / (orender.dist / object.scale);
	xend = orender.screen_pos.x + object.size.x / 2.0 / (orender.dist / object.scale);
	yend = (orender.screen_pos.y);
	if (!object.oriented)
		texture = env->textures[object.sprites[0]];
	x = xstart;
	while (x <= xend)
	{
		xalpha = (x - xstart) / (double)(xend - xstart);
		textx = (1.0 - xalpha) * object.start.x + xalpha * object.end.x;
		y = ystart;
		while (y <= yend)
		{
			yalpha = (y - ystart) / (double)(yend - ystart);
			texty = (1.0 - yalpha) * object.start.y + yalpha * object.end.y;
			if (x >= 0 && x < env->w && y >= 0 && y < env->h
					&& texture.str[textx + texty * texture.surface->w] != 0xFFC10099)
			{
				if (!env->options.lighting)
					env->sdl.texture_pixels[x + y * env->w] = texture.str[textx + texty * texture.surface->w];
				else
					env->sdl.texture_pixels[x + y * env->w] = apply_light(texture.str[textx + texty * texture.surface->w], render->light);
			}
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

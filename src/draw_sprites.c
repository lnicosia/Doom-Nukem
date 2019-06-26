/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_sprites.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/20 15:04:12 by lnicosia          #+#    #+#             */
/*   Updated: 2019/06/26 13:45:09 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "render.h"

static int	get_sprite_direction(t_object object, t_render_object orender)
{
	double	angle;

	angle = (atan2(orender.translated_pos.z, orender.translated_pos.x)) * CONVERT_DEGREES;
	if (angle >= object.angle - 22.5 && angle < object.angle + 22.5)
		return (4);
	else if (angle >= object.angle + 22.5 && angle < object.angle + 67.5)
		return (5);
	else if (angle >= object.angle + 67.5 && angle < object.angle + 112.5)
		return (6);
	else if (angle >= object.angle + 112.5 && angle < object.angle + 157.5)
		return (7);
	else if (angle >= object.angle + 157.5 && angle < object.angle + 202.5)
		return (0);
	else if (angle >= object.angle + 202.5 && angle < object.angle + 247.5)
		return (1);
	else if (angle >= object.angle + 247.5 && angle < object.angle + 292.5)
		return (2);
	else if (angle >= object.angle + 292.5 && angle < object.angle + 337.5)
		return (3);
	else if (angle >= object.angle + 337.5)
		return (0);
	else if (angle < object.angle - 22.5 && angle >= object.angle - 67.5)
		return (3);
	else if (angle < object.angle - 67.5 && angle >= object.angle - 112.5)
		return (2);
	else if (angle < object.angle - 112.5 && angle >= object.angle - 157.5)
		return (1);
	else if (angle < object.angle - 157.5 && angle >= object.angle - 202.5)
		return (0);
	else if (angle < object.angle - 202.5 && angle >= object.angle - 247.5)
		return (7);
	else if (angle < object.angle - 247.5 && angle >= object.angle - 292.5)
		return (6);
	else if (angle < object.angle - 292.5 && angle >= object.angle - 337.5)
		return (5);
	else if (angle < object.angle - 337.5)
		return (4);
	else
		return (0);
}

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
	int				index;
	double			xalpha;
	double			yalpha;
	t_texture		texture;

	(void)render;
	get_translated_object_pos(&orender, object, env);
	get_rotated_object_pos(&orender, env);
	project_object(&orender, object, env);
	if (orender.rotated_pos.z <= 1)
		return ;
	if (!object.oriented)
		index = 0;
	else
		index = get_sprite_direction(object, orender);
	texture = env->textures[object.sprite];
	xstart = orender.screen_pos.x - object.size[index].x / 2.0 / (orender.rotated_pos.z / object.scale);
	ystart = orender.screen_pos.y - object.size[index].y / (orender.rotated_pos.z / object.scale);
	xend = orender.screen_pos.x + object.size[index].x / 2.0 / (orender.rotated_pos.z / object.scale);
	yend = (orender.screen_pos.y);
	x = xstart;
	while (x <= xend)
	{
		xalpha = (x - xstart) / (double)(xend - xstart);
		if (object.reversed[index])
			xalpha = 1.0 - xalpha;
		textx = (1.0 - xalpha) * object.start[index].x + xalpha * object.end[index].x;
		y = ystart;
		while (y <= yend)
		{
			yalpha = (y - ystart) / (double)(yend - ystart);
			texty = (1.0 - yalpha) * object.start[index].y + yalpha * object.end[index].y;
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
		{
			if (i == 1)
				draw_object(env->objects[i], env, render);
			env->objects[i].drawn = 1;
		}
		i++;
	}
}

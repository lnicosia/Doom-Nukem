/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_sprites.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/20 15:04:12 by lnicosia          #+#    #+#             */
/*   Updated: 2019/07/02 11:04:41 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "render.h"

static int	get_sprite_direction(t_object object)
{
	double	angle;

	angle = (atan2(object.translated_pos.z, object.translated_pos.x)) * CONVERT_DEGREES;
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
	t_sprite		sprite;
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
	double			light;
	t_texture		texture;

	(void)render;
	project_object(&orender, object, env);
	sprite = env->sprites[object.sprite];
	if (object.rotated_pos.z <= 1)
		return ;
	if (!sprite.oriented)
		index = 0;
	else
		index = get_sprite_direction(object);
	texture = env->textures[sprite.texture];
	xstart = orender.screen_pos.x - sprite.size[index].x / 2.0 / (object.rotated_pos.z / object.scale);
	ystart = orender.screen_pos.y - sprite.size[index].y / (object.rotated_pos.z / object.scale);
	xend = orender.screen_pos.x + sprite.size[index].x / 2.0 / (object.rotated_pos.z / object.scale);
	yend = (orender.screen_pos.y);
	light = 255 - ft_clamp(object.rotated_pos.z * 2, 0, 255);
	x = xstart;
	while (++x < xend)
	{
		if (object.rotated_pos.z >= env->depth_array[x])
			continue;
		xalpha = (x - xstart) / (double)(xend - xstart);
		if (sprite.reversed[index])
			xalpha = 1.0 - xalpha;
		textx = (1.0 - xalpha) * sprite.start[index].x + xalpha * sprite.end[index].x;
		y = ystart + 1;
		while (y < yend)
		{
			yalpha = (y - ystart) / (double)(yend - ystart);
			texty = (1.0 - yalpha) * sprite.start[index].y + yalpha * sprite.end[index].y;
			if (!(x >= env->w - 300 && x < env->w && y >= 0 && y <= 300) || !env->options.show_minimap)
				if (x >= 0 && x < env->w && y >= 0 && y < env->h
						&& texture.str[textx + texty * texture.surface->w] != 0xFFC10099)
				{
					if (!env->options.lighting)
						env->sdl.texture_pixels[x + y * env->w] = texture.str[textx + texty * texture.surface->w];
					else
						env->sdl.texture_pixels[x + y * env->w] = apply_light(texture.str[textx + texty * texture.surface->w], light);
				}
			y++;
		}
	}
}

static void	get_relative_pos(t_env *env)
{
	int	i;

	i = 0;
	while (i < env->nb_objects)
	{
		get_translated_object_pos(&env->objects[i], env);
		get_rotated_object_pos(&env->objects[i], env);
		//ft_printf("object z = %f\n", env->objects[i].rotated_pos.z);
		i++;
	}
}

static void	swap_objects(t_object *o1, t_object *o2)
{
	t_object	tmp;

	tmp = *o1;
	*o1 = *o2;
	*o2 = tmp;
}

static int	partition(t_object *objects, int start, int end)
{
	int	pivot;
	int	i;
	int	j;
	
	pivot = objects[end].rotated_pos.z;
	i = start - 1;
	j = start;
	while (j < end)
	{
		if (objects[j].rotated_pos.z > pivot)
		{
			i++;
			swap_objects(&objects[i], &objects[j]);
		}
		j++;
	}
	swap_objects(&objects[i + 1], &objects[end]);
	return (i + 1);
}

static void	sort_objects(t_object *objects, int start, int end)
{
	int	pi;

	if (start < end)
	{
		pi = partition(objects, start, end);
		sort_objects(objects, start, pi - 1);
		sort_objects(objects, pi + 1, end);
	}
}

void		draw_sprites(t_env *env, t_render *render)
{
	int	i;

	get_relative_pos(env);
	sort_objects(env->objects, 0, env->nb_objects - 1);
	i = 0;
	while (i < env->nb_objects)
	{
		draw_object(env->objects[i], env, render);
		i++;
	}
}

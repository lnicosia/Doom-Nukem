/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_sprites.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/20 15:04:12 by lnicosia          #+#    #+#             */
/*   Updated: 2019/07/30 15:00:37 by sipatry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
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

void		*object_loop(void *param)
{
	t_env			*env;
	t_object		object;
	t_render_object	orender;
	t_sprite		sprite;
	int				x;
	int				y;
	int				xend;
	int				yend;
	int				textx;
	int				texty;
	double			xalpha;
	double			yalpha;
	t_texture		texture;
	Uint32			*pixels;
	Uint32			*texture_pixels;
	double			*zbuffer;


	orender = ((t_object_thread*)param)->orender;
	env = ((t_object_thread*)param)->env;
	object = ((t_object_thread*)param)->object;
	sprite = env->sprites[object.sprite];
	texture = env->textures[sprite.texture];
	pixels = env->sdl.texture_pixels;
	texture_pixels = texture.str;
	zbuffer = env->depth_array;
	x = ((t_object_thread*)param)->xstart;
	xend = ((t_object_thread*)param)->xend;
	yend = orender.yend;
	while (++x <= xend)
	{
		xalpha = (x - orender.x1) / orender.xrange;
		if (sprite.reversed[orender.index])
			xalpha = 1.0 - xalpha;
		textx = (1.0 - xalpha) * sprite.start[orender.index].x + xalpha * sprite.end[orender.index].x;
		y = orender.ystart;
		while (y < yend)
		{
			yalpha = (y - orender.y1) / orender.yrange;
			texty = (1.0 - yalpha) * sprite.start[orender.index].y + yalpha * sprite.end[orender.index].y;
			if (object.rotated_pos.z < env->depth_array[x + y * env->w]
					&& texture_pixels[textx + texty * texture.surface->w] != 0xFFC10099)
			{
				if (!env->options.lighting)
					pixels[x + y * env->w] = texture_pixels[textx + texty * texture.surface->w];
				else
					pixels[x + y * env->w] = apply_light(texture_pixels[textx + texty * texture.surface->w], orender.light);
				zbuffer[x + y * env->w] = object.rotated_pos.z;
			}
			y++;
		}
	}
	return (NULL);
}

void		threaded_object_loop(t_object object, t_render_object orender, t_env *env)
{
	t_object_thread	ot[THREADS];
	pthread_t		threads[THREADS];
	int				i;

	i = 0;
	while (i < THREADS)
	{
		ot[i].env = env;
		ot[i].object = object;
		ot[i].orender = orender;
		ot[i].xstart = orender.xstart + (orender.xend - orender.xstart) / (double)THREADS * i;
		ot[i].xend = orender.xstart + (orender.xend - orender.xstart) / (double)THREADS * (i + 1);
		pthread_create(&threads[i], NULL, object_loop, &ot[i]);
		i++;
	}
	while (i-- > 0)
		pthread_join(threads[i], NULL);
}

void		draw_object(t_object *object, t_env *env)
{
	t_render_object	orender;
	t_sprite		sprite;

	sprite = env->sprites[object->sprite];
	project_object(&orender, *object, env);
	if (!sprite.oriented)
		orender.index = 0;
	else
		orender.index = get_sprite_direction(*object);
	orender.x1 = orender.screen_pos.x - sprite.size[orender.index].x / 2.0 / (object->rotated_pos.z / object->scale);
	orender.y1 = orender.screen_pos.y - sprite.size[orender.index].y / (object->rotated_pos.z / object->scale);
	orender.x2 = orender.screen_pos.x + sprite.size[orender.index].x / 2.0 / (object->rotated_pos.z / object->scale);
	orender.y2 = orender.screen_pos.y;
	orender.light = 255 - ft_clamp(object->rotated_pos.z * 2, 0, 255);
	orender.light = object->light;
	orender.xstart = ft_clamp(orender.x1, 0, env->w - 1);
	orender.ystart = ft_clamp(orender.y1 + 1, 0, env->h - 1);
	orender.xend = ft_clamp(orender.x2, 0, env->w - 1);
	orender.yend = ft_clamp(orender.y2, 0, env->h - 1);
	orender.xrange = orender.x2 - orender.x1;
	orender.yrange = orender.y2 - orender.y1;
	threaded_object_loop(*object, orender, env);
	if (env->depth_array[(orender.x1 + orender.x2) / 2 + env->w * ((orender.y1 + orender.y2) / 2)] == object->rotated_pos.z)
		object->seen = 1;
}

void	get_relative_pos(t_env *env)
{
	int	i;
	
	i = 0;
	while (i < env->nb_objects)
	{
		get_translated_object_pos(env, &env->objects[i]);
		get_rotated_object_pos(env, &env->objects[i]);
		i++;
	}
}

void	threaded_get_relative_pos(t_env *env)
{
	int				i;
	t_object_thread	object_threads[THREADS];
	pthread_t		threads[THREADS];

	env->current_object = 0;
	i = 0;
	while (i < THREADS)
	{
		object_threads[i].env = env;
		object_threads[i].xstart = env->nb_objects / (double)THREADS * i;
		object_threads[i].xend = env->nb_objects / (double)THREADS * (i + 1);
		//ft_printf("start = %d end = %d\n", object_threads[i].start, object_threads[i].end);
		pthread_create(&threads[i], NULL, get_object_relative_pos, &object_threads[i]);
		i++;
	}
	while (i-- > 0)
		pthread_join(threads[i], NULL);
}

/*static void	swap_objects(t_object *o1, t_object *o2)
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
}*/

void		draw_sprites(t_env *env)
{
	int	i;

	threaded_get_relative_pos(env);
	//get_relative_pos(env);
	//sort_objects(env->objects, 0, env->nb_objects - 1);
	i = 0;
	while (i < env->nb_objects)
	{
		if (env->objects[i].rotated_pos.z > 1)
			draw_object(&env->objects[i], env);
		i++;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_objects.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 13:36:47 by sipatry           #+#    #+#             */
/*   Updated: 2020/04/29 16:28:08 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

void	init_object_render(t_render_object *orender, t_object *object,
t_v2 size, t_env *env)
{
	orender->x1 = orender->screen_pos.x - size.y / 4;
	orender->x2 = orender->screen_pos.x + size.y / 4;
	orender->y1 = orender->screen_pos.y - size.x / 2;
	orender->y2 = orender->screen_pos.y;
	orender->light_color = object->light_color;
	orender->brightness = object->brightness;
	orender->intensity = object->intensity;
	orender->xstart = ft_clamp(orender->x1, 0, env->w - 1);
	orender->ystart = ft_clamp(orender->y1 + 1, 0, env->h - 1);
	orender->xend = ft_clamp(orender->x2, 0, env->w - 1);
	orender->yend = ft_clamp(orender->y2, 0, env->h - 1);
	object->left = orender->xstart;
	object->right = orender->xend;
	object->top = orender->ystart;
	object->bottom = orender->yend;
	orender->xrange = orender->x2 - orender->x1;
	orender->yrange = orender->y2 - orender->y1;
}

int		draw_object(t_camera *camera, t_object *object, t_env *env,
int death_sprite)
{
	t_render_object	orender;
	t_sprite		*sprite;
	t_v2			size;
	double			sprite_ratio;

	if (death_sprite >= 0)
		object->sprite = env->object_sprites[object->sprite].death_counterpart;
	sprite = &env->object_sprites[object->sprite];
	orender.camera = camera;
	project_object(&orender, object, env);
	if (sprite->oriented)
		orender.index = get_object_direction(object);
	else if (death_sprite >= 0)
		orender.index = death_sprite;
	else
		orender.index = 0;
	size.x = env->w * object->scale / object->rotated_pos.z;
	sprite_ratio = sprite->size[orender.index].x
	/ (double)sprite->size[orender.index].y;
	size.y = size.x * sprite_ratio;
	init_object_render(&orender, object, size, env);
	if (threaded_object_loop(object, &orender, env))
		return (-1);
	return (0);
}

int		threaded_get_relative_pos(t_camera *camera, t_env *env)
{
	int				i;
	t_object_thread	object_threads[MAX_PROC];

	env->current_object = 0;
	i = 0;
	while (i < env->nprocs)
	{
		object_threads[i].env = env;
		object_threads[i].camera = camera;
		object_threads[i].xstart = env->nb_objects / (double)env->nprocs * i;
		object_threads[i].xend = env->nb_objects
		/ (double)env->nprocs * (i + 1);
		if (tpool_work(&env->tpool, get_object_relative_pos,
			&object_threads[i]))
			return (-1);
		i++;
	}
	if (tpool_wait(&env->tpool))
		return (-1);
	return (0);
}

int		draw_current_object(t_camera *camera, int i, t_env *env)
{
	int	death_sprite;

	death_sprite = -1;
	if (env->objects[i].rotated_pos.z > 1 && env->objects[i].exists)
	{
		env->objects[i].seen = 0;
		if (!env->editor.in_game && env->objects[i].destructible == 1
			&& env->objects[i].health <= 0 && env->objects[i].exists)
		{
			if (env->object_sprites[env->objects[i].sprite].
				nb_death_sprites > 1)
				death_sprite = object_destruction(env, i,
				env->object_sprites[env->objects[i].sprite].
				nb_death_sprites);
			else
				env->objects[i].sprite = env->object_sprites[env->
				objects[i].sprite].death_counterpart;
		}
		if (env->objects[i].exists && env->objects[i].nb_rest_state > 1)
			object_anim_loop(env, i);
		if (env->objects[i].exists)
			if (draw_object(camera, &env->objects[i], env, death_sprite))
				return (-1);
	}
	return (0);
}

int		draw_objects(t_camera *camera, t_env *env)
{
	int	i;

	if (threaded_get_relative_pos(camera, env))
		return (-1);
	i = 0;
	while (i < env->nb_objects)
	{
		if (env->objects[i].sector != -1 && draw_current_object(camera, i, env))
			return (-1);
		i++;
	}
	return (0);
}

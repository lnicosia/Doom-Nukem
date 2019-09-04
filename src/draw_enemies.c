/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_enemies.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaerhard <gaerhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/20 15:04:12 by lnicosia          #+#    #+#             */
/*   Updated: 2019/09/04 15:15:53 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "render.h"

static int	get_sprite_direction(t_enemies enemy)
{
	double	angle;

	angle = (int)((atan2(enemy.translated_pos.z, enemy.translated_pos.x)) * CONVERT_DEGREES) % 360;
	if (angle >= enemy.angle - 22.5 && angle < enemy.angle + 22.5)
		return (4);
	else if (angle >= enemy.angle + 22.5 && angle < enemy.angle + 67.5)
		return (5);
	else if (angle >= enemy.angle + 67.5 && angle < enemy.angle + 112.5)
		return (6);
	else if (angle >= enemy.angle + 112.5 && angle < enemy.angle + 157.5)
		return (7);
	else if (angle >= enemy.angle + 157.5 && angle < enemy.angle + 202.5)
		return (0);
	else if (angle >= enemy.angle + 202.5 && angle < enemy.angle + 247.5)
		return (1);
	else if (angle >= enemy.angle + 247.5 && angle < enemy.angle + 292.5)
		return (2);
	else if (angle >= enemy.angle + 292.5 && angle < enemy.angle + 337.5)
		return (3);
	else if (angle >= enemy.angle + 337.5)
		return (0);
	else if (angle < enemy.angle - 22.5 && angle >= enemy.angle - 67.5)
		return (3);
	else if (angle < enemy.angle - 67.5 && angle >= enemy.angle - 112.5)
		return (2);
	else if (angle < enemy.angle - 112.5 && angle >= enemy.angle - 157.5)
		return (1);
	else if (angle < enemy.angle - 157.5 && angle >= enemy.angle - 202.5)
		return (0);
	else if (angle < enemy.angle - 202.5 && angle >= enemy.angle - 247.5)
		return (7);
	else if (angle < enemy.angle - 247.5 && angle >= enemy.angle - 292.5)
		return (6);
	else if (angle < enemy.angle - 292.5 && angle >= enemy.angle - 337.5)
		return (5);
	else if (angle < enemy.angle - 337.5)
		return (4);
	else
		return (0);
}

static void		*enemy_loop(void *param)
{
	t_env			*env;
	t_enemies		enemy;
	t_render_enemy	erender;
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


	erender = ((t_enemy_thread*)param)->erender;
	env = ((t_enemy_thread*)param)->env;
	enemy = ((t_enemy_thread*)param)->enemy;
	sprite = env->sprites[enemy.sprite];
	texture = env->textures[sprite.texture];
	pixels = env->sdl.texture_pixels;
	texture_pixels = texture.str;
	zbuffer = env->depth_array;
	x = ((t_enemy_thread*)param)->xstart;
	xend = ((t_enemy_thread*)param)->xend;
	yend = erender.yend;
	while (++x <= xend)
	{
		xalpha = (x - erender.x1) / erender.xrange;
		if (sprite.reversed[erender.index])
			xalpha = 1.0 - xalpha;
		textx = (1.0 - xalpha) * sprite.start[erender.index].x + xalpha * sprite.end[erender.index].x;
		y = erender.ystart;
		while (y < yend)
		{
			yalpha = (y - erender.y1) / erender.yrange;
			texty = (1.0 - yalpha) * sprite.start[erender.index].y + yalpha * sprite.end[erender.index].y;
			if ((enemy.rotated_pos.z < zbuffer[x + y * env->w]
					&& texture_pixels[textx + texty * texture.surface->w] != 0xFFC10099))
			{
				if (env->editor.select && x == env->h_w && y == env->h_h)
				{
					env->selected_wall1 = -1;
					env->selected_wall2 = -1;
					env->selected_floor = -1;
					env->selected_ceiling = -1;
					env->selected_object = -1;
					env->selected_enemy = enemy.num;
				}
				if (!env->options.lighting)
					pixels[x + y * env->w] = texture_pixels[textx + texty * texture.surface->w];
				else
					pixels[x + y * env->w] = apply_light(texture_pixels[textx + texty * texture.surface->w], erender.light);
				if (env->editor.in_game && !env->editor.select && env->selected_enemy == enemy.num)
					pixels[x + y * env->w] = blend_alpha(pixels[x + y * env->w], 0xFF00FF00, 128);
				zbuffer[x + y * env->w] = enemy.rotated_pos.z;
			}
			y++;
		}
	}
	return (NULL);
}

static void		threaded_enemy_loop(t_enemies enemy, t_render_enemy erender, t_env *env)
{
	t_enemy_thread	et[THREADS];
	pthread_t		threads[THREADS];
	int				i;

	i = 0;
	while (i < THREADS)
	{
		et[i].env = env;
		et[i].enemy = enemy;
		et[i].erender = erender;
		et[i].xstart = erender.xstart + (erender.xend - erender.xstart) / (double)THREADS * i;
		et[i].xend = erender.xstart + (erender.xend - erender.xstart) / (double)THREADS * (i + 1);
		pthread_create(&threads[i], NULL, enemy_loop, &et[i]);
		i++;
	}
	while (i-- > 0)
		pthread_join(threads[i], NULL);
}

static void		draw_enemy(t_enemies *enemy, t_env *env, int death_sprite)
{
	t_render_enemy	erender;
	t_sprite		sprite;

	if (death_sprite >= 0)
	{
		enemy->sprite = env->sprites[enemy->sprite].death_counterpart;
		sprite = env->sprites[enemy->sprite];
	}
	else
		sprite = env->sprites[enemy->sprite];
	project_enemy(&erender, *enemy, env);
	if (sprite.oriented)
		erender.index = get_sprite_direction(*enemy);
	else if (death_sprite >= 0)
		erender.index = death_sprite;
	else
		erender.index = 0;
	erender.x1 = erender.screen_pos.x - sprite.size[erender.index].x / 2.0 / (enemy->rotated_pos.z / enemy->scale);
	erender.y1 = erender.screen_pos.y - sprite.size[erender.index].y / (enemy->rotated_pos.z / enemy->scale);
	erender.x2 = erender.screen_pos.x + sprite.size[erender.index].x / 2.0 / (enemy->rotated_pos.z / enemy->scale);
	erender.y2 = erender.screen_pos.y;
	erender.light = 255 - ft_clamp(enemy->rotated_pos.z * 2, 0, 255);
	erender.light = enemy->light;
	erender.xstart = ft_clamp(erender.x1, 0, env->w - 1);
	erender.ystart = ft_clamp(erender.y1 + 1, 0, env->h - 1);
	erender.xend = ft_clamp(erender.x2, 0, env->w - 1);
	erender.yend = ft_clamp(erender.y2, 0, env->h - 1);
	enemy->left = erender.xstart;
	enemy->right = erender.xend;
	enemy->top = erender.ystart;
	enemy->bottom = erender.yend;
	erender.xrange = erender.x2 - erender.x1;
	erender.yrange = erender.y2 - erender.y1;
	threaded_enemy_loop(*enemy, erender, env);
	/*if (((orender.x1 + orender.x2) / 2) < env->w && ((orender.x1 + orender.x2) / 2) >= 0 && ((orender.y1 + orender.y2) / 2) < env->h && ((orender.y1 + orender.y2) / 2) >= 0)
		if (env->depth_array[(orender.x1 + orender.x2) / 2 + env->w * ((orender.y1 + orender.y2) / 2)] == object->rotated_pos.z)
			object->seen = 1;*/
}
/*
static void	get_relative_pos(t_env *env)
{
	int	i;
	
	i = 0;
	while (i < env->nb_enemies)
	{
		get_translated_enemy_pos(env, &env->enemies[i]);
		get_rotated_enemy_pos(env, &env->enemies[i]);
		i++;
	}
}*/

static void	threaded_get_relative_pos(t_env *env)
{
	int				i;
	t_enemy_thread	enemies_threads[THREADS];
	pthread_t		threads[THREADS];

	env->current_enemy = 0;
	i = 0;
	while (i < THREADS)
	{
		enemies_threads[i].env = env;
		enemies_threads[i].xstart = env->nb_enemies / (double)THREADS * i;
		enemies_threads[i].xend = env->nb_enemies / (double)THREADS * (i + 1);
		//ft_printf("start = %d end = %d\n", object_threads[i].start, object_threads[i].end);
		pthread_create(&threads[i], NULL, get_enemy_relative_pos, &enemies_threads[i]);
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

void		draw_enemies(t_env *env)
{
	int	i;

	threaded_get_relative_pos(env);
	//get_relative_pos(env);
	//sort_objects(env->objects, 0, env->nb_objects - 1);
	i = 0;
	while (i < env->nb_enemies)
	{
		if (env->enemies[i].rotated_pos.z > 1 && env->enemies[i].exists)
		{
			if (env->enemies[i].health <= 0)
				draw_enemy(&env->enemies[i], env, dying_enemy(env, i));
			else
				draw_enemy(&env->enemies[i], env, -1);
		}
		i++;
	}
}

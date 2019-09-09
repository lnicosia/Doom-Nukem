/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_enemies.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaerhard <gaerhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/20 15:04:12 by lnicosia          #+#    #+#             */
/*   Updated: 2019/09/09 16:52:24 by sipatry          ###   ########.fr       */
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


	orender = ((t_enemy_thread*)param)->orender;
	env = ((t_enemy_thread*)param)->env;
	enemy = ((t_enemy_thread*)param)->enemy;
	sprite = env->sprites[enemy.sprite];
	texture = env->textures[sprite.texture];
	pixels = env->sdl.texture_pixels;
	texture_pixels = texture.str;
	zbuffer = env->depth_array;
	x = ((t_enemy_thread*)param)->xstart;
	xend = ((t_enemy_thread*)param)->xend;
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
			if ((enemy.rotated_pos.z < zbuffer[x + y * env->w]
						&& texture_pixels[textx + texty * texture.surface->w] != 0xFFC10099))
			{
				env->enemies[enemy.num].seen = 1;
				if (env->editor.select && x == env->h_w && y == env->h_h)
				{
					env->selected_wall1 = -1;
					env->selected_wall2 = -1;
					env->selected_floor = -1;
					env->selected_ceiling = -1;
					env->selected_object = -1;
					env->selected_enemy = enemy.num;
					env->editor.selected_wall = -1;
				}
				if (!env->options.lighting)
					pixels[x + y * env->w] = texture_pixels[textx + texty * texture.surface->w];
				else
					pixels[x + y * env->w] = apply_light(texture_pixels[textx + texty * texture.surface->w], orender.light_color, orender.brightness);
				if (env->enemies[enemy.num].hit)
					pixels[x + y * env->w] = blend_alpha(pixels[x + y * env->w], 0xFFFF0000, enemy_hurt(env, enemy.num));
				if (env->editor.in_game && !env->editor.select && env->selected_enemy == enemy.num)
					pixels[x + y * env->w] = blend_alpha(pixels[x + y * env->w], 0xFF00FF00, 128);
				zbuffer[x + y * env->w] = enemy.rotated_pos.z;
			}
			y++;
		}
	}
	return (NULL);
}

static void		threaded_enemy_loop(t_enemies enemy, t_render_object orender, t_env *env)
{
	t_enemy_thread	et[THREADS];
	pthread_t		threads[THREADS];
	int				i;

	i = 0;
	while (i < THREADS)
	{
		et[i].env = env;
		et[i].enemy = enemy;
		et[i].orender = orender;
		et[i].xstart = orender.xstart + (orender.xend - orender.xstart) / (double)THREADS * i;
		et[i].xend = orender.xstart + (orender.xend - orender.xstart) / (double)THREADS * (i + 1);
		pthread_create(&threads[i], NULL, enemy_loop, &et[i]);
		i++;
	}
	while (i-- > 0)
		pthread_join(threads[i], NULL);
}

static void		draw_enemy(t_enemies *enemy, t_env *env, int death_sprite)
{
	t_render_object	orender;
	t_sprite		sprite;

	if (death_sprite >= 0)
		enemy->sprite = env->sprites[enemy->sprite].death_counterpart;
	sprite = env->sprites[enemy->sprite];	
	project_enemy(&orender, *enemy, env);
	if (sprite.oriented)
		orender.index = get_sprite_direction(*enemy);
	else if (death_sprite >= 0)
		orender.index = death_sprite;
	else
		orender.index = 0;
	orender.x1 = orender.screen_pos.x - sprite.size[orender.index].x / 2.0 / (enemy->rotated_pos.z / enemy->scale);
	orender.y1 = orender.screen_pos.y - sprite.size[orender.index].y / (enemy->rotated_pos.z / enemy->scale);
	orender.x2 = orender.screen_pos.x + sprite.size[orender.index].x / 2.0 / (enemy->rotated_pos.z / enemy->scale);
	orender.y2 = orender.screen_pos.y;
	orender.light_color = enemy->light_color;
	orender.brightness = enemy->brightness;
	orender.xstart = ft_clamp(orender.x1, 0, env->w - 1);
	orender.ystart = ft_clamp(orender.y1 + 1, 0, env->h - 1);
	orender.xend = ft_clamp(orender.x2, 0, env->w - 1);
	orender.yend = ft_clamp(orender.y2, 0, env->h - 1);
	enemy->left = orender.xstart;
	enemy->right = orender.xend;
	enemy->top = orender.ystart;
	enemy->bottom = orender.yend;
	orender.xrange = orender.x2 - orender.x1;
	orender.yrange = orender.y2 - orender.y1;
	threaded_enemy_loop(*enemy, orender, env);
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
	int dying_sprite;

	threaded_get_relative_pos(env);
	//get_relative_pos(env);
	//sort_objects(env->objects, 0, env->nb_objects - 1);
	i = 0;
	while (i < env->nb_enemies)
	{
		dying_sprite = -1;
		if (env->enemies[i].rotated_pos.z > 1 && env->enemies[i].exists)
		{
			env->enemies[i].seen = 0;
			if (!env->editor.in_game)
			{
				if (env->enemies[i].health <= 0)
					dying_sprite = dying_enemy(env, i, env->sprites[env->enemies[i].sprite].nb_death_sprites);
				resting_enemy(env, i);
			}
			if (env->enemies[i].exists)
				draw_enemy(&env->enemies[i], env, dying_sprite);
		}
		i++;
	}
}

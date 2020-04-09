/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/08 18:15:21 by lnicosia          #+#    #+#             */
/*   Updated: 2020/03/09 15:34:39 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "render.h"

void	draw_vline_player(t_render_object *orender, t_sprite_drawer *drawer,
t_env *env)
{
	drawer->yalpha = (drawer->y - orender->y1) / orender->yrange;
	drawer->texty = (1.0 - drawer->yalpha)
	* drawer->sprite->start[orender->index].y + drawer->yalpha
	* drawer->sprite->end[orender->index].y;
	if ((drawer->object->rotated_pos.z < env->zbuffer[drawer->x
	  + drawer->y * env->w]	&& drawer->texture->str[drawer->textx
	+ drawer->texty * drawer->texture->surface->w] != 0xFFC10099))
	{
		if ((env->editor.select == 1 && drawer->x == env->sdl.mx
			&& drawer->y == env->sdl.my)
			|| (!env->editor.tab && env->editor.select == 1
			&& drawer->x == env->h_w && drawer->y == env->h_h))
		{
			reset_selection(env);
			env->editor.selected_start_player = 1;
			tabs_gestion(env);
		}
		put_object_pixel(orender, drawer, env);
	}
}

void	*player_loop(void *param)
{
	t_env			*env;
	t_render_object	*orender;
	t_sprite_drawer	drawer;

	orender = ((t_object_thread*)param)->orender;
	env = ((t_object_thread*)param)->env;
	drawer.object = ((t_object_thread*)param)->object;
	drawer.sprite = &env->object_sprites[drawer.object->sprite];
	drawer.texture = &env->sprite_textures[drawer.sprite->texture];
	drawer.x = ((t_object_thread*)param)->xstart;
	drawer.xend = ((t_object_thread*)param)->xend;
	drawer.yend = orender->yend;
	drawer.sector = &env->sectors[drawer.object->sector];
	while (++drawer.x <= drawer.xend)
	{
	  	get_sprite_x(orender, &drawer);
		while (drawer.y < drawer.yend)
		{
		  	draw_vline_player(orender, &drawer, env);
			drawer.y++;
		}
	}
	return (NULL);
}

static int	threaded_player_loop(t_object *object, t_render_object *orender,
		t_env *env)
{
	t_object_thread	et[THREADS];
	pthread_t		threads[THREADS];
	int				i;

	i = 0;
	while (i < THREADS)
	{
		et[i].env = env;
		et[i].object = object;
		et[i].orender = orender;
		et[i].xstart = orender->xstart + (orender->xend - orender->xstart)
			/ (double)THREADS * i;
		et[i].xend = orender->xstart + (orender->xend - orender->xstart)
			/ (double)THREADS * (i + 1);
		if (pthread_create(&threads[i], NULL, player_loop, &et[i]))
			return (-1);
		i++;
	}
	while (i-- > 0)
		if (pthread_join(threads[i], NULL))
			return (-1);
	return (0);
}

int			draw_player_as_object(t_camera *camera, t_object *object,
t_env *env)
{
	t_render_object	orender;
	t_sprite		*sprite;
	t_v2			size;
	double			sprite_ratio;

	orender.camera = camera;
	sprite = &env->object_sprites[object->sprite];
	project_object(&orender, object, env);
	if (sprite->oriented)
		orender.index = get_object_direction(object);
	else
		orender.index = 0;
	size.x = env->w * object->scale / object->rotated_pos.z;
	sprite_ratio = sprite->size[orender.index].x
		/ (double)sprite->size[orender.index].y;
	size.y = size.x * sprite_ratio;
	init_object_render(&orender, object, size, env);
	if (threaded_player_loop(object, &orender, env))
		return (-1);
	return (0);
}

int			draw_player(t_camera *camera, t_v3 pos, t_env *env)
{
	t_object	player;

	ft_bzero(&player, sizeof(player));
	player.pos = pos;
	player.sprite = DOOM_GUY;
	player.scale = 7;
	player.sector = get_sector_no_z(env, player.pos);
	if (player.sector != -1)
	{
		player.light_color = env->sectors[player.sector].light_color;
		player.brightness = env->sectors[player.sector].brightness;
		player.intensity = env->sectors[player.sector].intensity;
	}
	else
	{
		player.light_color = 0;
		player.brightness = 0;
		player.intensity = 0;
	}
	player.angle = env->player.init_data.camera.angle;
	get_translated_object_pos(camera, &player);
	get_rotated_object_pos(camera, &player);
	if (draw_player_as_object(camera, &player, env))
		return (-1);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/08 18:15:21 by lnicosia          #+#    #+#             */
/*   Updated: 2020/03/04 14:33:09 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "render.h"

static int      get_sprite_direction(t_object object)
{
	double  angle;

	angle = (int)((atan2(object.translated_pos.z, object.translated_pos.x)) * CONVERT_DEGREES) % 360;
	if (angle < 0)
		angle += 360;
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
		return (4);
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

static void		*player_loop(void *param)
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
	t_sector		sector;

	orender = ((t_object_thread*)param)->orender;
	env = ((t_object_thread*)param)->env;
	object = ((t_object_thread*)param)->object;
	sprite = env->object_sprites[object.sprite];
	texture = env->sprite_textures[sprite.texture];
	pixels = env->sdl.texture_pixels;
	texture_pixels = texture.str;
	zbuffer = env->zbuffer;
	x = ((t_object_thread*)param)->xstart;
	xend = ((t_object_thread*)param)->xend;
	yend = orender.yend;
	sector = env->sectors[object.sector];
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
			if ((object.rotated_pos.z < zbuffer[x + y * env->w]
						&& texture_pixels[textx
						+ texty * texture.surface->w] != 0xFFC10099))
			{
				if ((env->editor.select == 1 && x == env->sdl.mx
					&& y == env->sdl.my)
					|| (!env->editor.tab && env->editor.select == 1
					&& x == env->h_w && y == env->h_h))
				{
					reset_selection(env);
					env->editor.selected_start_player = 1;
					tabs_gestion(env);
				}
				if (!env->options.lighting
						|| (!sector.brightness && !sector.intensity))
					pixels[x + y * env->w] = texture_pixels[textx
						+ texty * texture.surface->w];
				else if (!sector.brightness)
					pixels[x + y * env->w] = apply_light_color(
							texture_pixels[textx + texty * texture.surface->w],
							orender.light_color, orender.intensity);
				else if (!sector.intensity)
					pixels[x + y * env->w] = apply_light_brightness(
							texture_pixels[textx + texty * texture.surface->w],
							orender.brightness);
				else
					pixels[x + y * env->w] = apply_light_both(
							texture_pixels[textx + texty * texture.surface->w],
							orender.light_color, orender.intensity, orender.brightness);
				if (!env->editor.select
						&& env->editor.selected_start_player == 1)
					pixels[x + y * env->w] =
						blend_alpha(pixels[x + y * env->w], 0x1abc9c, 128);
				zbuffer[x + y * env->w] = object.rotated_pos.z;
			}
			y++;
		}
	}
	return (NULL);
}

static int	threaded_player_loop(t_object object, t_render_object orender,
		t_env *env)
{
	t_object_thread  et[THREADS];
	pthread_t               threads[THREADS];
	int                             i;

	i = 0;
	while (i < THREADS)
	{
		et[i].env = env;
		et[i].object = object;
		et[i].orender = orender;
		et[i].xstart = orender.xstart + (orender.xend - orender.xstart)
			/ (double)THREADS * i;
		et[i].xend = orender.xstart + (orender.xend - orender.xstart)
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

int			draw_player_as_object(t_camera camera, t_object *object,
t_env *env)
{
	t_render_object	orender;
	t_sprite		sprite;
	t_v2			size;
	double			sprite_ratio;

	orender.camera = camera;
	sprite = env->object_sprites[object->sprite];
	project_object(&orender, *object, env);
	if (sprite.oriented)
		orender.index = get_sprite_direction(*object);
	else
		orender.index = 0;
	size.x = env->w * object->scale / object->rotated_pos.z;
	sprite_ratio = sprite.size[orender.index].x
		/ (double)sprite.size[orender.index].y;
	size.y = size.x * sprite_ratio;
	orender.x1 = orender.screen_pos.x - size.y / 4;
	orender.x2 = orender.screen_pos.x + size.y / 4;
	orender.y1 = orender.screen_pos.y - size.x / 2;
	orender.y2 = orender.screen_pos.y;
	orender.light_color = object->light_color;
	orender.brightness = object->brightness;
	orender.intensity = object->intensity;
	orender.xstart = ft_clamp(orender.x1, 0, env->w - 1);
	orender.ystart = ft_clamp(orender.y1 + 1, 0, env->h - 1);
	orender.xend = ft_clamp(orender.x2 - 1, 0, env->w - 1);
	orender.yend = ft_clamp(orender.y2, 0, env->h - 1);
	object->left = orender.xstart;
	object->right = orender.xend;
	object->top = orender.ystart;
	object->bottom = orender.yend;
	orender.xrange = orender.x2 - orender.x1;
	orender.yrange = orender.y2 - orender.y1;
	if (threaded_player_loop(*object, orender, env))
		return (-1);
	return (0);
}

int			draw_player(t_camera camera, t_v3 pos, t_env *env)
{
	t_object	player;

	//	if (camera.pos.x == env->player.pos.x && camera.pos.y == env->player.pos.y
	//			&& camera.pos.z == env->player.head_z)
	//		return (0);
	ft_bzero(&player, sizeof(player));
	player.pos = pos;
	player.sprite = DOOM_GUY;
	player.scale = 7;
	player.sector = get_sector_global(env, player.pos);
	player.light_color = env->sectors[player.sector].light_color;
	player.brightness = env->sectors[player.sector].brightness;
	player.intensity = env->sectors[player.sector].intensity;
	player.angle = env->player.init_data.camera.angle;
	get_translated_object_pos(camera, &player);
	get_rotated_object_pos(camera, &player);
	if (draw_player_as_object(camera, &player, env))
		return (-1);
	return (0);
}

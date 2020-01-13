/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_projectile_color.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipatry <sipatry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 17:24:44 by gaerhard          #+#    #+#             */
/*   Updated: 2020/01/08 17:58:25 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "render.h"

static void		*projectile_loop_color(void *param)
{
	t_env				*env;
	t_projectile		projectile;
	t_render_projectile	prender;
	t_sprite			sprite;
	int					x;
	int					y;
	int					xend;
	int					yend;
	int					textx;
	int					texty;
	double				xalpha;
	double				yalpha;
	t_texture			texture;
	Uint32				*pixels;
	Uint32				*texture_pixels;
	double				*zbuffer;

	prender = ((t_projectile_thread*)param)->prender;
	env = ((t_projectile_thread*)param)->env;
	projectile = ((t_projectile_thread*)param)->projectile;
	sprite = env->object_sprites[projectile.sprite];
	texture = env->sprite_textures[sprite.texture];
	pixels = env->sdl.texture_pixels;
	texture_pixels = texture.str;
	zbuffer = env->zbuffer;
	x = ((t_projectile_thread*)param)->xstart;
	xend = ((t_projectile_thread*)param)->xend;
	yend = prender.yend;
	while (++x <= xend)
	{
		xalpha = (x - prender.x1) / prender.xrange;
		if (sprite.reversed[prender.index])
			xalpha = 1.0 - xalpha;
		textx = (1.0 - xalpha) * sprite.start[prender.index].x + xalpha * sprite.end[prender.index].x;
		y = prender.ystart;
		while (y < yend)
		{
			yalpha = (y - prender.y1) / prender.yrange;
			texty = (1.0 - yalpha) * sprite.start[prender.index].y + yalpha * sprite.end[prender.index].y;
			if ((projectile.rotated_pos.z < zbuffer[x + y * env->w]
						&& texture_pixels[textx + texty * texture.surface->w] != 0xFFC10099))
			{
				pixels[x + y * env->w] = apply_light_color(
					texture_pixels[textx + texty * texture.surface->w],
					prender.light_color, prender.intensity);
				zbuffer[x + y * env->w] = projectile.rotated_pos.z;
			}
			y++;
		}
	}
	return (NULL);
}

static int	threaded_projectile_loop_color(t_projectile projectile,
t_render_projectile prender, t_env *env)
{
	t_projectile_thread	pt[THREADS];
	pthread_t			threads[THREADS];
	int					i;

	i = 0;
	while (i < THREADS)
	{
		pt[i].env = env;
		pt[i].projectile = projectile;
		pt[i].prender = prender;
		pt[i].xstart = prender.xstart + (prender.xend - prender.xstart) / (double)THREADS * i;
		pt[i].xend = prender.xstart + (prender.xend - prender.xstart) / (double)THREADS * (i + 1);
		if (pthread_create(&threads[i], NULL, projectile_loop_color, &pt[i]))
			return (-1);
		i++;
	}
	while (i-- > 0)
		if (pthread_join(threads[i], NULL))
			return (-1);
	return (0);
}

int			draw_projectile_color(t_camera camera, t_projectile *projectile,
t_env *env)
{
	t_render_projectile	prender;
	t_sprite			sprite;
	t_v2				size;
	double				sprite_ratio;

	sprite = env->object_sprites[projectile->sprite];
	prender.camera = camera;
	project_projectile(&prender, *projectile, env);
	prender.index = 0;
	if (sprite.oriented)
		prender.index = get_sprite_direction_projectile(*projectile);
	size.x = env->w * projectile->scale / projectile->rotated_pos.z;
	sprite_ratio = sprite.size[prender.index].x
		/ (double)sprite.size[prender.index].y;
	size.y = size.x * sprite_ratio;
	prender.x1 = prender.screen_pos.x - size.y / 4;
	prender.x2 = prender.screen_pos.x + size.y / 4;
	prender.y1 = prender.screen_pos.y - size.x / 2;
	prender.y2 = prender.screen_pos.y;
	prender.light_color = projectile->light_color;
	prender.brightness = projectile->brightness;
	prender.intensity = projectile->intensity;
	prender.xstart = ft_clamp(prender.x1, 0, env->w - 1);
	prender.ystart = ft_clamp(prender.y1 + 1, 0, env->h - 1);
	prender.xend = ft_clamp(prender.x2, 0, env->w - 1);
	prender.yend = ft_clamp(prender.y2, 0, env->h - 1);
	projectile->left = prender.xstart;
	projectile->right = prender.xend;
	projectile->top = prender.ystart;
	projectile->bottom = prender.yend;
	prender.xrange = prender.x2 - prender.x1;
	prender.yrange = prender.y2 - prender.y1;
	if (threaded_projectile_loop_color(*projectile, prender, env))
		return (-1);
	return (0);
}

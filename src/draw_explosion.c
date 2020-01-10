/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_explosion.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaerhard <gaerhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 17:24:44 by gaerhard          #+#    #+#             */
/*   Updated: 2020/01/09 15:32:15 by gaerhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "render.h"

static void		*explosion_loop(void *param)
{
	t_env				*env;
	t_explosion			explosion;
	t_render_explosion	erender;
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

	erender = ((t_explosion_thread*)param)->erender;
	env = ((t_explosion_thread*)param)->env;
	explosion = ((t_explosion_thread*)param)->explosion;
	sprite = env->object_sprites[explosion.sprite];
	texture = env->sprite_textures[sprite.texture];
	pixels = env->sdl.texture_pixels;
	texture_pixels = texture.str;
	zbuffer = env->zbuffer;
	x = ((t_explosion_thread*)param)->xstart;
	xend = ((t_explosion_thread*)param)->xend;
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
			if ((explosion.rotated_pos.z < zbuffer[x + y * env->w]
						&& texture_pixels[textx + texty * texture.surface->w] != 0xFFC10099))
			{
				pixels[x + y * env->w] = texture_pixels[textx + texty * texture.surface->w];
				zbuffer[x + y * env->w] = explosion.rotated_pos.z;
			}
			y++;
		}
	}
	return (NULL);
}

static void		threaded_explosion(t_explosion projectile, t_render_explosion erender, t_env *env)
{
	t_explosion_thread	pt[THREADS];
	pthread_t			threads[THREADS];
	int					i;

	i = 0;
	while (i < THREADS)
	{
		pt[i].env = env;
		pt[i].explosion = explosion;
		pt[i].erender = erender;
		pt[i].xstart = erender.xstart + (erender.xend - erender.xstart) / (double)THREADS * i;
		pt[i].xend = erender.xstart + (erender.xend - erender.xstart) / (double)THREADS * (i + 1);
		pthread_create(&threads[i], NULL, explosion_loop, &pt[i]);
		i++;
	}
	while (i-- > 0)
		pthread_join(threads[i], NULL);
}

void		draw_explosion(t_camera camera, t_explosion *explosion,
t_env *env)
{
	t_render_explosion	erender;
	t_sprite			sprite;
	t_v2				size;
	double				sprite_ratio;

	sprite = env->object_sprites[explosion->sprite];
	erender.camera = camera;
	project_explosion(&erender, *explosion, env);
	erender.index = 0;
	if (sprite.oriented)
		erender.index = get_sprite_direction_explosion(*explosion);
	size.x = env->w * explosion->scale / explosion->rotated_pos.z;
	sprite_ratio = sprite.size[erender.index].x
		/ (double)sprite.size[erender.index].y;
	size.y = size.x * sprite_ratio;
	erender.x1 = erender.screen_pos.x - size.y / 4;
	erender.x2 = erender.screen_pos.x + size.y / 4;
	erender.y1 = erender.screen_pos.y - size.x / 2;
	erender.y2 = erender.screen_pos.y;
	erender.light_color = explosion->light_color;
	erender.brightness = explosion->brightness;
	erender.intensity = explosion->intensity;
	erender.xstart = ft_clamp(erender.x1, 0, env->w - 1);
	erender.ystart = ft_clamp(erender.y1 + 1, 0, env->h - 1);
	erender.xend = ft_clamp(erender.x2, 0, env->w - 1);
	erender.yend = ft_clamp(erender.y2, 0, env->h - 1);
	explosion->left = erender.xstart;
	explosion->right = erender.xend;
	explosion->top = erender.ystart;
	explosion->bottom = erender.yend;
	erender.xrange = erender.x2 - erender.x1;
	erender.yrange = erender.y2 - erender.y1;
	threaded_projectile_loop(*explosion, erender, env);
}

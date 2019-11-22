/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_ceiling_sprites.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 10:12:52 by lnicosia          #+#    #+#             */
/*   Updated: 2019/11/21 17:24:08 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "render.h"

void	draw_ceiling_sprites(t_sector sector, t_render render, t_env *env)
{
	int			j;
	int			i;
	int			end;
	double		alpha;
	double		divider;
	double		z;
	double		y;
	double		x;
	double		sprite_x;
	double		sprite_y;
	t_sprite	sprite;
	Uint32*		sprite_pixels;
	Uint32*		pixels;
	int			coord;

	i = env->ymin[render.x];
	end = ft_min(render.current_ceiling, env->ymax[render.x]);
	pixels = env->sdl.texture_pixels;
	while (i <= end)
	{
		coord = render.x + env->w * i;
		// Opti ce truc
		alpha = (render.max_ceiling - i) / render.ceiling_height;
		divider = 1 / (render.camera->near_z + alpha * render.zrange);
		z = render.z_near_z * divider;
		if (z >= env->zbuffer[coord])
		{
			i++;
			continue;
		}
		y = (render.texel_y_near_z + alpha * render.texel_y_camera_range)
			* divider;
		x = (render.texel_x_near_z + alpha * render.texel_x_camera_range)
			* divider;
		j = 0;
		while (j < sector.nb_ceiling_sprites)
		{
			if (sector.ceiling_sprites.sprite[j] != -1)
			{
				sprite = env->wall_sprites[sector.ceiling_sprites.sprite[j]];
				sprite_pixels = (Uint32*)env->textures[sprite.texture].str;
				sprite_x = (x - sector.ceiling_sprites.pos[j].x)
					* (sprite.size[0].x) / sector.ceiling_sprites.scale[j].x;
				sprite_y = (y - sector.ceiling_sprites.pos[j].y)
					* (sprite.size[0].y) / sector.ceiling_sprites.scale[j].y;
				if (sprite_x >= sprite.start[0].x && sprite_x < sprite.end[0].x
						&& sprite_y >= sprite.start[0].y && sprite_y < sprite.end[0].y
						&& sprite_pixels[(int)sprite_x
						+ env->textures[sprite.texture].surface->w
						* (int)sprite_y] != 0xFFC10099)
				{
					pixels[coord] = apply_light(sprite_pixels[(int)sprite_x + env->textures[sprite.texture].surface->w * (int)sprite_y], sector.light_color, sector.brightness);
					env->zbuffer[coord] = z;
					break;
				}
			}
			j++;
		}
		i++;
	}
	(void)render;
	(void)sector;
	(void)env;
}

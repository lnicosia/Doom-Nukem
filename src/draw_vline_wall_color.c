/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_vline_wall_color.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipatry <sipatry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 17:44:32 by lnicosia          #+#    #+#             */
/*   Updated: 2020/03/11 14:02:27 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

/*
 **	Draw a vertical vline on the screen at vline.x
 */

void	draw_vline_wall_color(t_sector *sector, t_vline vline,
t_render *render, t_env *env)
{
	int			i;
	double		yalpha;
	double		y;
	double		x;
	Uint32		*pixels;
	Uint32		*texture_pixels;
	double		*zbuffer;
	int			coord;

	pixels = env->sdl.texture_pixels;
	if (env->options.mipmapping)
	{
		//ft_printf("{cyan}[WALL]{reset}\n");
		render->map_lvl = get_current_wall_map(render->texture, render->z,
		render, env);
	}
	texture_pixels = env->wall_textures[render->texture].maps[render->map_lvl]->pixels;
	zbuffer = env->zbuffer;
	yalpha = 0;
	coord = 0;
	x = 0;
	y = 0;
	/*y = render->alpha
		* render->camera->v[render->sector][render->i].texture_scale.x * render->z
		+ sector->align[render->i].x;
	if (y != y)
		return ;
	while (y >= render->texture_h)
		y -= render->texture_h;
	while (y < 0)
		y += render->texture_h;
	y = ft_fclamp(y, 0, render->texture_h);*/
	x = render->alpha
		* render->camera->v[render->sector][render->i]
		.texture_scale[render->map_lvl].x * render->z
		- render->camera->v[render->sector][render->i]
		.texture_align[render->map_lvl].x;
	if (x != x)
		return ;
	/*while (x >= render->texture_w)
		x -= render->texture_w;
	while (x < 0)
		x += render->texture_w;*/
	if (x >= render->texture_w || x < 0)
		x = ft_abs((int)x % render->texture_w);
	x = ft_fclamp(x, 0, render->texture_w);
	i = vline.start;
	//ft_printf("map lvl = %d\n", render->map_lvl);
	//ft_printf("texture_w = %d\n", render->texture_w);
	//ft_printf("texture_h = %d\n", render->texture_h);
	//ft_printf("first pixel = 0x%X\n", texture_pixels[0]);
	//ft_printf("x = %d\n", (int)x);
	while (i < vline.end)
	{
		coord = vline.x + env->w * i;
		if (render->z >= zbuffer[coord])
		{
			i++;
			continue;
		}
		yalpha = (i - render->no_slope_current_ceiling) / render->line_height;
		if ((env->editor.tab && vline.x == env->sdl.mx && i == env->sdl.my)
		|| (!env->editor.tab && vline.x == env->h_w && i == env->h_h))
		{
			if (env->editor.select)
			{
				reset_selection(env);
				env->editor.selected_sector = sector->num;
				env->editor.selected_wall = render->i;
				env->selected_wall1
				= env->sectors[render->sector].vertices[render->i];
				env->selected_wall2
				= env->sectors[render->sector].vertices[render->i + 1];
				tabs_gestion(env);				
				env->editor.just_selected = 1;
			}
			if (env->shooting
				&& render->z <= env->weapons[env->player.curr_weapon].range)
			{
				env->new_wall_bullet_hole = 1;
				env->new_bullet_hole_pos =
				new_v2(((render->alpha / render->camera->v[sector->num]
				[render->i + 1].vz) / ((1 - render->alpha) / render->
				camera->v[sector->num][render->i].vz + render->alpha / render->
				camera->v[sector->num][render->i + 1].vz)) * sector->
				wall_width[render->i], yalpha * (sector->ceiling - sector->floor));
				env->new_bullet_hole_sector = sector->num;
				env->new_bullet_hole_wall = render->i;
			}
			if (env->playing)
			{
				env->hovered_wall_sprite_wall = -1;
				env->hovered_wall_sprite_sprite = -1;
				env->hovered_wall_sprite_sector = -1;
			}
		}
		/*x = yalpha * render->camera->v[render->sector][render->i].texture_scale.y
			+ sector->align[render->i].y;
		while (x >= render->texture_w)
			x -= render->texture_w;
		while (x < 0)
			x += render->texture_w;*/
		y = yalpha * render->camera->v[render->sector][render->i]
		.texture_scale[render->map_lvl].y
		- render->camera->v[render->sector][render->i]
		.texture_align[render->map_lvl].y;
		/*while (y >= render->texture_h)
			y -= render->texture_h;
		while (y < 0)
			y += render->texture_h;*/
		if (y >= render->texture_h || y < 0)
			y = ft_abs((int)y % render->texture_h);
		//ft_printf("y = %d\n", (int)y);
			pixels[coord] = apply_light_color(texture_pixels[(int)x
			+ render->texture_w * (int)y], sector->light_color, sector->intensity);
		if (env->editor.in_game && sector->selected[render->i]
			&& !env->editor.select && !env->editor.select_portal)
			pixels[coord] = blend_alpha(pixels[coord], 0x1ABC9C, 128);
		zbuffer[coord] = render->z;
		i++;
	}
}

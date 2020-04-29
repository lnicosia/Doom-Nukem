/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_floor_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/29 16:19:19 by lnicosia          #+#    #+#             */
/*   Updated: 2020/04/29 16:19:19 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

void	get_floor_z(t_render *render, t_drawer *drawer, t_env *env)
{
	drawer->coord = render->x + env->w * drawer->i;
	drawer->alpha = (drawer->i - render->max_floor) / render->floor_height;
	drawer->divider = 1 / (render->camera->near_z + drawer->alpha
	* render->zrange);
	drawer->z = render->z_near_z * drawer->divider;
}

void	click_on_floor(t_drawer *drawer, t_render *render, t_env *env)
{
	if ((env->editor.tab && drawer->vline.x == env->sdl.mx
		&& drawer->i == env->sdl.my) || (!env->editor.tab
		&& drawer->vline.x == env->h_w && drawer->i == env->h_h))
	{
		if (env->editor.select)
		{
			reset_selection(env);
			env->selected_floor = render->sector->num;
			tabs_gestion(env);
		}
		if (env->shooting
			&& drawer->z <= env->weapons[env->player.curr_weapon].range)
		{
			env->new_floor_bullet_hole = 1;
			env->new_bullet_hole_pos =
			new_v2(drawer->x, drawer->y);
			env->new_bullet_hole_sector = drawer->sector->num;
		}
		if (env->playing)
			reset_hover(env);
	}
}

void	get_floor_texels(t_drawer *drawer, t_render *render, t_env *env)
{
	if (env->options.mipmapping)
		drawer->map_lvl = get_current_floor_map(
		drawer->sector->floor_texture, drawer->z, render, env);
	drawer->y = (render->texel_y_near_z + drawer->alpha
	* render->texel_y_camera_range) * drawer->divider;
	drawer->x = (render->texel_x_near_z + drawer->alpha
	* render->texel_x_camera_range) * drawer->divider;
	drawer->text_y =
	drawer->y * drawer->sector->floor_scale[drawer->map_lvl].y
	+ drawer->sector->floor_align[drawer->map_lvl].y;
	drawer->text_x =
	drawer->x * drawer->sector->floor_scale[drawer->map_lvl].x
	+ drawer->sector->floor_align[drawer->map_lvl].x;
	drawer->text_y = render->texture_h - drawer->text_y;
	drawer->text_x = render->texture_w - drawer->text_x;
	if (drawer->text_y >= render->texture_h || drawer->text_y < 0)
		drawer->text_y = ft_abs((int)drawer->text_y % render->texture_h);
	if (drawer->text_x >= render->texture_w || drawer->text_x < 0)
		drawer->text_x = ft_abs((int)drawer->text_x % render->texture_w);
}

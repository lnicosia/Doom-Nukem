/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_skybox.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 14:30:19 by lnicosia          #+#    #+#             */
/*   Updated: 2019/09/09 13:49:25 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "render.h"

/*
**	Check if the skybox current wall is in the player FOV
*/

void	get_render_intersections(t_render *skybox, t_env *env)
{
	skybox->inter_left = get_intersection(
			new_v2(skybox->vx1, skybox->vz1),
			new_v2(skybox->vx2, skybox->vz2),
			new_v2(env->camera.near_left, env->camera.near_z),
			new_v2(env->camera.far_left, env->camera.far_z));
	skybox->inter_right = get_intersection(
			new_v2(skybox->vx1, skybox->vz1),
			new_v2(skybox->vx2, skybox->vz2),
			new_v2(env->camera.near_right, env->camera.near_z),
			new_v2(env->camera.far_right, env->camera.far_z));
	skybox->inter_near = get_intersection(
			new_v2(skybox->vx1, skybox->vz1),
			new_v2(skybox->vx2, skybox->vz2),
			new_v2(env->camera.near_left, env->camera.near_z),
			new_v2(env->camera.near_right, env->camera.near_z));
	skybox->inter_far = get_intersection(
			new_v2(skybox->vx1, skybox->vz1),
			new_v2(skybox->vx2, skybox->vz2),
			new_v2(env->camera.far_left, env->camera.far_z),
			new_v2(env->camera.far_right, env->camera.far_z));
}

/*
**	Check if the skybox current wall is in the player FOV
*/

int		clip_skybox(t_render *skybox, t_env *env)
{
	if ((skybox->vz1 < env->camera.near_z && skybox->vz2 < env->camera.near_z)
			|| (skybox->vz1 > env->camera.far_z && skybox->vz2 > env->camera.far_z)
			|| (skybox->vx1 < env->camera.far_left && skybox->vx2 < env->camera.far_left)
			|| (skybox->vx1 > env->camera.far_right && skybox->vx2 > env->camera.far_right))
		return (0);
	get_render_intersections(skybox, env);
	if (skybox->vz1 < env->camera.near_z)
	{
		skybox->clipped_vx1 = skybox->inter_near.x;
		skybox->clipped_vz1 = skybox->inter_near.y;
	}
	if (skybox->vz2 < env->camera.near_z)
	{
		skybox->clipped_vx2 = skybox->inter_near.x;
		skybox->clipped_vz2 = skybox->inter_near.y;
	}
	return (1);
}

/*
**	Compute every needed data to draw a skybox
*/

void	compute_skybox(t_render *skybox, t_env *env)
{
	skybox->vx1 = (skybox->v1.x - 5) * env->player.angle_sin - (skybox->v1.z - 5) * env->player.angle_cos;
	skybox->vz1 = (skybox->v1.x - 5) * env->player.angle_cos + (skybox->v1.z - 5) * env->player.angle_sin;
	skybox->vx2 = (skybox->v2.x - 5) * env->player.angle_sin - (skybox->v2.z - 5) * env->player.angle_cos;
	skybox->vz2 = (skybox->v2.x - 5) * env->player.angle_cos + (skybox->v2.z - 5) * env->player.angle_sin;
	//ft_printf("vertex 1 [%f][%f] vertex 2 [%f][%f]\n", skybox->v1.z, skybox->v1.x,
	//skybox->v2.z, skybox->v2.x);
	//ft_printf("vx1 = %f vx2 = %f\n", skybox->vx1, skybox->vx2);
	//ft_printf("vz1 = %f vz2 = %f\n", skybox->vz1, skybox->vz2);
	skybox->clipped_vx1 = skybox->vx1;
	skybox->clipped_vx2 = skybox->vx2;
	skybox->clipped_vz1 = skybox->vz1;
	skybox->clipped_vz2 = skybox->vz2;
	skybox->scale1 = env->camera.scale / -skybox->vz1;
	skybox->scale2 = env->camera.scale / -skybox->vz2;
	skybox->angle_z1 = skybox->vz1 * env->player.angle_z;
	skybox->angle_z2 = skybox->vz2 * env->player.angle_z;
	skybox->preclip_x1 = env->h_w + skybox->vx1 * skybox->scale1;
	skybox->preclip_x2 = env->h_w + skybox->vx2 * skybox->scale2;
	skybox->preclip_floor1 = env->h_h + (-5 + skybox->angle_z1) * skybox->scale1;
	skybox->preclip_floor2 = env->h_h + (-5 + skybox->angle_z2) * skybox->scale2;
	skybox->preclip_ceiling1 = env->h_h + (5 + skybox->angle_z1) * skybox->scale1;
	skybox->preclip_ceiling2 = env->h_h + (5 + skybox->angle_z2) * skybox->scale2;
}

/*
**	Set up walls pos according to i
*/

void		set_v(t_render *skybox, int i)
{
	if (!i)
	{
		skybox->v1.x = 0;
		skybox->v1.z = 0;
		skybox->v2.x = 10;
		skybox->v2.z = 0;
	}
	else
		skybox->v1 = skybox->v2;
	if (i == 1)
	{
		skybox->v2.x = 10;
		skybox->v2.z = 10;
	}
	else if (i == 2)
	{
		skybox->v2.x = 0;
		skybox->v2.z = 10;
	}
	else if (i == 3)
	{
		skybox->v2.x = 0;
		skybox->v2.z = 0;
	}
}

/*
**	Draw a skybox at the current wall's ceiling
*/

void		draw_skybox(t_render render, t_env *env)
{
	t_render	skybox;
	t_vline		vline;
	int			i;

	i = 0;
	skybox.floor_texture = 38;
	skybox.floor_xscale = env->textures[38].surface->w / 10;
	skybox.floor_yscale = env->textures[38].surface->h / 10;
	skybox.ceiling_texture = 39;
	skybox.ceiling_xscale = env->textures[39].surface->w / 10;
	skybox.ceiling_yscale = env->textures[39].surface->h / 10;
	skybox.brightness = 0;
	skybox.light_color = render.light_color;
	skybox.player_pos.x = 5;
	skybox.player_pos.y = 5;
	skybox.skybox = 0;
	skybox.horizon = env->h_h - env->player.angle_z * env->camera.scale;
	skybox.ceiling_horizon = skybox.horizon;
	skybox.floor_horizon = skybox.horizon;
	while (i < 4)
	{
		//ft_printf("i = %d\n", i);
		set_v(&skybox, i);
		//ft_printf("v1 = [%f][%f] v2 = [%f][%f]\n", skybox.v1.x, skybox.v1.z, skybox.v2.x, skybox.v2.z);
		compute_skybox(&skybox, env);
		//ft_printf("clipped_vx1 = %f clipped_vx2 = %f\n", skybox.clipped_vx1, skybox.clipped_vx2);
		//ft_printf("clipped_vz1 = %f clipped_vz2 = %f\n", skybox.clipped_vz1, skybox.clipped_vz2);
		//ft_printf("x1 = %f x2 = %f\n", skybox.x1, skybox.x2);
		if (clip_skybox(&skybox, env))
		{
			skybox.scale1 = env->camera.scale / -skybox.clipped_vz1;
			skybox.scale2 = env->camera.scale / -skybox.clipped_vz2;
			skybox.angle_z1 = skybox.clipped_vz1 * env->player.angle_z;
			skybox.angle_z2 = skybox.clipped_vz2 * env->player.angle_z;
			skybox.x1 = env->h_w + skybox.clipped_vx1 * skybox.scale1;
			skybox.x2 = env->h_w + skybox.clipped_vx2 * skybox.scale2;
			//skybox->x1 = ceil(skybox->x1);
			skybox.floor1 = env->h_h + (-5 + skybox.angle_z1) * skybox.scale1;
			skybox.floor2 = env->h_h + (-5 + skybox.angle_z2) * skybox.scale2;
			skybox.ceiling1 = env->h_h + (5 + skybox.angle_z1) * skybox.scale1;
			skybox.ceiling2 = env->h_h + (5 + skybox.angle_z2) * skybox.scale2;
			if (skybox.x1 < skybox.x2
					&& render.currentx >= skybox.x1 && render.currentx <= skybox.x2)
			{
				/*ft_printf("x1 = %f x2 = %f\n", skybox.x1, skybox.x2);
				ft_printf("floor1 = %f floor2 = %f\n", skybox.floor1, skybox.floor2);
				ft_printf("ceiling1 = %f ceiling2 = %f\n", skybox.ceiling1, skybox.ceiling2);
				ft_printf("clipped_vx1 = %f clipped_vx2 = %f\n", skybox.clipped_vx1, skybox.clipped_vx2);
				ft_printf("clipped_vz1 = %f clipped_vz2 = %f\n", skybox.clipped_vz1, skybox.clipped_vz2);*/
				skybox.texture = 40 + i;
				skybox.xstart = ft_max(skybox.x1, render.xstart);
				skybox.xend = ft_min(skybox.x2, render.xend);
				skybox.xrange = skybox.x2 - skybox.x1;
				skybox.preclip_xrange = skybox.preclip_x2 - skybox.preclip_x1;
				skybox.floor_range = skybox.floor2 - skybox.floor1;
				skybox.ceil_range = skybox.ceiling2 - skybox.ceiling1;
				skybox.x1z1 = skybox.v1.x / skybox.vz1;
				skybox.x2z2 = skybox.v2.x / skybox.vz2;
				skybox.y1z1 = skybox.v1.z / skybox.vz1;
				skybox.y2z2 = skybox.v2.z / skybox.vz2;
				if (skybox.vz2)
					skybox.projected_texture_w = env->textures[40 + i].surface->w
						/ skybox.vz2;
				else
					skybox.projected_texture_w = env->textures[40 + i].surface->w
						/ skybox.clipped_vz2;
				skybox.projected_texture_h = env->textures[40 + i].surface->h;
				/*draw_line_free(new_point(skybox.x1, skybox.floor1),
				  new_point(skybox.x2, skybox.floor2), *env, 0xFFFF0000);
				  draw_line_free(new_point(skybox.x1, skybox.ceiling1),
				  new_point(skybox.x2, skybox.ceiling2), *env, 0xFFFF0000);
				  draw_line_free(new_point(skybox.x1, skybox.floor1),
				  new_point(skybox.x1, skybox.ceiling1), *env, 0xFFFF0000);
				  draw_line_free(new_point(skybox.x2, skybox.floor2),
				  new_point(skybox.x2, skybox.ceiling2), *env, 0xFFFF0000);*/
				skybox.currentx = render.currentx;
				skybox.alpha = (skybox.currentx - skybox.preclip_x1) / skybox.preclip_xrange;
				skybox.clipped_alpha = (skybox.currentx - skybox.x1) / skybox.xrange;
				skybox.z = 1.0 / ((1.0 - skybox.alpha) / skybox.vz1 + skybox.alpha / skybox.vz2);
				skybox.clipped_z = 1.0 / ((1.0 - skybox.clipped_alpha)
						/ skybox.clipped_vz1 + skybox.clipped_alpha / skybox.clipped_vz2);
				skybox.texel.x = ((1.0 - skybox.alpha) * skybox.x1z1 + skybox.alpha * skybox.x2z2) * skybox.z;
				skybox.texel.y = ((1.0 - skybox.alpha) * skybox.y1z1 + skybox.alpha * skybox.y2z2) * skybox.z;
				skybox.max_ceiling = skybox.clipped_alpha * skybox.ceil_range + skybox.ceiling1;
				skybox.current_ceiling = ft_clamp(skybox.max_ceiling, env->ymin[skybox.currentx], env->ymax[skybox.currentx]);
				skybox.max_floor = skybox.clipped_alpha * skybox.floor_range + skybox.floor1;
				skybox.current_floor = ft_clamp(skybox.max_floor, env->ymin[skybox.currentx], env->ymax[skybox.currentx]);
				skybox.line_height = skybox.max_floor - skybox.max_ceiling;
				skybox.ceiling_start = skybox.max_ceiling - skybox.horizon;
				skybox.floor_start = skybox.max_floor - skybox.horizon;
				vline.x = skybox.currentx;
				/*if (skybox.current_floor < render.current_ceiling)
				  {
				  vline.start = skybox.current_floor;
				  vline.end = render.current_ceiling;
				  vline.color = 0xFF0B6484;
				  draw_vline_floor(vline, skybox, env);
				  }*/
				if (skybox.current_ceiling < render.current_ceiling)
				  {
				  vline.start = skybox.current_ceiling;
				  vline.end = ft_min(skybox.current_floor, render.current_ceiling);
				  vline.color = 0xFF0B6484;
				  draw_vline(vline, skybox, env);
				  }
				if (env->ymin[skybox.currentx] < skybox.current_ceiling)
				  {
				  vline.start = env->ymin[skybox.currentx];
				  vline.end = ft_min(skybox.current_ceiling, render.current_ceiling);
				  vline.color = 0xFF0B6484;
				  draw_vline_ceiling(vline, skybox, env);
				  }
			}
		}
		i++;
	}
}
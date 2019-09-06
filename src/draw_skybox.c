/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_skybox.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 14:30:19 by lnicosia          #+#    #+#             */
/*   Updated: 2019/09/06 12:33:44 by lnicosia         ###   ########.fr       */
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

void	clip_skybox(t_render *skybox, t_env *env)
{
	if ((skybox->vz1 < env->camera.near_z && skybox->vz2 < env->camera.near_z)
			|| (skybox->vz1 > env->camera.far_z && skybox->vz2 > env->camera.far_z)
			|| (skybox->vx1 < env->camera.far_left && skybox->vx2 < env->camera.far_left)
			|| (skybox->vx1 > env->camera.far_right && skybox->vx2 > env->camera.far_right))
		return ;
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
}

/*
**	Compute every needed data to draw a skybox
*/

void	compute_skybox(t_render *skybox, t_render render, t_env *env)
{
	(void)render;
	(void)skybox;
	(void)env;
	skybox->vx1 = skybox->v1.x * env->player.angle_sin - skybox->v1.z * env->player.angle_cos;
	skybox->vz1 = skybox->v1.x * env->player.angle_cos - skybox->v1.z * env->player.angle_sin;
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
	clip_skybox(skybox, env);
	skybox->scale1 = env->camera.scale / -skybox->clipped_vz1;
	skybox->scale2 = env->camera.scale / -skybox->clipped_vz2;
	skybox->angle_z1 = skybox->clipped_vz1 * env->player.angle_z;
	skybox->angle_z2 = skybox->clipped_vz2 * env->player.angle_z;
	skybox->x1 = env->h_w + skybox->clipped_vx1 * skybox->scale1;
	skybox->x2 = env->h_w + skybox->clipped_vx2 * skybox->scale2;
	skybox->floor1 = env->h_h + (-5 + skybox->angle_z1) * skybox->scale1;
	skybox->floor2 = env->h_h + (-5 + skybox->angle_z2) * skybox->scale2;
	skybox->ceiling1 = env->h_h + (5 + skybox->angle_z1) * skybox->scale1;
	skybox->ceiling2 = env->h_h + (5 + skybox->angle_z2) * skybox->scale2;
}

/*
**	Draw a skybox at the current wall's ceiling
*/

void		draw_skybox(t_vline vline, t_render render, t_env *env)
{
	t_render	skybox;
	int			i;

	i = 0;
	skybox.floor_texture = 38;
	skybox.ceiling_texture = 39;
	while (i < 4)
	{
		if (i % 2)
			skybox.v1.x = 5;
		else
			skybox.v1.x = -5;
		if (i / 2)
			skybox.v1.z = -5;
		else
			skybox.v1.z = 5;
		//ft_printf("x = %f y = %f\n", skybox.v1.x, skybox.v1.z);
		compute_skybox(&skybox, render, env);
		if (skybox.x1 < skybox.x2
				&& skybox.x1 <= render.xend && skybox.x2 >= render.xstart)
		{
			skybox.texture = 40 + i;
			skybox.xstart = ft_max(skybox.x1, render.xstart);
			skybox.xend = ft_max(skybox.x2, render.xend);
			skybox.xrange = skybox.x2 - skybox.x1;
			skybox.preclip_xrange = skybox.preclip_x2 - skybox.preclip_x1;
			skybox.floor_range = skybox.floor2 - skybox.floor1;
			skybox.ceil_range = skybox.ceiling2 - skybox.ceiling1;
			skybox.projected_texture_w = env->textures[40 + i].surface->w
				/ skybox.clipped_vz2;
			skybox.projected_texture_h = env->textures[40 + i].surface->h;
			threaded_skybox(env, skybox);
		}
		i++;
	}
	//ft_printf("\n\n");
	(void)env;
	(void)render;
	(void)vline;
}

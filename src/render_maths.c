/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_maths.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 09:57:35 by lnicosia          #+#    #+#             */
/*   Updated: 2019/05/21 17:27:36 by sipatry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "render.h"

/*
 **	Get the translated vertices coord for the current wall
 */

void	get_translated_vertices(t_render *render, t_env *env, t_sector sector, int i)
{
	render->v1.x = env->vertices[sector.vertices[i]].x - env->player.pos.x;
	render->v1.y = env->vertices[sector.vertices[i]].y - env->player.pos.y;
	render->v2.x = env->vertices[sector.vertices[i + 1]].x - env->player.pos.x;
	render->v2.y = env->vertices[sector.vertices[i + 1]].y - env->player.pos.y;
}

/*
 **	Get the rotated vertices coord for the current wall
 */

void	get_rotated_vertices(t_render *render, t_env *env)
{
	render->vz1 = render->v1.x * env->player.angle_cos + render->v1.y * env->player.angle_sin;
	render->vz2 = render->v2.x * env->player.angle_cos + render->v2.y * env->player.angle_sin;
	render->vx1 = render->v1.x * env->player.angle_sin - render->v1.y * env->player.angle_cos;
	render->vx2 = render->v2.x * env->player.angle_sin - render->v2.y * env->player.angle_cos;
}

/*
 **	Get the floor and ceiling position on the screen
 */

void	project_floor_and_ceiling(t_render *render, t_env *env, t_sector sector, int i)
{
	double	hfov;
	double	vfov;

	hfov = HFOV * env->h;
	vfov = VFOV * env->h;
	hfov = env->camera.scale;
	vfov = env->camera.scale;
	//hfov *= 1 / tan((env->camera.hfov / 2) * M_PI / 180.0);
	//vfov *= 1 / tan((env->camera.vfov / 2) * M_PI / 180.0);
	render->floor1 = env->h / 2 +
		(int)((sector.clipped_floors1[i] - env->player.pos.z + render->vz1 * env->player.angle_z)
				* (vfov / -render->vz1));
	render->floor2 = env->h / 2 +
		(int)((sector.clipped_floors2[i + 1] - env->player.pos.z + render->vz2 * env->player.angle_z)
				* (vfov / -render->vz2));
	render->ceiling1 = env->h / 2 +
		(int)((sector.clipped_ceilings1[i] - env->player.pos.z + render->vz1 * env->player.angle_z)
				* (vfov / -render->vz1));
	render->ceiling2 = env->h / 2 +
		(int)((sector.clipped_ceilings2[i + 1] - env->player.pos.z + render->vz2 * env->player.angle_z)
				* (vfov / -render->vz2));
	render->x1 = env->w / 2 + (int)(render->vx1 * (hfov / -render->vz1));
	render->x2 = env->w / 2 + (int)(render->vx2 * (hfov / -render->vz2));
}

/*
 **	Get the neighbor floor and ceiling position on the screen
 */

void	project_neighbor_floor_and_ceiling(t_render *render, t_env *env, t_sector neighbor)
{
	double	hfov;
	double	vfov;

	hfov = HFOV * env->h;
	vfov = VFOV * env->h;
	hfov = env->camera.scale;
	vfov = env->camera.scale;
	//hfov *= 1 / tan((env->camera.hfov / 2) * M_PI / 180.0);
	//vfov *= 1 / tan((env->camera.vfov / 2) * M_PI / 180.0);
	render->neighbor_floor1 = env->h / 2 +
		(int)((neighbor.clipped_floors1[render->nv1] - env->player.pos.z + render->vz1 * env->player.angle_z)
				* (vfov / -render->vz1));
	render->neighbor_floor2 = env->h / 2 +
		(int)((neighbor.clipped_floors2[render->nv2] - env->player.pos.z + render->vz2 * env->player.angle_z)
				* (vfov / -render->vz2));
	render->neighbor_ceiling1 = env->h / 2 +
		(int)((neighbor.clipped_ceilings1[render->nv1] - env->player.pos.z + render->vz1 * env->player.angle_z)
				* (vfov / -render->vz1));
	render->neighbor_ceiling2 = env->h / 2 +
		(int)((neighbor.clipped_ceilings2[render->nv2] - env->player.pos.z + render->vz2 * env->player.angle_z)
				* (vfov / -render->vz2));
}

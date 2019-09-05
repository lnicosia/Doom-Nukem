/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_maths.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 09:57:35 by lnicosia          #+#    #+#             */
/*   Updated: 2019/09/05 14:57:22 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "render.h"

/*
**	Get the translated vertices coord for the current wall
*/

void	get_translated_vertices(t_render *render, t_env *env, t_sector sector, int i)
{
	if (i != 0)
	{
		render->v1.x = render->v2.x;
		render->v1.z = render->v2.z;
	}
	else
	{
		render->v1.x = env->vertices[sector.vertices[i]].x - env->player.pos.x;
		render->v1.z = env->vertices[sector.vertices[i]].y - env->player.pos.y;
	}
	render->v2.x = env->vertices[sector.vertices[i + 1]].x - env->player.pos.x;
	render->v2.z = env->vertices[sector.vertices[i + 1]].y - env->player.pos.y;
}

/*
**	Get the rotated vertices coord for the current wall
*/

void	get_rotated_vertices(t_render *render, t_env *env, int i)
{
	if (i != 0)
	{
		render->vx1 = render->vx2;
		render->vz1 = render->vz2;
	}
	else
	{
		render->vx1 = render->v1.x * env->player.angle_sin - render->v1.z * env->player.angle_cos;
		render->vz1 = render->v1.x * env->player.angle_cos + render->v1.z * env->player.angle_sin;
	}
	render->vx2 = render->v2.x * env->player.angle_sin - render->v2.z * env->player.angle_cos;
	render->vz2 = render->v2.x * env->player.angle_cos + render->v2.z * env->player.angle_sin;
	render->preclip_angle_z1 = render->vz1 * env->player.angle_z;
	render->preclip_angle_z2 = render->vz2 * env->player.angle_z;
}

/*
** Translate and rotate vertices z into player's view
*/

void	get_relative_heights(t_render *render, t_env *env, t_sector sector, int i)
{
	double	y1;
	double	y2;

	render->angle_z1 = render->clipped_vz1 * env->player.angle_z;
	render->angle_z2 = render->clipped_vz2 * env->player.angle_z;
	y1 = sector.clipped_floors1[i] - env->player.head_z;
	y2 = sector.clipped_floors2[i + 1] - env->player.head_z;
	render->vfy1 = y1 + render->angle_z1;
	render->vfy2 = y2 + render->angle_z2;
	y1 = sector.clipped_ceilings1[i] - env->player.head_z;
	y2 = sector.clipped_ceilings2[i + 1] - env->player.head_z;
	render->vcy1 = y1 + render->angle_z1;
	render->vcy2 = y2 + render->angle_z2;
}

/*
** Translate and rotate vertices z into player's view
*/

void	get_relative_heights_preclip(t_render *render, t_env *env, t_sector sector, int i)
{
	double	y1;
	double	y2;

	y1 = sector.floors[i] - env->player.head_z;
	y2 = sector.floors[i + 1] - env->player.head_z;
	render->vfy1 = y1 + render->preclip_angle_z1;
	render->vfy2 = y2 + render->preclip_angle_z2;
	y1 = sector.ceilings[i] - env->player.head_z;
	y2 = sector.ceilings[i + 1] - env->player.head_z;
	render->vcy1 = y1 + render->preclip_angle_z1;
	render->vcy2 = y2 + render->preclip_angle_z2;
}

/*
** Translate and rotate neighbor's vertices z into player's view
*/

void	get_neighbor_relative_heights(t_render *render, t_env *env, t_sector neighbor)
{
	double	y1;
	double	y2;

	y1 = neighbor.clipped_floors1[render->nv1] - env->player.head_z;
	y2 = neighbor.clipped_floors2[render->nv2] - env->player.head_z;
	render->nvfy1 = y1 + render->angle_z1;
	render->nvfy2 = y2 + render->angle_z2;
	y1 = neighbor.clipped_ceilings1[render->nv1] - env->player.head_z;
	y2 = neighbor.clipped_ceilings2[render->nv2] - env->player.head_z;
	render->nvcy1 = y1 + render->angle_z1;
	render->nvcy2 = y2 + render->angle_z2;
}

/*
**	Get the floor and ceiling position on the screen
*/

void	project_floor_and_ceiling(t_render *render, t_env *env, t_sector sector, int i)
{
	render->scale1 = env->camera.scale / -render->clipped_vz1;
	render->scale2 = env->camera.scale / -render->clipped_vz2;
	get_relative_heights(render, env, sector, i);
	render->floor1 = env->h_h +
		render->vfy1 * render->scale1;
	render->floor2 = env->h_h +
		render->vfy2 * render->scale2;
	render->ceiling1 = env->h_h +
		render->vcy1 * render->scale1;
	render->ceiling2 = env->h_h +
		render->vcy2 * render->scale2;
	render->horizon = env->h_h -
		env->player.angle_z * env->camera.scale;
	render->floor_horizon = env->h_h
		+ (sector.floor_slope * (sector.floor_max + env->player.head_z) + render->preclip_angle_z1) * env->camera.scale / -render->vz1;
	render->floor_horizon1 = env->h_h
		+ (sector.floor_slope * (sector.floors[i] - env->player.head_z) + render->preclip_angle_z1) * env->camera.scale / -render->vz1;
	render->floor_horizon2 = env->h_h
		+ (sector.floor_slope * (sector.floors[i + 1] - env->player.head_z) + render->preclip_angle_z2) * env->camera.scale / -render->vz2;
	render->floor_horizon_range = render->floor_horizon2 - render->floor_horizon1;
	render->ceiling_horizon = env->h_h
		+ (sector.ceiling_slope * (sector.ceiling_max + env->player.head_z) + render->angle_z1) * render->scale1;
	render->x1 = env->h_w + render->clipped_vx1 * render->scale1;
	render->x2 = env->h_w + render->clipped_vx2 * render->scale2;
	render->x1 = ceil(render->x1);
	//render->x2 = floor(render->x2);
}

/*
**	Get the neighbor floor and ceiling position on the screen
*/

void	project_neighbor_floor_and_ceiling(t_render *render, t_env *env, t_sector neighbor)
{
	get_neighbor_relative_heights(render, env, neighbor);
	render->neighbor_floor1 = env->h_h +
		render->nvfy1 * render->scale1;
	render->neighbor_floor2 = env->h_h +
		render->nvfy2 * render->scale2;
	render->neighbor_ceiling1 = env->h_h +
		render->nvcy1 * render->scale1;
	render->neighbor_ceiling2 = env->h_h +
		render->nvcy2 * render->scale2;
}

/*
**	Get the floor and ceiling position on the screen before clipping
*/

void	project_floor_and_ceiling_preclip(t_render *render, t_env *env, t_sector sector, int i)
{
	render->scale1 = env->camera.scale / -render->vz1;
	render->scale2 = env->camera.scale / -render->vz2;
	get_relative_heights_preclip(render, env, sector, i);
	render->preclip_floor1 = env->h_h +
		render->vfy1 * render->scale1;
	render->preclip_floor2 = env->h_h +
		render->vfy2 * render->scale2;
	render->preclip_ceiling1 = env->h_h +
		render->vcy1 * render->scale1;
	render->preclip_ceiling2 = env->h_h +
		render->vcy2 * render->scale2;
	render->preclip_x1 = env->h_w + render->vx1 * render->scale1;
	render->preclip_x2 = env->h_w + render->vx2 * render->scale2;
	render->preclip_x1 = ceil(render->preclip_x1);
	//render->preclip_x2 = floor(render->preclip_x2);
}

void	get_neighbor_ceil_floor(t_render *render, t_env *env, int x)
{
	//Calculer y actuel du plafond et du sol du voisin
	/*render->current_neighbor_ceiling = (x - render->x1)
		* (render->neighbor_ceiling2 - render->neighbor_ceiling1)
		/ (render->x2 - render->x1) + render->neighbor_ceiling1;
	render->current_neighbor_floor = (x - render->x1)
		* (render->neighbor_floor2 - render->neighbor_floor1)
		/ (render->x2 - render->x1) + render->neighbor_floor1;*/
	render->max_neighbor_ceiling = render->clipped_alpha
		* render->neighbor_ceil_range + render->neighbor_ceiling1;
	render->max_neighbor_floor = render->clipped_alpha
		* render->neighbor_floor_range + render->neighbor_floor1;
	render->current_neighbor_ceiling = ft_clamp(render->max_neighbor_ceiling
			, env->ymin[x], env->ymax[x]);
	render->current_neighbor_floor = ft_clamp(render->max_neighbor_floor
			, env->ymin[x], env->ymax[x]);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_maths.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 09:57:35 by lnicosia          #+#    #+#             */
/*   Updated: 2019/05/07 12:15:35 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "render.h"

/*
 **	Get the translated vertices coord for the current wall
 */

void	get_translated_vertices(t_render *render, t_env *env, t_sector sector, int i)
{
	// 	Vertex 1
	render->v1.x = env->vertices[sector.vertices[i]].x - env->player.pos.x;
	render->v1.y = env->vertices[sector.vertices[i]].y - env->player.pos.y;
	//	Vertex 2
	render->v2.x = env->vertices[sector.vertices[i + 1]].x - env->player.pos.x;
	render->v2.y = env->vertices[sector.vertices[i + 1]].y - env->player.pos.y;
	/*ft_printf("v1 = %d\n", sector.vertices[i]);
	  ft_printf("v1.x = %f\n", v1.x);
	  ft_printf("v1.y = %f\n", v1.y);
	  ft_printf("v2 = %d\n", sector.vertices[i + 1]);
	  ft_printf("v2.x = %f\n", v2.x);
	  ft_printf("v2.y = %f\n", v2.y);*/
}

/*
 **	Get the rotated vertices coord for the current wall
 */

void	get_rotated_vertices(t_render *render, t_env *env)
{
	// Calculer le z entre les murs et le joueur
	render->vz1 = render->v1.x * env->player.angle_cos + render->v1.y * env->player.angle_sin;
	render->vz2 = render->v2.x * env->player.angle_cos + render->v2.y * env->player.angle_sin;
	// Calculer le x entre les murs et le joueur
	render->vx1 = render->v1.x * env->player.angle_sin - render->v1.y * env->player.angle_cos;
	render->vx2 = render->v2.x * env->player.angle_sin - render->v2.y * env->player.angle_cos;
	/*ft_printf("\nz1 = %f\n", render.vz1);
	  ft_printf("z2 = %f\n", render.vz2);
	  ft_printf("x1 = %f\n", x1);
	  ft_printf("x2 = %f\n", x2);*/
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
	render->floor1 = env->h / 2 -
		(int)((sector.floors[i] - env->player.pos.z + render->vz1 * env->player.angle_z)
				* (vfov / render->vz1));
	render->floor2 = env->h / 2 -
		(int)((sector.floors[i + 1] - env->player.pos.z + render->vz2 * env->player.angle_z)
				* (vfov / render->vz2));
	render->ceiling1 = env->h / 2 -
		(int)((sector.ceilings[i] - env->player.pos.z + render->vz1 * env->player.angle_z)
				* (vfov / render->vz1));
	render->ceiling2 = env->h / 2 -
		(int)((sector.ceilings[i + 1] - env->player.pos.z + render->vz2 * env->player.angle_z)
				* (vfov / render->vz2));
	render->x1 = env->w / 2 - (int)(render->vx1 * (hfov / render->vz1));
	render->x2 = env->w / 2 - (int)(render->vx2 * (hfov / render->vz2));
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
	render->neighbor_floor1 = env->h / 2 -
		(int)((neighbor.floors[render->nv1] - env->player.pos.z + render->vz1 * env->player.angle_z)
				* (vfov / render->vz1));
	render->neighbor_floor2 = env->h / 2 -
		(int)((neighbor.floors[render->nv2] - env->player.pos.z + render->vz2 * env->player.angle_z)
				* (vfov / render->vz2));
	render->neighbor_ceiling1 = env->h / 2 -
		(int)((neighbor.ceilings[render->nv1] - env->player.pos.z + render->vz1 * env->player.angle_z)
				* (vfov / render->vz1));
	render->neighbor_ceiling2 = env->h / 2 -
		(int)((neighbor.ceilings[render->nv2] - env->player.pos.z + render->vz2 * env->player.angle_z)
				* (vfov / render->vz2));
}

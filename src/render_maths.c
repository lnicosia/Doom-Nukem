/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_maths.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 09:57:35 by lnicosia          #+#    #+#             */
/*   Updated: 2019/04/16 17:03:25 by sipatry          ###   ########.fr       */
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

void	get_intersection(t_render *render, t_v2 *new_vz, int check_vz)
{
	if (check_vz == 2)
	{
		{
			new_vz->x = vxs(vxs(render->vx1,render->vz1, render->vx2,render->vz2),
					(render->vz1)-(render->vz2),
					vxs(-render->near_side,render->near_z, render->far_side,render->far_z),
					(render->near_z)-(render->far_z))
					/ vxs((render->vx1)-(render->vx2), (render->vz1)-(render->vz2),
					(render->near_side)-(render->far_side), (render->near_z)-(render->far_z));
			new_vz->y = vxs(vxs(render->vx1,render->vz1, render->vx2,render->vz2),
					(render->vz1)-(render->vz2),
					vxs(-render->near_side,render->near_z, -render->far_side,render->far_z),
					(render->near_z)-(render->far_z))
				/ vxs((render->vx1)-(render->vx2), (render->vz1)-(render->vz2),
					(render->near_side)-(render->far_side), (render->near_z)-(render->far_z));
		}

	}
	if (check_vz == 1)
	{
		{
			new_vz->x = vxs(vxs(render->vx1,render->vz1, render->vx2,render->vz2),
					(render->vz1)-(render->vz2),
					vxs(-render->near_side,render->near_z, -render->far_side,render->far_z),
					(render->near_z)-(render->far_z))
					/ vxs((render->vx1)-(render->vx2), (render->vz1)-(render->vz2),
					(-render->near_side)-(render->far_side), (render->near_z)-(render->far_z));
			new_vz->y = vxs(vxs(render->vx1,render->vx1, render->vx2,render->vz2),
					(render->vz1)-(render->vz2),
					vxs(-render->near_side,render->near_z, -render->far_side,render->far_z),
					(render->near_z)-(render->far_z))
				/ vxs((render->vx1)-(render->vx2), (render->vz1)-(render->vz2),
					(-render->near_side)-(-render->far_side), (render->near_z)-(render->far_z));
		}
	}
}
/*
   {
   vxs((vxs(render->v1.x, render->v1.y, render->v2.x, render->v2.y),
   (render->v1.x) - (render->v2.x),
   vxs(env->player.pox.x, env->player.pos.y, x4,y4),
   (en->player.pos.x)-(x4)) /
   vxs(render->v1.x, render->v1.y, render->v2.x, render->v2.y),
   (render->v1.x) - (render->v2.x));
   vxs(env->player.pox.x, env->player.pos.y, x4,y4),
   (en->player.pos.x)-(x4);
   vxs(vxs(x1,y1, x2,y2), (y1)-(y2),
   ,y3, x4,y4), (y3)-(y4))
   / vxs((x1)-(x2), (y1)-(y2), (x3)-(x4), (y3)-(y4));
   }
   */
/*
 **	Get the floor and ceiling position on the screen
 */

void	get_floor_and_ceiling_screen_coordinates(t_render *render, t_env *env, t_sector sector)
{
	render->floor1 = env->h / 2 -
		(int)((sector.floor - env->player.pos.z + render->vz1 * env->player.angle_z)
				* ((VFOV * env->h) / render->vz1));
	render->floor2 = env->h / 2 -
		(int)((sector.floor - env->player.pos.z + render->vz2 * env->player.angle_z)
				* ((VFOV * env->h) / render->vz2));
	render->ceiling1 = env->h / 2 -
		(int)((sector.ceiling - env->player.pos.z + render->vz1 * env->player.angle_z)
				* ((VFOV * env->h) / render->vz1));
	render->ceiling2 = env->h / 2 -
		(int)((sector.ceiling - env->player.pos.z + render->vz2 * env->player.angle_z)
				* ((VFOV * env->h) / render->vz2));
	render->x1 = (int)(env->w / 2 - render->vx1 * ((HFOV * env->h) / render->vz1));
	render->x2 = (int)(env->w / 2 - render->vx2 * ((HFOV * env->h) / render->vz2));
}

/*
 **	Get the neighbor floor and ceiling position on the screen
 */

void	get_neighbor_floor_and_ceiling_screen_coordinates(t_render *render, t_env *env, t_sector neighbor)
{
	render->neighbor_floor1 = env->h / 2 -
		(int)((neighbor.floor - env->player.pos.z + render->vz1 * env->player.angle_z)
				* ((VFOV * env->h) / render->vz1));
	render->neighbor_floor2 = env->h / 2 -
		(int)((neighbor.floor - env->player.pos.z + render->vz2 * env->player.angle_z)
				* ((VFOV * env->h) / render->vz2));
	render->neighbor_ceiling1 = env->h / 2 -
		(int)((neighbor.ceiling - env->player.pos.z + render->vz1 * env->player.angle_z)
				* ((VFOV * env->h) / render->vz1));
	render->neighbor_ceiling2 = env->h / 2 -
		(int)((neighbor.ceiling - env->player.pos.z + render->vz2 * env->player.angle_z)
				* ((VFOV * env->h) / render->vz2));
}

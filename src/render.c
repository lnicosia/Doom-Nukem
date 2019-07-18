/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaerhard <gaerhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 11:57:06 by lnicosia          #+#    #+#             */
/*   Updated: 2019/07/17 13:36:59 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "utils.h"
#include "render.h"

short	get_vertex_nb_in_sector(short vertex, t_sector sector)
{
	short	i;
	short	res;

	i = 0;
	res = 0;
	while (i < sector.nb_vertices)
	{
		if (sector.vertices[i] == vertex)
			res = i;
		i++;
	}
	return (res);
}

void	clipped_slope1(t_env *env, t_sector sector, t_render render, int i)
{
	env->vertices[sector.vertices[i]].clipped_x[0] = render.clipped_vx1 * env->player.angle_sin
		+ render.clipped_vz1 * env->player.angle_cos;
	env->vertices[sector.vertices[i]].clipped_y[0] = render.clipped_vx1 * -env->player.angle_cos
		+ render.clipped_vz1 * env->player.angle_sin;
	env->vertices[sector.vertices[i]].clipped_x[0] += env->player.pos.x;
	env->vertices[sector.vertices[i]].clipped_y[0] += env->player.pos.y;
	env->vertices[sector.vertices[i]].clipped[0] = 1;
	if (sector.floor_slope)
		env->sectors[render.sector].clipped_floors1[i] = get_clipped_floor(0, sector, env->vertices[sector.vertices[i]], env); 
	if (sector.ceiling_slope)
		env->sectors[render.sector].clipped_ceilings1[i] = get_clipped_ceiling(0, sector, env->vertices[sector.vertices[i]], env); 
}

void	clipped_slope2(t_env *env, t_sector sector, t_render render, int i)
{
	env->vertices[sector.vertices[i + 1]].clipped_x[1] = render.clipped_vx2 * env->player.angle_sin
		+ render.clipped_vz2 * env->player.angle_cos;
	env->vertices[sector.vertices[i + 1]].clipped_y[1] = render.clipped_vx2 * -env->player.angle_cos
		+ render.clipped_vz2 * env->player.angle_sin;
	env->vertices[sector.vertices[i + 1]].clipped_x[1] += env->player.pos.x;
	env->vertices[sector.vertices[i + 1]].clipped_y[1] += env->player.pos.y;
	env->vertices[sector.vertices[i + 1]].clipped[1] = 1;
	if (sector.floor_slope)
		env->sectors[render.sector].clipped_floors2[i + 1] = get_clipped_floor(1, sector, env->vertices[sector.vertices[i + 1]], env); 
	if (sector.ceiling_slope)
		env->sectors[render.sector].clipped_ceilings2[i + 1] = get_clipped_ceiling(1, sector, env->vertices[sector.vertices[i + 1]], env); 
}


void	render_sector(t_env *env, t_render render)
{
	int			i;
	t_sector	sector;
	//t_vline		vline;
	int			x;

	if (!env->rendered_sectors[render.sector])
	{
		env->rendered_sectors[render.sector]++;
		i = 0;
		sector = env->sectors[render.sector];
		while (i < sector.nb_vertices)
		{
			render.i = i;
			// Calculer les coordonnes transposees du mur par rapport au joueur 
			get_translated_vertices(&render, env, sector, i);
			// Calculer les coordonnes tournees du mur par rapport au joueur 
			get_rotated_vertices(&render, env, i);

			project_floor_and_ceiling_preclip(&render, env, sector, i);
			render.v1_clipped = 0;
			render.v2_clipped = 0;
			render.wall_width = sector.wall_width[i] / 10;
			render.wall_height = (sector.ceiling - sector.floor) / 10;
			render.texture = sector.textures[i];
			render.floor_texture = sector.floor_texture;
			render.ceiling_texture = sector.ceiling_texture;
			render.floor_yscale = env->textures[render.floor_texture].surface->h / 5.0;
			render.floor_xscale = env->textures[render.floor_texture].surface->w / 5.0;
			render.ceiling_yscale = env->textures[render.ceiling_texture].surface->h / 5.0;
			render.ceiling_xscale = env->textures[render.ceiling_texture].surface->w / 5.0;
			// On continue uniquement si au moins un des deux vertex est dans le champ de vision
			if (check_fov(&render, env))
			{
				// Calculer le cliping
				clip_walls(&render, env);
				if (render.v1_clipped)
					clipped_slope1(env, sector, render, i);
				else
				{
					render.clipped_vz1 = render.vz1;
					render.clipped_vx1 = render.vx1;
				}
				if (render.v2_clipped)
					clipped_slope2(env, sector, render, i);
				else
				{
					render.clipped_vz2 = render.vz2;
					render.clipped_vx2 = render.vx2;
				}
				// Obtenir les coordoonees du sol et du plafond sur l'ecran
				project_floor_and_ceiling(&render, env, sector, i);

				if (render.x1 < render.x2
						&& render.x1 < render.xmax && render.x2 > render.xmin)
				{
					render.xstart = ft_max(render.x1, render.xmin);
					render.xend = ft_min(render.x2, render.xmax);
					// Pareil pour le secteur voisin si c'est un portail
					if (sector.neighbors[i] >= 0 && sector.neighbors[i] != env->player.sector
					   && !env->rendered_sectors[sector.neighbors[i]])
					{
						render.nv1 = get_vertex_nb_in_sector(sector.vertices[i], env->sectors[sector.neighbors[i]]);
						render.nv2 = get_vertex_nb_in_sector(sector.vertices[i + 1], env->sectors[sector.neighbors[i]]);
						project_neighbor_floor_and_ceiling(&render, env, env->sectors[sector.neighbors[i]]);
					}
					x = render.xstart;
					render.xrange = render.x2 - render.x1;
					render.preclip_xrange = render.preclip_x2 - render.preclip_x1;
					render.x1z1 = env->vertices[sector.vertices[i]].x / render.vz1;
					render.x2z2 = env->vertices[sector.vertices[i + 1]].x / render.vz2;
					render.y1z1 = env->vertices[sector.vertices[i]].y / render.vz1;
					render.y2z2 = env->vertices[sector.vertices[i + 1]].y / render.vz2; 
					render.ceil_range = render.ceiling2 - render.ceiling1;
					render.floor_range = render.floor2 - render.floor1;
					if (render.vz2)
						render.projected_texture_w = env->textures[render.texture].surface->w
							* render.wall_width / render.vz2;
					else
						render.projected_texture_w = env->textures[render.texture].surface->w
							* render.wall_width / render.clipped_vz2;
					render.projected_texture_h = env->textures[render.texture].surface->h
						* render.wall_height;

					// Multithread
					threaded_raycasting(env, render);

					if (sector.neighbors[i] >= 0)
					{
						t_render new = render;
						new.xmin = render.xstart;
						new.xmax = render.xend;
						new.sector = sector.neighbors[i];
						render_sector(env, new);
					}
				}
			}
			i++;
		}
		env->rendered_sectors[render.sector]--;
	}
}

static void		reset_render_utils(t_env *env)
{
	int	i;
	int	max;
	int	ymin;
	int	ymax;

	max = env->screen_sectors_size;
	ymin = ft_max(env->h_h + env->camera.y1 * env->camera.scale, 0);
	ymax = ft_min(env->h_h + env->camera.y2 * env->camera.scale, env->h - 1);
	i = 0;
	while (i < max)
	{
		env->xmin[i] = -1;
		env->xmax[i] = -1;
		env->screen_sectors[i] = -1;
		i++;
	}
	i = 0;
	while (i < env->nb_sectors)
	{
		env->rendered_sectors[i] = 0;
		i++;
	}
	i = 0;
	while (i < env->w)
	{
		env->ymin[i] = ymin;
		env->ymax[i] = ymax;
		i++;
	}
}

/*
**	Main draw function
*/

int				draw_walls(t_env *env)
{
	int				i;
	int				screen_sectors;
	t_render		render;

	i = 0;
	//ft_printf("\n");
	env->count = 0;
	reset_render_utils(env);
	screen_sectors = get_screen_sectors(env);
	while (i < screen_sectors)
	{
		render.xmin = env->xmin[i];
		render.xmax = env->xmax[i];
		render.sector = env->screen_sectors[i];
		//ft_printf("rendering from sector %d\n", render.sector);
		render_sector(env, render);
		i++;
	}
	return (0);
}

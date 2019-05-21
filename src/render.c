/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaerhard <gaerhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 11:57:06 by lnicosia          #+#    #+#             */
/*   Updated: 2019/05/21 17:35:25 by sipatry          ###   ########.fr       */
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
	if (res < 0)
		res = sector.nb_vertices - 1;
	return (res);
}

/*void	calc_render(t_render *render, t_line *line, int x)
  {
  render->currentx = x;
// Lumiere
render->light = 255 - ft_fclamp(((double)(x - render->x1) * (double)(render->vz2 - render->vz1) / (double)(render->x2 - render->x1) + (double)render->vz1) * 6.00, 0.00, 255.00);
// Calculer y actuel du plafond et du sol
render->current_ceiling = (x - render->x1) * (render->ceiling2 - render->ceiling1) / (render->x2 - render->x1) + render->ceiling1;
render->current_ceiling = ft_clamp(render->current_ceiling, render->ymin, render->ymax);
render->current_floor = (x - render->x1) * (render->floor2 - render->floor1) / (render->x2 - render->x1) + render->floor1;
render->current_floor = ft_clamp(render->current_floor, render->ymin, render->ymax);
line->start = render->current_ceiling;
line->end = render->current_floor;
line->x = x;

}*/

void	neighbor_ceil_floor(t_render *render, int x)
{
	//Calculer y actuel du plafond et du sol du voisin
	render->current_neighbor_ceiling = (x - render->x1)
		* (render->neighbor_ceiling2 - render->neighbor_ceiling1)
		/ (render->x2 - render->x1) + render->neighbor_ceiling1;
	render->current_neighbor_ceiling = ft_clamp(render->current_neighbor_ceiling
			, render->ymin, render->ymax);
	render->current_neighbor_floor = (x - render->x1)
		* (render->neighbor_floor2 - render->neighbor_floor1)
		/ (render->x2 - render->x1) + render->neighbor_floor1;
	render->current_neighbor_floor = ft_clamp(render->current_neighbor_floor
			, render->ymin, render->ymax);
}

void	render_sector(t_env *env, t_render render)
{
	int			i;
	t_sector	sector;
	t_vline		vline;
	t_line		line;
	int			x;
	int			xstart;
	int			xend;

	i = 0;
	while (i < env->w)
	{
		env->depth_array[i] = -2147483647;
		i++;
	}
	if (!env->rendered_sectors[render.sector])
	{
		env->rendered_sectors[render.sector]++;
		i = 0;
		sector = env->sectors[render.sector];
		while (i < sector.nb_vertices)
		{
			// Calculer les coordonnes transposees du mur par rapport au joueur 
			get_translated_vertices(&render, env, sector, i);
			// Calculer les coordonnes tournees du mur par rapport au joueur 
			get_rotated_vertices(&render, env);
			render.v1_clipped = 0;
			render.v2_clipped = 0;
			// On continue uniquement si au moins un des deux vertex est dans le champ de vision
			if (check_fov(&render, env))
				//|| !env->options.clipping)
			{
				// Calculer le cliping
				if (env->options.clipping)
				{
					clip_walls(&render, env);
					if (render.v1_clipped)
					{
						env->vertices[sector.vertices[i]].clipped_x[0] = (render.vx1) * env->player.angle_sin
							+ (render.vz1) * env->player.angle_cos;
						env->vertices[sector.vertices[i]].clipped_y[0] = (render.vx1) * -env->player.angle_cos
							+ (render.vz1) * env->player.angle_sin;
						env->vertices[sector.vertices[i]].clipped_x[0] += env->player.pos.x;
						env->vertices[sector.vertices[i]].clipped_y[0] += env->player.pos.y;
						env->vertices[sector.vertices[i]].clipped[0] = 1;
						line.x0 = env->w - 150 + (env->vertices[sector.vertices[i]].clipped_x[0] - env->player.pos.x) * env->options.minimap_scale;
						line.y0 = 150 + (env->vertices[sector.vertices[i]].clipped_y[0] - env->player.pos.y) * env->options.minimap_scale;
						if (sector.floor_slope)
							env->sectors[render.sector].clipped_floors1[i] = get_clipped_floor(0, sector, env->vertices[sector.vertices[i]], env); 
						if (sector.ceiling_slope)
							env->sectors[render.sector].clipped_ceilings1[i] = get_clipped_ceiling(0, sector, env->vertices[sector.vertices[i]], env); 
					}
					else
					{
						line.x0 = env->w - 150 + (env->vertices[sector.vertices[i]].x - env->player.pos.x) * env->options.minimap_scale;
						line.y0 = 150 + (env->vertices[sector.vertices[i]].y - env->player.pos.y) * env->options.minimap_scale;
					}
					if (render.v2_clipped)
					{
						env->vertices[sector.vertices[i + 1]].clipped_x[1] = (render.vx2) * env->player.angle_sin
							+ (render.vz2) * env->player.angle_cos;
						env->vertices[sector.vertices[i + 1]].clipped_y[1] = (render.vx2) * -env->player.angle_cos
							+ (render.vz2) * env->player.angle_sin;
						env->vertices[sector.vertices[i + 1]].clipped_x[1] += env->player.pos.x;
						env->vertices[sector.vertices[i + 1]].clipped_y[1] += env->player.pos.y;
						env->vertices[sector.vertices[i + 1]].clipped[1] = 1;
						line.x1 = env->w - 150 + (env->vertices[sector.vertices[i + 1]].clipped_x[1] - env->player.pos.x) * env->options.minimap_scale;
						line.y1 = 150 + (env->vertices[sector.vertices[i + 1]].clipped_y[1] - env->player.pos.y) * env->options.minimap_scale;
						if (sector.floor_slope)
							env->sectors[render.sector].clipped_floors2[i + 1] = get_clipped_floor(1, sector, env->vertices[sector.vertices[i + 1]], env); 
						if (sector.ceiling_slope)
							env->sectors[render.sector].clipped_ceilings2[i + 1] = get_clipped_ceiling(1, sector, env->vertices[sector.vertices[i + 1]], env); 
					}
					else
					{
						line.x1 = env->w - 150 + (env->vertices[sector.vertices[i + 1]].x - env->player.pos.x) * env->options.minimap_scale;
						line.y1 = 150 + (env->vertices[sector.vertices[i + 1]].y - env->player.pos.y) * env->options.minimap_scale;
					}
					if (env->options.test && env->player.pos.z > sector.floor_min && env->player.pos.z < sector.ceiling_max)
					{
						line.color = 0xFFFF0000;
						draw_line_3(env, line);
					}
				}
				// Obtenir les coordoonees du sol et du plafond sur l'ecran
				project_floor_and_ceiling(&render, env, sector, i);
				if (render.x1 < render.x2)
				{
					xstart = ft_max(render.x1, render.xmin);
					xend = ft_min(render.x2, render.xmax);
					// Pareil pour le secteur voisin si c'est un portail
					if (sector.neighbors[i] >= 0 && sector.neighbors[i] != env->player.sector)
					{
						render.nv1 = get_vertex_nb_in_sector(sector.vertices[i], env->sectors[sector.neighbors[i]]);
						render.nv2 = get_vertex_nb_in_sector(sector.vertices[i + 1], env->sectors[sector.neighbors[i]]);
						project_neighbor_floor_and_ceiling(&render, env, env->sectors[sector.neighbors[i]]);
					}
					if (sector.neighbors[i] >= 0 && env->options.render_sectors)
					{
						// TODO array de ymin et ymax pour delimiter la hauteur du prochain secteur
						t_render new = render;
						new.xmin = xstart;
						new.xmax = xend;
						new.sector = sector.neighbors[i];
						render_sector(env, new);
					}
					x = xstart;
					while (x <= xend)
					{
						render.currentx = x;
						// Lumiere
						render.light = 255 - ft_fclamp(((double)(x - render.x1) * (double)(render.vz2 - render.vz1) / (double)(render.x2 - render.x1) + (double)render.vz1) * 4.00, 0.00, 255.00);
						// Calculer y actuel du plafond et du sol
						render.current_ceiling = (x - render.x1) * (render.ceiling2 - render.ceiling1) / (render.x2 - render.x1) + render.ceiling1;
						//	ft_printf(" ceiling = %d ", render.current_ceiling);
						render.current_ceiling = ft_clamp(render.current_ceiling, render.ymin, render.ymax);
						render.current_floor = (x - render.x1) * (render.floor2 - render.floor1) / (render.x2 - render.x1) + render.floor1;
						render.current_floor = ft_clamp(render.current_floor, render.ymin, render.ymax);
						vline.start = render.current_ceiling;
						vline.end = render.current_floor;
						vline.x = x;
						if (sector.neighbors[i] >= 0)
						{
							neighbor_ceil_floor(&render, x);
							// Dessiner le plafond de ymin jusqu'au plafond
							draw_ceiling(render, env);
							// Dessiner le sol du sol jusqu'a ymax
							draw_floor(render, env);
							if (!env->options.render_sectors)
							{
								// Dessiner le portail en rouge
								vline.color = 0xFFAA0000;
								if (env->options.lighting)
									vline.color = 255 << 24 | (int)render.light << 16;
								if (env->options.contouring && (x == render.x1 || x == render.x2))
									vline.color = 0;
								draw_vline(vline, env);
							}
							// Dessiner corniche
							if (render.current_neighbor_ceiling > render.current_ceiling)
								draw_upper_wall(render, env);
							// Dessiner marche
							if (render.current_neighbor_floor < render.current_floor)
							{
								/*ft_printf("current sector vertex floor height = %f current neighbor vertex floor height = %f\n",
										sector.clipped_floors1[i], env->sectors[sector.neighbors[i]].clipped_floors2[render.nv2]);
								ft_printf("current sector vertex floor height = %d current neighbor vertex floor height = %d\n",
										render.current_neighbor_floor, render.current_floor);*/
								draw_bottom_wall(render, env);
							}
						}
						else
						{
							if (env->depth_array[x] < render.light)
							{
								env->depth_array[x] = render.light;
								if (env->options.color_clipping && (render.v1_clipped || render.v2_clipped))
									vline.color = 0xFF00AA00;
								else
									vline.color = 0xFF888888;
								if (env->options.wall_color)
								{
									if (i == 0)
										vline.color = 0xFFAA0000;
									if (i == 1)
										vline.color = 0xFF00AA00;
									if (i == 2)
										line.color = 0xAAFF;
								}	
								if (env->options.lighting)
									vline.color = 255 << 24 | (int)render.light << 16 | (int)render.light << 8 | (int)render.light << 0;
								if (env->options.contouring && (x == render.x1 || x == render.x2))
									vline.color = 0xFF222222;
								draw_vline(vline, env);
								// Dessiner le plafond de ymin jusqu'au plafond
								draw_ceiling(render, env);
								// Dessiner le sol du sol jusqu'a ymax
								draw_floor(render, env);
							}
						}
						x++;
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

	max = ft_min(env->nb_sectors, env->w);
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
}

/*
 **	Main draw function
 **	TODO Protect function
 */

int				draw(t_env *env)
{
	int			i;
	int			screen_sectors;
	t_render	render;

	i = 0;
	reset_render_utils(env);
	screen_sectors = get_screen_sectors(env);
	render.ymin = ft_max(env->h / 2 + env->camera.y1 * env->camera.scale, 0);
	render.ymax = ft_min(env->h / 2 + env->camera.y2 * env->camera.scale, env->h - 1);
	while (i < screen_sectors)
	{
		render.xmin = env->xmin[i];
		render.xmax = env->xmax[i];
		render.sector = env->screen_sectors[i];
		render_sector(env, render);
		i++;
	}
	return (0);
}

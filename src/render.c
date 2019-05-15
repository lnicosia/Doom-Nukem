/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaerhard <gaerhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 11:57:06 by lnicosia          #+#    #+#             */
/*   Updated: 2019/05/15 11:46:03 by sipatry          ###   ########.fr       */
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

void	calc_render(t_render *render, t_line *line, int x)
{
	render->currentx = x;
	// Lumiere
	render->light = 255 - ft_fclamp(((double)(x - render->x1) * (double)(render->vz2 - render->vz1) / (double)(render->x2 - render->x1) + (double)render->vz1) * 8.00, 0.00, 255.00);
	// Calculer y actuel du plafond et du sol
	render->current_ceiling = (x - render->x1) * (render->ceiling2 - render->ceiling1) / (render->x2 - render->x1) + render->ceiling1;
	render->current_ceiling = ft_clamp(render->current_ceiling, render->ymin, render->ymax);
	render->current_floor = (x - render->x1) * (render->floor2 - render->floor1) / (render->x2 - render->x1) + render->floor1;
	render->current_floor = ft_clamp(render->current_floor, render->ymin, render->ymax);
	line->start = render->current_ceiling;
	line->end = render->current_floor;
	line->x = x;

}


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

void	render_sector(t_env *env, t_render render, short *rendered_sectors)
{
	int			i;
	t_sector	sector;
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
	if (!rendered_sectors[render.sector])
	{
		rendered_sectors[render.sector]++;
		i = 0;
		sector = env->sectors[render.sector];
		while (i < sector.nb_vertices)
		{
			// Calculer les coordonnes transposees du mur par rapport au joueur 
			get_translated_vertices(&render, env, sector, i);
			// Calculer les coordonnes tournees du mur par rapport au joueur 
			get_rotated_vertices(&render, env);
			// On continue uniquement si au moins un des deux vertex est dans le champ de vision
			if (check_fov(&render, env)
					|| !env->options.clipping)
			{
				// Calculer le cliping
				if (env->options.clipping)
				{
					clip_walls(&render, env);
					if (render.v1_clipped)
					{
						env->vertices[sector.vertices[i]].clipped_y = (render.vx1) * -env->player.angle_cos
							+ (render.vz1) * env->player.angle_sin;
						env->vertices[sector.vertices[i]].clipped_x = (render.vx1) * env->player.angle_sin
							- (render.vz1) * -env->player.angle_cos;
						env->vertices[sector.vertices[i]].clipped_x += env->player.pos.x;
						env->vertices[sector.vertices[i]].clipped_y += env->player.pos.y;
						env->vertices[sector.vertices[i]].clipped = 1;
					}
					if (render.v2_clipped)
					{
						env->vertices[sector.vertices[i + 1]].clipped_y = (render.vx2) * -env->player.angle_cos
							+ (render.vz2) * env->player.angle_sin;
						env->vertices[sector.vertices[i + 1]].clipped_x = (render.vx2) * env->player.angle_sin
							- (render.vz2) * -env->player.angle_cos;
						env->vertices[sector.vertices[i + 1]].clipped_x += env->player.pos.x;
						env->vertices[sector.vertices[i + 1]].clipped_y += env->player.pos.y;
						env->vertices[sector.vertices[i + 1]].clipped = 1;
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
						new.father = sector.num;
						new.sector = sector.neighbors[i];
						render_sector(env, new, rendered_sectors);
					}
					x = xstart;
					while (x <= xend)
					{
						calc_render(&render, &line, x);
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
								line.color = 0xAA0000FF;
								if (env->options.lighting)
									line.color = (int)render.light << 24 | 255;
								draw_line(line, env);
							}
							// Dessiner corniche
							if (render.current_neighbor_ceiling > render.current_ceiling)
								draw_upper_wall(render, env);
							// Dessiner marche
							if (render.current_neighbor_floor < render.current_floor)
								draw_bottom_wall(render, env);
						}
						else
						{

							if (env->depth_array[x] < render.light)
							{
								env->depth_array[x] = render.light;
								if (render.clipped && env->options.color_clipping)
									line.color = 0x00AA00FF;
								else
									line.color = 0x888888FF;
								if (env->options.wall_color)
								{
									if (i == 0)
										line.color = 0xAA0000FF;
									if (i == 1)
										line.color = 0x00AA00FF;
									if (i == 2)
										line.color = 0xAAFF;
								}	
								if (env->options.lighting)
									line.color = (int)render.light << 24 | (int)render.light << 16 | (int)render.light << 8 | 255;
								if (env->options.contouring && (x == render.x1 || x == render.x2))
									line.color = 0xFF;
								draw_line(line, env);
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
		rendered_sectors[render.sector]--;
	}
}


static short	*init_rendered_sector(t_env *env)
{
	short	*res;
	int		i;

	if (!(res = (short*)malloc(sizeof(short) * env->nb_sectors)))
	{
		ft_printf("Could not malloc rendering sector array!\n");
		return (NULL);
	}
	i = 0;
	while (i < env->nb_sectors)
	{
		res[i] = 0;
		i++;
	}
	return (res);
}

/*
 **	Main draw function
 **	TODO Protect function
 */

int				draw(t_env *env)
{
	t_render	render;
	short		*rendered_sectors;

	if (!(env->depth_array = (double *)malloc(sizeof(double) * env->w)))
		return (-1);
	render.xmin = 0;
	render.xmax = env->w - 1;
	render.ymin = 0;
	render.ymax = env->h - 1;
	render.father = -2;
	if (!(rendered_sectors = init_rendered_sector(env)))
		return (-1);
	if (env->options.render_type)
		render.sector = env->player.camera_sector;
	else
		render.sector = env->player.sector;
	// On commence par rendre le secteur courant
	render_sector(env, render, rendered_sectors);
	ft_memdel((void**)&rendered_sectors);
	ft_memdel((void**)&env->depth_array);
	return (0);
}

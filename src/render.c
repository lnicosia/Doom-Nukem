/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaerhard <gaerhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 11:57:06 by lnicosia          #+#    #+#             */
/*   Updated: 2019/05/08 18:20:29 by lnicosia         ###   ########.fr       */
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
	//ft_printf("Vertex n %d in env\n", vertex);
	while (i < sector.nb_vertices)
	{
		//ft_printf("Neighbor sector %d = %d\n", i, sector.vertices[i]);
		if (sector.vertices[i] == vertex)
			res = i;
		i++;
	}
	if (res < 0)
		res = sector.nb_vertices - 1;
	return (res);
}

void	render_sector(t_env *env, t_render render, short *rendered_sectors)
{
	int			i;
	t_sector	sector;
	t_line		line;
	int			x;
	int			xstart;
	int			xend;

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
			if (is_in_fov(render.vx1, render.vz1, env) || is_in_fov(render.vx2, render.vz2, env))
			{
				// Calculer le cliping
				clip_walls(&render, env);

				// Obtenir les coordoonees du sol et du plafond sur l'ecran
				project_floor_and_ceiling(&render, env, sector, i);

				if (render.x1 < render.x2)
				{
					// Pareil pour le secteur voisin si c'est un portail
					if (sector.neighbors[i] >= 0 && sector.neighbors[i] != env->player.sector)
					{
						render.nv1 = get_vertex_nb_in_sector(sector.vertices[i], env->sectors[sector.neighbors[i]]);
						render.nv2 = get_vertex_nb_in_sector(sector.vertices[i + 1], env->sectors[sector.neighbors[i]]);
						project_neighbor_floor_and_ceiling(&render, env, env->sectors[sector.neighbors[i]]);
					}
					xstart = ft_max(render.x1, render.xmin);
					xend = ft_min(render.x2, render.xmax);
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
						render.currentx = x;
						// Lumiere
						render.light = 255 - ft_clamp(((x - render.x1) * (render.vz2 - render.vz1) / (render.x2 - render.x1) + render.vz1) * 8, 0, 255);

						// Calculer y actuel du plafond et du sol
						render.current_ceiling = (x - render.x1) * (render.ceiling2 - render.ceiling1) / (render.x2 - render.x1) + render.ceiling1;
						render.current_ceiling = ft_clamp(render.current_ceiling, render.ymin, render.ymax);
						render.current_floor = (x - render.x1) * (render.floor2 - render.floor1) / (render.x2 - render.x1) + render.floor1;
						render.current_floor = ft_clamp(render.current_floor, render.ymin, render.ymax);

						// Dessiner le plafond de ymin jusqu'au plafond
						draw_ceiling(render, env);

						// Dessiner le sol du sol jusqu'a ymax
						draw_floor(render, env);

						// Dessiner le mur du plafond jusqu'au sol
						line.start = render.current_ceiling;
						line.end = render.current_floor;
						line.x = x;
						if (sector.neighbors[i] >= 0)
						{
							if (!env->options.render_sectors)
							{
								// Dessiner le portail en rouge
								line.color = 0xAA0000FF;
								if (env->options.lighting)
									line.color = render.light << 24 | 255;
								draw_line(line, env);
							}
							// Calculer y actuel du plafond et du sol du voisin
							render.current_neighbor_ceiling = (x - render.x1) * (render.neighbor_ceiling2 - render.neighbor_ceiling1) / (render.x2 - render.x1) + render.neighbor_ceiling1;
							render.current_neighbor_ceiling = ft_clamp(render.current_neighbor_ceiling, render.ymin, render.ymax);
							render.current_neighbor_floor = (x - render.x1) * (render.neighbor_floor2 - render.neighbor_floor1) / (render.x2 - render.x1) + render.neighbor_floor1;
							render.current_neighbor_floor = ft_clamp(render.current_neighbor_floor, render.ymin, render.ymax);
							// Dessiner corniche
							if (render.current_neighbor_ceiling > render.current_ceiling)
								draw_upper_wall(render, env);
							// Dessiner marche
							if (render.current_neighbor_floor < render.current_floor)
								draw_bottom_wall(render, env);
						}
						else
						{
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
								line.color = render.light << 24 | render.light << 16 | render.light << 8 | 255;
							if (env->options.contouring && (x == render.x1 || x == render.x2))
								line.color = 0xFF;
							draw_line(line, env);
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
	int			i;

	i = 0;
	render.xmin = 0;
	render.xmax = env->w - 1;
	render.ymin = 0;
	render.ymax = env->h - 1;
	render.father = -2;
	if (!(rendered_sectors = init_rendered_sector(env)))
		return (-1);
	render.sector = env->player.sector;
	// On commence par rendre le secteur courant
	render_sector(env, render, rendered_sectors);
	ft_memdel((void**)&rendered_sectors);
	return (0);
}

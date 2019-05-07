/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaerhard <gaerhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 11:57:06 by lnicosia          #+#    #+#             */
/*   Updated: 2019/05/07 18:03:14 by sipatry          ###   ########.fr       */
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

void	render_sector(t_env *env, t_render render, short *rendered_sectors, int coucou)
{
	int			i;
	t_sector	sector;
	t_line		line;
	int			x;
	int			xstart;
	int			xend;
//	int			temp;

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
		//ft_printf("rendering sector #%d\n", render.sector);
		sector = env->sectors[render.sector];
		//ft_printf("rendering sector numero %d from sector numero %d\n\n", render.sector, render.father);
		//ft_printf("Sector #%d\n%d vertices\n", sector.num, sector.nb_vertices);
		while (i < sector.nb_vertices)
		{
			//	printf("mur[%d] = %d | %d\n", i, env->vertices[sector.vertices[i]].num, env->vertices[sector.vertices[i + 1]].num);
			ft_printf("\n v%d a v%d\n", i, i + 1);
			// Calculer les coordonnes transposees du mur par rapport au joueur 
			get_translated_vertices(&render, env, sector, i);

			// Calculer les coordonnes tournees du mur par rapport au joueur 
			get_rotated_vertices(&render, env);

			// On continue que si au moins une des deux profondeurs est positive
			// (= mur devant le joueur)
			if (render.vz1 > 0 || render.vz2 > 0)
			{
				ft_printf("visible\n");
				// Calculer le cliping
				if(render.vz1 <= 0 || render.vz2 <= 0)
				{
					render.clipped = 1;
					t_v2	new_vz1;
					t_v2	new_vz2;
					render.near_z = 0.0005;
					render.far_z = 5;
					render.near_side = 0.00001;
					render.far_side = 20.f;

					//Find an intersection between the wall and the approximate edges of player's view
					get_intersection(&render, &new_vz1, 1);
					get_intersection(&render, &new_vz2, 2);
					if(render.vz1 < render.near_z)
					{
						if(new_vz1.y > 0)
						{
							render.vx1 = new_vz1.x;
							render.vz1 = new_vz1.y;
						}
						else
						{
							render.vx1 = new_vz2.x;
							render.vz1 = new_vz2.y;
						}
					}
					if(render.vz2 < render.near_z)
					{
						if(new_vz1.y > 0)
						{
							render.vx2 = new_vz1.x;
							render.vz2 = new_vz1.y;
						}
						else
						{
							render.vx2 = new_vz2.x;
							render.vz2 = new_vz2.y;
						}
					}
				}
				else
					render.clipped = 0;
				// Obtenir les coordoonees du sol et du plafond sur l'ecran
				project_floor_and_ceiling(&render, env, sector, i);
			/*	if ( render.x1 > render.x2)
				{
					temp = render.x1;
					render.x1 = render.x2;
					render.x2 = temp;
					temp = render.floor1;
					render.floor1 = render.floor2;
					render.floor2 = temp;
					temp = render.ceiling1;
					render.ceiling1 = render.ceiling2;
					render.ceiling2 = temp;
				}*/
				if (render.x1 < render.x2)
				{
					// Pareil pour le secteur voisin si c'est un portail
					if (sector.neighbors[i] >= 0 && sector.neighbors[i] != env->player.sector)
					{
						render.nv1 = get_vertex_nb_in_sector(sector.vertices[i], env->sectors[sector.neighbors[i]]);
						render.nv2 = get_vertex_nb_in_sector(sector.vertices[i + 1], env->sectors[sector.neighbors[i]]);
						//ft_printf("nv1 = %d, nv2 = %d\n", render.nv1, render.nv2);
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
						/*			if (render.neighbor_floor1 >= render.current_floor)
									new.ymax = render.current_floor;
									else
									new.ymax = render.neighbor_floor1;
									if (render.neighbor_ceiling1 >= render.current_ceiling)
									new.ymin = render.neighbor_ceiling1;
									else
									new.ymin = render.current_ceiling;*/
						new.father = sector.num;
						new.sector = sector.neighbors[i];
						render_sector(env, new, rendered_sectors, coucou + 1);
					}
					//ft_printf("xstart = %d xend = %d\n\n", x, xend);
					x = xstart;
					while (x <= xend)
					{
						render.currentx = x;
						// Lumiere
						render.light = 255 - ft_fclamp(((double)(x - render.x1) * (double)(render.vz2 - render.vz1) / (double)(render.x2 - render.x1) + (double)render.vz1) * 8.00, 0.00, 255.00);

						//	if (env->depth_array[x] > render.light)
						//		{
						//env->depth_array[x] = render.light;
						// Calculer y actuel du plafond et du sol
						render.current_ceiling = (x - render.x1) * (render.ceiling2 - render.ceiling1) / (render.x2 - render.x1) + render.ceiling1;
						//	ft_printf(" ceiling = %d ", render.current_ceiling);
						render.current_ceiling = ft_clamp(render.current_ceiling, render.ymin, render.ymax);
						render.current_floor = (x - render.x1) * (render.floor2 - render.floor1) / (render.x2 - render.x1) + render.floor1;
						render.current_floor = ft_clamp(render.current_floor, render.ymin, render.ymax);
						line.start = render.current_ceiling;
						line.end = render.current_floor;
						line.x = x;
						if (sector.neighbors[i] >= 0)
						{
							// Calculer y actuel du plafond et du sol du voisin
							render.current_neighbor_ceiling = (x - render.x1) * (render.neighbor_ceiling2 - render.neighbor_ceiling1) / (render.x2 - render.x1) + render.neighbor_ceiling1;
							render.current_neighbor_ceiling = ft_clamp(render.current_neighbor_ceiling, render.ymin, render.ymax);
							render.current_neighbor_floor = (x - render.x1) * (render.neighbor_floor2 - render.neighbor_floor1) / (render.x2 - render.x1) + render.neighbor_floor1;
							render.current_neighbor_floor = ft_clamp(render.current_neighbor_floor, render.ymin, render.ymax);
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
							//	ft_printf(" before %f %f |", env->depth_array[x], render.light);
							if (env->depth_array[x] < render.light)
							{
								// Dessiner le plafond de ymin jusqu'au plafond
								draw_ceiling(render, env);

								// Dessiner le sol du sol jusqu'a ymax
								draw_floor(render, env);
								/*		if (env->depth_array[x] != 2147483647)
										ft_printf("%d = %d, ", x, env->depth_array[x]);*/
								env->depth_array[x] = render.light;
								//ft_printf("| %d = %f %f |", x, env->depth_array[x], render.light);
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
/*								// Dessiner le plafond de ymin jusqu'au plafond
								draw_ceiling(render, env);

								// Dessiner le sol du sol jusqu'a ymax
								draw_floor(render, env);
*/								//}
							}
						}
						x++;
					}
				}
				else
					ft_printf("not visible\n");
			}
			i++;
		}
		ft_printf("\n");
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
	//ft_printf("{green}[New render]{reset} | [%d Sectors][%d Vertices]\n", env->nb_sectors, env->nb_vertices);
	render.xmin = 0;
	render.xmax = env->w - 1;
	render.ymin = 0;
	render.ymax = env->h - 1;
	render.father = -2;
	if (!(rendered_sectors = init_rendered_sector(env)))
		return (-1);
	render.sector = env->player.sector;
	// On commence par rendre le secteur courant
	render_sector(env, render, rendered_sectors, 0);
	ft_memdel((void**)&rendered_sectors);
	return (0);
}

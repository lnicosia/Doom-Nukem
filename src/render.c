/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaerhard <gaerhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 11:57:06 by lnicosia          #+#    #+#             */
/*   Updated: 2019/06/20 15:41:40 by lnicosia         ###   ########.fr       */
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
	//ft_printf("\n");
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
			get_rotated_vertices(&render, env, sector, i);

			project_floor_and_ceiling_preclip(&render, env, sector, i);
			render.v1_clipped = 0;
			render.v2_clipped = 0;
			render.wall_width = sector.wall_width[i] / 10;
			render.wall_height = (sector.ceiling - sector.floor) / 10;
			render.texture = sector.textures[i];
			render.floor_texture = sector.floor_texture;
			render.ceiling_texture = sector.ceiling_texture;
			render.i = i;
			// On continue uniquement si au moins un des deux vertex est dans le champ de vision
			if (check_fov(&render, env))
				//|| !env->options.clipping)
			{
				// Calculer le cliping
				clip_walls(&render, env);
				if (render.v1_clipped)
				{
					env->vertices[sector.vertices[i]].clipped_x[0] = (render.clipped_vx1) * env->player.angle_sin
						+ (render.clipped_vz1) * env->player.angle_cos;
					env->vertices[sector.vertices[i]].clipped_y[0] = (render.clipped_vx1) * -env->player.angle_cos
						+ (render.clipped_vz1) * env->player.angle_sin;
					env->vertices[sector.vertices[i]].clipped_x[0] += env->player.pos.x;
					env->vertices[sector.vertices[i]].clipped_y[0] += env->player.pos.y;
					env->vertices[sector.vertices[i]].clipped[0] = 1;
					line.p0.x = env->w - 150 + (env->vertices[sector.vertices[i]].clipped_x[0] - env->player.pos.x) * env->options.minimap_scale;
					line.p0.y = 150 + (env->vertices[sector.vertices[i]].clipped_y[0] - env->player.pos.y) * env->options.minimap_scale;
					if (sector.floor_slope)
						env->sectors[render.sector].clipped_floors1[i] = get_clipped_floor(0, sector, env->vertices[sector.vertices[i]], env); 
					if (sector.ceiling_slope)
						env->sectors[render.sector].clipped_ceilings1[i] = get_clipped_ceiling(0, sector, env->vertices[sector.vertices[i]], env); 
				}
				else
				{
					line.p0.x = env->w - 150 + (env->vertices[sector.vertices[i]].x - env->player.pos.x) * env->options.minimap_scale;
					line.p0.y = 150 + (env->vertices[sector.vertices[i]].y - env->player.pos.y) * env->options.minimap_scale;
					render.clipped_vz1 = render.vz1;
					render.clipped_vx1 = render.vx1;
				}
				if (render.v2_clipped)
				{
					env->vertices[sector.vertices[i + 1]].clipped_x[1] = (render.clipped_vx2) * env->player.angle_sin
						+ (render.clipped_vz2) * env->player.angle_cos;
					env->vertices[sector.vertices[i + 1]].clipped_y[1] = (render.clipped_vx2) * -env->player.angle_cos
						+ (render.clipped_vz2) * env->player.angle_sin;
					env->vertices[sector.vertices[i + 1]].clipped_x[1] += env->player.pos.x;
					env->vertices[sector.vertices[i + 1]].clipped_y[1] += env->player.pos.y;
					env->vertices[sector.vertices[i + 1]].clipped[1] = 1;
					line.p1.x = env->w - 150 + (env->vertices[sector.vertices[i + 1]].clipped_x[1] - env->player.pos.x) * env->options.minimap_scale;
					line.p1.y = 150 + (env->vertices[sector.vertices[i + 1]].clipped_y[1] - env->player.pos.y) * env->options.minimap_scale;
					if (sector.floor_slope)
						env->sectors[render.sector].clipped_floors2[i + 1] = get_clipped_floor(1, sector, env->vertices[sector.vertices[i + 1]], env); 
					if (sector.ceiling_slope)
						env->sectors[render.sector].clipped_ceilings2[i + 1] = get_clipped_ceiling(1, sector, env->vertices[sector.vertices[i + 1]], env); 
				}
				else
				{
					line.p1.x = env->w - 150 + (env->vertices[sector.vertices[i + 1]].x - env->player.pos.x) * env->options.minimap_scale;
					line.p1.y = 150 + (env->vertices[sector.vertices[i + 1]].y - env->player.pos.y) * env->options.minimap_scale;
					render.clipped_vz2 = render.vz2;
					render.clipped_vx2 = render.vx2;
				}
				if (env->options.test && env->player.pos.z > sector.floor_min && env->player.pos.z < sector.ceiling_max)
				{
					line.color = 0xFFFF0000;
					draw_line(line.p0, line.p1, *env, line.color);
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
						if (env->options.render_sectors)
						{
							t_render new = render;
							new.xmin = xstart;
							new.xmax = xend;
							new.sector = sector.neighbors[i];
							render_sector(env, new);
						}
					}
					x = xstart;
					while (x <= xend)
					{
						render.currentx = x;
						render.alpha = (x - render.preclip_x1) / (double)(render.preclip_x2 - render.preclip_x1);
						render.clipped_alpha = (x - render.x1) / (double)(render.x2 - render.x1);
						render.texel.x = ((1.0 - render.alpha) * env->vertices[sector.vertices[i]].x / render.vz1 + render.alpha * env->vertices[sector.vertices[i + 1]].x / render.vz2) / ((1.0 - render.alpha) / render.vz1 + render.alpha / render.vz2);
						render.texel.y = ((1.0 - render.alpha) * env->vertices[sector.vertices[i]].y / render.vz1 + render.alpha * env->vertices[sector.vertices[i + 1]].y / render.vz2) / ((1.0 - render.alpha) / render.vz1 + render.alpha / render.vz2);
						if (render.texel.y < 0 || render.texel.y > 35 || render.texel.x < 0 || render.texel.x > 35)
						{
							//ft_printf("texel = [%f][%f]\n", render.texel.y, render.texel.x);
							/*ft_printf("i = [%f][%f]\n", env->vertices[sector.vertices[i]].y, env->vertices[sector.vertices[i]].x);
							ft_printf("i + 1 = [%f][%f]\n", env->vertices[sector.vertices[i + 1]].y, env->vertices[sector.vertices[i + 1]].x);
							ft_printf("alpha = %f\n", render.alpha);*/
						}
						// Lumiere
						render.light = 255 - ft_fclamp(((x - render.x1) * (render.vz2 - render.vz1) / (render.x2 - render.x1) + render.vz1) * 2.00, 0.00, 255.00);
						// Calculer y actuel du plafond et du sol
						render.max_ceiling = (x - render.x1) * (render.ceiling2 - render.ceiling1) / (render.x2 - render.x1) + render.ceiling1;
						render.current_ceiling = ft_clamp(render.max_ceiling, render.ymin, render.ymax);
						render.max_floor = (x - render.x1) * (render.floor2 - render.floor1) / (render.x2 - render.x1) + render.floor1;
						render.current_floor = ft_clamp(render.max_floor, render.ymin, render.ymax);
						render.floor_horizon = (render.max_floor + render.max_ceiling) / 2.0;
						render.ceiling_horizon = (render.max_floor + render.max_ceiling) / 2.0;
						render.distfloor = ((env->h / 2.0) / (double)(render.max_floor - render.floor_horizon));
						render.distceiling = ((env->h / 2.0) / (double)(render.max_ceiling - render.ceiling_horizon));
						//render.distwall = (x - render.x1) * (render.vz2 - render.vz1) / (render.x2 - render.x1) + render.vz1;
						//ft_printf("distwall = %f\n", render.distwall);
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
								draw_vline_color(vline, render, env);
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
									vline.color = 0xFF0B6484;
								if (env->options.wall_color)
								{
									if (i == 0)
										vline.color = 0xFFAA0000;
									if (i == 1)
										vline.color = 0xFF00AA00;
									if (i == 2)
										line.color = 0xFF0000AA;
								}	
								if (env->options.lighting)
									vline.color = apply_light(vline.color, render.light);
								if (env->options.contouring && (x == render.x1 || x == render.x2))
									vline.color = 0xFF222222;
								//draw_vline_color(vline, render, env);
								draw_vline(vline, render, env);
								// Dessiner le plafond de ymin jusqu'au plafond
								draw_ceiling(render, env);
								// Dessiner le sol du sol jusqu'a ymax
								draw_floor(render, env);
							}
						}
						//Ligne noire pour separer les sols
						/*if (x == xstart)
						{
							vline.start = render.max_floor;
							vline.end = env->h - 1;
							vline.color = 0xFF;
							draw_vline(vline, render, env);
						}*/
						x++;
					}
				}
			}
			i++;
		}
		draw_sprites(env, &render);
		env->rendered_sectors[render.sector]--;
	}
}

static void		reset_render_utils(t_env *env)
{
	int	i;
	int	max;

	max = env->screen_sectors_size;
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

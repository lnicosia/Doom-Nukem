/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 11:57:06 by lnicosia          #+#    #+#             */
/*   Updated: 2019/04/14 20:27:35 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "utils.h"
#include "draw.h"

void	draw_line(t_line line, t_env *env)
{
	if (env->options.contouring)
	{
		env->sdl.img_str[line.x + env->w * line.start] = 0xFF;
		env->sdl.img_str[line.x + env->w * line.end] = 0xFF;
		line.start++;
		line.end--;
	}
	while (line.start <= line.end)
	{
		env->sdl.img_str[line.x + env->w * line.start] = line.color;
		line.start++;
	}
}

/*
 **	Draw the ceiling of the current wall
 */

void	draw_ceiling(int current_ceiling, t_render render,t_env *env)
{
	t_line	line;

	line.x = render.currentx;
	line.start = render.ymin;
	line.end = current_ceiling;
	line.color = 0x222222FF;
	if (env->options.lighting)
		line.color = (render.light / 5) << 24
			| (render.light / 5) << 16
			| (render.light / 5) << 8
			| 255;
	//ft_printf("floor end = %d\n", line.end);
	draw_line(line, env);
}

/*
 **	Draw the floor of the current wall
 */

void	draw_floor(int current_floor, t_render render,t_env *env)
{
	t_line	line;

	line.x = render.currentx;
	line.start = current_floor;
	line.end = render.ymax;
	line.color = 0x444444FF;
	if (env->options.lighting)
		line.color = (render.light / 3) << 24
			| (render.light / 3) << 16
			| (render.light / 3) << 8
			| 255;
	//ft_printf("ceiling start = %d\n", line.start);
	draw_line(line, env);
}

/*
 **	Draw the wall part of the current wall
 */

/*void	draw_wall(int current_floor, int render.light, t_line line,t_env *env)
  {
  render.line.color = 0x888888FF;
  if (env->options.render.lighting)
  render.line.color = render.light << 24 | render.light << 16 | render.light << 8 | 255;
  if (env->options.contouring && (x == x1 || x == x2))
  render.line.color = 0xFF;
  draw_line(render.line, env);
  }*/

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

void	render_sector(t_env *env, t_render render)
{
	int			i;
	t_sector	sector;
	t_line		line;
	int			x;
	int			xstart;
	int			xend;
	int			current_floor;
	int			current_ceiling;

	i = 0;
	sector = env->sector[render.sector];
	//ft_printf("Sector #%d\n%d vertices\n", sector.num, sector.nb_vertices);
	while (i < sector.nb_vertices)
	{
		//ft_printf("rendering wall %d\n", sector.vertices[i]);
		// Calculer les coordonnes transposees du mur par rapport au joueur 
		get_translated_vertices(&render, env, sector, i);

		// Calculer les coordonnes tournees du mur par rapport au joueur 
		get_rotated_vertices(&render, env);

		// On continue que si au moins une des deux profondeurs est positive
		// (= mur devant le joueur)
		if (render.vz1 > 0 || render.vz2 > 0)
		{
			// Obtenir les coordoonees du sol et du plafond sur l'ecran

			get_floor_and_ceiling_screen_coordinates(&render, env, sector);
			//ft_printf("x1 = %f x2 = %f\n", x1, x2);
			xstart = ft_max(render.x1, render.xmin);
			xend = ft_min(render.x2, render.xmax);
			//ft_printf("x = %d xend = %d\n\n", x, xend);
			//int floor_test = (x - x1) * (floor2 - floor1) / (x2 - x1) + floor1;
			x = xstart;
			while (x <= xend)
			{
				render.currentx = x;

				// Lumiere
				render.light = 255 - ft_clamp(((x - render.x1) * (render.vz2 - render.vz1) / (render.x2 - render.x1) + render.vz1) * 8, 0, 255);

				// Calculer y du plafond et du sol actuel
				current_ceiling = (x - render.x1) * (render.ceiling2 - render.ceiling1) / (render.x2 - render.x1) + render.ceiling1;
				current_ceiling = ft_clamp(current_ceiling, render.ymin, render.ymax);
				current_floor = (x - render.x1) * (render.floor2 - render.floor1) / (render.x2 - render.x1) + render.floor1;
				current_floor = ft_clamp(current_floor, render.ymin, render.ymax);

				// Dessiner le plafond de ymin jusqu'au plafond
				draw_ceiling(current_ceiling, render, env);

				// Dessiner le sol du sol jusqu'a ymax
				draw_floor(current_floor, render, env);

				// Dessiner le mur du plafond jusqu'au sol
				line.start = current_ceiling;
				line.end = current_floor;
				line.x = x;
				if (sector.neighbors[i] >= 0 && !env->options.render_sectors)
				{
					//ft_printf("[NEIGHBOR]\nRendering sector #%d\n", sector.neighbors[i]);
					line.color = 0xAA0000FF;
					if (env->options.lighting)
						line.color = render.light << 24 | 255;
					draw_line(line, env);
				}
				else
				{
					line.color = 0x888888FF;
					if (env->options.lighting)
						line.color = render.light << 24 | render.light << 16 | render.light << 8 | 255;
					if (env->options.contouring && (x == render.x1 || x == render.x2))
						line.color = 0xFF;
					draw_line(line, env);
				}
				x++;
			}
			if (sector.neighbors[i] >= 0 && sector.neighbors[i] != render.father && env->options.render_sectors)
			{
				// TODO array de ymin et ymax pour delimiter la hauteur du prochain secteur
				t_render new = render;
				new.xmin = xstart;
				new.xmax = xend;
				new.father = sector.num;
				new.sector = sector.neighbors[i];
				render_sector(env, new);
			}
		}
		i++;
	}
}

void	draw(t_env *env)
{
	t_render	render;
	int			i;

	i = 0;
	render.xmin = 0;
	render.xmax = env->w - 1;
	render.ymin = 0;
	render.ymax = env->h - 1;
	render.father = -2;
	render.sector = env->player.sector;
	// On commence par rendre le secteur courant
	render_sector(env, render);
}

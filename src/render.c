/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 11:57:06 by lnicosia          #+#    #+#             */
/*   Updated: 2019/04/15 11:47:05 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "utils.h"
#include "render.h"

void	render_sector(t_env *env, t_render render)
{
	int			i;
	t_sector	sector;
	t_line		line;
	int			x;
	int			xstart;
	int			xend;

	i = 0;
	//ft_printf("rendering sector #%d\n", render.sector);
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
		if (render.vz1 > 0 && render.vz2 > 0)
		{
			// Obtenir les coordoonees du sol et du plafond sur l'ecran

			get_floor_and_ceiling_screen_coordinates(&render, env, sector);
			if (sector.neighbors[i] >= 0)
				get_neighbor_floor_and_ceiling_screen_coordinates(&render, env, env->sector[sector.neighbors[i]]);
			xstart = ft_max(render.x1, render.xmin);
			xend = ft_min(render.x2, render.xmax);
			//ft_printf("xstart = %d xend = %d\n\n", x, xend);
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
					if (render.current_neighbor_ceiling > render.current_ceiling)
						draw_upper_wall(render, env);
					if (render.current_neighbor_floor < render.current_floor)
						draw_bottom_wall(render, env);
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

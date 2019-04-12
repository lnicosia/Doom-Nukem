/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 11:57:06 by lnicosia          #+#    #+#             */
/*   Updated: 2019/04/12 17:28:48 by lnicosia         ###   ########.fr       */
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

void	render_sector(t_env *env, t_render render)
{
	int			i;
	t_line		line;
	t_sector	sector;
	t_v2		v1;
	t_v2		v2;
	double		x1;
	double		x2;
	double		z1;
	double		z2;
	int			y_floor1;
	int			y_floor2;
	int			y_ceiling1;
	int			y_ceiling2;
	int			xstart;
	int			xend;
	int			floor_start;
	int			ceiling_end;

	(void)render;
	i = 0;
	sector = env->sector[env->player.sector];
	ft_printf("Sector #%d\n%d vertices\n", sector.num, sector.nb_vertices);
	while (i < sector.nb_vertices)
	{
		// Calculer 
		// 		Vertex 1
		v1.x = env->vertices[sector.vertices[i]].x - env->player.pos.x;
		v1.y = env->vertices[sector.vertices[i]].y - env->player.pos.y;
		//		Vertex 2
		v2.x = env->vertices[sector.vertices[i + 1]].x - env->player.pos.x;
		v2.y = env->vertices[sector.vertices[i + 1]].y - env->player.pos.y;
		ft_printf("v1 = %d\n", sector.vertices[i]);
		ft_printf("v1.x = %f\n", v1.x);
		ft_printf("v1.y = %f\n", v1.y);
		ft_printf("v2 = %d\n", sector.vertices[i + 1]);
		ft_printf("v2.x = %f\n", v2.x);
		ft_printf("v2.y = %f\n", v2.y);


		// Calculer la distance entre les murs et le joueur
		z1 = v1.x * env->player.angle_cos + v1.y * env->player.angle_sin;
		z2 = v2.x * env->player.angle_cos + v2.y * env->player.angle_sin;
		// Calculer la position des murs par rapport au joueur
		x1 = v1.x * env->player.angle_sin - v1.y * env->player.angle_cos;
		x2 = v2.x * env->player.angle_sin - v2.y * env->player.angle_cos;

		ft_printf("\nz1 = %f\n", z1);
		ft_printf("z2 = %f\n", z2);
		ft_printf("x1 = %f\n", x1);
		ft_printf("x2 = %f\n", x2);
		// On continue que si au moins une des deux profondeurs est positive
		// (= mur devant le joueur)
		if (z1 > 0 && z2 > 0)
		{
			/*if (z1 <= 0)
			{
				double tmp;
				tmp = z1;
				z1 = z2;
				z2 = tmp;
			}
			if (z2 <= 0)
			{
				double tmp;
				tmp = z2;
				z2 = z1;
				z1 = tmp;
			}*/
			// Convertir plafond et sol en screen coordinates
			y_floor1 = env->h / 2 - (int)((sector.floor - env->player.pos.z + z1 * env->player.angle_z) * ((VFOV * env->h) / z1));
			y_floor2 = env->h / 2 - (int)((sector.floor - env->player.pos.z + z2 * env->player.angle_z) * ((VFOV * env->h) / z2));
			y_ceiling1 = env->h / 2 - (int)((sector.ceiling - env->player.pos.z + z1 * env->player.angle_z) * ((VFOV * env->h) / z1));
			y_ceiling2 = env->h / 2 - (int)((sector.ceiling - env->player.pos.z + z2 * env->player.angle_z) * ((VFOV * env->h) / z2));
			x1 = (int)(env->w / 2 - x1 * ((HFOV * env->h) / z1));
			x2 = (int)(env->w / 2 - x2 * ((HFOV * env->h) / z2));
			//ft_printf("x1 = %f x2 = %f\n", x1, x2);
			xstart = ft_max(x1, render.x1);
			xend = ft_min(x2, render.x2);
			ft_printf("xstart = %d xend = %d\n\n", xstart, xend);
			//int floor_test = (xstart - x1) * (floor2 - floor1) / (x2 - x1) + floor1;
			while (xstart <= xend)
			{
				line.x = xstart;
				ceiling_end = (xstart - x1) * (y_ceiling2 - y_ceiling1) / (x2 - x1) + y_ceiling1;
				ceiling_end = ft_clamp(ceiling_end, 0, env->h - 1);
				floor_start = (xstart - x1) * (y_floor2 - y_floor1) / (x2 - x1) + y_floor1;
				floor_start = ft_clamp(floor_start, 0, env->h - 1);

				// Protection
				/*if (z1 <= 0)
					ceiling_end = 0;
				if (z2 <= 0)
					floor_start = env->h - 1;*/

				// Dessiner plafond
				line.start = 0;
				line.end = ceiling_end;
				line.color = 0x222222FF;
				//ft_printf("floor end = %d\n", line.end);
				draw_line(line, env);

				// Dessiner sol
				line.start = floor_start;
				line.end = env->h - 1;
				line.color = 0x444444FF;
				//ft_printf("ceiling start = %d\n", line.start);
				draw_line(line, env);

				// Dessiner mur
				line.start = ceiling_end;
				line.end = floor_start;
				line.color = 0x888888FF;
				if (env->options.contouring && (xstart == x1 || xstart == x2))
					line.color = 0xFF;
				draw_line(line, env);
				xstart++;
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
	render.x1 = 0;
	render.x2 = env->w - 1;
	ft_printf("player cos = %f\nplayer sin = %f\n", env->player.angle_cos, env->player.angle_sin);
	// On commence par rendre le secteur courant
	render_sector(env, render);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 11:57:06 by lnicosia          #+#    #+#             */
/*   Updated: 2019/04/11 12:40:22 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "draw.h"

void	draw_line(t_line line, t_env *env)
{
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
	t_v2		scale1;
	t_v2		scale2;
	int			floor1;
	int			floor2;
	int			ceiling1;
	int			ceiling2;

	(void)render;
	i = 0;
	sector = env->sector[env->player.sector];
	while (i < sector.nb_vertices - 1)
	{
		// Calculer 
		// 		Vertex 1
		v1.x = env->vertices[sector.vertices[i]].x - env->player.pos.x;
		v1.y = env->vertices[sector.vertices[i]].y - env->player.pos.y;
		//		Vertex 2
		v2.x = env->vertices[sector.vertices[i + 1]].x - env->player.pos.x;
		v2.y = env->vertices[sector.vertices[i + 1]].y - env->player.pos.y;
		
		
		// Calculer la distance entre les murs et le joueur
		z1 = v1.x * env->player.dir.x + v1.y * env->player.dir.y;
		z2 = v2.x * env->player.dir.x + v2.y * env->player.dir.y;
		// Calculer la position des murs par rapport au joueur
		x1 = v1.x * env->player.dir.y - v1.y * env->player.dir.x;
		x2 = v2.x * env->player.dir.y - v2.y * env->player.dir.x;
		
		// On continue que si au moins une des deux profondeurs est positive
		// (= mur devant le joueur)
		if (z1 > 0 && z2 > 0)
		{
			scale1.x = HFOV / z1;
			scale2.x = HFOV / z2;
			scale1.y = VFOV / z1;
			scale2.y = VFOV / z2;
			floor1 = env->h / 2 - sector.floor * VFOV / z1;
			ceiling1 = env->h / 2 - sector.ceiling * VFOV / z1;
			floor2 = env->h / 2 - sector.floor * VFOV / z2;
			ceiling2 = env->h / 2 - sector.ceiling * VFOV / z2;
			x1 = env->w / 2 - x1 * HFOV / z1;
			x2 = env->w / 2 - x2 * HFOV / z2;
			render.x1 = ft_max(x1, render.x1);
			render.x2 = ft_min(x2, render.x2);
			while (render.x1 < render.x2)
			{
				line.x = render.x1;
				line.start = 0;
				line.end = (render.x1 - x1) * (floor2 - floor1) / (x2 - x1) + floor1;
				line.color = 0xFF0000FF;
				draw_line(line, env);
				line.start = (render.x1 - x1) * (ceiling2 - ceiling1) / (x2 - x1) + ceiling1;
				line.end = env->h;
				line.color = 0xFFFF00FF;
				draw_line(line, env);
				render.x1++;
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
	ft_printf("Draw\n");
	// On commence par rendre le secteur courant
	render_sector(env, render);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 11:57:06 by lnicosia          #+#    #+#             */
/*   Updated: 2019/04/10 18:10:00 by lnicosia         ###   ########.fr       */
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
	int	i;
	t_line		line;
	t_sector	sector;
	t_v2		v1;
	t_v2		v2;
	double		z1;
	double		z2;

	(void)line;
	(void)render;
	i = 0;
	sector = env->sector[env->player.sector];
	while (i < sector.nb_vertices - 1)
	{
		/*
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
		
		// On continue que si au moins une des deux profondeurs est positive
		// (= mur devant le joueur)
		if (z1 > 0 || z2 > 0)
		{
		}

		*/
		i++;
	}
}

void	draw(t_env *env)
{
	t_render	render;
	int			i;

	i = 0;
	render.x1 = 0;
	render.x2 = env->w;
	// On commence par rendre le secteur courant
	render_sector(env, render);
}

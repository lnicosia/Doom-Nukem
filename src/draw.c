/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 11:57:06 by lnicosia          #+#    #+#             */
/*   Updated: 2019/04/09 18:02:13 by lnicosia         ###   ########.fr       */
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
	t_sector	current;

	(void)line;
	i = 0;
	current = env->sectors[render.num];
	while (i < current.nb_vertices)
	{
		// Deux options:
		// 		-bisqwit way: calculer tous les murs
		// 		-raycasting?

		// tracer plafond
		// tracer sol
		// tracer mur
		// if (voisin)
		// 		if (plus haut) tracer marche
		// 		if (plus bas) tracer corniche
		// 		rendre secteur voisin
		i++;
	}
}

void	draw(t_env *env)
{
	t_render	render;
	int			i;

	map_brute(env);
	i = 0;
	render.num = env->player.sector;
	render.x1 = 0;
	render.x2 = env->w;
	// On commence par rendre le secteur courant
	render_sector(env, render);
}

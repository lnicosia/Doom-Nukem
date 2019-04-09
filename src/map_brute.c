/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_brute.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 13:47:54 by lnicosia          #+#    #+#             */
/*   Updated: 2019/04/09 14:20:03 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	map_brute(t_env *env)
{
	env->sectors = (t_sector*)malloc(sizeof(t_sector));
	env->vertices = (t_vertex*)malloc(sizeof(t_vertex));
	env->vertices[0].x = 0;
	env->vertices[0].y = 0;
	env->vertices[0].num = 0;
	env->vertices[1].x = 15;
	env->vertices[1].y = 0;
	env->vertices[1].num = 1;
	env->vertices[2].x = 0;
	env->vertices[2].y = 15;
	env->vertices[2].num = 2;
	env->vertices[3].x = 15;
	env->vertices[3].y = 15;
	env->vertices[3].num = 3;
	env->sectors[0].floor = 0;
	env->sectors[0].ceiling = 20;
	env->sectors[0].num = 0;
	env->sectors[0].nbvertices = 4;
	env->sectors[0].vertices = (short*)malloc(sizeof(short) * 4);
	env->sectors[0].vertices[0] = 0;
	env->sectors[0].vertices[1] = 1;
	env->sectors[0].vertices[2] = 2;
	env->sectors[0].vertices[3] = 3;
	env->sectors[0].neighbors = (short*)malloc(sizeof(short) * 4);
	env->sectors[0].neighbors[0] = -1;
	env->sectors[0].neighbors[1] = -1;
	env->sectors[0].neighbors[2] = -1;
	env->sectors[0].neighbors[3] = -1;
	env->player.pos.x = 1;
	env->player.pos.y = 1;
	env->player.angle = 0;
	env->player.sector = 0;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 17:57:06 by lnicosia          #+#    #+#             */
/*   Updated: 2019/04/04 14:34:19 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	init_map(t_env *env)
{
	t_map		map;
	t_sector	sectors[2];

	/*walls[0].x = 0;
	walls[0].y = 0;
	walls[0].num = 0;
	walls[0].next_wall = 1;
	walls[0].next_sector = -1;*/
	sectors[0].walls = (t_v2*)malloc(sizeof(t_v2) * 4);
	sectors[0].neighbors = (short*)malloc(sizeof(short) * 4);
	sectors[0].num = 0;
	sectors[0].floor = 0;
	sectors[0].floor = 1;
	sectors[0].walls[0].y = 0;
	sectors[0].walls[0].x = 0;
	sectors[0].neighbors[0] = -1;
	sectors[0].walls[1].y = 0;
	sectors[0].walls[1].x = 1;
	sectors[0].neighbors[1] = -1;
	sectors[0].walls[2].y = 1;
	sectors[0].walls[2].x = 1;
	sectors[0].neighbors[2] = 1;
	sectors[0].walls[3].y = 1;
	sectors[0].walls[3].x = 0;
	sectors[0].neighbors[3] = -1;
	sectors[0].nbwalls = 4;

	sectors[1].walls = (t_v2*)malloc(sizeof(t_v2) * 4);
	sectors[1].neighbors = (short*)malloc(sizeof(short) * 4);
	sectors[1].num = 1;
	sectors[1].floor = 0.2;
	sectors[1].floor = 0.8;
	sectors[1].walls[0].y = 0;
	sectors[1].walls[0].x = 1;
	sectors[1].neighbors[0] = -1;
	sectors[1].walls[1].y = 0;
	sectors[1].walls[1].x = 2;
	sectors[1].neighbors[1] = -1;
	sectors[1].walls[2].y = 1;
	sectors[1].walls[2].x = 2;
	sectors[1].neighbors[2] = -1;
	sectors[1].walls[3].y = 1;
	sectors[1].walls[3].x = 1;
	sectors[1].neighbors[3] = 0;
	sectors[1].nbwalls = 4;

	map.sectors = sectors;
	env->map = map;
}

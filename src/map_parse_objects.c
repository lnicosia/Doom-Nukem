/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parse_objects.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/20 13:51:46 by lnicosia          #+#    #+#             */
/*   Updated: 2019/06/26 13:36:56 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "map_parser.h"

int			parse_objects(t_env *env, t_map_parser *parser)
{
	(void)parser;
	env->nb_objects = 2;
	env->objects = (t_object*)malloc(sizeof(t_object) * 2);
	env->objects[0].oriented = 0;
	env->objects[0].sprite = 28;
	env->objects[0].reversed[0] = 0;
	env->objects[0].pickable = 0;
	env->objects[0].solid = 0;
	env->objects[0].pos.x = 5;
	env->objects[0].pos.y = 5;
	env->objects[0].pos.z = 0;
	env->objects[0].start[0].x = 511;
	env->objects[0].start[0].y = 78;
	env->objects[0].end[0].x = 562;
	env->objects[0].end[0].y = 102;
	env->objects[0].size[0].x = 51;
	env->objects[0].size[0].y = 24;
	env->objects[0].width = 2;
	env->objects[0].height = 2;
	env->objects[0].scale = 60;
	env->objects[0].sector = 0;
	env->objects[0].drawn = 0;

	// Sprite oriente
	env->objects[1].oriented = 1;
	env->objects[1].sprite = 29;
	env->objects[1].pickable = 0;
	env->objects[1].solid = 0;
	env->objects[1].pos.x = 20;
	env->objects[1].pos.y = 10;
	env->objects[1].pos.z = 6;
	env->objects[1].width = 2;
	env->objects[1].height = 2;
	env->objects[1].scale = 60;
	env->objects[1].sector = 0;
	env->objects[1].drawn = 0;
	env->objects[1].angle = -90;

	env->objects[1].start[0].x = 44;
	env->objects[1].start[0].y = 120;
	env->objects[1].end[0].x = 87;
	env->objects[1].end[0].y = 165;
	env->objects[1].size[0].x = 44;
	env->objects[1].size[0].y = 46;
	env->objects[1].reversed[0] = 0;

	env->objects[1].start[1].x = 374;
	env->objects[1].start[1].y = 120;
	env->objects[1].end[1].x = 405;
	env->objects[1].end[1].y = 172;
	env->objects[1].size[1].x = 32;
	env->objects[1].size[1].y = 53;
	env->objects[1].reversed[1] = 0;

	env->objects[1].start[2].x = 299;
	env->objects[1].start[2].y = 120;
	env->objects[1].end[2].x = 329;
	env->objects[1].end[2].y = 173;
	env->objects[1].size[2].x = 31;
	env->objects[1].size[2].y = 54;
	env->objects[1].reversed[2] = 0;

	env->objects[1].start[3].x = 220;
	env->objects[1].start[3].y = 120;
	env->objects[1].end[3].x = 254;
	env->objects[1].end[3].y = 171;
	env->objects[1].size[3].x = 35;
	env->objects[1].size[3].y = 52;
	env->objects[1].reversed[3] = 0;

	env->objects[1].start[4].x = 132;
	env->objects[1].start[4].y = 120;
	env->objects[1].end[4].x = 175;
	env->objects[1].end[4].y = 165;
	env->objects[1].size[4].x = 44;
	env->objects[1].size[4].y = 46;
	env->objects[1].reversed[4] = 0;

	env->objects[1].start[5].x = 220;
	env->objects[1].start[5].y = 120;
	env->objects[1].end[5].x = 254;
	env->objects[1].end[5].y = 171;
	env->objects[1].size[5].x = 35;
	env->objects[1].size[5].y = 52;
	env->objects[1].reversed[5] = 1;

	env->objects[1].start[6].x = 299;
	env->objects[1].start[6].y = 120;
	env->objects[1].end[6].x = 329;
	env->objects[1].end[6].y = 173;
	env->objects[1].size[6].x = 31;
	env->objects[1].size[6].y = 54;
	env->objects[1].reversed[6] = 1;

	env->objects[1].start[7].x = 374;
	env->objects[1].start[7].y = 120;
	env->objects[1].end[7].x = 405;
	env->objects[1].end[7].y = 172;
	env->objects[1].size[7].x = 32;
	env->objects[1].size[7].y = 53;
	env->objects[1].reversed[7] = 1;
	return (0);
}

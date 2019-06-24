/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parse_objects.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/20 13:51:46 by lnicosia          #+#    #+#             */
/*   Updated: 2019/06/24 12:10:23 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "map_parser.h"

int			parse_objects(t_env *env, t_map_parser *parser)
{
	(void)parser;
	env->nb_objects = 1;
	env->objects = (t_object*)malloc(sizeof(t_object));
	env->objects[0].oriented = 0;
	env->objects[0].sprites[0] = 28;
	env->objects[0].pickable = 0;
	env->objects[0].solid = 0;
	env->objects[0].pos.x = 5;
	env->objects[0].pos.y = 5;
	env->objects[0].pos.z = 0;
	env->objects[0].start.x = 511;
	env->objects[0].start.y = 78;
	env->objects[0].end.x = 562;
	env->objects[0].end.y = 102;
	env->objects[0].size.x = 51;
	env->objects[0].size.y = 24;
	env->objects[0].width = 2;
	env->objects[0].height = 2;
	env->objects[0].scale = 60;
	env->objects[0].sector = 0;
	env->objects[0].drawn = 0;
	return (0);
}

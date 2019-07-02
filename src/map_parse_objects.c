/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parse_objects.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/20 13:51:46 by lnicosia          #+#    #+#             */
/*   Updated: 2019/07/02 11:03:43 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "map_parser.h"

int			parse_objects(t_env *env, t_map_parser *parser)
{
	(void)parser;
	env->nb_objects = 3;
	env->objects = (t_object*)malloc(sizeof(t_object) * env->nb_objects);
	env->objects[0].sprite = 0;
	env->objects[0].pickable = 0;
	env->objects[0].solid = 0;
	env->objects[0].pos.x = 5;
	env->objects[0].pos.y = 5;
	env->objects[0].pos.z = 0;
	env->objects[0].scale = 60;
	env->objects[0].sector = 0;

	env->objects[1].sprite = 1;
	env->objects[1].pickable = 0;
	env->objects[1].solid = 0;
	env->objects[1].pos.x = 20;
	env->objects[1].pos.y = 10;
	env->objects[1].pos.z = 6;
	env->objects[1].scale = 60;
	env->objects[1].sector = 0;
	env->objects[1].angle = 90;

	env->objects[2].sprite = 1;
	env->objects[2].pickable = 0;
	env->objects[2].solid = 0;
	env->objects[2].pos.x = 10;
	env->objects[2].pos.y = 20;
	env->objects[2].pos.z = 6;
	env->objects[2].scale = 60;
	env->objects[2].sector = 0;
	env->objects[2].angle = -90;

	/*env->objects[0].sprite = 0;
	env->objects[0].pickable = 0;
	env->objects[0].solid = 0;
	env->objects[0].pos.x = 17.5;
	env->objects[0].pos.y = -2;
	env->objects[0].pos.z = 6;
	env->objects[0].scale = 60;
	env->objects[0].sector = 0;
	env->objects[0].angle = -90;*/
	return (0);
}

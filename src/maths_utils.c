/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maths_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaerhard <gaerhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/07 12:13:32 by lnicosia          #+#    #+#             */
/*   Updated: 2019/09/23 17:13:13 by sipatry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "render.h"

void	update_player_z(t_env *env)
{
	t_sector	sector;
	t_vertex	v0;

	env->player.state.walk = 1;
	sector = env->sectors[env->player.highest_sect];
	v0 = env->vertices[sector.vertices[0]];
	env->player.pos.z =
		sector.floor +
		(sector.normal.x * (env->player.pos.x - v0.x)
		 - sector.normal.y * (env->player.pos.y - v0.y)) * sector.floor_slope;
	env->player.head_z = env->player.pos.z + env->player.eyesight;
	env->player.camera.pos.z = env->player.head_z;
}

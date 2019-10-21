/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_player_z.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipatry <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 13:58:03 by sipatry           #+#    #+#             */
/*   Updated: 2019/10/21 14:35:05 by sipatry          ###   ########.fr       */
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

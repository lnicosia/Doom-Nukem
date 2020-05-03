/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_player_z.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/07 12:13:32 by lnicosia          #+#    #+#             */
/*   Updated: 2020/05/01 11:37:06 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

void	update_player_z_flying(t_env *env)
{
	t_sector	*sector;

	env->player.state.walk = 1;
	sector = &env->sectors[env->player.highest_sect];
	if (get_floor_at_pos(sector, env->player.pos, env) > env->player.pos.z
		&& get_ceiling_at_pos(sector, env->player.pos, env) >
		env->player.pos.z + env->player.eyesight + 1)
	{
		env->player.pos.z = get_floor_at_pos(sector, env->player.pos, env);
	}
	else if (get_ceiling_at_pos(sector, env->player.pos, env) <
	env->player.pos.z + env->player.eyesight + 1)
	{
		env->player.pos.z = get_ceiling_at_pos(sector, env->player.pos, env)
		- env->player.eyesight - 1;
	}
	env->player.head_z = env->player.pos.z + env->player.eyesight;
	env->player.camera.pos.z = env->player.head_z;
}

void	update_player_z(t_env *env)
{
	t_sector	*sector;

	if (!env->player.state.fly)
	{
		env->player.state.walk = 1;
		sector = &env->sectors[env->player.highest_sect];
		env->player.pos.z = get_floor_at_pos(sector, env->player.pos, env);
		env->player.head_z = env->player.pos.z + env->player.eyesight;
		env->player.camera.pos.z = env->player.head_z;
	}
	else
	{
		update_player_z_flying(env);
	}
}

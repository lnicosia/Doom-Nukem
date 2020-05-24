/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_player_z.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/07 12:13:32 by lnicosia          #+#    #+#             */
/*   Updated: 2020/05/20 13:28:22 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

void	update_player_z_flying(t_env *env)
{
	t_sector	*sector;
	double		floor;
	double		ceiling;

	env->player.state.walk = 1;
	sector = &env->sectors[env->player.highest_sect];
	floor = get_floor_at_pos(sector, env->player.pos, env);
	ceiling = get_ceiling_at_pos(sector, env->player.pos, env);
	if (floor > env->player.pos.z && ceiling >
		env->player.pos.z + env->player.eyesight + 1)
		env->player.pos.z = floor;
	else if (ceiling - floor >= env->player.eyesight + 1
		&& ceiling < env->player.pos.z + env->player.eyesight + 1)
		env->player.pos.z = get_ceiling_at_pos(sector, env->player.pos, env)
		- env->player.eyesight - 1;
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

void	update_start_player_z(t_env *env)
{
	env->player.starting_pos.z = get_floor_at_pos(&env->sectors[
	get_sector_no_z(env, env->player.starting_pos)], env->player.starting_pos,
	env);
}

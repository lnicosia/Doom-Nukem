/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_player_z.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/07 12:13:32 by lnicosia          #+#    #+#             */
/*   Updated: 2020/05/13 14:21:46 by marvin           ###   ########.fr       */
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
		env->player.pos.z = get_floor_at_pos(sector, env->player.pos, env);
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
	//int			old_z;

//	old_z = 0;
	if (!env->player.state.fly)
	{
		env->player.state.walk = 1;
	//	old_z = env->player.pos.z;
		sector = &env->sectors[env->player.highest_sect];
		env->player.pos.z = get_floor_at_pos(sector, env->player.pos, env);
	/*	if (env->player.pos.z < old_z - 1)
		{
			ft_printf("old is too high\n");
			env->player.pos.z = old_z;
		}*/
		env->player.head_z = env->player.pos.z + env->player.eyesight;
		env->player.camera.pos.z = env->player.head_z;
	}
	else
	{
		update_player_z_flying(env);
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_selection.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/21 13:35:07 by lnicosia          #+#    #+#             */
/*   Updated: 2020/05/22 19:05:03 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "collision.h"

int		drop_player(t_env *env)
{
	env->editor.dragged_player = -1;
	env->player.sector = get_sector_no_z(env, env->player.pos);
	env->player.highest_sect = env->player.sector;
	if (env->player.sector == -1
		|| check_player_height(&env->sectors[env->player.sector], env))
	{
		env->player.pos.x = env->editor.start_pos.x;
		env->player.pos.y = env->editor.start_pos.y;
		if (update_confirmation_box(&env->confirmation_box,
			"The player does not fit at this pos", ERROR, env))
			return (-1);
	}
	if (env->player.highest_sect == -1 && env->player.sector != -1)
		env->player.highest_sect = env->player.sector;
	if (env->player.sector != -1)
	{
		update_player_pos(env);
		update_player_z(env);
	}
	return (0);
}

int		player_selection(t_env *env)
{
	if (env->inputs.left_click && env->editor.dragged_player == 1)
	{
		env->player.pos.x = (env->sdl.mx - env->editor.center.x)
		/ env->editor.scale;
		env->player.pos.y = (env->sdl.my - env->editor.center.y)
		/ env->editor.scale;
	}
	else
		return (drop_player(env));
	return (0);
}

int		drop_starting_player(t_env *env)
{
	env->editor.dragged_start_player = -1;
	env->player.starting_sector =
	get_sector_no_z_origin(env, env->player.starting_pos,
	env->player.starting_sector);
	if (env->player.starting_sector == -1 || check_start_player_height(
		&env->sectors[env->player.starting_sector], env))
	{
		env->player.starting_pos.x = env->editor.start_pos.x;
		env->player.starting_pos.y = env->editor.start_pos.y;
		if (update_confirmation_box(&env->confirmation_box,
			"The player does not fit at this pos", ERROR, env))
			return (-1);
	}
	if (env->player.starting_sector != -1)
		update_start_player_z(env);
	return (0);
}

int		starting_player_selection(t_env *env)
{
	if (env->inputs.left_click && env->editor.dragged_start_player == 1)
	{
		env->player.starting_pos.x = (env->sdl.mx - env->editor.center.x)
		/ env->editor.scale;
		env->player.starting_pos.y = (env->sdl.my - env->editor.center.y)
		/ env->editor.scale;
	}
	else
		return (drop_starting_player(env));
	return (0);
}

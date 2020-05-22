/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_selection.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipatry <sipatry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/21 13:35:07 by lnicosia          #+#    #+#             */
/*   Updated: 2020/02/27 16:07:11 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "collision.h"

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
	{
		env->editor.dragged_player = -1;
		env->player.sector = get_sector_no_z(env, env->player.pos);
		if (check_player_height(&env->sectors[env->player.sector], env))
		{
			env->player.pos.x = env->editor.start_pos.x;
			env->player.pos.y = env->editor.start_pos.y;
			if (update_confirmation_box(&env->confirmation_box,
				"The player does not fit at this pos", ERROR, env))
				return (-1);
		}
		if (env->player.sector != -1)
		{
			update_player_pos(env);
			update_player_z(env);
		}
	}
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
	{
		env->editor.dragged_start_player = -1;
		env->player.starting_sector =
		get_sector_no_z_origin(env, env->player.starting_pos,
		env->player.starting_sector);
		if (check_start_player_height(
			&env->sectors[env->player.starting_sector], env))
		{
			env->player.starting_pos.x = env->editor.start_pos.x;
			env->player.starting_pos.y = env->editor.start_pos.y;
			if (update_confirmation_box(&env->confirmation_box,
				"The player does not fit at this pos", ERROR, env))
				return (-1);
		}
		if (env->player.starting_sector != -1)
		{
			update_player_pos(env);
			update_start_player_z(env);
		}
	}
	return (0);
}

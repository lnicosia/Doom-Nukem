/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_selection.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipatry <sipatry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/21 13:35:07 by lnicosia          #+#    #+#             */
/*   Updated: 2020/02/04 19:52:31 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "collision.h"

void	player_selection(t_env *env)
{
	if (env->inputs.left_click && env->editor.dragged_player == 1)
	{
		env->player.pos.x = (env->sdl.mx - env->editor.center.x)
		/ env->editor.scale;
		env->player.pos.y = (env->sdl.my - env->editor.center.y)
		/ env->editor.scale;
		env->player.sector = get_sector_no_z_origin(env, env->player.pos,
		env->player.sector);
		if (env->player.sector != -1)
		{
			update_player_pos(env);
			update_player_z(env);
		}
	}
	else
		env->editor.dragged_player = -1;
}

void	starting_player_selection(t_env *env)
{
	if (env->inputs.left_click && env->editor.dragged_start_player == 1)
	{
		env->player.starting_pos.x = (env->sdl.mx - env->editor.center.x)
		/ env->editor.scale;
		env->player.starting_pos.y = (env->sdl.my - env->editor.center.y)
		/ env->editor.scale;
		env->player.starting_sector = get_sector_no_z_origin(env, env->player.starting_pos,
		env->player.starting_sector);
		if (env->player.starting_sector != -1)
		{
			update_player_pos(env);
			update_player_z(env);
		}
	}
	else
		env->editor.dragged_start_player = -1;
}

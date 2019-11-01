/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_selection.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaerhard <gaerhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/21 13:35:07 by lnicosia          #+#    #+#             */
/*   Updated: 2019/11/01 16:17:01 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

void	player_selection(t_env *env)
{
	if (env->inputs.left_click
			&& env->sdl.mx > 80
			&& env->sdl.mx < 120
			&& env->sdl.my > 80
			&& env->sdl.my < 120
			&& env->editor.start_vertex == -1
			&& env->editor.dragged_player == -1
			&& env->editor.dragged_vertex == -1
			&& env->editor.dragged_object == -1)
		env->editor.dragged_player = 1;
	if (!env->inputs.left_click && env->editor.dragged_player == 1)
	{
		env->editor.dragged_player = -1;
		if (env->sdl.mx > 200)
		{
			add_player(env);
			env->editor.new_player = 1;
		}
		else
			env->editor.new_player = 0;
	}
	if (env->editor.new_player && env->player.sector != -1)
		update_player_z(env);
	env->player.camera.pos.z = env->player.head_z;
}

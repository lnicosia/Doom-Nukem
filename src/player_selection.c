/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_selection.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipatry <sipatry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/21 13:35:07 by lnicosia          #+#    #+#             */
/*   Updated: 2019/10/30 15:18:46 by sipatry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "collision.h"

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
			&& env->editor.dragged_object == -1
			&& !env->teleport.create)
		env->editor.dragged_player = 1;
	if (!env->inputs.left_click && env->editor.dragged_player == 1)
	{
		env->editor.dragged_player = -1;
		if (env->sdl.mx > 200 && check_player_z(env))
		{
			add_player(env);
			env->editor.new_player = 1;
		}
		else
		{
			ft_printf("Couldn't add mew player\n");
			env->editor.new_player = 0;
		}
	}
}

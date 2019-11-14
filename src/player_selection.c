/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_selection.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipatry <sipatry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/21 13:35:07 by lnicosia          #+#    #+#             */
/*   Updated: 2019/11/14 11:54:27 by sipatry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "collision.h"

void	player_selection(t_env *env)
{
	if (env->inputs.left_click
			&& env->editor.start_vertex == -1
			&& env->editor.dragged_player == -1
			&& env->editor.dragged_vertex == -1
			&& env->editor.dragged_object == -1
			&& !env->teleport.create
			&& env->editor.selected_player != -1)
		env->editor.dragged_player = 1;
	if (!env->inputs.left_click && env->editor.dragged_player == 1)
	{
		env->editor.dragged_player = -1;
		if (env->sdl.mx > 200 && check_player_z(env))
			add_player(env);
		else
			ft_printf("Couldn't add new player\n");
	}
}

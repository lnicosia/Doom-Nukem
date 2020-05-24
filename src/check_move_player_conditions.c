/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_move_player_conditions.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/29 15:04:54 by lnicosia          #+#    #+#             */
/*   Updated: 2020/04/29 15:04:55 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

int		check_move_player_conditions(t_env *env)
{
	if ((((env->inputs.forward || env->inputs.backward || env->inputs.left
		|| env->inputs.right || env->inputs.space || env->jump.on_going == 1
		|| env->crouch.on_going || env->inputs.lgui)
		&& env->player.health > 0
		&& (((env->selected_enemy == -1 && env->editor.tab)
		|| (env->selected_enemy != -1 && !env->editor.tab))
		|| (env->selected_enemy == -1 && !env->editor.tab)))
		|| (env->player.state.climb || env->player.state.drop))
		&& !env->editor.tab)
		return (1);
	return (0);
}

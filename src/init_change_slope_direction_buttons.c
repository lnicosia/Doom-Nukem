/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_change_slope_direction_buttons.c              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/30 11:47:42 by lnicosia          #+#    #+#             */
/*   Updated: 2020/04/30 11:47:43 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

void	init_change_slope_direction_buttons(t_env *env)
{
	env->editor.next_slope_swap =
	new_next_button(WHEN_DOWN, &change_slope_direction, env, env);
	env->editor.next_slope_swap_env.env = env;
	env->editor.next_slope_swap.pos = new_point(315, 600);
	env->editor.next_slope_swap_env.button_type = NEXT;
	env->editor.previous_slope_swap =
	new_previous_button(WHEN_DOWN, &change_slope_direction, env, env);
	env->editor.previous_slope_swap_env.env = env;
	env->editor.previous_slope_swap.pos = new_point(60, 600);
	env->editor.previous_slope_swap_env.button_type = PREVIOUS;
}

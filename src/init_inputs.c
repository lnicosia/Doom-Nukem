/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_inputs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/30 12:02:14 by lnicosia          #+#    #+#             */
/*   Updated: 2020/04/30 12:02:14 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

void	init_inputs(t_env *env)
{
	env->inputs.forward = 0;
	env->inputs.backward = 0;
	env->inputs.s = 0;
	env->inputs.h = 0;
	env->inputs.left = 0;
	env->inputs.right = 0;
	env->inputs.plus = 0;
	env->inputs.minus = 0;
	env->inputs.shift = 0;
	env->inputs.ctrl = 0;
	env->inputs.space = 0;
	env->inputs.ctrl = 0;
	env->inputs.option = 0;
	env->inputs.left_click = 0;
	env->inputs.right_click = 0;
	env->inputs.enter = 0;
	env->inputs.up = 0;
	env->inputs.down = 0;
	env->inputs.tab = 0;
	env->inputs.nb1 = 0;
	env->inputs.nb2 = 0;
	env->inputs.nb3 = 0;
	env->inputs.nb4 = 0;
	env->inputs.nb5 = 0;
}

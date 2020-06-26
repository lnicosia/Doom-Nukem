/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inputs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/24 14:33:55 by lnicosia          #+#    #+#             */
/*   Updated: 2020/04/30 12:16:26 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

void	set_mouse_inputs(t_env *env, int mode)
{
	if (env->sdl.event.button.button == SDL_BUTTON_LEFT)
		env->inputs.left_click = mode;
	if (env->sdl.event.button.button == SDL_BUTTON_RIGHT)
		env->inputs.right_click = mode;
}

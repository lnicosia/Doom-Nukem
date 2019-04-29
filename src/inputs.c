/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inputs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/24 14:33:55 by lnicosia          #+#    #+#             */
/*   Updated: 2019/04/24 16:09:18 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	init_inputs(t_env *env)
{
	env->inputs.forward = 0;
	env->inputs.backward = 0;
	env->inputs.left = 0;
	env->inputs.right = 0;
}

void	set_inputs(t_env *env, int mode)
{
	if (env->sdl.event.key.keysym.sym == env->keys.forward
			|| env->sdl.event.key.keysym.sym == env->keys.forward2)
		env->inputs.forward = mode;
	if (env->sdl.event.key.keysym.sym == env->keys.backward
			|| env->sdl.event.key.keysym.sym == env->keys.backward2)
		env->inputs.backward = mode;
	if (env->sdl.event.key.keysym.sym == env->keys.left
			|| env->sdl.event.key.keysym.sym == env->keys.left2)
		env->inputs.left = mode;
	if (env->sdl.event.key.keysym.sym == env->keys.right
			|| env->sdl.event.key.keysym.sym == env->keys.right2)
		env->inputs.right = mode;
}

void	keys(t_env *env)
{
	if (env->sdl.event.type == SDL_KEYDOWN)
		set_inputs(env, 1);
	if (env->sdl.event.type == SDL_KEYUP)
	{
		set_inputs(env, 0);
		options(env);
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inputs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaerhard <gaerhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/24 14:33:55 by lnicosia          #+#    #+#             */
/*   Updated: 2019/09/03 14:19:06 by sipatry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

void	init_inputs(t_env *env)
{
	env->inputs.forward = 0;
	env->inputs.backward = 0;
	env->inputs.s = 0;
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
}

int		button_leftclick(t_env *env, int nb)
{
	int	xmax;
	int	ymax;

	if (env->button[nb].image == 30 || env->button[nb].image == 31)
	{
		xmax = env->button[nb].x + 40;
		ymax = env->button[nb].y + 40;
	}
	else
	{
		xmax = env->button[nb].x + 150;
		ymax = env->button[nb].y + 150;
	}
	if ((env->sdl.mx >= env->button[nb].x
		&& env->sdl.mx <= xmax)
		&& (env->sdl.my >=  env->button[nb].y
		&& env->sdl.my <= ymax))
		return (1);
	else
		return (0);
}

void	set_inputs(t_env *env, int mode)
{
	if (env->sdl.event.key.keysym.sym == env->keys.forward
			|| env->sdl.event.key.keysym.sym == env->keys.forward2)
		env->inputs.forward = mode;
	if (env->sdl.event.key.keysym.sym == env->keys.s
			|| env->sdl.event.key.keysym.sym == env->keys.backward2)
		env->inputs.backward = mode;
	if (env->sdl.event.key.keysym.sym == env->keys.left
			|| env->sdl.event.key.keysym.sym == env->keys.left2)
		env->inputs.left = mode;
	if (env->sdl.event.key.keysym.sym == env->keys.right
			|| env->sdl.event.key.keysym.sym == env->keys.right2)
		env->inputs.right = mode;
	if (env->sdl.event.key.keysym.sym == env->keys.plus)
		env->inputs.plus = mode;
	if (env->sdl.event.key.keysym.sym == env->keys.minus)
		env->inputs.minus = mode;
	if (env->sdl.event.key.keysym.sym == env->keys.shift)
		env->inputs.shift = mode;
	if (env->sdl.event.key.keysym.sym == env->keys.space)
		env->inputs.space = mode;
	if (env->sdl.event.key.keysym.sym == env->keys.ctrl)
		env->inputs.ctrl = mode;
	if (env->sdl.event.key.keysym.sym == env->keys.up)
		env->inputs.up = mode;
	if (env->sdl.event.key.keysym.sym == env->keys.down)
		env->inputs.down = mode;
	if (env->sdl.event.key.keysym.sym == env->keys.option)
		env->inputs.option = mode;	
	if (env->sdl.event.button.button == SDL_BUTTON_LEFT)
		env->inputs.left_click = mode;
	if (env->sdl.event.button.button == SDL_BUTTON_RIGHT)
		env->inputs.right_click = mode;
	if (env->sdl.event.key.keysym.sym == env->keys.enter)
		env->inputs.enter = mode;
	if (env->sdl.event.key.keysym.sym == env->keys.s)
		env->inputs.s = mode;
	if (env->sdl.event.key.keysym.sym == env->keys.backspace)
		env->inputs.backspace = mode;
	if (env->sdl.event.key.keysym.sym == env->keys.del)
		env->inputs.del = mode;

}

void	update_inputs(t_env *env)
{
	if (env->sdl.event.type == SDL_KEYDOWN)
		set_inputs(env, 1);
	if (env->sdl.event.type == SDL_KEYUP)
		set_inputs(env, 0);
	if (env->sdl.event.type == SDL_MOUSEBUTTONDOWN)
		set_inputs(env, 1);
	if (env->sdl.event.type == SDL_MOUSEBUTTONUP)
		set_inputs(env, 0);
}

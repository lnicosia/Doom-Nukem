/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inputs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipatry <sipatry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/24 14:33:55 by lnicosia          #+#    #+#             */
/*   Updated: 2020/02/19 11:29:25 by sipatry          ###   ########.fr       */
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
	env->inputs.nb1 = 0;
	env->inputs.nb2 = 0;
	env->inputs.nb3 = 0;
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
	if (env->sdl.event.key.keysym.sym == env->keys.shift
			|| env->sdl.event.key.keysym.sym == env->keys.shift2)
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
	if (env->sdl.event.key.keysym.sym == env->keys.comma)
		env->inputs.comma = mode;
	if (env->sdl.event.key.keysym.sym == env->keys.period)
		env->inputs.period = mode;
	if (env->sdl.event.key.keysym.sym == env->keys.minus1)
		env->inputs.minus1 = mode;
	if (env->sdl.event.key.keysym.sym == env->keys.equals)
		env->inputs.equals = mode;
	if (env->sdl.event.key.keysym.sym == env->keys.p)
		env->inputs.p = mode;
	if (env->sdl.event.key.keysym.sym == env->keys.e)
		env->inputs.e = mode;
	if (env->sdl.event.key.keysym.sym == env->keys.home)
		env->inputs.home = mode;
	if (env->sdl.event.key.keysym.sym == env->keys.end)
		env->inputs.end = mode;
	if (env->sdl.event.key.keysym.sym == env->keys.a)
		env->inputs.a = mode;
	if (env->sdl.event.key.keysym.sym == env->keys.lgui)
		env->inputs.lgui = mode;
	if (env->sdl.event.key.keysym.sym == env->keys.nb1)
		env->inputs.nb1 = mode;
	if (env->sdl.event.key.keysym.sym == env->keys.nb2)
		env->inputs.nb2 = mode;
	if (env->sdl.event.key.keysym.sym == env->keys.nb3)
		env->inputs.nb3 = mode;
	if (!env->editor.key_delay && mode)
		env->editor.start_key_delay = SDL_GetTicks() - 1;
	if (mode)
		env->editor.key_delay = SDL_GetTicks() - env->editor.start_key_delay;
	else if (env->editor.key_delay && !mode)
		env->editor.key_delay = 0;
	if (env->editor.key_delay < 200)
		env->editor.keyup_allowed = 1;
	else
		env->editor.keyup_allowed = 0;
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

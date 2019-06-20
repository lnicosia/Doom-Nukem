/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inputs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaerhard <gaerhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/24 14:33:55 by lnicosia          #+#    #+#             */
/*   Updated: 2019/06/14 14:39:14 by gaerhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	init_inputs(t_env *env)
{
	env->inputs.forward = 0;
	env->inputs.backward = 0;
	env->inputs.left = 0;
	env->inputs.right = 0;
	env->inputs.plus = 0;
	env->inputs.minus = 0;
	env->inputs.shift = 0;
	env->inputs.ctrl = 0;
	env->inputs.space = 0;
	env->inputs.ctrl = 0;
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
	if (env->sdl.event.key.keysym.sym == env->keys.plus)
		env->inputs.plus = mode;
	if (env->sdl.event.key.keysym.sym == env->keys.minus)
		env->inputs.minus = mode;
	if (env->sdl.event.key.keysym.sym == env->keys.shift)
		env->inputs.shift = mode;
	if (env->sdl.event.key.keysym.sym == env->keys.space)
	{
		env->inputs.space = mode;
	}
	if (env->sdl.event.key.keysym.sym == env->keys.ctrl)
		env->inputs.ctrl = mode;
	if (env->sdl.event.key.keysym.sym == env->keys.up)
		env->inputs.up = mode;
	if (env->sdl.event.key.keysym.sym == env->keys.down)
		env->inputs.down = mode;
	if (env->sdl.event.button.button == SDL_BUTTON_LEFT)
		env->inputs.leftclick = mode;
	if (env->sdl.event.button.button == SDL_BUTTON_RIGHT && mode == 1)
	{
		if (env->weapons[env->player.curr_weapon].ammo < env->weapons[env->player.curr_weapon].max_ammo)
			env->weapons[env->player.curr_weapon].ammo++;
	}
}

void	update_inputs(t_env *env)
{
	if (env->sdl.event.type == SDL_KEYDOWN)
		set_inputs(env, 1);
	if (env->sdl.event.type == SDL_KEYUP)
	{
		set_inputs(env, 0);
		options(env);
	}
	if (env->sdl.event.type == SDL_MOUSEBUTTONDOWN)
		set_inputs(env, 1);
 	if (env->sdl.event.type == SDL_MOUSEBUTTONUP)
		set_inputs(env, 0);
	if (env->sdl.event.type == SDL_MOUSEWHEEL && !env->weapon_change.on_going && !env->shot.on_going)
		weapon_change(env);
}

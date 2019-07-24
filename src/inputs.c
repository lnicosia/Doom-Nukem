/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inputs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaerhard <gaerhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/24 14:33:55 by lnicosia          #+#    #+#             */
/*   Updated: 2019/07/24 16:00:40 by sipatry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

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
	env->inputs.option = 0;
	env->inputs.left_click = 0;
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
		env->inputs.leftclick = mode;
	if (env->sdl.event.button.button == SDL_BUTTON_RIGHT)
		env->inputs.right_click = mode;

/*
 * * gestion menu option
 */

	if (env->sdl.event.button.button == SDL_BUTTON_LEFT && env->option)
	{
		env->inputs.left_click  = env->inputs.left_click ? 0 : 1;
		if (env->inputs.left_click
			&& button_leftclick(env, 2)
			&& env->i > 0)
			env->i--;
		else if (env->inputs.left_click
			&& button_leftclick(env, 3)
			&& env->i < 2)
			env->i++;
		else if (env->inputs.left_click
			&& button_leftclick(env, 4)
			&& env->sound.g_music > 5)
			env->sound.g_music -= 5;
		else if (env->inputs.left_click
			&& button_leftclick(env, 5)
			&& env->sound.g_music < 100)
			env->sound.g_music += 5;
		else if (env->inputs.left_click
			&& button_leftclick(env, 1))
			env->aplicate_changes = 1;
		else if (env->inputs.left_click
			&& button_leftclick(env, 7))
			env->menu_select = 1;
	}

/*
 * * gestion menu start
 */

	if (env->sdl.event.button.button == SDL_BUTTON_LEFT && env->menu_start)
	{	
		if (button_leftclick(env, 0))
		{
			env->menu_start = 0;
			SDL_SetRelativeMouseMode(1);
		}
	}

/*
 * * gestion menu select
 */

	if (env->sdl.event.button.button == SDL_BUTTON_LEFT && env->menu_select)
	{
		if (button_leftclick(env, 6))
			env->menu_select = 0;
		if (button_leftclick(env, 8))
		{
			env->menu_select = 0;
			env->menu_edit = 0;
			env->option = 0;
		}
		if (button_leftclick(env, 9))
		{
			env->menu_select = 0;
			env->menu_edit = 1;
		}
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
}

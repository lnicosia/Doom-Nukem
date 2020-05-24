/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_box_keys.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/30 12:14:57 by lnicosia          #+#    #+#             */
/*   Updated: 2020/04/30 16:36:11 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "input_box_utils.h"

int		input_box_keys4(t_input_box *box, t_env *env)
{
	if (env->sdl.event.key.keysym.sym == SDLK_RIGHT
		&& box->cursor <= ft_strlen(box->str) && SDL_GetTicks()
		- box->move_cursor_timer > box->move_cursor_delay)
	{
		if (box->select_start == box->select_end
			&& box->cursor < ft_strlen(box->str))
			box->cursor++;
		else
		{
			if (box->cursor < ft_strlen(box->str))
				box->cursor = ft_max(box->select_end, box->select_start);
			box->select_start = 0;
			box->select_end = 0;
		}
		box->move_cursor_timer = SDL_GetTicks();
	}
	else if (env->sdl.event.key.keysym.sym == SDLK_DOWN
		&& SDL_GetTicks() - box->move_cursor_timer > box->move_cursor_delay)
	{
		box->down = 1;
		box->select_start = 0;
		box->select_end = 0;
		box->move_cursor_timer = SDL_GetTicks();
	}
	return (input_box_keys5(box, env));
}

int		input_box_keys3(t_input_box *box, t_env *env)
{
	if (env->sdl.event.key.keysym.sym == SDLK_LEFT && box->cursor > 0
		&& SDL_GetTicks() - box->move_cursor_timer > box->move_cursor_delay)
	{
		if (box->select_start == box->select_end)
			box->cursor--;
		else
		{
			box->cursor = ft_min(box->select_end, box->select_start);
			box->select_start = 0;
			box->select_end = 0;
		}
		box->move_cursor_timer = SDL_GetTicks();
	}
	return (input_box_keys4(box, env));
}

int		input_box_keys2(t_input_box *box, t_env *env)
{
	if (env->inputs.del)
	{
		if (box->select_start != box->select_end
			&& (box->type != UINT32 || (box->select_start > 2
			&& box->select_end > 2)))
		{
			if (delete_box_selection(box))
				return (-1);
		}
		else if (SDL_GetTicks() - box->del_timer > box->del_delay
		&& box->cursor < ft_strlen(box->str)
		&& (box->str[box->cursor] != '.'
			|| box->float_count + box->int_count <= 9)
		&& (box->type != UINT32 || box->cursor > 1))
		{
			if (del_char(box, 1))
				return (-1);
		}
		env->inputs.del = 0;
	}
	return (input_box_keys3(box, env));
}

int		input_box_backspace(t_input_box *box, t_env *env)
{
	if (box->select_start != box->select_end && (box->type != UINT32
		|| (box->select_start > 2 && box->select_end > 2)))
	{
		if (delete_box_selection(box))
			return (-1);
	}
	else if (SDL_GetTicks() - box->del_timer > box->del_delay && box->
	cursor > 0 && (box->str[box->cursor - 1] != '.' || box->float_count
	+ box->int_count <= 9) && (box->type != UINT32 || box->cursor > 2))
	{
		if (del_char(box, 0))
			return (-1);
	}
	env->inputs.backspace = 0;
	return (0);
}

int		input_box_keys(t_input_box *box, t_env *env)
{
	int		res;

	if (env->inputs.enter || env->sdl.event.key.keysym.sym == SDLK_KP_ENTER)
	{
		if ((res = validate_input(box, env)) == -1)
			return (-1);
		else if (res == 1)
			return (0);
		env->inputs.enter = 0;
		env->editor.enter_locked = 1;
	}
	else if (env->inputs.backspace)
	{
		if (input_box_backspace(box, env))
			return (-1);
	}
	return (input_box_keys2(box, env));
}

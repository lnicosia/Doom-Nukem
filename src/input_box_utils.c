/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_box_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 10:29:15 by lnicosia          #+#    #+#             */
/*   Updated: 2020/03/10 11:46:21 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "input_box_utils.h"

/*
**	Delete a char at cursor position
**	If mode == 0, it's a backspace, delete the previous char
**	else if mode == 1, it's a del, delete the next char
*/

int		del_char(t_input_box *box, int mode)
{
	char	*s1;
	char	*s2;
	char	*res;

	box->del_timer = SDL_GetTicks();
	if (!mode)
	{
		s1 = ft_strsub(box->str, 0, box->cursor - 1);
		s2 = ft_strsub(box->str,
		box->cursor, ft_strlen(box->str) - box->cursor);
		if (box->cursor == 1 && box->minus)
			box->minus--;
		box->cursor--;
		if (box->type == DOUBLE)
		{
			if (box->str[box->cursor] == '.')
			{
				box->int_count += box->float_count;
				box->float_count = 0;
				box->period_index = 0;
				box->period--;
			}
			else if (box->float_count > 0
				&& box->cursor > box->period_index)
				box->float_count--;
			else if (box->cursor <= box->period_index)
				box->period_index--;
			if (ft_isdigit(box->str[box->cursor])
				&& (!box->period
				|| (box->cursor <= box->period_index)))
				box->int_count--;
		}
	}
	else
	{
		s1 = ft_strsub(box->str, 0, box->cursor);
		s2 = ft_strsub(box->str,
		box->cursor + 1, ft_strlen(box->str) - (box->cursor + 1));
		if (!box->cursor && box->minus)
			box->minus--;
		if (box->type == DOUBLE)
		{
			if (box->str[box->cursor] == '.')
			{
				box->int_count += box->float_count;
				box->float_count = 0;
				box->period_index = 0;
				box->period--;
			}
			else if (box->float_count > 0
				&& box->cursor > box->period_index)
				box->float_count--;
			else if (box->cursor <= box->period_index)
				box->period_index--;
			if (ft_isdigit(box->str[box->cursor])
				&& (!box->period
				|| (box->cursor <= box->period_index)))
				box->int_count--;
		}
	}
	if (!(res = ft_strnew(ft_strlen(box->str) - 1)))
		return (-1);
	res = ft_strcpy(res, s1);
	res = ft_strcat(res, s2);
	if (s1)
		ft_strdel(&s1);
	if (s2)
		ft_strdel(&s2);
	if (box->str)
	ft_strdel(&box->str);
	box->str = res;
	return (0);
}

/*
**	Add the char contained in c (string of 1 char)
**	at cursor position
*/

int		add_char(t_input_box *box, char c)
{
	char	*s1;
	char	*s2;
	char	*res;

	if (!box->str)
	{
		if (!(box->str = ft_strnew(1)))
			return (-1);
		box->str[0] = c;
		return (0);
	}
	if (box->select_start != box->select_end)
		delete_box_selection(box);
	s1 = ft_strsub(box->str, 0, box->cursor);
	s2 = ft_strsub(box->str, box->cursor, ft_strlen(box->str) - box->cursor + 1);
	if (!(res = ft_strnew(ft_strlen(box->str) + 1)))
		return (-1);
	res = ft_strcpy(res, s1);
	res[box->cursor] = c;
	res = ft_strcat(res, s2);
	if (s1)
		ft_strdel(&s1);
	if (s2)
		ft_strdel(&s2);
	if (box->str)
		ft_strdel(&box->str);
	box->str = res;
	box->cursor++;
	return (0);
}

int		parse_uint32_input(t_input_box *box, t_env *env)
{
	char	new;

	(void)box;
	new = ft_getchar(env->sdl.event.key.keysym.sym, env->inputs.shift);
	if (!new || !ft_ishexa(new) || ft_strlen(box->str) > 9)
		return (0);
	if (box->select_start < 2)
		box->select_start = 2;
	if (box->select_end < 2)
		box->select_end = 2;
	if (box->cursor <= 1)
		box->cursor = 2;
	/*if ((box->select_start <= 2 || box->select_end <= 1)
		&& box->select_end != box->select_start)
	{
		box->select_start = 2;
		//box->select_end = 3;
		box->cursor = 2;
	}*/
	if (add_char(box, new))
		return (-1);
	return (0);
}

int		parse_integer_input(t_input_box *box, t_env *env)
{
	char	new;

	new = ft_getchar(env->sdl.event.key.keysym.sym, env->inputs.shift);
	if (!new)
		return (0);
	if (!ft_isdigit(new))
	{
		if (new != '-' || (new == '-' && box->cursor && box->select_start != 0
			&& box->select_end != ft_strlen(box->str)))
			return (0);
	}
	if (ft_strlen(box->str) - box->minus >= 9 || (box->minus && !box->cursor))
		return (0);
	if (add_char(box, new))
		return (-1);
	if (new == '-')
		box->minus++;
	if (box->int_count >= 9)
		box->cursor = ft_strlen(box->str);
	return (0);
}

int		parse_double_input(t_input_box *box, t_env *env)
{
	char	new;

	new = ft_getchar(env->sdl.event.key.keysym.sym, env->inputs.shift);
	if (!new)
		return (0);
	if (!ft_isdigit(new))
	{
		if ((new != '.' && new != '-')
			|| (new == '.' && box->period)
			|| (new == '-' && box->cursor && box->select_start != 0
			&& box->select_end != ft_strlen(box->str)))
			return (0);
	}
	else if ((box->float_count >= 5 && box->cursor > box->period_index)
		|| (box->minus && !box->cursor)
		|| (box->int_count >= 9
		&& box->cursor <= box->period_index))
		return (0);
	if (ft_strlen(box->str) - box->minus >= 9 && !box->period)
	{
		box->cursor = 9 + box->minus;
		box->period_index = box->cursor;
		if (add_char(box, '.'))
			return (-1);
		box->period++;
	}
	if (add_char(box, new))
		return (-1);
	if (ft_isdigit(new))
	{
		if (box->cursor - 1 <= box->period_index || !box->period)
		{
			box->int_count++;
			box->period_index++;
		}
		if (box->period && box->cursor - 1 > box->period_index)
			box->float_count++;
	}
	if (new == '.')
	{
		box->period_index = box->cursor - 1;
		box->float_count = ft_strlen(box->str) - box->period_index
		- 1;
		box->int_count -= box->float_count;
		box->period++;
	}
	if (new == '-')
		box->minus++;
	if (ft_strlen(box->str) - box->minus >= 9 && !box->period)
	{
		box->cursor = 9 + box->minus;
		box->period_index = box->cursor;
		if (add_char(box, '.'))
			return (-1);
		box->period++;
	}
	if (box->int_count >= 9)
		box->cursor = ft_strlen(box->str);
	return (0);
}

/*
**	Read user input as a string into the input box
**	Light protection, only is_print()
*/

int		parse_str_input(t_input_box *box, t_env *env)
{
	char	new;

	new = ft_getchar(env->sdl.event.key.keysym.sym, env->inputs.shift);
	if (!new)
		return (0);
	env->sdl.event.key.keysym.sym = 0;
	if (!(ft_isalnum(new) || new == '-' || new == '.'
		|| new == '_' || new == '/' || new == ' '))
		return (0);
	if (add_char(box, new))
		return (-1);
	return (0);
}

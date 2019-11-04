/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_box_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 10:29:15 by lnicosia          #+#    #+#             */
/*   Updated: 2019/11/04 17:42:15 by lnicosia         ###   ########.fr       */
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
		box->cursor--;
	}
	else
	{
		s1 = ft_strsub(box->str, 0, box->cursor);
		s2 = ft_strsub(box->str,
		box->cursor + 1, ft_strlen(box->str) - (box->cursor + 1));
	}
	if (!(res = ft_strnew(ft_strlen(box->str) - 1)))
		return (-1);
	res = ft_strcpy(res, s1);
	res = ft_strcat(res, s2);
	ft_strdel(&s1);
	ft_strdel(&s2);
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
	s1 = ft_strsub(box->str, 0, box->cursor);
	s2 = ft_strsub(box->str, box->cursor, ft_strlen(box->str) - box->cursor + 1);
	if (!(res = ft_strnew(ft_strlen(box->str) + 1)))
		return (-1);
	res = ft_strcpy(res, s1);
	res[box->cursor] = c;
	res = ft_strcat(res, s2);
	ft_strdel(&s1);
	ft_strdel(&s2);
	ft_strdel(&box->str);
	box->str = res;
	box->cursor++;
	return (0);
}

int		parse_integer_input(t_input_box *box, t_env *env)
{
	char	new;

	if (ft_strlen(box->str) >= 9)
		return (0);
	new = ft_getchar(env->sdl.event.key.keysym.sym,
			env->inputs.shift);
	if (!new)
		return (0);
	env->sdl.event.key.keysym.sym = 0;
	if (!ft_isdigit(new))
		return (0);
	if (add_char(box, new))
		return (-1);
	return (0);
}

int		parse_double_input(t_input_box *box, t_env *env)
{
	char	new;

	if (ft_strlen(box->str) >= 9 && !box->period)
	{
		if (add_char(box, '.'))
			return (-1);
		box->period++;
	}
	new = ft_getchar(env->sdl.event.key.keysym.sym,
			env->inputs.shift);
	if (!new)
		return (0);
	env->sdl.event.key.keysym.sym = 0;
	if (!ft_isdigit(new) || (new == '.' && box->period))
		return (0);
	if (add_char(box, new))
		return (-1);
	if (new == '.')
		box->period++;
	return (0);
}

/*
**	Read user input as a string into the input box
**	Light protection, only is_print()
*/

int		parse_str_input(t_input_box *box, t_env *env)
{
	char	new;

	new = ft_getchar(env->sdl.event.key.keysym.sym,
			env->inputs.shift);
	if (!new)
		return (0);
	env->sdl.event.key.keysym.sym = 0;
	if (!(ft_isalnum(new) || new == '-' || new == '.'
		|| new == '_' || new == '/'))
		return (0);
	if (add_char(box, new))
		return (-1);
	return (0);
}

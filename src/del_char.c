/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del_char.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/30 16:07:07 by lnicosia          #+#    #+#             */
/*   Updated: 2020/04/30 16:07:08 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "input_box_utils.h"

void	update_double_box(t_input_box *box)
{
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
			&& (!box->period || (box->cursor <= box->period_index)))
			box->int_count--;
	}
}

int		del_previous_char(t_input_box *box, char **s1, char **s2)
{
	*s1 = ft_strsub(box->str, 0, box->cursor - 1);
	if (box->cursor - 1 > 0 && !*s1)
		return (-1);
	*s2 = ft_strsub(box->str, box->cursor, ft_strlen(box->str) - box->cursor);
	if (ft_strlen(box->str) - box->cursor > 0 && !*s2)
	{
		ft_strdel(s1);
		return (-1);
	}
	if (box->cursor == 1 && box->minus)
		box->minus--;
	box->cursor--;
	update_double_box(box);
	return (0);
}

int		del_next_char(t_input_box *box, char **s1, char **s2)
{
	*s1 = ft_strsub(box->str, 0, box->cursor);
	if (box->cursor - 1 > 0 && !*s1)
		return (-1);
	*s2 = ft_strsub(box->str, box->cursor + 1,
	ft_strlen(box->str) - (box->cursor + 1));
	if (ft_strlen(box->str) - (box->cursor + 1) > 0 && !*s2)
	{
		ft_strdel(s1);
		return (-1);
	}
	if (!box->cursor && box->minus)
		box->minus--;
	update_double_box(box);
	return (0);
}

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
		if (del_previous_char(box, &s1, &s2))
		return (-1);
	}
	else if (del_next_char(box, &s1, &s2))
		return (-1);
	if (!(res = ft_strnew(ft_strlen(box->str) - 1)))
	{
		ft_strdel(&s1);
		ft_strdel(&s2);
		return (-1);
	}
	res = ft_strcpy(res, s1);
	res = ft_strcat(res, s2);
	ft_strdel(&s1);
	ft_strdel(&s2);
	if (box->str)
		ft_strdel(&box->str);
	box->str = res;
	return (0);
}

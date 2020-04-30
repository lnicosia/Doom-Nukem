/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_char.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/30 16:06:35 by lnicosia          #+#    #+#             */
/*   Updated: 2020/04/30 16:06:36 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "input_box_utils.h"

int		add_char2(t_input_box *box, char *s1, char *s2, char c)
{
	char	*res;

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

/*
**	Add the char contained in c (string of 1 char)
**	at cursor position
*/

int		add_char(t_input_box *box, char c)
{
	char	*s1;
	char	*s2;

	if (!box->str)
	{
		if (!(box->str = ft_strnew(1)))
			return (-1);
		box->str[0] = c;
		return (0);
	}
	if (box->select_start != box->select_end)
		if (delete_box_selection(box))
			return (-1);
	s1 = ft_strsub(box->str, 0, box->cursor);
	if (box->cursor > 0 && !s1)
		return (-1);
	s2 =
	ft_strsub(box->str, box->cursor, ft_strlen(box->str) - box->cursor + 1);
	if (ft_strlen(box->str) - box->cursor + 1 > 0 && !s2)
		return (-1);
	return (add_char2(box, s1, s2, c));
}

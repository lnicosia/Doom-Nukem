/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_box_text.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/01 10:49:01 by lnicosia          #+#    #+#             */
/*   Updated: 2020/05/20 12:23:46 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "input_box_utils.h"
#include "draw.h"

int		box_cursor(t_input_box *box, char *str, char *tmp2, t_env *env)
{
	if (box->cursor > box->count
		&& box->cursor <= box->count + ft_strlen(tmp2)
		&& (box->cursor_state || env->inputs.home || env->inputs.end
		|| env->inputs.right || env->inputs.left || env->inputs.up
		|| env->inputs.down || env->inputs.left_click))
	{
		if (draw_cursor(box, box->current_line_pos, ft_strsub(tmp2, 0,
			box->cursor - box->count), env))
			return (-1);
		if (box->up)
		{
			box->up = 0;
			box->cursor = box->prec_count + box->cursor_in_line;
		}
		if (box->down && ft_strlen(str))
		{
			box->down = 0;
			box->change_cursor_line = 1;
		}
	}
	return (0);
}

int		split_str(char **tmp, char **tmp2)
{
	if (!(*tmp2 = ft_strsub(*tmp, 0,
	ft_strlen(*tmp) - ft_strlen(ft_strrchr(*tmp, ' ')))))
	{
		ft_strdel(tmp);
		return (0);
	}
	ft_strdel(tmp);
	return (1);
}

char	*get_current_str(t_input_box *box, char **str)
{
	char	*tmp;
	char	*tmp2;
	char	*tmp3;

	tmp = NULL;
	tmp2 = NULL;
	tmp3 = NULL;
	if (!(tmp = get_current_box_line(box, *str)))
		return (0);
	if (ft_strlen(tmp) < ft_strlen(*str) && ft_strrchr(tmp, ' '))
	{
		if (!(split_str(&tmp, &tmp2)))
			return (0);
	}
	else
		tmp2 = tmp;
	if (!(tmp3 = ft_strsub(*str, ft_strlen(tmp2),
		ft_strlen(*str) - ft_strlen(tmp2))))
	{
		ft_strdel(&tmp2);
		return (0);
	}
	ft_strdel(str);
	*str = tmp3;
	return (tmp2);
}

/*
**	If the string is too big to fit in one line
**	Prints the text in multiple lines
*/

int		split_box_text(t_input_box *box, t_env *env)
{
	char	*str;

	box->current_line_pos = new_point(box->pos.y + box->size.y / 100,
	box->pos.x + box->size.x / 100);
	box->cursor_in_line = 0;
	if (!(str = ft_strdup(box->str)))
		return (-1);
	if (TTF_SizeText(box->font, str, &box->current_text_size.x,
		&box->current_text_size.y))
	{
		ft_strdel(&str);
		return (-1);
	}
	while (ft_strlen(str) && box->current_line_pos.x
		+ box->current_text_size.y <= box->pos.y + box->size.y * 0.99)
	{
		if (draw_current_line(box, &str, env))
		{
			ft_strdel(&str);
			return (-1);
		}
	}
	ft_strdel(&str);
	return (0);
}

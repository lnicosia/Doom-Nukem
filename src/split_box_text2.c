/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_box_text2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/19 17:23:25 by marvin            #+#    #+#             */
/*   Updated: 2020/05/20 11:55:48 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "input_box_utils.h"
#include "draw.h"

int	draw_current_line4(t_input_box *box, char **str, char *tmp2, t_env *env)
{
	box->cursor_in_line = box->cursor - box->count;
	if (box_cursor(box, *str, tmp2, env))
	{
		ft_strdel(&tmp2);
		return (-1);
	}
	if (print_text(box->current_line_pos, new_printable_text(tmp2, box->font,
	0x333333FF, 0), env))
	{
		ft_strdel(&tmp2);
		return (-1);
	}
	box->prec_count = box->count;
	box->count += ft_strlen(tmp2);
	ft_strdel(&tmp2);
	box->current_line_pos.x += box->current_text_size.y + 5;
	return (0);
}

int	draw_current_line3(t_input_box *box, char **str, char *tmp2, t_env *env)
{
	if (env->inputs.left_click
		&& env->sdl.mx >= box->current_line_pos.y
		&& env->sdl.mx <= box->current_line_pos.y + box->size.x
		&& env->sdl.my >= box->current_line_pos.x
		&& env->sdl.my <= box->current_line_pos.x
		+ box->current_text_size.y)
	{
		if (input_box_mouse(box, box->current_line_pos, tmp2, env))
		{
			ft_strdel(&tmp2);
			return (-1);
		}
	}
	return (draw_current_line4(box, str, tmp2, env));
}

int	draw_current_line2(t_input_box *box, char **str, char *tmp2, t_env *env)
{
	(void)str;
	if (box->select_start != box->select_end
		&& ((box->select_start <= ft_strlen(tmp2) + box->count
		&& box->select_end >= box->count)
		|| (box->select_end <= ft_strlen(tmp2) + box->count
		&& box->select_start >= box->count)))
	{
		if (draw_box_selection(box, box->current_line_pos, tmp2, env))
		{
			ft_strdel(&tmp2);
			return (-1);
		}
	}
	return (draw_current_line3(box, str, tmp2, env));
}

int	draw_current_line(t_input_box *box, char **str, t_env *env)
{
	char	*tmp2;

	if (box->change_cursor_line)
		box->cursor =
		ft_min(box->count + box->cursor_in_line, ft_strlen(box->str));
	box->change_cursor_line = 0;
	if (!(tmp2 = get_current_str(box, str)))
		return (-1);
	if (TTF_SizeText(box->font, tmp2, &box->current_text_size.x,
		&box->current_text_size.y))
	{
		ft_strdel(&tmp2);
		return (-1);
	}
	return (draw_current_line2(box, str, tmp2, env));
}

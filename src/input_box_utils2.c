/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_box_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/30 12:15:46 by lnicosia          #+#    #+#             */
/*   Updated: 2020/05/18 18:44:50 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "input_box_utils.h"

int		init_input_box(t_input_box *box, t_env *env)
{
	ft_bzero(box, sizeof(*box));
	box->type = DOUBLE;
	box->del_delay = 25;
	box->input_delay = 50;
	box->move_cursor_delay = 100;
	box->cursor_delay = 500;
	if (!(box->str = ft_strnew(0)))
		return (-1);
	box->size = new_point(200, 30);
	box->pos = new_point(env->h_w - box->size.x / 2, env->h_h
	- box->size.y / 2);
	box->font = env->sdl.fonts.lato20;
	return (0);
}

/*
**	Finds the maximum number of characters that can fit in one line
**	of the input box
*/

int		find_input_box_max_char(t_input_box *box)
{
	char	*str;
	size_t	len;
	t_point size;

	size = new_point(0, 0);
	len = 1;
	if (!(str = ft_strnew(0)))
		return (-1);
	while (size.x < box->size.x * 0.99)
	{
		ft_strdel(&str);
		if (!(str = ft_strnew(len)))
			return (-1);
		ft_memset(str, 'a', len);
		if (TTF_SizeText(box->font, str, &size.x, &size.y))
		{
			ft_strdel(&str);
			return (-1);
		}
		len++;
	}
	ft_strdel(&str);
	box->line_size = len;
	box->max_lines = (box->size.y * 0.99) / (double)size.y;
	return (0);
}

/*
**	Draws the cursor
*/

int		draw_cursor(t_input_box *box, t_point pos, char *sub, t_env *env)
{
	t_point	size;
	int		y;

	if (!sub)
		return (-1);
	if (TTF_SizeText(box->font, sub, &size.x, &size.y))
		return (-1);
	y = pos.x;
	while (y < pos.x + size.y)
	{
		env->sdl.texture_pixels[pos.y + size.x + env->w * y] =
		0xFF606060;
		y++;
	}
	ft_strdel(&sub);
	return (0);
}

void	get_selection_boundaries(size_t *start, size_t *end, char *str,
t_input_box *box)
{
	if (box->select_start > box->select_end)
	{
		*start = box->select_end;
		*end = box->select_start;
	}
	else
	{
		*start = box->select_start;
		*end = box->select_end;
	}
	*start = ft_max(0, *start - box->count);
	*end = ft_min(*end - box->count, ft_strlen(str));
}

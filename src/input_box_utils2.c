/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_box_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/30 12:15:46 by lnicosia          #+#    #+#             */
/*   Updated: 2020/04/30 12:15:47 by lnicosia         ###   ########.fr       */
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
**	Find the largest string of the current text characters that fit in one line
*/

char	*get_current_box_line(t_input_box *box, char *str)
{
	size_t	len;
	char	*res;
	t_point	size;

	size = new_point(0, 0);
	len = 1;
	if (!(res = ft_strnew(0)))
		return (0);
	while (size.x < box->size.x * 0.99 && len <= ft_strlen(str))
	{
		ft_strdel(&res);
		if (!(res = ft_strsub(str, 0, len)))
			return (0);
		if (TTF_SizeText(box->font, res, &size.x, &size.y))
		{
			ft_strdel(&res);
			return (0);
		}
		len++;
	}
	if (size.x >= box->size.x * 0.99)
	{
		ft_strdel(&res);
		if (!(res = ft_strsub(str, 0, len - 2)))
			return (0);
	}
	return (res);
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

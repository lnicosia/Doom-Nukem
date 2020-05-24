/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_box.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 09:59:10 by lnicosia          #+#    #+#             */
/*   Updated: 2020/05/18 19:18:08 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "input_box_utils.h"
#include "draw.h"

/*
**	Highlight the current selection with blue
*/

int		draw_box_selection2(t_input_box *box, char *sub, t_point size2)
{
	if (TTF_SizeText(box->font, sub, &size2.x, &size2.y))
	{
		ft_strdel(&sub);
		return (-1);
	}
	if (sub)
		ft_strdel(&sub);
	return (0);
}

int		draw_box_selection(t_input_box *box, t_point pos, char *str, t_env *env)
{
	t_point	size1;
	t_point	size2;
	size_t	start;
	size_t	end;
	char	*sub;

	get_selection_boundaries(&start, &end, str, box);
	if (!(sub = ft_strsub(str, 0, start)) && start)
		return (-1);
	if (TTF_SizeText(box->font, sub, &size1.x, &size1.y))
	{
		ft_strdel(&sub);
		return (-1);
	}
	if (sub)
		ft_strdel(&sub);
	if (!(sub = ft_strsub(str, start, end - start)) && end - start)
		return (-1);
	if (draw_box_selection2(box, sub, size2))
		return (-1);
	draw_selection(pos, size1, size2, env);
	return (0);
}

int		draw_single_line(t_input_box *box, t_point size, t_env *env)
{
	t_point				pos;
	t_printable_text	text;

	pos = new_point(box->pos.y + box->size.y / 2 - size.y / 2,
	box->pos.x + 6);
	if (box->select_start != box->select_end
		&& draw_box_selection(box, pos, box->str, env))
		return (-1);
	if (env->inputs.left_click && input_box_mouse(box, pos, box->str, env))
		return (-1);
	text = new_printable_text(box->str, box->font, 0x333333FF, box->size.x);
	if (print_text(pos, text, env))
		return (-1);
	if (box->cursor_state || env->inputs.home || env->inputs.end
		|| env->inputs.right || env->inputs.left || env->inputs.left_click
		|| env->inputs.up || env->inputs.down)
	{
		if (draw_cursor(box, pos, ft_strsub(box->str, 0, box->cursor), env))
			return (-1);
	}
	return (0);
}

int		draw_input_box_content(t_input_box *box, t_env *env)
{
	t_point				size;

	if (!box->str || (box->str && box->str[0] == 0) || !box->font)
		return (0);
	if (TTF_SizeText(box->font, box->str, &size.x, &size.y))
		return (-1);
	box->count = 0;
	box->prec_count = 0;
	if (size.x < box->size.x * 0.99 || box->type != STRING)
	{
		if (draw_single_line(box, size, env))
			return (-1);
	}
	else if (box->type == STRING)
	{
		if (split_box_text(box, env))
			return (-1);
	}
	return (0);
}

int		draw_input_box(t_input_box *box, t_env *env)
{
	draw_rectangle(env, box->rectangle, box->pos, box->size);
	if (draw_input_box_content(box, env))
		return (-1);
	if (SDL_GetTicks() - box->cursor_timer > box->cursor_delay)
	{
		box->cursor_timer = SDL_GetTicks();
		box->cursor_state = box->cursor_state ? 0 : 1;
	}
	return (0);
}

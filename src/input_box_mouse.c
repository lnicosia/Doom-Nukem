/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_box_mouse.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/30 12:15:15 by lnicosia          #+#    #+#             */
/*   Updated: 2020/04/30 13:36:02 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

int		get_current_size(t_input_box *box, char *str, int i, t_point *size2)
{
	char	*sub;

	if (!(sub = ft_strsub(str, 0, i + 1)))
		return (-1);
	if (TTF_SizeText(box->font, sub, &size2->x, &size2->y))
	{
		ft_strdel(&sub);
		return (-1);
	}
	if (sub)
		ft_strdel(&sub);
	return (0);
}

void	update_selection(t_input_box *box)
{
	if (!box->selecting)
	{
		box->select_start = box->cursor;
		box->selecting = 1;
	}
	box->select_end = box->cursor;
}

int		input_box_mouse2(t_input_box *box, char *str)
{
	box->cursor = ft_strlen(str) + box->count;
	if (!box->selecting)
	{
		box->select_end = box->cursor;
		box->select_start = box->cursor;
	}
	return (0);
}

/*
**	Moves the cursor according to the click
*/

int		input_box_mouse(t_input_box *box, t_point pos, char *str, t_env *env)
{
	int		i;
	t_point	size;
	t_point	size2;

	i = 0;
	size = new_point(0, 0);
	while (str[i])
	{
		if (get_current_size(box, str, i, &size2))
			return (-1);
		if (env->sdl.mx < pos.y + size2.x)
		{
			if ((pos.y + size2.x) - env->sdl.mx
				> env->sdl.mx - (pos.y + size.x))
				box->cursor = i + box->count;
			else
				box->cursor = i + 1 + box->count;
			update_selection(box);
			return (0);
		}
		size = size2;
		i++;
	}
	return (input_box_mouse2(box, str));
}

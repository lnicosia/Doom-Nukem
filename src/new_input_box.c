/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_input_box.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/30 16:08:28 by lnicosia          #+#    #+#             */
/*   Updated: 2020/04/30 16:08:29 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "input_box_utils.h"
#include "events.h"

int	new_input_box4(t_input_box *box)
{
	if (find_input_box_max_char(box))
		return (-1);
	box->cursor = ft_strlen(box->str);
	box->select_start = 0;
	box->select_end = ft_strlen(box->str);
	box->check = 0;
	box->update = 0;
	box->count = 0;
	box->error_message = "Error";
	return (0);
}

int	new_input_box3(t_input_box *box, int type, void *target)
{
	char	*tmp;

	if (type == UINT32)
	{
		box->uint32_target = (Uint32*)target;
		if (box->str)
			ft_strdel(&box->str);
		if (!(tmp = ft_strnew(15)))
			return (-1);
		ft_snprintf(tmp, 15, "0x%X", *box->uint32_target);
		if (!(box->str = ft_strdup(tmp)))
		{
			ft_strdel(&tmp);
			return (-1);
		}
		ft_strdel(&tmp);
		set_double_stats(box);
	}
	else if (type == STRING)
	{
		if (set_new_string_input_box(box, target))
			return (-1);
	}
	return (new_input_box4(box));
}

int	new_input_box2(t_input_box *box, int type, void *target)
{
	size_t	len;
	size_t	dec_len;

	len = 0;
	if (type == DOUBLE)
	{
		box->double_target = (double*)target;
		if (box->str)
			ft_strdel(&box->str);
		len = get_double_len(*(box->double_target));
		dec_len = get_decimal_len(*(box->double_target));
		if (!(box->str = ft_strnew(len)))
			return (-1);
		if (*box->double_target < 0)
			box->minus = 1;
		if (dec_len)
		{
			box->period = 1;
			box->period_index = len - dec_len + box->minus;
		}
		ft_snprintf(box->str, len + 1, "%.*f", dec_len,
		*(box->double_target));
		set_double_stats(box);
	}
	return (new_input_box3(box, type, target));
}

int	new_input_box(t_input_box *box, t_point pos, int type, void *target)
{
	if (type < 0 || type > 3 || !target)
		return (-1);
	box->size = new_point(250, 60);
	box->pos = pos;
	box->rectangle = new_rectangle(0xFFFFFFFF, 0xFF606060, 1, 3);
	box->type = type;
	box->state = 1;
	box->accept_inputs = 0;
	if (type == INT)
	{
		box->int_target = (int*)target;
		if (box->str)
			ft_strdel(&box->str);
		if (!(box->str = ft_itoa(*((int*)target))))
			return (-1);
		if (*box->int_target < 0)
			box->minus = 1;
		set_double_stats(box);
	}
	return (new_input_box2(box, type, target));
}

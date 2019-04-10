/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_float_padding.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/25 13:52:43 by lnicosia          #+#    #+#             */
/*   Updated: 2019/03/05 16:44:27 by gaerhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "put_padding.h"

void		set_fpadding_lmin(t_data *data)
{
	if (!data->left)
	{
		if (data->zero)
			data->padding.zeros = data->l_min - data->padding.size;
		else
			data->padding.left_spaces = data->l_min - data->padding.size;
	}
	else
		data->padding.right_spaces = data->l_min - data->padding.size;
}

void		set_fpadding(t_data *data, long i_part, long double nb)
{
	data->padding.size = (data->prec > 0) ? data->prec + 1 : data->prec;
	if (i_part == 0)
		data->padding.size++;
	if (data->sharp && data->prec == 0)
		data->padding.size++;
	if (data->plus || data->space || nb < 0 || 1.0 / nb < 0)
	{
		data->padding.sign = 1;
		data->padding.size++;
	}
	while (i_part != 0)
	{
		data->padding.size++;
		i_part /= 10;
	}
	data->padding.left_spaces = 0;
	data->padding.right_spaces = 0;
	if (data->l_min > data->padding.size)
		set_fpadding_lmin(data);
}

void		set_fpadding_inf(t_data *data, long double nb)
{
	data->padding.size = (nb == -1.0 / 0.0) ? 3 : 3;
	if (data->plus || data->space || nb == -1.0 / 0.0)
	{
		data->padding.sign = 1;
		data->padding.size++;
	}
	data->padding.left_spaces = 0;
	data->padding.right_spaces = 0;
	if (!data->left)
		data->padding.left_spaces = data->l_min - data->padding.size;
	else
		data->padding.right_spaces = data->l_min - data->padding.size;
}

int			inf(t_data *data, long double nb)
{
	if (nb == 1.0 / 0.0 || nb == -1.0 / 0.0 || nb != nb)
	{
		set_fpadding_inf(data, nb);
		put_left_spaces(data);
		if (nb == -1.0 / 0.0)
			fill_buffer(data, "-", 1);
		else if (data->plus)
			fill_buffer(data, "+", 1);
		else if (data->space)
			fill_buffer(data, " ", 1);
		put_zeros(data);
		if (nb == -1.0 / 0.0)
			fill_buffer(data, "inf", 3);
		else if (nb == 1.0 / 0.0)
			fill_buffer(data, "inf", 3);
		else
			fill_buffer(data, "nan", 3);
		put_right_spaces(data);
		return (-1);
	}
	return (1);
}

long double	cast_float(t_data *data)
{
	long double nb;

	if (data->size == 16)
		nb = va_arg(data->ap, long double);
	else
		nb = va_arg(data->ap, double);
	return (nb);
}

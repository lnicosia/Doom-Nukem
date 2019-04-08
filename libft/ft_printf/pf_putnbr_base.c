/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/12 22:33:02 by lnicosia          #+#    #+#             */
/*   Updated: 2019/02/22 16:10:50 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "put_padding.h"
#include "base_utils.h"

void	pf_putnbr_x(t_data *data)
{
	unsigned long	nb;

	nb = cast_base(data);
	data->padding.size = 0;
	if (data->sharp && (nb && (data->l_min != 0 && data->prec == -1)))
		data->padding.size += 2;
	set_zeros_base(data, nb, 16);
	if (data->sharp && (nb && !(data->l_min != 0 && data->prec == -1)))
		data->padding.size += 2;
	set_spaces_base(data);
	put_left_spaces(data);
	if (data->sharp && nb)
		fill_buffer(data, "0x", 2);
	put_zeros(data);
	if (nb != 0 || data->prec != 0)
		pf_putlong_base(nb, "0123456789abcdef", data);
	put_right_spaces(data);
}

void	pf_putnbr_xcaps(t_data *data)
{
	unsigned long	nb;

	nb = cast_base(data);
	data->padding.size = 0;
	if (data->sharp && (nb && (data->l_min != 0 && data->prec == -1)))
		data->padding.size += 2;
	set_zeros_base(data, nb, 16);
	if (data->sharp && (nb && !(data->l_min != 0 && data->prec == -1)))
		data->padding.size += 2;
	set_spaces_base(data);
	put_left_spaces(data);
	if (data->sharp && nb)
		fill_buffer(data, "0X", 2);
	put_zeros(data);
	if (nb != 0 || data->prec != 0)
		pf_putlong_base(nb, "0123456789ABCDEF", data);
	put_right_spaces(data);
}

void	pf_putnbr_o(t_data *data)
{
	unsigned long	nb;

	nb = cast_base(data);
	data->padding.size = 0;
	set_zeros_base(data, nb, 8);
	if (data->sharp && ((data->padding.zeros == 0 && nb != 0) || (data->prec
					== 0 && nb == 0)))
		data->padding.size += 1;
	set_spaces_base(data);
	put_left_spaces(data);
	if (data->sharp && ((data->padding.zeros == 0 && nb != 0) || (data->prec
					== 0 && nb == 0)))
		fill_buffer(data, "0", 1);
	put_zeros(data);
	if (!(data->prec == 0 && nb == 0))
		pf_putlong_base(nb, "01234567", data);
	put_right_spaces(data);
}

void	pf_putnbr_b(t_data *data)
{
	unsigned long	nb;

	nb = cast_base(data);
	data->padding.size = 0;
	if (data->sharp && (nb && (data->l_min != 0 && data->prec == -1)))
		data->padding.size += 2;
	set_zeros_base(data, nb, 2);
	if (data->sharp && (nb && !(data->l_min != 0 && data->prec == -1)))
		data->padding.size += 2;
	set_spaces_base(data);
	put_left_spaces(data);
	if (data->sharp && nb)
		fill_buffer(data, "0b", 2);
	put_zeros(data);
	if (nb != 0 || data->prec != 0)
		pf_putlong_base(nb, "01", data);
	put_right_spaces(data);
}

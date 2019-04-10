/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putadrr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/01 19:05:57 by lnicosia          #+#    #+#             */
/*   Updated: 2019/02/22 16:14:09 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "put_padding.h"

static void	set_paddingx(t_data *data, unsigned long nb, int base_len)
{
	data->padding.size = (nb == 0 && data->prec != 0) ? 1 : 0;
	while (nb != 0)
	{
		data->padding.size++;
		nb /= base_len;
	}
	data->padding.zeros = 0;
	if (data->prec != -1)
		data->padding.zeros = data->prec - data->padding.size;
	else if (!data->left && data->zero)
		data->padding.zeros = data->l_min - data->padding.size - 2;
	if (data->padding.zeros < 0)
		data->padding.zeros = 0;
	data->padding.right_spaces = 0;
	data->padding.left_spaces = 0;
	if (data->left)
		data->padding.right_spaces = data->l_min - data->padding.zeros
			- data->padding.size - 2;
	else
		data->padding.left_spaces = data->l_min - data->padding.zeros
			- data->padding.size - 2;
}

void		pf_putaddr(t_data *data)
{
	unsigned long	nb;

	nb = va_arg(data->ap, unsigned long);
	set_paddingx(data, nb, 16);
	put_left_spaces(data);
	fill_buffer(data, "0x", 2);
	put_zeros(data);
	if (nb != 0 || data->prec != 0)
		pf_putlong_base(nb, "0123456789abcdef", data);
	put_right_spaces(data);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   base_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 16:06:51 by lnicosia          #+#    #+#             */
/*   Updated: 2019/02/22 16:09:40 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			set_spaces_base(t_data *data)
{
	data->padding.right_spaces = 0;
	data->padding.left_spaces = 0;
	if (data->left)
		data->padding.right_spaces = data->l_min - data->padding.zeros
			- data->padding.size;
	else
		data->padding.left_spaces = data->l_min - data->padding.zeros
			- data->padding.size;
}

void			set_zeros_base(t_data *data, unsigned long nb, int base_len)
{
	if (nb == 0 && data->prec != 0)
		data->padding.size = 1;
	while (nb != 0)
	{
		data->padding.size++;
		nb /= base_len;
	}
	data->padding.zeros = 0;
	if (data->prec != -1)
		data->padding.zeros = data->prec - data->padding.size;
	else if ((!data->left && data->zero))
		data->padding.zeros = data->l_min - data->padding.size;
	if (data->padding.zeros < 0)
		data->padding.zeros = 0;
}

unsigned long	cast_base(t_data *data)
{
	unsigned long	nb;

	nb = va_arg(data->ap, unsigned long);
	if (data->size == 1)
		nb = (unsigned char)nb;
	else if (data->size == 2)
		nb = (unsigned int)nb;
	else if (data->size == 4)
		nb = (unsigned int)nb;
	return (nb);
}

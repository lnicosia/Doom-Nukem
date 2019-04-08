/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/05 14:42:42 by lnicosia          #+#    #+#             */
/*   Updated: 2019/02/28 17:01:57 by gaerhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "put_padding.h"

static void	set_padding(t_data *data)
{
	data->padding.size = 1;
	data->padding.zeros = 0;
	if (!data->left && data->zero)
		data->padding.zeros = data->l_min - data->padding.size;
	data->padding.right_spaces = 0;
	data->padding.left_spaces = 0;
	if (data->left)
		data->padding.right_spaces = data->l_min - data->padding.zeros
			- data->padding.size;
	else
		data->padding.left_spaces = data->l_min - data->padding.zeros
			- data->padding.size;
}

void		pf_putchar(t_data *data)
{
	char	c;

	c = va_arg(data->ap, int);
	set_padding(data);
	put_left_spaces(data);
	put_zeros(data);
	fill_buffer(data, &c, 1);
	put_right_spaces(data);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_padding.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 13:29:55 by lnicosia          #+#    #+#             */
/*   Updated: 2019/02/13 13:43:00 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	put_left_spaces(t_data *data)
{
	while (data->padding.left_spaces > 0)
	{
		fill_buffer(data, " ", 1);
		data->padding.left_spaces--;
	}
}

void	put_sign(t_data *data, long nb)
{
	if (data->padding.sign)
	{
		if (nb < 0)
			fill_buffer(data, "-", 1);
		else if (data->plus)
			fill_buffer(data, "+", 1);
		else if (data->space)
			fill_buffer(data, " ", 1);
	}
}

void	put_zeros(t_data *data)
{
	while (data->padding.zeros > 0)
	{
		fill_buffer(data, "0", 1);
		data->padding.zeros--;
	}
}

void	put_right_spaces(t_data *data)
{
	while (data->padding.right_spaces > 0)
	{
		fill_buffer(data, " ", 1);
		data->padding.right_spaces--;
	}
}

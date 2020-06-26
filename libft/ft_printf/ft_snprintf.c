/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_snprintf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/13 10:27:50 by lnicosia          #+#    #+#             */
/*   Updated: 2020/05/01 18:44:24 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_snprintf(char *restrict str, size_t size,
const char *restrict format, ...)
{
	t_data	data;

	if (!format)
		return (-1);
	init_data(&data, 1);
	data.str = str;
	data.str_size = size;
	data.mode = STR;
	va_start(data.ap, format);
	parse_format(format, &data);
	str[data.i] = '\0';
	va_end(data.ap);
	return (data.ret);
}

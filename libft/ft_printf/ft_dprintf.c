/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaerhard <gaerhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/27 16:40:14 by gaerhard          #+#    #+#             */
/*   Updated: 2019/02/27 16:48:06 by gaerhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_dprintf(int fd, const char *restrict format, ...)
{
	t_data	data;

	if (!format)
		return (-1);
	init_data(&data, fd);
	va_start(data.ap, format);
	parse_format(format, &data);
	write(fd, data.buffer, data.i);
	va_end(data.ap);
	return (data.ret);
}

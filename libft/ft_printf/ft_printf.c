/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/01 15:03:58 by lnicosia          #+#    #+#             */
/*   Updated: 2019/02/28 17:15:19 by gaerhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	(*const g_printers[128])(t_data *data) =
{
	['d'] = &pf_putnbr,
	['D'] = &pf_putnbr,
	['i'] = &pf_putnbr,
	['o'] = &pf_putnbr_o,
	['b'] = &pf_putnbr_b,
	['O'] = &pf_putnbr_o,
	['u'] = &pf_putunbr,
	['U'] = &pf_putunbr,
	['x'] = &pf_putnbr_x,
	['X'] = &pf_putnbr_xcaps,
	['c'] = &pf_putchar,
	['C'] = &pf_putchar,
	['s'] = &pf_putstr,
	['S'] = &pf_putstr,
	['p'] = &pf_putaddr,
	['%'] = &pf_putpercent,
	['f'] = &pf_putfloat,
	['F'] = &pf_putfloat
};

void		fill_buffer(t_data *data, const char *s, unsigned int size)
{
	unsigned int	i;

	i = 0;
	if (data->ret != -1)
		data->ret += size;
	if (data->i + size > 2147483647)
		data->ret = -1;
	if (data->i + size >= BUFF_SIZE)
	{
		write(data->fd, data->buffer, data->i);
		data->i = 0;
	}
	if (size < BUFF_SIZE)
	{
		while (i < size)
		{
			data->buffer[data->i] = s[i];
			i++;
			data->i++;
		}
	}
	else
		write(data->fd, s, size);
}

void		reset_options(t_data *data)
{
	data->left = 0;
	data->plus = 0;
	data->zero = 0;
	data->space = 0;
	data->sharp = 0;
	data->l_min = 0;
	data->prec = -1;
	data->size = 4;
	data->invalid = "\0";
	data->padding.size = 0;
	data->padding.zeros = 0;
}

void		init_data(t_data *data, int fd)
{
	int	i;

	i = -1;
	data->i = 0;
	data->ret = 0;
	data->fd = fd;
	while (++i < BUFF_SIZE)
		data->buffer[i] = '\0';
	reset_options(data);
}

void		parse_format(const char *restrict format, t_data *data)
{
	int	i;
	int	c;

	i = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			c = parse_flags(format, &i, data);
			if (g_printers[c] == NULL)
				pf_invalid(data);
			else
				g_printers[c](data);
		}
		else if (format[i] == '{')
			parse_color(format, &i, data);
		else
			fill_buffer(data, format + i, 1);
		reset_options(data);
		i++;
	}
}

int			ft_printf(const char *restrict format, ...)
{
	t_data	data;

	if (!format)
		return (-1);
	init_data(&data, 1);
	va_start(data.ap, format);
	parse_format(format, &data);
	write(1, data.buffer, data.i);
	va_end(data.ap);
	return (data.ret);
}

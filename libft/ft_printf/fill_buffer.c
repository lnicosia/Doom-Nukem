/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_buffer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/01 18:45:05 by lnicosia          #+#    #+#             */
/*   Updated: 2020/05/01 19:05:28 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		fill_str(t_data *data, const char *s, unsigned int size)
{
	unsigned int	i;

	i = 0;
	while (i < size && data->i < (int)data->str_size - 1)
	{
		data->str[data->i] = s[i];
		i++;
		data->i++;
	}
}

void		fill_output_buffer(t_data *data, const char *s, unsigned int size)
{
	unsigned int	i;

	i = 0;
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

void		fill_buffer(t_data *data, const char *s, unsigned int size)
{
	if (data->ret != -1)
		data->ret += size;
	if (data->i + size > 2147483647)
		data->ret = -1;
	if (data->mode == STDOUT)
		fill_output_buffer(data, s, size);
	else if (data->mode == STR)
		fill_str(data, s, size);
}

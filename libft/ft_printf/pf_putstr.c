/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 11:07:40 by lnicosia          #+#    #+#             */
/*   Updated: 2019/02/22 16:00:52 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "put_padding.h"

static int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

static void	set_padding(t_data *data, char *s)
{
	data->padding.size = data->prec != 0 ? ft_strlen(s) : 0;
	data->padding.zeros = 0;
	if (data->prec > 0 && data->prec < data->padding.size)
		data->padding.size = data->prec;
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

static char	*cast(t_data *data)
{
	char	*s;
	int		i;

	i = 0;
	s = va_arg(data->ap, char *);
	return (s);
}

void		pf_putstr(t_data *data)
{
	char	*s;

	s = cast(data);
	if (s == NULL)
		s = "(null)";
	set_padding(data, s);
	put_left_spaces(data);
	put_zeros(data);
	if (data->prec != 0)
		fill_buffer(data, s, data->padding.size);
	put_right_spaces(data);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_putfloat.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaerhard <gaerhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 15:35:58 by gaerhard          #+#    #+#             */
/*   Updated: 2019/03/05 17:01:39 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "put_padding.h"
#include <stdlib.h>

static void			put_sign_float(t_data *data, long double nb)
{
	if (data->padding.sign)
	{
		if (nb < 0 || 1.0 / nb < 0)
		{
			fill_buffer(data, "-", 1);
		}
		else if (data->plus)
			fill_buffer(data, "+", 1);
		else if (data->space)
			fill_buffer(data, " ", 1);
	}
}

static int			pf_ftoa(t_data *data, long nb, int precision)
{
	int		i;
	char	*str;

	if (!(str = pf_strnew(precision, data)))
		return (-1);
	i = 0;
	while (nb > 0)
	{
		str[i] = (nb % 10) + '0';
		nb = nb / 10;
		i++;
	}
	while (i < precision)
		str[i++] = '0';
	rev_str(str, i);
	str[i++] = '\0';
	fill_buffer(data, str, precision);
	pf_strdel(&str);
	return (i);
}

static int			pf_itoa(t_data *data, long nb)
{
	int		i;
	int		size;
	char	*str;

	size = get_size(nb);
	if (nb == 0)
	{
		fill_buffer(data, "0", 1);
		return (1);
	}
	nb = (nb > 0) ? -nb : nb;
	if (!(str = pf_strnew(size, data)))
		return (-1);
	i = 0;
	while (nb < 0)
	{
		str[i++] = '0' - (nb % 10);
		nb = nb / 10;
	}
	rev_str(str, i);
	fill_buffer(data, str, size);
	pf_strdel(&str);
	return (i + 1);
}

static long double	pf_ipart(t_data *data, long double nb)
{
	long i_part;

	i_part = (long)nb;
	set_fpadding(data, i_part, nb);
	put_left_spaces(data);
	put_sign_float(data, nb);
	put_zeros(data);
	return ((long double)i_part);
}

void				pf_putfloat(t_data *data)
{
	long double		nb;
	long double		f_part;
	long			i_part;

	nb = cast_float(data);
	if (inf(data, nb) == -1)
		return ;
	data->prec = (data->prec == -1) ? 6 : data->prec;
	if (data->prec == 0 && nb != 0)
		nb += (nb < 0) ? -0.4999999 : 0.4999999;
	i_part = pf_ipart(data, nb);
	f_part = nb - i_part;
	if (data->prec != 0)
	{
		f_part = (f_part < 0) ? -f_part : f_part;
		f_part = f_part * power(10, data->prec) + 0.5;
	}
	i_part += get_size((long)f_part) > data->prec && data->prec > 0 ? 1 : 0;
	f_part = get_size((long)f_part) > data->prec && data->prec > 0 ? 0 : f_part;
	if ((pf_itoa(data, i_part)) == -1)
		return ;
	(data->prec != 0 || data->sharp) ? fill_buffer(data, ".", 1) : (void)nb;
	if ((pf_ftoa(data, f_part, data->prec)) == -1)
		return ;
	put_right_spaces(data);
}

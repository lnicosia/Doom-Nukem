/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putlong_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 12:18:56 by lnicosia          #+#    #+#             */
/*   Updated: 2019/02/28 17:06:03 by gaerhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	pf_check_base(char *base)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (base[i])
	{
		if (base[i] <= ' ' || base[i] > '~' || base[i] == '+' || base[i] == '-')
			return (0);
		j = i + 1;
		while (base[j])
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	return (i);
}

static void	pf_print(unsigned long nbr, unsigned int len, char *base,
		t_data *data)
{
	if (nbr < len)
		fill_buffer(data, &base[nbr], 1);
	else
	{
		pf_print((nbr) / len, len, base, data);
		pf_print((nbr) % len, len, base, data);
	}
}

void		pf_putlong_base(unsigned long nbr, char *base, t_data *data)
{
	unsigned int	len;
	int				min_stock;

	len = pf_check_base(base);
	min_stock = -1;
	if (len > 1)
	{
		pf_print(nbr, len, base, data);
		if (min_stock != -1)
			fill_buffer(data, &base[min_stock % len], 1);
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_double_len.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 15:28:29 by lnicosia          #+#    #+#             */
/*   Updated: 2020/02/04 16:11:02 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		get_decimal_len(double nb)
{
	size_t	i;

	if (nb < 0)
		nb = -nb;
	nb = nb * 1000000;
	i = 5;
	while (i > 0)
	{
		nb /= 10;
		if ((size_t)nb % 10)
			return (i);
		i--;
	}
	return (0);
}

size_t		get_double_len(double nb)
{
	size_t	dec;

	dec = get_decimal_len(nb);
	if (dec)
		dec++;
	if (nb < 0)
		dec++;
	return (ft_getlen(nb) + dec);
}

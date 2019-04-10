/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/13 11:00:36 by lnicosia          #+#    #+#             */
/*   Updated: 2019/02/01 12:16:52 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		set_res(char *nbr, char *base_from, int res, int j)
{
	if (base_from[j] >= 'a' && base_from[j] < 'z')
	{
		if (*nbr == base_from[j] || *nbr == base_from[j] - 32)
			res = ft_strlen(base_from) * res + j;
	}
	else if (base_from[j] >= 'A' && base_from[j] < 'Z')
	{
		if (*nbr == base_from[j] || *nbr == base_from[j] + 32)
			res = ft_strlen(base_from) * res + j;
	}
	else if (*nbr == base_from[j])
		res = ft_strlen(base_from) * res + j;
	return (res);
}

int		ft_atoi_base(char *nbr, char *base_from)
{
	int res;
	int j;
	int k;
	int neg;

	neg = 1;
	res = 0;
	k = 0;
	if (*nbr == '-')
	{
		neg = -1;
		nbr++;
	}
	while (*nbr && *nbr != ' ')
	{
		j = -1;
		while (base_from[++j])
			res = set_res(nbr, base_from, res, j);
		nbr++;
		k++;
	}
	return (res * neg);
}

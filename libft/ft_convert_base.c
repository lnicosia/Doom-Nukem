/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/21 17:49:40 by lnicosia          #+#    #+#             */
/*   Updated: 2018/08/22 00:16:23 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_strlen(char *str)
{
	int len;

	len = 0;
	while (str[len] != '\0')
	{
		len++;
	}
	return (len);
}

int		ft_check_base(char *base)
{
	int i;
	int j;

	i = 0;
	j = 0;
	if (ft_strlen(base) < 2)
		return (0);
	while (base[i])
	{
		j = i + 1;
		if (base[i] == '+' || base[i] == '-' || base[i] == ' ')
			return (0);
		while (base[j])
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int		ft_atoi(char *nbr, char *base_from)
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
	while (*nbr)
	{
		j = -1;
		while (base_from[++j])
		{
			if (*nbr == base_from[j])
				res = ft_strlen(base_from) * res + j;
		}
		nbr++;
		k++;
	}
	return (res * neg);
}

char	*ft_itoa(int nbr, char *str, char *base_to, int size)
{
	int	len;
	int i;

	i = 0;
	len = ft_strlen(base_to);
	if (nbr == -2147483648)
	{
		str[--size] = base_to[-(nbr % len)];
		nbr = nbr / len;
	}
	if (nbr < 0)
	{
		str[i] = '-';
		i++;
		nbr = -nbr;
	}
	while (size > i)
	{
		str[size - 1] = base_to[(nbr % len)];
		nbr = nbr / len;
		size--;
	}
	return (str);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int		res;
	int		size;
	int		nb2;
	char	*str;

	res = 0;
	size = 0;
	str = 0;
	if (!ft_check_base(base_from) || !ft_check_base(base_to))
		return (0);
	res = ft_atoi(nbr, base_from);
	if (res <= 0)
		size++;
	nb2 = res;
	while (nb2 != 0)
	{
		nb2 = nb2 / ft_strlen(base_to);
		size++;
	}
	if (!(str = (char*)malloc(sizeof(char) * (size + 1))))
		return (0);
	str = ft_itoa(res, str, base_to, size);
	str[size] = '\0';
	return (str);
}

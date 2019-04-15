/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 17:34:47 by lnicosia          #+#    #+#             */
/*   Updated: 2019/04/15 18:46:47 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

double		ft_atof(const char *str)
{
	double	res;
	double	res1;
	double	res2;
	int		count;

	count = 0;
	res1 = ft_atoi(str);
	while (*str >= '0' && *str <= '9')
	{
		str++;
		count++;
	}
	if (!*str || *str != '.')
		return (res1);
	str++;
	count = 0;
	res2 = ft_atoi(str);
	while (*str >= '0' && *str <= '9')
	{
		str++;
		count++;
	}
	while (count > 0)
	{
		res2 /= 10;
		count--;
	}
	res = res1 + res2;
	return (res);
}

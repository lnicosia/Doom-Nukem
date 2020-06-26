/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 17:44:04 by sipatry           #+#    #+#             */
/*   Updated: 2020/05/01 19:03:49 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	skip_numbers(const char **str, int *count)
{
	while (**str >= '0' && **str <= '9')
	{
		(*str)++;
		(*count)++;
	}
}

static void	get_float_part(int *count, double *res2)
{
	while (*count > 0)
	{
		*res2 /= 10;
		(*count)--;
	}
}

double		ft_atof(const char *str)
{
	double	res;
	double	res1;
	double	res2;
	int		count;
	int		neg;

	neg = 1;
	if (*str == '-')
	{
		neg = -1;
		str++;
	}
	count = 0;
	res1 = ft_abs(ft_atoi(str));
	skip_numbers(&str, &count);
	if (!*str || *str != '.')
		return (neg * res1);
	str++;
	count = 0;
	res2 = ft_abs(ft_atoi(str));
	skip_numbers(&str, &count);
	get_float_part(&count, &res2);
	res = res1 + res2;
	return (neg * res);
}

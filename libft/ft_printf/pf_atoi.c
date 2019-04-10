/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaerhard <gaerhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/28 16:45:36 by gaerhard          #+#    #+#             */
/*   Updated: 2019/02/28 16:45:46 by gaerhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		pf_atoi(const char *str)
{
	int res;
	int i;
	int neg;

	res = 0;
	i = 0;
	neg = 1;
	while (str[i] == ' ' || (str[i] > 8 && str[i] < 14))
		i++;
	if (str[i] == '-')
	{
		neg = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] > 47 && str[i] < 58)
	{
		res = 10 * res + (str[i] - 48);
		i++;
	}
	return (neg * res);
}

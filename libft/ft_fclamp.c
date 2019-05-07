/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fclamp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 15:13:26 by lnicosia          #+#    #+#             */
/*   Updated: 2019/05/06 10:16:05 by sipatry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

double		ft_fclamp(double  nb, double min, double max)
{
	if (nb < min)
		nb = min;
	else if (nb > max)
		nb = max;
	return (nb);
}

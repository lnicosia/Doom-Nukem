/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/19 12:14:56 by lnicosia          #+#    #+#             */
/*   Updated: 2019/04/19 12:15:54 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

t_v2	new_v2(double x, double y)
{
	t_v2	new;

	new.x = x;
	new.y = y;
	return (new);
}

t_v3	new_v3(double x, double y, double z)
{
	t_v3	new;

	new.x = x;
	new.y = y;
	new.z = z;
	return (new);
}
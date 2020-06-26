/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_sector_utils2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipatry <sipatry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 12:12:07 by sipatry           #+#    #+#             */
/*   Updated: 2020/02/25 14:09:56 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

int		update_walls_map_lvl_tab(int index, int size, double ***tab)
{
	*tab = (double**)ft_delindex(*tab,
		sizeof(double*) * (size),
		sizeof(double*),
		sizeof(double*) * index);
	return (0);
}

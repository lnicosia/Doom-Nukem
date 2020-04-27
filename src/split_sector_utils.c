/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_sector_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipatry <sipatry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 12:12:07 by sipatry           #+#    #+#             */
/*   Updated: 2020/02/25 14:09:56 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

int		update_double_tab(int index, double size, double **tab)
{
	*tab = (double*)ft_delindex(*tab,
		sizeof(double) * (size),
		sizeof(double),
		sizeof(double) * index);
	return (0);
}

int		update_int_tab(int index, int size, int **tab)
{
	*tab = (int*)ft_delindex(*tab,
		sizeof(int) * (size),
		sizeof(int),
		sizeof(int) * index);
	return (0);
}

int		update_t_v2_tab(int index, int size, t_v2 **tab)
{
	*tab = (t_v2*)ft_delindex(*tab,
		sizeof(t_v2) * (size),
		sizeof(t_v2),
		sizeof(t_v2) * index);
	return (0);
}

int		update_t_list_tab(int index, int size, t_list ***tab)
{
	*tab = (t_list**)ft_delindex(*tab,
		sizeof(t_list*) * (size),
		sizeof(t_list*),
		sizeof(t_list*) * index);
	return (0);
}

int		update_t_wall_sprite_tab(int index, int size, t_wall_sprites **tab)
{
	*tab = (t_wall_sprites*)ft_delindex(*tab,
		sizeof(t_wall_sprites) * (size),
		sizeof(t_wall_sprites),
		sizeof(t_wall_sprites) * index);
	return (0);
}

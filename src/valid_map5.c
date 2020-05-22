/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_map5.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/21 17:46:57 by marvin            #+#    #+#             */
/*   Updated: 2020/05/21 18:07:38 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

int			check_valid_map_start_data(t_env *env)
{
	if (!env->nb_sectors)
	{
		ft_printf("You need at least one sector to go in"
		" 3d mode\n");
		return (1);
	}
	if (!env->editor.player_exist)
	{
		ft_printf("You need to place the player\n");
		return (1);
	}
	if (env->player.sector == -1 || env->player.starting_sector == -1)
	{
		ft_printf("Player position is not valid\n");
		return (1);
	}
	return (0);
}

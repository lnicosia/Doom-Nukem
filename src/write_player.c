/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_player.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/30 11:52:29 by lnicosia          #+#    #+#             */
/*   Updated: 2020/03/03 11:06:44 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "save.h"

void	write_player(int fd, t_env *env)
{
	ft_dprintf(fd, "\n%.*f %.*f %d\n",
	ft_min(5, get_decimal_len(env->player.starting_pos.y)),
	env->player.starting_pos.y,
	ft_min(5, get_decimal_len(env->player.starting_pos.x)),
	env->player.starting_pos.x,
	(int)(env->player.player_init_data.camera.angle * CONVERT_DEGREES) % 360);
}

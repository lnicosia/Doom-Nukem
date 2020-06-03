/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_player.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/30 11:52:29 by lnicosia          #+#    #+#             */
/*   Updated: 2020/03/03 16:31:16 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "save.h"

void	write_player(int fd, t_env *env)
{
	ft_dprintf(fd, "\n%.*f %.*f %d %d %d %.*f\n",
	ft_min(5, get_decimal_len(env->player.starting_pos.y)),
	env->player.starting_pos.y,
	ft_min(5, get_decimal_len(env->player.starting_pos.x)),
	env->player.starting_pos.x,
	(int)(env->player.init_data.camera.angle) % 360,
	env->player.health, env->player.armor,
	ft_min(5, get_decimal_len(env->player.start_speed)),
	env->player.start_speed);
}

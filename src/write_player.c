/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_player.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/30 11:52:29 by lnicosia          #+#    #+#             */
/*   Updated: 2019/09/18 11:26:43 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "save.h"

void	write_player(int fd, t_env *env)
{
	ft_dprintf(fd, "\n%.*f %.*f %d\n",
			ft_min(5, get_decimal_len(env->player.pos.y)), env->player.pos.y,
			ft_min(5, get_decimal_len(env->player.pos.x)), env->player.pos.x,
			(int)(env->player.camera.angle * CONVERT_DEGREES) % 360);
}

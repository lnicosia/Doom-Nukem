/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_player.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/30 11:52:29 by lnicosia          #+#    #+#             */
/*   Updated: 2019/07/30 14:03:18 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "save.h"

void	write_player(int fd, t_env *env)
{
	ft_dprintf(fd, "\n%.3f %.3f %.3f %d\n",
			env->player.pos.y, env->player.pos.x,
			env->player.angle * CONVERT_DEGREES,
			env->player.sector);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interaction.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipatry <sipatry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 15:58:10 by sipatry           #+#    #+#             */
/*   Updated: 2019/11/04 12:29:59 by sipatry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

void	interactions(t_env *env)
{
	int	i;
	t_sector sector;

	i = 0;
	if (env->player.sector == -1)
		return ;
	sector = env->sectors[env->player.sector];
	if ((sector.status == 1 || sector.status == 2 || env->elevator.on) && !env->elevator.off)
		activate_elevator(env);
	else if (sector.status != 1 && env->elevator.off)
		env->elevator.off = 0;
	else if (env->sectors[env->player.sector].status == 3)
		activate_teleport(env);
	if (!env->hidden_sect.create)
		hidden_sectors(env);
}
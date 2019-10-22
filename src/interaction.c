/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interaction.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipatry <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 15:58:10 by sipatry           #+#    #+#             */
/*   Updated: 2019/09/17 14:38:00 by sipatry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

void	interactions(t_env *env)
{
	int	i;
	t_sector sector;

	i = 0;
	sector = env->sectors[env->player.sector];
	if ((sector.statue == 1 || sector.statue == 2) && !env->elevator.off)
		activate_elevator(env);
	else if (sector.statue != 1)
		env->elevator.off = 0;
//	else if (env->sectors[env->player.sector].statue == 2)
//		activate_teleport(env);
}

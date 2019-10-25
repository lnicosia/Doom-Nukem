/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interaction.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaerhard <gaerhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 15:58:10 by sipatry           #+#    #+#             */
/*   Updated: 2019/10/25 12:28:32 by sipatry          ###   ########.fr       */
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
	if ((sector.statue == 1 || sector.statue == 2 || env->elevator.on) && !env->elevator.off)
		activate_elevator(env);
	else if (sector.statue != 1 && env->elevator.off)
		env->elevator.off = 0;
	else if (env->sectors[env->player.sector].statue == 3)
		activate_teleport(env);
}

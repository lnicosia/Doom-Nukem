/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   teleporter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipatry <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 14:36:18 by sipatry           #+#    #+#             */
/*   Updated: 2019/10/25 11:49:06 by sipatry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

void	create_teleporter(t_env *env)
{
	int	i;

	i = 0;
	env->teleport.create = 1;
}

void	activate_teleport(t_env *env)
{
	if (env->sectors[env->player.sector].statue == 3)
	{
		env->player.pos.x = env->sectors[env->player.sector].tp.x;
		env->player.pos.y = env->sectors[env->player.sector].tp.y;
		update_player_z(env);
	}
}

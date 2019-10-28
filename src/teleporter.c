/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   teleporter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipatry <sipatry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 14:36:18 by sipatry           #+#    #+#             */
/*   Updated: 2019/10/28 19:10:17 by sipatry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

void	create_teleport(t_env *env)
{
	int	sector;
	t_v3	futur_pos;
	
	env->teleport.create = 1;
	futur_pos.x = env->teleport.tmp_pos.x;
	futur_pos.x = env->teleport.tmp_pos.x;
	futur_pos.y = 0;
	sector = 0;
	if ((sector = get_sector_no_z(env, futur_pos)) && env->teleport.selected )
	{
		ft_printf("tp created\n");
		env->sectors[sector].tp.x = futur_pos.x;
		env->sectors[sector].tp.y = futur_pos.y;
		env->teleport.create = 0;
		env->teleport.selected = 0;
		update_player_z(env);
		update_camera_position(&env->player.camera);
	}
	else
		ft_printf("Destination is outside of the map\n");
}

void	activate_teleport(t_env *env)
{
	if (env->sectors[env->player.sector].statue == 3)
	{
		env->player.pos.x = env->sectors[env->player.sector].tp.x;
		env->player.pos.y = env->sectors[env->player.sector].tp.y;
	}
}
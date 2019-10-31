/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_player.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipatry <sipatry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 15:58:46 by sipatry           #+#    #+#             */
/*   Updated: 2019/10/30 17:15:11 by sipatry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

int	check_player_z(t_env *env)
{
	env->player.pos.x = (env->sdl.mx - env->editor.center.x) / env->editor.scale;
	env->player.pos.y = (env->sdl.my - env->editor.center.y) / env->editor.scale;
	env->player.sector = get_sector_no_z(env, env->player.pos);
	env->player.camera.angle = 0;
	env->player.camera.angle_z = 0;
	env->player.camera.pos = env->player.pos;
	env->player.camera.pos.z = 6;
	env->player.eyesight = 6.0;
	ft_printf("player_z: %f | sector_height: %f\n", env->player.eyesight,
	env->sectors[env->player.sector].ceiling - env->sectors[env->player.sector].floor);
	if ((env->sectors[env->player.sector].ceiling
	- env->sectors[env->player.sector].floor) < env->player.eyesight)
	{
		env->player.pos.x = 0;
		env->player.pos.y = 0;
		env->player.sector = -1;
		env->player.camera.angle = 0;
		env->player.camera.angle_z = 0;
		env->player.camera.pos.z = 0;
		env->player.eyesight = 0;
		return (0);
	}
	return (1);
}

void	add_player(t_env *env)
{
	ft_printf("adding a player\n");
	env->player.pos.x = (env->sdl.mx - env->editor.center.x) / env->editor.scale;
	env->player.pos.y = (env->sdl.my - env->editor.center.y) / env->editor.scale;
	env->player.pos.z = 0;
	env->player.camera.angle = 0;
	env->player.camera.angle_z = 0;
	env->player.camera.pos = env->player.pos;
	env->player.camera.pos.z = 6;
	env->player.eyesight = 6;
	env->player.speed = 0.5;
	env->player.camera.angle_cos = cos(env->player.camera.angle);
	env->player.camera.angle_sin = sin(env->player.camera.angle);
	env->player.camera.perp_cos = cos(env->player.camera.angle - M_PI / 2);
	env->player.camera.perp_sin = sin(env->player.camera.angle - M_PI / 2);
	env->player.sector = get_sector_no_z(env,
			env->player.pos);
	if (env->player.sector != -1)
		update_player_z(env);
	env->player.highest_sect = env->player.pos.z;
	env->player.lowest_sect = env->player.pos.z;
}

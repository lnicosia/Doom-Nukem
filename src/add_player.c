/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_player.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaerhard <gaerhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 15:58:46 by sipatry           #+#    #+#             */
/*   Updated: 2019/08/21 13:42:07 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

void	add_player(t_env *env)
{
	env->player.pos.x = (env->sdl.mx - env->editor.center.x) / env->editor.scale;
	env->player.pos.y = (env->sdl.my - env->editor.center.y) / env->editor.scale;
	env->player.pos.z = 0;
	env->player.angle = 0;
	env->player.angle_z = 0;
	env->player.eyesight = 6;
	env->player.speed = 0.5;
	env->player.angle_cos = cos(env->player.angle);
	env->player.angle_cos = sin(env->player.angle);
	env->player.perp_cos = cos(env->player.angle - M_PI / 2);
	env->player.perp_sin = sin(env->player.angle - M_PI / 2);
	env->player.sector = get_sector_no_z(env,
			env->player.pos);
	if (env->player.sector != -1)
		update_player_z(env);
}

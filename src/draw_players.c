/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_players.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 10:38:52 by lnicosia          #+#    #+#             */
/*   Updated: 2019/09/19 14:51:57 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "render.h"

int			draw_players(t_camera camera, t_env *env)
{
	t_object	player;

	if (camera.pos.x == env->player.pos.x && camera.pos.y == env->player.pos.y
			&& camera.pos.z == env->player.head_z)
		return (1);
	player.pos = env->player.pos;
	player.sprite = 2;
	player.scale = 50;
	if (env->player.camera.angle < 0)
		player.angle = 360 + (int)(env->player.camera.angle * CONVERT_DEGREES) % 360;
	else
		player.angle = (int)(env->player.camera.angle * CONVERT_DEGREES) % 360;
	get_translated_object_pos(camera, &player);
	get_rotated_object_pos(camera, &player);
	draw_object(camera, &player, env);
	return (0);
}

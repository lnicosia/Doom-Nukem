/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_player.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/28 15:48:29 by lnicosia          #+#    #+#             */
/*   Updated: 2020/05/22 19:01:06 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include <math.h>

static void	compute_player_pos(t_env *env)
{
	int			i;
	t_v2		pos;
	t_sector	sector;

	i = 0;
	sector = env->sectors[0];
	pos = new_v2(0, 0);
	while (i < sector.nb_vertices)
	{
		pos.x += (env->vertices[sector.vertices[i]].x - env->player.pos.x);
		pos.y += (env->vertices[sector.vertices[i]].y - env->player.pos.y);
		i++;
	}
	pos.x /= sector.nb_vertices;
	pos.y /= sector.nb_vertices;
	env->player.pos.x = pos.x + 1;
	env->player.pos.y = pos.y;
	env->player.starting_pos.x = pos.x;
	env->player.starting_pos.y = pos.y;
}

void		add_player2(t_env *env)
{
	env->player.speed = 0.1;
	env->player.camera.angle_cos = cos(env->player.camera.angle);
	env->player.camera.angle_sin = sin(env->player.camera.angle);
	env->player.camera.perp_cos = cos(env->player.camera.angle - M_PI / 2);
	env->player.camera.perp_sin = sin(env->player.camera.angle - M_PI / 2);
	env->player.sector = get_sector_no_z(env,
			env->player.pos);
	env->player.highest_sect = env->player.sector;
	if (env->player.sector != -1)
		update_player_z(env);
	env->player.head_z = env->player.pos.z + env->player.eyesight;
	env->player.camera.pos = env->player.pos;
	env->player.camera.pos.z = env->player.head_z;
	update_camera_position(&env->player.camera);
}

void		add_player(t_env *env)
{
	if (!env->editor.player_exist)
	{
		env->editor.player_exist = 1;
		compute_player_pos(env);
	}
	else
	{
		env->player.pos.x = (env->sdl.mx - env->editor.center.x)
		/ env->editor.scale;
		env->player.pos.y = (env->sdl.my - env->editor.center.y)
		/ env->editor.scale;
		env->player.starting_pos.x = (env->sdl.mx - env->editor.center.x)
		/ env->editor.scale;
		env->player.starting_pos.y = (env->sdl.my - env->editor.center.y)
		/ env->editor.scale;
	}
	env->player.camera.angle = 0;
	env->player.camera.angle_z = 0;
	env->player.camera.pos = env->player.pos;
	env->player.camera.pos.z = 6;
	env->player.eyesight = 6;
	add_player2(env);
	ft_printf("h %d\n", env->player.highest_sect);
	ft_printf("s %d\n", env->player.sector);
}

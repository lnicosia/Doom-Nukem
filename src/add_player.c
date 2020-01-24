/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_player.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipatry <sipatry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 15:58:46 by sipatry           #+#    #+#             */
/*   Updated: 2020/01/21 18:22:13 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

static void	calcul_player_pos(t_env *env)
{
	int		i;
	t_v2	pos;
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
	env->player.pos.x = pos.x;
	env->player.pos.y = pos.y;
}

int			check_player_z(t_env *env)
{
	int	sector;

	sector = get_sector_no_z(env, env->player.pos);
	if (sector == -1)
			return (1);
	env->player.sector = sector;
	env->player.pos.x = (env->sdl.mx - env->editor.center.x) / env->editor.scale;
	env->player.pos.y = (env->sdl.my - env->editor.center.y) / env->editor.scale;
	env->player.camera.angle = 0;
	env->player.camera.angle_z = 0;
	env->player.camera.pos = env->player.pos;
	env->player.camera.pos.z = 6;
	env->player.eyesight = 6.0;
	env->player.highest_sect = env->player.sector;
	/*ft_printf("player_z: %f | sector_height: %f\n", env->player.eyesight,
	env->sectors[env->player.sector].ceiling - env->sectors[env->player.sector].floor);*/
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

void		add_player(t_env *env)
{
	if (!env->editor.player_exist)
	{
		env->editor.player_exist = 1;
		calcul_player_pos(env);
	}
	else
	{
		env->player.pos.x = (env->sdl.mx - env->editor.center.x) / env->editor.scale;
		env->player.pos.y = (env->sdl.my - env->editor.center.y) / env->editor.scale;
	}
	env->player.camera.angle = 0;
	env->player.camera.angle_z = 0;
	env->player.camera.pos = env->player.pos;
	env->player.camera.pos.z = 6;
	env->player.eyesight = 6;
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

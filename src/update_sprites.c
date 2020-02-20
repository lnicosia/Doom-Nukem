/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_sprites.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 13:28:39 by lnicosia          #+#    #+#             */
/*   Updated: 2020/02/20 10:30:12 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

void	update_enemy(t_env *env, int i)
{
	update_enemy_light(env, i);
	update_enemy_z(env, i);
}

void	update_object(t_env *env, int i)
{
	update_object_light(env, i);
	update_object_z(env, i);
}

void	update_enemy_z(t_env *env, int i)
{
	env->enemies[i].sector = get_sector_no_z_origin(env, env->enemies[i].pos,
	env->enemies[i].sector);
	if (env->enemies[i].sector != -1)
		env->enemies[i].pos.z =
		get_floor_at_pos(env->sectors[env->enemies[i].sector],
		env->enemies[i].pos, env) + env->enemies[i].height_on_floor;
	else
		env->enemies[i].pos.z = 0;
}

void	update_object_z(t_env *env, int i)
{
	env->objects[i].sector = get_sector_no_z_origin(env, env->objects[i].pos,
	env->objects[i].sector);
	if (env->objects[i].sector != -1)
		env->objects[i].pos.z =
		get_floor_at_pos(env->sectors[env->objects[i].sector],
		env->objects[i].pos, env);
	else
		env->objects[i].pos.z = 0;
}

void	update_sector_enemies_z(t_env *env, int sector)
{
	int	i;

	i = 0;
	while (i < env->nb_enemies)
	{
		if (env->enemies[i].sector == sector)
			update_enemy_z(env, i);
		i++;
	}
}

void	update_sector_entities_z(t_env *env, int sector)
{
	update_sector_enemies_z(env, sector);
	if (env->player.sector == sector)
		update_player_z(env);
}

void	update_sector_entities_light(t_env *env, int sector)
{
	int	i;

	i = 0;
	while (i < env->nb_enemies)
	{
		if (env->enemies[i].sector == sector)
			update_enemy_light(env, i);
		i++;
	}
	i = 0;
	while (i < env->nb_objects)
	{
		if (env->objects[i].sector == sector)
			update_object_light(env, i);
		i++;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projectiles_collisions.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 17:48:32 by gaerhard          #+#    #+#             */
/*   Updated: 2020/04/30 18:45:00 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "collision.h"

int		projectile_player_collision(t_env *env, t_v3 pos, t_v3 dest,
double radius)
{
	if (env->player.health > 0 && distance_two_points_2d(env->player.pos.x,
		env->player.pos.y, pos.x, pos.y) < env->player.size_2d + radius
		&& pos.z <= env->player.head_z && pos.z >= env->player.pos.z)
		return (1);
	if (env->player.health > 0 && hitbox_collision(new_v2(pos.x, pos.y),
		new_v2(dest.x, dest.y), new_v2(env->player.pos.x, env->player.pos.y),
		radius + env->player.size_2d) && pos.z <= env->player.head_z
		&& pos.z >= env->player.pos.z)
		return (1);
	return (0);
}

void	projectile_object_collision_line(t_env *env,
t_projectile_collision *collision, int i)
{
	if (env->objects[i].health > 0
		&& distance_two_points_2d(env->objects[i].pos.x, env->objects[i].pos.y,
		collision->pos.x, collision->pos.y) < env->objects[i].size_2d
		+ collision->radius && env->objects[i].exists
		&& env->objects[i].solid && collision->pos.z <= env->objects[i].height
		+ env->objects[i].pos.z && collision->pos.z >= env->objects[i].pos.z)
	{
		collision->distance = distance_two_points_2d(env->objects[i].pos.x,
		env->objects[i].pos.y, collision->pos.x, collision->pos.y);
		if (collision->distance < collision->nearest_dist)
		{
			collision->nearest_dist = collision->distance;
			collision->object = i;
		}
	}
}

void	projectile_object_collision_hitbox(t_env *env,
t_projectile_collision *collision, int i)
{
	if (hitbox_collision(new_v2(collision->pos.x, collision->pos.y),
		new_v2(collision->dest.x, collision->dest.y),
		new_v2(env->objects[i].pos.x, env->objects[i].pos.y),
		collision->radius + env->objects[i].size_2d) && env->objects[i].exists
		&& env->objects[i].solid && collision->pos.z <= env->objects[i].height
		+ env->objects[i].pos.z && collision->pos.z >= env->objects[i].pos.z)
	{
		collision->distance = distance_two_points_2d(env->objects[i].pos.x,
		env->objects[i].pos.y, collision->pos.x, collision->pos.y);
		if (collision->distance < collision->nearest_dist)
		{
			collision->nearest_dist = collision->distance;
			collision->object = i;
		}
	}
}

int		projectile_object_collision(t_env *env, t_v3 pos, t_v3 dest,
double radius)
{
	int						i;
	t_projectile_collision	collision;

	i = 0;
	collision.object = -1;
	collision.nearest_dist = 2147483647;
	collision.pos = pos;
	collision.dest = dest;
	collision.radius = radius;
	while (i < env->nb_objects)
	{
		projectile_object_collision_line(env, &collision, i);
		projectile_object_collision_hitbox(env, &collision, i);
		i++;
	}
	return (collision.object);
}

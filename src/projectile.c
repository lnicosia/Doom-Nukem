/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projectile.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaerhard <gaerhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/01 18:23:02 by gaerhard          #+#    #+#             */
/*   Updated: 2020/03/05 17:28:38 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "collision.h"

int		projectile_hits_structure(int collision, t_projectile *projectile,
t_env *env)
{
	if (collision == -2
	 	&& env->sectors[projectile->sector].ceiling_texture >= 0)
	{
	  	if (projectile_hits_ceiling(projectile, env))
		  	return (-1);
	}
	else if (collision == -3
	  	&& env->sectors[projectile->sector].floor_texture >= 0)
	{
	  	if (projectile_hits_floor(projectile, env))
		  	return (-1);
	}
	else if (collision >= 0
	  	&& env->sectors[projectile->sector].textures[collision] >= 0)
	{
	  	if (projectile_hits_wall(collision, projectile, env))
		  	return (-1);
	}
	return (0);
}

int		process_current_projectile2(t_v3 move, t_projectile *projectile,
t_list **tmp, t_env *env)
{
	int		collision;

	collision = collision_projectiles(env, move,
	new_motion(projectile->sector, projectile->size_2d, 0, projectile->pos));
	if (collision == -1)
	  	projectile_hits_nothing(move, projectile, tmp, env);
	else
	{
	  	if (projectile_hits_structure(collision, projectile, env))
		  	return (-1);
		*tmp = ft_lstdelnode(&env->projectiles, *tmp);
	}
	return (0);
}

int		process_current_projectile(t_projectile *projectile, t_list **tmp,
t_env *env)
{
	int		nb;
	t_v3	move;

	move = sprite_movement(env, projectile->speed, projectile->pos,
	projectile->dest);
	nb = enemy_collision(env, projectile->pos,
	new_v3(projectile->pos.x + move.x, projectile->pos.y + move.y,
	projectile->pos.z + move.z), projectile->size_2d);
	if (nb >= 0)
	  	return (projectile_hits_enemy(nb, projectile, tmp, env));
	nb = projectile_object_collision(env, projectile->pos,
		new_v3(projectile->pos.x + move.x, projectile->pos.y + move.y,
		projectile->pos.z + move.z), projectile->size_2d); 
	if (nb >= 0 && env->objects[nb].solid)
	  	return (projectile_hits_object(projectile, tmp, env));
	if (projectile_player_collision(env, projectile->pos,
		new_v3(projectile->pos.x + move.x, projectile->pos.y + move.y,
		projectile->pos.z + move.z), projectile->size_2d))
	  	return (projectile_hits_player(projectile, tmp, env));
	return (process_current_projectile2(move, projectile, tmp, env));
}

int		projectiles_movement(t_env *env)
{
	t_list	*tmp;

	if (env->projectiles)
	{
		tmp = env->projectiles;
		while (tmp)
		{
		  	if (process_current_projectile((t_projectile*)tmp->content,
				&tmp, env))
				return (-1);
		}
	}
	return (0);
}

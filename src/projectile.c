/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projectile.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaerhard <gaerhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/01 18:23:02 by gaerhard          #+#    #+#             */
/*   Updated: 2019/11/08 18:54:02 by gaerhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

void	projectile_coord(t_v3 pos, t_projectile *projectile, double angle_z)
{
	projectile->pos.x = 3 * cos(projectile->angle * CONVERT_RADIANS) + pos.x;
	projectile->pos.y = 3 * sin(projectile->angle * CONVERT_RADIANS) + pos.y;
	projectile->pos.z = 3 * -angle_z + pos.z + 5.6;
	projectile->dest.x = 100000 * cos(projectile->angle * CONVERT_RADIANS) + pos.x;
	projectile->dest.y = 100000 * sin(projectile->angle * CONVERT_RADIANS) + pos.y;
	projectile->dest.z = 100000 * -angle_z + pos.z + 5.6;
}

int		create_projectile(t_env *env, int sprite, t_v3 pos, double angle)
{
	t_list	*new;

	if (!(new = ft_lstnew(&env->projectile, sizeof(t_projectile))))
		return (ft_printf("Error when creating new projectile\n"));
	ft_lstpushback(&env->projectiles, new);
	((t_projectile*)new->content)->sprite = sprite;
	((t_projectile*)new->content)->angle = angle;
	projectile_coord(pos, ((t_projectile*)new->content), env->player.camera.angle_z);
	((t_projectile*)new->content)->scale = 50;
	((t_projectile*)new->content)->exists = 1;
	return (0);
}

void	projectiles_movement(t_env *env)
{
	t_v3	move;
	t_list	*tmp;

	if (env->projectiles)
	{
		tmp = env->projectiles;
		if (tmp)
		{
			move = sprite_movement(0.8, ((t_projectile*)tmp->content)->pos, ((t_projectile*)tmp->content)->dest);
			((t_projectile*)tmp->content)->pos.x += move.x;
			((t_projectile*)tmp->content)->pos.y += move.y;
			((t_projectile*)tmp->content)->pos.z += move.z;
		}
		while (tmp->next)
		{
			tmp = tmp->next;
			move = sprite_movement(0.8, ((t_projectile*)tmp->content)->pos, ((t_projectile*)tmp->content)->dest);
			((t_projectile*)tmp->content)->pos.x += move.x;
			((t_projectile*)tmp->content)->pos.y += move.y;
			((t_projectile*)tmp->content)->pos.z += move.z;
		}
	}
	//projectile->pos.z += move.z;
}
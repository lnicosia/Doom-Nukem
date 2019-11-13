/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projectile.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaerhard <gaerhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/01 18:23:02 by gaerhard          #+#    #+#             */
/*   Updated: 2019/11/13 12:27:34 by gaerhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "collision.h"

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
	t_v3			move;
	t_list			*tmp;
	t_projectile	*projectile;

	if (env->projectiles)
	{
		tmp = env->projectiles;
		if (tmp)
		{
			projectile = (t_projectile*)tmp->content;
			move = sprite_movement(0.8, projectile->pos, projectile->dest);
			if (collision_projectiles(env, move, new_movement(projectile->sector, projectile->size_2d,
				0, projectile->pos)))
			{
				projectile->pos.x += move.x;
				projectile->pos.y += move.y;
				projectile->pos.z += move.z;
				projectile->sector = get_sector_no_z_origin(env, projectile->pos, projectile->sector);
			}
			else
				ft_printf("BOOOOM!!!!!!\n");
		}
		while (tmp->next)
		{
			tmp = tmp->next;
			projectile = (t_projectile*)tmp->content;
			move = sprite_movement(0.8, projectile->pos, projectile->dest);
			if (collision_projectiles(env, move, new_movement(projectile->sector, projectile->size_2d,
				0, projectile->pos)))
			{
				projectile->pos.x += move.x;
				projectile->pos.y += move.y;
				projectile->pos.z += move.z;
				projectile->sector = get_sector_no_z_origin(env, projectile->pos, projectile->sector);
			}
			else
				ft_printf("EXPLOSIOOOON!!!!\n");
		}
	}
}
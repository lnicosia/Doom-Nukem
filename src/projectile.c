/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projectile.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaerhard <gaerhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/01 18:23:02 by gaerhard          #+#    #+#             */
/*   Updated: 2019/11/14 18:25:54 by gaerhard         ###   ########.fr       */
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

int		create_projectile(t_env *env, t_projectile_data data, t_projectile_stats stats, double angle_z)
{
	t_list	*new;

	if (!(new = ft_lstnew(&env->projectile, sizeof(t_projectile))))
		return (ft_printf("Error when creating new projectile\n"));
	ft_lstpushback(&env->projectiles, new);
	((t_projectile*)new->content)->sprite = data.sprite;
	((t_projectile*)new->content)->speed = stats.speed;
	((t_projectile*)new->content)->angle = data.angle;
	projectile_coord(data.pos, ((t_projectile*)new->content), angle_z);
	((t_projectile*)new->content)->scale = data.scale;
	((t_projectile*)new->content)->damage = stats.damage;
	((t_projectile*)new->content)->size_2d = stats.size_2d;
	((t_projectile*)new->content)->exists = 1;
	return (0);
}
#include "stdio.h"
void	projectiles_movement(t_env *env)
{
	int				nb;
	t_v3			move;
	t_list			*tmp;
	t_projectile	*projectile;

	if (env->projectiles)
	{
		tmp = env->projectiles;
		while (tmp)
		{
			projectile = (t_projectile*)tmp->content;
			move = sprite_movement(env, projectile->speed, projectile->pos, projectile->dest);
			nb = enemy_collision(env, projectile->pos, projectile->size_2d);
			if (nb >= 0)
			{
				env->enemies[nb].health -= projectile->damage;
				env->enemies[nb].hit = 1;
				tmp = ft_lstdelnode(&env->projectiles, tmp);
				continue ;
			}
			if (projectile_player_collision(env, projectile->pos, projectile->size_2d))
			{
				env->player.hit = 1;
				env->player.health -= projectile->damage;
				tmp = ft_lstdelnode(&env->projectiles, tmp);
				continue ;
			}
			if (collision_projectiles(env, move, new_movement(projectile->sector, projectile->size_2d,
				0, projectile->pos)))
			{
				projectile->pos.x += move.x;
				projectile->pos.y += move.y;
				projectile->pos.z += move.z;
				projectile->sector = get_sector_no_z_origin(env, projectile->pos, projectile->sector);
				tmp = tmp->next;
			}
			else
			{
				tmp = ft_lstdelnode(&env->projectiles, tmp);
				ft_printf("EXPLOSIOOOON!!!!\n");
			}
		}
	}
}
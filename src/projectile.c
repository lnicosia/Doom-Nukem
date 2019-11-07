/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projectile.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaerhard <gaerhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/01 18:23:02 by gaerhard          #+#    #+#             */
/*   Updated: 2019/11/06 11:21:16 by gaerhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

void	projectile_coord(t_v3 pos, t_projectile *projectile, double angle_z)
{
	/*double phi;
	double theta;*/

	(void)angle_z;
	/*phi = atan2(pos.y, pos.x);
	theta = acos((pos.z / 5));
	projectile->pos.x = 5 * sin(theta) * cos(phi) + pos.x;
	projectile->pos.y = 5 * sin(theta) * sin(phi) + pos.y;
	projectile->pos.z = 5 * cos(phi) + pos.z + 4;
	theta = acos((pos.z / 100000));
	projectile->dest.x = 100000 * sin(theta) * cos(phi) + pos.x;
	projectile->dest.y = 100000 * sin(theta) * sin(phi) + pos.y;
	projectile->dest.z = projectile->pos.z;
	*/
	projectile->pos.x = 5 * cos(projectile->angle * CONVERT_RADIANS) + pos.x;
	projectile->pos.y = 5 * sin(projectile->angle * CONVERT_RADIANS) + pos.y;
	projectile->pos.z = pos.z + 4;
	projectile->dest.x = 100000 * cos(projectile->angle * CONVERT_RADIANS) + pos.x;
	projectile->dest.y = 100000 * sin(projectile->angle * CONVERT_RADIANS) + pos.y;
	projectile->dest.z = pos.z + 4;
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
	ft_printf("<-------------->\n");
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
			ft_printf("player     x: %f y: %f z: %f\n", env->player.pos.x, env->player.pos.y, env->player.pos.z);
			ft_printf("projectile x: %f y: %f z: %f\n", ((t_projectile*)tmp->content)->pos.x, ((t_projectile*)tmp->content)->pos.y, ((t_projectile*)tmp->content)->pos.z);
			move = sprite_movement(0.8, ((t_projectile*)tmp->content)->pos, ((t_projectile*)tmp->content)->dest);
			((t_projectile*)tmp->content)->pos.x += move.x * 0;
			((t_projectile*)tmp->content)->pos.y += move.y * 0;
			((t_projectile*)tmp->content)->pos.z += move.z * 0;
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
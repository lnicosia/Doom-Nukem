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

int	create_projectile(t_env *env, int sprite, t_v3 pos, t_v3 dest)
{
	t_list	*new;
	t_list	*tmp;

	if (!(new = ft_lstnew(&env->projectile, sizeof(t_projectile))))
		return (ft_printf("Error when creating new projectile\n"));
	ft_lstpushback(&env->projectiles, new);
	tmp = env->projectiles;
	((t_projectile*)new->content)->sprite = sprite;
	((t_projectile*)new->content)->pos.x = pos.x;
	((t_projectile*)new->content)->pos.y = pos.y;
	((t_projectile*)new->content)->pos.z = pos.z + 6;
	((t_projectile*)new->content)->dest.x = dest.x;
	((t_projectile*)new->content)->dest.y = dest.y;
	((t_projectile*)new->content)->dest.z = dest.z;
	((t_projectile*)new->content)->scale = 50;
	((t_projectile*)new->content)->angle = env->player.camera.angle * CONVERT_DEGREES;
	((t_projectile*)new->content)->exists = 1;
	ft_printf("<-------------->\n");
	return (0);
}


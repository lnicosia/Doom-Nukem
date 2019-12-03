/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   explosion.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaerhard <gaerhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/02 21:06:13 by gaerhard          #+#    #+#             */
/*   Updated: 2019/12/03 17:49:47 by gaerhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

t_explosion_data	new_explosion_data(t_v3 pos, double radius, int damage, int sprite)
{
	t_explosion_data	new;

	new.pos = pos;
	new.radius = radius;
	new.damage = damage;
	new.sprite = sprite;
	return (new);
}

int		create_explosion(t_env *env, t_explosion_data data)
{
	t_list		*new;

	ft_printf("create explosion\n");
	if (!(new = ft_lstnew(&env->explosion, sizeof(t_explosion))))
		return (ft_printf("Error when creating explosion\n"));
	ft_lstpushback(&env->explosions, new);
	((t_explosion*)new->content)->sprite = data.sprite;
	((t_explosion*)new->content)->damage = data.damage;
	((t_explosion*)new->content)->radius = data.radius;
	((t_explosion*)new->content)->pos = data.pos;
	((t_explosion*)new->content)->damage_burst = 1;
	return (0);
}

int		explosion_player(t_env *env)
{
	t_list *tmp;
	double	distance;

	tmp = env->explosions;
	while (tmp)
	{
		if (((t_explosion*)tmp->content)->damage_burst)
		{
			distance = distance_two_points_3d(new_v3(env->player.pos.x, env->player.pos.y, env->player.pos.z + env->player.eyesight / 2), ((t_explosion*)tmp->content)->pos);
			ft_printf("distance in explosion_player = %f\n", distance);
			if (distance < ((t_explosion*)tmp->content)->radius && ((t_explosion*)tmp->content)->damage_burst)
				env->player.health -= aoe_damage(distance, ((t_explosion*)tmp->content)->radius, ((t_explosion*)tmp->content)->damage);
			((t_explosion*)tmp->content)->damage_burst = 0;
		}
		env->player.health = ft_clamp(env->player.health, 0, 100);
		tmp = tmp->next;
	}
	return (0);
}
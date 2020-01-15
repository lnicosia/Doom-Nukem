/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   explosion.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaerhard <gaerhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/02 21:06:13 by gaerhard          #+#    #+#             */
/*   Updated: 2020/01/15 14:36:36 by gaerhard         ###   ########.fr       */
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

int		create_explosion(t_env *env, t_explosion_data data, int centered_sprite)
{
	t_list		*new;

	if (!(new = ft_lstnew(&env->explosion, sizeof(t_explosion))))
		return (ft_printf("Error when creating explosion\n"));
	ft_lstpushback(&env->explosions, new);
	((t_explosion*)new->content)->sprite = data.sprite;
	((t_explosion*)new->content)->damage = data.damage;
	((t_explosion*)new->content)->radius = data.radius;
	((t_explosion*)new->content)->pos = data.pos;
	((t_explosion*)new->content)->damage_burst = 1;
	((t_explosion*)new->content)->scale = data.radius;
	((t_explosion*)new->content)->explosion_anim.start = 0;
	((t_explosion*)new->content)->centered_sprite = centered_sprite;
	return (0);
}

int		explosion_collision_player(t_env *env)
{
	t_list *tmp;
	double	distance;
	int		damage;

	tmp = env->explosions;
	while (tmp)
	{
		if (((t_explosion*)tmp->content)->damage_burst)
		{
			distance = distance_two_points_3d(new_v3(env->player.pos.x, env->player.pos.y, env->player.pos.z + env->player.eyesight / 2), ((t_explosion*)tmp->content)->pos);
			if (distance < ((t_explosion*)tmp->content)->radius && ((t_explosion*)tmp->content)->damage_burst)
			{
				env->player.hit = 1;
				damage = aoe_damage(distance, ((t_explosion*)tmp->content)->radius, ((t_explosion*)tmp->content)->damage);
				env->player.health -= ft_clamp(damage - env->player.armor, 0, damage);
				env->player.armor -= ft_clamp(damage, 0, env->player.armor);
			}
			env->player.health = ft_clamp(env->player.health, 0, 100);
			((t_explosion*)tmp->content)->damage_burst = 0;
			tmp = tmp->next;
		}
		else
			tmp = tmp->next;
	}
	return (0);
}

int		explosion_collision_objects(t_env *env)
{
	t_list *tmp;
	double	distance;
	int		damage;
	int		i;

	tmp = env->explosions;
	while (tmp)
	{
		i = 0;
		while (i < env->nb_objects)
		{
			if (((t_explosion*)tmp->content)->damage_burst && env->objects[i].destructible && env->objects[i].health > 0)
			{
				distance = distance_two_points_3d(new_v3(env->objects[i].pos.x, env->objects[i].pos.y, env->objects[i].pos.z), ((t_explosion*)tmp->content)->pos);
				if (distance < ((t_explosion*)tmp->content)->radius && ((t_explosion*)tmp->content)->damage_burst)
				{
					damage = aoe_damage(distance, ((t_explosion*)tmp->content)->radius, ((t_explosion*)tmp->content)->damage);
					env->objects[i].health -= damage;
					if (env->objects[i].explodes && env->objects[i].health <= 0)
					{
						create_explosion(env,
							new_explosion_data(env->objects[i].pos, env->objects[i].explosion_size, env->objects[i].damage, env->object_sprites[env->objects[i].sprite].death_counterpart), 0);
						env->objects[i].exists = 0;
					}
				}
			}
			i++;
		}
		tmp = tmp->next;
	}
	return (0);
}
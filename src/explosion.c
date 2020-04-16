/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   explosion.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaerhard <gaerhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/02 21:06:13 by gaerhard          #+#    #+#             */
/*   Updated: 2020/03/03 12:01:20 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

void	current_explosion_collision_player(t_explosion *explosion, t_env *env)
{
	double	distance;
	int		damage;

	if (explosion->damage_burst == 1)
	{
		distance = distance_two_points_3d(new_v3(env->player.pos.x,
		env->player.pos.y, env->player.pos.z + env->player.eyesight / 2),
		explosion->pos);
		if (distance < explosion->radius
		  	&& explosion->damage_burst)
		{
			env->player.hit = 1;
			damage = aoe_damage(distance, explosion->radius, explosion->damage);
			if (!env->player.invincible)
			{
				env->player.health -=
				ft_clamp(damage - env->player.armor, 0, damage);
				env->player.armor -=
				ft_clamp(damage, 0, env->player.armor);
			}
		}
		explosion->damage_burst = 0;
		env->nb_explosions--;
	}
}

int		explosion_collision_player(t_env *env)
{
	t_list *tmp;

	tmp = env->explosions;
	while (tmp)
	{
		current_explosion_collision_player(((t_explosion*)tmp->content), env);
		tmp = tmp->next;
	}
	return (0);
}

void	explosion_collision_object(t_explosion *explosion, int i, t_env *env)
{
	double	distance;
	int		damage;

	if (explosion->damage_burst == 1 && env->objects[i].destructible
	  	&& env->objects[i].health > 0)
	{
		distance = distance_two_points_3d(new_v3(env->objects[i].pos.x,
		env->objects[i].pos.y, env->objects[i].pos.z), explosion->pos);
		if (distance < explosion->radius && explosion->damage_burst == 1)
		{
			damage = aoe_damage(distance, explosion->radius, explosion->damage);
			env->objects[i].health -= damage;
			if (env->objects[i].explodes && env->objects[i].health <= 0)
			{
				create_explosion(env,
					new_explosion_data(env->objects[i].pos,
					env->objects[i].explosion_size,
					env->objects[i].damage,
					env->object_sprites[env->objects[i].sprite].
					death_counterpart), 0);
				env->objects[i].exists = 0;
			}
		}
	}
}

int		explosion_collision_objects(t_env *env)
{
	t_list *tmp;
	int		i;

	activate_explosions(env);
	tmp = env->explosions;
	while (tmp)
	{
		i = 0;
		while (i < env->nb_objects)
		{
		  	explosion_collision_object(((t_explosion*)tmp->content), i, env);
			i++;
		}
		tmp = tmp->next;
	}
	return (0);
}

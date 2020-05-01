/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   weapons3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/01 12:09:08 by lnicosia          #+#    #+#             */
/*   Updated: 2020/05/01 12:09:12 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

int		enemy_hit(t_env *env, int i)
{
	env->enemies[i].health -= damage_done(env, env->enemies[i].rotated_pos.z);
	env->player.touched = 1;
	if (env->enemies[i].health <= 0)
	{
		env->player.killed++;
		if (env->enemies[i].nb_death_events > 0
			&& env->enemies[i].death_events
			&& start_event(&env->enemies[i].death_events,
			&env->enemies[i].nb_death_events, env))
			return (-1);
	}
	env->enemies[i].hit = 1;
	return (0);
}

int		object_hit(t_env *env, int i)
{
	env->objects[i].health -= damage_done(env, env->objects[i].rotated_pos.z);
	if (env->objects[i].explodes && env->objects[i].health <= 0)
	{
		if (create_explosion(env, new_explosion_data(env->objects[i].pos,
			env->objects[i].explosion_size, env->objects[i].damage,
			env->object_sprites[env->objects[i].sprite].death_counterpart), 0))
			return (-1);
		env->nb_explosions++;
		env->objects[i].exists = 0;
	}
	return (0);
}

int		hitscan_shot(t_env *env)
{
	int	i;

	i = -1;
	env->shooting = 1;
	while (++i < env->nb_enemies)
	{
		if (hitscan_enemies(env, i) == 1)
		{
			if (enemy_hit(env, i))
				return (-1);
		}
	}
	i = -1;
	while (++i < env->nb_objects)
	{
		if (env->objects[i].destructible && env->objects[i].exists)
		{
			if (hitscan_objects(env, i) == 1)
			{
				if (object_hit(env, i))
					return (-1);
			}
		}
	}
	return (0);
}

int		shot(t_env *env)
{
	if (env->weapons[env->player.curr_weapon].ammo_type == ROCKET)
	{
		if (create_projectile(env, new_projectile_data(env->player.pos,
			env->player.camera.angle, 1, 1),
			new_projectile_stats(0.5, env->weapons[env->player.curr_weapon].
			damage, 0.8, env->player.eyesight - 0.4),
			new_projectile_data_2(env->player.camera.angle_z,
			env->player.size_2d)))
			return (-1);
	}
	else
	{
		if (hitscan_shot(env))
			return (-1);
	}
	env->player.nb_shots += 1;
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_enemy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaerhard <gaerhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 13:32:16 by sipatry           #+#    #+#             */
/*   Updated: 2020/01/31 18:39:16 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

int	add_enemy(t_env *env)
{
	t_enemies	enemy;

	enemy.num = env->nb_enemies;
	enemy.pos.x = (env->sdl.mx - env->editor.center.x) / env->editor.scale;
	enemy.pos.y = (env->sdl.my - env->editor.center.y) / env->editor.scale;
	enemy.sprite = env->editor.current_enemy;
	enemy.scale = 5;
	enemy.angle = 0;
	enemy.exists = 1;
	enemy.sector = get_sector_no_z(env, new_v3(enemy.pos.x, enemy.pos.y, 0));
	enemy.speed = 40;
	enemy.map_hp = 40;
	enemy.damage = 25;
	if (enemy.sector != -1)
	{
		enemy.light_color = env->sectors[enemy.sector].light_color;
		enemy.brightness = env->sectors[enemy.sector].brightness;
		enemy.intensity = env->sectors[enemy.sector].intensity;
		enemy.pos.z = get_floor_at_pos(env->sectors[enemy.sector],
		enemy.pos, env);
	}
	else
	{
		enemy.light_color = 0xFFFFFFFF;
		enemy.brightness = 0;
		enemy.intensity = 0;
		enemy.pos.z = 0;
	}
	if (!(env->enemies = (t_enemies*)ft_realloc(env->enemies, sizeof(t_enemies) * env->nb_enemies, sizeof(t_enemies) * (env->nb_enemies + 1))))
		return (ft_printf("Could not realloc enemys\n"));
	env->enemies[env->nb_enemies] = enemy;
	env->editor.create_enemy = 0;
	env->nb_enemies++;
	env->editor.add_enemy.state = UP;
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_enemy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaerhard <gaerhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 13:32:16 by sipatry           #+#    #+#             */
/*   Updated: 2020/02/03 15:28:29 by lnicosia         ###   ########.fr       */
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
	enemy.angle = 0;
	enemy.exists = 1;
	enemy.sector = get_sector_no_z(env, new_v3(enemy.pos.x, enemy.pos.y, 0));
	enemy.speed = 40;
	enemy.map_hp = 40;
	enemy.damage = 25;
	if (enemy.sprite < CYBER_DEMON)
	{
		enemy.height_on_floor = 5;
		enemy.scale = 5;
	}
	else if (enemy.sprite < MAX_ENEMY_SPRITES)
	{
		enemy.height_on_floor = 0;
		enemy.scale = 5;
	}
	else
	{
		enemy.height_on_floor = 0;
		enemy.scale = 5;
	}
	if (!(env->enemies = (t_enemies*)ft_realloc(env->enemies,
		sizeof(t_enemies) * env->nb_enemies, sizeof(t_enemies)
		* (env->nb_enemies + 1))))
		return (ft_printf("Could not realloc enemies\n"));
	env->enemies[env->nb_enemies] = enemy;
	env->editor.create_enemy = 0;
	update_enemy(env, env->nb_enemies);
	env->nb_enemies++;
	env->editor.add_enemy.state = UP;
	return (0);
}

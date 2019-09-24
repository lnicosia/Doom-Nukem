/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   death.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaerhard <gaerhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/24 14:55:11 by gaerhard          #+#    #+#             */
/*   Updated: 2019/09/24 15:17:22 by gaerhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

void        death(t_env *env)
{
    int i;

    i = 0;
	while (i < env->nb_enemies)
	{
		env->enemies[i].pos = env->enemies[i].enemies_init_data.pos;
		env->enemies[i].health = env->enemies[i].enemies_init_data.health;
		env->enemies[i].sector = env->enemies[i].enemies_init_data.sector;
		env->enemies[i].angle = env->enemies[i].enemies_init_data.angle;
        env->enemies[i].sprite = env->enemies[i].main_sprite;
		i++;
	}
	env->player.pos = env->player.player_init_data.pos;
	env->player.health = env->player.player_init_data.health;
	env->player.sector = env->player.player_init_data.sector;
	env->player.camera = env->player.player_init_data.camera;
	i = 0;
	while (i < env->nb_objects)
	{
		env->objects[i].pos = env->objects[i].object_init_data.pos;
		env->objects[i].sector = env->objects[i].object_init_data.sector;
		env->objects[i].angle = env->objects[i].object_init_data.angle;
		i++;
	}
    init_weapons(env);
    init_enemies_data(env);
    init_animations(env);
    update_player_z(env);
}
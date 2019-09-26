/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   death.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaerhard <gaerhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/24 14:55:11 by gaerhard          #+#    #+#             */
/*   Updated: 2019/09/26 13:46:38 by gaerhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "collision.h"

void		respawn(t_env *env)
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
	env->player.killed = 0;
	env->player.touched = 0;
	env->player.nb_shots = 0;
	env->player.accuracy = 0;
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
	env->player.highest_sect = find_highest_sector(env, new_movement(env->player.sector, env->player.size_2d, env->player.eyesight, env->player.pos));
}

void        death(t_env *env)
{
	int		i;

	i = 0;
	if (env->player.nb_shots > 0)
		env->player.accuracy = (int)((env->player.touched / env->player.nb_shots) * 100);
	if (!env->confirmation_box.state)
	{
		env->confirmation_box.state = 1;
		if (!(env->confirmation_box.str = ft_strdup("You Died...\nRespawn?")))
			ft_perror("Could not malloc confirmation box str");
		new_confirmation_box(&env->confirmation_box, env);
		SDL_SetRelativeMouseMode(0);
		while (++i < env->nb_enemies)
			env->enemies[i].state = RESTING;
	}
}
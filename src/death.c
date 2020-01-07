/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   death.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaerhard <gaerhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 17:44:30 by gaerhard          #+#    #+#             */
/*   Updated: 2019/11/14 09:42:13 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "collision.h"

void		respawn(void *param)
{
	int 	i;
	t_env	*env;

	env = (t_env*)param;
	i = 0;
	while (i < env->nb_enemies)
	{
		env->enemies[i].pos = env->enemies[i].enemies_init_data.pos;
		env->enemies[i].health = env->enemies[i].enemies_init_data.health;
		env->enemies[i].sector = env->enemies[i].enemies_init_data.sector;
		env->enemies[i].angle = env->enemies[i].enemies_init_data.angle;
		env->enemies[i].sprite = env->enemies[i].main_sprite;
		env->enemies[i].saw_player = 0;
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
	SDL_SetRelativeMouseMode(1);
	SDL_GetRelativeMouseState(&env->sdl.mouse_x, &env->sdl.mouse_y);
}

void		stop_game(void *param)
{
	((t_env*)param)->running = 0;
}

void		death(t_env *env)
{
	int		i;

	i = 0;
	if (env->player.nb_shots > 0)
		env->player.accuracy = (int)((env->player.touched / env->player.nb_shots) * 100);
	if (!env->confirmation_box.state)
	{
		SDL_SetRelativeMouseMode(0);
		while (++i < env->nb_enemies)
			env->enemies[i].state = RESTING;
		if (update_confirmation_box(&env->confirmation_box,
			"You died... Respawn?", YESNO, env))
			return ;
		env->confirmation_box.yes_action = respawn;
		env->confirmation_box.yes_target = env;
		env->confirmation_box.no_action = stop_game;
		env->confirmation_box.no_target = env;
	}
}

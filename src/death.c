/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   death.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 17:44:30 by gaerhard          #+#    #+#             */
/*   Updated: 2020/04/29 15:52:22 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "free.h"
#include "init.h"
#include "collision.h"
#include "parser.h"

void		respawn_entities(void *param)
{
	int		i;
	t_env	*env;

	i = 0;
	env = (t_env *)param;
	while (i < env->nb_enemies)
	{
		env->enemies[i].pos = env->enemies[i].init_data.pos;
		env->enemies[i].health = env->enemies[i].init_data.health;
		env->enemies[i].sector = env->enemies[i].init_data.sector;
		env->enemies[i].angle = env->enemies[i].init_data.angle;
		env->enemies[i].sprite = env->enemies[i].main_sprite;
		env->enemies[i].saw_player = 0;
		i++;
	}
	i = 0;
	while (i < env->nb_objects)
	{
		env->objects[i].sprite = env->objects[i].main_sprite;
		env->objects[i].pos = env->objects[i].init_data.pos;
		env->objects[i].sector = env->objects[i].init_data.sector;
		env->objects[i].angle = env->objects[i].init_data.angle;
		i++;
	}
}

int			respawn2(t_env *env)
{
	int		i;

	i = -1;
	while (++i < env->nb_enemies)
	{
		env->enemies[i].exists = 1;
		env->enemies[i].health = env->enemies[i].map_hp * env->difficulty;
	}
	env->dialog_box = 0;
	env->next_dialog = 0;
	if (init_camera(&env->player.camera, env))
		return (-1);
	update_camera_position(&env->player.camera);
	view(env);
	init_weapons(env);
	init_enemies_data(env);
	init_objects_data(env);
	init_animations(env);
	env->player.highest_sect = find_highest_sector(env,
	new_motion(env->player.sector, env->player.size_2d,
	env->player.eyesight, env->player.pos));
	update_player_z(env);
	SDL_SetRelativeMouseMode(1);
	SDL_GetRelativeMouseState(&env->sdl.mouse_x, &env->sdl.mouse_y);
	return (0);
}

int			respawn(void *param)
{
	t_env	*env;
	int		i;

	env = (t_env*)param;
	free_map(env);
	init_player(env);
	if (parse_map(env->save_file, env))
		return (-1);
	if (valid_map(env))
		return (-1);
	if (!(env->sector_list = (int*)ft_memalloc(sizeof(int) * env->nb_sectors)))
		return (custom_error("Could not malloc sector list"));
	precompute_slopes(env);
	update_player_z(env);
	ft_bzero(&env->inputs, sizeof(env->inputs));
	i = 0;
	while (i < env->nb_objects)
	{
		env->objects[i].exists = 1;
		i++;
	}
	free_camera(&env->player.camera);
	return (respawn2(env));
}

int			stop_game(void *param)
{
	((t_env*)param)->running = 0;
	return (0);
}

int			death(t_env *env)
{
	int		i;

	i = 0;
	if (env->player.nb_shots > 0)
		env->player.accuracy = ((env->player.touched / env->player.nb_shots)
		* 100);
	if (!env->confirmation_box.state)
	{
		SDL_SetRelativeMouseMode(0);
		while (++i < env->nb_enemies)
			env->enemies[i].state = RESTING;
		if (update_confirmation_box(&env->confirmation_box,
			"You died... Respawn?", YESNO, env))
			return (-1);
		env->confirmation_box.yes_action = &respawn;
		env->confirmation_box.yes_target = env;
		env->confirmation_box.no_action = &stop_game;
		env->confirmation_box.no_target = env;
	}
	return (0);
}

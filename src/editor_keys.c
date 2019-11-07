/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   editor_keys.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaerhard <gaerhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/29 15:07:41 by lnicosia          #+#    #+#             */
/*   Updated: 2019/11/07 16:07:19 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

int			editor_keys(t_env *env)
{
	double time;

	time = SDL_GetTicks();
	if (env->inputs.backspace && !env->confirmation_box.state)
	{
		del_last_vertex(env);
		env->inputs.backspace = 0;
	}
	if (env->inputs.del)
		if (delete_action(env))
			return (-1);
	player_selection(env);
	enemy_selection(env);
	objects_selection(env);
	vertices_selection(env);
	if (env->confirmation_box.state)
		confirmation_box_keys(&env->confirmation_box, env);
	if (env->inputs.right_click)
	{
		env->editor.center.x += env->sdl.mouse_x;
		env->editor.center.y += env->sdl.mouse_y;
	}
	if (env->inputs.enter && !env->confirmation_box.state
		&& !env->input_box.state)
	{
		if (!valid_map(env))
		{
			env->editor.selected_vertex = -1;
			env->editor.selected_sector = -1;
			env->editor.selected_player = -1;
			env->editor.selected_object = -1;
			env->selected_enemy = -1;
			env->editor.in_game = 1;
			env->inputs.enter = 0;
			env->screen_sectors_size = ft_min(env->nb_sectors, env->w);
			free_camera(&env->player.camera);
			if (init_camera_arrays(&env->player.camera, env))
				return (ft_printf("Could not init camera arrays\n"));
			if (env->sector_list)
				ft_memdel((void**)&env->sector_list);
			if (!(env->sector_list = (int*)malloc(sizeof(int) * env->nb_sectors)))
				return (ft_printf("Could not allocate sector list\n", env));
			update_camera_position(&env->player.camera);
			update_player_z(env);
			ft_bzero(&env->inputs, sizeof(env->inputs));
			SDL_SetRelativeMouseMode(1);
			SDL_GetRelativeMouseState(&env->sdl.mouse_x, &env->sdl.mouse_y);
		}
		env->inputs.enter = 0;
	}
	if (env->inputs.left && !env->editor.tab && !env->inputs.ctrl)
		env->editor.center.x -= 3;
	if (env->inputs.right && !env->editor.tab && !env->inputs.ctrl)
		env->editor.center.x += 3;
	if (env->inputs.forward && !env->editor.tab && !env->inputs.ctrl)
		env->editor.center.y -= 3;
	if (env->inputs.backward && !env->editor.tab && !env->inputs.ctrl)
		env->editor.center.y += 3;
	if (env->inputs.s && env->inputs.ctrl && !valid_map(env))// && !env->editor.in_game)
	{
		if (save_map("maps/test.map", env))
			return (ft_printf("Could not save the map\n"));
		env->inputs.s = 0;
		//env->inputs.ctrl = 0;
	}
	if (env->editor.tab && env->editor.selected_sector != -1 && !env->editor.in_game)
	{
		time = SDL_GetTicks();
		if (!env->time.tick2)
			env->time.tick2 = SDL_GetTicks();
		if (env->inputs.backward && env->selected_stat < 2 && time - env->time.tick2 > 300)
		{
			env->time.tick2 = time;
			env->selected_stat++;
		}
		else if (env->inputs.forward && env->selected_stat > 0 && time - env->time.tick2 > 300)
		{
			env->time.tick2 = time;
			env->selected_stat--;
		}
		selected_information_in_sector(env);
	}
	if ((env->inputs.plus || env->inputs.minus) && !env->editor.in_game && env->editor.selected_sector != -1)
	{
		if (!env->time.tick4)
			env->time.tick4 = SDL_GetTicks();
		time = SDL_GetTicks();
		if (env->inputs.plus && env->sectors[env->editor.selected_sector].statue < 3
		&& time - env->time.tick4 > 300)
		{
			env->sectors[env->editor.selected_sector].statue++;
			env->time.tick4 = time;
		}
		if (env->inputs.minus && env->sectors[env->editor.selected_sector].statue > 0
		&& time - env->time.tick4 > 300)
		{
			env->sectors[env->editor.selected_sector].statue--;
			env->time.tick4 = time;
		}
/*		if (env->sectors[env->editor.selected_sector].statue == 3)
			create_teleporter(env);*/
	}
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   editor_keys.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipatry <sipatry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/29 15:07:41 by lnicosia          #+#    #+#             */
/*   Updated: 2019/12/04 17:59:54 by sipatry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

int			editor_keys(t_env *env)
{
	double time;
	int	i;

	i = 0;
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

	/*
	**	Moving the map with arrows
	*/

	if (env->inputs.left && !env->editor.tab && !env->inputs.ctrl)
		env->editor.center.x -= 3;
	if (env->inputs.right && !env->editor.tab && !env->inputs.ctrl)
		env->editor.center.x += 3;
	if (env->inputs.forward && !env->editor.tab && !env->inputs.ctrl)
		env->editor.center.y -= 3;
	if (env->inputs.backward && !env->editor.tab && !env->inputs.ctrl)
		env->editor.center.y += 3;
	if (env->inputs.s && env->inputs.ctrl && !valid_map(env))
	{
		new_input_box(&env->input_box, new_point(env->h_w, env->h_h),
		STRING, &env->save_file);
		env->inputs.s = 0;
		env->inputs.ctrl = 0;
	}

	/*
	**	control of the selection the stats in 2D mode editor iwh include:
	**	floor | ceiling | brightness control on arrows or keybord usual binding (w-a-s-d)
	**	control of the sector status with +/-
	*/

	while (i < MAX_WALL_TEXTURE)
	{
		button_keys(&env->editor.textures[i], env);
		i++;
	}
	if (env->editor.tab && env->editor.selected_sector != -1 && !env->editor.in_game)
	{
		time = SDL_GetTicks();
		if (!env->time.tick2)
			env->time.tick2 = SDL_GetTicks();
		if (env->inputs.backward && env->selected_stat < 3 && time - env->time.tick2 > 300)
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
		if (env->inputs.plus && env->sectors[env->editor.selected_sector].status < 5
		&& time - env->time.tick4 > 300)
		{
			env->sectors[env->editor.selected_sector].status++;
			env->time.tick4 = time;
		}
		if (env->inputs.minus && env->sectors[env->editor.selected_sector].status > 0
		&& time - env->time.tick4 > 300)
		{
			env->sectors[env->editor.selected_sector].status--;
			env->time.tick4 = time;
		}
		if (env->sectors[env->editor.selected_sector].status == 3)
		{
			env->teleport.create = 1;
			env->hidden_sect.create = 0;
		}
		if (env->sectors[env->editor.selected_sector].status == 5)
		{
			env->hidden_sect.sector = env->editor.selected_sector;
			env->hidden_sect.create = 1;
			env->teleport.create = 0;
		}
	}
	if (env->inputs.left_click && env->teleport.create)
	{
		env->teleport.tmp_pos.x = (env->sdl.mx - env->editor.center.x) / env->editor.scale;
		env->teleport.tmp_pos.y = (env->sdl.my - env->editor.center.y) / env->editor.scale;
		create_teleport(env);
	}
	if (env->inputs.left_click && env->hidden_sect.create)
	{
		if (env->selected_enemy != -1)
			create_hidden_sector(env);
		else
			ft_printf("please select an enemy to complete the creation\n");
	}
	return (0);
}

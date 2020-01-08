/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   editor_keyup.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipatry <sipatry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 17:29:35 by lnicosia          #+#    #+#             */
/*   Updated: 2019/11/28 16:08:37 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

int	editor_keyup(t_env *env)
{
	int	clicked_vertex;
	int	i;

	i = 0;
	if (env->sdl.event.key.keysym.sym == SDLK_m)
	{
		env->options.show_minimap = env->options.show_minimap ? 0 : 1;
		env->options.mipmapping = env->options.mipmapping ? 0 : 1;
	}
	if (env->sdl.event.key.keysym.sym == SDLK_t)
	{
		env->options.test = env->options.test ? 0 : 1;
		if (env->editor.selected_sector != -1
				&& env->editor.current_texture >= 0
				&& env->editor.current_texture < MAX_WALL_TEXTURE)
		{
				if (apply_texture(env->editor.current_texture,
				&env->sectors[env->editor.selected_sector], env))
					return (-1);
		}
	}
	if (env->sdl.event.key.keysym.sym == SDLK_l)
		env->options.l = env->options.l ? 0 : 1;
	if (env->sdl.event.key.keysym.sym == SDLK_o)
		env->options.o = env->options.o ? 0 : 1;
	if (env->sdl.event.key.keysym.sym == SDLK_TAB)
		env->editor.tab = env->editor.tab ? 0 : 1;
	if (env->editor.in_game && env->sdl.event.key.keysym.sym == SDLK_g)
		env->editor.game = env->editor.game ? 0 : 1;
	if (env->confirmation_box.state)
		confirmation_box_keyup(&env->confirmation_box, env);
	if (env->sdl.mx > 200 && env->sdl.event.button.button == SDL_BUTTON_LEFT
			&& !env->confirmation_box.state
			&& env->editor.start_vertex == -1
			&& env->editor.dragged_player == -1
			&& env->editor.dragged_object == -1
			&& env->editor.dragged_vertex == -1
			&& env->editor.dragged_enemy == -1)
	{
		env->editor.selected_sector = get_sector_no_z(env,
				new_v3((env->sdl.mx - env->editor.center.x) / env->editor.scale,
					(env->sdl.my - env->editor.center.y) / env->editor.scale,
					0));
		env->editor.selected_vertex = -1;
		env->editor.selected_object = -1;
		env->editor.selected_player = -1;
		env->selected_enemy = -1;
	}
	if (env->sdl.event.key.keysym.sym == SDLK_SPACE
		&& env->editor.dragged_player == -1
		&& env->editor.dragged_object == -1
		&& env->editor.dragged_vertex == -1
		&& !env->editor.in_game)
	{
		clicked_vertex = get_existing_vertex(env);
		if (clicked_vertex == -1 && is_new_vertex_valid(env, clicked_vertex))
		{
			if (add_vertex(env))
				return (ft_printf("Could not add new vertex\n"));
			add_vertex_to_current_sector(env, env->nb_vertices - 1);
			if (env->editor.start_vertex == -1) //Nouveau secteur
			{
				env->editor.start_vertex = env->nb_vertices - 1;
			}
		}
		else if (clicked_vertex >= 0)
		{
			if (env->editor.start_vertex == -1)
			{
				env->editor.start_vertex = clicked_vertex;
				add_vertex_to_current_sector(env, clicked_vertex);
			}
			else
			{
				if (clicked_vertex == ((t_vertex*)env->editor.current_vertices->content)->num
						&& ft_lstlen(env->editor.current_vertices) > 2
						&& is_new_vertex_valid(env, clicked_vertex))
				{
					env->editor.reverted = get_clockwise_order(env) ? 0 : 1;
					env->editor.start_vertex = -1;
					if (add_sector(env))
						return (ft_printf("Error while creating new sector\n"));
					free_current_vertices(env);
					//get_new_floor_and_ceiling(env);
					//update_sector_slope(env, &env->sectors[env->nb_sectors - 1]);
				}
				else if (is_new_vertex_valid(env, clicked_vertex))
					add_vertex_to_current_sector(env, clicked_vertex);
			}
		}
		env->inputs.space = 0;
	}
	/*
	** Going in the 3D mode
	*/

	if (env->sdl.event.key.keysym.sym == env->keys.enter
		&& !env->confirmation_box.state && !env->input_box.state
		&& !env->editor.enter_locked)
	{
		if (!valid_map(env))
		{
			env->editor.selected_vertex = -1;
			env->editor.selected_sector = -1;
			env->editor.selected_player = -1;
			env->editor.selected_object = -1;
			env->selected_enemy = -1;
			env->editor.in_game = 1;
			env->screen_sectors_size = ft_min(env->nb_sectors, env->w);
			free_camera(&env->player.camera, env);
			precompute_slopes(env);
			if (init_camera_arrays(&env->player.camera, env))
				return (ft_printf("Could not init camera arrays\n"));
			if (env->sector_list)
				ft_memdel((void**)&env->sector_list);
			if (!(env->sector_list = (int*)ft_memalloc(sizeof(int) * env->nb_sectors)))
				return (ft_printf("Could not allocate sector list\n", env));
			update_camera_position(&env->player.camera);
			update_player_z(env);
			ft_bzero(&env->inputs, sizeof(env->inputs));
			env->options.mouse = 1;
			SDL_SetRelativeMouseMode(1);
			SDL_GetRelativeMouseState(&env->sdl.mouse_x, &env->sdl.mouse_y);
			SDL_GetRelativeMouseState(&env->sdl.mouse_x, &env->sdl.mouse_y);
		}
	}
	if (env->sdl.event.key.keysym.sym == env->keys.enter
		&& env->editor.enter_locked)
		env->editor.enter_locked = 0;
	if (env->inputs.ctrl && env->sdl.event.button.button == SDL_BUTTON_LEFT
	/*&& env->editor.selected_vertex != -1*/)
	{
		/*if (env->editor.add.v1 == -1 && env->editor.add.v2 == -1)
			env->editor.select_vertex_on_going = 1;*/
		if ((is_mouse_on_a_wall(env)))
		{
			if (add_vertex_in_sector(env))
			{
				env->editor.add.v1 = -1;
				env->editor.add.v2 = -1;
				return (0);
			}
		}
	}
	if (env->editor.draw_selection_tab)
	{
		while (i < MAX_WALL_TEXTURE)
		{
			//ft_printf("%d\n", i);
			button_keyup(&env->editor.textures[i], env);
			i++;
		}
	}
	if (env->sdl.event.button.button == SDL_BUTTON_LEFT && (env->sdl.mx < 74 && env->sdl.mx > 10)
	&& (env->sdl.my < 414 && env->sdl.my > 350))
		env->editor.draw_selection_tab = 1;
	else if (env->editor.draw_selection_tab && env->sdl.event.button.button == SDL_BUTTON_LEFT)
		env->editor.draw_selection_tab = 0;
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   editor_keyup.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipatry <sipatry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 17:29:35 by lnicosia          #+#    #+#             */
/*   Updated: 2020/02/13 15:36:51 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

int	editor_keyup(t_env *env)
{
	int	clicked_vertex;
	int	i;

	i = 0;
	if (env->editor.creating_event && !env->confirmation_box.state)
	{
		if (event_panel_keyup(env))
			return (-1);
	}
	if (env->sdl.event.key.keysym.sym == SDLK_m)
	{
		env->options.show_minimap = env->options.show_minimap ? 0 : 1;
		env->options.mipmapping = env->options.mipmapping ? 0 : 1;
	}
/*	if (env->sdl.event.key.keysym.sym == SDLK_t)
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
		else if (env->editor.selected_sector != -1
		&& env->edito.curren)

	}*/
	if (env->sdl.event.key.keysym.sym == SDLK_l)
		env->options.l = env->options.l ? 0 : 1;
	if (env->sdl.event.key.keysym.sym == SDLK_o)
		env->options.o = env->options.o ? 0 : 1;
	if (env->sdl.event.key.keysym.sym == SDLK_TAB)
		env->editor.tab = env->editor.tab ? 0 : 1;
	if (env->editor.in_game && env->sdl.event.key.keysym.sym == SDLK_g)
		env->editor.game = env->editor.game ? 0 : 1;
	if (env->sdl.event.button.button == SDL_BUTTON_LEFT
		&& env->editor.event_panel_dragged)
		env->editor.event_panel_dragged = -1;
	if (env->sdl.mx > 400 && env->sdl.event.button.button == SDL_BUTTON_LEFT
			&& !env->confirmation_box.state
			&& env->editor.event_panel_dragged == -1
			&& (!is_mouse_on_event_panel(env) || !env->editor.creating_event)
			&& env->editor.start_vertex == -1
			&& env->editor.dragged_player == -1
			&& env->editor.dragged_object == -1
			&& env->editor.dragged_vertex == -1
			&& env->editor.dragged_enemy == -1)
	{
		reset_selection(env);
		env->editor.selected_sector = get_sector_no_z(env,
				new_v3((env->sdl.mx - env->editor.center.x) / env->editor.scale,
					(env->sdl.my - env->editor.center.y) / env->editor.scale,
					0));
		env->editor.selected_vertex = -1;
		env->editor.selected_player = -1;
		env->editor.selected_events = 0;
		env->editor.selected_event = 0;
		env->editor.selected_launch_condition = 0;
		env->editor.selected_exec_condition = 0;
		if (env->editor.selected_sector == -1)
		{
			env->selected_floor = -1;
			env->selected_ceiling = -1;
		}
		env->selected_enemy = -1;
		tabs_gestion(env);
		check_event_creation(env);
	}
	if (env->confirmation_box.state)
	{
		if (confirmation_box_keyup(&env->confirmation_box, env))
			return (-1);
	}
	if (env->sdl.mx > 400 && env->sdl.event.button.button == SDL_BUTTON_LEFT
			&& !env->confirmation_box.state
			&& env->editor.start_vertex == -1
			&& env->editor.event_panel_dragged == -1
			&& env->editor.dragged_player == 1
			&& env->editor.selected_player == 1
			&& env->editor.dragged_object == -1
			&& env->editor.dragged_vertex == -1
			&& env->editor.dragged_enemy == -1)
	{
		
	}
	if (env->sdl.event.key.keysym.sym == SDLK_SPACE
		&& env->editor.event_panel_dragged == -1
		&& env->editor.dragged_player == -1
		&& env->editor.dragged_object == -1
		&& env->editor.dragged_vertex == -1
		&& !env->editor.in_game
		&& env->sdl.mx > 400)
	{
		clicked_vertex = get_existing_vertex(env);
		//ft_printf("clicked_vertex: %d\n", clicked_vertex);
		if (clicked_vertex == -1 && is_new_vertex_valid(env, clicked_vertex))
		{
		//	ft_printf("add vertex\n");
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
				if (ft_lstlen(env->editor.current_vertices) == 2 && check_pos_vertices(env))
					split_sector(env);
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
			going_in_3D_mode(env);
	}
	if (env->sdl.event.key.keysym.sym == env->keys.enter
		&& env->editor.enter_locked)
		env->editor.enter_locked = 0;
	if (env->inputs.ctrl && env->sdl.event.button.button == SDL_BUTTON_LEFT)
	{
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
	if (button_keyup(&env->editor.add_enemy, env))
		return (-1);
	if (button_keyup(&env->editor.add_object, env))
		return (-1);
	if (button_keyup(&env->editor.save, env))
		return (-1);
	if (button_keyup(&env->editor.change_mode, env))
		return (-1);
	if (button_keyup(&env->editor.launch_game, env))
		return (-1);
	if (button_keyup(&env->editor.texture_background, env))
		return (-1);
	if (button_keyup(&env->editor.enemy_background, env))
		return (-1);
	if (button_keyup(&env->editor.sector_tab, env))
		return (-1);
	if (button_keyup(&env->editor.general_tab, env))
		return (-1);
	if (button_keyup(&env->editor.sprite_tab, env))
		return (-1);
	if (button_keyup(&env->editor.events_tab, env))
		return (-1);
	if (env->editor.events_tab.state == DOWN)
	{
		if (button_keyup(&env->editor.next_events, env))
			return (-1);
		if (button_keyup(&env->editor.previous_events, env))
			return (-1);
		if (button_keyup(&env->editor.new_event, env))
			return (-1);
		if (is_modify_event_button_visible(env))
		{
			if (button_keyup(&env->editor.modify_event, env))
				return (-1);
			if (button_keyup(&env->editor.delete_event, env))
				return (-1);
		}
		if (are_event_selection_buttons_visible(env))
		{
			if (button_keyup(&env->editor.next_event, env))
				return (-1);
			if (button_keyup(&env->editor.previous_event, env))
				return (-1);
		}
		if (are_launch_condition_selection_buttons_visible(env))
		{
			if (button_keyup(&env->editor.next_launch_condition, env))
				return (-1);
			if (button_keyup(&env->editor.previous_launch_condition, env))
				return (-1);
		}
		if (are_exec_condition_selection_buttons_visible(env))
		{
			if (button_keyup(&env->editor.next_exec_condition, env))
				return (-1);
			if (button_keyup(&env->editor.previous_exec_condition, env))
				return (-1);
		}
	}
	if (env->editor.selected_sector != -1 && sector_buttons_up(env))
		return (-1);
	if (env->editor.selected_player != -1 && player_buttons_up(env))
		return (-1);
	if (env->selected_enemy != -1 && enemy_buttons_up(env))
		return (-1);
	if (env->selected_object != -1 && object_buttons_up(env))
		return (-1);
	if (env->editor.draw_texture_tab)
	{
		while (i < MAX_WALL_TEXTURE)
		{
			if (button_keyup(&env->editor.textures[i], env))
				return (-1);
			i++;
		}
		i = 0;
		while (i < MAX_SKYBOX)
		{
			button_keyup(&env->editor.skyboxes[i], env);
			i++;
		}
	}
	if (env->editor.draw_enemy_tab)
	{
		while (i < MAX_ENEMIES)
		{
			if (button_keyup(&env->editor.enemy_tab[i], env))
				return (-1);
			i++;
		}
	}
	if (env->sdl.event.button.button == SDL_BUTTON_LEFT && (env->sdl.mx < 348 && env->sdl.mx > 230)
	&& (env->sdl.my < 208 && env->sdl.my > 80))
		env->editor.draw_texture_tab = 1;
	else if (env->editor.draw_texture_tab && env->sdl.event.button.button == SDL_BUTTON_LEFT)
		env->editor.draw_texture_tab = 0;
	if (env->sdl.event.button.button == SDL_BUTTON_LEFT && (env->sdl.mx < 304 && env->sdl.mx > 240)
	&& (env->sdl.my < 404 && env->sdl.my > 340))
		env->editor.draw_enemy_tab = 1;
	else if (env->editor.draw_enemy_tab && env->sdl.event.button.button == SDL_BUTTON_LEFT)
		env->editor.draw_enemy_tab = 0;
	if (env->sdl.event.button.button == SDL_BUTTON_LEFT && env->editor.create_enemy && env->sdl.mx > 400)
		add_enemy(env);
	if (env->sdl.event.button.button == SDL_BUTTON_LEFT && env->editor.create_object && env->sdl.mx > 400)
		add_object(env);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   editor_3d_keys.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipatry <sipatry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/01 12:18:01 by lnicosia          #+#    #+#             */
/*   Updated: 2020/02/12 18:09:17 by sipatry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

int		change_textures_scales(t_env *env)
{
	if (env->inputs.minus1
	&& (env->editor.selected_wall != -1 || env->selected_floor != -1
	|| env->selected_ceiling != -1))
	{
		if (reduce_walls_texture_scale(env))
			return (-1);
	}
	if (env->inputs.equals
	&& (env->editor.selected_wall != -1 || env->selected_floor != -1
	|| env->selected_ceiling != -1))
	{
		if (increase_walls_texture_scale(env))
			return (-1);
	}
	return (0);
}

int		change_walls_texture(t_env *env)
{
	t_sector	*sector;

	sector = NULL;
	if (env->selected_floor != -1)
		sector = &env->sectors[env->selected_floor];
	if (env->editor.selected_wall != -1)
		sector = &env->sectors[env->editor.selected_sector];
	if (env->selected_ceiling != -1)
		sector = &env->sectors[env->selected_ceiling];
	if (env->inputs.down)
	{
		if (decrease_wall_texture_number(env, sector))
			return (-1);
	}
	if (env->inputs.up)
	{
		if (increase_wall_texture_number(env, sector))
			return (-1);
	}
	return (0);
}

int		change_slopes(t_env *env)
{
	if (env->inputs.plus)
	{
		if (increase_slope(env))
			return (-1);
	}
	else if (env->inputs.minus)
	{
		if (decrease_slope(env))
			return (-1);
	}
	return (0);
}

int		editor_3d_keys(t_env *env)
{
	double	time;
	int		i;

	i = 0;
	time = SDL_GetTicks();
	if (env->editor.in_game
	&& env->editor.selected_wall != -1)
	{
		if (env->inputs.comma)
			left_wall_texture_alignement(env);
		if (env->inputs.period)
			right_wall_texture_alignement(env);
		if (change_textures_scales(env))
			return (-1);
	}
	if (env->editor.in_game
		&& (env->selected_wall_sprite_sprite != -1
		|| env->selected_ceiling_sprite != -1
		|| env->selected_floor_sprite != -1))
		editor_wall_sprites_keys(env);
	if ((env->inputs.plus || env->inputs.minus)
	&& (env->selected_ceiling || env->selected_floor))
		change_ceiling_floor_height(env);
	if (change_walls_texture(env))
		return (-1);
	if (env->inputs.ctrl && (env->inputs.plus || env->inputs.minus))
	{
		if (change_slopes(env))
			return (-1);
	}	
			
	if (env->inputs.forward || env->inputs.backward || env->inputs.left
			|| env->inputs.right)
		play_sound(env, &env->sound.footstep_chan, env->sound.footstep,
			env->sound.ambient_vol);
	if ((((env->inputs.forward || env->inputs.backward || env->inputs.left
		|| env->inputs.right || env->inputs.space || env->jump.on_going == 1
		|| env->crouch.on_going || env->inputs.lgui)
		&& env->player.health > 0 && !env->inputs.ctrl
		&&  (((env->selected_enemy == -1 && env->editor.tab)
		|| (env->selected_enemy != -1 && !env->editor.tab))
		|| (env->selected_enemy == -1 && !env->editor.tab)))
		|| (env->player.state.climb || env->player.state.drop))
		&& !env->editor.tab)
		move_player(env);
	if (env->inputs.plus && !env->inputs.shift
			&& env->options.minimap_scale * 1.2 < 100)
		env->options.minimap_scale *= 1.2;
	if (env->inputs.minus && !env->inputs.shift
			&& env->options.minimap_scale / 1.2 > 1)
		env->options.minimap_scale /= 1.2;
	if (env->editor.in_game && env->inputs.right_click)
	{
		reset_selection(env);
		new_tabs_position(env);
	}
	if (env->inputs.s && env->inputs.ctrl && !valid_map(env))
	{
		SDL_SetRelativeMouseMode(0);
		SDL_GetRelativeMouseState(&env->sdl.mouse_x, &env->sdl.mouse_y);
		new_input_box(&env->input_box, new_point(env->h_w, env->h_h),
				STRING, &env->save_file);
		env->inputs.s = 0;
		env->inputs.ctrl = 0;
	}
	if (env->confirmation_box.state)
	{
		if (confirmation_box_keys(&env->confirmation_box, env))
			return (-1);
	}
	if (env->inputs.comma)
	{
		if (env->inputs.shift && !env->inputs.ctrl
		&& env->sectors[env->selected_ceiling].ceiling_map_align.y > -1000
		&& env->sectors[env->selected_ceiling].ceiling_map_align.x > -1000)
		{
			env->sectors[env->selected_ceiling].ceiling_map_align.y -= 1;
			env->sectors[env->selected_ceiling].ceiling_map_align.x -= 1;
		}
		else if (env->inputs.ctrl)
			env->sectors[env->selected_ceiling].ceiling_map_align.y -= 1;
		else
			env->sectors[env->selected_ceiling].ceiling_map_align.x -= 1;
	}
	if (env->inputs.period)
	{
		if (env->inputs.shift && !env->inputs.ctrl)
		{
			env->sectors[env->selected_ceiling].ceiling_map_align.y += 1;
			env->sectors[env->selected_ceiling].ceiling_map_align.x += 1;
		}
		else if (env->inputs.ctrl)
			env->sectors[env->selected_ceiling].ceiling_map_align.y += 1;
		else
			env->sectors[env->selected_ceiling].ceiling_map_align.x += 1;
	}

	/*
	 * *	selection of textures on ceiling and floor
	 **	All the || conditions: reset time only if those keys are pressed
	 */

	if (env->editor.in_game && env->selected_floor != -1
			&& env->selected_floor_sprite == -1
			&& (env->inputs.down || env->inputs.up
				|| env->inputs.plus || env->inputs.minus
				|| env->inputs.comma || env->inputs.period
				|| env->inputs.equals || env->inputs.minus1))
	{
		if (env->inputs.comma)
		{
			if (env->inputs.shift && !env->inputs.ctrl)
			{
				env->sectors[env->selected_floor].floor_map_align.y -= 1;
				env->sectors[env->selected_floor].floor_map_align.x -= 1;
			}
			else if (env->inputs.ctrl)
				env->sectors[env->selected_floor].floor_map_align.y -= 1;
			else
				env->sectors[env->selected_floor].floor_map_align.x -= 1;
		}
		if (env->inputs.period)
		{
			if (env->inputs.shift && !env->inputs.ctrl)
			{
				env->sectors[env->selected_floor].floor_map_align.y += 1;
				env->sectors[env->selected_floor].floor_map_align.x += 1;
			}
			else if (env->inputs.ctrl)
				env->sectors[env->selected_floor].floor_map_align.y += 1;
			else
				env->sectors[env->selected_floor].floor_map_align.x += 1;
		}
	}

	if (env->selected_floor != -1 && env->editor.in_game && env->inputs.ctrl)
	{
		if (!env->time.tick3)
			env->time.tick3 = SDL_GetTicks();
		if (env->inputs.left && time - env->time.tick3 > 250
		&& env->sectors[env->selected_floor].start_floor_slope
		< env->sectors[env->selected_floor].nb_vertices)
		{
			env->sectors[env->selected_floor].start_floor_slope++;
			env->time.tick3 = time;
		}
		else if (env->inputs.right && time - env->time.tick3 > 250
		&& env->sectors[env->selected_floor].start_floor_slope > 0)
		{
			env->sectors[env->selected_floor].start_floor_slope--;
			env->time.tick3 = time;
		}
		env->sectors[env->selected_floor].floor_normal =
		get_sector_normal(env->sectors[env->selected_floor], env,
		env->sectors[env->selected_floor]. start_floor_slope);
		update_sector_slope(env, &env->sectors[env->selected_floor]);
		clear_portals(env);
		while (i < env->nb_sectors)
		{
			create_portals(env, env->sectors[i]);
			i++;
		}
	}
	if (env->selected_ceiling != -1 && env->editor.in_game && env->inputs.ctrl)
	{
		if (!env->time.tick3)
			env->time.tick3 = SDL_GetTicks();
		if (env->inputs.left && time - env->time.tick3 > 250
		&& env->sectors[env->selected_ceiling].start_ceiling_slope
		< env->sectors[env->selected_ceiling].nb_vertices)
		{
			env->sectors[env->selected_ceiling].start_ceiling_slope++;
			env->time.tick3 = time;
		}
		else if (env->inputs.right && time - env->time.tick3 > 250
		&& env->sectors[env->selected_ceiling].start_ceiling_slope > 0)
		{
			env->sectors[env->selected_ceiling].start_ceiling_slope--;
			env->time.tick3 = time;
		}
		env->sectors[env->selected_ceiling].ceiling_normal =
		get_sector_normal(env->sectors[env->selected_ceiling],
		env, env->sectors[env->selected_ceiling].start_ceiling_slope);
		update_sector_slope(env, &env->sectors[env->selected_ceiling]);
		update_player_z(env);
		clear_portals(env);
		while (i < env->nb_sectors)
		{
			create_portals(env, env->sectors[i]);
			i++;
		}
	}

	if (env->inputs.right_click && !env->option)
	{
		if (env->weapons[env->player.curr_weapon].ammo < env->weapons[env->player.curr_weapon].max_ammo)
			env->weapons[env->player.curr_weapon].ammo++;
	}
	if (env->editor.tab)
	{
		if (button_keys(&env->editor.save, env))
			return (-1);
		if (button_keys(&env->editor.sprite_tab, env))
			return (-1);
		else if (button_keys(&env->editor.general_tab, env))
			return (-1);
		else if (button_keys(&env->editor.sector_tab, env))
			return (-1);
		if (button_keys(&env->editor.change_mode, env))
			return (-1);
		if (button_keys(&env->editor.launch_game, env))
			return (-1);
		if (button_keys(&env->editor.texture_background, env))
			return (-1);
		if (button_keys(&env->editor.events_tab, env))
			return (-1);
		if (env->editor.events_tab.state == DOWN)
		{
			if (button_keys(&env->editor.next_events, env))
				return (-1);
			if (button_keys(&env->editor.previous_events, env))
				return (-1);
			if (are_event_selection_buttons_visible(env))
			{
				if (button_keys(&env->editor.next_event, env))
					return (-1);
				if (button_keys(&env->editor.previous_event, env))
					return (-1);
			}
			if (are_launch_condition_selection_buttons_visible(env))
			{
				if (button_keys(&env->editor.next_launch_condition, env))
					return (-1);
				if (button_keys(&env->editor.previous_launch_condition, env))
					return (-1);
			}
			if (are_exec_condition_selection_buttons_visible(env))
			{
				if (button_keys(&env->editor.next_exec_condition, env))
					return (-1);
				if (button_keys(&env->editor.previous_exec_condition, env))
					return (-1);
			}
		}
		if (env->selected_ceiling != -1 && ceiling_buttons(env))
				return (-1);
		if (env->selected_floor != -1 && floor_buttons(env))
				return (-1);
		if (env->editor.selected_wall != -1 && wall_buttons(env))
				return (-1);
		if (env->selected_enemy != -1 && enemy_buttons(env))
				return (-1);
		if (env->selected_object != -1 && object_buttons(env))
				return (-1);
		if ((env->selected_floor_sprite != -1 || env->selected_ceiling_sprite != -1
		|| env->selected_wall_sprite_sprite != -1) && env->editor.sprite_tab.state == DOWN)
		{
			if (button_keys(&env->editor.next_sprite, env))
				return (-1);
			if (button_keys(&env->editor.previous_sprite, env))
				return (-1);
			if (button_keys(&env->editor.current_sprite_selection, env))
				return (-1);
		}
		if (env->selected_floor_sprite != -1 && floor_sprite_buttons(env))
				return (-1);
		if (env->selected_ceiling_sprite != -1 && ceiling_sprite_buttons(env))
				return (-1);
		if (env->selected_wall_sprite_sprite != -1 && wall_sprite_buttons(env))
				return (-1);
	}
	if (env->editor.tab)
	{
		i = 0;
		if (env->editor.draw_texture_tab)
		{
			while (i < MAX_WALL_TEXTURE)
			{
				if (button_keys(&env->editor.textures[i], env))
					return (-1);
				i++;
			}
			i = 0;
			while (i < MAX_SKYBOX)
			{
				if (button_keys(&env->editor.skyboxes[i], env))
					return (-1);
				i++;
			}
		}
		if (env->editor.draw_enemy_tab)
		{
			while (i < MAX_ENEMIES)
			{
				if (button_keys(&env->editor.enemy_tab[i], env))
					return (-1);
				i++;
			}
		}
		if (env->editor.draw_sprite_tab)
		{
			while (i < MAX_OBJECTS)
			{
				if (button_keys(&env->editor.sprite_selection[i], env))
					return (-1);
				i++;
			}
		}
		if (env->editor.creating_event)
		{
			if (event_panel_keys(env))
				return (-1);
		}
	}
	return (0);
}

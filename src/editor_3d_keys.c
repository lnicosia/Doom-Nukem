/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   editor_3d_keys.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipatry <sipatry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/01 12:18:01 by lnicosia          #+#    #+#             */
/*   Updated: 2020/02/11 17:45:23 by sipatry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

int		editor_3d_keys(t_env *env)
{
	double	time;
	int		i;

	i = 0;
	time = SDL_GetTicks();
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
	/*
	 * *	selection of textures on walls
	 **	"&& (env->inputs.down || env->inputs.up))": reset time only if those keys are pressed
	 */
	if (env->editor.tab && env->editor.in_game
			&& env->editor.selected_wall != -1
			&& (env->inputs.down || env->inputs.up))
	{
		if (time - env->time.scroll_tick > 200)
		{
			env->time.scroll_tick = time;
			if (env->inputs.down)
			{
				if (env->inputs.shift
						&& env->sectors[env->editor.selected_sector].textures[env->editor.selected_wall] > 8)
					env->sectors[env->editor.selected_sector].textures[env->editor.selected_wall] -= 10;
				else if (env->sectors[env->editor.selected_sector].textures[env->editor.selected_wall] > -MAX_SKYBOX)
					env->sectors[env->editor.selected_sector].textures[env->editor.selected_wall] -= 1;
			}
			else if (env->inputs.up)
			{
				if (env->inputs.shift
						&& env->sectors[env->editor.selected_sector].textures[env->editor.selected_wall] < MAX_WALL_TEXTURE - 10)
					env->sectors[env->editor.selected_sector].textures[env->editor.selected_wall] += 10;
				else if (env->sectors[env->editor.selected_sector].textures[env->editor.selected_wall] < MAX_WALL_TEXTURE - 1)
					env->sectors[env->editor.selected_sector].textures[env->editor.selected_wall]++;
			}
			if (env->sectors[env->editor.selected_sector].textures[env->editor.selected_wall] < 0)
				env->contains_skybox = 1;
			if (set_sector_wall_map_array(&env->sectors[env->editor.
						selected_sector], env->wall_textures[env->sectors[env->
						editor.selected_sector].textures[env->editor.selected_wall]],
						env->editor.selected_wall, env))
				return (-1);
			if (set_camera_map_array(&env->player.camera,
						env->editor.selected_sector, env->editor.selected_wall, env))
				return (-1);
		}
	}
	if (env->editor.in_game
			&& env->editor.selected_wall != -1)
	{
		if (env->inputs.comma)
		{
			if (env->inputs.shift && !env->inputs.ctrl)
			{
				env->sectors[env->editor.selected_sector].align[env->editor.selected_wall].y -= 1;
				env->sectors[env->editor.selected_sector].align[env->editor.selected_wall].x -= 1;
			}
			else if (env->inputs.ctrl)
				env->sectors[env->editor.selected_sector].align[env->editor.selected_wall].y -= 1;
			else
				env->sectors[env->editor.selected_sector].align[env->editor.selected_wall].x -= 1;
		}
		if (env->inputs.period)
		{
			if (env->inputs.shift && !env->inputs.ctrl)
			{
				env->sectors[env->editor.selected_sector].align[env->editor.selected_wall].y += 1;
				env->sectors[env->editor.selected_sector].align[env->editor.selected_wall].x += 1;
			}
			else if (env->inputs.ctrl)
				env->sectors[env->editor.selected_sector].align[env->editor.selected_wall].y += 1;
			else
				env->sectors[env->editor.selected_sector].align[env->editor.selected_wall].x += 1;
		}
		if (env->inputs.equals)
		{
			if (env->inputs.shift && !env->inputs.ctrl)
			{
				env->sectors[env->editor.selected_sector].scale[env->editor.selected_wall].y *= 1.1;
				env->sectors[env->editor.selected_sector].scale[env->editor.selected_wall].x *= 1.1;
			}
			else if (env->inputs.ctrl)
				env->sectors[env->editor.selected_sector].scale[env->editor.selected_wall].y *= 1.1;
			else
				env->sectors[env->editor.selected_sector].scale[env->editor.selected_wall].x *= 1.1;
			if (set_sector_wall_map_array(&env->sectors[env->editor.selected_sector],
						env->wall_textures[env->sectors[env->editor.selected_sector].textures[env->editor.selected_wall]], env->editor.selected_wall, env))
				return (-1);
			if (set_camera_map_array(&env->player.camera,
						env->editor.selected_sector, env->editor.selected_wall, env))
				return (-1);
		}
		if (env->inputs.minus1)
		{
			if (env->inputs.shift && !env->inputs.ctrl)
			{
				env->sectors[env->editor.selected_sector].scale[env->editor.selected_wall].y /= 1.1;
				env->sectors[env->editor.selected_sector].scale[env->editor.selected_wall].x /= 1.1;
			}
			else if (env->inputs.ctrl)
				env->sectors[env->editor.selected_sector].scale[env->editor.selected_wall].y /= 1.1;
			else
				env->sectors[env->editor.selected_sector].scale[env->editor.selected_wall].x /= 1.1;
			if (set_sector_wall_map_array(&env->sectors[env->editor.selected_sector],
						env->wall_textures[env->sectors[env->editor.selected_sector].textures[env->editor.selected_wall]], env->editor.selected_wall, env))
				return (-1);
			if (set_camera_map_array(&env->player.camera,
						env->editor.selected_sector, env->editor.selected_wall, env))
				return (-1);
		}
	}


	/*
	 * *	Sprites on wall 
	 */


	if (env->editor.in_game
		&& (env->selected_wall_sprite_sprite != -1
		|| env->selected_ceiling_sprite != -1
		|| env->selected_floor_sprite != -1))
		editor_wall_sprites_keys(env);

	/*
	 * *	selection of textures on ceiling and floor
	 **	All the || conditions: reset time only if those keys are pressed
	 */

	if (env->editor.in_game && env->selected_ceiling != -1
			&& env->selected_ceiling_sprite == -1
			&& (env->inputs.down || env->inputs.up
				|| env->inputs.plus || env->inputs.minus
				|| env->inputs.comma || env->inputs.period
				|| env->inputs.equals || env->inputs.minus1))
	{
		if (time - env->time.scroll_tick > 200)
		{
			env->time.scroll_tick = time;
			if (env->inputs.down && env->editor.tab)
			{
				if (env->inputs.shift
						&& env->sectors[env->selected_ceiling].ceiling_texture > 9 - MAX_SKYBOX)
					env->sectors[env->selected_ceiling].ceiling_texture -= 10;
				else if (env->sectors[env->selected_ceiling].ceiling_texture > -MAX_SKYBOX)
					env->sectors[env->selected_ceiling].ceiling_texture--;
			}
			else if (env->inputs.up && env->editor.tab)
			{
				if (env->inputs.shift
						&& env->sectors[env->selected_ceiling].ceiling_texture < MAX_WALL_TEXTURE - 10)
					env->sectors[env->selected_ceiling].ceiling_texture += 10;
				else if (env->sectors[env->selected_ceiling].ceiling_texture < MAX_WALL_TEXTURE - 1)
					env->sectors[env->selected_ceiling].ceiling_texture++;
			}
			if (env->sectors[env->selected_ceiling].ceiling_texture < 0)
				env->contains_skybox = 1;
		}

		/*
		**	Change ceiling or floor height
		*/

		if ((env->inputs.plus || env->inputs.minus)
		&& (env->selected_ceiling || env->selected_floor))
			change_ceiling_floor_height(env);

	
		if (env->inputs.comma)
		{
			if (env->inputs.shift && !env->inputs.ctrl)
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
		if (env->inputs.equals)
		{
			if (env->inputs.shift && !env->inputs.ctrl)
			{
				env->sectors[env->selected_ceiling].ceiling_map_scale.y *= 1.1;
				env->sectors[env->selected_ceiling].ceiling_map_scale.x *= 1.1;
			}
			else if (env->inputs.ctrl)
				env->sectors[env->selected_ceiling].ceiling_map_scale.y *= 1.1;
			else
				env->sectors[env->selected_ceiling].ceiling_map_scale.x *= 1.1;
		}
		if (env->inputs.minus1)
		{
			if (env->inputs.shift && !env->inputs.ctrl
			&& env->sectors[env->selected_ceiling].ceiling_map_scale.y > 1
			&& env->sectors[env->selected_ceiling].ceiling_map_scale.x > 1)
			{
				env->sectors[env->selected_ceiling].ceiling_map_scale.y /= 1.1;
				env->sectors[env->selected_ceiling].ceiling_map_scale.x /= 1.1;
			}
			else if (env->inputs.ctrl
			&& env->sectors[env->selected_ceiling].ceiling_map_scale.y > 1)
				env->sectors[env->selected_ceiling].ceiling_map_scale.y /= 1.1;
			else if (env->sectors[env->selected_ceiling].ceiling_map_scale.x > 1)
				env->sectors[env->selected_ceiling].ceiling_map_scale.x /= 1.1;
		}
		if (set_sector_ceiling_map_array(&env->sectors[env->selected_ceiling],
					env->wall_textures[env->sectors[env->selected_ceiling].
					ceiling_texture], env))
			return (-1);
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
		if (time - env->time.tick > 200 && env->editor.tab)
		{
			env->time.tick = time;
			if (env->inputs.down && env->editor.tab)
			{
				if (env->inputs.shift
						&& env->sectors[env->selected_floor].floor_texture > 9 - MAX_SKYBOX)
					env->sectors[env->selected_floor].floor_texture -= 10;
				else if (env->sectors[env->selected_floor].floor_texture > -MAX_SKYBOX)
					env->sectors[env->selected_floor].floor_texture--;
			}
			else if (env->inputs.up && env->editor.tab)
			{
				if (env->inputs.shift
						&& env->sectors[env->selected_floor].floor_texture < MAX_WALL_TEXTURE - 10)
					env->sectors[env->selected_floor].floor_texture += 10;
				else if (env->sectors[env->selected_floor].floor_texture < MAX_WALL_TEXTURE - 1)
					env->sectors[env->selected_floor].floor_texture++;
			}
			if (env->sectors[env->selected_floor].floor_texture < 0)
				env->contains_skybox = 1;
		}
		if (env->inputs.plus
				&& env->sectors[env->selected_floor].floor < env->sectors[env->selected_floor].ceiling - 1)
			env->sectors[env->selected_floor].floor += 0.05;
		else if (env->inputs.minus)
			env->sectors[env->selected_floor].floor -= 0.05;
		update_sector_slope(env, &env->sectors[env->selected_floor]);
		update_sector_entities_z(env, env->selected_floor);
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
		if (env->inputs.equals)
		{
			if (env->inputs.shift && !env->inputs.ctrl)
			{
				env->sectors[env->selected_floor].floor_map_scale.y /= 1.1;
				env->sectors[env->selected_floor].floor_map_scale.x /= 1.1;
			}
			else if (env->inputs.ctrl)
				env->sectors[env->selected_floor].floor_map_scale.y /= 1.1;
			else
				env->sectors[env->selected_floor].floor_map_scale.x /= 1.1;
		}
		if (env->inputs.minus1)
		{
			if (env->inputs.shift && !env->inputs.ctrl)
			{
				env->sectors[env->selected_floor].floor_map_scale.y *= 1.1;
				env->sectors[env->selected_floor].floor_map_scale.x *= 1.1;
			}
			else if (env->inputs.ctrl)
				env->sectors[env->selected_floor].floor_map_scale.y *= 1.1;
			else
				env->sectors[env->selected_floor].floor_map_scale.x *= 1.1;
		}
		if (set_sector_floor_map_array(&env->sectors[env->selected_floor],
					env->wall_textures[env->sectors[env->selected_floor].floor_texture],
					env))
			return (-1);
	}

	/*
	 * *	selection of slopes on floor and ceiling
	 */
	if (env->inputs.down && !env->inputs.shift && !env->editor.tab
			&& env->editor.in_game && env->selected_ceiling != -1)
	{
		env->sectors[env->selected_ceiling].ceiling_slope -= 0.01;
		update_sector_slope(env, &env->sectors[env->selected_ceiling]);
	}
	if (env->inputs.up && !env->inputs.shift && !env->editor.tab
			&& env->editor.in_game && env->selected_ceiling != -1)
	{
		env->sectors[env->selected_ceiling].ceiling_slope += 0.01;
		update_sector_slope(env, &env->sectors[env->selected_ceiling]);
	}
	if (env->selected_ceiling != -1 && env->sectors[env->selected_ceiling].ceiling_slope <= 0.02
			&& env->sectors[env->selected_ceiling].ceiling_slope >= -0.02 && (!env->inputs.up && !env->inputs.down))
		env->sectors[env->selected_ceiling].ceiling_slope = 0;

	if (env->inputs.down && !env->inputs.shift && !env->editor.tab
			&& env->editor.in_game && env->selected_floor != -1)
	{
		env->sectors[env->selected_floor].floor_slope -= 0.01;
		update_sector_slope(env, &env->sectors[env->selected_floor]);
		update_enemies_z(env);
		update_objects_z(env);
	}
	if (env->inputs.up && !env->inputs.shift && !env->editor.tab
			&& env->editor.in_game && env->selected_floor != -1)
	{
		env->sectors[env->selected_floor].floor_slope += 0.01;
		update_sector_slope(env, &env->sectors[env->selected_floor]);
		update_objects_z(env);
	}
	if (env->selected_floor != -1 && env->sectors[env->selected_floor].floor_slope <= 0.02
			&& env->sectors[env->selected_floor].floor_slope >= -0.02 && (!env->inputs.up && !env->inputs.down))
		env->sectors[env->selected_floor].floor_slope = 0;
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

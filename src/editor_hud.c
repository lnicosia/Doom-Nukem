/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   editor_hud.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipatry <sipatry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/29 15:44:44 by sipatry           #+#    #+#             */
/*   Updated: 2020/01/28 13:33:45 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

void	print_events_tab(t_env *env)
{
	(void)env;
	if (env->selected_floor != -1 || env->editor.selected_sector != -1)
	{
		print_sector_events_tab(env);
	}
	else if (env->selected_wall_sprite_wall != -1)
	{
	}
	else if (env->selected_floor == -1 && env->editor.selected_sector == -1)
	{
		print_global_events_tab(env);
	}
}

void	print_sprite_tab(t_env *env)
{
	if (env->selected_wall_sprite_wall != -1)
		print_wall_sprite_tab(env);
	else if (env->selected_ceiling_sprite != -1)
		print_ceiling_sprite_tab(env);	
	else if (env->selected_floor_sprite != -1)
		print_floor_sprite_tab(env);
	if (env->selected_floor_sprite != -1 || env->selected_wall_sprite_sprite != -1
	|| env->selected_ceiling_sprite != -1)
	{
		draw_button(env, env->editor.next_sprite);
		draw_button(env, env->editor.previous_sprite);
	}
}

void	print_sector_tab(t_env *env)
{
	/*
	if (env->editor.selected_vertex != -1)
		print_vertex_general_tab(env);*/
	if (env->editor.selected_object != -1 || env->selected_object != -1)
		print_object_sector_tab(env);
	else if (env->selected_enemy != -1)
		print_enemy_sector_tab(env);
	else if (env->editor.selected_player != -1)
		print_player_sector_tab(env);
	else if (env->selected_ceiling != -1)
		print_ceiling_sector_tab(env);
	else if (env->selected_floor != -1)
		print_floor_sector_tab(env);
	else if (env->editor.selected_wall != -1 && env->editor.selected_sector != -1)
		print_wall_sector_tab(env);
}

void	print_general_tab(t_env *env)
{
	/*if (env->editor.selected_vertex != -1)
		print_vertex_general_tab(env);*/
	if (env->editor.selected_object != -1 || env->selected_object != -1)
		print_object_general_tab(env);
	else if (env->editor.selected_sector != -1 && !env->editor.in_game)
		print_sector_general_tab(env);
	else if (env->selected_ceiling != -1)
		print_ceiling_general_tab(env);
	else if (env->selected_floor != -1)
		print_floor_general_tab(env);
	else if (env->editor.selected_player != -1)
		print_player_general_tab(env);
	else if (env->editor.selected_wall != -1 && env->editor.selected_sector != -1)
		print_wall_general_tab(env);
	else if (env->selected_enemy != -1)
		print_enemy_general_tab(env);
}

void	print_vertex_informations(t_env *env)
{
	print_text(new_point(450, 180), new_printable_text("vertex ",
				env->sdl.fonts.alice30, 0xFFFFFFFF, 30), env);
	print_text(new_point(450, 280), new_printable_text(ft_sitoa(env->editor.selected_vertex),
				env->sdl.fonts.alice30, 0xFFFFFFFF, 30), env);
	print_text(new_point(490, 50), new_printable_text("Coordonates:", env->sdl.fonts.alice30, 0xFFFFFFFF, 30), env);
	print_text(new_point(540, 80), new_printable_text("X:", env->sdl.fonts.alice30, 0xFFFFFFFF, 30), env);
	print_text(new_point(540, 230), new_printable_text(ft_sitoa(env->vertices[env->editor.selected_vertex].x), env->sdl.fonts.alice30, 0xFFFFFFFF, 30), env);
	print_text(new_point(580, 80), new_printable_text("Y:", env->sdl.fonts.alice30, 0xFFFFFFFF, 30), env);
	print_text(new_point(580, 230), new_printable_text(ft_sitoa(env->vertices[env->editor.selected_vertex].y), env->sdl.fonts.alice30, 0xFFFFFFFF, 30), env);
}

void	editor_hud(t_env *env)
{
	if (!env->editor.in_game || (env->editor.in_game &&  env->editor.tab))
	{
		if (env->editor.in_game)
		{
			draw_rectangle(env,
			new_rectangle(0x00000000, 0xFF888888, 1, 5),
			new_point(0 , 0),
			new_point(400, 900));
		}
		draw_rectangle(env,
				new_rectangle(0x00000000, 0xFF888888, 1, 5),
				new_point(0 , 64),
				new_point(400, 270));
		draw_button(env, env->editor.add_enemy);
		draw_button(env, env->editor.add_object);
		draw_button(env, env->editor.texture_background);
		draw_button(env, env->editor.enemy_background);
		draw_button(env, env->editor.current_texture_selection);
		draw_button(env, env->editor.current_enemy_selection);
		draw_button(env, env->editor.change_mode);
		draw_button(env, env->editor.launch_game);
		draw_button(env, env->editor.save);
		draw_button(env, env->editor.general_tab);
		draw_button(env, env->editor.sector_tab);
		if (env->editor.in_game)
			draw_button(env, env->editor.sprite_tab);
		draw_rectangle(env,
				new_rectangle(0x00000000, 0x2C3E50, 1, 5),
				new_point(0 , 450),
				new_point(400, 450));
		if (env->editor.sector_tab.state == DOWN)
			print_sector_tab(env);
		if (env->editor.sprite_tab.state == DOWN)
			print_sprite_tab(env);
		if (env->editor.general_tab.state == DOWN)
			print_general_tab(env);
		if ((env->editor.selected_sector == -1 && env->selected_floor == -1
			&& env->nb_global_events > 0)
			|| (env->editor.selected_sector != -1 &&
			(env->sectors[env->editor.selected_sector].nb_stand_events > 0
			|| env->sectors[env->editor.selected_sector].nb_walk_in_events > 0
			|| env->sectors[env->editor.selected_sector].nb_walk_out_events > 0))
			|| (env->selected_floor != -1 &&
			(env->sectors[env->selected_floor].nb_stand_events > 0
			|| env->sectors[env->selected_floor].nb_walk_in_events > 0
			|| env->sectors[env->selected_floor].nb_walk_out_events > 0))
			|| (env->selected_wall_sprite_sprite != -1 && 
			(env->sectors[env->editor.selected_sector].wall_sprites[env->selected_wall_sprite_wall].nb_press_events[env->selected_wall_sprite_sprite] > 0
			|| env->sectors[env->editor.selected_sector].wall_sprites[env->selected_wall_sprite_wall].nb_shoot_events[env->selected_wall_sprite_sprite] > 0)))
		{
			draw_button(env, env->editor.events_tab);
			if (env->editor.events_tab.state == DOWN)
				print_events_tab(env);
		}
		if (env->editor.draw_selection_tab)
			selection_tab(env, MAX_WALL_TEXTURE);
		if (env->editor.draw_enemy_tab)
			enemy_tab(env, MAX_ENEMIES);
	}
}

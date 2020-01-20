/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   editor_hud.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipatry <sipatry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/29 15:44:44 by sipatry           #+#    #+#             */
/*   Updated: 2020/01/08 11:48:06 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
/*
void	print_general_tab(t_env *env)
{
	if (env->editor.selected_vertex != -1)
		print_vertex_general_tab(env);
	else if (env->editor.selected_player != -1)
		print_player_general(env);
	else if (env->editor.selected_object != -1 || env->selected_object != -1)
		print_object_informations(env);
	else if (env->editor.selected_sector != -1 && !env->editor.in_game)
		print_sector_informations(env);
	else if (env->editor.selected_wall != -1 && env->editor.selected_sector != -1)
		print_wall_informations(env);
	else if (env->selected_ceiling != -1)
		print_ceiling_informations(env);
	else if (env->selected_floor != -1)
		print_floor_general(env);
	else if (env->selected_enemy != -1)
		print_enemy_informations(env);
}
*/
void	print_sector_tab(t_env *env)
{
	/*
	if (env->editor.selected_vertex != -1)
		print_vertex_general_tab(env);

	else if (env->editor.selected_object != -1 || env->selected_object != -1)
		print_object_informations(env);
	else if (env->editor.selected_sector != -1 && !env->editor.in_game)
		print_sector_informations(env);
	else if (env->selected_enemy != -1)
		print_enemy_informations(env);
*/
	if (env->editor.selected_player != -1)
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
		print_vertex_general_tab(env);
	
	else if (env->editor.selected_object != -1 || env->selected_object != -1)
		print_object_informations(env);
	else if (env->editor.selected_sector != -1 && !env->editor.in_game)
		print_sector_informations(env);*/
	if (env->selected_ceiling != -1)
		print_ceiling_general_tab(env);
	else if (env->selected_floor != -1)
		print_floor_general_tab(env);
	else if (env->editor.selected_player != -1)
		print_player_general_tab(env);
	else if (env->editor.selected_wall != -1 && env->editor.selected_sector != -1)
		print_wall_general_tab(env);
//	else if (env->selected_enemy != -1)
//		print_enemy_informations(env);
}

void	select_informations(t_env *env)
{
	if (env->selected_enemy != -1)
		print_text(new_point(520 + env->selected_stat * 40, 30), new_printable_text("->|                              |<-",
				env->sdl.fonts.alice30, 0xFF00FF00, 30), env);
	else if (env->editor.selected_sector != -1)
		print_text(new_point(520 + env->selected_stat * 40, 30), new_printable_text("->|                             |<-",
				env->sdl.fonts.alice30, 0xFF00FF00, 30), env);

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

void	print_sector_informations(t_env *env)
{
	print_text(new_point(450, 180), new_printable_text("sector ", env->sdl.fonts.alice30, 0xFFFFFFFF, 30), env);
	print_text(new_point(450, 280), new_printable_text(ft_sitoa(env->editor.selected_sector), env->sdl.fonts.alice30, 0xFFFFFFFF, 30), env);
	print_text(new_point(520, 80), new_printable_text("floor: ", env->sdl.fonts.alice30, 0xFFFFFFFF, 30), env);
	print_text(new_point(520, 230), new_printable_text(ft_sitoa(env->sectors[env->editor.selected_sector].floor), env->sdl.fonts.alice30, 0xFFFFFFFF, 30), env);
	print_text(new_point(560, 80), new_printable_text("Ceiling: ", env->sdl.fonts.alice30, 0xFFFFFFFF, 30), env);
	print_text(new_point(560, 230), new_printable_text(ft_sitoa(env->sectors[env->editor.selected_sector].ceiling), env->sdl.fonts.alice30, 0xFFFFFFFF, 30), env);
	print_text(new_point(600, 80), new_printable_text("Texture: ", env->sdl.fonts.alice30, 0xFFFFFFFF, 30), env);
	print_text(new_point(600, 230), new_printable_text(ft_sitoa(env->sectors[env->editor.selected_sector].floor_texture), env->sdl.fonts.alice30, 0xFFFFFFFF, 30), env);
	print_text(new_point(640, 80), new_printable_text("Bright: ", env->sdl.fonts.alice30, 0xFFFFFFFF, 30), env);
	print_text(new_point(640, 230), new_printable_text(ft_sitoa(env->sectors[env->editor.selected_sector].brightness), env->sdl.fonts.alice30, 0xFFFFFFFF, 30), env);
	print_text(new_point(680, 80), new_printable_text("(f) Slope: ", env->sdl.fonts.alice30, 0xFFFFFFFF, 30), env);
	print_text(new_point(680, 230), new_printable_text(ft_sitoa(env->sectors[env->editor.selected_sector].floor_slope), env->sdl.fonts.alice30, 0xFFFFFFFF, 30), env);
	print_text(new_point(720, 80), new_printable_text("(C) Slope: ", env->sdl.fonts.alice30, 0xFFFFFFFF, 30), env);
	print_text(new_point(720, 230), new_printable_text(ft_sitoa(env->sectors[env->editor.selected_sector].ceiling_slope), env->sdl.fonts.alice30, 0xFFFFFFFF, 30), env);
	print_text(new_point(760, 80), new_printable_text("status: ", env->sdl.fonts.alice30, 0xFFFFFFFF, 30), env);
	if (env->editor.tab)
		select_informations(env);
}

void	print_object_informations(t_env *env)
{
	print_text(new_point(450, 180), new_printable_text("object ", env->sdl.fonts.alice30, 0xFFFFFFFF, 30), env);
	print_text(new_point(450, 180), new_printable_text(ft_sitoa(env->editor.selected_object), env->sdl.fonts.alice30, 0xFFFFFFFF, 30), env);
	print_text(new_point(520, 80), new_printable_text("Coordonates:", env->sdl.fonts.alice30, 0xFFFFFFFF, 30), env);
	if (env->editor.selected_object != -1)
	{
		print_text(new_point(560, 80), new_printable_text("pos_x : ", env->sdl.fonts.alice30, 0xFFFFFFFF, 30), env);
		print_text(new_point(560, 230), new_printable_text(ft_sitoa(env->objects[env->editor.selected_object].pos.x), env->sdl.fonts.alice30, 0xFFFFFFFF, 30), env);
		print_text(new_point(600, 80), new_printable_text("pos_y : ", env->sdl.fonts.alice30, 0xFFFFFFFF, 30), env);
		print_text(new_point(600, 230), new_printable_text(ft_sitoa(env->objects[env->editor.selected_object].pos.y), env->sdl.fonts.alice30, 0xFFFFFFFF, 30), env);
		print_text(new_point(640, 80), new_printable_text("pos_z : ", env->sdl.fonts.alice30, 0xFFFFFFFF, 30), env);
		print_text(new_point(640, 230), new_printable_text(ft_sitoa(env->objects[env->editor.selected_object].pos.z), env->sdl.fonts.alice30, 0xFFFFFFFF, 30), env);
	}
	else
	{
		print_text(new_point(560, 80), new_printable_text("pos_x : ", env->sdl.fonts.alice30, 0xFFFFFFFF, 30), env);
		print_text(new_point(560, 230), new_printable_text(ft_sitoa(env->objects[env->selected_object].pos.x), env->sdl.fonts.alice30, 0xFFFFFFFF, 30), env);
		print_text(new_point(600, 80), new_printable_text("pos_y : ", env->sdl.fonts.alice30, 0xFFFFFFFF, 30), env);
		print_text(new_point(600, 230), new_printable_text(ft_sitoa(env->objects[env->selected_object].pos.y), env->sdl.fonts.alice30, 0xFFFFFFFF, 30), env);
		print_text(new_point(640, 80), new_printable_text("pos_z : ", env->sdl.fonts.alice30, 0xFFFFFFFF, 30), env);
		print_text(new_point(640, 230), new_printable_text(ft_sitoa(env->objects[env->selected_object].pos.z), env->sdl.fonts.alice30, 0xFFFFFFFF, 30), env);
	}
}

void	print_enemy_informations(t_env *env)
{
	print_text(new_point(450, 180), new_printable_text("enemy",
				env->sdl.fonts.alice30, 0xFFFFFFFF, 30), env);
	print_text(new_point(450, 280), new_printable_text(ft_sitoa(env->selected_enemy),
				env->sdl.fonts.alice30, 0xFFFFFFFF, 30), env);
	print_text(new_point(520, 80), new_printable_text("health: ", env->sdl.fonts.alice30, 0xFFFFFFFF, 30), env);
	print_text(new_point(520, 230), new_printable_text(ft_sitoa(env->enemies[env->selected_enemy].health), env->sdl.fonts.alice30, 0xFFFFFFFF, 30), env);
	print_text(new_point(560, 80), new_printable_text("speed: ", env->sdl.fonts.alice30, 0xFFFFFFFF, 30), env);
	print_text(new_point(560, 230), new_printable_text(ft_sitoa(env->enemies[env->selected_enemy].speed), env->sdl.fonts.alice30, 0xFFFFFFFF, 30), env);
	print_text(new_point(600, 80), new_printable_text("damages: ", env->sdl.fonts.alice30, 0xFFFFFFFF, 30), env);
	print_text(new_point(600, 230), new_printable_text(ft_sitoa(env->enemies[env->selected_enemy].damage), env->sdl.fonts.alice30, 0xFFFFFFFF, 30), env);
	print_text(new_point(640, 80), new_printable_text("sprite: ", env->sdl.fonts.alice30, 0xFFFFFFFF, 30), env);
	print_text(new_point(640, 230), new_printable_text(ft_sitoa(env->enemies[env->selected_enemy].sprite), env->sdl.fonts.alice30, 0xFFFFFFFF, 30), env);
	if (env->editor.in_game)
		select_informations(env);
}

void	editor_hud(t_env *env)
{
	t_point	center;

	if (!env->editor.in_game || (env->editor.in_game &&  env->editor.tab))
	{
		if (env->editor.in_game)
		{
			draw_rectangle(env,
			new_rectangle(0x00000000, 0xFF888888, 1, 5),
			new_point(0 , 0),
			new_point(400, 900));
		}
		draw_button(env, env->editor.texture_background);
		draw_button(env, env->editor.enemy_background);
		draw_button(env, env->editor.current_texture_selection);
		draw_button(env, env->editor.current_enemy_selection);
		draw_button(env, env->editor.change_mode);
		draw_button(env, env->editor.launch_game);
		draw_button(env, env->editor.save);
		draw_button(env, env->editor.general_tab);
		draw_button(env, env->editor.sprite_tab);
		draw_button(env, env->editor.sector_tab);
		draw_rectangle(env,
				new_rectangle(0x00000000, 0xFF888888, 1, 5),
				new_point(0 , 64),
				new_point(400, 270));
		draw_rectangle(env,
				new_rectangle(0x00000000, 0x2C3E50, 1, 5),
				new_point(0 , 450),
				new_point(400, 450));
		print_text(new_point(100, 50), new_printable_text("Mipmapping:",
		env->sdl.fonts.lato20, 0xFFFFFFFF, 20), env);
		if (env->options.show_minimap)
			print_text(new_point(100, 175), new_printable_text("[ON]",
		env->sdl.fonts.lato20, 0x00FF00FF, 20), env);
		else
			print_text(new_point(100, 175), new_printable_text("[OFF]",
		env->sdl.fonts.lato20, 0xFF0000FF, 20), env);
		center.x = 100;
		center.y = 200;
		draw_circle_free(new_circle(0xFFFFFF00, 0xFFFFFF00, center, 15), env);
		print_text(new_point(150, 60), new_printable_text("Object", env->sdl.fonts.alice30, 0xFFFFFFFF, 30), env);
		center.x = 100;
		center.y = 270;
		draw_circle_free(new_circle(0xFF0000FF, 0xFF0000FF, center, 15), env);
		print_text(new_point(220, 60), new_printable_text("enemy", env->sdl.fonts.alice30, 0xFFFFFFFF, 30), env);
		if (env->editor.sector_tab.state == DOWN)
			print_sector_tab(env);/*
		else if (env->editor.sprite_tab == DOWN)
			print_sprite_tab(env);*/
		if (env->editor.general_tab.state == DOWN)
			print_general_tab(env);
		if (env->editor.draw_enemy_tab)
			enemy_tab(env, MAX_ENEMIES);
		if (env->editor.draw_selection_tab)
			selection_tab(env, MAX_WALL_TEXTURE);
	}
}

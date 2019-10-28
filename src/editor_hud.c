/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   editor_hud.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipatry <sipatry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/29 15:44:44 by sipatry           #+#    #+#             */
/*   Updated: 2019/10/28 14:08:53 by sipatry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

void	select_informations(t_env *env)
{
	if (env->selected_enemy != -1)
		print_text(new_point(90 + env->selected_stat * 40, 240), new_printable_text("->|                              |<-",
				env->sdl.fonts.alice30, 0xFF00FF00, 30), env);
	else if (env->editor.selected_sector != -1)
		print_text(new_point(90 + env->selected_stat * 120, 240), new_printable_text("->|                             |<-",
				env->sdl.fonts.alice30, 0xFF00FF00, 30), env);

}

void	print_vertex_informations(t_env *env)
{
	print_text(new_point(10, 380), new_printable_text("vertex ",
				env->sdl.fonts.alice30, 0xFFFFFFFF, 30), env);
	print_text(new_point(10, 480), new_printable_text(ft_sitoa(env->editor.selected_vertex),
				env->sdl.fonts.alice30, 0xFFFFFFFF, 30), env);
	print_text(new_point(90, 280), new_printable_text("Coordonates:", env->sdl.fonts.alice30, 0xFFFFFFFF, 30), env);
	print_text(new_point(140, 300), new_printable_text("X:", env->sdl.fonts.alice30, 0xFFFFFFFF, 30), env);
	print_text(new_point(140, 400), new_printable_text(ft_sitoa(env->vertices[env->editor.selected_vertex].x), env->sdl.fonts.alice30, 0xFFFFFFFF, 30), env);
	print_text(new_point(180, 300), new_printable_text("Y:", env->sdl.fonts.alice30, 0xFFFFFFFF, 30), env);
	print_text(new_point(180, 400), new_printable_text(ft_sitoa(env->vertices[env->editor.selected_vertex].y), env->sdl.fonts.alice30, 0xFFFFFFFF, 30), env);
}

void	print_sector_informations(t_env *env)
{
	print_text(new_point(10, 390), new_printable_text("sector ", env->sdl.fonts.alice30, 0xFFFFFFFF, 30), env);
	print_text(new_point(10, 480), new_printable_text(ft_sitoa(env->editor.selected_sector), env->sdl.fonts.alice30, 0xFFFFFFFF, 30), env);
	print_text(new_point(90, 280), new_printable_text("floor: ", env->sdl.fonts.alice30, 0xFFFFFFFF, 30), env);
	print_text(new_point(90, 440), new_printable_text(ft_sitoa(env->sectors[env->editor.selected_sector].floor), env->sdl.fonts.alice30, 0xFFFFFFFF, 30), env);
	print_text(new_point(130, 280), new_printable_text("(f) Slope: ", env->sdl.fonts.alice30, 0xFFFFFFFF, 30), env);
	print_text(new_point(130, 440), new_printable_text(ft_sitoa(env->sectors[env->editor.selected_sector].floor_slope), env->sdl.fonts.alice30, 0xFFFFFFFF, 30), env);
	print_text(new_point(170, 280), new_printable_text("Texture: ", env->sdl.fonts.alice30, 0xFFFFFFFF, 30), env);
	print_text(new_point(170, 440), new_printable_text(ft_sitoa(env->sectors[env->editor.selected_sector].floor_texture), env->sdl.fonts.alice30, 0xFFFFFFFF, 30), env);
	print_text(new_point(210, 280), new_printable_text("Ceiling: ", env->sdl.fonts.alice30, 0xFFFFFFFF, 30), env);
	print_text(new_point(210, 440), new_printable_text(ft_sitoa(env->sectors[env->editor.selected_sector].ceiling), env->sdl.fonts.alice30, 0xFFFFFFFF, 30), env);
	print_text(new_point(250, 280), new_printable_text("(C) Slope: ", env->sdl.fonts.alice30, 0xFFFFFFFF, 30), env);
	print_text(new_point(250, 440), new_printable_text(ft_sitoa(env->sectors[env->editor.selected_sector].ceiling_slope), env->sdl.fonts.alice30, 0xFFFFFFFF, 30), env);
	print_text(new_point(290, 280), new_printable_text("Texture: ", env->sdl.fonts.alice30, 0xFFFFFFFF, 30), env);
	print_text(new_point(290, 440), new_printable_text(ft_sitoa(env->sectors[env->editor.selected_sector].ceiling_texture), env->sdl.fonts.alice30, 0xFFFFFFFF, 30), env);
	print_text(new_point(330, 280), new_printable_text("Bright: ", env->sdl.fonts.alice30, 0xFFFFFFFF, 30), env);
	print_text(new_point(330, 420), new_printable_text(ft_sitoa(env->sectors[env->editor.selected_sector].brightness), env->sdl.fonts.alice30, 0xFFFFFFFF, 30), env);
	print_text(new_point(370, 280), new_printable_text("Statue: ", env->sdl.fonts.alice30, 0xFFFFFFFF, 30), env);
	print_text(new_point(370, 420), new_printable_text(ft_sitoa(env->sectors[env->editor.selected_sector].statue), env->sdl.fonts.alice30, 0xFFFFFFFF, 30), env);

	if (env->editor.tab)
		select_informations(env);
}

void	print_object_informations(t_env *env)
{
	print_text(new_point(10, 390), new_printable_text("object ", env->sdl.fonts.alice30, 0xFFFFFFFF, 30), env);
	print_text(new_point(10, 480), new_printable_text(ft_sitoa(env->editor.selected_object), env->sdl.fonts.alice30, 0xFFFFFFFF, 30), env);
	print_text(new_point(90, 280), new_printable_text("Coordonates:", env->sdl.fonts.alice30, 0xFFFFFFFF, 30), env);
	if (env->editor.selected_object != -1)
	{
		print_text(new_point(130, 300), new_printable_text("pos_x : ", env->sdl.fonts.alice30, 0xFFFFFFFF, 30), env);
		print_text(new_point(130, 430), new_printable_text(ft_sitoa(env->objects[env->editor.selected_object].pos.x), env->sdl.fonts.alice30, 0xFFFFFFFF, 30), env);
		print_text(new_point(170, 300), new_printable_text("pos_y : ", env->sdl.fonts.alice30, 0xFFFFFFFF, 30), env);
		print_text(new_point(170, 430), new_printable_text(ft_sitoa(env->objects[env->editor.selected_object].pos.y), env->sdl.fonts.alice30, 0xFFFFFFFF, 30), env);
		print_text(new_point(210, 300), new_printable_text("pos_z : ", env->sdl.fonts.alice30, 0xFFFFFFFF, 30), env);
		print_text(new_point(210, 430), new_printable_text(ft_sitoa(env->objects[env->editor.selected_object].pos.z), env->sdl.fonts.alice30, 0xFFFFFFFF, 30), env);
	}
	else
	{
		print_text(new_point(130, 300), new_printable_text("pos_x : ", env->sdl.fonts.alice30, 0xFFFFFFFF, 30), env);
		print_text(new_point(130, 430), new_printable_text(ft_sitoa(env->objects[env->selected_object].pos.x), env->sdl.fonts.alice30, 0xFFFFFFFF, 30), env);
		print_text(new_point(170, 300), new_printable_text("pos_y : ", env->sdl.fonts.alice30, 0xFFFFFFFF, 30), env);
		print_text(new_point(170, 430), new_printable_text(ft_sitoa(env->objects[env->selected_object].pos.y), env->sdl.fonts.alice30, 0xFFFFFFFF, 30), env);
		print_text(new_point(210, 300), new_printable_text("pos_z : ", env->sdl.fonts.alice30, 0xFFFFFFFF, 30), env);
		print_text(new_point(210, 430), new_printable_text(ft_sitoa(env->objects[env->selected_object].pos.z), env->sdl.fonts.alice30, 0xFFFFFFFF, 30), env);
	}
}

void	print_player_informations(t_env *env)
{
	print_text(new_point(90, 280), new_printable_text("Coordonates:", env->sdl.fonts.alice30, 0xFFFFFFFF, 30), env);
	print_text(new_point(10, 400), new_printable_text("player ", env->sdl.fonts.alice30, 0xFFFFFFFF, 30), env);
	print_text(new_point(130, 300), new_printable_text("pos_x : ", env->sdl.fonts.alice30, 0xFFFFFFFF, 30), env);
	print_text(new_point(130, 430), new_printable_text(ft_sitoa(env->player.pos.x), env->sdl.fonts.alice30, 0xFFFFFFFF, 30), env);
	print_text(new_point(170, 300), new_printable_text("pos_y : ", env->sdl.fonts.alice30, 0xFFFFFFFF, 30), env);
	print_text(new_point(170, 430), new_printable_text(ft_sitoa(env->player.pos.y), env->sdl.fonts.alice30, 0xFFFFFFFF, 30), env);
	print_text(new_point(210, 300), new_printable_text("pos_z : ", env->sdl.fonts.alice30, 0xFFFFFFFF, 30), env);
	print_text(new_point(210, 430), new_printable_text(ft_sitoa(env->player.pos.z), env->sdl.fonts.alice30, 0xFFFFFFFF, 30), env);

}

void	print_wall_informations(t_env *env)
{
	print_text(new_point(10, 390), new_printable_text("Wall ", env->sdl.fonts.alice30, 0xFFFFFFFF, 30), env);
	print_text(new_point(10, 480), new_printable_text(ft_sitoa(env->editor.selected_wall), env->sdl.fonts.alice30, 0xFFFFFFFF, 30), env);
	print_text(new_point(220, 280), new_printable_text("Texture:", env->sdl.fonts.alice30, 0xFFFFFFFF, 30), env);
	print_text(new_point(220, 470), new_printable_text(ft_sitoa(env->sectors[env->editor.selected_sector].textures[env->editor.selected_wall]), env->sdl.fonts.alice30, 0xFFFFFFFF, 30), env);

}

void	print_ceiling_informations(t_env *env)
{
	print_text(new_point(10, 380), new_printable_text("Ceiling",
				env->sdl.fonts.alice30, 0xFFFFFFFF, 30), env);
	print_text(new_point(10, 480), new_printable_text(ft_sitoa(env->selected_ceiling),
				env->sdl.fonts.alice30, 0xFFFFFFFF, 30), env);
	print_text(new_point(90, 240), new_printable_text("Ceiling: ", env->sdl.fonts.alice30, 0xFFFFFFFF, 30), env);
	print_text(new_point(90, 470), new_printable_text(ft_sitoa(env->sectors[env->selected_ceiling].ceiling), env->sdl.fonts.alice30, 0xFFFFFFFF, 30), env);
	print_text(new_point(130, 240), new_printable_text("Ceiling slope: ", env->sdl.fonts.alice30, 0xFFFFFFFF, 30), env);
	print_text(new_point(130, 470), new_printable_text(ft_sitoa(env->sectors[env->selected_ceiling].ceiling_slope), env->sdl.fonts.alice30, 0xFFFFFFFF, 30), env);
	print_text(new_point(170, 240), new_printable_text("Texture: ", env->sdl.fonts.alice30, 0xFFFFFFFF, 30), env);
	print_text(new_point(170, 470), new_printable_text(ft_sitoa(env->sectors[env->selected_ceiling].ceiling_texture), env->sdl.fonts.alice30, 0xFFFFFFFF, 30), env);
}

void	print_floor_informations(t_env *env)
{
	print_text(new_point(10, 380), new_printable_text("floor",
				env->sdl.fonts.alice30, 0xFFFFFFFF, 30), env);
	print_text(new_point(10, 480), new_printable_text(ft_sitoa(env->selected_floor),
				env->sdl.fonts.alice30, 0xFFFFFFFF, 30), env);
	print_text(new_point(90, 240), new_printable_text("floor: ", env->sdl.fonts.alice30, 0xFFFFFFFF, 30), env);
	print_text(new_point(90, 470), new_printable_text(ft_sitoa(env->sectors[env->selected_floor].floor), env->sdl.fonts.alice30, 0xFFFFFFFF, 30), env);
	print_text(new_point(130, 240), new_printable_text("floor slope: ", env->sdl.fonts.alice30, 0xFFFFFFFF, 30), env);
	print_text(new_point(130, 470), new_printable_text(ft_sitoa(env->sectors[env->selected_floor].floor_slope), env->sdl.fonts.alice30, 0xFFFFFFFF, 30), env);
	print_text(new_point(170, 240), new_printable_text("Texture: ", env->sdl.fonts.alice30, 0xFFFFFFFF, 30), env);
	print_text(new_point(170, 470), new_printable_text(ft_sitoa(env->sectors[env->selected_floor].floor_texture), env->sdl.fonts.alice30, 0xFFFFFFFF, 30), env);
}

void	print_enemy_informations(t_env *env)
{
	print_text(new_point(10, 380), new_printable_text("enemy",
				env->sdl.fonts.alice30, 0xFFFFFFFF, 30), env);
	print_text(new_point(10, 480), new_printable_text(ft_sitoa(env->selected_enemy),
				env->sdl.fonts.alice30, 0xFFFFFFFF, 30), env);
	print_text(new_point(90, 280), new_printable_text("health: ", env->sdl.fonts.alice30, 0xFFFFFFFF, 30), env);
	print_text(new_point(90, 430), new_printable_text(ft_sitoa(env->enemies[env->selected_enemy].health), env->sdl.fonts.alice30, 0xFFFFFFFF, 30), env);
	print_text(new_point(130, 280), new_printable_text("speed: ", env->sdl.fonts.alice30, 0xFFFFFFFF, 30), env);
	print_text(new_point(130, 430), new_printable_text(ft_sitoa(env->enemies[env->selected_enemy].speed), env->sdl.fonts.alice30, 0xFFFFFFFF, 30), env);
	print_text(new_point(170, 280), new_printable_text("damages: ", env->sdl.fonts.alice30, 0xFFFFFFFF, 30), env);
	print_text(new_point(170, 430), new_printable_text(ft_sitoa(env->enemies[env->selected_enemy].damage), env->sdl.fonts.alice30, 0xFFFFFFFF, 30), env);
	print_text(new_point(210, 280), new_printable_text("sprite: ", env->sdl.fonts.alice30, 0xFFFFFFFF, 30), env);
	print_text(new_point(210, 430), new_printable_text(ft_sitoa(env->enemies[env->selected_enemy].sprite), env->sdl.fonts.alice30, 0xFFFFFFFF, 30), env);
	if (env->editor.in_game)
		select_informations(env);
}

void	editor_hud(t_env *env)
{
	t_point	center;

	if (!env->editor.in_game)
	{
		center.x = 100;
		center.y = 100;
		draw_circle_free(new_circle(0xFFFF0000, 0xFFFF0000, center, 15), env);
		print_text(new_point(50, 60), new_printable_text("Player", env->sdl.fonts.alice30, 0xFFFFFFFF, 30), env);
		center.x = 100;
		center.y = 200;
		draw_circle_free(new_circle(0xFFFFFF00, 0xFFFFFF00, center, 15), env);
		print_text(new_point(150, 60), new_printable_text("Object", env->sdl.fonts.alice30, 0xFFFFFFFF, 30), env);
		center.x = 100;
		center.y = 300;
		draw_circle_free(new_circle(0xFF0000FF, 0xFF0000FF, center, 15), env);
		print_text(new_point(250, 60), new_printable_text("enemy", env->sdl.fonts.alice30, 0xFFFFFFFF, 30), env);

	}
	if (env->editor.tab)
	{
		draw_rectangle(env,
				new_rectangle(0x00000000, 0xFF888888, 1, 5),
				new_point( 220 , 60),
				new_point(300, 400));
		print_text(new_point(10, 240), new_printable_text("Selected: ", env->sdl.fonts.alice30, 0xFFFFFFFF, 30), env);
		if (env->editor.selected_vertex != -1)
			print_vertex_informations(env);
		else if (env->editor.selected_player != -1)
			print_player_informations(env);
		else if (env->editor.selected_object != -1 || env->selected_object != -1)
			print_object_informations(env);
		else if (env->editor.selected_sector != -1 && !env->editor.in_game)
			print_sector_informations(env);
		else if (env->editor.selected_wall != -1)
			print_wall_informations(env);
		else if (env->selected_ceiling != -1)
			print_ceiling_informations(env);
		else if (env->selected_floor != -1)
			print_floor_informations(env);
		else if (env->selected_enemy != -1)
			print_enemy_informations(env);
		else
			print_text(new_point(10, 430), new_printable_text("none", env->sdl.fonts.alice30, 0xFFFFFFFF, 30), env);
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   editor_floor_tabs.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipatry <sipatry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 17:31:40 by sipatry           #+#    #+#             */
/*   Updated: 2020/02/04 12:18:22 by sipatry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

int		print_floor_sprite_tab(t_env *env)
{
	env->editor.next_sprite_env.type = FLOOR_S;	
	env->editor.previous_sprite_env.type = FLOOR_S;	
	print_text(new_point(560, 60), new_printable_text("Pos: ", env->sdl.fonts.alice30, 0xFFFFFFFF, 30), env);
	env->editor.hud.sp_floor_sprite.pos_x.str = ft_sitoa(
	env->sectors[env->selected_floor].floor_sprites.pos[env->selected_floor_sprite].x);
	env->editor.hud.sp_floor_sprite.t_pos_x.target =
	&env->sectors[env->selected_floor].floor_sprites.pos[env->selected_floor_sprite].x;
	draw_button(env, env->editor.hud.sp_floor_sprite.pos_x);
	env->editor.hud.sp_floor_sprite.pos_y.str = ft_sitoa(
	env->sectors[env->selected_floor].floor_sprites.pos[env->selected_floor_sprite].y);
	env->editor.hud.sp_floor_sprite.t_pos_y.target =
	&env->sectors[env->selected_floor].floor_sprites.pos[env->selected_floor_sprite].y;
	draw_button(env, env->editor.hud.sp_floor_sprite.pos_y);
	print_text(new_point(600, 60), new_printable_text("Scale: ", env->sdl.fonts.alice30, 0xFFFFFFFF, 30), env);
	env->editor.hud.sp_floor_sprite.scale_x.str = ft_sitoa(
	env->sectors[env->selected_floor].floor_sprites.scale[env->selected_floor_sprite].x);
	env->editor.hud.sp_floor_sprite.t_scale_x.target =
	&env->sectors[env->selected_floor].floor_sprites.scale[env->selected_floor_sprite].x;
	draw_button(env, env->editor.hud.sp_floor_sprite.scale_x);
	env->editor.hud.sp_floor_sprite.scale_y.str = ft_sitoa(
	env->sectors[env->selected_floor].floor_sprites.scale[env->selected_floor_sprite].y);
	env->editor.hud.sp_floor_sprite.t_scale_y.target =
	&env->sectors[env->selected_floor].floor_sprites.scale[env->selected_floor_sprite].y;
	draw_button(env, env->editor.hud.sp_floor_sprite.scale_y);
	return (0);
}

int		print_floor_sector_tab(t_env *env)
{
	print_text(new_point(480, 60), new_printable_text("Sector:", env->sdl.fonts.alice30, 0xFFFFFFFF, 30), env);
	print_text(new_point(480, 230), new_printable_text(ft_sitoa(env->sectors[env->selected_floor].num),
	env->sdl.fonts.alice30, 0xFFFFFFFF, 30), env);
	print_text(new_point(520, 60), new_printable_text("Brightness:", env->sdl.fonts.alice30, 0xFFFFFFFF, 30), env);
	env->editor.hud.s_floor.brightness.str = ft_itoa(env->sectors[env->selected_floor].brightness);
	env->editor.hud.s_floor.t_brightness.target = &env->sectors[env->selected_floor].brightness;
	draw_button(env, env->editor.hud.s_floor.brightness);
	print_text(new_point(560, 60), new_printable_text("Light_color:", env->sdl.fonts.alice30, 0xFFFFFFFF, 30), env);
	env->editor.hud.s_floor.color.str = ft_sitoa(env->sectors[env->selected_floor].light_color);
	env->editor.hud.s_floor.t_color.target = &env->sectors[env->selected_floor].light_color;
	draw_button(env, env->editor.hud.s_floor.color);
	print_text(new_point(600, 60), new_printable_text("Intensity:", env->sdl.fonts.alice30, 0xFFFFFFFF, 30), env);
	env->editor.hud.s_floor.intensity.str = ft_sitoa(env->sectors[env->selected_floor].intensity);
	env->editor.hud.s_floor.t_intensity.target = &env->sectors[env->selected_floor].intensity;
	draw_button(env, env->editor.hud.s_floor.intensity);
	print_text(new_point(640, 60), new_printable_text("Gravity:", env->sdl.fonts.alice30, 0xFFFFFFFF, 30), env);
	env->editor.hud.s_floor.gravity.str = ft_sitoa(env->sectors[env->selected_floor].gravity);
	env->editor.hud.s_floor.t_gravity.target = &env->sectors[env->selected_floor].gravity;
	draw_button(env, env->editor.hud.s_floor.gravity);
	return (0);
}

int		print_floor_general_tab(t_env *env)
{
	print_text(new_point(520, 60), new_printable_text("Height: ", env->sdl.fonts.alice30, 0xFFFFFFFF, 30), env);
	env->editor.hud.g_floor.height.str = ft_sitoa(env->sectors[env->selected_floor].floor);
	env->editor.hud.g_floor.t_height.target = &env->sectors[env->selected_floor].floor;
	draw_button(env, env->editor.hud.g_floor.height);
	print_text(new_point(560, 60), new_printable_text("Slope: ", env->sdl.fonts.alice30, 0xFFFFFFFF, 30), env);
	env->editor.hud.g_floor.slope.str = ft_sitoa(env->sectors[env->selected_floor].floor_slope);
	env->editor.hud.g_floor.t_slope.target = &env->sectors[env->selected_floor].floor_slope;
	draw_button(env, env->editor.hud.g_floor.slope);
	print_text(new_point(600, 100), new_printable_text("Slope direction", env->sdl.fonts.alice30, 0xFFFFFFFF, 30), env);
	draw_button(env, env->editor.previous_slope_swap);
	draw_button(env, env->editor.next_slope_swap);
	print_text(new_point(640, 60), new_printable_text("Scale X: ", env->sdl.fonts.alice30, 0xFFFFFFFF, 30), env);
	env->editor.hud.g_floor.texture_scale_x.str = ft_sitoa(env->sectors[env->selected_floor].floor_map_scale.x);
	env->editor.hud.g_floor.t_texture_scale_x.target = &env->sectors[env->selected_floor].floor_map_scale.x;
	draw_button(env, env->editor.hud.g_floor.texture_scale_x);
	print_text(new_point(680, 60), new_printable_text("Scale Y: ", env->sdl.fonts.alice30, 0xFFFFFFFF, 30), env);
	env->editor.hud.g_floor.texture_scale_y.str = ft_sitoa(env->sectors[env->selected_floor].floor_map_scale.y);
	env->editor.hud.g_floor.t_texture_scale_y.target = &env->sectors[env->selected_floor].floor_map_scale.y;
	draw_button(env, env->editor.hud.g_floor.texture_scale_y);
	print_text(new_point(720, 60), new_printable_text("Align X: ", env->sdl.fonts.alice30, 0xFFFFFFFF, 30), env);
	env->editor.hud.g_floor.texture_align_x.str = ft_sitoa(env->sectors[env->selected_floor].floor_map_align.x);
	env->editor.hud.g_floor.t_texture_align_x.target = &env->sectors[env->selected_floor].floor_map_align.x;
	draw_button(env, env->editor.hud.g_floor.texture_align_x);
	print_text(new_point(760, 60), new_printable_text("Align Y: ", env->sdl.fonts.alice30, 0xFFFFFFFF, 30), env);
	env->editor.hud.g_floor.texture_align_y.str = ft_sitoa(env->sectors[env->selected_floor].floor_map_align.y);
	env->editor.hud.g_floor.t_texture_align_y.target = &env->sectors[env->selected_floor].floor_map_align.y;
	draw_button(env, env->editor.hud.g_floor.texture_align_y);
	return (0);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   editor_wall_tabs.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipatry <sipatry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 18:07:20 by sipatry           #+#    #+#             */
/*   Updated: 2020/01/29 14:30:00 by sipatry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

int		print_wall_sprite_tab(t_env *env)
{
	
	env->editor.next_sprite_env.type = WALL_S;
	env->editor.previous_sprite_env.type = WALL_S;
	env->editor.current_sprite = env->selected_wall_sprite_sprite;
	env->editor.current_sprite_selection.img_down = env->mini_objects_textures[env->selected_wall_sprite_sprite].surface;
	env->editor.current_sprite_selection.img_pressed = env->mini_objects_textures[env->selected_wall_sprite_sprite].surface;
	env->editor.current_sprite_selection.img_hover = env->mini_objects_textures[env->selected_wall_sprite_sprite].surface;
	env->editor.current_sprite_selection.img_up = env->mini_objects_textures[env->selected_wall_sprite_sprite].surface;
	print_text(new_point(520, 60), new_printable_text("Num: ", env->sdl.fonts.alice30, 0xFFFFFFFF, 30), env);
	env->editor.hud.sp_wall_sprite.num.str = ft_sitoa(env->selected_wall_sprite_sprite);
	env->editor.hud.sp_wall_sprite.t_num.target = &env->selected_wall_sprite_sprite;
	draw_button(env, env->editor.hud.sp_wall_sprite.num);
	print_text(new_point(560, 60), new_printable_text("Pos: ", env->sdl.fonts.alice30, 0xFFFFFFFF, 30), env);
	env->editor.hud.sp_wall_sprite.pos_x.str = ft_sitoa(
	env->sectors[env->editor.selected_sector].wall_sprites[env->selected_wall_sprite_wall].pos[env->selected_wall_sprite_sprite].x);
	env->editor.hud.sp_wall_sprite.t_pos_x.target =
	&env->sectors[env->editor.selected_sector].wall_sprites[env->selected_wall_sprite_wall].pos[env->selected_wall_sprite_sprite].x;
	draw_button(env, env->editor.hud.sp_wall_sprite.pos_x);
	env->editor.hud.sp_wall_sprite.pos_y.str = ft_sitoa(
	env->sectors[env->editor.selected_sector].wall_sprites[env->selected_wall_sprite_wall].pos[env->selected_wall_sprite_sprite].y);
	env->editor.hud.sp_wall_sprite.t_pos_y.target =
	&env->sectors[env->editor.selected_sector].wall_sprites[env->selected_wall_sprite_wall].pos[env->selected_wall_sprite_sprite].y;
	draw_button(env, env->editor.hud.sp_wall_sprite.pos_y);
	print_text(new_point(600, 60), new_printable_text("Scale: ", env->sdl.fonts.alice30, 0xFFFFFFFF, 30), env);
	env->editor.hud.sp_wall_sprite.scale_x.str = ft_sitoa(
	env->sectors[env->editor.selected_sector].wall_sprites[env->selected_wall_sprite_wall].scale[env->selected_wall_sprite_sprite].x);
	env->editor.hud.sp_wall_sprite.t_scale_x.target =
	&env->sectors[env->editor.selected_sector].wall_sprites[env->selected_wall_sprite_wall].scale[env->selected_wall_sprite_sprite].x;
	draw_button(env, env->editor.hud.sp_wall_sprite.scale_x);
	env->editor.hud.sp_wall_sprite.scale_y.str = ft_sitoa(
	env->sectors[env->editor.selected_sector].wall_sprites[env->selected_wall_sprite_wall].scale[env->selected_wall_sprite_sprite].y);
	env->editor.hud.sp_wall_sprite.t_scale_y.target =
	&env->sectors[env->editor.selected_sector].wall_sprites[env->selected_wall_sprite_wall].scale[env->selected_wall_sprite_sprite].y;
	draw_button(env, env->editor.hud.sp_wall_sprite.scale_y);
	return (0);
}

int		print_wall_sector_tab(t_env *env)
{
	print_text(new_point(480, 60), new_printable_text("Sector:", env->sdl.fonts.alice30, 0xFFFFFFFF, 30), env);
	print_text(new_point(480, 230), new_printable_text(ft_sitoa(env->editor.selected_sector),
	env->sdl.fonts.alice30, 0xFFFFFFFF, 30), env);
	print_text(new_point(520, 60), new_printable_text("Brightness:", env->sdl.fonts.alice30, 0xFFFFFFFF, 30), env);
	env->editor.hud.s_wall.brightness.str = ft_itoa(env->sectors[env->editor.selected_sector].brightness);
	env->editor.hud.s_wall.t_brightness.target = &env->sectors[env->editor.selected_sector].brightness;
	draw_button(env, env->editor.hud.s_wall.brightness);
	print_text(new_point(560, 60), new_printable_text("Light_color:", env->sdl.fonts.alice30, 0xFFFFFFFF, 30), env);
	env->editor.hud.s_wall.color.str = ft_sitoa(env->sectors[env->editor.selected_sector].light_color);
	env->editor.hud.s_wall.t_color.target = &env->sectors[env->editor.selected_sector].light_color;
	draw_button(env, env->editor.hud.s_wall.color);
	print_text(new_point(600, 60), new_printable_text("Intensity:", env->sdl.fonts.alice30, 0xFFFFFFFF, 30), env);
	env->editor.hud.s_wall.intensity.str = ft_sitoa(env->sectors[env->editor.selected_sector].intensity);
	env->editor.hud.s_wall.t_intensity.target = &env->sectors[env->editor.selected_sector].intensity;
	draw_button(env, env->editor.hud.s_wall.intensity);
	return (0);
}

int		print_wall_general_tab(t_env *env)
{
	print_text(new_point(520, 60), new_printable_text("Texture: ", env->sdl.fonts.alice30, 0xFFFFFFFF, 30), env);
	env->editor.hud.g_wall.texture.str = ft_sitoa(env->sectors[env->editor.selected_sector].textures[env->editor.selected_wall]);
	env->editor.hud.g_wall.t_texture.target = &env->sectors[env->editor.selected_sector].textures[env->editor.selected_wall];
	draw_button(env, env->editor.hud.g_wall.texture);
	print_text(new_point(560, 60), new_printable_text("Scale X: ", env->sdl.fonts.alice30, 0xFFFFFFFF, 30), env);
	env->editor.hud.g_wall.texture_scale_x.str = ft_sitoa(env->sectors[env->editor.selected_sector].scale[env->editor.selected_wall].x);
	env->editor.hud.g_wall.t_texture_scale_x.target = &env->sectors[env->editor.selected_sector].scale[env->editor.selected_wall].x;
	draw_button(env, env->editor.hud.g_wall.texture_scale_x);
	print_text(new_point(600, 60), new_printable_text("Scale Y: ", env->sdl.fonts.alice30, 0xFFFFFFFF, 30), env);
	env->editor.hud.g_wall.texture_scale_y.str = ft_sitoa(env->sectors[env->editor.selected_sector].scale[env->editor.selected_wall].y);
	env->editor.hud.g_wall.t_texture_scale_y.target = &env->sectors[env->editor.selected_sector].scale[env->editor.selected_wall].y;
	draw_button(env, env->editor.hud.g_wall.texture_scale_y);
	print_text(new_point(640, 60), new_printable_text("Align X: ", env->sdl.fonts.alice30, 0xFFFFFFFF, 30), env);
	env->editor.hud.g_wall.texture_align_x.str = ft_sitoa(env->sectors[env->editor.selected_sector].align[env->editor.selected_wall].x);
	env->editor.hud.g_wall.t_texture_align_x.target = &env->sectors[env->editor.selected_sector].align[env->editor.selected_wall].x;
	draw_button(env, env->editor.hud.g_wall.texture_align_x);
	print_text(new_point(680, 60), new_printable_text("Align Y: ", env->sdl.fonts.alice30, 0xFFFFFFFF, 30), env);
	env->editor.hud.g_wall.texture_align_y.str = ft_sitoa(env->sectors[env->editor.selected_sector].align[env->editor.selected_wall].y);
	env->editor.hud.g_wall.t_texture_align_y.target = &env->sectors[env->editor.selected_sector].align[env->editor.selected_wall].y;
	draw_button(env, env->editor.hud.g_wall.texture_align_y);
	return (0);
}
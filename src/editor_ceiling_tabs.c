/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   editor_ceiling_tabs.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipatry <sipatry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 17:40:14 by sipatry           #+#    #+#             */
/*   Updated: 2020/01/27 16:54:47 by sipatry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

void	print_ceiling_sprite_tab(t_env *env)
{
	env->editor.next_sprite_env.type = CEILING_S;	
	env->editor.previous_sprite_env.type = CEILING_S;	
	print_text(new_point(520, 60), new_printable_text("Num: ", env->sdl.fonts.alice30, 0xFFFFFFFF, 30), env);
	env->editor.hud.sp_ceiling_sprite.num.str = ft_sitoa(env->selected_ceiling_sprite);
	env->editor.hud.sp_ceiling_sprite.t_num.target = &env->selected_ceiling_sprite;
	draw_button(env, env->editor.hud.sp_ceiling_sprite.num);
	print_text(new_point(520, 60), new_printable_text("Num: ", env->sdl.fonts.alice30, 0xFFFFFFFF, 30), env);
	env->editor.hud.sp_ceiling_sprite.num.str =
	ft_sitoa(env->sectors[env->selected_ceiling].ceiling_sprites.sprite[env->selected_ceiling_sprite]);
	env->editor.hud.sp_ceiling_sprite.t_num.target = &env->selected_ceiling_sprite;
	draw_button(env, env->editor.hud.sp_ceiling_sprite.num);
	print_text(new_point(560, 60), new_printable_text("Pos: ", env->sdl.fonts.alice30, 0xFFFFFFFF, 30), env);
	env->editor.hud.sp_ceiling_sprite.pos_x.str = ft_sitoa(
	env->sectors[env->selected_ceiling].ceiling_sprites.pos[env->selected_ceiling_sprite].x);
	env->editor.hud.sp_ceiling_sprite.t_pos_x.target =
	&env->sectors[env->selected_ceiling].ceiling_sprites.pos[env->selected_ceiling_sprite].x;
	draw_button(env, env->editor.hud.sp_ceiling_sprite.pos_x);
	env->editor.hud.sp_ceiling_sprite.pos_y.str = ft_sitoa(
	env->sectors[env->selected_ceiling].ceiling_sprites.pos[env->selected_ceiling_sprite].y);
	env->editor.hud.sp_ceiling_sprite.t_pos_y.target =
	&env->sectors[env->selected_ceiling].ceiling_sprites.pos[env->selected_ceiling_sprite].y;
	draw_button(env, env->editor.hud.sp_ceiling_sprite.pos_y);
	print_text(new_point(600, 60), new_printable_text("Scale: ", env->sdl.fonts.alice30, 0xFFFFFFFF, 30), env);
	env->editor.hud.sp_ceiling_sprite.scale_x.str = ft_sitoa(
	env->sectors[env->selected_ceiling].ceiling_sprites.scale[env->selected_ceiling_sprite].x);
	env->editor.hud.sp_ceiling_sprite.t_scale_x.target =
	&env->sectors[env->selected_ceiling].ceiling_sprites.scale[env->selected_ceiling_sprite].x;
	draw_button(env, env->editor.hud.sp_ceiling_sprite.scale_x);
	env->editor.hud.sp_ceiling_sprite.scale_y.str = ft_sitoa(
	env->sectors[env->selected_ceiling].ceiling_sprites.scale[env->selected_ceiling_sprite].y);
	env->editor.hud.sp_ceiling_sprite.t_scale_y.target =
	&env->sectors[env->selected_ceiling].ceiling_sprites.scale[env->selected_ceiling_sprite].y;
	draw_button(env, env->editor.hud.sp_ceiling_sprite.scale_y);
}

void	print_ceiling_sector_tab(t_env *env)
{
	print_text(new_point(480, 60), new_printable_text("Sector:", env->sdl.fonts.alice30, 0xFFFFFFFF, 30), env);
	print_text(new_point(480, 230), new_printable_text(ft_sitoa(env->sectors[env->selected_ceiling].num),
	env->sdl.fonts.alice30, 0xFFFFFFFF, 30), env);
	print_text(new_point(520, 60), new_printable_text("Brightness:", env->sdl.fonts.alice30, 0xFFFFFFFF, 30), env);
	env->editor.hud.s_ceilling.brightness.str = ft_itoa(env->sectors[env->selected_ceiling].brightness);
	env->editor.hud.s_ceilling.t_brightness.target = &env->sectors[env->selected_ceiling].brightness;
	draw_button(env, env->editor.hud.s_ceilling.brightness);
	print_text(new_point(560, 60), new_printable_text("Light_color:", env->sdl.fonts.alice30, 0xFFFFFFFF, 30), env);
	env->editor.hud.s_ceilling.color.str = ft_sitoa(env->sectors[env->selected_ceiling].light_color);
	env->editor.hud.s_ceilling.t_color.target = &env->sectors[env->selected_ceiling].light_color;
	draw_button(env, env->editor.hud.s_ceilling.color);
	print_text(new_point(600, 60), new_printable_text("Intensity:", env->sdl.fonts.alice30, 0xFFFFFFFF, 30), env);
	env->editor.hud.s_ceilling.intensity.str = ft_sitoa(env->sectors[env->selected_ceiling].intensity);
	env->editor.hud.s_ceilling.t_intensity.target = &env->sectors[env->selected_ceiling].intensity;
	draw_button(env, env->editor.hud.s_ceilling.intensity);
}

void	print_ceiling_general_tab(t_env *env)
{
	print_text(new_point(520, 60), new_printable_text("Height: ", env->sdl.fonts.alice30, 0xFFFFFFFF, 30), env);
	env->editor.hud.g_ceilling.height.str = ft_sitoa(env->sectors[env->selected_ceiling].ceiling);
	env->editor.hud.g_ceilling.t_height.target = &env->sectors[env->selected_ceiling].ceiling;
	draw_button(env, env->editor.hud.g_ceilling.height);	
	print_text(new_point(560, 60), new_printable_text("Slope: ", env->sdl.fonts.alice30, 0xFFFFFFFF, 30), env);
	env->editor.hud.g_ceilling.slope.str = ft_sitoa(env->sectors[env->selected_ceiling].ceiling_slope);
	env->editor.hud.g_ceilling.t_slope.target = &env->sectors[env->selected_ceiling].ceiling_slope;
	draw_button(env, env->editor.hud.g_ceilling.slope);
	print_text(new_point(600, 60), new_printable_text("Texture: ", env->sdl.fonts.alice30, 0xFFFFFFFF, 30), env);
	env->editor.hud.g_ceilling.texture.str = ft_sitoa(env->sectors[env->selected_ceiling].ceiling_texture);
	env->editor.hud.g_ceilling.t_texture.target = &env->sectors[env->selected_ceiling].ceiling_texture;
	draw_button(env, env->editor.hud.g_ceilling.texture);
	print_text(new_point(640, 60), new_printable_text("Scale X: ", env->sdl.fonts.alice30, 0xFFFFFFFF, 30), env);
	env->editor.hud.g_ceilling.texture_scale_x.str = ft_sitoa(env->sectors[env->selected_ceiling].ceiling_scale->x);
	env->editor.hud.g_ceilling.t_texture_scale_x.target = &env->sectors[env->selected_ceiling].ceiling_scale->x;
	draw_button(env, env->editor.hud.g_ceilling.texture_scale_x);
	print_text(new_point(680, 60), new_printable_text("Scale Y: ", env->sdl.fonts.alice30, 0xFFFFFFFF, 30), env);
	env->editor.hud.g_ceilling.texture_scale_y.str = ft_sitoa(env->sectors[env->selected_ceiling].ceiling_scale->y);
	env->editor.hud.g_ceilling.t_texture_scale_y.target = &env->sectors[env->selected_ceiling].ceiling_scale->y;
	draw_button(env, env->editor.hud.g_ceilling.texture_scale_y);
	print_text(new_point(720, 60), new_printable_text("Align X: ", env->sdl.fonts.alice30, 0xFFFFFFFF, 30), env);
	env->editor.hud.g_ceilling.texture_align_x.str = ft_sitoa(env->sectors[env->selected_ceiling].ceiling_align->x);
	env->editor.hud.g_ceilling.t_texture_align_x.target = &env->sectors[env->selected_ceiling].ceiling_align->x;
	draw_button(env, env->editor.hud.g_ceilling.texture_align_x);
	print_text(new_point(760, 60), new_printable_text("Align Y: ", env->sdl.fonts.alice30, 0xFFFFFFFF, 30), env);
	env->editor.hud.g_ceilling.texture_align_y.str = ft_sitoa(env->sectors[env->selected_ceiling].ceiling_align->y);
	env->editor.hud.g_ceilling.t_texture_align_y.target = &env->sectors[env->selected_ceiling].ceiling_align->y;
	draw_button(env, env->editor.hud.g_ceilling.texture_align_y);
}
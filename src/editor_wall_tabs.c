/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   editor_wall_tabs.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipatry <sipatry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 18:07:20 by sipatry           #+#    #+#             */
/*   Updated: 2020/01/17 15:53:51 by sipatry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

void	print_wall_sprite_tab(t_env *env)
{
	(void)env;
}

void	print_wall_sector_tab(t_env *env)
{
	print_text(new_point(480, 60), new_printable_text("Sector:", env->sdl.fonts.alice30, 0xFFFFFFFF, 30), env);
	print_text(new_point(480, 230), new_printable_text(ft_sitoa(env->sectors[env->editor.selected_wall].num),
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
}

void	print_wall_general_tab(t_env *env)
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
}
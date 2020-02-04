/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   editor_sector_tabs.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipatry <sipatry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 17:52:15 by sipatry           #+#    #+#             */
/*   Updated: 2020/02/03 18:05:13 by sipatry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

int		print_sector_general_tab(t_env *env)
{
	print_text(new_point(450, 80), new_printable_text("sector ", env->sdl.fonts.alice30, 0xFFFFFFFF, 30), env);
	print_text(new_point(450, 180), new_printable_text(ft_sitoa(env->editor.selected_sector), env->sdl.fonts.alice30, 0xFFFFFFFF, 30), env);
	print_text(new_point(520, 60), new_printable_text("Brightness:", env->sdl.fonts.alice30, 0xFFFFFFFF, 30), env);
	env->editor.hud.g_sector.brightness.str = ft_itoa(env->sectors[env->editor.selected_sector].brightness);
	env->editor.hud.g_sector.t_brightness.target = &env->sectors[env->editor.selected_sector].brightness;
	draw_button(env, env->editor.hud.g_sector.brightness);
	print_text(new_point(560, 60), new_printable_text("Light_color:", env->sdl.fonts.alice30, 0xFFFFFFFF, 30), env);
	env->editor.hud.g_sector.color.str = ft_sitoa(env->sectors[env->editor.selected_sector].light_color);
	env->editor.hud.g_sector.t_color.target = &env->sectors[env->editor.selected_sector].light_color;
	draw_button(env, env->editor.hud.g_sector.color);
	print_text(new_point(600, 60), new_printable_text("Intensity:", env->sdl.fonts.alice30, 0xFFFFFFFF, 30), env);
	env->editor.hud.g_sector.intensity.str = ft_sitoa(env->sectors[env->editor.selected_sector].intensity);
	env->editor.hud.g_sector.t_intensity.target = &env->sectors[env->editor.selected_sector].intensity;
	draw_button(env, env->editor.hud.g_sector.intensity);
	print_text(new_point(640, 60), new_printable_text("floor: ", env->sdl.fonts.alice30, 0xFFFFFFFF, 30), env);
	env->editor.hud.g_sector.floor.str = ft_itoa(env->sectors[env->editor.selected_sector].floor);
	env->editor.hud.g_sector.t_floor.target = &env->sectors[env->editor.selected_sector].floor;
	draw_button(env, env->editor.hud.g_sector.floor);
	print_text(new_point(680, 60), new_printable_text("Ceiling: ", env->sdl.fonts.alice30, 0xFFFFFFFF, 30), env);
	env->editor.hud.g_sector.ceiling.str = ft_itoa(env->sectors[env->editor.selected_sector].ceiling);
	env->editor.hud.g_sector.t_ceilling.target = &env->sectors[env->editor.selected_sector].ceiling;
	draw_button(env, env->editor.hud.g_sector.ceiling);
	print_text(new_point(720, 60), new_printable_text("(f) Slope: ", env->sdl.fonts.alice30, 0xFFFFFFFF, 30), env);
	env->editor.hud.g_sector.floor_slope.str = ft_itoa(env->sectors[env->editor.selected_sector].floor_slope);
	env->editor.hud.g_sector.t_floor_slope.target = &env->sectors[env->editor.selected_sector].floor_slope;
	draw_button(env, env->editor.hud.g_sector.floor_slope);
	print_text(new_point(760, 60), new_printable_text("(C) Slope: ", env->sdl.fonts.alice30, 0xFFFFFFFF, 30), env);
	env->editor.hud.g_sector.ceiling_slope.str = ft_itoa(env->sectors[env->editor.selected_sector].ceiling_slope);
	env->editor.hud.g_sector.t_ceiling_slope.target = &env->sectors[env->editor.selected_sector].ceiling_slope;
	draw_button(env, env->editor.hud.g_sector.ceiling_slope);
	print_text(new_point(800, 60), new_printable_text("Gravity: ", env->sdl.fonts.alice30, 0xFFFFFFFF, 30), env);
	env->editor.hud.g_sector.gravity.str = ft_itoa(env->sectors[env->editor.selected_sector].gravity);
	env->editor.hud.g_sector.t_gravity.target = &env->sectors[env->editor.selected_sector].gravity;
	draw_button(env, env->editor.hud.g_sector.gravity);
	return (0);
}
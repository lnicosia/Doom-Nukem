/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   editor_sector_tabs.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipatry <sipatry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 17:52:15 by sipatry           #+#    #+#             */
/*   Updated: 2020/02/04 15:00:29 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

int		print_sector_general_tab(t_env *env)
{
	print_text(new_point(450, 80), new_printable_text("sector ",
	env->sdl.fonts.alice30, 0xFFFFFFFF, 30), env);
	ft_snprintf(env->snprintf, SNPRINTF_SIZE, "%d", env->editor.selected_sector);
	print_text(new_point(450, 180), new_printable_text(env->snprintf,
	env->sdl.fonts.alice30, 0xFFFFFFFF, 30), env);
	print_text(new_point(520, 60), new_printable_text("Brightness:",
	env->sdl.fonts.alice30, 0xFFFFFFFF, 30), env);
	ft_snprintf(env->snprintf, SNPRINTF_SIZE, "%d",
	env->sectors[env->editor.selected_sector].brightness);
	env->editor.hud.g_sector.t_brightness.target =
	&env->sectors[env->editor.selected_sector].brightness;
	draw_button(env, env->editor.hud.g_sector.brightness, env->snprintf);
	print_text(new_point(560, 60), new_printable_text("Light_color:",
	env->sdl.fonts.alice30, 0xFFFFFFFF, 30), env);
	ft_snprintf(env->snprintf, SNPRINTF_SIZE, "0x%X",
	env->sectors[env->editor.selected_sector].light_color);
	env->editor.hud.g_sector.t_color.target =
	&env->sectors[env->editor.selected_sector].light_color;
	draw_button(env, env->editor.hud.g_sector.color, env->snprintf);
	print_text(new_point(600, 60), new_printable_text("Intensity:",
	env->sdl.fonts.alice30, 0xFFFFFFFF, 30), env);
	ft_snprintf(env->snprintf, SNPRINTF_SIZE, "%d",
	env->sectors[env->editor.selected_sector].intensity);
	env->editor.hud.g_sector.t_intensity.target =
	&env->sectors[env->editor.selected_sector].intensity;
	draw_button(env, env->editor.hud.g_sector.intensity, env->snprintf);
	print_text(new_point(640, 60), new_printable_text("floor: ",
	env->sdl.fonts.alice30, 0xFFFFFFFF, 30), env);
	ft_snprintf(env->snprintf, SNPRINTF_SIZE, "%.*f",
	get_decimal_len(env->sectors[env->editor.selected_sector].floor),
	env->sectors[env->editor.selected_sector].floor);
	env->editor.hud.g_sector.t_floor.target =
	&env->sectors[env->editor.selected_sector].floor;
	draw_button(env, env->editor.hud.g_sector.floor, env->snprintf);
	print_text(new_point(680, 60), new_printable_text("Ceiling: ",
	env->sdl.fonts.alice30, 0xFFFFFFFF, 30), env);
	ft_snprintf(env->snprintf, SNPRINTF_SIZE, "%.*f",
	get_decimal_len(env->sectors[env->editor.selected_sector].ceiling),
	env->sectors[env->editor.selected_sector].ceiling);
	env->editor.hud.g_sector.t_ceilling.target =
	&env->sectors[env->editor.selected_sector].ceiling;
	draw_button(env, env->editor.hud.g_sector.ceiling, env->snprintf);
	print_text(new_point(720, 60), new_printable_text("(f) Slope: ",
	env->sdl.fonts.alice30, 0xFFFFFFFF, 30), env);
	ft_snprintf(env->snprintf, SNPRINTF_SIZE, "%.*f",
	get_decimal_len(env->sectors[env->editor.selected_sector].floor_slope),
	env->sectors[env->editor.selected_sector].floor_slope);
	env->editor.hud.g_sector.t_floor_slope.target =
	&env->sectors[env->editor.selected_sector].floor_slope;
	draw_button(env, env->editor.hud.g_sector.floor_slope, env->snprintf);
	print_text(new_point(760, 60), new_printable_text("(C) Slope: ",
	env->sdl.fonts.alice30, 0xFFFFFFFF, 30), env);
	ft_snprintf(env->snprintf, SNPRINTF_SIZE, "%.*f",
	get_decimal_len(env->sectors[env->editor.selected_sector].ceiling_slope),
	env->sectors[env->editor.selected_sector].ceiling_slope);
	env->editor.hud.g_sector.t_ceiling_slope.target =
	&env->sectors[env->editor.selected_sector].ceiling_slope;
	draw_button(env, env->editor.hud.g_sector.ceiling_slope, env->snprintf);
	print_text(new_point(800, 60), new_printable_text("Gravity: ",
	env->sdl.fonts.alice30, 0xFFFFFFFF, 30), env);
	ft_snprintf(env->snprintf, SNPRINTF_SIZE, "%.*f",
	get_decimal_len(env->sectors[env->editor.selected_sector].gravity),
	env->sectors[env->editor.selected_sector].gravity);
	env->editor.hud.g_sector.t_gravity.target =
	&env->sectors[env->editor.selected_sector].gravity;
	draw_button(env, env->editor.hud.g_sector.gravity, env->snprintf);
	return (0);
}

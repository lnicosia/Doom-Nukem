/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   editor_sector_tabs.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 17:52:15 by sipatry           #+#    #+#             */
/*   Updated: 2020/05/18 14:42:33 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "draw.h"

int		print_sector_general_tab4(t_env *env)
{
	if (print_text(new_point(760, 60), new_printable_text("Ceiling slope",
	env->sdl.fonts.lato20, 0x333333FF, 30), env))
		return (-1);
	ft_snprintf(env->snprintf, SNPRINTF_SIZE, "%.*f",
	get_decimal_len(env->sectors[env->editor.selected_sector].ceiling_slope),
	env->sectors[env->editor.selected_sector].ceiling_slope);
	env->editor.hud.g_sector.t_ceiling_slope.target =
	&env->sectors[env->editor.selected_sector].ceiling_slope;
	if (draw_button(env, env->editor.hud.g_sector.ceiling_slope, env->snprintf))
		return (-1);
	if (print_text(new_point(800, 60), new_printable_text("Gravity",
	env->sdl.fonts.lato20, 0x333333FF, 30), env))
		return (-1);
	ft_snprintf(env->snprintf, SNPRINTF_SIZE, "%.*f",
	get_decimal_len(env->sectors[env->editor.selected_sector].gravity),
	env->sectors[env->editor.selected_sector].gravity);
	env->editor.hud.g_sector.t_gravity.target =
	&env->sectors[env->editor.selected_sector].gravity;
	if (draw_button(env, env->editor.hud.g_sector.gravity, env->snprintf))
		return (-1);
	return (0);
}

int		print_sector_general_tab3(t_env *env)
{
	if (draw_button(env, env->editor.hud.g_sector.floor, env->snprintf))
		return (-1);
	if (print_text(new_point(680, 60), new_printable_text("Ceiling",
	env->sdl.fonts.lato20, 0x333333FF, 30), env))
		return (-1);
	ft_snprintf(env->snprintf, SNPRINTF_SIZE, "%.*f",
	get_decimal_len(env->sectors[env->editor.selected_sector].ceiling),
	env->sectors[env->editor.selected_sector].ceiling);
	env->editor.hud.g_sector.t_ceiling.target =
	&env->sectors[env->editor.selected_sector].ceiling;
	if (draw_button(env, env->editor.hud.g_sector.ceiling, env->snprintf))
		return (-1);
	if (print_text(new_point(720, 60), new_printable_text("Floor slope",
	env->sdl.fonts.lato20, 0x333333FF, 30), env))
		return (-1);
	ft_snprintf(env->snprintf, SNPRINTF_SIZE, "%.*f",
	get_decimal_len(env->sectors[env->editor.selected_sector].floor_slope),
	env->sectors[env->editor.selected_sector].floor_slope);
	env->editor.hud.g_sector.t_floor_slope.target =
	&env->sectors[env->editor.selected_sector].floor_slope;
	if (draw_button(env, env->editor.hud.g_sector.floor_slope, env->snprintf))
		return (-1);
	return (print_sector_general_tab4(env));
}

int		print_sector_general_tab2(t_env *env)
{
	ft_snprintf(env->snprintf, SNPRINTF_SIZE, "0x%X",
	env->sectors[env->editor.selected_sector].light_color);
	env->editor.hud.g_sector.t_color.target =
	&env->sectors[env->editor.selected_sector].light_color;
	if (draw_button(env, env->editor.hud.g_sector.color, env->snprintf))
		return (-1);
	if (print_text(new_point(600, 60), new_printable_text("Intensity",
	env->sdl.fonts.lato20, 0x333333FF, 30), env))
		return (-1);
	ft_snprintf(env->snprintf, SNPRINTF_SIZE, "%d",
	env->sectors[env->editor.selected_sector].intensity);
	env->editor.hud.g_sector.t_intensity.target =
	&env->sectors[env->editor.selected_sector].intensity;
	if (draw_button(env, env->editor.hud.g_sector.intensity, env->snprintf))
		return (-1);
	if (print_text(new_point(640, 60), new_printable_text("Floor",
	env->sdl.fonts.lato20, 0x333333FF, 30), env))
		return (-1);
	ft_snprintf(env->snprintf, SNPRINTF_SIZE, "%.*f",
	get_decimal_len(env->sectors[env->editor.selected_sector].floor),
	env->sectors[env->editor.selected_sector].floor);
	env->editor.hud.g_sector.t_floor.target =
	&env->sectors[env->editor.selected_sector].floor;
	return (print_sector_general_tab3(env));
}

int		print_sector_general_tab(t_env *env)
{
	t_point		size;

	ft_snprintf(env->snprintf, SNPRINTF_SIZE, "Sector %d",
	env->editor.selected_sector);
	if (TTF_SizeText(env->sdl.fonts.lato_black30,
		env->snprintf, &size.x, &size.y))
		return (-1);
	if (print_text(new_point(465, 200 - size.x / 2),
	new_printable_text(env->snprintf,
	env->sdl.fonts.lato_black30, 0x333333FF, 30), env))
		return (-1);
	if (print_text(new_point(520, 60), new_printable_text("Brightness",
	env->sdl.fonts.lato20, 0x333333FF, 30), env))
		return (-1);
	ft_snprintf(env->snprintf, SNPRINTF_SIZE, "%d",
	env->sectors[env->editor.selected_sector].brightness);
	env->editor.hud.g_sector.t_brightness.target =
	&env->sectors[env->editor.selected_sector].brightness;
	if (draw_button(env, env->editor.hud.g_sector.brightness, env->snprintf))
		return (-1);
	if (print_text(new_point(560, 60), new_printable_text("Light color",
	env->sdl.fonts.lato20, 0x333333FF, 30), env))
		return (-1);
	return (print_sector_general_tab2(env));
}

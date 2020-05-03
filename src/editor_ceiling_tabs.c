/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   editor_ceiling_tabs.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 17:40:14 by sipatry           #+#    #+#             */
/*   Updated: 2020/04/29 18:04:55 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

int		print_ceiling_sector_tab2(t_env *env)
{
	draw_button(env, env->editor.hud.s_ceiling.color, env->snprintf);
	print_text(new_point(600, 60), new_printable_text("Intensity",
	env->sdl.fonts.lato20, 0x333333FF, 30), env);
	ft_snprintf(env->snprintf, SNPRINTF_SIZE, "%d",
	env->sectors[env->selected_ceiling].intensity);
	env->editor.hud.s_ceiling.t_intensity.target =
	&env->sectors[env->selected_ceiling].intensity;
	draw_button(env, env->editor.hud.s_ceiling.intensity, env->snprintf);
	print_text(new_point(640, 60), new_printable_text("Gravity",
	env->sdl.fonts.lato20, 0x333333FF, 30), env);
	ft_snprintf(env->snprintf, SNPRINTF_SIZE, "%.*f",
	get_decimal_len(env->sectors[env->selected_ceiling].gravity),
	env->sectors[env->selected_ceiling].gravity);
	env->editor.hud.s_ceiling.t_gravity.target =
	&env->sectors[env->selected_ceiling].gravity;
	draw_button(env, env->editor.hud.s_ceiling.gravity, env->snprintf);
	return (0);
}

int		print_ceiling_sector_tab(t_env *env)
{
	t_point		size;

	ft_snprintf(env->snprintf, SNPRINTF_SIZE, "Sector %d",
	env->selected_ceiling);
	TTF_SizeText(env->sdl.fonts.lato_black30, env->snprintf, &size.x, &size.y);
	print_text(new_point(465, 200 - size.x / 2),
	new_printable_text(env->snprintf,
	env->sdl.fonts.lato_black30, 0x333333FF, 30), env);
	print_text(new_point(520, 60), new_printable_text("Brightness",
	env->sdl.fonts.lato20, 0x333333FF, 30), env);
	ft_snprintf(env->snprintf, SNPRINTF_SIZE, "%d",
	env->sectors[env->selected_ceiling].brightness);
	env->editor.hud.s_ceiling.t_brightness.target =
	&env->sectors[env->selected_ceiling].brightness;
	draw_button(env, env->editor.hud.s_ceiling.brightness, env->snprintf);
	print_text(new_point(560, 60), new_printable_text("Light_color",
	env->sdl.fonts.lato20, 0x333333FF, 30), env);
	ft_snprintf(env->snprintf, SNPRINTF_SIZE, "0x%X",
	env->sectors[env->selected_ceiling].light_color);
	env->editor.hud.s_ceiling.t_color.target =
	&env->sectors[env->selected_ceiling].light_color;
	return (print_ceiling_sector_tab2(env));
}

int		print_ceiling_general_tab3(t_env *env)
{
	env->editor.hud.g_ceiling.t_texture_scale_y.target =
	&env->sectors[env->selected_ceiling].ceiling_map_scale.y;
	draw_button(env, env->editor.hud.g_ceiling.texture_scale_y, env->snprintf);
	print_text(new_point(720, 60), new_printable_text("Align X",
	env->sdl.fonts.lato20, 0x333333FF, 30), env);
	ft_snprintf(env->snprintf, SNPRINTF_SIZE, "%.*f",
	get_decimal_len(env->sectors[env->selected_ceiling].ceiling_map_align.x),
	env->sectors[env->selected_ceiling].ceiling_map_align.x);
	env->editor.hud.g_ceiling.t_texture_align_x.target =
	&env->sectors[env->selected_ceiling].ceiling_map_align.x;
	draw_button(env, env->editor.hud.g_ceiling.texture_align_x, env->snprintf);
	print_text(new_point(760, 60), new_printable_text("Align Y",
	env->sdl.fonts.lato20, 0x333333FF, 30), env);
	ft_snprintf(env->snprintf, SNPRINTF_SIZE, "%.*f",
	get_decimal_len(env->sectors[env->selected_ceiling].ceiling_map_align.y),
	env->sectors[env->selected_ceiling].ceiling_map_align.y);
	env->editor.hud.g_ceiling.t_texture_align_y.target =
	&env->sectors[env->selected_ceiling].ceiling_map_align.y;
	draw_button(env, env->editor.hud.g_ceiling.texture_align_y, env->snprintf);
	draw_button(env, env->editor.hud.g_ceiling.add_sprite,
	env->editor.hud.g_ceiling.add_sprite.str);
	return (0);
}

int		print_ceiling_general_tab2(t_env *env, t_point size)
{
	env->editor.hud.g_ceiling.t_slope.target =
	&env->sectors[env->selected_ceiling].ceiling_slope;
	draw_button(env, env->editor.hud.g_ceiling.slope, env->snprintf);
	ft_snprintf(env->snprintf, SNPRINTF_SIZE, "Start slope %d",
	env->sectors[env->selected_ceiling].start_ceiling_slope);
	TTF_SizeText(env->sdl.fonts.lato20, env->snprintf, &size.x, &size.y);
	print_text(new_point(600, 200 - size.x / 2),
	new_printable_text(env->snprintf,
	env->sdl.fonts.lato20, 0x333333FF, 30), env);
	draw_button(env, env->editor.previous_slope_swap, NULL);
	draw_button(env, env->editor.next_slope_swap, NULL);
	print_text(new_point(640, 60), new_printable_text("Scale X",
	env->sdl.fonts.lato20, 0x333333FF, 30), env);
	ft_snprintf(env->snprintf, SNPRINTF_SIZE, "%.*f",
	get_decimal_len(env->sectors[env->selected_ceiling].ceiling_map_scale.x),
	env->sectors[env->selected_ceiling].ceiling_map_scale.x);
	env->editor.hud.g_ceiling.t_texture_scale_x.target =
	&env->sectors[env->selected_ceiling].ceiling_map_scale.x;
	draw_button(env, env->editor.hud.g_ceiling.texture_scale_x, env->snprintf);
	print_text(new_point(680, 60), new_printable_text("Scale Y",
	env->sdl.fonts.lato20, 0x333333FF, 30), env);
	ft_snprintf(env->snprintf, SNPRINTF_SIZE, "%.*f",
	get_decimal_len(env->sectors[env->selected_ceiling].ceiling_map_scale.y),
	env->sectors[env->selected_ceiling].ceiling_map_scale.y);
	return (print_ceiling_general_tab3(env));
}

int		print_ceiling_general_tab(t_env *env)
{
	t_point		size;

	ft_snprintf(env->snprintf, SNPRINTF_SIZE, "Sector %d",
	env->selected_ceiling);
	TTF_SizeText(env->sdl.fonts.lato_black30, env->snprintf, &size.x, &size.y);
	print_text(new_point(465, 200 - size.x / 2),
	new_printable_text(env->snprintf,
	env->sdl.fonts.lato_black30, 0x333333FF, 30), env);
	print_text(new_point(520, 60), new_printable_text("Height",
	env->sdl.fonts.lato20, 0x333333FF, 30), env);
	ft_snprintf(env->snprintf, SNPRINTF_SIZE, "%.*f",
	get_decimal_len(env->sectors[env->selected_ceiling].ceiling),
	env->sectors[env->selected_ceiling].ceiling);
	env->editor.hud.g_ceiling.t_height.target =
	&env->sectors[env->selected_ceiling].ceiling;
	draw_button(env, env->editor.hud.g_ceiling.height, env->snprintf);
	print_text(new_point(560, 60), new_printable_text("Slope",
	env->sdl.fonts.lato20, 0x333333FF, 30), env);
	ft_snprintf(env->snprintf, SNPRINTF_SIZE, "%.*f",
	get_decimal_len(env->sectors[env->selected_ceiling].ceiling_slope),
	env->sectors[env->selected_ceiling].ceiling_slope);
	return (print_ceiling_general_tab2(env, size));
}

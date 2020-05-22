/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   editor_floor_tabs.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 17:31:40 by sipatry           #+#    #+#             */
/*   Updated: 2020/04/29 18:07:31 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "draw.h"

int		print_floor_general_tab3(t_env *env)
{
	env->editor.hud.g_floor.t_texture_scale_y.target =
	&env->sectors[env->selected_floor].floor_map_scale.y;
	if (draw_button(env, env->editor.hud.g_floor.texture_scale_y,
		env->snprintf))
		return (-1);
	if (print_text(new_point(720, 60), new_printable_text("Align X: ",
		env->sdl.fonts.lato20, 0x333333FF, 30), env))
		return (-1);
	ft_snprintf(env->snprintf, SNPRINTF_SIZE, "%.*f",
	get_decimal_len(env->sectors[env->selected_floor].floor_map_align.x),
	env->sectors[env->selected_floor].floor_map_align.x);
	env->editor.hud.g_floor.t_texture_align_x.target =
	&env->sectors[env->selected_floor].floor_map_align.x;
	if (draw_button(env, env->editor.hud.g_floor.texture_align_x,
		env->snprintf))
		return (-1);
	if (print_text(new_point(760, 60), new_printable_text("Align Y: ",
		env->sdl.fonts.lato20, 0x333333FF, 30), env))
		return (-1);
	ft_snprintf(env->snprintf, SNPRINTF_SIZE, "%.*f",
	get_decimal_len(env->sectors[env->selected_floor].floor_map_align.y),
	env->sectors[env->selected_floor].floor_map_align.y);
	env->editor.hud.g_floor.t_texture_align_y.target =
	&env->sectors[env->selected_floor].floor_map_align.y;
	if (draw_button(env, env->editor.hud.g_floor.texture_align_y,
		env->snprintf))
		return (-1);
	if (draw_button(env, env->editor.hud.g_floor.add_sprite,
	env->editor.hud.g_floor.add_sprite.str))
		return (-1);
	return (0);
}

int		print_floor_general_tab2(t_env *env, t_point size)
{
	env->editor.hud.g_floor.t_slope.target =
	&env->sectors[env->selected_floor].floor_slope;
	if (draw_button(env, env->editor.hud.g_floor.slope, env->snprintf))
		return (-1);
	ft_snprintf(env->snprintf, SNPRINTF_SIZE, "Start slope %d",
	env->sectors[env->selected_floor].start_floor_slope);
	if (TTF_SizeText(env->sdl.fonts.lato20, env->snprintf, &size.x, &size.y))
		return (-1);
	if (print_text(new_point(600, 200 - size.x / 2),
		new_printable_text(env->snprintf,
		env->sdl.fonts.lato20, 0x333333FF, 30), env))
		return (-1);
	if (draw_button(env, env->editor.previous_slope_swap, NULL))
		return (-1);
	if (draw_button(env, env->editor.next_slope_swap, NULL))
		return (-1);
	if (print_text(new_point(640, 60), new_printable_text("Scale X: ",
		env->sdl.fonts.lato20, 0x333333FF, 30), env))
		return (-1);
	ft_snprintf(env->snprintf, SNPRINTF_SIZE, "%.*f",
	get_decimal_len(env->sectors[env->selected_floor].floor_map_scale.x),
	env->sectors[env->selected_floor].floor_map_scale.x);
	env->editor.hud.g_floor.t_texture_scale_x.target =
	&env->sectors[env->selected_floor].floor_map_scale.x;
	if (draw_button(env, env->editor.hud.g_floor.texture_scale_x,
		env->snprintf))
		return (-1);
	if (print_text(new_point(680, 60), new_printable_text("Scale Y: ",
		env->sdl.fonts.lato20, 0x333333FF, 30), env))
		return (-1);
	ft_snprintf(env->snprintf, SNPRINTF_SIZE, "%.*f",
	get_decimal_len(env->sectors[env->selected_floor].floor_map_scale.y),
	env->sectors[env->selected_floor].floor_map_scale.y);
	return (print_floor_general_tab3(env));
}

int		print_floor_general_tab(t_env *env)
{
	t_point		size;

	ft_snprintf(env->snprintf, SNPRINTF_SIZE, "Sector %d",
	env->selected_floor);
	if (TTF_SizeText(env->sdl.fonts.lato_black30,
		env->snprintf, &size.x, &size.y))
		return (-1);
	if (print_text(new_point(465, 200 - size.x / 2),
		new_printable_text(env->snprintf,
		env->sdl.fonts.lato_black30, 0x333333FF, 30), env))
		return (-1);
	if (print_text(new_point(520, 60), new_printable_text("Height: ",
		env->sdl.fonts.lato20, 0x333333FF, 30), env))
		return (-1);
	ft_snprintf(env->snprintf, SNPRINTF_SIZE, "%.*f",
	get_decimal_len(env->sectors[env->selected_floor].floor),
	env->sectors[env->selected_floor].floor);
	env->editor.hud.g_floor.t_height.target =
	&env->sectors[env->selected_floor].floor;
	if (draw_button(env, env->editor.hud.g_floor.height, env->snprintf))
		return (-1);
	if (print_text(new_point(560, 60), new_printable_text("Slope: ",
		env->sdl.fonts.lato20, 0x333333FF, 30), env))
		return (-1);
	ft_snprintf(env->snprintf, SNPRINTF_SIZE, "%.*f",
	get_decimal_len(env->sectors[env->selected_floor].floor_slope),
	env->sectors[env->selected_floor].floor_slope);
	return (print_floor_general_tab2(env, size));
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   editor_ceiling_tabs.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipatry <sipatry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 17:40:14 by sipatry           #+#    #+#             */
/*   Updated: 2020/02/20 10:15:39 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

int		print_ceiling_sprite_tab(t_env *env)
{
	env->editor.next_sprite_env.type = CEILING_S;	
	env->editor.previous_sprite_env.type = CEILING_S;	
	print_text(new_point(560, 60), new_printable_text("Pos: ", 
	env->sdl.fonts.lato20, 0x00000000, 30), env);
	ft_snprintf(env->snprintf, SNPRINTF_SIZE, "%.*f",
	get_decimal_len(env->sectors[env->selected_ceiling].
	ceiling_sprites.pos[env->selected_ceiling_sprite].x),
	env->sectors[env->selected_ceiling].
	ceiling_sprites.pos[env->selected_ceiling_sprite].x);
	env->editor.hud.sp_ceiling_sprite.t_pos_x.target =
	&env->sectors[env->selected_ceiling].ceiling_sprites.
	pos[env->selected_ceiling_sprite].x;
	draw_button(env, env->editor.hud.sp_ceiling_sprite.pos_x, env->snprintf);
	ft_snprintf(env->snprintf, SNPRINTF_SIZE, "%.*f",
	get_decimal_len(env->sectors[env->selected_ceiling].ceiling_sprites.
	pos[env->selected_ceiling_sprite].y),
	env->sectors[env->selected_ceiling].ceiling_sprites.
	pos[env->selected_ceiling_sprite].y);
	env->editor.hud.sp_ceiling_sprite.t_pos_y.target =
	&env->sectors[env->selected_ceiling].ceiling_sprites.
	pos[env->selected_ceiling_sprite].y;
	draw_button(env, env->editor.hud.sp_ceiling_sprite.pos_y, env->snprintf);
	print_text(new_point(600, 60), new_printable_text("Scale: ",
	env->sdl.fonts.lato20, 0x00000000, 30), env);
	ft_snprintf(env->snprintf, SNPRINTF_SIZE, "%.*f",
	get_decimal_len(env->sectors[env->selected_ceiling].ceiling_sprites.
	scale[env->selected_ceiling_sprite].x),
	env->sectors[env->selected_ceiling].ceiling_sprites.
	scale[env->selected_ceiling_sprite].x);
	env->editor.hud.sp_ceiling_sprite.t_scale_x.target =
	&env->sectors[env->selected_ceiling].ceiling_sprites.
	scale[env->selected_ceiling_sprite].x;
	draw_button(env, env->editor.hud.sp_ceiling_sprite.scale_x, env->snprintf);
	ft_snprintf(env->snprintf, SNPRINTF_SIZE, "%.*f",
	get_decimal_len(env->sectors[env->selected_ceiling].ceiling_sprites.
	scale[env->selected_ceiling_sprite].y),
	env->sectors[env->selected_ceiling].ceiling_sprites.
	scale[env->selected_ceiling_sprite].y);
	env->editor.hud.sp_ceiling_sprite.t_scale_y.target =
	&env->sectors[env->selected_ceiling].ceiling_sprites.
	scale[env->selected_ceiling_sprite].y;
	draw_button(env, env->editor.hud.sp_ceiling_sprite.scale_y, env->snprintf);
	return (0);
}

int		print_ceiling_sector_tab(t_env *env)
{
	ft_snprintf(env->snprintf, SNPRINTF_SIZE, "Sector %d", env->selected_ceiling);
	print_text(new_point(480, 60), new_printable_text(env->snprintf,
	env->sdl.fonts.lato20, 0x00000000, 30), env);
	print_text(new_point(520, 60), new_printable_text("Brightness:",
	env->sdl.fonts.lato20, 0x00000000, 30), env);
	ft_snprintf(env->snprintf, SNPRINTF_SIZE, "%d",
	env->sectors[env->selected_ceiling].brightness);
	env->editor.hud.s_ceilling.t_brightness.target =
	&env->sectors[env->selected_ceiling].brightness;
	draw_button(env, env->editor.hud.s_ceilling.brightness, env->snprintf);
	print_text(new_point(560, 60), new_printable_text("Light_color:",
	env->sdl.fonts.lato20, 0x00000000, 30), env);
	ft_snprintf(env->snprintf, SNPRINTF_SIZE, "0x%X",
	env->sectors[env->selected_ceiling].light_color);
	env->editor.hud.s_ceilling.t_color.target =
	&env->sectors[env->selected_ceiling].light_color;
	draw_button(env, env->editor.hud.s_ceilling.color, env->snprintf);
	print_text(new_point(600, 60), new_printable_text("Intensity:",
	env->sdl.fonts.lato20, 0x00000000, 30), env);
	ft_snprintf(env->snprintf, SNPRINTF_SIZE, "%d",
	env->sectors[env->selected_ceiling].intensity);
	env->editor.hud.s_ceilling.t_intensity.target =
	&env->sectors[env->selected_ceiling].intensity;
	draw_button(env, env->editor.hud.s_ceilling.intensity, env->snprintf);
	print_text(new_point(640, 60), new_printable_text("Gravity:",
	env->sdl.fonts.lato20, 0x00000000, 30), env);
	ft_snprintf(env->snprintf, SNPRINTF_SIZE, "%.*f",
	get_decimal_len(env->sectors[env->selected_ceiling].gravity),
	env->sectors[env->selected_ceiling].gravity);
	env->editor.hud.s_ceilling.t_gravity.target =
	&env->sectors[env->selected_ceiling].gravity;
	draw_button(env, env->editor.hud.s_ceilling.gravity, env->snprintf);
	return (0);
}

int		print_ceiling_general_tab(t_env *env)
{
	print_text(new_point(520, 60), new_printable_text("Height: ",
	env->sdl.fonts.lato20, 0x00000000, 30), env);
	ft_snprintf(env->snprintf, SNPRINTF_SIZE, "%.*f",
	get_decimal_len(env->sectors[env->selected_ceiling].ceiling),
	env->sectors[env->selected_ceiling].ceiling);
	env->editor.hud.g_ceilling.t_height.target =
	&env->sectors[env->selected_ceiling].ceiling;
	draw_button(env, env->editor.hud.g_ceilling.height, env->snprintf);	
	print_text(new_point(560, 60), new_printable_text("Slope: ",
	env->sdl.fonts.lato20, 0x00000000, 30), env);
	ft_snprintf(env->snprintf, SNPRINTF_SIZE, "%.*f",
	get_decimal_len(env->sectors[env->selected_ceiling].ceiling_slope),
	env->sectors[env->selected_ceiling].ceiling_slope);
	env->editor.hud.g_ceilling.t_slope.target =
	&env->sectors[env->selected_ceiling].ceiling_slope;
	draw_button(env, env->editor.hud.g_ceilling.slope, env->snprintf);
	draw_button(env, env->editor.previous_slope_swap, NULL);
	draw_button(env, env->editor.next_slope_swap, NULL);
	print_text(new_point(640, 60), new_printable_text("Scale X: ",
	env->sdl.fonts.lato20, 0x00000000, 30), env);
	ft_snprintf(env->snprintf, SNPRINTF_SIZE, "%.*f",
	get_decimal_len(env->sectors[env->selected_ceiling].ceiling_map_scale.x),
	env->sectors[env->selected_ceiling].ceiling_map_scale.x);
	env->editor.hud.g_ceilling.t_texture_scale_x.target =
	&env->sectors[env->selected_ceiling].ceiling_map_scale.x;
	draw_button(env, env->editor.hud.g_ceilling.texture_scale_x, env->snprintf);
	print_text(new_point(680, 60), new_printable_text("Scale Y: ",
	env->sdl.fonts.lato20, 0x00000000, 30), env);
	ft_snprintf(env->snprintf, SNPRINTF_SIZE, "%.*f",
	get_decimal_len(env->sectors[env->selected_ceiling].ceiling_map_scale.y),
	env->sectors[env->selected_ceiling].ceiling_map_scale.y);
	env->editor.hud.g_ceilling.t_texture_scale_y.target =
	&env->sectors[env->selected_ceiling].ceiling_map_scale.y;
	draw_button(env, env->editor.hud.g_ceilling.texture_scale_y, env->snprintf);
	print_text(new_point(720, 60), new_printable_text("Align X: ",
	env->sdl.fonts.lato20, 0x00000000, 30), env);
	ft_snprintf(env->snprintf, SNPRINTF_SIZE, "%.*f",
	get_decimal_len(env->sectors[env->selected_ceiling].ceiling_map_align.x),
	env->sectors[env->selected_ceiling].ceiling_map_align.x);
	env->editor.hud.g_ceilling.t_texture_align_x.target
	= &env->sectors[env->selected_ceiling].ceiling_map_align.x;
	draw_button(env, env->editor.hud.g_ceilling.texture_align_x, env->snprintf);
	print_text(new_point(760, 60), new_printable_text("Align Y: ",
	env->sdl.fonts.lato20, 0x00000000, 30), env);
	ft_snprintf(env->snprintf, SNPRINTF_SIZE, "%.*f",
	get_decimal_len(env->sectors[env->selected_ceiling].ceiling_map_align.y),
	env->sectors[env->selected_ceiling].ceiling_map_align.y);
	env->editor.hud.g_ceilling.t_texture_align_y.target =
	&env->sectors[env->selected_ceiling].ceiling_map_align.y;
	draw_button(env, env->editor.hud.g_ceilling.texture_align_y, env->snprintf);
	draw_button(env, env->editor.hud.g_ceilling.add_sprite, env->editor.hud.g_ceilling.add_sprite.str);
	return (0);
}

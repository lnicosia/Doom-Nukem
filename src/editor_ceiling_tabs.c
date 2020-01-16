/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   editor_ceiling_tabs.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipatry <sipatry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 17:40:14 by sipatry           #+#    #+#             */
/*   Updated: 2020/01/16 17:12:58 by sipatry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

void	print_ceiling_sprite_tab(t_env *env)
{
	(void)env;
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
	print_text(new_point(520, 230), new_printable_text(ft_sitoa(env->sectors[env->selected_ceiling].ceiling), env->sdl.fonts.alice30, 0xFFFFFFFF, 30), env);
	print_text(new_point(560, 60), new_printable_text("Slope: ", env->sdl.fonts.alice30, 0xFFFFFFFF, 30), env);
	print_text(new_point(560, 270), new_printable_text(ft_sitoa(env->sectors[env->selected_ceiling].ceiling_slope), env->sdl.fonts.alice30, 0xFFFFFFFF, 30), env);
	print_text(new_point(600, 60), new_printable_text("Texture: ", env->sdl.fonts.alice30, 0xFFFFFFFF, 30), env);
	print_text(new_point(600, 230), new_printable_text(ft_sitoa(env->sectors[env->selected_ceiling].ceiling_texture), env->sdl.fonts.alice30, 0xFFFFFFFF, 30), env);
	print_text(new_point(640, 60), new_printable_text("Scale X: ", env->sdl.fonts.alice30, 0xFFFFFFFF, 30), env);
	print_text(new_point(640, 230), new_printable_text(ft_sitoa(env->sectors[env->selected_ceiling].ceiling_scale->x), env->sdl.fonts.alice30, 0xFFFFFFFF, 30), env);
	print_text(new_point(680, 60), new_printable_text("Scale Y: ", env->sdl.fonts.alice30, 0xFFFFFFFF, 30), env);
	print_text(new_point(680, 230), new_printable_text(ft_sitoa(env->sectors[env->selected_ceiling].ceiling_scale->y), env->sdl.fonts.alice30, 0xFFFFFFFF, 30), env);
	print_text(new_point(720, 60), new_printable_text("Align X: ", env->sdl.fonts.alice30, 0xFFFFFFFF, 30), env);
	print_text(new_point(720, 230), new_printable_text(ft_sitoa(env->sectors[env->selected_ceiling].ceiling_align->x ), env->sdl.fonts.alice30, 0xFFFFFFFF, 30), env);
	print_text(new_point(760, 60), new_printable_text("Align Y: ", env->sdl.fonts.alice30, 0xFFFFFFFF, 30), env);
	print_text(new_point(760, 230), new_printable_text(ft_sitoa(env->sectors[env->selected_ceiling].ceiling_align->y ), env->sdl.fonts.alice30, 0xFFFFFFFF, 30), env);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   editor_object_tabs.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipatry <sipatry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 15:50:14 by sipatry           #+#    #+#             */
/*   Updated: 2020/01/28 10:29:07 by sipatry          ###   ########.fr       */	
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

int		print_object_sector_tab(t_env *env)
{
	print_text(new_point(480, 60), new_printable_text("object:", env->sdl.fonts.alice30, 0xFFFFFFFF, 30), env);
	print_text(new_point(520, 60), new_printable_text("Brightness:", env->sdl.fonts.alice30, 0xFFFFFFFF, 30), env);
	env->editor.hud.s_object.brightness.str = ft_itoa(env->sectors[env->objects[env->editor.selected_object].sector].brightness);
	env->editor.hud.s_object.t_brightness.target = &env->sectors[env->objects[env->editor.selected_object].sector].brightness;
	draw_button(env, env->editor.hud.s_object.brightness);
	print_text(new_point(560, 60), new_printable_text("Light_color:", env->sdl.fonts.alice30, 0xFFFFFFFF, 30), env);
	env->editor.hud.s_object.color.str = ft_sitoa(env->sectors[env->objects[env->editor.selected_object].sector].light_color);
	env->editor.hud.s_object.t_color.target = &env->sectors[env->objects[env->editor.selected_object].sector].light_color;
	draw_button(env, env->editor.hud.s_object.color);
	print_text(new_point(600, 60), new_printable_text("Intensity:", env->sdl.fonts.alice30, 0xFFFFFFFF, 30), env);
	env->editor.hud.s_object.intensity.str = ft_sitoa(env->sectors[env->objects[env->editor.selected_object].sector].intensity);
	env->editor.hud.s_object.t_intensity.target = &env->sectors[env->objects[env->editor.selected_object].sector].intensity;
	draw_button(env, env->editor.hud.s_object.intensity);
	return (0);
}

int		print_object_general_tab(t_env *env)
{
	print_text(new_point(520, 60), new_printable_text("Pos: ", env->sdl.fonts.alice30, 0xFFFFFFFF, 30), env);
	env->editor.hud.g_object.pos_x.str = ft_sitoa(env->objects[env->editor.selected_object].pos.x);
	env->editor.hud.g_object.t_pos_x.target = &env->objects[env->editor.selected_object].pos.x;
	draw_button(env, env->editor.hud.g_object.pos_x);
	env->editor.hud.g_object.pos_y.str = ft_sitoa(env->objects[env->editor.selected_object].pos.y);
	env->editor.hud.g_object.t_pos_y.target = &env->objects[env->editor.selected_object].pos.y;
	draw_button(env, env->editor.hud.g_object.pos_y);
	env->editor.hud.g_object.pos_z.str = ft_sitoa(env->objects[env->editor.selected_object].pos.z);
	env->editor.hud.g_object.t_pos_z.target = &env->objects[env->editor.selected_object].pos.z;
	draw_button(env, env->editor.hud.g_object.pos_z);
	print_text(new_point(560, 60), new_printable_text("Health: ", env->sdl.fonts.alice30, 0xFFFFFFFF, 30), env);
	env->editor.hud.g_object.health.str = ft_sitoa(env->objects[env->editor.selected_object].health);
	env->editor.hud.g_object.t_health.target = &env->objects[env->editor.selected_object].health;
	draw_button(env, env->editor.hud.g_object.health);
	return (0);
}
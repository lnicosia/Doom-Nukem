/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   editor_object_tabs.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipatry <sipatry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 15:50:14 by sipatry           #+#    #+#             */
/*   Updated: 2020/03/04 11:28:59 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

int		print_object_sector_tab(t_env *env)
{
	print_text(new_point(480, 60), new_printable_text("object:",
	env->sdl.fonts.lato20, 0x00000000, 30), env);
	print_text(new_point(520, 60), new_printable_text("Brightness:",
	env->sdl.fonts.lato20, 0x00000000, 30), env);
	ft_snprintf(env->snprintf, SNPRINTF_SIZE, "%d",
	env->sectors[env->objects[env->selected_object].sector].brightness);
	env->editor.hud.s_object.t_brightness.target =
	&env->sectors[env->objects[env->selected_object].sector].brightness;
	draw_button(env, env->editor.hud.s_object.brightness, env->snprintf);
	print_text(new_point(560, 60), new_printable_text("Light_color:",
	env->sdl.fonts.lato20, 0x00000000, 30), env);
	ft_snprintf(env->snprintf, SNPRINTF_SIZE, "0x%X",
	env->sectors[env->objects[env->selected_object].sector].light_color);
	env->editor.hud.s_object.t_color.target =
	&env->sectors[env->objects[env->selected_object].sector].light_color;
	draw_button(env, env->editor.hud.s_object.color, env->snprintf);
	print_text(new_point(600, 60), new_printable_text("Intensity:",
	env->sdl.fonts.lato20, 0x00000000, 30), env);
	ft_snprintf(env->snprintf, SNPRINTF_SIZE, "%d",
	env->sectors[env->objects[env->selected_object].sector].intensity);
	env->editor.hud.s_object.t_intensity.target =
	&env->sectors[env->objects[env->selected_object].sector].intensity;
	draw_button(env, env->editor.hud.s_object.intensity, env->snprintf);
	print_text(new_point(640, 60), new_printable_text("Gravity:",
	env->sdl.fonts.lato20, 0x00000000, 30), env);
	ft_snprintf(env->snprintf, SNPRINTF_SIZE, "%.*f",
	get_decimal_len(env->sectors[env->objects[env->selected_object].sector].
	gravity), env->sectors[env->objects[env->selected_object].sector].gravity);
	env->editor.hud.s_object.t_gravity.target =
	&env->sectors[env->objects[env->selected_object].sector].gravity;
	draw_button(env, env->editor.hud.s_object.gravity, env->snprintf);
	return (0);
}

int		print_object_general_tab(t_env *env)
{
	print_text(new_point(520, 60), new_printable_text("Pos: ",
	env->sdl.fonts.lato20, 0x00000000, 30), env);
	ft_snprintf(env->snprintf, SNPRINTF_SIZE, "%.*f",
	ft_min(1, get_decimal_len(env->objects[env->selected_object].pos.x)),
	env->objects[env->selected_object].pos.x),
	env->editor.hud.g_object.t_pos_x.target =
	&env->objects[env->selected_object].pos.x;
	draw_button(env, env->editor.hud.g_object.pos_x, env->snprintf);
	ft_snprintf(env->snprintf, SNPRINTF_SIZE, "%.*f",
	ft_min(1, get_decimal_len(env->objects[env->selected_object].pos.y)),
	env->objects[env->selected_object].pos.y);
	env->editor.hud.g_object.t_pos_y.target =
	&env->objects[env->selected_object].pos.y;
	draw_button(env, env->editor.hud.g_object.pos_y, env->snprintf);
	ft_snprintf(env->snprintf, SNPRINTF_SIZE, "%.*f",
	ft_min(1, get_decimal_len(env->objects[env->selected_object].pos.z)),
	env->objects[env->selected_object].pos.z);
	env->editor.hud.g_object.t_pos_z.target =
	&env->objects[env->selected_object].pos.z;
	draw_button(env, env->editor.hud.g_object.pos_z, env->snprintf);
	print_text(new_point(560, 60), new_printable_text("Health: ",
	env->sdl.fonts.lato20, 0x00000000, 30), env);
	ft_snprintf(env->snprintf, SNPRINTF_SIZE, "%d",
	env->objects[env->selected_object].health);
	env->editor.hud.g_object.t_health.target =
	&env->objects[env->selected_object].health;
	draw_button(env, env->editor.hud.g_object.health, env->snprintf);
	print_text(new_point(600, 60), new_printable_text("Scale: ",
	env->sdl.fonts.lato20, 0x00000000, 30), env);
	ft_snprintf(env->snprintf, SNPRINTF_SIZE, "%.*f",
	get_decimal_len(env->objects[env->selected_object].scale),
	env->objects[env->selected_object].scale);
	env->editor.hud.g_object.t_scale.target =
	&env->objects[env->selected_object].scale;
	draw_button(env, env->editor.hud.g_object.scale, env->snprintf);
	print_text(new_point(640, 60), new_printable_text("Damage: ",
	env->sdl.fonts.lato20, 0x00000000, 30), env);
	ft_snprintf(env->snprintf, SNPRINTF_SIZE, "%d",
	env->objects[env->selected_object].damage);
	env->editor.hud.g_object.t_damage.target =
	&env->objects[env->selected_object].damage;
	draw_button(env, env->editor.hud.g_object.damage, env->snprintf);
	print_text(new_point(680, 60), new_printable_text("Angle: ",
	env->sdl.fonts.lato20, 0x333333FF, 30), env);
	ft_snprintf(env->snprintf, SNPRINTF_SIZE, "%.*f",
	get_decimal_len(env->objects[env->selected_object].angle),
	env->objects[env->selected_object].angle);
	env->editor.hud.g_object.t_angle.target =
	&env->objects[env->selected_object].angle;
	draw_button(env, env->editor.hud.g_object.angle, env->snprintf);
	return (0);
}
